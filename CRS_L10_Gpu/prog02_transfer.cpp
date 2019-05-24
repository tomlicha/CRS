//----------------------------------------------------------------------------

#include "crsGpu.hpp"

#define ASSUMED_CACHELINE_SIZE 64

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
float xFactor;
float yFactor;
int elemCount;
const float *X;
const float *Y;
float *Z;
};

//---- the actual work done by each thread ----
void
threadTask(int index,
           SharedData &sd)
{
//---- prevent this thread from migrating to another CPU ----
crs::bindCurrentThreadToCpu(sd.cpuInfo[index].cpuId);

//---- determine the part of the work to be done by this thread ----
const int64_t count=sd.elemCount;
const int64_t workBegin=count*index/crs::len(sd.td);
const int64_t workEnd=std::min(count,count*(index+1)/crs::len(sd.td));

//---- compute ----
const float xFactor=sd.xFactor;
const float yFactor=sd.yFactor;
const float * RESTRICT X=sd.X;
const float * RESTRICT Y=sd.Y;
float * RESTRICT Z=sd.Z;
TRY_TO_VECTORISE
for(int64_t id=workBegin;id<workEnd;++id)
  { Z[id]=xFactor*X[id]+yFactor*Y[id]; }
}

//---- multi-CPU-based linear combination of two vectors ----
void
cpuLinearCombination(const std::vector<std::string> &cmdLine,
                     float xFactor,
                     float yFactor,
                     const std::vector<float> &X,
                     const std::vector<float> &Y,
                     std::vector<float> &Z)
{
const double t0=crs::gettimeofday();

//---- prepare data for parallel work ----
SharedData sd;
const bool enableSmt=crs::find(cmdLine,"smt")!=-1;
sd.cpuInfo=crs::detectCpuInfo(enableSmt);
const int threadCount=crs::len(sd.cpuInfo);
crs::out("using % threads\n",threadCount);
sd.td.resize(threadCount);
sd.elemCount=crs::len(Z);
sd.xFactor=xFactor;
sd.yFactor=yFactor;
sd.X=X.data();
sd.Y=Y.data();
sd.Z=Z.data();

const double t1=crs::gettimeofday();

//---- launch parallel work ----
for(int i=0;i<threadCount;++i)
  { sd.td[i].th=std::thread(threadTask,i,std::ref(sd)); }

//---- wait for parallel work to terminate ----
for(int i=0;i<threadCount;++i)
  { sd.td[i].th.join(); }

//---- display performances ----
const double t2=crs::gettimeofday();
crs::out("CPU initialisation: % seconds\n"
         "CPU computation:    % seconds for % elements\n",
         t1-t0,t2-t1,sd.elemCount);
}

//---- GPU-based linear combination of two vectors ----
void
gpuLinearCombination(const std::vector<std::string> &cmdLine,
                     float xFactor,
                     float yFactor,
                     const std::vector<float> &X,
                     const std::vector<float> &Y,
                     std::vector<float> &Z)
{
(void)cmdLine; // avoid ``unused parameter'' warning
(void)xFactor;
(void)yFactor;
(void)X;
(void)Y;
const double t0=crs::gettimeofday();

//---- choose GPU-program layout ----
const int groupSize=crs::Gpu::chooseWorkGroupSize();
const int groupCount=crs::Gpu::chooseWorkGroupCount();

//---- generate and build GPU-program ----
crs::GpuProgram program(groupSize,groupCount,
  //
  // ... À COMPLÉTER {1} ...
  //
  // Déclarer deux buffers en lecture seule pour obtenir les valeurs
  // des vecteurs ``X'' et ``Y''.
  // Déclarer un buffer en écriture seule pour fournir les valeurs
  // calculées du vecteur ``Z''.
  //

  // ...
  "                                             \n"
  //
  // ... À COMPLÉTER {2} ...
  //
  // Déclarer un paramètre de type ``int'' désignant le
  // nombre total d'éléments de chaque vecteur.
  // Déclarer un paramètre de type ``vec2'' désignant les
  // deux facteurs multiplicatifs pour ``X'' et ``Y''.
  //

  // ...
  "                                             \n"
  " void                                        \n"
  " main(void)                                  \n"
  " {                                           \n"
  //
  // ... À COMPLÉTER {3} ...
  //
  // Réaliser la boucle qui assure que l'ensemble des indices de
  // calcul traitent bien le nombre total d'éléments.
  // Chaque itération réalisera dans ``Z'', à l'indice courant, la
  // combinaison linéaire de ``X'' et ``Y'' selon les facteurs reçus en
  // paramètres.
  //

  // ...
  " }                                           \n");

//---- allocate suitable GPU-buffers ----
const int elemCount=crs::len(Z);
//
// ... À COMPLÉTER {4} ...
//
// Créer sur le GPU les trois buffers nécessaires au programme.
// Ils doivent être dimensionnés pour contenir les mêmes données que les
// vecteurs ``X'', ``Y'' et ``Z''.
//

// ...

//---- transfer data from host to GPU ----
crs::Gpu::flush(true);
const double t1=crs::gettimeofday();
//
// ... À COMPLÉTER {5} ...
//
// Rendre le contenu de ``X'' et ``Y'' disponible dans les buffers
// correspondants sur le GPU.
//

// ...

//---- launch GPU-program with its buffers and parameters ----
//
// ... À COMPLÉTER {6} ...
//
// Préciser à ``program'' les trois buffers qu'il doit utiliser ainsi que
// les paramètres ``elemCount'', ``xFactor'' et ``yFactor'',
// et lancer enfin son exécution.
//

// ...

//---- transfer data from GPU to host ----
//
// ... À COMPLÉTER {7} ...
//
// Obtenir le contenu de ``Z'' depuis le buffer
// correspondant sur le GPU.
//

// ...

//---- display performances ----
crs::Gpu::flush(true);
const double t2=crs::gettimeofday();
crs::out("GPU initialisation: % seconds\n"
         "GPU computation:    % seconds for % elements\n",
         t1-t0,t2-t1,elemCount);
}

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- prepare application data ----
const bool big=crs::find(args,"big")!=-1;
const int elemCount=big ? 50'000'000 : 1'000'000;
std::srand(int(std::time(nullptr)));
const float xFactor=1.41f,yFactor=0.35f;
std::vector<float> X(elemCount),Y(elemCount),Z(elemCount);
for(int i=0;i<elemCount;++i)
  {
  X[i]=float(std::rand())/float(RAND_MAX);
  Y[i]=float(std::rand())/float(RAND_MAX);
  }

//---- use multi-CPU if requested ----
std::vector<float> cpuZ;
if(crs::find(args,"cpu")!=-1)
  {
  cpuZ.resize(elemCount);
  cpuLinearCombination(args,xFactor,yFactor,X,Y,cpuZ);
  }

//---- use GPU ----
gpuLinearCombination(args,xFactor,yFactor,X,Y,Z);

//---- check CPU/GPU consistency ----
if(!cpuZ.empty())
  {
  int mismatchCount=0;
  for(int i=0;i<elemCount;++i)
    {
    if(::fabsf(Z[i]-cpuZ[i])>1e-6f)
      { ++mismatchCount; }
    }
  if(mismatchCount)
    { crs::out("!!! CPU/GPU mismatch for % elements !!!\n",mismatchCount); }
  }
    
return 0;
}

//----------------------------------------------------------------------------
