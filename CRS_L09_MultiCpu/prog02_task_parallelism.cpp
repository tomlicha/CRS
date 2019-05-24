//----------------------------------------------------------------------------

#include "image.hpp"

#define ASSUMED_CACHELINE_SIZE 64

//---- some data to be kept around each thread ----
struct ThreadData
{
std::thread th;
int histo[256];
// ensure at least two _aligned_ cache-lines between ``hot data''
uint8_t padding[3*ASSUMED_CACHELINE_SIZE];
};

//---- some data common to every thread ----
struct SharedData
{
std::vector<ThreadData> td;
const Pixel *image;
int width,height;
Pixel *result;
};

//---- the actual work done by each thread ----
void
threadTask(int index,
           SharedData &sd)
{
//---- access thread-specific data ----
ThreadData &td=sd.td[index];

//---- compute histogram ----
::memset(td.histo,0,256*sizeof(*td.histo));
const int size=sd.width*sd.height;
for(int i=0;i<size;++i)
  { ++td.histo[sd.image[i][index]]; }

//---- accumulate and equalise histogram ----
const double norm=255.0/size;
for(int prev=0,i=0;i<256;++i)
  { td.histo[i]=int(norm*(prev+=td.histo[i])); }

//---- adjust intensities ----
for(int i=0;i<size;++i)
  { sd.result[i][index]=uint8_t(td.histo[sd.image[i][index]]); }
}

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- prepare images and storage for result ----
ImageSequence seq(args,3000);
std::vector<Pixel> storage;
const double t0=crs::gettimeofday();

//---- prepare data for parallel work ----
SharedData sd;
const int threadCount=3; // 3 tasks: red green blue
sd.td.resize(threadCount);

//---- process every image in the sequence ----
int width,height;
Pixel *result=nullptr;
while(const Pixel *image=seq.next(width,height))
  {
  (void)image; // avoid ``unused variable'' warning

  //---- ensure storage is large enough for result ----
  const int size=width*height;
  if(size>crs::len(storage)) { storage.resize(size); }
  result=storage.data();

  //---- launch parallel work ----
  //
  // ... À COMPLÉTER {1} ...
  //
  // Renseigner les champs ``image'', ``width'', ``height'' et ``result''
  // de la structure partagée ``sd'' avec les variables locales qui viennent
  // d'être déterminées pour cette nouvelle image de la séquence.
  // Puis, pour chacun des ``threadCount'' éléments de ``sd.td'', initialiser
  // le champ ``th'' avec un thread qui exécute la fonction ``threadTask()''.
  // Celle-ci doit recevoir, en plus d'un indice numérotant les threads,
  // une _référence_ sur la donnée partagée ``sd'' à laquelle les threads
  // accéderont tous.
  //
  sd.image=image;
  sd.width=width;
  sd.height=height;
  sd.result=result;
  for (int i=0;i<threadCount;i++){
    sd.td[i].th=std::thread(threadTask,i,std::ref(sd));
  }
  // ...

  //---- wait for parallel work to terminate ----
  //
  // ... À COMPLÉTER {2} ...
  //
  // Parcourir ``sd.td'' afin d'effectuer l'opération ``join()'' sur chacun
  // des threads qu'il désigne.
  //
  for (int i=0;i<threadCount;i++){
    sd.td[i].th.join();
  }
  // ...
  }

//---- display performances ----
const double duration=crs::gettimeofday()-t0;
crs::out("% images in % seconds (% per second)\n",
         seq.current(),duration,seq.current()/duration);

//---- save last result (to check correctness) ----
if(result) { saveImage(result,width,height,"output_last.ppm"); }

return 0;
}

//----------------------------------------------------------------------------
