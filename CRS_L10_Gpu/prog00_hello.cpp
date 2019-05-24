//----------------------------------------------------------------------------

#include "crsGpu.hpp"

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- display GPU properties ----
crs::out(crs::Gpu::showProperties());

//---- prepare host data ----
auto pattern={72,100,106,105,107,27,65,73,77,23,109,100,102,95,86,18,16,15};
const int patternSize=crs::len(pattern);
std::vector<int32_t> hostData;
while(crs::len(hostData)<1000)
  { hostData.insert(hostData.end(),pattern); }
const int dataSize=crs::len(hostData);

//---- choose GPU-program layout ----
const int groupSize=crs::Gpu::chooseWorkGroupSize();
const int groupCount=crs::Gpu::chooseWorkGroupCount();

//---- generate and build GPU-program ----
crs::GpuProgram program(groupSize,groupCount,
  " READ_WRITE_BUFFER(0, int data[]; )          \n"
  "                                             \n"
  " PARAMETER(0, ivec2 )                        \n"
  " const int count =PARAM_0.x,                 \n"
  "           modulo=PARAM_0.y;                 \n"
  "                                             \n"
  " void                                        \n"
  " main(void)                                  \n"
  " {                                           \n"
  " for(int id=globalId;id<count;id+=GRID_SIZE) \n"
  "   {                                         \n"
  "   data[id]+=(id%modulo);                    \n"
  "   }                                         \n"
  " }                                           \n");
crs::out(
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n%"
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",
  program.sourceCode());

//---- allocate suitable GPU-buffer ----
crs::GpuBuffer gpuData(dataSize*sizeof(int32_t));

//---- transfer data from host to GPU ----
gpuData.fromHost(hostData.data());

//---- launch GPU-program with its buffers and parameters ----
program.buffer(0,gpuData)
       .param_vec2(0,dataSize,patternSize)
       .call();

//---- transfer data from GPU to host ----
gpuData.toHost(hostData.data());

//---- make use of computed data ----
std::string msg; for(auto i: hostData) { msg+=char(i); }
crs::out("%\n",msg);

return 0;
}

//----------------------------------------------------------------------------
