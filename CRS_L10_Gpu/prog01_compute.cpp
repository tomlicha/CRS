//----------------------------------------------------------------------------

#include "crsGpu.hpp"

#define ASSUMED_CACHELINE_SIZE 64

//---- some data to be kept with each thread ----
struct ThreadData
{
std::thread th;
std::array<uint32_t,2> seed;
int64_t insideCount;
// ensure at least two _aligned_ cache-lines between ``hot data''
uint8_t padding[3*ASSUMED_CACHELINE_SIZE];
};

//---- some data common to every thread ----
struct SharedData
{
std::vector<ThreadData> td;
std::vector<crs::CpuInfo> cpuInfo;
int count;
};

//---- simple random generator ----
float // random value in [0.0,1.0]
rnd(std::array<uint32_t,2> &seed)
{
//  Adapted from MWC generator described in George Marsaglia's post
//  ``Random numbers for C: End, at last?'' on sci.stat.math,
//  sci.math, sci.math.num-analysis, sci.crypt, sci.physics.research,
//  comp.os.msdos.djgpp (Thu, 21 Jan 1999 03:08:52 GMT)
seed[0]=36969*(seed[0]&0x0000FFFFU)+(seed[0]>>16);
seed[1]=18000*(seed[1]&0x0000FFFFU)+(seed[1]>>16);
const uint32_t value=(seed[0]<<16)+seed[1];
const float div=1.0f/8388607.0f; // 23-bit mantissa
return float(value&0x007FFFFFU)*div;
}

//---- the actual work done by each thread ----
void
threadTask(int index,
           SharedData &sd)
{
//---- access thread-specific data ----
ThreadData &td=sd.td[index];

//---- prevent this thread from migrating to another CPU ----
crs::bindCurrentThreadToCpu(sd.cpuInfo[index].cpuId);

//---- determine the part of the work to be done by this thread ----
const int count=sd.count;
const int workBegin=count*index/crs::len(sd.td);
const int workEnd=std::min(count,count*(index+1)/crs::len(sd.td));

//---- compute ----
auto seed=td.seed;
int64_t insideCount=0;
for(int id=workBegin;id<workEnd;++id)
  {
  for(int repeat=0;repeat<1000;++repeat)
    {
    const float x=rnd(seed);
    const float y=rnd(seed);
    if((x*x+y*y)<=1.0f) { ++insideCount; }
    }
  }
td.insideCount=insideCount;
}

//---- multi-CPU-based Monte-Carlo estimation of PI ----
void
cpuEstimation(const std::vector<std::string> &cmdLine,
              int count)
{
const double t0=crs::gettimeofday();

//---- prepare data for parallel work ----
SharedData sd;
const bool enableSmt=crs::find(cmdLine,"smt")!=-1;
sd.cpuInfo=crs::detectCpuInfo(enableSmt);
const int threadCount=crs::len(sd.cpuInfo);
crs::out("using % threads\n",threadCount);
sd.td.resize(threadCount);
sd.count=count;

const double t1=crs::gettimeofday();

//---- launch parallel work ----
for(int i=0;i<threadCount;++i)
  {
  sd.td[i].seed[0]=(std::rand()<<16)+std::rand();
  sd.td[i].seed[1]=(std::rand()<<16)+std::rand();
  sd.td[i].th=std::thread(threadTask,i,std::ref(sd));
  }

//---- wait for parallel work to terminate and collect results ----
int64_t insideCount=0;
for(int i=0;i<threadCount;++i)
  {
  sd.td[i].th.join();
  insideCount+=sd.td[i].insideCount;
  }

//---- display performances ----
const double t2=crs::gettimeofday();
const int64_t pointCount=1000*int64_t(count);
const double estimatedPi=double(insideCount)*4.0/double(pointCount);
const double delta=estimatedPi-M_PI;
crs::out("CPU initialisation: % seconds\n"
         "CPU computation:    % seconds\n"
         "% points, % inside, estimated=%%%, delta=%\n",
         t1-t0,t2-t1,pointCount,insideCount,
         std::setprecision(12),estimatedPi,std::setprecision(6),delta);
}

