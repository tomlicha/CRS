//----------------------------------------------------------------------------

#include "image.hpp"

void
histogramEqualisation(Pixel *result,
                      const Pixel *image,
                      int width,
                      int height,
                      int histoR[256],
                      int histoG[256],
                      int histoB[256])
{
//---- compute histogram ----
::memset(histoR,0,256*sizeof(*histoR));
::memset(histoG,0,256*sizeof(*histoG));
::memset(histoB,0,256*sizeof(*histoB));
const int size=width*height;
for(int i=0;i<size;++i)
  {
  const Pixel p=image[i];
  ++histoR[p.r()];
  ++histoG[p.g()];
  ++histoB[p.b()];
  }

//---- accumulate and equalise histogram ----
const double norm=255.0/size;
for(int prevR=0,prevG=0,prevB=0,i=0;i<256;++i)
  {
  histoR[i]=int(norm*(prevR+=histoR[i]));
  histoG[i]=int(norm*(prevG+=histoG[i]));
  histoB[i]=int(norm*(prevB+=histoB[i]));
  }

//---- adjust intensities ----
for(int i=0;i<size;++i)
  {
  const Pixel p=image[i];
  result[i].r()=uint8_t(histoR[p.r()]);
  result[i].g()=uint8_t(histoG[p.g()]);
  result[i].b()=uint8_t(histoB[p.b()]);
  }
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

//---- process every image in the sequence ----
int width,height;
Pixel *result=nullptr;
while(const Pixel *image=seq.next(width,height))
  {
  //---- ensure storage is large enough for result ----
  const int size=width*height;
  if(size>crs::len(storage)) { storage.resize(size); }
  result=storage.data();

  //---- perform histogram normalisation ----
  int histoR[256];
  int histoG[256];
  int histoB[256];
  histogramEqualisation(result,image,width,height,
                        histoR,histoG,histoB);
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
