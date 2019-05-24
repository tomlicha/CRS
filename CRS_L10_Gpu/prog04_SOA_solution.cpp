//----------------------------------------------------------------------------

#include "crsGpu.hpp"

#define ASSUMED_CACHELINE_SIZE 64

struct Point_SOA
{
std::vector<float> px,py; // positions
std::vector<float> vx,vy; // velocities
std::vector<float> r,g,b; // colours
};

//---- some data to be kept with each thread ----
struct ThreadData
{
std::thread th;
// ensure at least two _aligned_ cache-lines between ``hot data''
uint8_t padding[3*ASSUMED_CACHELINE_SIZE];
};

//---- some data common to every thread ----
struct SharedData
{
std::vector<ThreadData> td;
std::vector<crs::CpuInfo> cpuInfo;
Point_SOA *points;
float xAccel,yAccel,dt,xLimit,yLimit;
std::atomic<int> step{0};
std::atomic<int> inCurrentStep{0};
std::atomic<int> inMotion{0};
volatile bool done{false};
};

//---- the actual work to be done in each thread ----
void
threadWork(int index,
           SharedData &sd)
{
//---- determine the part of the work to be done by this thread ----
const int64_t count=crs::len(sd.points->px);
const int64_t workBegin=count*index/crs::len(sd.td);
const int64_t workEnd=std::min(count,count*(index+1)/crs::len(sd.td));

//---- compute point motion ----
const float xAccel=sd.xAccel,yAccel=sd.yAccel,dt=sd.dt,
            xLimit=sd.xLimit,yLimit=sd.yLimit;
float * RESTRICT soa_px=sd.points->px.data();
float * RESTRICT soa_py=sd.points->py.data();
float * RESTRICT soa_vx=sd.points->vx.data();
float * RESTRICT soa_vy=sd.points->vy.data();
TRY_TO_VECTORISE
for(int64_t id=workBegin;id<workEnd;++id)
  {
  //-- read --
  float px=soa_px[id], py=soa_py[id];
  float vx=soa_vx[id], vy=soa_vy[id];
  //-- compute --
  px+=(vx+xAccel*0.5f*dt)*dt;
  py+=(vy+yAccel*0.5f*dt)*dt;
  vx+=xAccel*dt;
  vy+=yAccel*dt;
  if(px>xLimit)
    { px=xLimit; if(vx>=0.0) { vx=-vx; } }
  else if(px<-xLimit)
    { px=-xLimit; if(vx<=0.0) { vx=-vx; } }
  if(py>yLimit)
    { py=yLimit; if(vy>=0.0) { vy=-vy; } }
  else if(py<-yLimit)
    { py=-yLimit; if(vy<=0.0) { vy=-vy; } }
  //-- write --
  soa_px[id]=px; soa_py[id]=py;
  soa_vx[id]=vx; soa_vy[id]=vy;
  }

if(!(sd.step%10))
  {
  //---- signal and wait for end of motion ----
  if(--sd.inMotion>0)
    { while(sd.inMotion) { /* busy-wait */ } }

  //---- compute point colour ----
  float * RESTRICT soa_r=sd.points->r.data();
  float * RESTRICT soa_g=sd.points->g.data();
  float * RESTRICT soa_b=sd.points->b.data();
  TRY_TO_VECTORISE
  for(int64_t id=workBegin;id<workEnd;++id)
    {
    //-- read --
    const float px=soa_px[id], py=soa_py[id];
    const float vx=soa_vx[id], vy=soa_vy[id];
    //-- compute --
    const float r=(px+xLimit)/(2.0f*xLimit);
    const float g=(py+yLimit)/(2.0f*yLimit);
    const float b=std::min(1.0f,sqrtf(vx*vx+vy*vy));
    //-- write --
    soa_r[id]=r; soa_g[id]=g; soa_b[id]=b;
    }
  }
}