//---- GPU-based Monte-Carlo estimation of PI ----
void
gpuEstimation(const std::vector<std::string> &cmdLine,
              int count)
{
(void)cmdLine; // avoid ``unused parameter'' warning
const double t0=crs::gettimeofday();

//---- choose GPU-program layout ----
const int groupSize=crs::Gpu::chooseWorkGroupSize();
const int groupCount=crs::Gpu::chooseWorkGroupCount();

//---- prepare host data ----
const int gridSize=groupSize*groupCount;
std::vector<int32_t> hostCounts(gridSize);

//---- generate and build GPU-program ----
crs::GpuProgram program(groupSize,groupCount,
  //
  // ... À COMPLÉTER {1} ...
  //
  // Déclarer un buffer en écriture seule pour fournir les comptes des
  // points aléatoires figurant dans le quart de disque (ils seront
  // récupérés dans ``hostCounts'').
  //

  // ...
  "    WRITE_ONLY_BUFFER(0, int counts[]; )                      \n"
  //
  // ... À COMPLÉTER {2} ...
  //
  // Déclarer un paramètre de type ``int'' désignant le
  // nombre total de milliers de points aléatoires à tirer ; il servira
  // à initialiser une constante de type ``int'' nommée ``count''.
  // Déclarer un paramètre de type ``vec4'' désignant quatre réels
  // aléatoires provenant de l'hôte ; il servira à initialiser une
  // constante de type ``vec4'' nommée ``hostSeed''.
  //

  // ...
  " PARAMETER(0, int )                                    \n"
  " const int count =PARAM_0;                             \n"
  " PARAMETER(1, vec4 )                                   \n"
  " const vec4 hostSeed=PARAM_1;                          \n"
  " uvec2 // initial seed for random generation           \n"
  " makeRndSeed(vec4 hs)                                  \n"
  " {                                                     \n"
  " const float i=(globalId+1)/float(GRID_SIZE);          \n"
  " const vec2 s0=vec2(hs.x,i);                           \n"
  " const vec2 s1=vec2(i,hs.y);                           \n"
  " const vec2 s2=vec2(i,hs.z);                           \n"
  " const vec2 s3=vec2(hs.w,i);                           \n"
  " const vec2 c=vec2(12.9898,78.233);                    \n"
  " const vec4 d=vec4(dot(s0,c),dot(s1,c),                \n"
  "                   dot(s2,c),dot(s3,c));               \n"
  " const vec4 s=sin(mod(d,acos(-1.0)));                  \n"
  " const uvec4 f=uvec4(65535.0*fract(s*43758.5453));     \n"
  " return (f.xy<<16)+f.zw;                               \n"
  " }                                                     \n"
  "                                                       \n"
  " float // random value in [0.0;1.0]                    \n"
  " rnd(inout uvec2 seed)                                 \n"
  " {                                                     \n"
  " seed=uvec2(36969,18000)*(seed&0x0000FFFF)+(seed>>16); \n"
  " const uint value=(seed.x<<16)+seed.y;                 \n"
  " const float div=1.0/8388607.0; // 23-bit mantissa     \n"
  " return (value&0x007FFFFF)*div;                        \n"
  " }                                                     \n"
  "                                                       \n"
  " void                                                  \n"
  " main(void)                                            \n"
  " {                                                     \n"
  " uvec2 seed=makeRndSeed(hostSeed);                     \n"
  //
  // ... À COMPLÉTER {3} ...
  //
  // Réaliser la boucle qui assure que l'ensemble des indices de calcul
  // traitent bien le nombre total de milliers de points aléatoires à tirer.
  // * À chaque indice de calcul il faudra effectuer mille tirages de
  //   points aléatoires
  // * Chaque point aléatoire sera obtenu par deux appels à ``rnd(seed)''
  // * Compter à chaque fois que le produit scalaire du point avec
  //   lui-même est inférieur ou égal à ``1.0'' (dans le quart de disque).
  // Inscrire enfin dans le buffer le compte obtenu par l'indice de calcul
  // ``globalId''.
  //
  " int countScalaire=0;                                     \n"
 " for(int id=globalId;id<count;id+=GRID_SIZE) \n"
  "     for(int i = 0;i<1000;++i){             \n"
  "       const vec2 p=  vec2(rnd(seed),rnd(seed));  \n"
  "       if(dot(p,p)<=1.0) { ++countScalaire; }    \n"
  "     }                                      \n"
  "                                             \n"
  "counts[globalId]= countScalaire;            \n"
  // ...
  " }                                                     \n");

//---- allocate suitable GPU-buffer ----
//
// ... À COMPLÉTER {4} ...
//
// Créer sur le GPU le buffer nécessaire au programme.
// Il doit être dimensionné pour contenir les mêmes
// données que le vecteur ``hostCounts''.
//
crs::GpuBuffer gpuCounts(hostCounts.size()*sizeof(hostCounts[0]));
// ...

//---- launch GPU-program with its buffers and parameters ----
crs::Gpu::flush(true);
const double t1=crs::gettimeofday();
const float hostSeed[4]={ float(std::rand())/float(RAND_MAX),
                          float(std::rand())/float(RAND_MAX),
                          float(std::rand())/float(RAND_MAX),
                          float(std::rand())/float(RAND_MAX) };
(void)hostSeed; // avoid ``unused variable'' warning
//
// ... À COMPLÉTER {5} ...
// 
// Préciser à ``program'' le buffer qu'il doit utiliser ainsi que le
// paramètre ``count'' et les quatre réels aléatoires de ``hostSeed'',
// et lancer enfin son exécution.
//
program.buffer(0,gpuCounts)
       .param_int(0,count)
       .param_vec4(1,hostSeed[0],hostSeed[1],hostSeed[2],hostSeed[3])
       .call();

// ...

//---- transfer data from GPU to host ----
//
// ... À COMPLÉTER {6} ...
//
// Obtenir le contenu de ``hostCounts'' depuis le buffer
// correspondant sur le GPU.
//
gpuCounts.toHost(hostCounts.data());
// ...

//---- make use of computed data ----
int64_t insideCount=0;
for(int i=0;i<gridSize;++i)
  { insideCount+=hostCounts[i]; }

//---- display performances ----
crs::Gpu::flush(true);
const double t2=crs::gettimeofday();
const int64_t pointCount=1000*int64_t(count);
const double estimatedPi=double(insideCount)*4.0/double(pointCount);
const double delta=estimatedPi-M_PI;
crs::out("GPU initialisation: % seconds\n"
         "GPU computation:    % seconds\n"
         "% points, % inside, estimated=%%%, delta=%\n",
         t1-t0,t2-t1,pointCount,insideCount,
         std::setprecision(12),estimatedPi,std::setprecision(6),delta);
}

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- prepare application data ----
const bool big=crs::find(args,"big")!=-1;
const int count=big ? 10'000'000 : 1'000'000;
std::srand(int(std::time(nullptr)));

//---- use multi-CPU if requested ----
if(crs::find(args,"cpu")!=-1)
  { cpuEstimation(args,count); }

//---- use GPU ----
gpuEstimation(args,count);

return 0;
}

//----------------------------------------------------------------------------
