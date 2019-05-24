//----------------------------------------------------------------------------

#include "crsGpu.hpp"

namespace crs {

static void createDefaultGlContext(void);
static void destroyDefaultGlContext(void);

#define THROW_GPU_FAILURE                                            \
        do                                                           \
          {                                                          \
          throw std::runtime_error(txt("%:%:%() Gpu failure",        \
                                       __FILE__,__LINE__,__func__)); \
          } while(0)

//----------------------------------------------------------------------------

GpuBuffer::GpuBuffer(intptr_t size)
: _id{0}
, _size{0}
, _mapped{false}
{
(void)Gpu::properties(); // ensure initialisation
resize(size);
}

GpuBuffer::GpuBuffer(GpuBuffer &&rhs)
: _id{rhs._id}
, _size{rhs._size}
, _mapped{rhs._mapped}
{
rhs._id=0;
rhs._size=0;
rhs._mapped=0;
}

GpuBuffer & // itself
GpuBuffer::operator=(GpuBuffer &&rhs)
{
if(&rhs!=this)
  {
  resize(0);
  _id=rhs._id; rhs._id=0;
  _size=rhs._size; rhs._size=0;
  _mapped=rhs._mapped; rhs._mapped=false;
  }
return *this;
}

GpuBuffer::~GpuBuffer()
{
resize(0);
}

void
GpuBuffer::resize(intptr_t size)
{
if(_mapped)
  { throw std::runtime_error("cannot resize GPU buffer while mapped"); }
if(_size)
  {
  glDeleteBuffers(1,&_id);
  ON_GL_ERROR({ THROW_GPU_FAILURE; });
  }
_id=0;
_size=size;
if(_size)
  {
  glGenBuffers(1,&_id);
  ON_GL_ERROR({ THROW_GPU_FAILURE; });
  glBindBuffer(GL_SHADER_STORAGE_BUFFER,_id);
  ON_GL_ERROR({ THROW_GPU_FAILURE; });
  glBufferData(GL_SHADER_STORAGE_BUFFER,
               _size,(const void *)0,
               GL_STATIC_COPY); // suitable for long term read/write on GPU
  ON_GL_ERROR({ THROW_GPU_FAILURE; });
  }
}

void * // mapped address
GpuBuffer::_map(bool readAccess,
                bool writeAccess,
                intptr_t size,
                intptr_t offset)
{
if(!size) { size=_size-offset; }
glBindBuffer(GL_SHADER_STORAGE_BUFFER,_id);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
GLbitfield access=0;
if(readAccess)  { access|=GL_MAP_READ_BIT;  }
if(writeAccess) { access|=GL_MAP_WRITE_BIT; }
void *addr=glMapBufferRange(GL_SHADER_STORAGE_BUFFER,offset,size,access);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
_mapped=true;
return addr;
}

void
GpuBuffer::unmap()
{
glBindBuffer(GL_SHADER_STORAGE_BUFFER,_id);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
_mapped=false;
}

void
GpuBuffer::fromHost(const void *hostSrc,
                    intptr_t size,
                    intptr_t dstOffset,
                    intptr_t srcOffset)
{
glBindBuffer(GL_SHADER_STORAGE_BUFFER,_id);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
glBufferSubData(GL_SHADER_STORAGE_BUFFER,dstOffset,
                size ? size : _size-dstOffset,
                srcOffset+(uint8_t *)hostSrc);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
}

void
GpuBuffer::toHost(void *hostDst,
                  intptr_t size,
                  intptr_t dstOffset,
                  intptr_t srcOffset)
{
glBindBuffer(GL_SHADER_STORAGE_BUFFER,_id);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
glGetBufferSubData(GL_SHADER_STORAGE_BUFFER,srcOffset,
                   size ? size : _size-srcOffset,
                   dstOffset+(uint8_t *)hostDst);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
}

void
GpuBuffer::toBuffer(GpuBuffer &gpuDst,
                    intptr_t size,
                    intptr_t dstOffset,
                    intptr_t srcOffset)
{
glBindBuffer(GL_COPY_WRITE_BUFFER,gpuDst._id);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
glBindBuffer(GL_COPY_READ_BUFFER,_id);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
glCopyBufferSubData(GL_COPY_READ_BUFFER,GL_COPY_WRITE_BUFFER,
                    srcOffset,dstOffset,
                    size ? size : std::min(gpuDst._size-dstOffset,
                                           _size-srcOffset));
ON_GL_ERROR({ THROW_GPU_FAILURE; });
}

//----------------------------------------------------------------------------

GLuint GpuProgram::_current{0};

GpuProgram::GpuProgram(int groupSize,
                       int groupCount,
                       const std::string &sourceCode)
: _groupSize(groupSize)
, _groupCount{groupCount}
, _sourceCode{_preamble(groupSize,groupCount)+sourceCode}
, _id{0}
{
char *log=(char *)0;
_id=CoreGl_buildComputeShader(_sourceCode.data(),false,&log);
if(log)
  {
  err("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n%"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",
      log);
  Memory_free(log);
  }
if(!_id) { THROW_GPU_FAILURE; }
}

GpuProgram::GpuProgram(const std::string &sourceCode)
: GpuProgram{0,0,sourceCode}
{
}

GpuProgram::GpuProgram(GpuProgram &&rhs)
: _id{rhs._id}
{
rhs._id=0;
}

GpuProgram & // itself
GpuProgram::operator=(GpuProgram &&rhs)
{
if(&rhs!=this)
  { _destroy(); _id=rhs._id; rhs._id=0; }
return *this;
}

GpuProgram::~GpuProgram()
{
_destroy();
}

GpuProgram & // itself
GpuProgram::buffer(int index,
                   GpuBuffer &buffer)
{
_setCurrent();
glBindBufferBase(GL_SHADER_STORAGE_BUFFER,index,buffer.id());
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_int(int index,
                      int32_t value)
{
_setCurrent();
glUniform1i(index,value);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_ivec2(int index,
                        int32_t value0,
                        int32_t value1)
{
_setCurrent();
glUniform2i(index,value0,value1);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_ivec3(int index,
                        int32_t value0,
                        int32_t value1,
                        int32_t value2)
{
_setCurrent();
glUniform3i(index,value0,value1,value2);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_ivec4(int index,
                        int32_t value0,
                        int32_t value1,
                        int32_t value2,
                        int32_t value3)
{
_setCurrent();
glUniform4i(index,value0,value1,value2,value3);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_uint(int index,
                       uint32_t value)
{
_setCurrent();
glUniform1ui(index,value);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_uvec2(int index,
                        uint32_t value0,
                        uint32_t value1)
{
_setCurrent();
glUniform2ui(index,value0,value1);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_uvec3(int index,
                        uint32_t value0,
                        uint32_t value1,
                        uint32_t value2)
{
_setCurrent();
glUniform3ui(index,value0,value1,value2);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_uvec4(int index,
                        uint32_t value0,
                        uint32_t value1,
                        uint32_t value2,
                        uint32_t value3)
{
_setCurrent();
glUniform4ui(index,value0,value1,value2,value3);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_float(int index,
                        real32_t value)
{
_setCurrent();
glUniform1f(index,value);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_vec2(int index,
                       real32_t value0,
                       real32_t value1)
{
_setCurrent();
glUniform2f(index,value0,value1);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_vec3(int index,
                       real32_t value0,
                       real32_t value1,
                       real32_t value2)
{
_setCurrent();
glUniform3f(index,value0,value1,value2);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

GpuProgram & // itself
GpuProgram::param_vec4(int index,
                       real32_t value0,
                       real32_t value1,
                       real32_t value2,
                       real32_t value3)
{
_setCurrent();
glUniform4f(index,value0,value1,value2,value3);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return *this;
}

void
GpuProgram::call(int groupCount,
                 bool barrier)
{
_setCurrent();
glDispatchCompute(groupCount>0 ? groupCount : _groupCount,1,1);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
if(barrier)
  {
  glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
  ON_GL_ERROR({ THROW_GPU_FAILURE; });
  }
}

void
GpuProgram::_destroy()
{
if(_id)
  {
  if(_current==_id) { _current=0; }
  glDeleteProgram(_id);
  ON_GL_ERROR({ THROW_GPU_FAILURE; });
  _id=0;
  }
}

void
GpuProgram::_setCurrent()
{
if(_current!=_id)
  {
  _current=_id;
  if(_id)
    {
    glUseProgram(_id);
    ON_GL_ERROR({ THROW_GPU_FAILURE; });
    }
  }
}

std::string // compute-shader code source preamble
GpuProgram::_preamble(int groupSize,
                      int groupCount)
{
const Gpu::Properties &properties=Gpu::properties();
std::string result;
if(groupSize<=0) { return result; }
result+=txt(" #version %% \n",
            CoreGl_shadingLanguageVersion(),
            CoreGl_embedded()&&(CoreGl_shadingLanguageVersion()>=300)
              ? " es" : "");
if(properties.hasBallot)
  {
  result+=" #extension GL_NV_shader_thread_group: enable \n";
  }
if(properties.hasShuffle)
  {
  result+=" #extension GL_NV_shader_thread_shuffle: enable \n";
  }
for(const auto &e: { "GL_ARB_gpu_shader_int64", "GL_NV_gpu_shader5" })
  {
  if(CoreGl_hasExtension(e)) // support for 64-bit integers
    { result+=txt(" #extension %: enable \n",e); break; }
  }
const int warpSize=properties.warpSize;
int warpShift=0;
while((1<<warpShift)<warpSize) ++warpShift;
result+=txt("                           \n"
            " // compile-time constants \n"
            " #define WARP_SIZE   %     \n"
            " #define WARP_MASK   %     \n"
            " #define WARP_SHIFT  %     \n"
            " #define GROUP_SIZE  %     \n",
            warpSize,
            warpSize-1,
            warpShift,
            groupSize);
if(!(groupSize&(groupSize-1))) // power-of-two
  {
  int groupShift=0;
  while((1<<groupShift)<groupSize) ++groupShift;
  result+=txt(" #define GROUP_MASK  % \n"
              " #define GROUP_SHIFT % \n",
              groupSize-1,
              groupShift);
  }
if(groupCount)
  {
  result+=txt(" #define GROUP_COUNT %                        \n"
              " #define GRID_SIZE   (GROUP_COUNT*GROUP_SIZE) \n",
              groupCount);
  }
result+="                                                  \n"
        " // run-time constants                            \n"
        " const int globalId=int(gl_GlobalInvocationID.x); \n"
        " const int groupId=int(gl_WorkGroupID.x);         \n"
        " const int localId=int(gl_LocalInvocationID.x);   \n"
        // gl_ThreadInWarpNV of GL_NV_shader_thread_group extension would
        // be usable but gl_WarpIDNV refers to the hardware warp (not
        // necessarily less than gl_WorkGroupSize.x/gl_WarpSizeNV)
        " const int warpId=localId>>WARP_SHIFT;            \n"
        " const int inWarpId=localId&WARP_MASK;            \n";
if(!groupCount)
  {
  result+=" const int groupCount=int(gl_NumWorkGroups.x); \n"
          " const int gridSize=groupCount*GROUP_SIZE;     \n";
  }
result+="                                                       \n"
        " #define READ_ONLY_BUFFER(b,content)                 \\\n"
        "         layout(std430,binding=b) restrict readonly  \\\n"
        "         buffer SSBO_##b { content };                  \n"
        "                                                       \n"
        " #define WRITE_ONLY_BUFFER(b,content)                \\\n"
        "         layout(std430,binding=b) restrict writeonly \\\n"
        "         buffer SSBO_##b { content };                  \n"
        "                                                       \n"
        " #define READ_WRITE_BUFFER(b,content)                \\\n"
        "         layout(std430,binding=b) restrict           \\\n"
        "         buffer SSBO_##b { content };                  \n"
        "                                                       \n"
        " #define VOLATILE_BUFFER(b,content)                  \\\n"
        "         layout(std430,binding=b) volatile coherent  \\\n"
        "         buffer SSBO_##b { content };                  \n"
        "                                                       \n"
        " #define PARAMETER(p,type)                           \\\n"
        "         layout(location=p) uniform type PARAM_##p;    \n"
        "                                                       \n"
        " layout(local_size_x=GROUP_SIZE) in;                   \n"
        "                                                       \n"
        " //---- end of preamble ----                           \n"
        "                                                       \n";
return result;
}

//----------------------------------------------------------------------------

GpuMarker::GpuMarker()
: _id{0}
{
glGenQueries(1,&_id);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
}

GpuMarker::GpuMarker(GpuMarker &&rhs)
: _id{rhs._id}
{
rhs._id=0;
}

GpuMarker & //itself
GpuMarker::operator=(GpuMarker &&rhs)
{
if(&rhs!=this)
  { _destroy(); _id=rhs._id; rhs._id=0; }
return *this;
}

GpuMarker::~GpuMarker()
{
_destroy();
}

void
GpuMarker::set()
{
glQueryCounter(_id,GL_TIMESTAMP);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
}

bool // marker is reached
GpuMarker::test()
{
GLint available=0;
glGetQueryObjectiv(_id,GL_QUERY_RESULT_AVAILABLE,&available);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
return available==GL_TRUE;
}

double // seconds between current and other markers
GpuMarker::interval(GpuMarker &other)
{
GLuint64 firstTime=0;
GLuint64 secondTime=0;
glGetQueryObjectui64v(_id,GL_QUERY_RESULT,&firstTime);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
glGetQueryObjectui64v(other._id,GL_QUERY_RESULT,&secondTime);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
GLuint64 interval=secondTime>firstTime ? secondTime-firstTime
                                       : firstTime-secondTime;
return double(interval)*1e-9;
}

void
GpuMarker::_destroy()
{
if(_id)
  {
  glDeleteQueries(1,&_id);
  ON_GL_ERROR({ THROW_GPU_FAILURE; });
  }
}

//----------------------------------------------------------------------------

Gpu::Properties Gpu::_properties{};

void
Gpu::_init()
{
if(_properties.glslVersion) return;
(void)&destroyDefaultGlContext; // avoid ``unused function'' warning
createDefaultGlContext();
if(!CoreGl_init()) { THROW_GPU_FAILURE; }
const GLubyte *str{nullptr};
str=glGetString(GL_VERSION);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
_properties.glVersionString=reinterpret_cast<const char *>(str);
str=glGetString(GL_SHADING_LANGUAGE_VERSION);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
_properties.glShadingLanguageVersionString=reinterpret_cast<const char *>(str);
str=glGetString(GL_VENDOR);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
_properties.glVendorString=reinterpret_cast<const char *>(str);
str=glGetString(GL_RENDERER);
ON_GL_ERROR({ THROW_GPU_FAILURE; });
_properties.glRendererString=reinterpret_cast<const char *>(str);
_properties.glVersionMajor=CoreGl_majorVersion();
_properties.glVersionMinor=CoreGl_minorVersion();
_properties.glslVersion=CoreGl_shadingLanguageVersion();
const CoreGlComputeProperties *prop=CoreGl_computeProperties();
if(!prop) { THROW_GPU_FAILURE; }
#define COPY_COMPUTE_PROPERTY(name) _properties.name=prop->name;
COPY_COMPUTE_PROPERTY(maxWorkGroupCount[0])
COPY_COMPUTE_PROPERTY(maxWorkGroupCount[1])
COPY_COMPUTE_PROPERTY(maxWorkGroupCount[2])
COPY_COMPUTE_PROPERTY(maxWorkGroupSize[0])
COPY_COMPUTE_PROPERTY(maxWorkGroupSize[1])
COPY_COMPUTE_PROPERTY(maxWorkGroupSize[2])
COPY_COMPUTE_PROPERTY(maxWorkGroupInvocations)
COPY_COMPUTE_PROPERTY(maxUniformBlocks)
COPY_COMPUTE_PROPERTY(maxTextureImageUnits)
COPY_COMPUTE_PROPERTY(maxAtomicCounterBuffers)
COPY_COMPUTE_PROPERTY(maxAtomicCounters)
COPY_COMPUTE_PROPERTY(maxSharedMemorySize)
COPY_COMPUTE_PROPERTY(maxUniformComponents)
COPY_COMPUTE_PROPERTY(maxImageUniforms)
COPY_COMPUTE_PROPERTY(maxCombinedUniformComponents)
COPY_COMPUTE_PROPERTY(maxShaderStorageBlocks)
COPY_COMPUTE_PROPERTY(warpSize)
COPY_COMPUTE_PROPERTY(warpsPerStreamingMultiprocessor)
COPY_COMPUTE_PROPERTY(streamingMultiprocessorCount)
COPY_COMPUTE_PROPERTY(hasBallot)
COPY_COMPUTE_PROPERTY(hasShuffle)
}

std::string // textual description of compute-shader properties
Gpu::showProperties()
{
_init();
std::string result;
result+=txt("glVersionString=\"%\"\n",
            _properties.glVersionString);
result+=txt("glShadingLanguageVersionString=\"%\"\n",
            _properties.glShadingLanguageVersionString);
result+=txt("glVendorString=\"%\"\n",
            _properties.glVendorString);
result+=txt("glRendererString=\"%\"\n",
            _properties.glRendererString);
result+=txt("glVersionMajor=%\n",
            _properties.glVersionMajor);
result+=txt("glVersionMinor=%\n",
            _properties.glVersionMinor);
result+=txt("glslVersion=%\n",
            _properties.glslVersion);
result+=txt("maxWorkGroupCount=% % %\n",
            _properties.maxWorkGroupCount[0],
            _properties.maxWorkGroupCount[1],
            _properties.maxWorkGroupCount[2]);
result+=txt("maxWorkGroupSize=% % %\n",
            _properties.maxWorkGroupSize[0],
            _properties.maxWorkGroupSize[1],
            _properties.maxWorkGroupSize[2]);
result+=txt("maxWorkGroupInvocations=%\n",
            _properties.maxWorkGroupInvocations);
result+=txt("maxUniformBlocks=%\n",
            _properties.maxUniformBlocks);
result+=txt("maxTextureImageUnits=%\n",
            _properties.maxTextureImageUnits);
result+=txt("maxAtomicCounterBuffers=%\n",
            _properties.maxAtomicCounterBuffers);
result+=txt("maxAtomicCounters=%\n",
            _properties.maxAtomicCounters);
result+=txt("maxSharedMemorySize=%\n",
            _properties.maxSharedMemorySize);
result+=txt("maxUniformComponents=%\n",
            _properties.maxUniformComponents);
result+=txt("maxImageUniforms=%\n",
            _properties.maxImageUniforms);
result+=txt("maxCombinedUniformComponents=%\n",
            _properties.maxCombinedUniformComponents);
result+=txt("maxShaderStorageBlocks=%\n",
            _properties.maxShaderStorageBlocks);
result+=txt("warpSize=%\n",
            _properties.warpSize);
result+=txt("warpsPerStreamingMultiprocessor=%\n",
            _properties.warpsPerStreamingMultiprocessor);
result+=txt("streamingMultiprocessorCount=%\n",
            _properties.streamingMultiprocessorCount);
result+=txt("hasBallot=%\n",
            _properties.hasBallot);
result+=txt("hasShuffle=%\n",
            _properties.hasShuffle);
return result;
}

int // maximal size supported by a 1D work-group
Gpu::maxWorkGroupSize()
{
_init();
const int sz1=_properties.maxWorkGroupSize[0];
const int sz2=_properties.maxWorkGroupInvocations;
return sz1<sz2 ? sz1 : sz2;
}

int // maximal power-of-two size supported by a 1D work-group
Gpu::maxPowerOfTwoWorkGroupSize()
{
_init();
const int maxSz=maxWorkGroupSize();
int sz=_properties.warpSize;
while((sz<<1)<=maxSz) sz<<=1;
return sz;
}

int // a generaly suitable work-group size
Gpu::chooseWorkGroupSize(bool powerOfTwo)
{
_init();
(void)powerOfTwo; // avoid ``unused parameter'' warning
// A power-of-two work-group size is not mandatory but seems to be faster
// FIXME: this hardcoded setting gives good average performances for some
//        experiments on the actual device used during development.
//        The performances may vary for other devices and/or algorithms that
//        would require specific settings.
const int sz=maxPowerOfTwoWorkGroupSize()/4;
const int warpSize=_properties.warpSize;
return sz<warpSize ? warpSize : sz;
}

int // a generaly suitable work-group count
Gpu::chooseWorkGroupCount()
{
_init();
// FIXME: this hardcoded setting gives good average performances for some
//        experiments on the actual device used during development.
//        The performances may vary for other devices and/or algorithms that
//        would require specific settings.
return 8*_properties.streamingMultiprocessorCount;
}

void
Gpu::flush(bool wait)
{
_init();
if(wait)
  {
  glMemoryBarrier(GL_ALL_BARRIER_BITS);
  ON_GL_ERROR({ THROW_GPU_FAILURE; });
  glFinish();
  ON_GL_ERROR({ THROW_GPU_FAILURE; });
  }
else
  {
  glFlush();
  ON_GL_ERROR({ THROW_GPU_FAILURE; });
  }
}

//----------------------------------------------------------------------------


#if defined _WIN32 //-- Windows-specific implementation ----------------------

static HINSTANCE hInstance;
static HWND window;
static HDC hdc;
static HGLRC wglContext;

#if !defined WGL_CONTEXT_MAJOR_VERSION_ARB
# define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#endif

#if !defined WGL_CONTEXT_MINOR_VERSION_ARB
# define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092
#endif

#if !defined WGL_CONTEXT_LAYER_PLANE_ARB
# define WGL_CONTEXT_LAYER_PLANE_ARB 0x2093
#endif

#if !defined WGL_CONTEXT_FLAGS_ARB
# define WGL_CONTEXT_FLAGS_ARB 0x2094
#endif

#if !defined WGL_CONTEXT_PROFILE_MASK_ARB
# define WGL_CONTEXT_PROFILE_MASK_ARB 0x9126
#endif

#if !defined WGL_CONTEXT_DEBUG_BIT_ARB
# define WGL_CONTEXT_DEBUG_BIT_ARB 0x0001
#endif

#if !defined WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB
# define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x0002
#endif

#if !defined WGL_CONTEXT_CORE_PROFILE_BIT_ARB
# define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#endif

#if !defined WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
# define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#endif

static
HGLRC
(APIENTRY *createContextAttribsFnct)(HDC hDC,
                                     HGLRC,
                                     const int *);
static
LRESULT CALLBACK
wndProc(HWND hWnd,
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam)
{
// printf("wndProc(hWnd=%d,uMsg=%d,wParam=%d,lParam=%d\n",
//        (int)(intptr_t)hWnd,(int)uMsg,(int)wParam,(int)lParam);
return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

#define WINDOW_CLASS_NAME "GpuElintGlContext"

static
void
createDefaultGlContext(void)
{
hInstance=(HINSTANCE)GetModuleHandle((LPCTSTR)0);
ON_ERROR(!hInstance,"GetModuleHandle() failure",{ exit(1); });
WNDCLASS wc;
wc.style=CS_OWNDC;
wc.lpfnWndProc=wndProc;
wc.cbClsExtra=0;
wc.cbWndExtra=0;
wc.hInstance=hInstance;
wc.hIcon=LoadIcon((HINSTANCE)0,IDI_APPLICATION);
wc.hCursor=(HCURSOR)0;
wc.hbrBackground=(HBRUSH)0;
wc.lpszMenuName=(LPCTSTR)0;
wc.lpszClassName=WINDOW_CLASS_NAME;
ATOM atm=RegisterClass(&wc);
ON_ERROR(!atm,"RegisterClass() failure",{ exit(1); });
DWORD dwStyle=WS_OVERLAPPEDWINDOW;
DWORD dwExStyle=0;
window=CreateWindowEx(dwExStyle,WINDOW_CLASS_NAME,"",dwStyle,
                      0,0,16,16,(HWND)0,(HMENU)0,hInstance,(LPVOID)0);
ON_ERROR(!window,"CreateWindowEx() failure",{ exit(1); });
PIXELFORMATDESCRIPTOR pfd;
pfd.nSize=sizeof(pfd);
pfd.nVersion=1;
pfd.dwFlags=PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER;
pfd.iPixelType=PFD_TYPE_RGBA;
pfd.cColorBits=32;
pfd.cRedBits=0;
pfd.cRedShift=0;
pfd.cGreenBits=0;
pfd.cGreenShift=0;
pfd.cBlueBits=0;
pfd.cBlueShift=0;
pfd.cAlphaBits=0;
pfd.cAlphaShift=0;
pfd.cAccumBits=0;
pfd.cAccumRedBits=0;
pfd.cAccumGreenBits=0;
pfd.cAccumBlueBits=0;
pfd.cAccumAlphaBits=0;
pfd.cDepthBits=24;
pfd.cStencilBits=0;
pfd.cAuxBuffers=0;
pfd.iLayerType=PFD_MAIN_PLANE;
pfd.bReserved=0;
pfd.dwLayerMask=0;
pfd.dwVisibleMask=0;
pfd.dwDamageMask=0;
hdc=GetDC(window);
int pixelFormat=ChoosePixelFormat(hdc,&pfd);
ON_ERROR(!pixelFormat,"ChoosePixelFormat() failure",{ exit(1); });
BOOL r=SetPixelFormat(hdc,pixelFormat,&pfd);
ON_ERROR(!r,"SetPixelFormat() failure",{ exit(1); });
HGLRC tmpContext=wglCreateContext(hdc);
ON_ERROR(!tmpContext,"wglCreateContext() failure",{ exit(1); });
r=wglMakeCurrent(hdc,tmpContext);
ON_ERROR(!r,"wglMakeCurrent() failure",{ exit(1); });
const char *extSuffixes[]={ "", "ARB", "EXT", (const char *)0 };
CoreGl_extensionFunctionWithSuffix(&createContextAttribsFnct,
                                   "wglCreateContextAttribs",
                                   extSuffixes);
if(createContextAttribsFnct)
  {
  int gl3Attribs[]={WGL_CONTEXT_MAJOR_VERSION_ARB,
                    3,
                    WGL_CONTEXT_MINOR_VERSION_ARB,
                    2,
                    WGL_CONTEXT_PROFILE_MASK_ARB,
                    WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
                    // WGL_CONTEXT_FLAGS_ARB,
                    // WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
                    0};
  int *useGl3Attribs=(int *)0;
  PFNGLGETSTRINGPROC getStringFnct=(PFNGLGETSTRINGPROC)0;
  CoreGl_extensionFunction(&getStringFnct,"glGetString");
  if(getStringFnct)
    {
    int major=0,minor=0;
    const char *version=(const char *)getStringFnct(GL_VERSION);
    if(version&&(sscanf(version,"%d.%d",&major,&minor)==2)&&
       ((major>3)||((major==3)&&(minor>=2))))
      {
      gl3Attribs[1]=major;
      gl3Attribs[3]=minor;
      useGl3Attribs=gl3Attribs;
      }
    }
  wglContext=createContextAttribsFnct(hdc,(HGLRC)0,useGl3Attribs);
  // ON_ERROR(!wglContext,"wglCreateContextAttribs() failure",{ exit(1); });
  }
if(!wglContext)
  {
  wglContext=tmpContext;
  }
else
  {
  wglMakeCurrent((HDC)0,(HGLRC)0);
  wglDeleteContext(tmpContext);
  r=wglMakeCurrent(hdc,wglContext);
  ON_ERROR(!r,"wglMakeCurrent() failure",{ exit(1); });
  }
}

static
void
destroyDefaultGlContext(void)
{
wglMakeCurrent((HDC)0,(HGLRC)0);
wglDeleteContext(wglContext);
ReleaseDC(window,hdc);
DestroyWindow(window);
UnregisterClass(WINDOW_CLASS_NAME,hInstance);
}

#else //-- X11-specific implementation ---------------------------------------

#define __gl_h_ // prevent glx.h from including gl.h
#include <GL/glx.h>
#include <X11/Xlib.h>

// FIXME: ugly hack!
// Even in C, the ``class'' member generates a warning!
// --> workaround accessing the ``class'' member right after ``depth''
#define XVisualInfo_class(info) \
        ((&((info)->depth))[1])

static Display *display;
static GLXFBConfig fbConfig;
static XVisualInfo *visual;
static Colormap colormap;
static Window window;
static GLXContext glxContext;

#if !defined GLX_CONTEXT_MAJOR_VERSION_ARB
# define GLX_CONTEXT_MAJOR_VERSION_ARB 0x2091
#endif

#if !defined GLX_CONTEXT_MINOR_VERSION_ARB
# define GLX_CONTEXT_MINOR_VERSION_ARB 0x2092
#endif

#if !defined GLX_CONTEXT_FLAGS_ARB
# define GLX_CONTEXT_FLAGS_ARB 0x2094
#endif

#if !defined GLX_CONTEXT_PROFILE_MASK_ARB
# define GLX_CONTEXT_PROFILE_MASK_ARB 0x9126
#endif

#if !defined GLX_CONTEXT_DEBUG_BIT_ARB
# define GLX_CONTEXT_DEBUG_BIT_ARB 0x0001
#endif

#if !defined GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB
# define GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x0002
#endif

#if !defined GLX_CONTEXT_CORE_PROFILE_BIT_ARB
# define GLX_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#endif

#if !defined GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
# define GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#endif

static
GLXContext
(APIENTRY *createContextAttribsFnct)(Display *,
                                     void *,
                                     GLXContext,
                                     Bool,
                                     const int *);

static
bool // success
checkVisual(Display *display,
            XVisualInfo *info,
            bool doubleBuffer,
            bool stereo,
            bool accum,
            bool stencil)
{
if((info->screen!=DefaultScreen(display))||
   ((XVisualInfo_class(info)!=TrueColor)&&
    (XVisualInfo_class(info)!=DirectColor))||
   (!info->red_mask)||(!info->green_mask)||(!info->blue_mask))
  {
  return false;
  }
int value;
if(glXGetConfig(display,info,GLX_USE_GL,&value)||!value)
  {
  return false;
  }
if(glXGetConfig(display,info,GLX_RGBA,&value)||!value)
  {
  return false;
  }
if(glXGetConfig(display,info,GLX_RED_SIZE,&value)||!value)
  {
  return false;
  }
if(glXGetConfig(display,info,GLX_GREEN_SIZE,&value)||!value)
  {
  return false;
  }
if(glXGetConfig(display,info,GLX_BLUE_SIZE,&value)||!value)
  {
  return false;
  }
#if 0 // sometimes value is 0 even if alpha is supported!
  if(glXGetConfig(display,info,GLX_ALPHA_SIZE,&value)||!value)
    {
    return false;
    }
#endif
if(glXGetConfig(display,info,GLX_DEPTH_SIZE,&value)||!value)
  {
  return false;
  }
if(doubleBuffer)
  {
  if(glXGetConfig(display,info,GLX_DOUBLEBUFFER,&value)||!value)
    {
    return false;
    }
  }
else
  {
  if(glXGetConfig(display,info,GLX_DOUBLEBUFFER,&value)||value)
    {
    return false;
    }
  }
if(stereo)
  {
  if(glXGetConfig(display,info,GLX_STEREO,&value)||!value)
    {
    return false;
    }
  }
else
  {
  if(glXGetConfig(display,info,GLX_STEREO,&value)||value)
    {
    return false;
    }
  }
if(accum)
  {
  if(glXGetConfig(display,info,GLX_ACCUM_RED_SIZE,&value)||!value)
    {
    return false;
    }
  if(glXGetConfig(display,info,GLX_ACCUM_GREEN_SIZE,&value)||!value)
    {
    return false;
    }
  if(glXGetConfig(display,info,GLX_ACCUM_BLUE_SIZE,&value)||!value)
    {
    return false;
    }
  if(glXGetConfig(display,info,GLX_ACCUM_ALPHA_SIZE,&value)||!value)
    {
    return false;
    }
  }
if(stencil)
  {
  if(glXGetConfig(display,info,GLX_STENCIL_SIZE,&value)||!value)
    {
    return false;
    }
  }
return true;
}

static
XVisualInfo *
chooseVisual(Display *display,
             bool doubleBuffer,
             bool stereo,
             bool accum,
             bool stencil)
{
int attribs[0x20];
int attribCount=0;
attribs[attribCount++]=GLX_RGBA;
attribs[attribCount++]=GLX_RED_SIZE;
attribs[attribCount++]=1;
attribs[attribCount++]=GLX_GREEN_SIZE;
attribs[attribCount++]=1;
attribs[attribCount++]=GLX_BLUE_SIZE;
attribs[attribCount++]=1;
attribs[attribCount++]=GLX_ALPHA_SIZE;
attribs[attribCount++]=1;
attribs[attribCount++]=GLX_DEPTH_SIZE;
attribs[attribCount++]=1;
if(doubleBuffer)
  {
  attribs[attribCount++]=GLX_DOUBLEBUFFER;
  }
if(stereo)
  {
  attribs[attribCount++]=GLX_STEREO;
  }
if(accum)
  {
  attribs[attribCount++]=GLX_ACCUM_RED_SIZE;
  attribs[attribCount++]=1;
  attribs[attribCount++]=GLX_ACCUM_GREEN_SIZE;
  attribs[attribCount++]=1;
  attribs[attribCount++]=GLX_ACCUM_BLUE_SIZE;
  attribs[attribCount++]=1;
  attribs[attribCount++]=GLX_ACCUM_ALPHA_SIZE;
  attribs[attribCount++]=1;
  }
if(stencil)
  {
  attribs[attribCount++]=GLX_STENCIL_SIZE;
  attribs[attribCount++]=1;
  }
attribs[attribCount++]=None;
XVisualInfo *best=glXChooseVisual(display,DefaultScreen(display),attribs);
if(best)
  {
  if(!checkVisual(display,best,doubleBuffer,stereo,accum,stencil))
    {
    XFree(best); // reject configurations we don't want to use
    best=(XVisualInfo *)0;
    }
  }
if(!best) // try our own visual selection algorithm
  {
  int infoCount;
  XVisualInfo *infos=XGetVisualInfo(display,VisualNoMask,
                                    (XVisualInfo *)0,&infoCount);
  if(infos)
    {
    for(int i=0;i<infoCount;++i)
      {
      if(checkVisual(display,infos+i,doubleBuffer,stereo,accum,stencil))
        {
        if(!best) // first match
          {
          best=infos+i;
          }
        else if(infos[i].depth>best->depth) // better depth
          {
          best=infos+i;
          }
        else if((infos[i].depth==best->depth)&&           // prefer TrueColor
                (XVisualInfo_class(infos+i)==TrueColor))  // to DirectColor
          {
          best=infos+i;
          }
        }
      }
    if(best)
      {
      XVisualInfo tmp;
      tmp.screen=best->screen;
      tmp.visualid=best->visualid; // get only this visual
      best=XGetVisualInfo(display,VisualScreenMask|VisualIDMask,
                          &tmp,&infoCount);
      }
    XFree(infos);
    }
  }
if(!best&&!doubleBuffer) // try double-buffer if single is not available
  {
  best=chooseVisual(display,true,stereo,accum,stencil);
  }
return best;
}

static
bool // success
checkFBConfig(Display *display,
              GLXFBConfig fbConfig,
              bool doubleBuffer,
              bool stereo,
              bool accum,
              bool stencil)
{
XVisualInfo *visual=glXGetVisualFromFBConfig(display,fbConfig);
if(!visual)
  {
  return false;
  }
if((visual->screen!=DefaultScreen(display))||
   ((XVisualInfo_class(visual)!=TrueColor)&&
    (XVisualInfo_class(visual)!=DirectColor))||
   (!visual->red_mask)||(!visual->green_mask)||(!visual->blue_mask))
  {
  XFree(visual);
  return false;
  }
XFree(visual);
int value;
if(glXGetFBConfigAttrib(display,fbConfig,GLX_RENDER_TYPE,&value)||
   !(value&GLX_RGBA_BIT))
  {
  return false;
  }
#if 0
if(glXGetFBConfigAttrib(display,fbConfig,GLX_SAMPLE_BUFFERS,&value)||
   !value)
  {
  return false;
  }
#endif
if(glXGetFBConfigAttrib(display,fbConfig,GLX_RED_SIZE,&value)||
   !value)
  {
  return false;
  }
if(glXGetFBConfigAttrib(display,fbConfig,GLX_GREEN_SIZE,&value)||
   !value)
  {
  return false;
  }
if(glXGetFBConfigAttrib(display,fbConfig,GLX_BLUE_SIZE,&value)||
   !value)
  {
  return false;
  }
#if 0 // sometimes value is 0 even if alpha is supported!
  if(glXGetFBConfigAttrib(display,fbConfig,GLX_ALPHA_SIZE,&value)||
     !value)
    {
    return false;
    }
#endif
if(glXGetFBConfigAttrib(display,fbConfig,GLX_DEPTH_SIZE,&value)||
   !value)
  {
  return false;
  }
if(doubleBuffer)
  {
  if(glXGetFBConfigAttrib(display,fbConfig,GLX_DOUBLEBUFFER,&value)||
     !value)
    {
    return false;
    }
  }
else
  {
  if(glXGetFBConfigAttrib(display,fbConfig,GLX_DOUBLEBUFFER,&value)||
     value)
    {
    return false;
    }
  }
if(stereo)
  {
  if(glXGetFBConfigAttrib(display,fbConfig,GLX_STEREO,&value)||
     !value)
    {
    return false;
    }
  }
else
  {
  if(glXGetFBConfigAttrib(display,fbConfig,GLX_STEREO,&value)||
     value)
    {
    return false;
    }
  }
if(accum)
  {
  if(glXGetFBConfigAttrib(display,fbConfig,GLX_ACCUM_RED_SIZE,&value)||
     !value)
    {
    return false;
    }
  if(glXGetFBConfigAttrib(display,fbConfig,GLX_ACCUM_GREEN_SIZE,&value)||
     !value)
    {
    return false;
    }
  if(glXGetFBConfigAttrib(display,fbConfig,GLX_ACCUM_BLUE_SIZE,&value)||
     !value)
    {
    return false;
    }
  if(glXGetFBConfigAttrib(display,fbConfig,GLX_ACCUM_ALPHA_SIZE,&value)||
     !value)
    {
    return false;
    }
  }
if(stencil)
  {
  if(glXGetFBConfigAttrib(display,fbConfig,GLX_STENCIL_SIZE,&value)||
     !value)
    {
    return false;
    }
  }
return true;
}

static
GLXFBConfig
chooseFBConfig(Display *display,
               bool doubleBuffer,
               bool stereo,
               bool accum,
               bool stencil)
{
int attribs[0x30];
int attribCount=0;
attribs[attribCount++]=GLX_X_RENDERABLE;
attribs[attribCount++]=True;
attribs[attribCount++]=GLX_DRAWABLE_TYPE;
attribs[attribCount++]=GLX_WINDOW_BIT;
attribs[attribCount++]=GLX_RENDER_TYPE;
attribs[attribCount++]=GLX_RGBA_BIT;
attribs[attribCount++]=GLX_X_VISUAL_TYPE;
attribs[attribCount++]=GLX_TRUE_COLOR;
attribs[attribCount++]=GLX_RED_SIZE;
attribs[attribCount++]=1;
attribs[attribCount++]=GLX_GREEN_SIZE;
attribs[attribCount++]=1;
attribs[attribCount++]=GLX_BLUE_SIZE;
attribs[attribCount++]=1;
attribs[attribCount++]=GLX_ALPHA_SIZE;
attribs[attribCount++]=1;
attribs[attribCount++]=GLX_DEPTH_SIZE;
attribs[attribCount++]=1;
if(doubleBuffer)
  {
  attribs[attribCount++]=GLX_DOUBLEBUFFER;
  attribs[attribCount++]=True;
  }
if(stereo)
  {
  attribs[attribCount++]=GLX_STEREO;
  attribs[attribCount++]=True;
  }
if(accum)
  {
  attribs[attribCount++]=GLX_ACCUM_RED_SIZE;
  attribs[attribCount++]=1;
  attribs[attribCount++]=GLX_ACCUM_GREEN_SIZE;
  attribs[attribCount++]=1;
  attribs[attribCount++]=GLX_ACCUM_BLUE_SIZE;
  attribs[attribCount++]=1;
  attribs[attribCount++]=GLX_ACCUM_ALPHA_SIZE;
  attribs[attribCount++]=1;
  }
if(stencil)
  {
  attribs[attribCount++]=GLX_STENCIL_SIZE;
  attribs[attribCount++]=1;
  }
// attribs[attribCount++]=GLX_SAMPLE_BUFFERS;
// attribs[attribCount++]=1;
// attribs[attribCount++]=GLX_SAMPLES;
// attribs[attribCount++]=1;
attribs[attribCount++]=None;
GLXFBConfig best=(GLXFBConfig)0;
int configCount;
GLXFBConfig *fbc=glXChooseFBConfig(display,DefaultScreen(display),
                                   attribs,&configCount);
if(fbc)
  {
  int bestSamples=-1;
  for(int i=0;i<configCount;++i)
    {
    if(checkFBConfig(display,fbc[i],doubleBuffer,stereo,accum,stencil))
      {
      int sampleBuffers;
      if(!glXGetFBConfigAttrib(display,fbc[i],GLX_SAMPLE_BUFFERS,
                               &sampleBuffers))
        {
        int samples=0;
        if(!glXGetFBConfigAttrib(display,fbc[i],GLX_SAMPLES,&samples))
          {
          if((!best)||(sampleBuffers&&(samples>bestSamples)))
            {
            best=fbc[i];
            bestSamples=samples;
            }
          }
        }
      }
    }
  XFree(fbc);
  }
if(!best&&!doubleBuffer) // try double-buffer if single is not available
  {
  best=chooseFBConfig(display,true,stereo,accum,stencil);
  }
return best;
}

static
void
createDefaultGlContext(void)
{
display=XOpenDisplay(::getenv("DISPLAY") ? "" : ":0");
ON_ERROR(!display,"XOpenDisplay() failure",{ exit(1); });
const char *extSuffixes[]={ "", "ARB", "EXT", (const char *)0 };
CoreGl_extensionFunctionWithSuffix(&createContextAttribsFnct,
                                   "glXCreateContextAttribs",
                                   extSuffixes);
bool doubleBuffer=true;
bool stereo=false;
bool accum=false;
bool stencil=false;
if(createContextAttribsFnct)
  {
  fbConfig=chooseFBConfig(display,doubleBuffer,stereo,accum,stencil);
  }
if(fbConfig)
  {
  visual=glXGetVisualFromFBConfig(display,fbConfig);
  ON_ERROR(!visual,"glXGetVisualFromFBConfig() failure",{ exit(1); });
  }
if(!visual)
  {
  visual=chooseVisual(display,doubleBuffer,stereo,accum,stencil);
  ON_ERROR(!visual,"chooseVisual() failure",{ exit(1); });
  }
colormap=XCreateColormap(display,DefaultRootWindow(display),
                         visual->visual,AllocNone);
ON_ERROR(!colormap,"XCreateColormap() failure",{ exit(1); });

XSetWindowAttributes wAttr;
wAttr.colormap=colormap;
wAttr.background_pixel=WhitePixel(display,DefaultScreen(display));
wAttr.border_pixel=BlackPixel(display,DefaultScreen(display));
window=XCreateWindow(display,DefaultRootWindow(display),
                     0,0,16,16,0,visual->depth,InputOutput,visual->visual,
                     CWColormap|CWBackPixel|CWBorderPixel,&wAttr);
ON_ERROR(!window,"XCreateWindow() failure",{ exit(1); });
GLXContext tmpContext=glXCreateContext(display,visual,(GLXContext)0,True);
ON_ERROR(!tmpContext,"glXCreateContext() failure",{ exit(1); });
Bool r=glXMakeCurrent(display,window,tmpContext);
ON_ERROR(!r,"glXMakeCurrent() failure",{ exit(1); });
if(fbConfig)
  {
  int gl3Attribs[]={GLX_CONTEXT_MAJOR_VERSION_ARB,
                    3,
                    GLX_CONTEXT_MINOR_VERSION_ARB,
                    2,
                    GLX_CONTEXT_PROFILE_MASK_ARB,
                    GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
                    // GLX_CONTEXT_FLAGS_ARB,
                    // GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
                    0};
  int *useGl3Attribs=(int *)0;
  int major=0,minor=0;
  PFNGLGETSTRINGPROC getStringFnct=(PFNGLGETSTRINGPROC)0;
  CoreGl_extensionFunction(&getStringFnct,"glGetString");
  if(getStringFnct)
    {
    const char *version=(const char *)getStringFnct(GL_VERSION);
    if(version&&(sscanf(version,"%d.%d",&major,&minor)==2)&&
       ((major>3)||((major==3)&&(minor>=2))))
      {
      gl3Attribs[1]=major;
      gl3Attribs[3]=minor;
      useGl3Attribs=gl3Attribs;
      }
    }
  glxContext=createContextAttribsFnct(display,fbConfig,(GLXContext)0,
                                      True,useGl3Attribs);
  // ON_ERROR(!glxContext,"glXCreateContextAttribs() failure",{ exit(1); });
  }
if(!glxContext)
  {
  glxContext=tmpContext;
  }
else
  {
  glXMakeCurrent(display,(Window)0,(GLXContext)0);
  glXDestroyContext(display,tmpContext);
  r=glXMakeCurrent(display,window,glxContext);
  ON_ERROR(!r,"glXMakeCurrent() failure",{ exit(1); });
  }
XSync(display,False);
}

static
void
destroyDefaultGlContext(void)
{
XSync(display,False);
glXMakeCurrent(display,(Window)0,(GLXContext)0);
glXDestroyContext(display,glxContext);
XDestroyWindow(display,window);
XFreeColormap(display,colormap);
XFree(visual);
XCloseDisplay(display);
}

#endif

} // namespace crs

//----------------------------------------------------------------------------