//---- multi-CPU-based simulation of many animated points ----
void
cpuSimulation(const std::vector<std::string> &cmdLine,
              Point_SOA &points,
              float xAccel,
              float yAccel,
              float dt,
              float xLimit,
              float yLimit,
              int stepCount)
{
const double t0=crs::gettimeofday();
const int pointCount=crs::len(points.px);

//---- prepare data for parallel work ----
SharedData sd;
const bool enableSmt=crs::find(cmdLine,"smt")!=-1;
sd.cpuInfo=crs::detectCpuInfo(enableSmt);
const int threadCount=crs::len(sd.cpuInfo);
crs::out("using % threads\n",threadCount);
sd.td.resize(threadCount);

//---- prevent main thread from migrating to another CPU ----
crs::bindCurrentThreadToCpu(sd.cpuInfo[0].cpuId);

//---- launch background threads once for all ----
for(int i=1;i<threadCount;++i) // skip thread 0 (main)
  {
  sd.td[i].th=std::thread([index=i,&sd]()
    {
    //---- prevent this thread from migrating to another CPU ----
    crs::bindCurrentThreadToCpu(sd.cpuInfo[index].cpuId);

    for(int lastStep=0;;)
      {
      //---- wait for a new step ----
      int step;
      while(lastStep==(step=sd.step)) { /* busy-wait */ }
      lastStep=step;
      if(sd.done) { break; }

      //---- perform actual work for this step ----
      threadWork(index,sd);

      //---- signal end of this step ----
      --sd.inCurrentStep;
      }
    });
  }

const double t1=crs::gettimeofday();

for(int i=0;i<stepCount;++i)
  {
  //---- start a new step ----
  sd.points=&points;
  sd.xAccel=xAccel; sd.yAccel=yAccel; sd.dt=dt;
  sd.xLimit=xLimit; sd.yLimit=yLimit;
  sd.inCurrentStep=threadCount-1;
  sd.inMotion=threadCount;
  ++sd.step; // threads synchronise on this last change

  //---- work as thread 0 ----
  threadWork(0,sd);

  //---- wait for this step to end ----
  while(sd.inCurrentStep) { /* busy-wait */ }
  }

//---- signal end of work ----
sd.done=true;
++sd.step;

//---- wait for background threads to terminate ----
for(int i=1;i<threadCount;++i) // skip thread 0 (main)
  { sd.td[i].th.join(); }

//---- display performances ----
const double t2=crs::gettimeofday();
crs::out("CPU initialisation: % seconds\n"
         "CPU computation:    % seconds --> % Mp/s\n",
         t1-t0,t2-t1,1e-6*pointCount*stepCount/(t2-t1));
}

