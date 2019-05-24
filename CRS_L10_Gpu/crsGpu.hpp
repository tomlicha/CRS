//----------------------------------------------------------------------------

#ifndef CRS_GPU_HPP
#define CRS_GPU_HPP 1

#include "crsUtils.hpp"
#include "coreGl.h"

namespace crs {

class GpuBuffer
{
public:

  GpuBuffer(intptr_t size=0);

  GpuBuffer(GpuBuffer &&rhs);

  GpuBuffer & // itself
  operator=(GpuBuffer &&rhs);

  ~GpuBuffer();

  GpuBuffer(const GpuBuffer &) =delete;
  GpuBuffer & operator=(const GpuBuffer &) =delete;

  GLuint // OpenGL identifier
  id() const
  { return _id; }

  intptr_t // size in bytes
  size() const
  { return _size; }

  void
  resize(intptr_t size);

  const void * // mapped address
  mapR(intptr_t size=0,
       intptr_t offset=0)
  { return _map(true,false,size,offset); }

  void * // mapped address
  mapW(intptr_t size=0,
       intptr_t offset=0)
  { return _map(false,true,size,offset); }

  void * // mapped address
  mapRW(intptr_t size=0,
        intptr_t offset=0)
  { return _map(true,true,size,offset); }

  void
  unmap();

  void
  fromHost(const void *hostSrc,
           intptr_t size=0,
           intptr_t dstOffset=0,
           intptr_t srcOffset=0);

  void
  toHost(void *hostDst,
         intptr_t size=0,
         intptr_t dstOffset=0,
         intptr_t srcOffset=0);

  void
  toBuffer(GpuBuffer &gpuDst,
           intptr_t size=0,
           intptr_t dstOffset=0,
           intptr_t srcOffset=0);

private:

  void * // mapped address
  _map(bool readAccess,
       bool writeAccess,
       intptr_t size=0,
       intptr_t offset=0);

  GLuint _id;
  intptr_t _size;
  bool _mapped;
};

class GpuProgram
{
public:

  GpuProgram(int groupSize,
             int groupCount,
             const std::string &sourceCode);

  GpuProgram(const std::string &sourceCode);

  GpuProgram(GpuProgram &&rhs);

  GpuProgram & // itself
  operator=(GpuProgram &&rhs);

  ~GpuProgram();

  GpuProgram(const GpuProgram &) =delete;
  GpuProgram & operator=(const GpuProgram &) =delete;

  int // work-group size
  groupSize() const
  { return _groupSize; }

  int // number of work-groups
  groupCount() const
  { return _groupCount; }

  const std::string & // source code (with preamble)
  sourceCode() const
  { return _sourceCode; }

  GLuint // OpenGL identifier
  id() const
  { return _id; }

  GpuProgram & // itself
  buffer(int index,
         GpuBuffer &buffer);

  GpuProgram & // itself
  param_int(int index,
            int32_t value);

  GpuProgram & // itself
  param_ivec2(int index,
              int32_t value0,
              int32_t value1);

  GpuProgram & // itself
  param_ivec3(int index,
              int32_t value0,
              int32_t value1,
              int32_t value2);

  GpuProgram & // itself
  param_ivec4(int index,
              int32_t value0,
              int32_t value1,
              int32_t value2,
              int32_t value3);

  GpuProgram & // itself
  param_uint(int index,
             uint32_t value);

  GpuProgram & // itself
  param_uvec2(int index,
              uint32_t value0,
              uint32_t value1);

  GpuProgram & // itself
  param_uvec3(int index,
              uint32_t value0,
              uint32_t value1,
              uint32_t value2);

  GpuProgram & // itself
  param_uvec4(int index,
              uint32_t value0,
              uint32_t value1,
              uint32_t value2,
              uint32_t value3);

  GpuProgram & // itself
  param_float(int index,
              real32_t value);

  GpuProgram & // itself
  param_vec2(int index,
             real32_t value0,
             real32_t value1);

  GpuProgram & // itself
  param_vec3(int index,
             real32_t value0,
             real32_t value1,
             real32_t value2);

  GpuProgram & // itself
  param_vec4(int index,
             real32_t value0,
             real32_t value1,
             real32_t value2,
             real32_t value3);

  void
  call(int groupCount=0,
       bool barrier=true);

private:

  void
  _destroy();

  void
  _setCurrent();

  static
  std::string // compute-shader code source preamble
  _preamble(int groupSize,
            int groupCount);

  int _groupSize;
  int _groupCount;
  std::string _sourceCode;
  GLuint _id;
  static GLuint _current;
};

class GpuMarker
{
public:

  GpuMarker();

  GpuMarker(GpuMarker &&rhs);

  GpuMarker & // itself
  operator=(GpuMarker &&rhs);

  GpuMarker(const GpuMarker &) =delete;
  GpuMarker & operator=(const GpuMarker &) =delete;

  ~GpuMarker();

  GLuint // OpenGL identifier
  id() const
  { return _id; }

  void 
  set();

  bool // marker is reached  
  test();

  double // seconds between current and other markers
  interval(GpuMarker &other);

private:

  void
  _destroy();

  GLuint _id;
};

class Gpu
{
public:

  struct Properties
  {
  std::string glVersionString;
  std::string glShadingLanguageVersionString;
  std::string glVendorString;
  std::string glRendererString;
  int glVersionMajor;
  int glVersionMinor;
  int glslVersion;
  int maxWorkGroupCount[3];
  int maxWorkGroupSize[3];
  int maxWorkGroupInvocations;
  int maxUniformBlocks;
  int maxTextureImageUnits;
  int maxAtomicCounterBuffers;
  int maxAtomicCounters;
  int maxSharedMemorySize;
  int maxUniformComponents;
  int maxImageUniforms;
  int maxCombinedUniformComponents;
  int maxShaderStorageBlocks;
  int warpSize;
  int warpsPerStreamingMultiprocessor;
  int streamingMultiprocessorCount;
  bool hasBallot;
  bool hasShuffle;
  };

  Gpu() =delete;
  ~Gpu() =delete;
  Gpu(const Gpu &) =delete;
  Gpu & operator =(const Gpu &) =delete;
  Gpu(Gpu &&) =delete;
  Gpu & operator =(Gpu &&) =delete;

  static
  const Properties & // compute-shader properties
  properties()
  { _init(); return _properties; }

  static
  std::string // textual description of compute-shader properties
  showProperties();

  static
  int // maximal size supported by a 1D work-group
  maxWorkGroupSize();

  static
  int // maximal power-of-two size supported by a 1D work-group
  maxPowerOfTwoWorkGroupSize();

  static
  int // a generaly suitable work-group size
  chooseWorkGroupSize(bool powerOfTwo=false);

  static
  int // a generaly suitable work-group count
  chooseWorkGroupCount();

  static
  void 
  flush(bool wait=false);

private:

  static
  void
  _init();

  static Properties _properties;
};

} // namespace crs

#endif // CRS_GPU_HPP

//----------------------------------------------------------------------------