//---- GPU-based simulation of many animated points ----
void
gpuSimulation(const std::vector<std::string> &cmdLine,
              Point_SOA &points,
              float xAccel,
              float yAccel,
              float dt,
              float xLimit,
              float yLimit,
              int stepCount)
{
(void)cmdLine; // avoid ``unused parameter'' warning
(void)xAccel;
(void)yAccel;
(void)dt;
(void)xLimit;
(void)yLimit;
const double t0=crs::gettimeofday();

//---- choose GPU-program layout ----
const int groupSize=crs::Gpu::chooseWorkGroupSize();
const int groupCount=crs::Gpu::chooseWorkGroupCount();

//---- generate and build the motion GPU-program ----
crs::GpuProgram motionProgram(groupSize,groupCount,
  //
  // ... À COMPLÉTER {1} ...
  //
  // Déclarer quatre buffers en lecture-écriture pour contenir les données
  // des vecteurs de ``points'' qui correspondant à la position et à la
  // vitesse.
  //
  " READ_WRITE_BUFFER(0, float px[]; )               \n"
  " READ_WRITE_BUFFER(1, float py[]; )               \n"
  " READ_WRITE_BUFFER(2, float vx[]; )               \n"
  " READ_WRITE_BUFFER(3, float vy[]; )               \n"
  // ...
  "                                                  \n"
  //
  // ... À COMPLÉTER {2} ...
  //
  // Déclarer un paramètre de type ``int'' désignant le
  // nombre total de points.
  // Déclarer un paramètre de type ``vec2'' désignant les
  // limites des positions selon les axes x et y.
  // Déclarer un paramètre de type ``vec3'' désignant d'une
  // part le vecteur accélération (de type ``vec2'') et d'autre
  // part le pas de temps (de type ``float'').
  //
  " PARAMETER(0, int )                               \n"
  " const int count=PARAM_0.x;                       \n"
  "                                                  \n"
  " PARAMETER(1, vec2 )                              \n"
  " const vec2 limit=PARAM_1.xy;                     \n"
  "                                                  \n"
  " PARAMETER(2, vec3 )                              \n"
  " const vec2  accel=PARAM_2.xy;                    \n"
  " const float dt   =PARAM_2.z;                     \n"
  // ...
  "                                                  \n"
  " void                                             \n"
  " main(void)                                       \n"
  " {                                                \n"
  //
  // ... À COMPLÉTER {3} ...
  //
  // Réaliser la boucle qui assure que l'ensemble des indices de
  // calcul traitent bien le nombre total de points.
  // * Obtenir depuis les buffers la position et la vitesse du point
  //   à l'indice courant.
  // * Modifier la position selon la formule :
  //     position += (vitesse + accélération*0.5*dt) * dt
  // * Modifier la vitesse selon la formule :
  //     vitesse += accélération * dt
  // * Rester dans les limites imposées selon le principe :
  //     si position > limite
  //       position = limite
  //       si vitesse > 0.0, vitesse = - vitesse
  //     sinon si position < - limite
  //       position = - limite
  //       si vitesse < 0.0, vitesse = - vitesse
  //   (à effectuer indépendamment sur les axes x et y)
  // * Inscrire enfin dans les buffers les nouvelles position et vitesse
  //   du point à l'indice courant.
  //
  " for(int id=globalId;id<count;id+=GRID_SIZE)      \n"
  "   {                                              \n"
  "   //-- read --                                   \n"
  "   vec2 p=vec2(px[id],py[id]);                    \n"
  "   vec2 v=vec2(vx[id],vy[id]);                    \n"
  "   //-- compute --                                \n"
  "   p+=(v+accel*0.5*dt)*dt;                        \n"
  "   v+=accel*dt;                                   \n"
  "   if(p.x>limit.x)                                \n"
  "     { p.x=limit.x; if(v.x>=0.0) { v.x=-v.x; } }  \n"
  "   else if(p.x<-limit.x)                          \n"
  "     { p.x=-limit.x; if(v.x<=0.0) { v.x=-v.x; } } \n"
  "   if(p.y>limit.y)                                \n"
  "     { p.y=limit.y; if(v.y>=0.0) { v.y=-v.y; } }  \n"
  "   else if(p.y<-limit.y)                          \n"
  "     { p.y=-limit.y; if(v.y<=0.0) { v.y=-v.y; } } \n"
  "   //-- write --                                  \n"
  "   px[id]=p.x; py[id]=p.y;                        \n"
  "   vx[id]=v.x; vy[id]=v.y;                        \n"
  "   }                                              \n"
  // ...
  " }                                                \n");

//---- generate and build the colour GPU-program ----
crs::GpuProgram colourProgram(groupSize,groupCount,
  //
  // ... À COMPLÉTER {4} ...
  //
  // Déclarer quatre buffers en lecture seule pour contenir les données
  // des vecteurs de ``points'' qui correspondent à la position et à la
  // vitesse.
  // Déclarer trois buffers en écriture seule pour contenir les données
  // des vecteurs de ``points'' qui correspondent à la couleur.
  //
  "  READ_ONLY_BUFFER(0, float px[]; )               \n"
  "  READ_ONLY_BUFFER(1, float py[]; )               \n"
  "  READ_ONLY_BUFFER(2, float vx[]; )               \n"
  "  READ_ONLY_BUFFER(3, float vy[]; )               \n"
  " WRITE_ONLY_BUFFER(4, float r[];  )               \n"
  " WRITE_ONLY_BUFFER(5, float g[];  )               \n"
  " WRITE_ONLY_BUFFER(6, float b[];  )               \n"
  // ...
  "                                                  \n"
  //
  // ... À COMPLÉTER {5} ...
  //
  // Déclarer un paramètre de type ``int'' désignant le
  // nombre total de points.
  // Déclarer un paramètre de type ``vec2'' désignant les
  // limites des positions selon les axes x et y.
  //
  " PARAMETER(0, int )                               \n"
  " const int count=PARAM_0.x;                       \n"
  "                                                  \n"
  " PARAMETER(1, vec2 )                              \n"
  " const vec2 limit=PARAM_1.xy;                     \n"
  // ...
  "                                                  \n"
  " void                                             \n"
  " main(void)                                       \n"
  " {                                                \n"
  //
  // ... À COMPLÉTER {6} ...
  //
  // Réaliser la boucle qui assure que l'ensemble des indices de
  // calcul traitent bien le nombre total de points.
  // * Obtenir depuis les buffers la position et la vitesse du point
  //   à l'indice courant.
  // * Calculer les composantes rouge et verte selon la formule :
  //     composante = (position + limite) / (2.0 * limite)
  //   (considérer l'axe x pour la rouge et l'axe y pour la verte)
  // * Calculer la composante bleue selon la formule :
  //     composante = min(1.0, norme_de_la_vitesse)
  // * Inscrire enfin dans les buffers la nouvelle couleur
  //   du point à l'indice courant.
  //
  " for(int id=globalId;id<count;id+=GRID_SIZE)      \n"
  "   {                                              \n"
  "   //-- read --                                   \n"
  "   const vec2 p=vec2(px[id],py[id]);              \n"
  "   const vec2 v=vec2(vx[id],vy[id]);              \n"
  "   //-- compute --                                \n"
  "   const vec3 c=vec3((p.x+limit.x)/(2.0*limit.x), \n"
  "                     (p.y+limit.y)/(2.0*limit.y), \n"
  "                     min(1.0,length(v)));         \n"
  "   //-- write --                                  \n"
  "   r[id]=c.r; g[id]=c.g; b[id]=c.b;               \n"
  "   }                                              \n"
  // ...
  " }                                                \n");

//---- allocate suitable GPU-buffers ----
const int pointCount=crs::len(points.px);
//
// ... À COMPLÉTER {7} ...
//
// Créer sur le GPU les buffers nécessaires aux programmes.
// Ils doivent être dimensionnés pour contenir les mêmes données que les
// vecteurs de ``points''.
//
crs::GpuBuffer gpuPx(pointCount*sizeof(points.px[0]));
crs::GpuBuffer gpuPy(pointCount*sizeof(points.py[0]));
crs::GpuBuffer gpuVx(pointCount*sizeof(points.vx[0]));
crs::GpuBuffer gpuVy(pointCount*sizeof(points.vy[0]));
crs::GpuBuffer gpuR(pointCount*sizeof(points.r[0]));
crs::GpuBuffer gpuG(pointCount*sizeof(points.g[0]));
crs::GpuBuffer gpuB(pointCount*sizeof(points.b[0]));
// ...

//---- transfer data from host to GPU ----
crs::Gpu::flush(true);
const double t1=crs::gettimeofday();
//
// ... À COMPLÉTER {8} ...
//
// Rendre le contenu des vecteurs de ``points'' disponible dans les buffers
// correspondants sur le GPU.
//
gpuPx.fromHost(points.px.data());
gpuPy.fromHost(points.py.data());
gpuVx.fromHost(points.vx.data());
gpuVy.fromHost(points.vy.data());
gpuR.fromHost(points.r.data());
gpuG.fromHost(points.g.data());
gpuB.fromHost(points.b.data());
// ...

for(int i=0;i<stepCount;++i)
  {
  //---- launch motion GPU-program with its buffers and parameters ----
  //
  // ... À COMPLÉTER {9} ...
  //
  // Préciser à ``motionProgram'' les buffers qu'il doit utiliser ainsi que
  // les paramètres ``pointCount'', ``xLimit'', ``yLimit'',
  // ``xAccel'', ``yAccel'' et ``dt'',
  // et lancer enfin son exécution.
  //
  motionProgram.buffer(0,gpuPx)
               .buffer(1,gpuPy)
               .buffer(2,gpuVx)
               .buffer(3,gpuVy)
               .param_int(0,pointCount)
               .param_vec2(1,xLimit,yLimit)
               .param_vec3(2,xAccel,yAccel,dt)
               .call();
  // ...
  if(!(i%10)) // once out of ten times
    {
    //---- launch colour GPU-program with its buffers and parameters ----
    //
    // ... À COMPLÉTER {10} ...
    //
    // Préciser à ``colourProgram'' les buffers qu'il doit utiliser ainsi que
    // les paramètres ``pointCount'', ``xLimit'' et ``yLimit'',
    // et lancer enfin son exécution.
    //
    colourProgram.buffer(0,gpuPx)
                 .buffer(1,gpuPy)
                 .buffer(2,gpuVx)
                 .buffer(3,gpuVy)
                 .buffer(4,gpuR)
                 .buffer(5,gpuG)
                 .buffer(6,gpuB)
                 .param_int(0,pointCount)
                 .param_vec2(1,xLimit,yLimit)
                 .call();
    // ...
    }
  }

//---- transfer data from GPU to host ----
//
// ... À COMPLÉTER {11} ...
//
// Obtenir le contenu des vecteurs de ``points'' depuis les buffers
// correspondants sur le GPU.
//
gpuPx.toHost(points.px.data());
gpuPy.toHost(points.py.data());
gpuVx.toHost(points.vx.data());
gpuVy.toHost(points.vy.data());
gpuR.toHost(points.r.data());
gpuG.toHost(points.g.data());
gpuB.toHost(points.b.data());
// ...

//---- display performances ----
crs::Gpu::flush(true);
const double t2=crs::gettimeofday();
crs::out("GPU initialisation: % seconds\n"
         "GPU computation:    % seconds --> % Mp/s\n",
         t1-t0,t2-t1,1e-6*pointCount*stepCount/(t2-t1));
}

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- prepare application data ----
const bool big=crs::find(args,"big")!=-1;
const int pointCount=big ? 5'000'000 : 100'000;
const int stepCount=big ? 200 : 10'000;
std::srand(int(std::time(nullptr)));
const float angle=M_2PIf*float(std::rand())/float(RAND_MAX);
const float xAccel=cosf(angle);
const float yAccel=sinf(angle);
const float dt=0.0001f;
const float xLimit=1.0f;
const float yLimit=0.5f;
crs::out("% points, % steps\n",pointCount,stepCount);
Point_SOA points;
for(int i=0;i<pointCount;++i)
  {
  points.px.push_back(2.0f*xLimit*(0.5f-float(std::rand())/float(RAND_MAX)));
  points.py.push_back(2.0f*yLimit*(0.5f-float(std::rand())/float(RAND_MAX)));
  points.vx.push_back(2.0f*(0.5f-float(std::rand())/float(RAND_MAX)));
  points.vy.push_back(2.0f*(0.5f-float(std::rand())/float(RAND_MAX)));
  points.r.push_back(0.0f);
  points.g.push_back(0.0f);
  points.b.push_back(0.0f);
  }

//---- use multi-CPU if requested ----
Point_SOA cpuPoints;
if(crs::find(args,"cpu")!=-1)
  {
  cpuPoints=points;
  cpuSimulation(args,cpuPoints,xAccel,yAccel,dt,xLimit,yLimit,stepCount);
  }

//---- use GPU ----
gpuSimulation(args,points,xAccel,yAccel,dt,xLimit,yLimit,stepCount);

//---- check CPU/GPU consistency ----
if(!cpuPoints.px.empty())
  {
  int mismatchCount=0;
  for(int i=0;i<pointCount;++i)
    {
    const double dx=cpuPoints.px[i]-points.px[i];
    const double dy=cpuPoints.py[i]-points.py[i];
    const double epsilon=1e-3;
    if((dx*dx+dy*dy)>epsilon*epsilon)
      { ++mismatchCount; }
    }
  if(mismatchCount)
    { crs::out("!!! CPU/GPU mismatch for % points !!!\n",mismatchCount); }
  }

return 0;
}

//----------------------------------------------------------------------------
