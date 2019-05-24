//----------------------------------------------------------------------------
// Copyright (C) 2008-2016 Fabrice HARROUET (ENIB)
//
// This file is part of TransProg.
//   http://www.enib.fr/~harrouet/transprog.html
//
// TransProg is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// TransProg is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with TransProg.  If not, see <http://www.gnu.org/licenses/>.
//----------------------------------------------------------------------------

// This Core OpenGL wrapper is generated from:
//    http://www.opengl.org/registry/api/GL/glcorearb.h
// Do not edit or your changes will be lost!

#include "coreGl.h"
// #include "TransGl/coreGl.h"
//
// The preceding inclusion can be changed in order to find coreGl.h in its
// actual location (independant from the TransProg library).
//

#if defined TRANSGL_API_H
  #include "TransProg/memory.h"
  const char * _CoreGl_querySpecificExtensions(void); // defined elsewhere
#else // TransProg library is not used
  static
  const char * _CoreGl_querySpecificExtensions(void)
  { return (const char *)0; } // fake definition
#endif

#if defined _WIN32
# define GL_LIBRARY_NAME  "OPENGL32.DLL"
#elif defined __APPLE__
# define GL_LIBRARY_NAME  "/System/Library/Frameworks/OpenGL.framework" \
                          "/Libraries/libGL.dylib"
#elif defined __ANDROID__
# define GL_LIBRARY_NAME  "libGLESv2.so"
  #if !defined EGL_VERSION
    EXTERN_C_SYMBOL void (*eglGetProcAddress(const char *))(void);
  #endif
#else
# define GL_LIBRARY_NAME  "libGL.so"
  #if !defined GLX_VERSION
    EXTERN_C_SYMBOL void (*glXGetProcAddress(const GLubyte *))(void);
  #endif
#endif

TRANSGL_API_VAR struct _CoreGlManager _CoreGl_mgr;

static
void
CoreGl_addExtensionList(const char *extensionList)
{
if(extensionList)
  {
  for(int run=0;run<2;++run)
    {
    const char *beginList=extensionList;
    const char *endList=beginList+strlen(beginList);
    int extCount=_CoreGl_mgr.extensionCount;
    while(beginList<endList)
      {
      int extLen=(int)strcspn(beginList," ");
      if(extLen)
        {
        if(run!=0)
          {
          char *ext=Memory_alloc(extLen+1,char);
          memcpy(ext,beginList,extLen);
          ext[extLen]='\0';
          _CoreGl_mgr.extensions[extCount]=ext;
          }
        ++extCount;
        }
      beginList+=extLen+1;
      }
    if(run==0)
      {
      _CoreGl_mgr.extensions=Memory_reAlloc(_CoreGl_mgr.extensions,
                                            extCount+1,char *);
      }
    else
      {
      _CoreGl_mgr.extensions[extCount]=(char *)0;
      _CoreGl_mgr.extensionCount=extCount;
      }
    }
  }
}

static
bool // extension is available
CoreGl_load_VERSION_1_0(void)
{
bool hasExt=CoreGl_isAtLeastVersion(1,0);
CoreGl_extensionFunction(&CoreGl_CullFace,
                         "glCullFace");
if(!CoreGl_CullFace)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FrontFace,
                         "glFrontFace");
if(!CoreGl_FrontFace)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Hint,
                         "glHint");
if(!CoreGl_Hint)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_LineWidth,
                         "glLineWidth");
if(!CoreGl_LineWidth)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PointSize,
                         "glPointSize");
if(!CoreGl_PointSize)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PolygonMode,
                         "glPolygonMode");
if(!CoreGl_PolygonMode)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Scissor,
                         "glScissor");
if(!CoreGl_Scissor)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexParameterf,
                         "glTexParameterf");
if(!CoreGl_TexParameterf)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexParameterfv,
                         "glTexParameterfv");
if(!CoreGl_TexParameterfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexParameteri,
                         "glTexParameteri");
if(!CoreGl_TexParameteri)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexParameteriv,
                         "glTexParameteriv");
if(!CoreGl_TexParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexImage1D,
                         "glTexImage1D");
if(!CoreGl_TexImage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexImage2D,
                         "glTexImage2D");
if(!CoreGl_TexImage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawBuffer,
                         "glDrawBuffer");
if(!CoreGl_DrawBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Clear,
                         "glClear");
if(!CoreGl_Clear)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearColor,
                         "glClearColor");
if(!CoreGl_ClearColor)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearStencil,
                         "glClearStencil");
if(!CoreGl_ClearStencil)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearDepth,
                         "glClearDepth");
if(!CoreGl_ClearDepth)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_StencilMask,
                         "glStencilMask");
if(!CoreGl_StencilMask)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ColorMask,
                         "glColorMask");
if(!CoreGl_ColorMask)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DepthMask,
                         "glDepthMask");
if(!CoreGl_DepthMask)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Disable,
                         "glDisable");
if(!CoreGl_Disable)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Enable,
                         "glEnable");
if(!CoreGl_Enable)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Finish,
                         "glFinish");
if(!CoreGl_Finish)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Flush,
                         "glFlush");
if(!CoreGl_Flush)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BlendFunc,
                         "glBlendFunc");
if(!CoreGl_BlendFunc)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_LogicOp,
                         "glLogicOp");
if(!CoreGl_LogicOp)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_StencilFunc,
                         "glStencilFunc");
if(!CoreGl_StencilFunc)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_StencilOp,
                         "glStencilOp");
if(!CoreGl_StencilOp)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DepthFunc,
                         "glDepthFunc");
if(!CoreGl_DepthFunc)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PixelStoref,
                         "glPixelStoref");
if(!CoreGl_PixelStoref)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PixelStorei,
                         "glPixelStorei");
if(!CoreGl_PixelStorei)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ReadBuffer,
                         "glReadBuffer");
if(!CoreGl_ReadBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ReadPixels,
                         "glReadPixels");
if(!CoreGl_ReadPixels)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetBooleanv,
                         "glGetBooleanv");
if(!CoreGl_GetBooleanv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetDoublev,
                         "glGetDoublev");
if(!CoreGl_GetDoublev)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetError,
                         "glGetError");
if(!CoreGl_GetError)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetFloatv,
                         "glGetFloatv");
if(!CoreGl_GetFloatv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetIntegerv,
                         "glGetIntegerv");
if(!CoreGl_GetIntegerv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetString,
                         "glGetString");
if(!CoreGl_GetString)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTexImage,
                         "glGetTexImage");
if(!CoreGl_GetTexImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTexParameterfv,
                         "glGetTexParameterfv");
if(!CoreGl_GetTexParameterfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTexParameteriv,
                         "glGetTexParameteriv");
if(!CoreGl_GetTexParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTexLevelParameterfv,
                         "glGetTexLevelParameterfv");
if(!CoreGl_GetTexLevelParameterfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTexLevelParameteriv,
                         "glGetTexLevelParameteriv");
if(!CoreGl_GetTexLevelParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsEnabled,
                         "glIsEnabled");
if(!CoreGl_IsEnabled)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DepthRange,
                         "glDepthRange");
if(!CoreGl_DepthRange)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Viewport,
                         "glViewport");
if(!CoreGl_Viewport)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_1_1(void)
{
bool hasExt=CoreGl_isAtLeastVersion(1,1);
CoreGl_extensionFunction(&CoreGl_DrawArrays,
                         "glDrawArrays");
if(!CoreGl_DrawArrays)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawElements,
                         "glDrawElements");
if(!CoreGl_DrawElements)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetPointerv,
                         "glGetPointerv");
if(!CoreGl_GetPointerv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PolygonOffset,
                         "glPolygonOffset");
if(!CoreGl_PolygonOffset)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyTexImage1D,
                         "glCopyTexImage1D");
if(!CoreGl_CopyTexImage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyTexImage2D,
                         "glCopyTexImage2D");
if(!CoreGl_CopyTexImage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyTexSubImage1D,
                         "glCopyTexSubImage1D");
if(!CoreGl_CopyTexSubImage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyTexSubImage2D,
                         "glCopyTexSubImage2D");
if(!CoreGl_CopyTexSubImage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexSubImage1D,
                         "glTexSubImage1D");
if(!CoreGl_TexSubImage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexSubImage2D,
                         "glTexSubImage2D");
if(!CoreGl_TexSubImage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindTexture,
                         "glBindTexture");
if(!CoreGl_BindTexture)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteTextures,
                         "glDeleteTextures");
if(!CoreGl_DeleteTextures)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GenTextures,
                         "glGenTextures");
if(!CoreGl_GenTextures)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsTexture,
                         "glIsTexture");
if(!CoreGl_IsTexture)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_1_2(void)
{
bool hasExt=CoreGl_isAtLeastVersion(1,2);
CoreGl_extensionFunction(&CoreGl_DrawRangeElements,
                         "glDrawRangeElements");
if(!CoreGl_DrawRangeElements)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexImage3D,
                         "glTexImage3D");
if(!CoreGl_TexImage3D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexSubImage3D,
                         "glTexSubImage3D");
if(!CoreGl_TexSubImage3D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyTexSubImage3D,
                         "glCopyTexSubImage3D");
if(!CoreGl_CopyTexSubImage3D)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_1_3(void)
{
bool hasExt=CoreGl_isAtLeastVersion(1,3);
CoreGl_extensionFunction(&CoreGl_ActiveTexture,
                         "glActiveTexture");
if(!CoreGl_ActiveTexture)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_SampleCoverage,
                         "glSampleCoverage");
if(!CoreGl_SampleCoverage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CompressedTexImage3D,
                         "glCompressedTexImage3D");
if(!CoreGl_CompressedTexImage3D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CompressedTexImage2D,
                         "glCompressedTexImage2D");
if(!CoreGl_CompressedTexImage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CompressedTexImage1D,
                         "glCompressedTexImage1D");
if(!CoreGl_CompressedTexImage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CompressedTexSubImage3D,
                         "glCompressedTexSubImage3D");
if(!CoreGl_CompressedTexSubImage3D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CompressedTexSubImage2D,
                         "glCompressedTexSubImage2D");
if(!CoreGl_CompressedTexSubImage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CompressedTexSubImage1D,
                         "glCompressedTexSubImage1D");
if(!CoreGl_CompressedTexSubImage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetCompressedTexImage,
                         "glGetCompressedTexImage");
if(!CoreGl_GetCompressedTexImage)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_1_4(void)
{
bool hasExt=CoreGl_isAtLeastVersion(1,4);
CoreGl_extensionFunction(&CoreGl_BlendFuncSeparate,
                         "glBlendFuncSeparate");
if(!CoreGl_BlendFuncSeparate)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MultiDrawArrays,
                         "glMultiDrawArrays");
if(!CoreGl_MultiDrawArrays)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MultiDrawElements,
                         "glMultiDrawElements");
if(!CoreGl_MultiDrawElements)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PointParameterf,
                         "glPointParameterf");
if(!CoreGl_PointParameterf)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PointParameterfv,
                         "glPointParameterfv");
if(!CoreGl_PointParameterfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PointParameteri,
                         "glPointParameteri");
if(!CoreGl_PointParameteri)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PointParameteriv,
                         "glPointParameteriv");
if(!CoreGl_PointParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BlendColor,
                         "glBlendColor");
if(!CoreGl_BlendColor)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BlendEquation,
                         "glBlendEquation");
if(!CoreGl_BlendEquation)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_1_5(void)
{
bool hasExt=CoreGl_isAtLeastVersion(1,5);
CoreGl_extensionFunction(&CoreGl_GenQueries,
                         "glGenQueries");
if(!CoreGl_GenQueries)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteQueries,
                         "glDeleteQueries");
if(!CoreGl_DeleteQueries)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsQuery,
                         "glIsQuery");
if(!CoreGl_IsQuery)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BeginQuery,
                         "glBeginQuery");
if(!CoreGl_BeginQuery)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_EndQuery,
                         "glEndQuery");
if(!CoreGl_EndQuery)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetQueryiv,
                         "glGetQueryiv");
if(!CoreGl_GetQueryiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetQueryObjectiv,
                         "glGetQueryObjectiv");
if(!CoreGl_GetQueryObjectiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetQueryObjectuiv,
                         "glGetQueryObjectuiv");
if(!CoreGl_GetQueryObjectuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindBuffer,
                         "glBindBuffer");
if(!CoreGl_BindBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteBuffers,
                         "glDeleteBuffers");
if(!CoreGl_DeleteBuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GenBuffers,
                         "glGenBuffers");
if(!CoreGl_GenBuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsBuffer,
                         "glIsBuffer");
if(!CoreGl_IsBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BufferData,
                         "glBufferData");
if(!CoreGl_BufferData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BufferSubData,
                         "glBufferSubData");
if(!CoreGl_BufferSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetBufferSubData,
                         "glGetBufferSubData");
if(!CoreGl_GetBufferSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MapBuffer,
                         "glMapBuffer");
if(!CoreGl_MapBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UnmapBuffer,
                         "glUnmapBuffer");
if(!CoreGl_UnmapBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetBufferParameteriv,
                         "glGetBufferParameteriv");
if(!CoreGl_GetBufferParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetBufferPointerv,
                         "glGetBufferPointerv");
if(!CoreGl_GetBufferPointerv)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_2_0(void)
{
bool hasExt=CoreGl_isAtLeastVersion(2,0);
CoreGl_extensionFunction(&CoreGl_BlendEquationSeparate,
                         "glBlendEquationSeparate");
if(!CoreGl_BlendEquationSeparate)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawBuffers,
                         "glDrawBuffers");
if(!CoreGl_DrawBuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_StencilOpSeparate,
                         "glStencilOpSeparate");
if(!CoreGl_StencilOpSeparate)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_StencilFuncSeparate,
                         "glStencilFuncSeparate");
if(!CoreGl_StencilFuncSeparate)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_StencilMaskSeparate,
                         "glStencilMaskSeparate");
if(!CoreGl_StencilMaskSeparate)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_AttachShader,
                         "glAttachShader");
if(!CoreGl_AttachShader)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindAttribLocation,
                         "glBindAttribLocation");
if(!CoreGl_BindAttribLocation)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CompileShader,
                         "glCompileShader");
if(!CoreGl_CompileShader)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateProgram,
                         "glCreateProgram");
if(!CoreGl_CreateProgram)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateShader,
                         "glCreateShader");
if(!CoreGl_CreateShader)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteProgram,
                         "glDeleteProgram");
if(!CoreGl_DeleteProgram)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteShader,
                         "glDeleteShader");
if(!CoreGl_DeleteShader)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DetachShader,
                         "glDetachShader");
if(!CoreGl_DetachShader)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DisableVertexAttribArray,
                         "glDisableVertexAttribArray");
if(!CoreGl_DisableVertexAttribArray)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_EnableVertexAttribArray,
                         "glEnableVertexAttribArray");
if(!CoreGl_EnableVertexAttribArray)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetActiveAttrib,
                         "glGetActiveAttrib");
if(!CoreGl_GetActiveAttrib)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetActiveUniform,
                         "glGetActiveUniform");
if(!CoreGl_GetActiveUniform)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetAttachedShaders,
                         "glGetAttachedShaders");
if(!CoreGl_GetAttachedShaders)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetAttribLocation,
                         "glGetAttribLocation");
if(!CoreGl_GetAttribLocation)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramiv,
                         "glGetProgramiv");
if(!CoreGl_GetProgramiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramInfoLog,
                         "glGetProgramInfoLog");
if(!CoreGl_GetProgramInfoLog)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetShaderiv,
                         "glGetShaderiv");
if(!CoreGl_GetShaderiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetShaderInfoLog,
                         "glGetShaderInfoLog");
if(!CoreGl_GetShaderInfoLog)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetShaderSource,
                         "glGetShaderSource");
if(!CoreGl_GetShaderSource)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetUniformLocation,
                         "glGetUniformLocation");
if(!CoreGl_GetUniformLocation)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetUniformfv,
                         "glGetUniformfv");
if(!CoreGl_GetUniformfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetUniformiv,
                         "glGetUniformiv");
if(!CoreGl_GetUniformiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetVertexAttribdv,
                         "glGetVertexAttribdv");
if(!CoreGl_GetVertexAttribdv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetVertexAttribfv,
                         "glGetVertexAttribfv");
if(!CoreGl_GetVertexAttribfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetVertexAttribiv,
                         "glGetVertexAttribiv");
if(!CoreGl_GetVertexAttribiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetVertexAttribPointerv,
                         "glGetVertexAttribPointerv");
if(!CoreGl_GetVertexAttribPointerv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsProgram,
                         "glIsProgram");
if(!CoreGl_IsProgram)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsShader,
                         "glIsShader");
if(!CoreGl_IsShader)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_LinkProgram,
                         "glLinkProgram");
if(!CoreGl_LinkProgram)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ShaderSource,
                         "glShaderSource");
if(!CoreGl_ShaderSource)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UseProgram,
                         "glUseProgram");
if(!CoreGl_UseProgram)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform1f,
                         "glUniform1f");
if(!CoreGl_Uniform1f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform2f,
                         "glUniform2f");
if(!CoreGl_Uniform2f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform3f,
                         "glUniform3f");
if(!CoreGl_Uniform3f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform4f,
                         "glUniform4f");
if(!CoreGl_Uniform4f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform1i,
                         "glUniform1i");
if(!CoreGl_Uniform1i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform2i,
                         "glUniform2i");
if(!CoreGl_Uniform2i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform3i,
                         "glUniform3i");
if(!CoreGl_Uniform3i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform4i,
                         "glUniform4i");
if(!CoreGl_Uniform4i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform1fv,
                         "glUniform1fv");
if(!CoreGl_Uniform1fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform2fv,
                         "glUniform2fv");
if(!CoreGl_Uniform2fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform3fv,
                         "glUniform3fv");
if(!CoreGl_Uniform3fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform4fv,
                         "glUniform4fv");
if(!CoreGl_Uniform4fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform1iv,
                         "glUniform1iv");
if(!CoreGl_Uniform1iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform2iv,
                         "glUniform2iv");
if(!CoreGl_Uniform2iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform3iv,
                         "glUniform3iv");
if(!CoreGl_Uniform3iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform4iv,
                         "glUniform4iv");
if(!CoreGl_Uniform4iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix2fv,
                         "glUniformMatrix2fv");
if(!CoreGl_UniformMatrix2fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix3fv,
                         "glUniformMatrix3fv");
if(!CoreGl_UniformMatrix3fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix4fv,
                         "glUniformMatrix4fv");
if(!CoreGl_UniformMatrix4fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ValidateProgram,
                         "glValidateProgram");
if(!CoreGl_ValidateProgram)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib1d,
                         "glVertexAttrib1d");
if(!CoreGl_VertexAttrib1d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib1dv,
                         "glVertexAttrib1dv");
if(!CoreGl_VertexAttrib1dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib1f,
                         "glVertexAttrib1f");
if(!CoreGl_VertexAttrib1f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib1fv,
                         "glVertexAttrib1fv");
if(!CoreGl_VertexAttrib1fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib1s,
                         "glVertexAttrib1s");
if(!CoreGl_VertexAttrib1s)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib1sv,
                         "glVertexAttrib1sv");
if(!CoreGl_VertexAttrib1sv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib2d,
                         "glVertexAttrib2d");
if(!CoreGl_VertexAttrib2d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib2dv,
                         "glVertexAttrib2dv");
if(!CoreGl_VertexAttrib2dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib2f,
                         "glVertexAttrib2f");
if(!CoreGl_VertexAttrib2f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib2fv,
                         "glVertexAttrib2fv");
if(!CoreGl_VertexAttrib2fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib2s,
                         "glVertexAttrib2s");
if(!CoreGl_VertexAttrib2s)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib2sv,
                         "glVertexAttrib2sv");
if(!CoreGl_VertexAttrib2sv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib3d,
                         "glVertexAttrib3d");
if(!CoreGl_VertexAttrib3d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib3dv,
                         "glVertexAttrib3dv");
if(!CoreGl_VertexAttrib3dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib3f,
                         "glVertexAttrib3f");
if(!CoreGl_VertexAttrib3f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib3fv,
                         "glVertexAttrib3fv");
if(!CoreGl_VertexAttrib3fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib3s,
                         "glVertexAttrib3s");
if(!CoreGl_VertexAttrib3s)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib3sv,
                         "glVertexAttrib3sv");
if(!CoreGl_VertexAttrib3sv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4Nbv,
                         "glVertexAttrib4Nbv");
if(!CoreGl_VertexAttrib4Nbv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4Niv,
                         "glVertexAttrib4Niv");
if(!CoreGl_VertexAttrib4Niv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4Nsv,
                         "glVertexAttrib4Nsv");
if(!CoreGl_VertexAttrib4Nsv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4Nub,
                         "glVertexAttrib4Nub");
if(!CoreGl_VertexAttrib4Nub)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4Nubv,
                         "glVertexAttrib4Nubv");
if(!CoreGl_VertexAttrib4Nubv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4Nuiv,
                         "glVertexAttrib4Nuiv");
if(!CoreGl_VertexAttrib4Nuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4Nusv,
                         "glVertexAttrib4Nusv");
if(!CoreGl_VertexAttrib4Nusv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4bv,
                         "glVertexAttrib4bv");
if(!CoreGl_VertexAttrib4bv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4d,
                         "glVertexAttrib4d");
if(!CoreGl_VertexAttrib4d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4dv,
                         "glVertexAttrib4dv");
if(!CoreGl_VertexAttrib4dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4f,
                         "glVertexAttrib4f");
if(!CoreGl_VertexAttrib4f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4fv,
                         "glVertexAttrib4fv");
if(!CoreGl_VertexAttrib4fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4iv,
                         "glVertexAttrib4iv");
if(!CoreGl_VertexAttrib4iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4s,
                         "glVertexAttrib4s");
if(!CoreGl_VertexAttrib4s)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4sv,
                         "glVertexAttrib4sv");
if(!CoreGl_VertexAttrib4sv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4ubv,
                         "glVertexAttrib4ubv");
if(!CoreGl_VertexAttrib4ubv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4uiv,
                         "glVertexAttrib4uiv");
if(!CoreGl_VertexAttrib4uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttrib4usv,
                         "glVertexAttrib4usv");
if(!CoreGl_VertexAttrib4usv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribPointer,
                         "glVertexAttribPointer");
if(!CoreGl_VertexAttribPointer)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_2_1(void)
{
bool hasExt=CoreGl_isAtLeastVersion(2,1);
CoreGl_extensionFunction(&CoreGl_UniformMatrix2x3fv,
                         "glUniformMatrix2x3fv");
if(!CoreGl_UniformMatrix2x3fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix3x2fv,
                         "glUniformMatrix3x2fv");
if(!CoreGl_UniformMatrix3x2fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix2x4fv,
                         "glUniformMatrix2x4fv");
if(!CoreGl_UniformMatrix2x4fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix4x2fv,
                         "glUniformMatrix4x2fv");
if(!CoreGl_UniformMatrix4x2fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix3x4fv,
                         "glUniformMatrix3x4fv");
if(!CoreGl_UniformMatrix3x4fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix4x3fv,
                         "glUniformMatrix4x3fv");
if(!CoreGl_UniformMatrix4x3fv)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_3_0(void)
{
bool hasExt=CoreGl_isAtLeastVersion(3,0);
CoreGl_extensionFunction(&CoreGl_ColorMaski,
                         "glColorMaski");
if(!CoreGl_ColorMaski)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetBooleani_v,
                         "glGetBooleani_v");
if(!CoreGl_GetBooleani_v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetIntegeri_v,
                         "glGetIntegeri_v");
if(!CoreGl_GetIntegeri_v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Enablei,
                         "glEnablei");
if(!CoreGl_Enablei)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Disablei,
                         "glDisablei");
if(!CoreGl_Disablei)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsEnabledi,
                         "glIsEnabledi");
if(!CoreGl_IsEnabledi)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BeginTransformFeedback,
                         "glBeginTransformFeedback");
if(!CoreGl_BeginTransformFeedback)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_EndTransformFeedback,
                         "glEndTransformFeedback");
if(!CoreGl_EndTransformFeedback)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindBufferRange,
                         "glBindBufferRange");
if(!CoreGl_BindBufferRange)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindBufferBase,
                         "glBindBufferBase");
if(!CoreGl_BindBufferBase)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TransformFeedbackVaryings,
                         "glTransformFeedbackVaryings");
if(!CoreGl_TransformFeedbackVaryings)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTransformFeedbackVarying,
                         "glGetTransformFeedbackVarying");
if(!CoreGl_GetTransformFeedbackVarying)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClampColor,
                         "glClampColor");
if(!CoreGl_ClampColor)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BeginConditionalRender,
                         "glBeginConditionalRender");
if(!CoreGl_BeginConditionalRender)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_EndConditionalRender,
                         "glEndConditionalRender");
if(!CoreGl_EndConditionalRender)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribIPointer,
                         "glVertexAttribIPointer");
if(!CoreGl_VertexAttribIPointer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetVertexAttribIiv,
                         "glGetVertexAttribIiv");
if(!CoreGl_GetVertexAttribIiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetVertexAttribIuiv,
                         "glGetVertexAttribIuiv");
if(!CoreGl_GetVertexAttribIuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI1i,
                         "glVertexAttribI1i");
if(!CoreGl_VertexAttribI1i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI2i,
                         "glVertexAttribI2i");
if(!CoreGl_VertexAttribI2i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI3i,
                         "glVertexAttribI3i");
if(!CoreGl_VertexAttribI3i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI4i,
                         "glVertexAttribI4i");
if(!CoreGl_VertexAttribI4i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI1ui,
                         "glVertexAttribI1ui");
if(!CoreGl_VertexAttribI1ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI2ui,
                         "glVertexAttribI2ui");
if(!CoreGl_VertexAttribI2ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI3ui,
                         "glVertexAttribI3ui");
if(!CoreGl_VertexAttribI3ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI4ui,
                         "glVertexAttribI4ui");
if(!CoreGl_VertexAttribI4ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI1iv,
                         "glVertexAttribI1iv");
if(!CoreGl_VertexAttribI1iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI2iv,
                         "glVertexAttribI2iv");
if(!CoreGl_VertexAttribI2iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI3iv,
                         "glVertexAttribI3iv");
if(!CoreGl_VertexAttribI3iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI4iv,
                         "glVertexAttribI4iv");
if(!CoreGl_VertexAttribI4iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI1uiv,
                         "glVertexAttribI1uiv");
if(!CoreGl_VertexAttribI1uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI2uiv,
                         "glVertexAttribI2uiv");
if(!CoreGl_VertexAttribI2uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI3uiv,
                         "glVertexAttribI3uiv");
if(!CoreGl_VertexAttribI3uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI4uiv,
                         "glVertexAttribI4uiv");
if(!CoreGl_VertexAttribI4uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI4bv,
                         "glVertexAttribI4bv");
if(!CoreGl_VertexAttribI4bv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI4sv,
                         "glVertexAttribI4sv");
if(!CoreGl_VertexAttribI4sv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI4ubv,
                         "glVertexAttribI4ubv");
if(!CoreGl_VertexAttribI4ubv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribI4usv,
                         "glVertexAttribI4usv");
if(!CoreGl_VertexAttribI4usv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetUniformuiv,
                         "glGetUniformuiv");
if(!CoreGl_GetUniformuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindFragDataLocation,
                         "glBindFragDataLocation");
if(!CoreGl_BindFragDataLocation)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetFragDataLocation,
                         "glGetFragDataLocation");
if(!CoreGl_GetFragDataLocation)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform1ui,
                         "glUniform1ui");
if(!CoreGl_Uniform1ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform2ui,
                         "glUniform2ui");
if(!CoreGl_Uniform2ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform3ui,
                         "glUniform3ui");
if(!CoreGl_Uniform3ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform4ui,
                         "glUniform4ui");
if(!CoreGl_Uniform4ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform1uiv,
                         "glUniform1uiv");
if(!CoreGl_Uniform1uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform2uiv,
                         "glUniform2uiv");
if(!CoreGl_Uniform2uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform3uiv,
                         "glUniform3uiv");
if(!CoreGl_Uniform3uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform4uiv,
                         "glUniform4uiv");
if(!CoreGl_Uniform4uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexParameterIiv,
                         "glTexParameterIiv");
if(!CoreGl_TexParameterIiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexParameterIuiv,
                         "glTexParameterIuiv");
if(!CoreGl_TexParameterIuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTexParameterIiv,
                         "glGetTexParameterIiv");
if(!CoreGl_GetTexParameterIiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTexParameterIuiv,
                         "glGetTexParameterIuiv");
if(!CoreGl_GetTexParameterIuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearBufferiv,
                         "glClearBufferiv");
if(!CoreGl_ClearBufferiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearBufferuiv,
                         "glClearBufferuiv");
if(!CoreGl_ClearBufferuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearBufferfv,
                         "glClearBufferfv");
if(!CoreGl_ClearBufferfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearBufferfi,
                         "glClearBufferfi");
if(!CoreGl_ClearBufferfi)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetStringi,
                         "glGetStringi");
if(!CoreGl_GetStringi)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsRenderbuffer,
                         "glIsRenderbuffer");
if(!CoreGl_IsRenderbuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindRenderbuffer,
                         "glBindRenderbuffer");
if(!CoreGl_BindRenderbuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteRenderbuffers,
                         "glDeleteRenderbuffers");
if(!CoreGl_DeleteRenderbuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GenRenderbuffers,
                         "glGenRenderbuffers");
if(!CoreGl_GenRenderbuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_RenderbufferStorage,
                         "glRenderbufferStorage");
if(!CoreGl_RenderbufferStorage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetRenderbufferParameteriv,
                         "glGetRenderbufferParameteriv");
if(!CoreGl_GetRenderbufferParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsFramebuffer,
                         "glIsFramebuffer");
if(!CoreGl_IsFramebuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindFramebuffer,
                         "glBindFramebuffer");
if(!CoreGl_BindFramebuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteFramebuffers,
                         "glDeleteFramebuffers");
if(!CoreGl_DeleteFramebuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GenFramebuffers,
                         "glGenFramebuffers");
if(!CoreGl_GenFramebuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CheckFramebufferStatus,
                         "glCheckFramebufferStatus");
if(!CoreGl_CheckFramebufferStatus)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FramebufferTexture1D,
                         "glFramebufferTexture1D");
if(!CoreGl_FramebufferTexture1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FramebufferTexture2D,
                         "glFramebufferTexture2D");
if(!CoreGl_FramebufferTexture2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FramebufferTexture3D,
                         "glFramebufferTexture3D");
if(!CoreGl_FramebufferTexture3D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FramebufferRenderbuffer,
                         "glFramebufferRenderbuffer");
if(!CoreGl_FramebufferRenderbuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetFramebufferAttachmentParameteriv,
                         "glGetFramebufferAttachmentParameteriv");
if(!CoreGl_GetFramebufferAttachmentParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GenerateMipmap,
                         "glGenerateMipmap");
if(!CoreGl_GenerateMipmap)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BlitFramebuffer,
                         "glBlitFramebuffer");
if(!CoreGl_BlitFramebuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_RenderbufferStorageMultisample,
                         "glRenderbufferStorageMultisample");
if(!CoreGl_RenderbufferStorageMultisample)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FramebufferTextureLayer,
                         "glFramebufferTextureLayer");
if(!CoreGl_FramebufferTextureLayer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MapBufferRange,
                         "glMapBufferRange");
if(!CoreGl_MapBufferRange)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FlushMappedBufferRange,
                         "glFlushMappedBufferRange");
if(!CoreGl_FlushMappedBufferRange)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindVertexArray,
                         "glBindVertexArray");
if(!CoreGl_BindVertexArray)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteVertexArrays,
                         "glDeleteVertexArrays");
if(!CoreGl_DeleteVertexArrays)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GenVertexArrays,
                         "glGenVertexArrays");
if(!CoreGl_GenVertexArrays)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsVertexArray,
                         "glIsVertexArray");
if(!CoreGl_IsVertexArray)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_3_1(void)
{
bool hasExt=CoreGl_isAtLeastVersion(3,1);
CoreGl_extensionFunction(&CoreGl_DrawArraysInstanced,
                         "glDrawArraysInstanced");
if(!CoreGl_DrawArraysInstanced)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawElementsInstanced,
                         "glDrawElementsInstanced");
if(!CoreGl_DrawElementsInstanced)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexBuffer,
                         "glTexBuffer");
if(!CoreGl_TexBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PrimitiveRestartIndex,
                         "glPrimitiveRestartIndex");
if(!CoreGl_PrimitiveRestartIndex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyBufferSubData,
                         "glCopyBufferSubData");
if(!CoreGl_CopyBufferSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetUniformIndices,
                         "glGetUniformIndices");
if(!CoreGl_GetUniformIndices)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetActiveUniformsiv,
                         "glGetActiveUniformsiv");
if(!CoreGl_GetActiveUniformsiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetActiveUniformName,
                         "glGetActiveUniformName");
if(!CoreGl_GetActiveUniformName)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetUniformBlockIndex,
                         "glGetUniformBlockIndex");
if(!CoreGl_GetUniformBlockIndex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetActiveUniformBlockiv,
                         "glGetActiveUniformBlockiv");
if(!CoreGl_GetActiveUniformBlockiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetActiveUniformBlockName,
                         "glGetActiveUniformBlockName");
if(!CoreGl_GetActiveUniformBlockName)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformBlockBinding,
                         "glUniformBlockBinding");
if(!CoreGl_UniformBlockBinding)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_3_2(void)
{
bool hasExt=CoreGl_isAtLeastVersion(3,2);
CoreGl_extensionFunction(&CoreGl_DrawElementsBaseVertex,
                         "glDrawElementsBaseVertex");
if(!CoreGl_DrawElementsBaseVertex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawRangeElementsBaseVertex,
                         "glDrawRangeElementsBaseVertex");
if(!CoreGl_DrawRangeElementsBaseVertex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawElementsInstancedBaseVertex,
                         "glDrawElementsInstancedBaseVertex");
if(!CoreGl_DrawElementsInstancedBaseVertex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MultiDrawElementsBaseVertex,
                         "glMultiDrawElementsBaseVertex");
if(!CoreGl_MultiDrawElementsBaseVertex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProvokingVertex,
                         "glProvokingVertex");
if(!CoreGl_ProvokingVertex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FenceSync,
                         "glFenceSync");
if(!CoreGl_FenceSync)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsSync,
                         "glIsSync");
if(!CoreGl_IsSync)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteSync,
                         "glDeleteSync");
if(!CoreGl_DeleteSync)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClientWaitSync,
                         "glClientWaitSync");
if(!CoreGl_ClientWaitSync)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_WaitSync,
                         "glWaitSync");
if(!CoreGl_WaitSync)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetInteger64v,
                         "glGetInteger64v");
if(!CoreGl_GetInteger64v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetSynciv,
                         "glGetSynciv");
if(!CoreGl_GetSynciv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetInteger64i_v,
                         "glGetInteger64i_v");
if(!CoreGl_GetInteger64i_v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetBufferParameteri64v,
                         "glGetBufferParameteri64v");
if(!CoreGl_GetBufferParameteri64v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FramebufferTexture,
                         "glFramebufferTexture");
if(!CoreGl_FramebufferTexture)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexImage2DMultisample,
                         "glTexImage2DMultisample");
if(!CoreGl_TexImage2DMultisample)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexImage3DMultisample,
                         "glTexImage3DMultisample");
if(!CoreGl_TexImage3DMultisample)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetMultisamplefv,
                         "glGetMultisamplefv");
if(!CoreGl_GetMultisamplefv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_SampleMaski,
                         "glSampleMaski");
if(!CoreGl_SampleMaski)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_3_3(void)
{
bool hasExt=CoreGl_isAtLeastVersion(3,3);
CoreGl_extensionFunction(&CoreGl_BindFragDataLocationIndexed,
                         "glBindFragDataLocationIndexed");
if(!CoreGl_BindFragDataLocationIndexed)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetFragDataIndex,
                         "glGetFragDataIndex");
if(!CoreGl_GetFragDataIndex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GenSamplers,
                         "glGenSamplers");
if(!CoreGl_GenSamplers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteSamplers,
                         "glDeleteSamplers");
if(!CoreGl_DeleteSamplers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsSampler,
                         "glIsSampler");
if(!CoreGl_IsSampler)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindSampler,
                         "glBindSampler");
if(!CoreGl_BindSampler)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_SamplerParameteri,
                         "glSamplerParameteri");
if(!CoreGl_SamplerParameteri)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_SamplerParameteriv,
                         "glSamplerParameteriv");
if(!CoreGl_SamplerParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_SamplerParameterf,
                         "glSamplerParameterf");
if(!CoreGl_SamplerParameterf)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_SamplerParameterfv,
                         "glSamplerParameterfv");
if(!CoreGl_SamplerParameterfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_SamplerParameterIiv,
                         "glSamplerParameterIiv");
if(!CoreGl_SamplerParameterIiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_SamplerParameterIuiv,
                         "glSamplerParameterIuiv");
if(!CoreGl_SamplerParameterIuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetSamplerParameteriv,
                         "glGetSamplerParameteriv");
if(!CoreGl_GetSamplerParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetSamplerParameterIiv,
                         "glGetSamplerParameterIiv");
if(!CoreGl_GetSamplerParameterIiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetSamplerParameterfv,
                         "glGetSamplerParameterfv");
if(!CoreGl_GetSamplerParameterfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetSamplerParameterIuiv,
                         "glGetSamplerParameterIuiv");
if(!CoreGl_GetSamplerParameterIuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_QueryCounter,
                         "glQueryCounter");
if(!CoreGl_QueryCounter)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetQueryObjecti64v,
                         "glGetQueryObjecti64v");
if(!CoreGl_GetQueryObjecti64v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetQueryObjectui64v,
                         "glGetQueryObjectui64v");
if(!CoreGl_GetQueryObjectui64v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribDivisor,
                         "glVertexAttribDivisor");
if(!CoreGl_VertexAttribDivisor)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribP1ui,
                         "glVertexAttribP1ui");
if(!CoreGl_VertexAttribP1ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribP1uiv,
                         "glVertexAttribP1uiv");
if(!CoreGl_VertexAttribP1uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribP2ui,
                         "glVertexAttribP2ui");
if(!CoreGl_VertexAttribP2ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribP2uiv,
                         "glVertexAttribP2uiv");
if(!CoreGl_VertexAttribP2uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribP3ui,
                         "glVertexAttribP3ui");
if(!CoreGl_VertexAttribP3ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribP3uiv,
                         "glVertexAttribP3uiv");
if(!CoreGl_VertexAttribP3uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribP4ui,
                         "glVertexAttribP4ui");
if(!CoreGl_VertexAttribP4ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribP4uiv,
                         "glVertexAttribP4uiv");
if(!CoreGl_VertexAttribP4uiv)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_4_0(void)
{
bool hasExt=CoreGl_isAtLeastVersion(4,0);
CoreGl_extensionFunction(&CoreGl_MinSampleShading,
                         "glMinSampleShading");
if(!CoreGl_MinSampleShading)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BlendEquationi,
                         "glBlendEquationi");
if(!CoreGl_BlendEquationi)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BlendEquationSeparatei,
                         "glBlendEquationSeparatei");
if(!CoreGl_BlendEquationSeparatei)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BlendFunci,
                         "glBlendFunci");
if(!CoreGl_BlendFunci)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BlendFuncSeparatei,
                         "glBlendFuncSeparatei");
if(!CoreGl_BlendFuncSeparatei)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawArraysIndirect,
                         "glDrawArraysIndirect");
if(!CoreGl_DrawArraysIndirect)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawElementsIndirect,
                         "glDrawElementsIndirect");
if(!CoreGl_DrawElementsIndirect)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform1d,
                         "glUniform1d");
if(!CoreGl_Uniform1d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform2d,
                         "glUniform2d");
if(!CoreGl_Uniform2d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform3d,
                         "glUniform3d");
if(!CoreGl_Uniform3d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform4d,
                         "glUniform4d");
if(!CoreGl_Uniform4d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform1dv,
                         "glUniform1dv");
if(!CoreGl_Uniform1dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform2dv,
                         "glUniform2dv");
if(!CoreGl_Uniform2dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform3dv,
                         "glUniform3dv");
if(!CoreGl_Uniform3dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_Uniform4dv,
                         "glUniform4dv");
if(!CoreGl_Uniform4dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix2dv,
                         "glUniformMatrix2dv");
if(!CoreGl_UniformMatrix2dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix3dv,
                         "glUniformMatrix3dv");
if(!CoreGl_UniformMatrix3dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix4dv,
                         "glUniformMatrix4dv");
if(!CoreGl_UniformMatrix4dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix2x3dv,
                         "glUniformMatrix2x3dv");
if(!CoreGl_UniformMatrix2x3dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix2x4dv,
                         "glUniformMatrix2x4dv");
if(!CoreGl_UniformMatrix2x4dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix3x2dv,
                         "glUniformMatrix3x2dv");
if(!CoreGl_UniformMatrix3x2dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix3x4dv,
                         "glUniformMatrix3x4dv");
if(!CoreGl_UniformMatrix3x4dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix4x2dv,
                         "glUniformMatrix4x2dv");
if(!CoreGl_UniformMatrix4x2dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformMatrix4x3dv,
                         "glUniformMatrix4x3dv");
if(!CoreGl_UniformMatrix4x3dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetUniformdv,
                         "glGetUniformdv");
if(!CoreGl_GetUniformdv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetSubroutineUniformLocation,
                         "glGetSubroutineUniformLocation");
if(!CoreGl_GetSubroutineUniformLocation)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetSubroutineIndex,
                         "glGetSubroutineIndex");
if(!CoreGl_GetSubroutineIndex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetActiveSubroutineUniformiv,
                         "glGetActiveSubroutineUniformiv");
if(!CoreGl_GetActiveSubroutineUniformiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetActiveSubroutineUniformName,
                         "glGetActiveSubroutineUniformName");
if(!CoreGl_GetActiveSubroutineUniformName)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetActiveSubroutineName,
                         "glGetActiveSubroutineName");
if(!CoreGl_GetActiveSubroutineName)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UniformSubroutinesuiv,
                         "glUniformSubroutinesuiv");
if(!CoreGl_UniformSubroutinesuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetUniformSubroutineuiv,
                         "glGetUniformSubroutineuiv");
if(!CoreGl_GetUniformSubroutineuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramStageiv,
                         "glGetProgramStageiv");
if(!CoreGl_GetProgramStageiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PatchParameteri,
                         "glPatchParameteri");
if(!CoreGl_PatchParameteri)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PatchParameterfv,
                         "glPatchParameterfv");
if(!CoreGl_PatchParameterfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindTransformFeedback,
                         "glBindTransformFeedback");
if(!CoreGl_BindTransformFeedback)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteTransformFeedbacks,
                         "glDeleteTransformFeedbacks");
if(!CoreGl_DeleteTransformFeedbacks)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GenTransformFeedbacks,
                         "glGenTransformFeedbacks");
if(!CoreGl_GenTransformFeedbacks)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsTransformFeedback,
                         "glIsTransformFeedback");
if(!CoreGl_IsTransformFeedback)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PauseTransformFeedback,
                         "glPauseTransformFeedback");
if(!CoreGl_PauseTransformFeedback)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ResumeTransformFeedback,
                         "glResumeTransformFeedback");
if(!CoreGl_ResumeTransformFeedback)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawTransformFeedback,
                         "glDrawTransformFeedback");
if(!CoreGl_DrawTransformFeedback)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawTransformFeedbackStream,
                         "glDrawTransformFeedbackStream");
if(!CoreGl_DrawTransformFeedbackStream)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BeginQueryIndexed,
                         "glBeginQueryIndexed");
if(!CoreGl_BeginQueryIndexed)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_EndQueryIndexed,
                         "glEndQueryIndexed");
if(!CoreGl_EndQueryIndexed)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetQueryIndexediv,
                         "glGetQueryIndexediv");
if(!CoreGl_GetQueryIndexediv)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_4_1(void)
{
bool hasExt=CoreGl_isAtLeastVersion(4,1);
CoreGl_extensionFunction(&CoreGl_ReleaseShaderCompiler,
                         "glReleaseShaderCompiler");
if(!CoreGl_ReleaseShaderCompiler)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ShaderBinary,
                         "glShaderBinary");
if(!CoreGl_ShaderBinary)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetShaderPrecisionFormat,
                         "glGetShaderPrecisionFormat");
if(!CoreGl_GetShaderPrecisionFormat)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DepthRangef,
                         "glDepthRangef");
if(!CoreGl_DepthRangef)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearDepthf,
                         "glClearDepthf");
if(!CoreGl_ClearDepthf)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramBinary,
                         "glGetProgramBinary");
if(!CoreGl_GetProgramBinary)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramBinary,
                         "glProgramBinary");
if(!CoreGl_ProgramBinary)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramParameteri,
                         "glProgramParameteri");
if(!CoreGl_ProgramParameteri)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UseProgramStages,
                         "glUseProgramStages");
if(!CoreGl_UseProgramStages)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ActiveShaderProgram,
                         "glActiveShaderProgram");
if(!CoreGl_ActiveShaderProgram)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateShaderProgramv,
                         "glCreateShaderProgramv");
if(!CoreGl_CreateShaderProgramv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindProgramPipeline,
                         "glBindProgramPipeline");
if(!CoreGl_BindProgramPipeline)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DeleteProgramPipelines,
                         "glDeleteProgramPipelines");
if(!CoreGl_DeleteProgramPipelines)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GenProgramPipelines,
                         "glGenProgramPipelines");
if(!CoreGl_GenProgramPipelines)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_IsProgramPipeline,
                         "glIsProgramPipeline");
if(!CoreGl_IsProgramPipeline)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramPipelineiv,
                         "glGetProgramPipelineiv");
if(!CoreGl_GetProgramPipelineiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform1i,
                         "glProgramUniform1i");
if(!CoreGl_ProgramUniform1i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform1iv,
                         "glProgramUniform1iv");
if(!CoreGl_ProgramUniform1iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform1f,
                         "glProgramUniform1f");
if(!CoreGl_ProgramUniform1f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform1fv,
                         "glProgramUniform1fv");
if(!CoreGl_ProgramUniform1fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform1d,
                         "glProgramUniform1d");
if(!CoreGl_ProgramUniform1d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform1dv,
                         "glProgramUniform1dv");
if(!CoreGl_ProgramUniform1dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform1ui,
                         "glProgramUniform1ui");
if(!CoreGl_ProgramUniform1ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform1uiv,
                         "glProgramUniform1uiv");
if(!CoreGl_ProgramUniform1uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform2i,
                         "glProgramUniform2i");
if(!CoreGl_ProgramUniform2i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform2iv,
                         "glProgramUniform2iv");
if(!CoreGl_ProgramUniform2iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform2f,
                         "glProgramUniform2f");
if(!CoreGl_ProgramUniform2f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform2fv,
                         "glProgramUniform2fv");
if(!CoreGl_ProgramUniform2fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform2d,
                         "glProgramUniform2d");
if(!CoreGl_ProgramUniform2d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform2dv,
                         "glProgramUniform2dv");
if(!CoreGl_ProgramUniform2dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform2ui,
                         "glProgramUniform2ui");
if(!CoreGl_ProgramUniform2ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform2uiv,
                         "glProgramUniform2uiv");
if(!CoreGl_ProgramUniform2uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform3i,
                         "glProgramUniform3i");
if(!CoreGl_ProgramUniform3i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform3iv,
                         "glProgramUniform3iv");
if(!CoreGl_ProgramUniform3iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform3f,
                         "glProgramUniform3f");
if(!CoreGl_ProgramUniform3f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform3fv,
                         "glProgramUniform3fv");
if(!CoreGl_ProgramUniform3fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform3d,
                         "glProgramUniform3d");
if(!CoreGl_ProgramUniform3d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform3dv,
                         "glProgramUniform3dv");
if(!CoreGl_ProgramUniform3dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform3ui,
                         "glProgramUniform3ui");
if(!CoreGl_ProgramUniform3ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform3uiv,
                         "glProgramUniform3uiv");
if(!CoreGl_ProgramUniform3uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform4i,
                         "glProgramUniform4i");
if(!CoreGl_ProgramUniform4i)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform4iv,
                         "glProgramUniform4iv");
if(!CoreGl_ProgramUniform4iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform4f,
                         "glProgramUniform4f");
if(!CoreGl_ProgramUniform4f)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform4fv,
                         "glProgramUniform4fv");
if(!CoreGl_ProgramUniform4fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform4d,
                         "glProgramUniform4d");
if(!CoreGl_ProgramUniform4d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform4dv,
                         "glProgramUniform4dv");
if(!CoreGl_ProgramUniform4dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform4ui,
                         "glProgramUniform4ui");
if(!CoreGl_ProgramUniform4ui)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniform4uiv,
                         "glProgramUniform4uiv");
if(!CoreGl_ProgramUniform4uiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix2fv,
                         "glProgramUniformMatrix2fv");
if(!CoreGl_ProgramUniformMatrix2fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix3fv,
                         "glProgramUniformMatrix3fv");
if(!CoreGl_ProgramUniformMatrix3fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix4fv,
                         "glProgramUniformMatrix4fv");
if(!CoreGl_ProgramUniformMatrix4fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix2dv,
                         "glProgramUniformMatrix2dv");
if(!CoreGl_ProgramUniformMatrix2dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix3dv,
                         "glProgramUniformMatrix3dv");
if(!CoreGl_ProgramUniformMatrix3dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix4dv,
                         "glProgramUniformMatrix4dv");
if(!CoreGl_ProgramUniformMatrix4dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix2x3fv,
                         "glProgramUniformMatrix2x3fv");
if(!CoreGl_ProgramUniformMatrix2x3fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix3x2fv,
                         "glProgramUniformMatrix3x2fv");
if(!CoreGl_ProgramUniformMatrix3x2fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix2x4fv,
                         "glProgramUniformMatrix2x4fv");
if(!CoreGl_ProgramUniformMatrix2x4fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix4x2fv,
                         "glProgramUniformMatrix4x2fv");
if(!CoreGl_ProgramUniformMatrix4x2fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix3x4fv,
                         "glProgramUniformMatrix3x4fv");
if(!CoreGl_ProgramUniformMatrix3x4fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix4x3fv,
                         "glProgramUniformMatrix4x3fv");
if(!CoreGl_ProgramUniformMatrix4x3fv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix2x3dv,
                         "glProgramUniformMatrix2x3dv");
if(!CoreGl_ProgramUniformMatrix2x3dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix3x2dv,
                         "glProgramUniformMatrix3x2dv");
if(!CoreGl_ProgramUniformMatrix3x2dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix2x4dv,
                         "glProgramUniformMatrix2x4dv");
if(!CoreGl_ProgramUniformMatrix2x4dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix4x2dv,
                         "glProgramUniformMatrix4x2dv");
if(!CoreGl_ProgramUniformMatrix4x2dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix3x4dv,
                         "glProgramUniformMatrix3x4dv");
if(!CoreGl_ProgramUniformMatrix3x4dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ProgramUniformMatrix4x3dv,
                         "glProgramUniformMatrix4x3dv");
if(!CoreGl_ProgramUniformMatrix4x3dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ValidateProgramPipeline,
                         "glValidateProgramPipeline");
if(!CoreGl_ValidateProgramPipeline)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramPipelineInfoLog,
                         "glGetProgramPipelineInfoLog");
if(!CoreGl_GetProgramPipelineInfoLog)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribL1d,
                         "glVertexAttribL1d");
if(!CoreGl_VertexAttribL1d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribL2d,
                         "glVertexAttribL2d");
if(!CoreGl_VertexAttribL2d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribL3d,
                         "glVertexAttribL3d");
if(!CoreGl_VertexAttribL3d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribL4d,
                         "glVertexAttribL4d");
if(!CoreGl_VertexAttribL4d)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribL1dv,
                         "glVertexAttribL1dv");
if(!CoreGl_VertexAttribL1dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribL2dv,
                         "glVertexAttribL2dv");
if(!CoreGl_VertexAttribL2dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribL3dv,
                         "glVertexAttribL3dv");
if(!CoreGl_VertexAttribL3dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribL4dv,
                         "glVertexAttribL4dv");
if(!CoreGl_VertexAttribL4dv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribLPointer,
                         "glVertexAttribLPointer");
if(!CoreGl_VertexAttribLPointer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetVertexAttribLdv,
                         "glGetVertexAttribLdv");
if(!CoreGl_GetVertexAttribLdv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ViewportArrayv,
                         "glViewportArrayv");
if(!CoreGl_ViewportArrayv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ViewportIndexedf,
                         "glViewportIndexedf");
if(!CoreGl_ViewportIndexedf)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ViewportIndexedfv,
                         "glViewportIndexedfv");
if(!CoreGl_ViewportIndexedfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ScissorArrayv,
                         "glScissorArrayv");
if(!CoreGl_ScissorArrayv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ScissorIndexed,
                         "glScissorIndexed");
if(!CoreGl_ScissorIndexed)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ScissorIndexedv,
                         "glScissorIndexedv");
if(!CoreGl_ScissorIndexedv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DepthRangeArrayv,
                         "glDepthRangeArrayv");
if(!CoreGl_DepthRangeArrayv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DepthRangeIndexed,
                         "glDepthRangeIndexed");
if(!CoreGl_DepthRangeIndexed)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetFloati_v,
                         "glGetFloati_v");
if(!CoreGl_GetFloati_v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetDoublei_v,
                         "glGetDoublei_v");
if(!CoreGl_GetDoublei_v)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_4_2(void)
{
bool hasExt=CoreGl_isAtLeastVersion(4,2);
CoreGl_extensionFunction(&CoreGl_DrawArraysInstancedBaseInstance,
                         "glDrawArraysInstancedBaseInstance");
if(!CoreGl_DrawArraysInstancedBaseInstance)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawElementsInstancedBaseInstance,
                         "glDrawElementsInstancedBaseInstance");
if(!CoreGl_DrawElementsInstancedBaseInstance)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawElementsInstancedBaseVertexBaseInstance,
                         "glDrawElementsInstancedBaseVertexBaseInstance");
if(!CoreGl_DrawElementsInstancedBaseVertexBaseInstance)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetInternalformativ,
                         "glGetInternalformativ");
if(!CoreGl_GetInternalformativ)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetActiveAtomicCounterBufferiv,
                         "glGetActiveAtomicCounterBufferiv");
if(!CoreGl_GetActiveAtomicCounterBufferiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindImageTexture,
                         "glBindImageTexture");
if(!CoreGl_BindImageTexture)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MemoryBarrier,
                         "glMemoryBarrier");
if(!CoreGl_MemoryBarrier)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexStorage1D,
                         "glTexStorage1D");
if(!CoreGl_TexStorage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexStorage2D,
                         "glTexStorage2D");
if(!CoreGl_TexStorage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexStorage3D,
                         "glTexStorage3D");
if(!CoreGl_TexStorage3D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawTransformFeedbackInstanced,
                         "glDrawTransformFeedbackInstanced");
if(!CoreGl_DrawTransformFeedbackInstanced)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DrawTransformFeedbackStreamInstanced,
                         "glDrawTransformFeedbackStreamInstanced");
if(!CoreGl_DrawTransformFeedbackStreamInstanced)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_4_3(void)
{
bool hasExt=CoreGl_isAtLeastVersion(4,3);
CoreGl_extensionFunction(&CoreGl_ClearBufferData,
                         "glClearBufferData");
if(!CoreGl_ClearBufferData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearBufferSubData,
                         "glClearBufferSubData");
if(!CoreGl_ClearBufferSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DispatchCompute,
                         "glDispatchCompute");
if(!CoreGl_DispatchCompute)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DispatchComputeIndirect,
                         "glDispatchComputeIndirect");
if(!CoreGl_DispatchComputeIndirect)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyImageSubData,
                         "glCopyImageSubData");
if(!CoreGl_CopyImageSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FramebufferParameteri,
                         "glFramebufferParameteri");
if(!CoreGl_FramebufferParameteri)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetFramebufferParameteriv,
                         "glGetFramebufferParameteriv");
if(!CoreGl_GetFramebufferParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetInternalformati64v,
                         "glGetInternalformati64v");
if(!CoreGl_GetInternalformati64v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_InvalidateTexSubImage,
                         "glInvalidateTexSubImage");
if(!CoreGl_InvalidateTexSubImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_InvalidateTexImage,
                         "glInvalidateTexImage");
if(!CoreGl_InvalidateTexImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_InvalidateBufferSubData,
                         "glInvalidateBufferSubData");
if(!CoreGl_InvalidateBufferSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_InvalidateBufferData,
                         "glInvalidateBufferData");
if(!CoreGl_InvalidateBufferData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_InvalidateFramebuffer,
                         "glInvalidateFramebuffer");
if(!CoreGl_InvalidateFramebuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_InvalidateSubFramebuffer,
                         "glInvalidateSubFramebuffer");
if(!CoreGl_InvalidateSubFramebuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MultiDrawArraysIndirect,
                         "glMultiDrawArraysIndirect");
if(!CoreGl_MultiDrawArraysIndirect)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MultiDrawElementsIndirect,
                         "glMultiDrawElementsIndirect");
if(!CoreGl_MultiDrawElementsIndirect)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramInterfaceiv,
                         "glGetProgramInterfaceiv");
if(!CoreGl_GetProgramInterfaceiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramResourceIndex,
                         "glGetProgramResourceIndex");
if(!CoreGl_GetProgramResourceIndex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramResourceName,
                         "glGetProgramResourceName");
if(!CoreGl_GetProgramResourceName)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramResourceiv,
                         "glGetProgramResourceiv");
if(!CoreGl_GetProgramResourceiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramResourceLocation,
                         "glGetProgramResourceLocation");
if(!CoreGl_GetProgramResourceLocation)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetProgramResourceLocationIndex,
                         "glGetProgramResourceLocationIndex");
if(!CoreGl_GetProgramResourceLocationIndex)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ShaderStorageBlockBinding,
                         "glShaderStorageBlockBinding");
if(!CoreGl_ShaderStorageBlockBinding)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexBufferRange,
                         "glTexBufferRange");
if(!CoreGl_TexBufferRange)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexStorage2DMultisample,
                         "glTexStorage2DMultisample");
if(!CoreGl_TexStorage2DMultisample)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TexStorage3DMultisample,
                         "glTexStorage3DMultisample");
if(!CoreGl_TexStorage3DMultisample)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureView,
                         "glTextureView");
if(!CoreGl_TextureView)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindVertexBuffer,
                         "glBindVertexBuffer");
if(!CoreGl_BindVertexBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribFormat,
                         "glVertexAttribFormat");
if(!CoreGl_VertexAttribFormat)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribIFormat,
                         "glVertexAttribIFormat");
if(!CoreGl_VertexAttribIFormat)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribLFormat,
                         "glVertexAttribLFormat");
if(!CoreGl_VertexAttribLFormat)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexAttribBinding,
                         "glVertexAttribBinding");
if(!CoreGl_VertexAttribBinding)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexBindingDivisor,
                         "glVertexBindingDivisor");
if(!CoreGl_VertexBindingDivisor)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DebugMessageControl,
                         "glDebugMessageControl");
if(!CoreGl_DebugMessageControl)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DebugMessageInsert,
                         "glDebugMessageInsert");
if(!CoreGl_DebugMessageInsert)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DebugMessageCallback,
                         "glDebugMessageCallback");
if(!CoreGl_DebugMessageCallback)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetDebugMessageLog,
                         "glGetDebugMessageLog");
if(!CoreGl_GetDebugMessageLog)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PushDebugGroup,
                         "glPushDebugGroup");
if(!CoreGl_PushDebugGroup)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_PopDebugGroup,
                         "glPopDebugGroup");
if(!CoreGl_PopDebugGroup)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ObjectLabel,
                         "glObjectLabel");
if(!CoreGl_ObjectLabel)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetObjectLabel,
                         "glGetObjectLabel");
if(!CoreGl_GetObjectLabel)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ObjectPtrLabel,
                         "glObjectPtrLabel");
if(!CoreGl_ObjectPtrLabel)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetObjectPtrLabel,
                         "glGetObjectPtrLabel");
if(!CoreGl_GetObjectPtrLabel)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_4_4(void)
{
bool hasExt=CoreGl_isAtLeastVersion(4,4);
CoreGl_extensionFunction(&CoreGl_BufferStorage,
                         "glBufferStorage");
if(!CoreGl_BufferStorage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearTexImage,
                         "glClearTexImage");
if(!CoreGl_ClearTexImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearTexSubImage,
                         "glClearTexSubImage");
if(!CoreGl_ClearTexSubImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindBuffersBase,
                         "glBindBuffersBase");
if(!CoreGl_BindBuffersBase)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindBuffersRange,
                         "glBindBuffersRange");
if(!CoreGl_BindBuffersRange)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindTextures,
                         "glBindTextures");
if(!CoreGl_BindTextures)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindSamplers,
                         "glBindSamplers");
if(!CoreGl_BindSamplers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindImageTextures,
                         "glBindImageTextures");
if(!CoreGl_BindImageTextures)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindVertexBuffers,
                         "glBindVertexBuffers");
if(!CoreGl_BindVertexBuffers)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_VERSION_4_5(void)
{
bool hasExt=CoreGl_isAtLeastVersion(4,5);
CoreGl_extensionFunction(&CoreGl_ClipControl,
                         "glClipControl");
if(!CoreGl_ClipControl)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateTransformFeedbacks,
                         "glCreateTransformFeedbacks");
if(!CoreGl_CreateTransformFeedbacks)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TransformFeedbackBufferBase,
                         "glTransformFeedbackBufferBase");
if(!CoreGl_TransformFeedbackBufferBase)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TransformFeedbackBufferRange,
                         "glTransformFeedbackBufferRange");
if(!CoreGl_TransformFeedbackBufferRange)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTransformFeedbackiv,
                         "glGetTransformFeedbackiv");
if(!CoreGl_GetTransformFeedbackiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTransformFeedbacki_v,
                         "glGetTransformFeedbacki_v");
if(!CoreGl_GetTransformFeedbacki_v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTransformFeedbacki64_v,
                         "glGetTransformFeedbacki64_v");
if(!CoreGl_GetTransformFeedbacki64_v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateBuffers,
                         "glCreateBuffers");
if(!CoreGl_CreateBuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedBufferStorage,
                         "glNamedBufferStorage");
if(!CoreGl_NamedBufferStorage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedBufferData,
                         "glNamedBufferData");
if(!CoreGl_NamedBufferData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedBufferSubData,
                         "glNamedBufferSubData");
if(!CoreGl_NamedBufferSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyNamedBufferSubData,
                         "glCopyNamedBufferSubData");
if(!CoreGl_CopyNamedBufferSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearNamedBufferData,
                         "glClearNamedBufferData");
if(!CoreGl_ClearNamedBufferData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearNamedBufferSubData,
                         "glClearNamedBufferSubData");
if(!CoreGl_ClearNamedBufferSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MapNamedBuffer,
                         "glMapNamedBuffer");
if(!CoreGl_MapNamedBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MapNamedBufferRange,
                         "glMapNamedBufferRange");
if(!CoreGl_MapNamedBufferRange)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_UnmapNamedBuffer,
                         "glUnmapNamedBuffer");
if(!CoreGl_UnmapNamedBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_FlushMappedNamedBufferRange,
                         "glFlushMappedNamedBufferRange");
if(!CoreGl_FlushMappedNamedBufferRange)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetNamedBufferParameteriv,
                         "glGetNamedBufferParameteriv");
if(!CoreGl_GetNamedBufferParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetNamedBufferParameteri64v,
                         "glGetNamedBufferParameteri64v");
if(!CoreGl_GetNamedBufferParameteri64v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetNamedBufferPointerv,
                         "glGetNamedBufferPointerv");
if(!CoreGl_GetNamedBufferPointerv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetNamedBufferSubData,
                         "glGetNamedBufferSubData");
if(!CoreGl_GetNamedBufferSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateFramebuffers,
                         "glCreateFramebuffers");
if(!CoreGl_CreateFramebuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedFramebufferRenderbuffer,
                         "glNamedFramebufferRenderbuffer");
if(!CoreGl_NamedFramebufferRenderbuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedFramebufferParameteri,
                         "glNamedFramebufferParameteri");
if(!CoreGl_NamedFramebufferParameteri)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedFramebufferTexture,
                         "glNamedFramebufferTexture");
if(!CoreGl_NamedFramebufferTexture)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedFramebufferTextureLayer,
                         "glNamedFramebufferTextureLayer");
if(!CoreGl_NamedFramebufferTextureLayer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedFramebufferDrawBuffer,
                         "glNamedFramebufferDrawBuffer");
if(!CoreGl_NamedFramebufferDrawBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedFramebufferDrawBuffers,
                         "glNamedFramebufferDrawBuffers");
if(!CoreGl_NamedFramebufferDrawBuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedFramebufferReadBuffer,
                         "glNamedFramebufferReadBuffer");
if(!CoreGl_NamedFramebufferReadBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_InvalidateNamedFramebufferData,
                         "glInvalidateNamedFramebufferData");
if(!CoreGl_InvalidateNamedFramebufferData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_InvalidateNamedFramebufferSubData,
                         "glInvalidateNamedFramebufferSubData");
if(!CoreGl_InvalidateNamedFramebufferSubData)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearNamedFramebufferiv,
                         "glClearNamedFramebufferiv");
if(!CoreGl_ClearNamedFramebufferiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearNamedFramebufferuiv,
                         "glClearNamedFramebufferuiv");
if(!CoreGl_ClearNamedFramebufferuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearNamedFramebufferfv,
                         "glClearNamedFramebufferfv");
if(!CoreGl_ClearNamedFramebufferfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ClearNamedFramebufferfi,
                         "glClearNamedFramebufferfi");
if(!CoreGl_ClearNamedFramebufferfi)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BlitNamedFramebuffer,
                         "glBlitNamedFramebuffer");
if(!CoreGl_BlitNamedFramebuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CheckNamedFramebufferStatus,
                         "glCheckNamedFramebufferStatus");
if(!CoreGl_CheckNamedFramebufferStatus)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetNamedFramebufferParameteriv,
                         "glGetNamedFramebufferParameteriv");
if(!CoreGl_GetNamedFramebufferParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetNamedFramebufferAttachmentParameteriv,
                         "glGetNamedFramebufferAttachmentParameteriv");
if(!CoreGl_GetNamedFramebufferAttachmentParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateRenderbuffers,
                         "glCreateRenderbuffers");
if(!CoreGl_CreateRenderbuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedRenderbufferStorage,
                         "glNamedRenderbufferStorage");
if(!CoreGl_NamedRenderbufferStorage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_NamedRenderbufferStorageMultisample,
                         "glNamedRenderbufferStorageMultisample");
if(!CoreGl_NamedRenderbufferStorageMultisample)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetNamedRenderbufferParameteriv,
                         "glGetNamedRenderbufferParameteriv");
if(!CoreGl_GetNamedRenderbufferParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateTextures,
                         "glCreateTextures");
if(!CoreGl_CreateTextures)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureBuffer,
                         "glTextureBuffer");
if(!CoreGl_TextureBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureBufferRange,
                         "glTextureBufferRange");
if(!CoreGl_TextureBufferRange)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureStorage1D,
                         "glTextureStorage1D");
if(!CoreGl_TextureStorage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureStorage2D,
                         "glTextureStorage2D");
if(!CoreGl_TextureStorage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureStorage3D,
                         "glTextureStorage3D");
if(!CoreGl_TextureStorage3D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureStorage2DMultisample,
                         "glTextureStorage2DMultisample");
if(!CoreGl_TextureStorage2DMultisample)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureStorage3DMultisample,
                         "glTextureStorage3DMultisample");
if(!CoreGl_TextureStorage3DMultisample)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureSubImage1D,
                         "glTextureSubImage1D");
if(!CoreGl_TextureSubImage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureSubImage2D,
                         "glTextureSubImage2D");
if(!CoreGl_TextureSubImage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureSubImage3D,
                         "glTextureSubImage3D");
if(!CoreGl_TextureSubImage3D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CompressedTextureSubImage1D,
                         "glCompressedTextureSubImage1D");
if(!CoreGl_CompressedTextureSubImage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CompressedTextureSubImage2D,
                         "glCompressedTextureSubImage2D");
if(!CoreGl_CompressedTextureSubImage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CompressedTextureSubImage3D,
                         "glCompressedTextureSubImage3D");
if(!CoreGl_CompressedTextureSubImage3D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyTextureSubImage1D,
                         "glCopyTextureSubImage1D");
if(!CoreGl_CopyTextureSubImage1D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyTextureSubImage2D,
                         "glCopyTextureSubImage2D");
if(!CoreGl_CopyTextureSubImage2D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CopyTextureSubImage3D,
                         "glCopyTextureSubImage3D");
if(!CoreGl_CopyTextureSubImage3D)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureParameterf,
                         "glTextureParameterf");
if(!CoreGl_TextureParameterf)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureParameterfv,
                         "glTextureParameterfv");
if(!CoreGl_TextureParameterfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureParameteri,
                         "glTextureParameteri");
if(!CoreGl_TextureParameteri)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureParameterIiv,
                         "glTextureParameterIiv");
if(!CoreGl_TextureParameterIiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureParameterIuiv,
                         "glTextureParameterIuiv");
if(!CoreGl_TextureParameterIuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureParameteriv,
                         "glTextureParameteriv");
if(!CoreGl_TextureParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GenerateTextureMipmap,
                         "glGenerateTextureMipmap");
if(!CoreGl_GenerateTextureMipmap)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_BindTextureUnit,
                         "glBindTextureUnit");
if(!CoreGl_BindTextureUnit)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTextureImage,
                         "glGetTextureImage");
if(!CoreGl_GetTextureImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetCompressedTextureImage,
                         "glGetCompressedTextureImage");
if(!CoreGl_GetCompressedTextureImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTextureLevelParameterfv,
                         "glGetTextureLevelParameterfv");
if(!CoreGl_GetTextureLevelParameterfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTextureLevelParameteriv,
                         "glGetTextureLevelParameteriv");
if(!CoreGl_GetTextureLevelParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTextureParameterfv,
                         "glGetTextureParameterfv");
if(!CoreGl_GetTextureParameterfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTextureParameterIiv,
                         "glGetTextureParameterIiv");
if(!CoreGl_GetTextureParameterIiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTextureParameterIuiv,
                         "glGetTextureParameterIuiv");
if(!CoreGl_GetTextureParameterIuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTextureParameteriv,
                         "glGetTextureParameteriv");
if(!CoreGl_GetTextureParameteriv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateVertexArrays,
                         "glCreateVertexArrays");
if(!CoreGl_CreateVertexArrays)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_DisableVertexArrayAttrib,
                         "glDisableVertexArrayAttrib");
if(!CoreGl_DisableVertexArrayAttrib)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_EnableVertexArrayAttrib,
                         "glEnableVertexArrayAttrib");
if(!CoreGl_EnableVertexArrayAttrib)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexArrayElementBuffer,
                         "glVertexArrayElementBuffer");
if(!CoreGl_VertexArrayElementBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexArrayVertexBuffer,
                         "glVertexArrayVertexBuffer");
if(!CoreGl_VertexArrayVertexBuffer)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexArrayVertexBuffers,
                         "glVertexArrayVertexBuffers");
if(!CoreGl_VertexArrayVertexBuffers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexArrayAttribBinding,
                         "glVertexArrayAttribBinding");
if(!CoreGl_VertexArrayAttribBinding)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexArrayAttribFormat,
                         "glVertexArrayAttribFormat");
if(!CoreGl_VertexArrayAttribFormat)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexArrayAttribIFormat,
                         "glVertexArrayAttribIFormat");
if(!CoreGl_VertexArrayAttribIFormat)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexArrayAttribLFormat,
                         "glVertexArrayAttribLFormat");
if(!CoreGl_VertexArrayAttribLFormat)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_VertexArrayBindingDivisor,
                         "glVertexArrayBindingDivisor");
if(!CoreGl_VertexArrayBindingDivisor)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetVertexArrayiv,
                         "glGetVertexArrayiv");
if(!CoreGl_GetVertexArrayiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetVertexArrayIndexediv,
                         "glGetVertexArrayIndexediv");
if(!CoreGl_GetVertexArrayIndexediv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetVertexArrayIndexed64iv,
                         "glGetVertexArrayIndexed64iv");
if(!CoreGl_GetVertexArrayIndexed64iv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateSamplers,
                         "glCreateSamplers");
if(!CoreGl_CreateSamplers)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateProgramPipelines,
                         "glCreateProgramPipelines");
if(!CoreGl_CreateProgramPipelines)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_CreateQueries,
                         "glCreateQueries");
if(!CoreGl_CreateQueries)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetQueryBufferObjecti64v,
                         "glGetQueryBufferObjecti64v");
if(!CoreGl_GetQueryBufferObjecti64v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetQueryBufferObjectiv,
                         "glGetQueryBufferObjectiv");
if(!CoreGl_GetQueryBufferObjectiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetQueryBufferObjectui64v,
                         "glGetQueryBufferObjectui64v");
if(!CoreGl_GetQueryBufferObjectui64v)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetQueryBufferObjectuiv,
                         "glGetQueryBufferObjectuiv");
if(!CoreGl_GetQueryBufferObjectuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_MemoryBarrierByRegion,
                         "glMemoryBarrierByRegion");
if(!CoreGl_MemoryBarrierByRegion)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetTextureSubImage,
                         "glGetTextureSubImage");
if(!CoreGl_GetTextureSubImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetCompressedTextureSubImage,
                         "glGetCompressedTextureSubImage");
if(!CoreGl_GetCompressedTextureSubImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetGraphicsResetStatus,
                         "glGetGraphicsResetStatus");
if(!CoreGl_GetGraphicsResetStatus)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetnCompressedTexImage,
                         "glGetnCompressedTexImage");
if(!CoreGl_GetnCompressedTexImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetnTexImage,
                         "glGetnTexImage");
if(!CoreGl_GetnTexImage)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetnUniformdv,
                         "glGetnUniformdv");
if(!CoreGl_GetnUniformdv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetnUniformfv,
                         "glGetnUniformfv");
if(!CoreGl_GetnUniformfv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetnUniformiv,
                         "glGetnUniformiv");
if(!CoreGl_GetnUniformiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_GetnUniformuiv,
                         "glGetnUniformuiv");
if(!CoreGl_GetnUniformuiv)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_ReadnPixels,
                         "glReadnPixels");
if(!CoreGl_ReadnPixels)
  {
  hasExt=false;
  }
CoreGl_extensionFunction(&CoreGl_TextureBarrier,
                         "glTextureBarrier");
if(!CoreGl_TextureBarrier)
  {
  hasExt=false;
  }
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_ES2_compatibility(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_ES2_compatibility");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_ES3_1_compatibility(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_ES3_1_compatibility");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_ES3_compatibility(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_ES3_compatibility");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_arrays_of_arrays(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_arrays_of_arrays");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_base_instance(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_base_instance");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_bindless_texture(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_bindless_texture");
CoreGl_extensionFunction(&CoreGl_GetTextureHandleARB,
                         "glGetTextureHandleARB");
ON_ERROR(hasExt&&!CoreGl_GetTextureHandleARB,
         "missing glGetTextureHandleARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetTextureSamplerHandleARB,
                         "glGetTextureSamplerHandleARB");
ON_ERROR(hasExt&&!CoreGl_GetTextureSamplerHandleARB,
         "missing glGetTextureSamplerHandleARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_MakeTextureHandleResidentARB,
                         "glMakeTextureHandleResidentARB");
ON_ERROR(hasExt&&!CoreGl_MakeTextureHandleResidentARB,
         "missing glMakeTextureHandleResidentARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_MakeTextureHandleNonResidentARB,
                         "glMakeTextureHandleNonResidentARB");
ON_ERROR(hasExt&&!CoreGl_MakeTextureHandleNonResidentARB,
         "missing glMakeTextureHandleNonResidentARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetImageHandleARB,
                         "glGetImageHandleARB");
ON_ERROR(hasExt&&!CoreGl_GetImageHandleARB,
         "missing glGetImageHandleARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_MakeImageHandleResidentARB,
                         "glMakeImageHandleResidentARB");
ON_ERROR(hasExt&&!CoreGl_MakeImageHandleResidentARB,
         "missing glMakeImageHandleResidentARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_MakeImageHandleNonResidentARB,
                         "glMakeImageHandleNonResidentARB");
ON_ERROR(hasExt&&!CoreGl_MakeImageHandleNonResidentARB,
         "missing glMakeImageHandleNonResidentARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_UniformHandleui64ARB,
                         "glUniformHandleui64ARB");
ON_ERROR(hasExt&&!CoreGl_UniformHandleui64ARB,
         "missing glUniformHandleui64ARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_UniformHandleui64vARB,
                         "glUniformHandleui64vARB");
ON_ERROR(hasExt&&!CoreGl_UniformHandleui64vARB,
         "missing glUniformHandleui64vARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_ProgramUniformHandleui64ARB,
                         "glProgramUniformHandleui64ARB");
ON_ERROR(hasExt&&!CoreGl_ProgramUniformHandleui64ARB,
         "missing glProgramUniformHandleui64ARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_ProgramUniformHandleui64vARB,
                         "glProgramUniformHandleui64vARB");
ON_ERROR(hasExt&&!CoreGl_ProgramUniformHandleui64vARB,
         "missing glProgramUniformHandleui64vARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_IsTextureHandleResidentARB,
                         "glIsTextureHandleResidentARB");
ON_ERROR(hasExt&&!CoreGl_IsTextureHandleResidentARB,
         "missing glIsTextureHandleResidentARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_IsImageHandleResidentARB,
                         "glIsImageHandleResidentARB");
ON_ERROR(hasExt&&!CoreGl_IsImageHandleResidentARB,
         "missing glIsImageHandleResidentARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_VertexAttribL1ui64ARB,
                         "glVertexAttribL1ui64ARB");
ON_ERROR(hasExt&&!CoreGl_VertexAttribL1ui64ARB,
         "missing glVertexAttribL1ui64ARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_VertexAttribL1ui64vARB,
                         "glVertexAttribL1ui64vARB");
ON_ERROR(hasExt&&!CoreGl_VertexAttribL1ui64vARB,
         "missing glVertexAttribL1ui64vARB() in GL_ARB_bindless_texture extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetVertexAttribLui64vARB,
                         "glGetVertexAttribLui64vARB");
ON_ERROR(hasExt&&!CoreGl_GetVertexAttribLui64vARB,
         "missing glGetVertexAttribLui64vARB() in GL_ARB_bindless_texture extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_blend_func_extended(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_blend_func_extended");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_buffer_storage(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_buffer_storage");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_cl_event(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_cl_event");
CoreGl_extensionFunction(&CoreGl_CreateSyncFromCLeventARB,
                         "glCreateSyncFromCLeventARB");
ON_ERROR(hasExt&&!CoreGl_CreateSyncFromCLeventARB,
         "missing glCreateSyncFromCLeventARB() in GL_ARB_cl_event extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_clear_buffer_object(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_clear_buffer_object");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_clear_texture(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_clear_texture");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_clip_control(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_clip_control");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_compressed_texture_pixel_storage(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_compressed_texture_pixel_storage");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_compute_shader(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_compute_shader");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_compute_variable_group_size(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_compute_variable_group_size");
CoreGl_extensionFunction(&CoreGl_DispatchComputeGroupSizeARB,
                         "glDispatchComputeGroupSizeARB");
ON_ERROR(hasExt&&!CoreGl_DispatchComputeGroupSizeARB,
         "missing glDispatchComputeGroupSizeARB() in GL_ARB_compute_variable_group_size extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_conditional_render_inverted(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_conditional_render_inverted");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_conservative_depth(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_conservative_depth");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_copy_buffer(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_copy_buffer");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_copy_image(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_copy_image");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_cull_distance(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_cull_distance");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_debug_output(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_debug_output");
CoreGl_extensionFunction(&CoreGl_DebugMessageControlARB,
                         "glDebugMessageControlARB");
ON_ERROR(hasExt&&!CoreGl_DebugMessageControlARB,
         "missing glDebugMessageControlARB() in GL_ARB_debug_output extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_DebugMessageInsertARB,
                         "glDebugMessageInsertARB");
ON_ERROR(hasExt&&!CoreGl_DebugMessageInsertARB,
         "missing glDebugMessageInsertARB() in GL_ARB_debug_output extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_DebugMessageCallbackARB,
                         "glDebugMessageCallbackARB");
ON_ERROR(hasExt&&!CoreGl_DebugMessageCallbackARB,
         "missing glDebugMessageCallbackARB() in GL_ARB_debug_output extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetDebugMessageLogARB,
                         "glGetDebugMessageLogARB");
ON_ERROR(hasExt&&!CoreGl_GetDebugMessageLogARB,
         "missing glGetDebugMessageLogARB() in GL_ARB_debug_output extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_depth_buffer_float(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_depth_buffer_float");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_depth_clamp(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_depth_clamp");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_derivative_control(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_derivative_control");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_direct_state_access(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_direct_state_access");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_draw_buffers_blend(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_draw_buffers_blend");
CoreGl_extensionFunction(&CoreGl_BlendEquationiARB,
                         "glBlendEquationiARB");
ON_ERROR(hasExt&&!CoreGl_BlendEquationiARB,
         "missing glBlendEquationiARB() in GL_ARB_draw_buffers_blend extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_BlendEquationSeparateiARB,
                         "glBlendEquationSeparateiARB");
ON_ERROR(hasExt&&!CoreGl_BlendEquationSeparateiARB,
         "missing glBlendEquationSeparateiARB() in GL_ARB_draw_buffers_blend extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_BlendFunciARB,
                         "glBlendFunciARB");
ON_ERROR(hasExt&&!CoreGl_BlendFunciARB,
         "missing glBlendFunciARB() in GL_ARB_draw_buffers_blend extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_BlendFuncSeparateiARB,
                         "glBlendFuncSeparateiARB");
ON_ERROR(hasExt&&!CoreGl_BlendFuncSeparateiARB,
         "missing glBlendFuncSeparateiARB() in GL_ARB_draw_buffers_blend extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_draw_elements_base_vertex(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_draw_elements_base_vertex");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_draw_indirect(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_draw_indirect");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_enhanced_layouts(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_enhanced_layouts");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_explicit_attrib_location(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_explicit_attrib_location");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_explicit_uniform_location(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_explicit_uniform_location");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_fragment_coord_conventions(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_fragment_coord_conventions");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_fragment_layer_viewport(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_fragment_layer_viewport");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_framebuffer_no_attachments(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_framebuffer_no_attachments");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_framebuffer_object(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_framebuffer_object");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_framebuffer_sRGB(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_framebuffer_sRGB");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_get_program_binary(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_get_program_binary");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_get_texture_sub_image(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_get_texture_sub_image");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_gpu_shader5(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_gpu_shader5");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_gpu_shader_fp64(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_gpu_shader_fp64");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_half_float_vertex(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_half_float_vertex");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_imaging(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_imaging");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_indirect_parameters(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_indirect_parameters");
CoreGl_extensionFunction(&CoreGl_MultiDrawArraysIndirectCountARB,
                         "glMultiDrawArraysIndirectCountARB");
ON_ERROR(hasExt&&!CoreGl_MultiDrawArraysIndirectCountARB,
         "missing glMultiDrawArraysIndirectCountARB() in GL_ARB_indirect_parameters extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_MultiDrawElementsIndirectCountARB,
                         "glMultiDrawElementsIndirectCountARB");
ON_ERROR(hasExt&&!CoreGl_MultiDrawElementsIndirectCountARB,
         "missing glMultiDrawElementsIndirectCountARB() in GL_ARB_indirect_parameters extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_internalformat_query(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_internalformat_query");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_internalformat_query2(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_internalformat_query2");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_invalidate_subdata(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_invalidate_subdata");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_map_buffer_alignment(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_map_buffer_alignment");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_map_buffer_range(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_map_buffer_range");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_multi_bind(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_multi_bind");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_multi_draw_indirect(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_multi_draw_indirect");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_occlusion_query2(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_occlusion_query2");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_pipeline_statistics_query(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_pipeline_statistics_query");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_program_interface_query(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_program_interface_query");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_provoking_vertex(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_provoking_vertex");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_query_buffer_object(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_query_buffer_object");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_robust_buffer_access_behavior(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_robust_buffer_access_behavior");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_robustness(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_robustness");
CoreGl_extensionFunction(&CoreGl_GetGraphicsResetStatusARB,
                         "glGetGraphicsResetStatusARB");
ON_ERROR(hasExt&&!CoreGl_GetGraphicsResetStatusARB,
         "missing glGetGraphicsResetStatusARB() in GL_ARB_robustness extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetnTexImageARB,
                         "glGetnTexImageARB");
ON_ERROR(hasExt&&!CoreGl_GetnTexImageARB,
         "missing glGetnTexImageARB() in GL_ARB_robustness extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_ReadnPixelsARB,
                         "glReadnPixelsARB");
ON_ERROR(hasExt&&!CoreGl_ReadnPixelsARB,
         "missing glReadnPixelsARB() in GL_ARB_robustness extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetnCompressedTexImageARB,
                         "glGetnCompressedTexImageARB");
ON_ERROR(hasExt&&!CoreGl_GetnCompressedTexImageARB,
         "missing glGetnCompressedTexImageARB() in GL_ARB_robustness extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetnUniformfvARB,
                         "glGetnUniformfvARB");
ON_ERROR(hasExt&&!CoreGl_GetnUniformfvARB,
         "missing glGetnUniformfvARB() in GL_ARB_robustness extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetnUniformivARB,
                         "glGetnUniformivARB");
ON_ERROR(hasExt&&!CoreGl_GetnUniformivARB,
         "missing glGetnUniformivARB() in GL_ARB_robustness extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetnUniformuivARB,
                         "glGetnUniformuivARB");
ON_ERROR(hasExt&&!CoreGl_GetnUniformuivARB,
         "missing glGetnUniformuivARB() in GL_ARB_robustness extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetnUniformdvARB,
                         "glGetnUniformdvARB");
ON_ERROR(hasExt&&!CoreGl_GetnUniformdvARB,
         "missing glGetnUniformdvARB() in GL_ARB_robustness extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_robustness_isolation(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_robustness_isolation");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_sample_shading(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_sample_shading");
CoreGl_extensionFunction(&CoreGl_MinSampleShadingARB,
                         "glMinSampleShadingARB");
ON_ERROR(hasExt&&!CoreGl_MinSampleShadingARB,
         "missing glMinSampleShadingARB() in GL_ARB_sample_shading extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_sampler_objects(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_sampler_objects");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_seamless_cube_map(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_seamless_cube_map");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_seamless_cubemap_per_texture(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_seamless_cubemap_per_texture");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_separate_shader_objects(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_separate_shader_objects");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_atomic_counters(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_atomic_counters");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_bit_encoding(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_bit_encoding");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_draw_parameters(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_draw_parameters");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_group_vote(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_group_vote");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_image_load_store(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_image_load_store");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_image_size(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_image_size");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_precision(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_precision");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_stencil_export(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_stencil_export");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_storage_buffer_object(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_storage_buffer_object");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_subroutine(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_subroutine");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shader_texture_image_samples(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shader_texture_image_samples");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shading_language_420pack(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shading_language_420pack");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shading_language_include(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shading_language_include");
CoreGl_extensionFunction(&CoreGl_NamedStringARB,
                         "glNamedStringARB");
ON_ERROR(hasExt&&!CoreGl_NamedStringARB,
         "missing glNamedStringARB() in GL_ARB_shading_language_include extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_DeleteNamedStringARB,
                         "glDeleteNamedStringARB");
ON_ERROR(hasExt&&!CoreGl_DeleteNamedStringARB,
         "missing glDeleteNamedStringARB() in GL_ARB_shading_language_include extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_CompileShaderIncludeARB,
                         "glCompileShaderIncludeARB");
ON_ERROR(hasExt&&!CoreGl_CompileShaderIncludeARB,
         "missing glCompileShaderIncludeARB() in GL_ARB_shading_language_include extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_IsNamedStringARB,
                         "glIsNamedStringARB");
ON_ERROR(hasExt&&!CoreGl_IsNamedStringARB,
         "missing glIsNamedStringARB() in GL_ARB_shading_language_include extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetNamedStringARB,
                         "glGetNamedStringARB");
ON_ERROR(hasExt&&!CoreGl_GetNamedStringARB,
         "missing glGetNamedStringARB() in GL_ARB_shading_language_include extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_GetNamedStringivARB,
                         "glGetNamedStringivARB");
ON_ERROR(hasExt&&!CoreGl_GetNamedStringivARB,
         "missing glGetNamedStringivARB() in GL_ARB_shading_language_include extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_shading_language_packing(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_shading_language_packing");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_sparse_buffer(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_sparse_buffer");
CoreGl_extensionFunction(&CoreGl_BufferPageCommitmentARB,
                         "glBufferPageCommitmentARB");
ON_ERROR(hasExt&&!CoreGl_BufferPageCommitmentARB,
         "missing glBufferPageCommitmentARB() in GL_ARB_sparse_buffer extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_NamedBufferPageCommitmentEXT,
                         "glNamedBufferPageCommitmentEXT");
ON_ERROR(hasExt&&!CoreGl_NamedBufferPageCommitmentEXT,
         "missing glNamedBufferPageCommitmentEXT() in GL_ARB_sparse_buffer extension\n",
         {});
CoreGl_extensionFunction(&CoreGl_NamedBufferPageCommitmentARB,
                         "glNamedBufferPageCommitmentARB");
ON_ERROR(hasExt&&!CoreGl_NamedBufferPageCommitmentARB,
         "missing glNamedBufferPageCommitmentARB() in GL_ARB_sparse_buffer extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_sparse_texture(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_sparse_texture");
CoreGl_extensionFunction(&CoreGl_TexPageCommitmentARB,
                         "glTexPageCommitmentARB");
ON_ERROR(hasExt&&!CoreGl_TexPageCommitmentARB,
         "missing glTexPageCommitmentARB() in GL_ARB_sparse_texture extension\n",
         {});
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_stencil_texturing(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_stencil_texturing");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_sync(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_sync");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_tessellation_shader(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_tessellation_shader");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_barrier(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_barrier");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_buffer_object_rgb32(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_buffer_object_rgb32");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_buffer_range(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_buffer_range");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_compression_bptc(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_compression_bptc");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_compression_rgtc(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_compression_rgtc");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_cube_map_array(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_cube_map_array");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_gather(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_gather");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_mirror_clamp_to_edge(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_mirror_clamp_to_edge");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_multisample(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_multisample");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_query_levels(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_query_levels");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_query_lod(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_query_lod");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_rg(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_rg");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_rgb10_a2ui(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_rgb10_a2ui");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_stencil8(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_stencil8");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_storage(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_storage");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_storage_multisample(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_storage_multisample");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_swizzle(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_swizzle");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_texture_view(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_texture_view");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_timer_query(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_timer_query");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_transform_feedback2(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_transform_feedback2");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_transform_feedback3(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_transform_feedback3");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_transform_feedback_instanced(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_transform_feedback_instanced");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_transform_feedback_overflow_query(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_transform_feedback_overflow_query");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_uniform_buffer_object(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_uniform_buffer_object");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_vertex_array_bgra(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_vertex_array_bgra");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_vertex_array_object(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_vertex_array_object");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_vertex_attrib_64bit(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_vertex_attrib_64bit");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_vertex_attrib_binding(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_vertex_attrib_binding");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_vertex_type_10f_11f_11f_rev(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_vertex_type_10f_11f_11f_rev");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_vertex_type_2_10_10_10_rev(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_vertex_type_2_10_10_10_rev");
return hasExt;
}

static
bool // extension is available
CoreGl_load_ARB_viewport_array(void)
{
bool hasExt=CoreGl_hasExtension("GL_ARB_viewport_array");
return hasExt;
}

static
bool // extension is available
CoreGl_load_KHR_context_flush_control(void)
{
bool hasExt=CoreGl_hasExtension("GL_KHR_context_flush_control");
return hasExt;
}

static
bool // extension is available
CoreGl_load_KHR_debug(void)
{
bool hasExt=CoreGl_hasExtension("GL_KHR_debug");
return hasExt;
}

static
bool // extension is available
CoreGl_load_KHR_no_error(void)
{
bool hasExt=CoreGl_hasExtension("GL_KHR_no_error");
return hasExt;
}

static
bool // extension is available
CoreGl_load_KHR_robust_buffer_access_behavior(void)
{
bool hasExt=CoreGl_hasExtension("GL_KHR_robust_buffer_access_behavior");
return hasExt;
}

static
bool // extension is available
CoreGl_load_KHR_robustness(void)
{
bool hasExt=CoreGl_hasExtension("GL_KHR_robustness");
return hasExt;
}

static
bool // extension is available
CoreGl_load_KHR_texture_compression_astc_hdr(void)
{
bool hasExt=CoreGl_hasExtension("GL_KHR_texture_compression_astc_hdr");
return hasExt;
}

static
bool // extension is available
CoreGl_load_KHR_texture_compression_astc_ldr(void)
{
bool hasExt=CoreGl_hasExtension("GL_KHR_texture_compression_astc_ldr");
return hasExt;
}

static
bool // extension is available
CoreGl_load_KHR_texture_compression_astc_sliced_3d(void)
{
bool hasExt=CoreGl_hasExtension("GL_KHR_texture_compression_astc_sliced_3d");
return hasExt;
}

bool // success
CoreGl_init(void)
{
if(!_CoreGl_mgr.initDone)
  {
  _CoreGl_mgr.coreProfile=false;
  _CoreGl_mgr.embedded=false;
  _CoreGl_mgr.majorVersion=0;
  _CoreGl_mgr.minorVersion=0;
  _CoreGl_mgr.shadingLanguageVersion=0;
  _CoreGl_mgr.extensionCount=0;
  _CoreGl_mgr.extensions=Memory_alloc(1,char *);
  _CoreGl_mgr.extensions[0]=(char *)0;
  _CoreGl_mgr.hasTessControlShaders=false;
  _CoreGl_mgr.hasTessEvaluationShaders=false;
  _CoreGl_mgr.hasGeometryShaders=false;
  _CoreGl_mgr.hasComputeShaders=false;
  CoreGl_extensionFunction(&glGetError,"glGetError");
  ON_ERROR(!glGetError,"glGetError() not found",{ return false; });
  CoreGl_extensionFunction(&glGetIntegerv,"glGetIntegerv");
  ON_ERROR(!glGetIntegerv,"glGetIntegerv() not found",{ return false; });
  CoreGl_extensionFunction(&glGetString,"glGetString");
  ON_ERROR(!glGetString,"glGetString() not found",{ return false; });
  int value=-1;
  glGetIntegerv(GL_CONTEXT_PROFILE_MASK,&value); // may fail
  if(value==-1) glGetError(); // clear previous error
  else
    {
    if(value&GL_CONTEXT_CORE_PROFILE_BIT)
      {
      _CoreGl_mgr.coreProfile=true;
      }
    }
  bool success=false;
  const char *version=(const char *)glGetString(GL_VERSION);
  ON_GL_ERROR({ return false; });
  if(version)
    {
    int major,minor;
    if(sscanf(version," %d.%d ",&major,&minor)==2)
      {
      _CoreGl_mgr.majorVersion=major;
      _CoreGl_mgr.minorVersion=minor;
      success=true;
      }
    else if(sscanf(version," OpenGL ES %d.%d ",&major,&minor)==2)
      {
      _CoreGl_mgr.embedded=true;
      _CoreGl_mgr.majorVersion=major;
      _CoreGl_mgr.minorVersion=minor;
      success=true;
      }
    }
  ON_ERROR(!success,"OpenGL version not detected",{ return false; });
  success=false;
  const char *glslVersion=(const char *)
                          glGetString(GL_SHADING_LANGUAGE_VERSION);
  ON_GL_ERROR({ return false; });
  if(glslVersion)
    {
    int major,minor;
    if(((sscanf(glslVersion," %d.%d ",&major,&minor)==2)||
        (sscanf(glslVersion," OpenGL ES GLSL %d.%d ",&major,&minor)==2)||
        (sscanf(glslVersion," OpenGL ES GLSL ES %d.%d ",&major,&minor)==2))&&
       (minor<100))
      {
      _CoreGl_mgr.shadingLanguageVersion=100*major+minor;
      success=true;
      }
    }
  ON_ERROR(!success,"OpenGL GLSL version not detected",{ return false; });
  CoreGl_extensionFunction(&glGetStringi,"glGetStringi"); // may fail
  if(glGetStringi) // modern means to detect extensions
    {
    int extCount=0;
    glGetIntegerv(GL_NUM_EXTENSIONS,&extCount); // may fail
    if(!extCount) glGetError(); // clear previous error
    else
      {
      _CoreGl_mgr.extensions=Memory_reAlloc(_CoreGl_mgr.extensions,
                                            extCount+1,char *);
      for(int i=0;i<extCount;++i)
        {
        const char *s=(const char *)glGetStringi(GL_EXTENSIONS,i); // may fail
        if(!s) glGetError(); // clear previous error
        else
          {
          int extLen=(int)strlen(s);
          char *ext=Memory_alloc(extLen+1,char);
          memcpy(ext,s,extLen+1);
          _CoreGl_mgr.extensions[_CoreGl_mgr.extensionCount++]=ext;
          }
        }
      _CoreGl_mgr.extensions[_CoreGl_mgr.extensionCount]=(char *)0;
      }
    }
  if(!_CoreGl_mgr.extensionCount) // fallback to legacy extension detection
    {
    const char *extList=(const char *)glGetString(GL_EXTENSIONS); // may fail
    if(!extList) glGetError(); // clear previous error
    else
      {
      CoreGl_addExtensionList(extList);
      }
    }
  CoreGl_addExtensionList(_CoreGl_querySpecificExtensions());
  _CoreGl_mgr.has_VERSION_1_0=CoreGl_load_VERSION_1_0();
  _CoreGl_mgr.has_VERSION_1_1=CoreGl_load_VERSION_1_1();
  _CoreGl_mgr.has_VERSION_1_2=CoreGl_load_VERSION_1_2();
  _CoreGl_mgr.has_VERSION_1_3=CoreGl_load_VERSION_1_3();
  _CoreGl_mgr.has_VERSION_1_4=CoreGl_load_VERSION_1_4();
  _CoreGl_mgr.has_VERSION_1_5=CoreGl_load_VERSION_1_5();
  _CoreGl_mgr.has_VERSION_2_0=CoreGl_load_VERSION_2_0();
  _CoreGl_mgr.has_VERSION_2_1=CoreGl_load_VERSION_2_1();
  _CoreGl_mgr.has_VERSION_3_0=CoreGl_load_VERSION_3_0();
  _CoreGl_mgr.has_VERSION_3_1=CoreGl_load_VERSION_3_1();
  _CoreGl_mgr.has_VERSION_3_2=CoreGl_load_VERSION_3_2();
  _CoreGl_mgr.has_VERSION_3_3=CoreGl_load_VERSION_3_3();
  _CoreGl_mgr.has_VERSION_4_0=CoreGl_load_VERSION_4_0();
  _CoreGl_mgr.has_VERSION_4_1=CoreGl_load_VERSION_4_1();
  _CoreGl_mgr.has_VERSION_4_2=CoreGl_load_VERSION_4_2();
  _CoreGl_mgr.has_VERSION_4_3=CoreGl_load_VERSION_4_3();
  _CoreGl_mgr.has_VERSION_4_4=CoreGl_load_VERSION_4_4();
  _CoreGl_mgr.has_VERSION_4_5=CoreGl_load_VERSION_4_5();
  _CoreGl_mgr.has_ARB_ES2_compatibility=CoreGl_load_ARB_ES2_compatibility();
  _CoreGl_mgr.has_ARB_ES3_1_compatibility=CoreGl_load_ARB_ES3_1_compatibility();
  _CoreGl_mgr.has_ARB_ES3_compatibility=CoreGl_load_ARB_ES3_compatibility();
  _CoreGl_mgr.has_ARB_arrays_of_arrays=CoreGl_load_ARB_arrays_of_arrays();
  _CoreGl_mgr.has_ARB_base_instance=CoreGl_load_ARB_base_instance();
  _CoreGl_mgr.has_ARB_bindless_texture=CoreGl_load_ARB_bindless_texture();
  _CoreGl_mgr.has_ARB_blend_func_extended=CoreGl_load_ARB_blend_func_extended();
  _CoreGl_mgr.has_ARB_buffer_storage=CoreGl_load_ARB_buffer_storage();
  _CoreGl_mgr.has_ARB_cl_event=CoreGl_load_ARB_cl_event();
  _CoreGl_mgr.has_ARB_clear_buffer_object=CoreGl_load_ARB_clear_buffer_object();
  _CoreGl_mgr.has_ARB_clear_texture=CoreGl_load_ARB_clear_texture();
  _CoreGl_mgr.has_ARB_clip_control=CoreGl_load_ARB_clip_control();
  _CoreGl_mgr.has_ARB_compressed_texture_pixel_storage=CoreGl_load_ARB_compressed_texture_pixel_storage();
  _CoreGl_mgr.has_ARB_compute_shader=CoreGl_load_ARB_compute_shader();
  _CoreGl_mgr.has_ARB_compute_variable_group_size=CoreGl_load_ARB_compute_variable_group_size();
  _CoreGl_mgr.has_ARB_conditional_render_inverted=CoreGl_load_ARB_conditional_render_inverted();
  _CoreGl_mgr.has_ARB_conservative_depth=CoreGl_load_ARB_conservative_depth();
  _CoreGl_mgr.has_ARB_copy_buffer=CoreGl_load_ARB_copy_buffer();
  _CoreGl_mgr.has_ARB_copy_image=CoreGl_load_ARB_copy_image();
  _CoreGl_mgr.has_ARB_cull_distance=CoreGl_load_ARB_cull_distance();
  _CoreGl_mgr.has_ARB_debug_output=CoreGl_load_ARB_debug_output();
  _CoreGl_mgr.has_ARB_depth_buffer_float=CoreGl_load_ARB_depth_buffer_float();
  _CoreGl_mgr.has_ARB_depth_clamp=CoreGl_load_ARB_depth_clamp();
  _CoreGl_mgr.has_ARB_derivative_control=CoreGl_load_ARB_derivative_control();
  _CoreGl_mgr.has_ARB_direct_state_access=CoreGl_load_ARB_direct_state_access();
  _CoreGl_mgr.has_ARB_draw_buffers_blend=CoreGl_load_ARB_draw_buffers_blend();
  _CoreGl_mgr.has_ARB_draw_elements_base_vertex=CoreGl_load_ARB_draw_elements_base_vertex();
  _CoreGl_mgr.has_ARB_draw_indirect=CoreGl_load_ARB_draw_indirect();
  _CoreGl_mgr.has_ARB_enhanced_layouts=CoreGl_load_ARB_enhanced_layouts();
  _CoreGl_mgr.has_ARB_explicit_attrib_location=CoreGl_load_ARB_explicit_attrib_location();
  _CoreGl_mgr.has_ARB_explicit_uniform_location=CoreGl_load_ARB_explicit_uniform_location();
  _CoreGl_mgr.has_ARB_fragment_coord_conventions=CoreGl_load_ARB_fragment_coord_conventions();
  _CoreGl_mgr.has_ARB_fragment_layer_viewport=CoreGl_load_ARB_fragment_layer_viewport();
  _CoreGl_mgr.has_ARB_framebuffer_no_attachments=CoreGl_load_ARB_framebuffer_no_attachments();
  _CoreGl_mgr.has_ARB_framebuffer_object=CoreGl_load_ARB_framebuffer_object();
  _CoreGl_mgr.has_ARB_framebuffer_sRGB=CoreGl_load_ARB_framebuffer_sRGB();
  _CoreGl_mgr.has_ARB_get_program_binary=CoreGl_load_ARB_get_program_binary();
  _CoreGl_mgr.has_ARB_get_texture_sub_image=CoreGl_load_ARB_get_texture_sub_image();
  _CoreGl_mgr.has_ARB_gpu_shader5=CoreGl_load_ARB_gpu_shader5();
  _CoreGl_mgr.has_ARB_gpu_shader_fp64=CoreGl_load_ARB_gpu_shader_fp64();
  _CoreGl_mgr.has_ARB_half_float_vertex=CoreGl_load_ARB_half_float_vertex();
  _CoreGl_mgr.has_ARB_imaging=CoreGl_load_ARB_imaging();
  _CoreGl_mgr.has_ARB_indirect_parameters=CoreGl_load_ARB_indirect_parameters();
  _CoreGl_mgr.has_ARB_internalformat_query=CoreGl_load_ARB_internalformat_query();
  _CoreGl_mgr.has_ARB_internalformat_query2=CoreGl_load_ARB_internalformat_query2();
  _CoreGl_mgr.has_ARB_invalidate_subdata=CoreGl_load_ARB_invalidate_subdata();
  _CoreGl_mgr.has_ARB_map_buffer_alignment=CoreGl_load_ARB_map_buffer_alignment();
  _CoreGl_mgr.has_ARB_map_buffer_range=CoreGl_load_ARB_map_buffer_range();
  _CoreGl_mgr.has_ARB_multi_bind=CoreGl_load_ARB_multi_bind();
  _CoreGl_mgr.has_ARB_multi_draw_indirect=CoreGl_load_ARB_multi_draw_indirect();
  _CoreGl_mgr.has_ARB_occlusion_query2=CoreGl_load_ARB_occlusion_query2();
  _CoreGl_mgr.has_ARB_pipeline_statistics_query=CoreGl_load_ARB_pipeline_statistics_query();
  _CoreGl_mgr.has_ARB_program_interface_query=CoreGl_load_ARB_program_interface_query();
  _CoreGl_mgr.has_ARB_provoking_vertex=CoreGl_load_ARB_provoking_vertex();
  _CoreGl_mgr.has_ARB_query_buffer_object=CoreGl_load_ARB_query_buffer_object();
  _CoreGl_mgr.has_ARB_robust_buffer_access_behavior=CoreGl_load_ARB_robust_buffer_access_behavior();
  _CoreGl_mgr.has_ARB_robustness=CoreGl_load_ARB_robustness();
  _CoreGl_mgr.has_ARB_robustness_isolation=CoreGl_load_ARB_robustness_isolation();
  _CoreGl_mgr.has_ARB_sample_shading=CoreGl_load_ARB_sample_shading();
  _CoreGl_mgr.has_ARB_sampler_objects=CoreGl_load_ARB_sampler_objects();
  _CoreGl_mgr.has_ARB_seamless_cube_map=CoreGl_load_ARB_seamless_cube_map();
  _CoreGl_mgr.has_ARB_seamless_cubemap_per_texture=CoreGl_load_ARB_seamless_cubemap_per_texture();
  _CoreGl_mgr.has_ARB_separate_shader_objects=CoreGl_load_ARB_separate_shader_objects();
  _CoreGl_mgr.has_ARB_shader_atomic_counters=CoreGl_load_ARB_shader_atomic_counters();
  _CoreGl_mgr.has_ARB_shader_bit_encoding=CoreGl_load_ARB_shader_bit_encoding();
  _CoreGl_mgr.has_ARB_shader_draw_parameters=CoreGl_load_ARB_shader_draw_parameters();
  _CoreGl_mgr.has_ARB_shader_group_vote=CoreGl_load_ARB_shader_group_vote();
  _CoreGl_mgr.has_ARB_shader_image_load_store=CoreGl_load_ARB_shader_image_load_store();
  _CoreGl_mgr.has_ARB_shader_image_size=CoreGl_load_ARB_shader_image_size();
  _CoreGl_mgr.has_ARB_shader_precision=CoreGl_load_ARB_shader_precision();
  _CoreGl_mgr.has_ARB_shader_stencil_export=CoreGl_load_ARB_shader_stencil_export();
  _CoreGl_mgr.has_ARB_shader_storage_buffer_object=CoreGl_load_ARB_shader_storage_buffer_object();
  _CoreGl_mgr.has_ARB_shader_subroutine=CoreGl_load_ARB_shader_subroutine();
  _CoreGl_mgr.has_ARB_shader_texture_image_samples=CoreGl_load_ARB_shader_texture_image_samples();
  _CoreGl_mgr.has_ARB_shading_language_420pack=CoreGl_load_ARB_shading_language_420pack();
  _CoreGl_mgr.has_ARB_shading_language_include=CoreGl_load_ARB_shading_language_include();
  _CoreGl_mgr.has_ARB_shading_language_packing=CoreGl_load_ARB_shading_language_packing();
  _CoreGl_mgr.has_ARB_sparse_buffer=CoreGl_load_ARB_sparse_buffer();
  _CoreGl_mgr.has_ARB_sparse_texture=CoreGl_load_ARB_sparse_texture();
  _CoreGl_mgr.has_ARB_stencil_texturing=CoreGl_load_ARB_stencil_texturing();
  _CoreGl_mgr.has_ARB_sync=CoreGl_load_ARB_sync();
  _CoreGl_mgr.has_ARB_tessellation_shader=CoreGl_load_ARB_tessellation_shader();
  _CoreGl_mgr.has_ARB_texture_barrier=CoreGl_load_ARB_texture_barrier();
  _CoreGl_mgr.has_ARB_texture_buffer_object_rgb32=CoreGl_load_ARB_texture_buffer_object_rgb32();
  _CoreGl_mgr.has_ARB_texture_buffer_range=CoreGl_load_ARB_texture_buffer_range();
  _CoreGl_mgr.has_ARB_texture_compression_bptc=CoreGl_load_ARB_texture_compression_bptc();
  _CoreGl_mgr.has_ARB_texture_compression_rgtc=CoreGl_load_ARB_texture_compression_rgtc();
  _CoreGl_mgr.has_ARB_texture_cube_map_array=CoreGl_load_ARB_texture_cube_map_array();
  _CoreGl_mgr.has_ARB_texture_gather=CoreGl_load_ARB_texture_gather();
  _CoreGl_mgr.has_ARB_texture_mirror_clamp_to_edge=CoreGl_load_ARB_texture_mirror_clamp_to_edge();
  _CoreGl_mgr.has_ARB_texture_multisample=CoreGl_load_ARB_texture_multisample();
  _CoreGl_mgr.has_ARB_texture_query_levels=CoreGl_load_ARB_texture_query_levels();
  _CoreGl_mgr.has_ARB_texture_query_lod=CoreGl_load_ARB_texture_query_lod();
  _CoreGl_mgr.has_ARB_texture_rg=CoreGl_load_ARB_texture_rg();
  _CoreGl_mgr.has_ARB_texture_rgb10_a2ui=CoreGl_load_ARB_texture_rgb10_a2ui();
  _CoreGl_mgr.has_ARB_texture_stencil8=CoreGl_load_ARB_texture_stencil8();
  _CoreGl_mgr.has_ARB_texture_storage=CoreGl_load_ARB_texture_storage();
  _CoreGl_mgr.has_ARB_texture_storage_multisample=CoreGl_load_ARB_texture_storage_multisample();
  _CoreGl_mgr.has_ARB_texture_swizzle=CoreGl_load_ARB_texture_swizzle();
  _CoreGl_mgr.has_ARB_texture_view=CoreGl_load_ARB_texture_view();
  _CoreGl_mgr.has_ARB_timer_query=CoreGl_load_ARB_timer_query();
  _CoreGl_mgr.has_ARB_transform_feedback2=CoreGl_load_ARB_transform_feedback2();
  _CoreGl_mgr.has_ARB_transform_feedback3=CoreGl_load_ARB_transform_feedback3();
  _CoreGl_mgr.has_ARB_transform_feedback_instanced=CoreGl_load_ARB_transform_feedback_instanced();
  _CoreGl_mgr.has_ARB_transform_feedback_overflow_query=CoreGl_load_ARB_transform_feedback_overflow_query();
  _CoreGl_mgr.has_ARB_uniform_buffer_object=CoreGl_load_ARB_uniform_buffer_object();
  _CoreGl_mgr.has_ARB_vertex_array_bgra=CoreGl_load_ARB_vertex_array_bgra();
  _CoreGl_mgr.has_ARB_vertex_array_object=CoreGl_load_ARB_vertex_array_object();
  _CoreGl_mgr.has_ARB_vertex_attrib_64bit=CoreGl_load_ARB_vertex_attrib_64bit();
  _CoreGl_mgr.has_ARB_vertex_attrib_binding=CoreGl_load_ARB_vertex_attrib_binding();
  _CoreGl_mgr.has_ARB_vertex_type_10f_11f_11f_rev=CoreGl_load_ARB_vertex_type_10f_11f_11f_rev();
  _CoreGl_mgr.has_ARB_vertex_type_2_10_10_10_rev=CoreGl_load_ARB_vertex_type_2_10_10_10_rev();
  _CoreGl_mgr.has_ARB_viewport_array=CoreGl_load_ARB_viewport_array();
  _CoreGl_mgr.has_KHR_context_flush_control=CoreGl_load_KHR_context_flush_control();
  _CoreGl_mgr.has_KHR_debug=CoreGl_load_KHR_debug();
  _CoreGl_mgr.has_KHR_no_error=CoreGl_load_KHR_no_error();
  _CoreGl_mgr.has_KHR_robust_buffer_access_behavior=CoreGl_load_KHR_robust_buffer_access_behavior();
  _CoreGl_mgr.has_KHR_robustness=CoreGl_load_KHR_robustness();
  _CoreGl_mgr.has_KHR_texture_compression_astc_hdr=CoreGl_load_KHR_texture_compression_astc_hdr();
  _CoreGl_mgr.has_KHR_texture_compression_astc_ldr=CoreGl_load_KHR_texture_compression_astc_ldr();
  _CoreGl_mgr.has_KHR_texture_compression_astc_sliced_3d=CoreGl_load_KHR_texture_compression_astc_sliced_3d();
  if(glCreateShader&&glDeleteShader)
    {
    int featureTest;
    featureTest=glCreateShader(GL_TESS_CONTROL_SHADER); // may fail
    if(!featureTest) glGetError(); // clear previous error
    else
      {
      _CoreGl_mgr.hasTessControlShaders=true;
      glDeleteShader(featureTest);
      ON_GL_ERROR({ return false; });
      }
    featureTest=glCreateShader(GL_TESS_EVALUATION_SHADER); // may fail
    if(!featureTest) glGetError(); // clear previous error
    else
      {
      _CoreGl_mgr.hasTessEvaluationShaders=true;
      glDeleteShader(featureTest);
      ON_GL_ERROR({ return false; });
      }
    featureTest=glCreateShader(GL_GEOMETRY_SHADER); // may fail
    if(!featureTest) glGetError(); // clear previous error
    else
      {
      _CoreGl_mgr.hasGeometryShaders=true;
      glDeleteShader(featureTest);
      ON_GL_ERROR({ return false; });
      }
    featureTest=glCreateShader(GL_COMPUTE_SHADER); // may fail
    if(!featureTest) glGetError(); // clear previous error
    else
      {
      _CoreGl_mgr.hasComputeShaders=true;
      glDeleteShader(featureTest);
      ON_GL_ERROR({ return false; });
      CoreGlComputeProperties *prop=&_CoreGl_mgr.computeProperties;
      glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT,0,
                      prop->maxWorkGroupCount+0);
      ON_GL_ERROR({ return false; });
      glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT,1,
                      prop->maxWorkGroupCount+1);
      ON_GL_ERROR({ return false; });
      glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT,2,
                      prop->maxWorkGroupCount+2);
      ON_GL_ERROR({ return false; });
      glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE,0,
                      prop->maxWorkGroupSize+0);
      ON_GL_ERROR({ return false; });
      glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE,1,
                      prop->maxWorkGroupSize+1);
      ON_GL_ERROR({ return false; });
      glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE,2,
                      prop->maxWorkGroupSize+2);
      ON_GL_ERROR({ return false; });
      glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS,
                    &prop->maxWorkGroupInvocations);
      ON_GL_ERROR({ return false; });
      glGetIntegerv(GL_MAX_COMPUTE_UNIFORM_BLOCKS,
                    &prop->maxUniformBlocks);
      ON_GL_ERROR({ return false; });
      glGetIntegerv(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS,
                    &prop->maxTextureImageUnits);
      ON_GL_ERROR({ return false; });
      glGetIntegerv(GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS,
                    &prop->maxAtomicCounterBuffers);
      ON_GL_ERROR({ return false; });
      glGetIntegerv(GL_MAX_COMPUTE_ATOMIC_COUNTERS,
                    &prop->maxAtomicCounters);
      ON_GL_ERROR({ return false; });
      glGetIntegerv(GL_MAX_COMPUTE_SHARED_MEMORY_SIZE,
                    &prop->maxSharedMemorySize);
      ON_GL_ERROR({ return false; });
      glGetIntegerv(GL_MAX_COMPUTE_UNIFORM_COMPONENTS,
                    &prop->maxUniformComponents);
      ON_GL_ERROR({ return false; });
      glGetIntegerv(GL_MAX_COMPUTE_IMAGE_UNIFORMS,
                    &prop->maxImageUniforms);
      ON_GL_ERROR({ return false; });
      glGetIntegerv(GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS,
                    &prop->maxCombinedUniformComponents);
      ON_GL_ERROR({ return false; });
      glGetIntegerv(GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS,
                    &prop->maxShaderStorageBlocks);
      ON_GL_ERROR({ return false; });
      bool useWarpInfo=false;
      prop->hasBallot=CoreGl_hasExtension("GL_NV_shader_thread_group");
      if(prop->hasBallot)
        {
        glGetIntegerv(0x9339, // WARP_SIZE_NV
                      &prop->warpSize);
        ON_GL_ERROR({ return false; });
        glGetIntegerv(0x933A, // WARPS_PER_SM_NV
                      &prop->warpsPerStreamingMultiprocessor);
        ON_GL_ERROR({ return false; });
        glGetIntegerv(0x933B, // SM_COUNT_NV
                      &prop->streamingMultiprocessorCount);
        ON_GL_ERROR({ return false; });
        prop->hasShuffle=CoreGl_hasExtension("GL_NV_shader_thread_shuffle");
        if((prop->warpSize>=2)&&
           !(prop->warpSize&(prop->warpSize-1)))
          {
          useWarpInfo=true; // ensure warpSize is a power of 2
          }
        }
      if(!useWarpInfo)
        {
        prop->warpSize=1;
        const char *vendor=(const char *)glGetString(GL_VENDOR);
        if(!vendor) glGetError(); // clear previous error
        else // try to guess warp size from the vendor
          {
          // FIXME: these values might change one day or another...
          if(strstr(vendor,"NVIDIA"))
            {
            prop->warpSize=32;
            }
          else if(strstr(vendor,"ATI"))
            {
            prop->warpSize=64;
            }
          }
        prop->warpsPerStreamingMultiprocessor=1;
        prop->streamingMultiprocessorCount=1;
        prop->hasBallot=false;
        prop->hasShuffle=false;
        }
      }
    }
  _CoreGl_mgr.initDone=true;
  }
return true;
}

bool // success
CoreGl_hasExtension(const char *extensionName)
{
int count;
const char * const *ext=CoreGl_extensions(&count);
for(int i=0;i<count;++i)
  {
  if(!strcmp(ext[i],extensionName))
    {
    return true;
    }
  }
return false;
}

void * // symbol or 0
CoreGl_extensionSymbol(const char *symbolName)
{
void *symbol=(void *)0;
#if defined _WIN32
  PROC procAddr=wglGetProcAddress(symbolName);
  memcpy(&symbol,&procAddr,sizeof(void *));
#elif defined __APPLE__
  // FIXME: no ???GetProcAddress() utility
#elif defined __ANDROID__
  // FIXME: eglGetProcAddress() only works for extension functions
  // void (*procAddr)(void)=eglGetProcAddress(symbolName);
  // memcpy(&symbol,&procAddr,sizeof(void *));
#else
  void (*procAddr)(void)=glXGetProcAddress((const GLubyte *)symbolName);
  memcpy(&symbol,&procAddr,sizeof(void *));
#endif
if(!symbol) // not found with a specific utility... may be the application
  {         // is linked against GL...
  static void *currentBinary=(void *)0;
  if(!currentBinary)
    {
#if defined _WIN32
    currentBinary=(void *)GetModuleHandle((LPCTSTR)0);
#else
    currentBinary=dlopen((const char *)0,RTLD_LAZY);
#endif
    }
  if(currentBinary)
    {
#if defined _WIN32
    FARPROC procAddr=GetProcAddress((HMODULE)currentBinary,symbolName);
    memcpy(&symbol,&procAddr,sizeof(void *));
#else
    symbol=dlsym(currentBinary,symbolName);
#endif
    }
  }
if(!symbol) // not found in the current binary... may be the application
  {         // is a dynamic library which is linked against GL...
  static void *glLibrary=(void *)0;
  if(!glLibrary)
    {
#if defined _WIN32
    glLibrary=(void *)LoadLibrary(GL_LIBRARY_NAME);
#else
    glLibrary=dlopen(GL_LIBRARY_NAME,RTLD_LAZY);
#endif
    }
  if(glLibrary)
    {
#if defined _WIN32
    FARPROC procAddr=GetProcAddress((HMODULE)glLibrary,symbolName);
    memcpy(&symbol,&procAddr,sizeof(void *));
#else
    symbol=dlsym(glLibrary,symbolName);
#endif
    }
  }
return symbol;
}

void * // symbol or 0
CoreGl_extensionSymbolWithSuffix(const char *symbolName,
                                 const char * const *suffixList)
{
for(int i=0;suffixList[i];++i)
  {
  char fullName[0x100];
  snprintf(fullName,0x100,"%s%s",symbolName,suffixList[i]);
  fullName[0xFF]='\0';
  void *symbol=CoreGl_extensionSymbol(fullName);
  if(symbol)
    {
    return symbol;
    }
  }
return (void *)0;
}

const char * // last OpenGL error message if any
CoreGl_lastError(void)
{
int err=glGetError();
switch(err)
  {
  case GL_NO_ERROR:
    {
    return (const char *)0;
    }
  case GL_INVALID_ENUM:
    {
    return "GL_INVALID_ENUM";
    }
  case GL_INVALID_VALUE:
    {
    return "GL_INVALID_VALUE";
    }
  case GL_INVALID_OPERATION:
    {
    return "GL_INVALID_OPERATION";
    }
  case GL_STACK_OVERFLOW:
    {
    return "GL_STACK_OVERFLOW";
    }
  case GL_STACK_UNDERFLOW:
    {
    return "GL_STACK_UNDERFLOW";
    }
  case GL_OUT_OF_MEMORY:
    {
    return "GL_OUT_OF_MEMORY";
    }
  case GL_INVALID_FRAMEBUFFER_OPERATION:
    {
    return "GL_INVALID_FRAMEBUFFER_OPERATION";
    }
  default:
    {
    static char buffer[0x20];
    sprintf(buffer,"unknown OpenGL error 0x%.4X",err);
    return buffer;
    }
  }
}

char * // allocated compilation/link error/warning message if any
CoreGl_shaderStatus(GLuint shader,
                    bool *out_error)
{
bool isProgram;
GLint status=GL_FALSE;
GLint len=0;
if(glIsProgram(shader))
  {
  isProgram=true;
  glGetProgramiv(shader,GL_LINK_STATUS,&status);
  ON_GL_ERROR({});
  glGetProgramiv(shader,GL_INFO_LOG_LENGTH,&len);
  ON_GL_ERROR({});
  }
else
  {
  isProgram=false;
  glGetShaderiv(shader,GL_COMPILE_STATUS,&status);
  ON_GL_ERROR({});
  glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&len);
  ON_GL_ERROR({});
  }
char *log=(char *)0;
*out_error=!status;
if(len>1)
  {
  log=Memory_initAlloc(len,char);
  GLint realLen=0;
  if(isProgram)
    {
    glGetProgramInfoLog(shader,len,&realLen,log);
    ON_GL_ERROR({ Memory_free(log); log=(char *)0; });
    }
  else
    {
    glGetShaderInfoLog(shader,len,&realLen,log);
    ON_GL_ERROR({ Memory_free(log); log=(char *)0; });
    }
  if(log)
    {
    int start=0;
    // sometimes the log just contains one of these useless information lines
    if(!start)
      {
      sscanf(log," %*d lines, 0 errors.%n",&start);
      }
    if(!start)
      {
      sscanf(log," Compiled%n",&start);
      }
    if(!start)
      {
      sscanf(log," --From Vertex Shader:"
                 " --From Fragment Shader:"
                 " Link was successful.%n",&start);
      }
    if(!start)
      {
      sscanf(log," %*s shader was successfully"
                 " compiled to run on hardware.%n",&start);
      }
    if(!start)
      {
      sscanf(log," Vertex shader(s) linked,"
                 " fragment shader(s) linked.%n",&start);
      }
    bool empty=true;
    for(int i=start;(i<len)&&log[i];++i)
      {
      if(!isspace(log[i]))
        {
        empty=false;
        break;
        }
      }
    if(empty)
      {
      Memory_free(log);
      log=(char *)0;
      }
    }
  }
if(!status&&!log)
  {
  log=Memory_alloc(64,char);
  if(isProgram)
    {
    sprintf(log,"shader program link failure\n");
    }
  else
    {
    sprintf(log,"shader compilation failure\n");
    }
  }
return log;
}

GLuint // compiled shader-object or 0
CoreGl_compileShader(GLenum shaderKind,
                     const char *sourceCode,
                     bool addPreamble,
                     char **out_allocatedCompilationLog)
{
*out_allocatedCompilationLog=(char *)0;
const char *esStr=CoreGl_embedded()&&(CoreGl_shadingLanguageVersion()>=300)
                  ? " es" : "";
char glslVersionStr[64];
sprintf(glslVersionStr," #version %d%s \n",
                       CoreGl_shadingLanguageVersion(),
                       esStr);
const char *preamble=""; // compose preamble to ease portability
const char *shaderKindStr="???";
switch(shaderKind)
  {
  case GL_VERTEX_SHADER:
    {
    shaderKindStr="VERTEX";
    preamble=" #if __VERSION__<130                                        \n"
             " # define in attribute                                      \n"
             " # define out varying                                       \n"
             " # define smooth                                            \n"
             " # define flat                                              \n"
             " # define noperspective                                     \n"
             " #endif                                                     \n";
    break;
    }
  case GL_GEOMETRY_SHADER:
    {
    shaderKindStr="GEOMETRY";
    preamble=" #if __VERSION__<130                                        \n"
             " # define in varying in                                     \n"
             " # define out varying out                                   \n"
             " # define smooth                                            \n"
             " # define flat                                              \n"
             " # define noperspective                                     \n"
             " #endif                                                     \n"
             " #if __VERSION__>=150                                       \n"
             " # define gl_PosIn(i) (gl_in[i].gl_Position)                \n"
             " #else                                                      \n"
             " # extension GL_EXT_geometry_shader4 : enable               \n"
             " # define gl_PosIn(i) (gl_PositionIn[i])                    \n"
             " #endif                                                     \n";
    break;
    }
  case GL_FRAGMENT_SHADER:
    {
    shaderKindStr="FRAGMENT";
    preamble=" #if defined GL_ES                                          \n"
             " # if defined GL_FRAGMENT_PRECISION_HIGH                    \n"
             "     precision highp float;                                 \n"
             " # else                                                     \n"
             "     precision mediump float;                               \n"
             " # endif                                                    \n"
             " #endif                                                     \n"
             " #if __VERSION__<130                                        \n"
             " # define in varying                                        \n"
             " # define smooth                                            \n"
             " # define flat                                              \n"
             " # define noperspective                                     \n"
             " #else                                                      \n"
             " # define texture2D texture                                 \n"
             " # define shadow2D texture                                  \n"
             " # define texture3D texture                                 \n"
             " # define textureCube texture                               \n"
             " # if __VERSION__>=330                                      \n"
             "     layout(location=0)                                     \n"
             " # endif                                                    \n"
             "   out vec4 defaultFragColour;                              \n"
             " # define gl_FragColor defaultFragColour                    \n"
             " #endif                                                     \n";
    break;
    }
  case GL_TESS_EVALUATION_SHADER:
    {
    shaderKindStr="TESS_EVALUATION";
    break;
    }
  case GL_TESS_CONTROL_SHADER:
    {
    shaderKindStr="TESS_CONTROL";
    break;
    }
  case GL_COMPUTE_SHADER:
    {
    shaderKindStr="COMPUTE";
    break;
    }
  }
GLuint shader=glCreateShader(shaderKind);
ON_GL_ERROR({ return 0; });
const char *strings[3]={ glslVersionStr, preamble, sourceCode };
if(!addPreamble)
  {
  strings[0]="";
  strings[1]="";
  }
glShaderSource(shader,3,strings,NULL);
ON_GL_ERROR({ glDeleteShader(shader); return 0; });
glCompileShader(shader);
ON_GL_ERROR({ glDeleteShader(shader); return 0; });
bool compilationError;
char *log=CoreGl_shaderStatus(shader,&compilationError);
if(log)
  {
  int srcCharCount=0,srcLineCount=1;
  for(int s=0;s<3;++s)
    {
    const char *src=strings[s];
    for(int i=0;src[i];++i)
      {
      ++srcCharCount;
      if(src[i]=='\n')
        {
        ++srcLineCount;
        }
      }
    }
  int lineCountWidth=1;
  int lineCountMax=10;
  while(lineCountMax<=srcLineCount)
    {
    ++lineCountWidth;
    lineCountMax*=10;
    }
  char *newLog=Memory_alloc(srcCharCount+srcLineCount*(lineCountWidth+1)+
                            strlen(log)+0x100,char);
  int pos=sprintf(newLog,"%s SHADER SOURCE:\n",shaderKindStr);
  srcLineCount=1;
  bool newLine=true;
  for(int s=0;s<3;++s)
    {
    const char *src=strings[s];
    for(int i=0;src[i];++i)
      {
      if(newLine)
        {
        newLine=false;
#if 0
        pos+=sprintf(newLog+pos,"%*d:",lineCountWidth,srcLineCount);
#else // workaround invalid warning with %* (gcc>=7)
        char linePadding[]="          ";
        char lineTag[11];
        int tagLen=sprintf(lineTag,"%d",srcLineCount);
        strcpy(linePadding+(lineCountWidth-tagLen),lineTag);
        pos+=sprintf(newLog+pos,"%s:",linePadding);
#endif
        }
      newLog[pos++]=src[i];
      if(src[i]=='\n')
        {
        ++srcLineCount;
        newLine=true;
        }
      }
    }
  if(!newLine)
    {
    newLog[pos++]='\n';
    }
  sprintf(newLog+pos,"%s SHADER LOG:\n%s\n",shaderKindStr,log);
  Memory_free(log);
  *out_allocatedCompilationLog=newLog;
  }
if(compilationError)
  {
  glDeleteShader(shader);
  ON_GL_ERROR({});
  return 0;
  }
return shader; // sucessfully compiled shader-object
}

GLuint // linked shader-program or 0
CoreGl_buildRenderShader(const char *vertexSrc,
                         const char *geometrySrc,
                         const char *fragmentSrc,
                         bool addPreamble,
                         char **out_allocatedBuildLog)
{
*out_allocatedBuildLog=(char *)0;
const char *sources[3]={ vertexSrc, geometrySrc, fragmentSrc };
GLenum kinds[3]={ GL_VERTEX_SHADER, GL_GEOMETRY_SHADER, GL_FRAGMENT_SHADER };
GLuint shaders[3]={ 0, 0, 0 };
bool tryToLink=true;
GLuint program=glCreateProgram();
ON_ERROR(!program,"glCreateProgram() failure", { goto undo; });
for(int i=0;i<3;++i)
  {
  if(sources[i]&&*sources[i])
    {
    char *log=(char *)0;
    shaders[i]=CoreGl_compileShader(kinds[i],sources[i],addPreamble,&log);
    if(log)
      {
      if(*out_allocatedBuildLog)
        {
        char *oldLog=*out_allocatedBuildLog;
        *out_allocatedBuildLog=Memory_alloc(strlen(oldLog)+strlen(log)+1,
                                            char);
        sprintf(*out_allocatedBuildLog,"%s%s",oldLog,log);
        Memory_free(oldLog);
        }
      else
        {
        *out_allocatedBuildLog=log;
        }
      }
    if(shaders[i])
      {
      glAttachShader(program,shaders[i]);
      ON_GL_ERROR({ goto undo; });
      if((kinds[i]==GL_GEOMETRY_SHADER)&&
         (CoreGl_shadingLanguageVersion()<150))
        {
        // ugly workaround: parse source to detect layout parameters
        int inputType=-1;
        int outputType=-1;
        int verticesOut=-1;
        char line[0x400];
        const char *begin=sources[i];
        const char *end=begin+strlen(begin);
        while(begin<end)
          {
          const char *cr=strchr(begin,'\n');
          if(!cr) cr=end;
          int len=(int)(cr-begin);
          memcpy(line,begin,len);
          line[len]='\0';
          char txt[0x100];
          int value;
          int charCount=0;
          if((sscanf(line," layout ( %[^)] ) in ; %n",
                     txt,&charCount)==1)&&charCount)
            {
            if(!strcmp(txt,"points"))
              {
              inputType=GL_POINTS;
              }
            else if(!strcmp(txt,"lines"))
              {
              inputType=GL_LINES;
              }
            else if(!strcmp(txt,"lines_adjacency"))
              {
              inputType=GL_LINES_ADJACENCY;
              }
            else if(!strcmp(txt,"triangles"))
              {
              inputType=GL_TRIANGLES;
              }
            else if(!strcmp(txt,"triangles_adjacency"))
              {
              inputType=GL_TRIANGLES_ADJACENCY;
              }
            }
          charCount=0;
          if((sscanf(line," layout ( %[^),] , max_vertices = %d ) out ; %n",
                     txt,&value,&charCount)==2)&&charCount)
            {
            if(!strcmp(txt,"points"))
              {
              outputType=GL_POINTS;
              }
            else if(!strcmp(txt,"line_strip"))
              {
              outputType=GL_LINE_STRIP;
              }
            else if(!strcmp(txt,"triangle_strip"))
              {
              outputType=GL_TRIANGLE_STRIP;
              }
            verticesOut=value;
            }
          begin=cr+1;
          }
        // use GL_EXT_geometry_shader4 layout parameters
        if(inputType>=0)
          {
          glProgramParameteri(program,
                              0x8DDB, // GL_GEOMETRY_INPUT_TYPE_EXT
                              inputType);
          ON_GL_ERROR({});
          }
        if(outputType>=0)
          {
          glProgramParameteri(program,
                              0x8DDC, // GL_GEOMETRY_OUTPUT_TYPE_EXT
                              outputType);
          ON_GL_ERROR({});
          }
        if(verticesOut>0)
          {
          glProgramParameteri(program,
                              0x8DDA, // GL_GEOMETRY_VERTICES_OUT_EXT
                              verticesOut);
          ON_GL_ERROR({});
          }
        }
      }
    else
      {
      tryToLink=false;
      }
    }
  }
if(tryToLink)
  {
  glLinkProgram(program);
  ON_GL_ERROR({ goto undo; });
  bool linkError;
  char *log=CoreGl_shaderStatus(program,&linkError);
  if(log)
    {
    if(*out_allocatedBuildLog)
      {
      char *oldLog=*out_allocatedBuildLog;
      *out_allocatedBuildLog=Memory_alloc(strlen(oldLog)+strlen(log)+0x100,
                                          char);
      sprintf(*out_allocatedBuildLog,"%sSHADER PROGRAM LOG:\n%s\n",
                                     oldLog,log);
      Memory_free(oldLog);
      }
    else
      {
      *out_allocatedBuildLog=Memory_alloc(strlen(log)+0x100,char);
      sprintf(*out_allocatedBuildLog,"SHADER PROGRAM LOG:\n%s\n",log);
      }
    Memory_free(log);
    }
  if(linkError)
    {
    goto undo;
    }
  for(int i=0;i<3;++i)
    {
    if(shaders[i])
      {
      glDeleteShader(shaders[i]); // still referenced by program
      ON_GL_ERROR({});
      }
    }
  return program; // sucessfully built shader-program
  }
undo:
if(program)
  {
  glDeleteProgram(program);
  ON_GL_ERROR({});
  }
for(int i=0;i<3;++i)
  {
  if(shaders[i])
    {
    glDeleteShader(shaders[i]);
    ON_GL_ERROR({});
    }
  }
return 0;
}

GLuint // linked shader-program or 0
CoreGl_buildComputeShader(const char *computeSrc,
                          bool addPreamble,
                          char **out_allocatedBuildLog)
{
*out_allocatedBuildLog=(char *)0;
GLuint shader=0;
GLuint program=glCreateProgram();
bool linkError=false;
char *log=(char *)0;
ON_ERROR(!program,"glCreateProgram() failure", { goto undo; });
shader=CoreGl_compileShader(GL_COMPUTE_SHADER,computeSrc,addPreamble,
                            out_allocatedBuildLog);
if(!shader) { goto undo; }
glAttachShader(program,shader);
ON_GL_ERROR({ goto undo; });
glLinkProgram(program);
ON_GL_ERROR({ goto undo; });
log=CoreGl_shaderStatus(program,&linkError);
if(log)
  {
  if(*out_allocatedBuildLog)
    {
    char *oldLog=*out_allocatedBuildLog;
    *out_allocatedBuildLog=Memory_alloc(strlen(oldLog)+strlen(log)+0x100,
                                        char);
    sprintf(*out_allocatedBuildLog,"%sSHADER PROGRAM LOG:\n%s\n",
                                   oldLog,log);
    Memory_free(oldLog);
    }
  else
    {
    *out_allocatedBuildLog=Memory_alloc(strlen(log)+0x100,char);
    sprintf(*out_allocatedBuildLog,"SHADER PROGRAM LOG:\n%s\n",log);
    }
  Memory_free(log);
  }
if(linkError)
  {
  goto undo;
  }
glDeleteShader(shader); // still referenced by program
ON_GL_ERROR({});
return program; // sucessfully built shader-program
undo:
if(program)
  {
  glDeleteProgram(program);
  ON_GL_ERROR({});
  }
if(shader)
  {
  glDeleteShader(shader);
  ON_GL_ERROR({});
  }
return 0;
}

//---- VERSION_1_0 ----

TRANSGL_API_VAR
PFNGLCULLFACEPROC
CoreGl_CullFace;

TRANSGL_API_VAR
PFNGLFRONTFACEPROC
CoreGl_FrontFace;

TRANSGL_API_VAR
PFNGLHINTPROC
CoreGl_Hint;

TRANSGL_API_VAR
PFNGLLINEWIDTHPROC
CoreGl_LineWidth;

TRANSGL_API_VAR
PFNGLPOINTSIZEPROC
CoreGl_PointSize;

TRANSGL_API_VAR
PFNGLPOLYGONMODEPROC
CoreGl_PolygonMode;

TRANSGL_API_VAR
PFNGLSCISSORPROC
CoreGl_Scissor;

TRANSGL_API_VAR
PFNGLTEXPARAMETERFPROC
CoreGl_TexParameterf;

TRANSGL_API_VAR
PFNGLTEXPARAMETERFVPROC
CoreGl_TexParameterfv;

TRANSGL_API_VAR
PFNGLTEXPARAMETERIPROC
CoreGl_TexParameteri;

TRANSGL_API_VAR
PFNGLTEXPARAMETERIVPROC
CoreGl_TexParameteriv;

TRANSGL_API_VAR
PFNGLTEXIMAGE1DPROC
CoreGl_TexImage1D;

TRANSGL_API_VAR
PFNGLTEXIMAGE2DPROC
CoreGl_TexImage2D;

TRANSGL_API_VAR
PFNGLDRAWBUFFERPROC
CoreGl_DrawBuffer;

TRANSGL_API_VAR
PFNGLCLEARPROC
CoreGl_Clear;

TRANSGL_API_VAR
PFNGLCLEARCOLORPROC
CoreGl_ClearColor;

TRANSGL_API_VAR
PFNGLCLEARSTENCILPROC
CoreGl_ClearStencil;

TRANSGL_API_VAR
PFNGLCLEARDEPTHPROC
CoreGl_ClearDepth;

TRANSGL_API_VAR
PFNGLSTENCILMASKPROC
CoreGl_StencilMask;

TRANSGL_API_VAR
PFNGLCOLORMASKPROC
CoreGl_ColorMask;

TRANSGL_API_VAR
PFNGLDEPTHMASKPROC
CoreGl_DepthMask;

TRANSGL_API_VAR
PFNGLDISABLEPROC
CoreGl_Disable;

TRANSGL_API_VAR
PFNGLENABLEPROC
CoreGl_Enable;

TRANSGL_API_VAR
PFNGLFINISHPROC
CoreGl_Finish;

TRANSGL_API_VAR
PFNGLFLUSHPROC
CoreGl_Flush;

TRANSGL_API_VAR
PFNGLBLENDFUNCPROC
CoreGl_BlendFunc;

TRANSGL_API_VAR
PFNGLLOGICOPPROC
CoreGl_LogicOp;

TRANSGL_API_VAR
PFNGLSTENCILFUNCPROC
CoreGl_StencilFunc;

TRANSGL_API_VAR
PFNGLSTENCILOPPROC
CoreGl_StencilOp;

TRANSGL_API_VAR
PFNGLDEPTHFUNCPROC
CoreGl_DepthFunc;

TRANSGL_API_VAR
PFNGLPIXELSTOREFPROC
CoreGl_PixelStoref;

TRANSGL_API_VAR
PFNGLPIXELSTOREIPROC
CoreGl_PixelStorei;

TRANSGL_API_VAR
PFNGLREADBUFFERPROC
CoreGl_ReadBuffer;

TRANSGL_API_VAR
PFNGLREADPIXELSPROC
CoreGl_ReadPixels;

TRANSGL_API_VAR
PFNGLGETBOOLEANVPROC
CoreGl_GetBooleanv;

TRANSGL_API_VAR
PFNGLGETDOUBLEVPROC
CoreGl_GetDoublev;

TRANSGL_API_VAR
PFNGLGETERRORPROC
CoreGl_GetError;

TRANSGL_API_VAR
PFNGLGETFLOATVPROC
CoreGl_GetFloatv;

TRANSGL_API_VAR
PFNGLGETINTEGERVPROC
CoreGl_GetIntegerv;

TRANSGL_API_VAR
PFNGLGETSTRINGPROC
CoreGl_GetString;

TRANSGL_API_VAR
PFNGLGETTEXIMAGEPROC
CoreGl_GetTexImage;

TRANSGL_API_VAR
PFNGLGETTEXPARAMETERFVPROC
CoreGl_GetTexParameterfv;

TRANSGL_API_VAR
PFNGLGETTEXPARAMETERIVPROC
CoreGl_GetTexParameteriv;

TRANSGL_API_VAR
PFNGLGETTEXLEVELPARAMETERFVPROC
CoreGl_GetTexLevelParameterfv;

TRANSGL_API_VAR
PFNGLGETTEXLEVELPARAMETERIVPROC
CoreGl_GetTexLevelParameteriv;

TRANSGL_API_VAR
PFNGLISENABLEDPROC
CoreGl_IsEnabled;

TRANSGL_API_VAR
PFNGLDEPTHRANGEPROC
CoreGl_DepthRange;

TRANSGL_API_VAR
PFNGLVIEWPORTPROC
CoreGl_Viewport;

//---- VERSION_1_1 ----

TRANSGL_API_VAR
PFNGLDRAWARRAYSPROC
CoreGl_DrawArrays;

TRANSGL_API_VAR
PFNGLDRAWELEMENTSPROC
CoreGl_DrawElements;

TRANSGL_API_VAR
PFNGLGETPOINTERVPROC
CoreGl_GetPointerv;

TRANSGL_API_VAR
PFNGLPOLYGONOFFSETPROC
CoreGl_PolygonOffset;

TRANSGL_API_VAR
PFNGLCOPYTEXIMAGE1DPROC
CoreGl_CopyTexImage1D;

TRANSGL_API_VAR
PFNGLCOPYTEXIMAGE2DPROC
CoreGl_CopyTexImage2D;

TRANSGL_API_VAR
PFNGLCOPYTEXSUBIMAGE1DPROC
CoreGl_CopyTexSubImage1D;

TRANSGL_API_VAR
PFNGLCOPYTEXSUBIMAGE2DPROC
CoreGl_CopyTexSubImage2D;

TRANSGL_API_VAR
PFNGLTEXSUBIMAGE1DPROC
CoreGl_TexSubImage1D;

TRANSGL_API_VAR
PFNGLTEXSUBIMAGE2DPROC
CoreGl_TexSubImage2D;

TRANSGL_API_VAR
PFNGLBINDTEXTUREPROC
CoreGl_BindTexture;

TRANSGL_API_VAR
PFNGLDELETETEXTURESPROC
CoreGl_DeleteTextures;

TRANSGL_API_VAR
PFNGLGENTEXTURESPROC
CoreGl_GenTextures;

TRANSGL_API_VAR
PFNGLISTEXTUREPROC
CoreGl_IsTexture;

//---- VERSION_1_2 ----

TRANSGL_API_VAR
PFNGLDRAWRANGEELEMENTSPROC
CoreGl_DrawRangeElements;

TRANSGL_API_VAR
PFNGLTEXIMAGE3DPROC
CoreGl_TexImage3D;

TRANSGL_API_VAR
PFNGLTEXSUBIMAGE3DPROC
CoreGl_TexSubImage3D;

TRANSGL_API_VAR
PFNGLCOPYTEXSUBIMAGE3DPROC
CoreGl_CopyTexSubImage3D;

//---- VERSION_1_3 ----

TRANSGL_API_VAR
PFNGLACTIVETEXTUREPROC
CoreGl_ActiveTexture;

TRANSGL_API_VAR
PFNGLSAMPLECOVERAGEPROC
CoreGl_SampleCoverage;

TRANSGL_API_VAR
PFNGLCOMPRESSEDTEXIMAGE3DPROC
CoreGl_CompressedTexImage3D;

TRANSGL_API_VAR
PFNGLCOMPRESSEDTEXIMAGE2DPROC
CoreGl_CompressedTexImage2D;

TRANSGL_API_VAR
PFNGLCOMPRESSEDTEXIMAGE1DPROC
CoreGl_CompressedTexImage1D;

TRANSGL_API_VAR
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC
CoreGl_CompressedTexSubImage3D;

TRANSGL_API_VAR
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC
CoreGl_CompressedTexSubImage2D;

TRANSGL_API_VAR
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC
CoreGl_CompressedTexSubImage1D;

TRANSGL_API_VAR
PFNGLGETCOMPRESSEDTEXIMAGEPROC
CoreGl_GetCompressedTexImage;

//---- VERSION_1_4 ----

TRANSGL_API_VAR
PFNGLBLENDFUNCSEPARATEPROC
CoreGl_BlendFuncSeparate;

TRANSGL_API_VAR
PFNGLMULTIDRAWARRAYSPROC
CoreGl_MultiDrawArrays;

TRANSGL_API_VAR
PFNGLMULTIDRAWELEMENTSPROC
CoreGl_MultiDrawElements;

TRANSGL_API_VAR
PFNGLPOINTPARAMETERFPROC
CoreGl_PointParameterf;

TRANSGL_API_VAR
PFNGLPOINTPARAMETERFVPROC
CoreGl_PointParameterfv;

TRANSGL_API_VAR
PFNGLPOINTPARAMETERIPROC
CoreGl_PointParameteri;

TRANSGL_API_VAR
PFNGLPOINTPARAMETERIVPROC
CoreGl_PointParameteriv;

TRANSGL_API_VAR
PFNGLBLENDCOLORPROC
CoreGl_BlendColor;

TRANSGL_API_VAR
PFNGLBLENDEQUATIONPROC
CoreGl_BlendEquation;

//---- VERSION_1_5 ----

TRANSGL_API_VAR
PFNGLGENQUERIESPROC
CoreGl_GenQueries;

TRANSGL_API_VAR
PFNGLDELETEQUERIESPROC
CoreGl_DeleteQueries;

TRANSGL_API_VAR
PFNGLISQUERYPROC
CoreGl_IsQuery;

TRANSGL_API_VAR
PFNGLBEGINQUERYPROC
CoreGl_BeginQuery;

TRANSGL_API_VAR
PFNGLENDQUERYPROC
CoreGl_EndQuery;

TRANSGL_API_VAR
PFNGLGETQUERYIVPROC
CoreGl_GetQueryiv;

TRANSGL_API_VAR
PFNGLGETQUERYOBJECTIVPROC
CoreGl_GetQueryObjectiv;

TRANSGL_API_VAR
PFNGLGETQUERYOBJECTUIVPROC
CoreGl_GetQueryObjectuiv;

TRANSGL_API_VAR
PFNGLBINDBUFFERPROC
CoreGl_BindBuffer;

TRANSGL_API_VAR
PFNGLDELETEBUFFERSPROC
CoreGl_DeleteBuffers;

TRANSGL_API_VAR
PFNGLGENBUFFERSPROC
CoreGl_GenBuffers;

TRANSGL_API_VAR
PFNGLISBUFFERPROC
CoreGl_IsBuffer;

TRANSGL_API_VAR
PFNGLBUFFERDATAPROC
CoreGl_BufferData;

TRANSGL_API_VAR
PFNGLBUFFERSUBDATAPROC
CoreGl_BufferSubData;

TRANSGL_API_VAR
PFNGLGETBUFFERSUBDATAPROC
CoreGl_GetBufferSubData;

TRANSGL_API_VAR
PFNGLMAPBUFFERPROC
CoreGl_MapBuffer;

TRANSGL_API_VAR
PFNGLUNMAPBUFFERPROC
CoreGl_UnmapBuffer;

TRANSGL_API_VAR
PFNGLGETBUFFERPARAMETERIVPROC
CoreGl_GetBufferParameteriv;

TRANSGL_API_VAR
PFNGLGETBUFFERPOINTERVPROC
CoreGl_GetBufferPointerv;

//---- VERSION_2_0 ----

TRANSGL_API_VAR
PFNGLBLENDEQUATIONSEPARATEPROC
CoreGl_BlendEquationSeparate;

TRANSGL_API_VAR
PFNGLDRAWBUFFERSPROC
CoreGl_DrawBuffers;

TRANSGL_API_VAR
PFNGLSTENCILOPSEPARATEPROC
CoreGl_StencilOpSeparate;

TRANSGL_API_VAR
PFNGLSTENCILFUNCSEPARATEPROC
CoreGl_StencilFuncSeparate;

TRANSGL_API_VAR
PFNGLSTENCILMASKSEPARATEPROC
CoreGl_StencilMaskSeparate;

TRANSGL_API_VAR
PFNGLATTACHSHADERPROC
CoreGl_AttachShader;

TRANSGL_API_VAR
PFNGLBINDATTRIBLOCATIONPROC
CoreGl_BindAttribLocation;

TRANSGL_API_VAR
PFNGLCOMPILESHADERPROC
CoreGl_CompileShader;

TRANSGL_API_VAR
PFNGLCREATEPROGRAMPROC
CoreGl_CreateProgram;

TRANSGL_API_VAR
PFNGLCREATESHADERPROC
CoreGl_CreateShader;

TRANSGL_API_VAR
PFNGLDELETEPROGRAMPROC
CoreGl_DeleteProgram;

TRANSGL_API_VAR
PFNGLDELETESHADERPROC
CoreGl_DeleteShader;

TRANSGL_API_VAR
PFNGLDETACHSHADERPROC
CoreGl_DetachShader;

TRANSGL_API_VAR
PFNGLDISABLEVERTEXATTRIBARRAYPROC
CoreGl_DisableVertexAttribArray;

TRANSGL_API_VAR
PFNGLENABLEVERTEXATTRIBARRAYPROC
CoreGl_EnableVertexAttribArray;

TRANSGL_API_VAR
PFNGLGETACTIVEATTRIBPROC
CoreGl_GetActiveAttrib;

TRANSGL_API_VAR
PFNGLGETACTIVEUNIFORMPROC
CoreGl_GetActiveUniform;

TRANSGL_API_VAR
PFNGLGETATTACHEDSHADERSPROC
CoreGl_GetAttachedShaders;

TRANSGL_API_VAR
PFNGLGETATTRIBLOCATIONPROC
CoreGl_GetAttribLocation;

TRANSGL_API_VAR
PFNGLGETPROGRAMIVPROC
CoreGl_GetProgramiv;

TRANSGL_API_VAR
PFNGLGETPROGRAMINFOLOGPROC
CoreGl_GetProgramInfoLog;

TRANSGL_API_VAR
PFNGLGETSHADERIVPROC
CoreGl_GetShaderiv;

TRANSGL_API_VAR
PFNGLGETSHADERINFOLOGPROC
CoreGl_GetShaderInfoLog;

TRANSGL_API_VAR
PFNGLGETSHADERSOURCEPROC
CoreGl_GetShaderSource;

TRANSGL_API_VAR
PFNGLGETUNIFORMLOCATIONPROC
CoreGl_GetUniformLocation;

TRANSGL_API_VAR
PFNGLGETUNIFORMFVPROC
CoreGl_GetUniformfv;

TRANSGL_API_VAR
PFNGLGETUNIFORMIVPROC
CoreGl_GetUniformiv;

TRANSGL_API_VAR
PFNGLGETVERTEXATTRIBDVPROC
CoreGl_GetVertexAttribdv;

TRANSGL_API_VAR
PFNGLGETVERTEXATTRIBFVPROC
CoreGl_GetVertexAttribfv;

TRANSGL_API_VAR
PFNGLGETVERTEXATTRIBIVPROC
CoreGl_GetVertexAttribiv;

TRANSGL_API_VAR
PFNGLGETVERTEXATTRIBPOINTERVPROC
CoreGl_GetVertexAttribPointerv;

TRANSGL_API_VAR
PFNGLISPROGRAMPROC
CoreGl_IsProgram;

TRANSGL_API_VAR
PFNGLISSHADERPROC
CoreGl_IsShader;

TRANSGL_API_VAR
PFNGLLINKPROGRAMPROC
CoreGl_LinkProgram;

TRANSGL_API_VAR
PFNGLSHADERSOURCEPROC
CoreGl_ShaderSource;

TRANSGL_API_VAR
PFNGLUSEPROGRAMPROC
CoreGl_UseProgram;

TRANSGL_API_VAR
PFNGLUNIFORM1FPROC
CoreGl_Uniform1f;

TRANSGL_API_VAR
PFNGLUNIFORM2FPROC
CoreGl_Uniform2f;

TRANSGL_API_VAR
PFNGLUNIFORM3FPROC
CoreGl_Uniform3f;

TRANSGL_API_VAR
PFNGLUNIFORM4FPROC
CoreGl_Uniform4f;

TRANSGL_API_VAR
PFNGLUNIFORM1IPROC
CoreGl_Uniform1i;

TRANSGL_API_VAR
PFNGLUNIFORM2IPROC
CoreGl_Uniform2i;

TRANSGL_API_VAR
PFNGLUNIFORM3IPROC
CoreGl_Uniform3i;

TRANSGL_API_VAR
PFNGLUNIFORM4IPROC
CoreGl_Uniform4i;

TRANSGL_API_VAR
PFNGLUNIFORM1FVPROC
CoreGl_Uniform1fv;

TRANSGL_API_VAR
PFNGLUNIFORM2FVPROC
CoreGl_Uniform2fv;

TRANSGL_API_VAR
PFNGLUNIFORM3FVPROC
CoreGl_Uniform3fv;

TRANSGL_API_VAR
PFNGLUNIFORM4FVPROC
CoreGl_Uniform4fv;

TRANSGL_API_VAR
PFNGLUNIFORM1IVPROC
CoreGl_Uniform1iv;

TRANSGL_API_VAR
PFNGLUNIFORM2IVPROC
CoreGl_Uniform2iv;

TRANSGL_API_VAR
PFNGLUNIFORM3IVPROC
CoreGl_Uniform3iv;

TRANSGL_API_VAR
PFNGLUNIFORM4IVPROC
CoreGl_Uniform4iv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX2FVPROC
CoreGl_UniformMatrix2fv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX3FVPROC
CoreGl_UniformMatrix3fv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX4FVPROC
CoreGl_UniformMatrix4fv;

TRANSGL_API_VAR
PFNGLVALIDATEPROGRAMPROC
CoreGl_ValidateProgram;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB1DPROC
CoreGl_VertexAttrib1d;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB1DVPROC
CoreGl_VertexAttrib1dv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB1FPROC
CoreGl_VertexAttrib1f;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB1FVPROC
CoreGl_VertexAttrib1fv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB1SPROC
CoreGl_VertexAttrib1s;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB1SVPROC
CoreGl_VertexAttrib1sv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB2DPROC
CoreGl_VertexAttrib2d;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB2DVPROC
CoreGl_VertexAttrib2dv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB2FPROC
CoreGl_VertexAttrib2f;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB2FVPROC
CoreGl_VertexAttrib2fv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB2SPROC
CoreGl_VertexAttrib2s;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB2SVPROC
CoreGl_VertexAttrib2sv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB3DPROC
CoreGl_VertexAttrib3d;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB3DVPROC
CoreGl_VertexAttrib3dv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB3FPROC
CoreGl_VertexAttrib3f;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB3FVPROC
CoreGl_VertexAttrib3fv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB3SPROC
CoreGl_VertexAttrib3s;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB3SVPROC
CoreGl_VertexAttrib3sv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4NBVPROC
CoreGl_VertexAttrib4Nbv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4NIVPROC
CoreGl_VertexAttrib4Niv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4NSVPROC
CoreGl_VertexAttrib4Nsv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4NUBPROC
CoreGl_VertexAttrib4Nub;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4NUBVPROC
CoreGl_VertexAttrib4Nubv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4NUIVPROC
CoreGl_VertexAttrib4Nuiv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4NUSVPROC
CoreGl_VertexAttrib4Nusv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4BVPROC
CoreGl_VertexAttrib4bv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4DPROC
CoreGl_VertexAttrib4d;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4DVPROC
CoreGl_VertexAttrib4dv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4FPROC
CoreGl_VertexAttrib4f;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4FVPROC
CoreGl_VertexAttrib4fv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4IVPROC
CoreGl_VertexAttrib4iv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4SPROC
CoreGl_VertexAttrib4s;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4SVPROC
CoreGl_VertexAttrib4sv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4UBVPROC
CoreGl_VertexAttrib4ubv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4UIVPROC
CoreGl_VertexAttrib4uiv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIB4USVPROC
CoreGl_VertexAttrib4usv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBPOINTERPROC
CoreGl_VertexAttribPointer;

//---- VERSION_2_1 ----

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX2X3FVPROC
CoreGl_UniformMatrix2x3fv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX3X2FVPROC
CoreGl_UniformMatrix3x2fv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX2X4FVPROC
CoreGl_UniformMatrix2x4fv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX4X2FVPROC
CoreGl_UniformMatrix4x2fv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX3X4FVPROC
CoreGl_UniformMatrix3x4fv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX4X3FVPROC
CoreGl_UniformMatrix4x3fv;

//---- VERSION_3_0 ----

TRANSGL_API_VAR
PFNGLCOLORMASKIPROC
CoreGl_ColorMaski;

TRANSGL_API_VAR
PFNGLGETBOOLEANI_VPROC
CoreGl_GetBooleani_v;

TRANSGL_API_VAR
PFNGLGETINTEGERI_VPROC
CoreGl_GetIntegeri_v;

TRANSGL_API_VAR
PFNGLENABLEIPROC
CoreGl_Enablei;

TRANSGL_API_VAR
PFNGLDISABLEIPROC
CoreGl_Disablei;

TRANSGL_API_VAR
PFNGLISENABLEDIPROC
CoreGl_IsEnabledi;

TRANSGL_API_VAR
PFNGLBEGINTRANSFORMFEEDBACKPROC
CoreGl_BeginTransformFeedback;

TRANSGL_API_VAR
PFNGLENDTRANSFORMFEEDBACKPROC
CoreGl_EndTransformFeedback;

TRANSGL_API_VAR
PFNGLBINDBUFFERRANGEPROC
CoreGl_BindBufferRange;

TRANSGL_API_VAR
PFNGLBINDBUFFERBASEPROC
CoreGl_BindBufferBase;

TRANSGL_API_VAR
PFNGLTRANSFORMFEEDBACKVARYINGSPROC
CoreGl_TransformFeedbackVaryings;

TRANSGL_API_VAR
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC
CoreGl_GetTransformFeedbackVarying;

TRANSGL_API_VAR
PFNGLCLAMPCOLORPROC
CoreGl_ClampColor;

TRANSGL_API_VAR
PFNGLBEGINCONDITIONALRENDERPROC
CoreGl_BeginConditionalRender;

TRANSGL_API_VAR
PFNGLENDCONDITIONALRENDERPROC
CoreGl_EndConditionalRender;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBIPOINTERPROC
CoreGl_VertexAttribIPointer;

TRANSGL_API_VAR
PFNGLGETVERTEXATTRIBIIVPROC
CoreGl_GetVertexAttribIiv;

TRANSGL_API_VAR
PFNGLGETVERTEXATTRIBIUIVPROC
CoreGl_GetVertexAttribIuiv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI1IPROC
CoreGl_VertexAttribI1i;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI2IPROC
CoreGl_VertexAttribI2i;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI3IPROC
CoreGl_VertexAttribI3i;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI4IPROC
CoreGl_VertexAttribI4i;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI1UIPROC
CoreGl_VertexAttribI1ui;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI2UIPROC
CoreGl_VertexAttribI2ui;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI3UIPROC
CoreGl_VertexAttribI3ui;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI4UIPROC
CoreGl_VertexAttribI4ui;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI1IVPROC
CoreGl_VertexAttribI1iv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI2IVPROC
CoreGl_VertexAttribI2iv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI3IVPROC
CoreGl_VertexAttribI3iv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI4IVPROC
CoreGl_VertexAttribI4iv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI1UIVPROC
CoreGl_VertexAttribI1uiv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI2UIVPROC
CoreGl_VertexAttribI2uiv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI3UIVPROC
CoreGl_VertexAttribI3uiv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI4UIVPROC
CoreGl_VertexAttribI4uiv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI4BVPROC
CoreGl_VertexAttribI4bv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI4SVPROC
CoreGl_VertexAttribI4sv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI4UBVPROC
CoreGl_VertexAttribI4ubv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBI4USVPROC
CoreGl_VertexAttribI4usv;

TRANSGL_API_VAR
PFNGLGETUNIFORMUIVPROC
CoreGl_GetUniformuiv;

TRANSGL_API_VAR
PFNGLBINDFRAGDATALOCATIONPROC
CoreGl_BindFragDataLocation;

TRANSGL_API_VAR
PFNGLGETFRAGDATALOCATIONPROC
CoreGl_GetFragDataLocation;

TRANSGL_API_VAR
PFNGLUNIFORM1UIPROC
CoreGl_Uniform1ui;

TRANSGL_API_VAR
PFNGLUNIFORM2UIPROC
CoreGl_Uniform2ui;

TRANSGL_API_VAR
PFNGLUNIFORM3UIPROC
CoreGl_Uniform3ui;

TRANSGL_API_VAR
PFNGLUNIFORM4UIPROC
CoreGl_Uniform4ui;

TRANSGL_API_VAR
PFNGLUNIFORM1UIVPROC
CoreGl_Uniform1uiv;

TRANSGL_API_VAR
PFNGLUNIFORM2UIVPROC
CoreGl_Uniform2uiv;

TRANSGL_API_VAR
PFNGLUNIFORM3UIVPROC
CoreGl_Uniform3uiv;

TRANSGL_API_VAR
PFNGLUNIFORM4UIVPROC
CoreGl_Uniform4uiv;

TRANSGL_API_VAR
PFNGLTEXPARAMETERIIVPROC
CoreGl_TexParameterIiv;

TRANSGL_API_VAR
PFNGLTEXPARAMETERIUIVPROC
CoreGl_TexParameterIuiv;

TRANSGL_API_VAR
PFNGLGETTEXPARAMETERIIVPROC
CoreGl_GetTexParameterIiv;

TRANSGL_API_VAR
PFNGLGETTEXPARAMETERIUIVPROC
CoreGl_GetTexParameterIuiv;

TRANSGL_API_VAR
PFNGLCLEARBUFFERIVPROC
CoreGl_ClearBufferiv;

TRANSGL_API_VAR
PFNGLCLEARBUFFERUIVPROC
CoreGl_ClearBufferuiv;

TRANSGL_API_VAR
PFNGLCLEARBUFFERFVPROC
CoreGl_ClearBufferfv;

TRANSGL_API_VAR
PFNGLCLEARBUFFERFIPROC
CoreGl_ClearBufferfi;

TRANSGL_API_VAR
PFNGLGETSTRINGIPROC
CoreGl_GetStringi;

TRANSGL_API_VAR
PFNGLISRENDERBUFFERPROC
CoreGl_IsRenderbuffer;

TRANSGL_API_VAR
PFNGLBINDRENDERBUFFERPROC
CoreGl_BindRenderbuffer;

TRANSGL_API_VAR
PFNGLDELETERENDERBUFFERSPROC
CoreGl_DeleteRenderbuffers;

TRANSGL_API_VAR
PFNGLGENRENDERBUFFERSPROC
CoreGl_GenRenderbuffers;

TRANSGL_API_VAR
PFNGLRENDERBUFFERSTORAGEPROC
CoreGl_RenderbufferStorage;

TRANSGL_API_VAR
PFNGLGETRENDERBUFFERPARAMETERIVPROC
CoreGl_GetRenderbufferParameteriv;

TRANSGL_API_VAR
PFNGLISFRAMEBUFFERPROC
CoreGl_IsFramebuffer;

TRANSGL_API_VAR
PFNGLBINDFRAMEBUFFERPROC
CoreGl_BindFramebuffer;

TRANSGL_API_VAR
PFNGLDELETEFRAMEBUFFERSPROC
CoreGl_DeleteFramebuffers;

TRANSGL_API_VAR
PFNGLGENFRAMEBUFFERSPROC
CoreGl_GenFramebuffers;

TRANSGL_API_VAR
PFNGLCHECKFRAMEBUFFERSTATUSPROC
CoreGl_CheckFramebufferStatus;

TRANSGL_API_VAR
PFNGLFRAMEBUFFERTEXTURE1DPROC
CoreGl_FramebufferTexture1D;

TRANSGL_API_VAR
PFNGLFRAMEBUFFERTEXTURE2DPROC
CoreGl_FramebufferTexture2D;

TRANSGL_API_VAR
PFNGLFRAMEBUFFERTEXTURE3DPROC
CoreGl_FramebufferTexture3D;

TRANSGL_API_VAR
PFNGLFRAMEBUFFERRENDERBUFFERPROC
CoreGl_FramebufferRenderbuffer;

TRANSGL_API_VAR
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC
CoreGl_GetFramebufferAttachmentParameteriv;

TRANSGL_API_VAR
PFNGLGENERATEMIPMAPPROC
CoreGl_GenerateMipmap;

TRANSGL_API_VAR
PFNGLBLITFRAMEBUFFERPROC
CoreGl_BlitFramebuffer;

TRANSGL_API_VAR
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC
CoreGl_RenderbufferStorageMultisample;

TRANSGL_API_VAR
PFNGLFRAMEBUFFERTEXTURELAYERPROC
CoreGl_FramebufferTextureLayer;

TRANSGL_API_VAR
PFNGLMAPBUFFERRANGEPROC
CoreGl_MapBufferRange;

TRANSGL_API_VAR
PFNGLFLUSHMAPPEDBUFFERRANGEPROC
CoreGl_FlushMappedBufferRange;

TRANSGL_API_VAR
PFNGLBINDVERTEXARRAYPROC
CoreGl_BindVertexArray;

TRANSGL_API_VAR
PFNGLDELETEVERTEXARRAYSPROC
CoreGl_DeleteVertexArrays;

TRANSGL_API_VAR
PFNGLGENVERTEXARRAYSPROC
CoreGl_GenVertexArrays;

TRANSGL_API_VAR
PFNGLISVERTEXARRAYPROC
CoreGl_IsVertexArray;

//---- VERSION_3_1 ----

TRANSGL_API_VAR
PFNGLDRAWARRAYSINSTANCEDPROC
CoreGl_DrawArraysInstanced;

TRANSGL_API_VAR
PFNGLDRAWELEMENTSINSTANCEDPROC
CoreGl_DrawElementsInstanced;

TRANSGL_API_VAR
PFNGLTEXBUFFERPROC
CoreGl_TexBuffer;

TRANSGL_API_VAR
PFNGLPRIMITIVERESTARTINDEXPROC
CoreGl_PrimitiveRestartIndex;

TRANSGL_API_VAR
PFNGLCOPYBUFFERSUBDATAPROC
CoreGl_CopyBufferSubData;

TRANSGL_API_VAR
PFNGLGETUNIFORMINDICESPROC
CoreGl_GetUniformIndices;

TRANSGL_API_VAR
PFNGLGETACTIVEUNIFORMSIVPROC
CoreGl_GetActiveUniformsiv;

TRANSGL_API_VAR
PFNGLGETACTIVEUNIFORMNAMEPROC
CoreGl_GetActiveUniformName;

TRANSGL_API_VAR
PFNGLGETUNIFORMBLOCKINDEXPROC
CoreGl_GetUniformBlockIndex;

TRANSGL_API_VAR
PFNGLGETACTIVEUNIFORMBLOCKIVPROC
CoreGl_GetActiveUniformBlockiv;

TRANSGL_API_VAR
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC
CoreGl_GetActiveUniformBlockName;

TRANSGL_API_VAR
PFNGLUNIFORMBLOCKBINDINGPROC
CoreGl_UniformBlockBinding;

//---- VERSION_3_2 ----

TRANSGL_API_VAR
PFNGLDRAWELEMENTSBASEVERTEXPROC
CoreGl_DrawElementsBaseVertex;

TRANSGL_API_VAR
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC
CoreGl_DrawRangeElementsBaseVertex;

TRANSGL_API_VAR
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC
CoreGl_DrawElementsInstancedBaseVertex;

TRANSGL_API_VAR
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC
CoreGl_MultiDrawElementsBaseVertex;

TRANSGL_API_VAR
PFNGLPROVOKINGVERTEXPROC
CoreGl_ProvokingVertex;

TRANSGL_API_VAR
PFNGLFENCESYNCPROC
CoreGl_FenceSync;

TRANSGL_API_VAR
PFNGLISSYNCPROC
CoreGl_IsSync;

TRANSGL_API_VAR
PFNGLDELETESYNCPROC
CoreGl_DeleteSync;

TRANSGL_API_VAR
PFNGLCLIENTWAITSYNCPROC
CoreGl_ClientWaitSync;

TRANSGL_API_VAR
PFNGLWAITSYNCPROC
CoreGl_WaitSync;

TRANSGL_API_VAR
PFNGLGETINTEGER64VPROC
CoreGl_GetInteger64v;

TRANSGL_API_VAR
PFNGLGETSYNCIVPROC
CoreGl_GetSynciv;

TRANSGL_API_VAR
PFNGLGETINTEGER64I_VPROC
CoreGl_GetInteger64i_v;

TRANSGL_API_VAR
PFNGLGETBUFFERPARAMETERI64VPROC
CoreGl_GetBufferParameteri64v;

TRANSGL_API_VAR
PFNGLFRAMEBUFFERTEXTUREPROC
CoreGl_FramebufferTexture;

TRANSGL_API_VAR
PFNGLTEXIMAGE2DMULTISAMPLEPROC
CoreGl_TexImage2DMultisample;

TRANSGL_API_VAR
PFNGLTEXIMAGE3DMULTISAMPLEPROC
CoreGl_TexImage3DMultisample;

TRANSGL_API_VAR
PFNGLGETMULTISAMPLEFVPROC
CoreGl_GetMultisamplefv;

TRANSGL_API_VAR
PFNGLSAMPLEMASKIPROC
CoreGl_SampleMaski;

//---- VERSION_3_3 ----

TRANSGL_API_VAR
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC
CoreGl_BindFragDataLocationIndexed;

TRANSGL_API_VAR
PFNGLGETFRAGDATAINDEXPROC
CoreGl_GetFragDataIndex;

TRANSGL_API_VAR
PFNGLGENSAMPLERSPROC
CoreGl_GenSamplers;

TRANSGL_API_VAR
PFNGLDELETESAMPLERSPROC
CoreGl_DeleteSamplers;

TRANSGL_API_VAR
PFNGLISSAMPLERPROC
CoreGl_IsSampler;

TRANSGL_API_VAR
PFNGLBINDSAMPLERPROC
CoreGl_BindSampler;

TRANSGL_API_VAR
PFNGLSAMPLERPARAMETERIPROC
CoreGl_SamplerParameteri;

TRANSGL_API_VAR
PFNGLSAMPLERPARAMETERIVPROC
CoreGl_SamplerParameteriv;

TRANSGL_API_VAR
PFNGLSAMPLERPARAMETERFPROC
CoreGl_SamplerParameterf;

TRANSGL_API_VAR
PFNGLSAMPLERPARAMETERFVPROC
CoreGl_SamplerParameterfv;

TRANSGL_API_VAR
PFNGLSAMPLERPARAMETERIIVPROC
CoreGl_SamplerParameterIiv;

TRANSGL_API_VAR
PFNGLSAMPLERPARAMETERIUIVPROC
CoreGl_SamplerParameterIuiv;

TRANSGL_API_VAR
PFNGLGETSAMPLERPARAMETERIVPROC
CoreGl_GetSamplerParameteriv;

TRANSGL_API_VAR
PFNGLGETSAMPLERPARAMETERIIVPROC
CoreGl_GetSamplerParameterIiv;

TRANSGL_API_VAR
PFNGLGETSAMPLERPARAMETERFVPROC
CoreGl_GetSamplerParameterfv;

TRANSGL_API_VAR
PFNGLGETSAMPLERPARAMETERIUIVPROC
CoreGl_GetSamplerParameterIuiv;

TRANSGL_API_VAR
PFNGLQUERYCOUNTERPROC
CoreGl_QueryCounter;

TRANSGL_API_VAR
PFNGLGETQUERYOBJECTI64VPROC
CoreGl_GetQueryObjecti64v;

TRANSGL_API_VAR
PFNGLGETQUERYOBJECTUI64VPROC
CoreGl_GetQueryObjectui64v;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBDIVISORPROC
CoreGl_VertexAttribDivisor;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBP1UIPROC
CoreGl_VertexAttribP1ui;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBP1UIVPROC
CoreGl_VertexAttribP1uiv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBP2UIPROC
CoreGl_VertexAttribP2ui;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBP2UIVPROC
CoreGl_VertexAttribP2uiv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBP3UIPROC
CoreGl_VertexAttribP3ui;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBP3UIVPROC
CoreGl_VertexAttribP3uiv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBP4UIPROC
CoreGl_VertexAttribP4ui;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBP4UIVPROC
CoreGl_VertexAttribP4uiv;

//---- VERSION_4_0 ----

TRANSGL_API_VAR
PFNGLMINSAMPLESHADINGPROC
CoreGl_MinSampleShading;

TRANSGL_API_VAR
PFNGLBLENDEQUATIONIPROC
CoreGl_BlendEquationi;

TRANSGL_API_VAR
PFNGLBLENDEQUATIONSEPARATEIPROC
CoreGl_BlendEquationSeparatei;

TRANSGL_API_VAR
PFNGLBLENDFUNCIPROC
CoreGl_BlendFunci;

TRANSGL_API_VAR
PFNGLBLENDFUNCSEPARATEIPROC
CoreGl_BlendFuncSeparatei;

TRANSGL_API_VAR
PFNGLDRAWARRAYSINDIRECTPROC
CoreGl_DrawArraysIndirect;

TRANSGL_API_VAR
PFNGLDRAWELEMENTSINDIRECTPROC
CoreGl_DrawElementsIndirect;

TRANSGL_API_VAR
PFNGLUNIFORM1DPROC
CoreGl_Uniform1d;

TRANSGL_API_VAR
PFNGLUNIFORM2DPROC
CoreGl_Uniform2d;

TRANSGL_API_VAR
PFNGLUNIFORM3DPROC
CoreGl_Uniform3d;

TRANSGL_API_VAR
PFNGLUNIFORM4DPROC
CoreGl_Uniform4d;

TRANSGL_API_VAR
PFNGLUNIFORM1DVPROC
CoreGl_Uniform1dv;

TRANSGL_API_VAR
PFNGLUNIFORM2DVPROC
CoreGl_Uniform2dv;

TRANSGL_API_VAR
PFNGLUNIFORM3DVPROC
CoreGl_Uniform3dv;

TRANSGL_API_VAR
PFNGLUNIFORM4DVPROC
CoreGl_Uniform4dv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX2DVPROC
CoreGl_UniformMatrix2dv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX3DVPROC
CoreGl_UniformMatrix3dv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX4DVPROC
CoreGl_UniformMatrix4dv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX2X3DVPROC
CoreGl_UniformMatrix2x3dv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX2X4DVPROC
CoreGl_UniformMatrix2x4dv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX3X2DVPROC
CoreGl_UniformMatrix3x2dv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX3X4DVPROC
CoreGl_UniformMatrix3x4dv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX4X2DVPROC
CoreGl_UniformMatrix4x2dv;

TRANSGL_API_VAR
PFNGLUNIFORMMATRIX4X3DVPROC
CoreGl_UniformMatrix4x3dv;

TRANSGL_API_VAR
PFNGLGETUNIFORMDVPROC
CoreGl_GetUniformdv;

TRANSGL_API_VAR
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC
CoreGl_GetSubroutineUniformLocation;

TRANSGL_API_VAR
PFNGLGETSUBROUTINEINDEXPROC
CoreGl_GetSubroutineIndex;

TRANSGL_API_VAR
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC
CoreGl_GetActiveSubroutineUniformiv;

TRANSGL_API_VAR
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC
CoreGl_GetActiveSubroutineUniformName;

TRANSGL_API_VAR
PFNGLGETACTIVESUBROUTINENAMEPROC
CoreGl_GetActiveSubroutineName;

TRANSGL_API_VAR
PFNGLUNIFORMSUBROUTINESUIVPROC
CoreGl_UniformSubroutinesuiv;

TRANSGL_API_VAR
PFNGLGETUNIFORMSUBROUTINEUIVPROC
CoreGl_GetUniformSubroutineuiv;

TRANSGL_API_VAR
PFNGLGETPROGRAMSTAGEIVPROC
CoreGl_GetProgramStageiv;

TRANSGL_API_VAR
PFNGLPATCHPARAMETERIPROC
CoreGl_PatchParameteri;

TRANSGL_API_VAR
PFNGLPATCHPARAMETERFVPROC
CoreGl_PatchParameterfv;

TRANSGL_API_VAR
PFNGLBINDTRANSFORMFEEDBACKPROC
CoreGl_BindTransformFeedback;

TRANSGL_API_VAR
PFNGLDELETETRANSFORMFEEDBACKSPROC
CoreGl_DeleteTransformFeedbacks;

TRANSGL_API_VAR
PFNGLGENTRANSFORMFEEDBACKSPROC
CoreGl_GenTransformFeedbacks;

TRANSGL_API_VAR
PFNGLISTRANSFORMFEEDBACKPROC
CoreGl_IsTransformFeedback;

TRANSGL_API_VAR
PFNGLPAUSETRANSFORMFEEDBACKPROC
CoreGl_PauseTransformFeedback;

TRANSGL_API_VAR
PFNGLRESUMETRANSFORMFEEDBACKPROC
CoreGl_ResumeTransformFeedback;

TRANSGL_API_VAR
PFNGLDRAWTRANSFORMFEEDBACKPROC
CoreGl_DrawTransformFeedback;

TRANSGL_API_VAR
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC
CoreGl_DrawTransformFeedbackStream;

TRANSGL_API_VAR
PFNGLBEGINQUERYINDEXEDPROC
CoreGl_BeginQueryIndexed;

TRANSGL_API_VAR
PFNGLENDQUERYINDEXEDPROC
CoreGl_EndQueryIndexed;

TRANSGL_API_VAR
PFNGLGETQUERYINDEXEDIVPROC
CoreGl_GetQueryIndexediv;

//---- VERSION_4_1 ----

TRANSGL_API_VAR
PFNGLRELEASESHADERCOMPILERPROC
CoreGl_ReleaseShaderCompiler;

TRANSGL_API_VAR
PFNGLSHADERBINARYPROC
CoreGl_ShaderBinary;

TRANSGL_API_VAR
PFNGLGETSHADERPRECISIONFORMATPROC
CoreGl_GetShaderPrecisionFormat;

TRANSGL_API_VAR
PFNGLDEPTHRANGEFPROC
CoreGl_DepthRangef;

TRANSGL_API_VAR
PFNGLCLEARDEPTHFPROC
CoreGl_ClearDepthf;

TRANSGL_API_VAR
PFNGLGETPROGRAMBINARYPROC
CoreGl_GetProgramBinary;

TRANSGL_API_VAR
PFNGLPROGRAMBINARYPROC
CoreGl_ProgramBinary;

TRANSGL_API_VAR
PFNGLPROGRAMPARAMETERIPROC
CoreGl_ProgramParameteri;

TRANSGL_API_VAR
PFNGLUSEPROGRAMSTAGESPROC
CoreGl_UseProgramStages;

TRANSGL_API_VAR
PFNGLACTIVESHADERPROGRAMPROC
CoreGl_ActiveShaderProgram;

TRANSGL_API_VAR
PFNGLCREATESHADERPROGRAMVPROC
CoreGl_CreateShaderProgramv;

TRANSGL_API_VAR
PFNGLBINDPROGRAMPIPELINEPROC
CoreGl_BindProgramPipeline;

TRANSGL_API_VAR
PFNGLDELETEPROGRAMPIPELINESPROC
CoreGl_DeleteProgramPipelines;

TRANSGL_API_VAR
PFNGLGENPROGRAMPIPELINESPROC
CoreGl_GenProgramPipelines;

TRANSGL_API_VAR
PFNGLISPROGRAMPIPELINEPROC
CoreGl_IsProgramPipeline;

TRANSGL_API_VAR
PFNGLGETPROGRAMPIPELINEIVPROC
CoreGl_GetProgramPipelineiv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM1IPROC
CoreGl_ProgramUniform1i;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM1IVPROC
CoreGl_ProgramUniform1iv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM1FPROC
CoreGl_ProgramUniform1f;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM1FVPROC
CoreGl_ProgramUniform1fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM1DPROC
CoreGl_ProgramUniform1d;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM1DVPROC
CoreGl_ProgramUniform1dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM1UIPROC
CoreGl_ProgramUniform1ui;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM1UIVPROC
CoreGl_ProgramUniform1uiv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM2IPROC
CoreGl_ProgramUniform2i;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM2IVPROC
CoreGl_ProgramUniform2iv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM2FPROC
CoreGl_ProgramUniform2f;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM2FVPROC
CoreGl_ProgramUniform2fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM2DPROC
CoreGl_ProgramUniform2d;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM2DVPROC
CoreGl_ProgramUniform2dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM2UIPROC
CoreGl_ProgramUniform2ui;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM2UIVPROC
CoreGl_ProgramUniform2uiv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM3IPROC
CoreGl_ProgramUniform3i;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM3IVPROC
CoreGl_ProgramUniform3iv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM3FPROC
CoreGl_ProgramUniform3f;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM3FVPROC
CoreGl_ProgramUniform3fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM3DPROC
CoreGl_ProgramUniform3d;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM3DVPROC
CoreGl_ProgramUniform3dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM3UIPROC
CoreGl_ProgramUniform3ui;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM3UIVPROC
CoreGl_ProgramUniform3uiv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM4IPROC
CoreGl_ProgramUniform4i;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM4IVPROC
CoreGl_ProgramUniform4iv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM4FPROC
CoreGl_ProgramUniform4f;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM4FVPROC
CoreGl_ProgramUniform4fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM4DPROC
CoreGl_ProgramUniform4d;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM4DVPROC
CoreGl_ProgramUniform4dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM4UIPROC
CoreGl_ProgramUniform4ui;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORM4UIVPROC
CoreGl_ProgramUniform4uiv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX2FVPROC
CoreGl_ProgramUniformMatrix2fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX3FVPROC
CoreGl_ProgramUniformMatrix3fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX4FVPROC
CoreGl_ProgramUniformMatrix4fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX2DVPROC
CoreGl_ProgramUniformMatrix2dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX3DVPROC
CoreGl_ProgramUniformMatrix3dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX4DVPROC
CoreGl_ProgramUniformMatrix4dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC
CoreGl_ProgramUniformMatrix2x3fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC
CoreGl_ProgramUniformMatrix3x2fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC
CoreGl_ProgramUniformMatrix2x4fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC
CoreGl_ProgramUniformMatrix4x2fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC
CoreGl_ProgramUniformMatrix3x4fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC
CoreGl_ProgramUniformMatrix4x3fv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC
CoreGl_ProgramUniformMatrix2x3dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC
CoreGl_ProgramUniformMatrix3x2dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC
CoreGl_ProgramUniformMatrix2x4dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC
CoreGl_ProgramUniformMatrix4x2dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC
CoreGl_ProgramUniformMatrix3x4dv;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC
CoreGl_ProgramUniformMatrix4x3dv;

TRANSGL_API_VAR
PFNGLVALIDATEPROGRAMPIPELINEPROC
CoreGl_ValidateProgramPipeline;

TRANSGL_API_VAR
PFNGLGETPROGRAMPIPELINEINFOLOGPROC
CoreGl_GetProgramPipelineInfoLog;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBL1DPROC
CoreGl_VertexAttribL1d;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBL2DPROC
CoreGl_VertexAttribL2d;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBL3DPROC
CoreGl_VertexAttribL3d;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBL4DPROC
CoreGl_VertexAttribL4d;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBL1DVPROC
CoreGl_VertexAttribL1dv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBL2DVPROC
CoreGl_VertexAttribL2dv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBL3DVPROC
CoreGl_VertexAttribL3dv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBL4DVPROC
CoreGl_VertexAttribL4dv;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBLPOINTERPROC
CoreGl_VertexAttribLPointer;

TRANSGL_API_VAR
PFNGLGETVERTEXATTRIBLDVPROC
CoreGl_GetVertexAttribLdv;

TRANSGL_API_VAR
PFNGLVIEWPORTARRAYVPROC
CoreGl_ViewportArrayv;

TRANSGL_API_VAR
PFNGLVIEWPORTINDEXEDFPROC
CoreGl_ViewportIndexedf;

TRANSGL_API_VAR
PFNGLVIEWPORTINDEXEDFVPROC
CoreGl_ViewportIndexedfv;

TRANSGL_API_VAR
PFNGLSCISSORARRAYVPROC
CoreGl_ScissorArrayv;

TRANSGL_API_VAR
PFNGLSCISSORINDEXEDPROC
CoreGl_ScissorIndexed;

TRANSGL_API_VAR
PFNGLSCISSORINDEXEDVPROC
CoreGl_ScissorIndexedv;

TRANSGL_API_VAR
PFNGLDEPTHRANGEARRAYVPROC
CoreGl_DepthRangeArrayv;

TRANSGL_API_VAR
PFNGLDEPTHRANGEINDEXEDPROC
CoreGl_DepthRangeIndexed;

TRANSGL_API_VAR
PFNGLGETFLOATI_VPROC
CoreGl_GetFloati_v;

TRANSGL_API_VAR
PFNGLGETDOUBLEI_VPROC
CoreGl_GetDoublei_v;

//---- VERSION_4_2 ----

TRANSGL_API_VAR
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC
CoreGl_DrawArraysInstancedBaseInstance;

TRANSGL_API_VAR
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC
CoreGl_DrawElementsInstancedBaseInstance;

TRANSGL_API_VAR
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC
CoreGl_DrawElementsInstancedBaseVertexBaseInstance;

TRANSGL_API_VAR
PFNGLGETINTERNALFORMATIVPROC
CoreGl_GetInternalformativ;

TRANSGL_API_VAR
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC
CoreGl_GetActiveAtomicCounterBufferiv;

TRANSGL_API_VAR
PFNGLBINDIMAGETEXTUREPROC
CoreGl_BindImageTexture;

TRANSGL_API_VAR
PFNGLMEMORYBARRIERPROC
CoreGl_MemoryBarrier;

TRANSGL_API_VAR
PFNGLTEXSTORAGE1DPROC
CoreGl_TexStorage1D;

TRANSGL_API_VAR
PFNGLTEXSTORAGE2DPROC
CoreGl_TexStorage2D;

TRANSGL_API_VAR
PFNGLTEXSTORAGE3DPROC
CoreGl_TexStorage3D;

TRANSGL_API_VAR
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC
CoreGl_DrawTransformFeedbackInstanced;

TRANSGL_API_VAR
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC
CoreGl_DrawTransformFeedbackStreamInstanced;

//---- VERSION_4_3 ----

TRANSGL_API_VAR
PFNGLCLEARBUFFERDATAPROC
CoreGl_ClearBufferData;

TRANSGL_API_VAR
PFNGLCLEARBUFFERSUBDATAPROC
CoreGl_ClearBufferSubData;

TRANSGL_API_VAR
PFNGLDISPATCHCOMPUTEPROC
CoreGl_DispatchCompute;

TRANSGL_API_VAR
PFNGLDISPATCHCOMPUTEINDIRECTPROC
CoreGl_DispatchComputeIndirect;

TRANSGL_API_VAR
PFNGLCOPYIMAGESUBDATAPROC
CoreGl_CopyImageSubData;

TRANSGL_API_VAR
PFNGLFRAMEBUFFERPARAMETERIPROC
CoreGl_FramebufferParameteri;

TRANSGL_API_VAR
PFNGLGETFRAMEBUFFERPARAMETERIVPROC
CoreGl_GetFramebufferParameteriv;

TRANSGL_API_VAR
PFNGLGETINTERNALFORMATI64VPROC
CoreGl_GetInternalformati64v;

TRANSGL_API_VAR
PFNGLINVALIDATETEXSUBIMAGEPROC
CoreGl_InvalidateTexSubImage;

TRANSGL_API_VAR
PFNGLINVALIDATETEXIMAGEPROC
CoreGl_InvalidateTexImage;

TRANSGL_API_VAR
PFNGLINVALIDATEBUFFERSUBDATAPROC
CoreGl_InvalidateBufferSubData;

TRANSGL_API_VAR
PFNGLINVALIDATEBUFFERDATAPROC
CoreGl_InvalidateBufferData;

TRANSGL_API_VAR
PFNGLINVALIDATEFRAMEBUFFERPROC
CoreGl_InvalidateFramebuffer;

TRANSGL_API_VAR
PFNGLINVALIDATESUBFRAMEBUFFERPROC
CoreGl_InvalidateSubFramebuffer;

TRANSGL_API_VAR
PFNGLMULTIDRAWARRAYSINDIRECTPROC
CoreGl_MultiDrawArraysIndirect;

TRANSGL_API_VAR
PFNGLMULTIDRAWELEMENTSINDIRECTPROC
CoreGl_MultiDrawElementsIndirect;

TRANSGL_API_VAR
PFNGLGETPROGRAMINTERFACEIVPROC
CoreGl_GetProgramInterfaceiv;

TRANSGL_API_VAR
PFNGLGETPROGRAMRESOURCEINDEXPROC
CoreGl_GetProgramResourceIndex;

TRANSGL_API_VAR
PFNGLGETPROGRAMRESOURCENAMEPROC
CoreGl_GetProgramResourceName;

TRANSGL_API_VAR
PFNGLGETPROGRAMRESOURCEIVPROC
CoreGl_GetProgramResourceiv;

TRANSGL_API_VAR
PFNGLGETPROGRAMRESOURCELOCATIONPROC
CoreGl_GetProgramResourceLocation;

TRANSGL_API_VAR
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC
CoreGl_GetProgramResourceLocationIndex;

TRANSGL_API_VAR
PFNGLSHADERSTORAGEBLOCKBINDINGPROC
CoreGl_ShaderStorageBlockBinding;

TRANSGL_API_VAR
PFNGLTEXBUFFERRANGEPROC
CoreGl_TexBufferRange;

TRANSGL_API_VAR
PFNGLTEXSTORAGE2DMULTISAMPLEPROC
CoreGl_TexStorage2DMultisample;

TRANSGL_API_VAR
PFNGLTEXSTORAGE3DMULTISAMPLEPROC
CoreGl_TexStorage3DMultisample;

TRANSGL_API_VAR
PFNGLTEXTUREVIEWPROC
CoreGl_TextureView;

TRANSGL_API_VAR
PFNGLBINDVERTEXBUFFERPROC
CoreGl_BindVertexBuffer;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBFORMATPROC
CoreGl_VertexAttribFormat;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBIFORMATPROC
CoreGl_VertexAttribIFormat;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBLFORMATPROC
CoreGl_VertexAttribLFormat;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBBINDINGPROC
CoreGl_VertexAttribBinding;

TRANSGL_API_VAR
PFNGLVERTEXBINDINGDIVISORPROC
CoreGl_VertexBindingDivisor;

TRANSGL_API_VAR
PFNGLDEBUGMESSAGECONTROLPROC
CoreGl_DebugMessageControl;

TRANSGL_API_VAR
PFNGLDEBUGMESSAGEINSERTPROC
CoreGl_DebugMessageInsert;

TRANSGL_API_VAR
PFNGLDEBUGMESSAGECALLBACKPROC
CoreGl_DebugMessageCallback;

TRANSGL_API_VAR
PFNGLGETDEBUGMESSAGELOGPROC
CoreGl_GetDebugMessageLog;

TRANSGL_API_VAR
PFNGLPUSHDEBUGGROUPPROC
CoreGl_PushDebugGroup;

TRANSGL_API_VAR
PFNGLPOPDEBUGGROUPPROC
CoreGl_PopDebugGroup;

TRANSGL_API_VAR
PFNGLOBJECTLABELPROC
CoreGl_ObjectLabel;

TRANSGL_API_VAR
PFNGLGETOBJECTLABELPROC
CoreGl_GetObjectLabel;

TRANSGL_API_VAR
PFNGLOBJECTPTRLABELPROC
CoreGl_ObjectPtrLabel;

TRANSGL_API_VAR
PFNGLGETOBJECTPTRLABELPROC
CoreGl_GetObjectPtrLabel;

//---- VERSION_4_4 ----

TRANSGL_API_VAR
PFNGLBUFFERSTORAGEPROC
CoreGl_BufferStorage;

TRANSGL_API_VAR
PFNGLCLEARTEXIMAGEPROC
CoreGl_ClearTexImage;

TRANSGL_API_VAR
PFNGLCLEARTEXSUBIMAGEPROC
CoreGl_ClearTexSubImage;

TRANSGL_API_VAR
PFNGLBINDBUFFERSBASEPROC
CoreGl_BindBuffersBase;

TRANSGL_API_VAR
PFNGLBINDBUFFERSRANGEPROC
CoreGl_BindBuffersRange;

TRANSGL_API_VAR
PFNGLBINDTEXTURESPROC
CoreGl_BindTextures;

TRANSGL_API_VAR
PFNGLBINDSAMPLERSPROC
CoreGl_BindSamplers;

TRANSGL_API_VAR
PFNGLBINDIMAGETEXTURESPROC
CoreGl_BindImageTextures;

TRANSGL_API_VAR
PFNGLBINDVERTEXBUFFERSPROC
CoreGl_BindVertexBuffers;

//---- VERSION_4_5 ----

TRANSGL_API_VAR
PFNGLCLIPCONTROLPROC
CoreGl_ClipControl;

TRANSGL_API_VAR
PFNGLCREATETRANSFORMFEEDBACKSPROC
CoreGl_CreateTransformFeedbacks;

TRANSGL_API_VAR
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC
CoreGl_TransformFeedbackBufferBase;

TRANSGL_API_VAR
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC
CoreGl_TransformFeedbackBufferRange;

TRANSGL_API_VAR
PFNGLGETTRANSFORMFEEDBACKIVPROC
CoreGl_GetTransformFeedbackiv;

TRANSGL_API_VAR
PFNGLGETTRANSFORMFEEDBACKI_VPROC
CoreGl_GetTransformFeedbacki_v;

TRANSGL_API_VAR
PFNGLGETTRANSFORMFEEDBACKI64_VPROC
CoreGl_GetTransformFeedbacki64_v;

TRANSGL_API_VAR
PFNGLCREATEBUFFERSPROC
CoreGl_CreateBuffers;

TRANSGL_API_VAR
PFNGLNAMEDBUFFERSTORAGEPROC
CoreGl_NamedBufferStorage;

TRANSGL_API_VAR
PFNGLNAMEDBUFFERDATAPROC
CoreGl_NamedBufferData;

TRANSGL_API_VAR
PFNGLNAMEDBUFFERSUBDATAPROC
CoreGl_NamedBufferSubData;

TRANSGL_API_VAR
PFNGLCOPYNAMEDBUFFERSUBDATAPROC
CoreGl_CopyNamedBufferSubData;

TRANSGL_API_VAR
PFNGLCLEARNAMEDBUFFERDATAPROC
CoreGl_ClearNamedBufferData;

TRANSGL_API_VAR
PFNGLCLEARNAMEDBUFFERSUBDATAPROC
CoreGl_ClearNamedBufferSubData;

TRANSGL_API_VAR
PFNGLMAPNAMEDBUFFERPROC
CoreGl_MapNamedBuffer;

TRANSGL_API_VAR
PFNGLMAPNAMEDBUFFERRANGEPROC
CoreGl_MapNamedBufferRange;

TRANSGL_API_VAR
PFNGLUNMAPNAMEDBUFFERPROC
CoreGl_UnmapNamedBuffer;

TRANSGL_API_VAR
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC
CoreGl_FlushMappedNamedBufferRange;

TRANSGL_API_VAR
PFNGLGETNAMEDBUFFERPARAMETERIVPROC
CoreGl_GetNamedBufferParameteriv;

TRANSGL_API_VAR
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC
CoreGl_GetNamedBufferParameteri64v;

TRANSGL_API_VAR
PFNGLGETNAMEDBUFFERPOINTERVPROC
CoreGl_GetNamedBufferPointerv;

TRANSGL_API_VAR
PFNGLGETNAMEDBUFFERSUBDATAPROC
CoreGl_GetNamedBufferSubData;

TRANSGL_API_VAR
PFNGLCREATEFRAMEBUFFERSPROC
CoreGl_CreateFramebuffers;

TRANSGL_API_VAR
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC
CoreGl_NamedFramebufferRenderbuffer;

TRANSGL_API_VAR
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC
CoreGl_NamedFramebufferParameteri;

TRANSGL_API_VAR
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC
CoreGl_NamedFramebufferTexture;

TRANSGL_API_VAR
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC
CoreGl_NamedFramebufferTextureLayer;

TRANSGL_API_VAR
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC
CoreGl_NamedFramebufferDrawBuffer;

TRANSGL_API_VAR
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC
CoreGl_NamedFramebufferDrawBuffers;

TRANSGL_API_VAR
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC
CoreGl_NamedFramebufferReadBuffer;

TRANSGL_API_VAR
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC
CoreGl_InvalidateNamedFramebufferData;

TRANSGL_API_VAR
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC
CoreGl_InvalidateNamedFramebufferSubData;

TRANSGL_API_VAR
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC
CoreGl_ClearNamedFramebufferiv;

TRANSGL_API_VAR
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC
CoreGl_ClearNamedFramebufferuiv;

TRANSGL_API_VAR
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC
CoreGl_ClearNamedFramebufferfv;

TRANSGL_API_VAR
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC
CoreGl_ClearNamedFramebufferfi;

TRANSGL_API_VAR
PFNGLBLITNAMEDFRAMEBUFFERPROC
CoreGl_BlitNamedFramebuffer;

TRANSGL_API_VAR
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC
CoreGl_CheckNamedFramebufferStatus;

TRANSGL_API_VAR
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC
CoreGl_GetNamedFramebufferParameteriv;

TRANSGL_API_VAR
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC
CoreGl_GetNamedFramebufferAttachmentParameteriv;

TRANSGL_API_VAR
PFNGLCREATERENDERBUFFERSPROC
CoreGl_CreateRenderbuffers;

TRANSGL_API_VAR
PFNGLNAMEDRENDERBUFFERSTORAGEPROC
CoreGl_NamedRenderbufferStorage;

TRANSGL_API_VAR
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC
CoreGl_NamedRenderbufferStorageMultisample;

TRANSGL_API_VAR
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC
CoreGl_GetNamedRenderbufferParameteriv;

TRANSGL_API_VAR
PFNGLCREATETEXTURESPROC
CoreGl_CreateTextures;

TRANSGL_API_VAR
PFNGLTEXTUREBUFFERPROC
CoreGl_TextureBuffer;

TRANSGL_API_VAR
PFNGLTEXTUREBUFFERRANGEPROC
CoreGl_TextureBufferRange;

TRANSGL_API_VAR
PFNGLTEXTURESTORAGE1DPROC
CoreGl_TextureStorage1D;

TRANSGL_API_VAR
PFNGLTEXTURESTORAGE2DPROC
CoreGl_TextureStorage2D;

TRANSGL_API_VAR
PFNGLTEXTURESTORAGE3DPROC
CoreGl_TextureStorage3D;

TRANSGL_API_VAR
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC
CoreGl_TextureStorage2DMultisample;

TRANSGL_API_VAR
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC
CoreGl_TextureStorage3DMultisample;

TRANSGL_API_VAR
PFNGLTEXTURESUBIMAGE1DPROC
CoreGl_TextureSubImage1D;

TRANSGL_API_VAR
PFNGLTEXTURESUBIMAGE2DPROC
CoreGl_TextureSubImage2D;

TRANSGL_API_VAR
PFNGLTEXTURESUBIMAGE3DPROC
CoreGl_TextureSubImage3D;

TRANSGL_API_VAR
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC
CoreGl_CompressedTextureSubImage1D;

TRANSGL_API_VAR
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC
CoreGl_CompressedTextureSubImage2D;

TRANSGL_API_VAR
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC
CoreGl_CompressedTextureSubImage3D;

TRANSGL_API_VAR
PFNGLCOPYTEXTURESUBIMAGE1DPROC
CoreGl_CopyTextureSubImage1D;

TRANSGL_API_VAR
PFNGLCOPYTEXTURESUBIMAGE2DPROC
CoreGl_CopyTextureSubImage2D;

TRANSGL_API_VAR
PFNGLCOPYTEXTURESUBIMAGE3DPROC
CoreGl_CopyTextureSubImage3D;

TRANSGL_API_VAR
PFNGLTEXTUREPARAMETERFPROC
CoreGl_TextureParameterf;

TRANSGL_API_VAR
PFNGLTEXTUREPARAMETERFVPROC
CoreGl_TextureParameterfv;

TRANSGL_API_VAR
PFNGLTEXTUREPARAMETERIPROC
CoreGl_TextureParameteri;

TRANSGL_API_VAR
PFNGLTEXTUREPARAMETERIIVPROC
CoreGl_TextureParameterIiv;

TRANSGL_API_VAR
PFNGLTEXTUREPARAMETERIUIVPROC
CoreGl_TextureParameterIuiv;

TRANSGL_API_VAR
PFNGLTEXTUREPARAMETERIVPROC
CoreGl_TextureParameteriv;

TRANSGL_API_VAR
PFNGLGENERATETEXTUREMIPMAPPROC
CoreGl_GenerateTextureMipmap;

TRANSGL_API_VAR
PFNGLBINDTEXTUREUNITPROC
CoreGl_BindTextureUnit;

TRANSGL_API_VAR
PFNGLGETTEXTUREIMAGEPROC
CoreGl_GetTextureImage;

TRANSGL_API_VAR
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC
CoreGl_GetCompressedTextureImage;

TRANSGL_API_VAR
PFNGLGETTEXTURELEVELPARAMETERFVPROC
CoreGl_GetTextureLevelParameterfv;

TRANSGL_API_VAR
PFNGLGETTEXTURELEVELPARAMETERIVPROC
CoreGl_GetTextureLevelParameteriv;

TRANSGL_API_VAR
PFNGLGETTEXTUREPARAMETERFVPROC
CoreGl_GetTextureParameterfv;

TRANSGL_API_VAR
PFNGLGETTEXTUREPARAMETERIIVPROC
CoreGl_GetTextureParameterIiv;

TRANSGL_API_VAR
PFNGLGETTEXTUREPARAMETERIUIVPROC
CoreGl_GetTextureParameterIuiv;

TRANSGL_API_VAR
PFNGLGETTEXTUREPARAMETERIVPROC
CoreGl_GetTextureParameteriv;

TRANSGL_API_VAR
PFNGLCREATEVERTEXARRAYSPROC
CoreGl_CreateVertexArrays;

TRANSGL_API_VAR
PFNGLDISABLEVERTEXARRAYATTRIBPROC
CoreGl_DisableVertexArrayAttrib;

TRANSGL_API_VAR
PFNGLENABLEVERTEXARRAYATTRIBPROC
CoreGl_EnableVertexArrayAttrib;

TRANSGL_API_VAR
PFNGLVERTEXARRAYELEMENTBUFFERPROC
CoreGl_VertexArrayElementBuffer;

TRANSGL_API_VAR
PFNGLVERTEXARRAYVERTEXBUFFERPROC
CoreGl_VertexArrayVertexBuffer;

TRANSGL_API_VAR
PFNGLVERTEXARRAYVERTEXBUFFERSPROC
CoreGl_VertexArrayVertexBuffers;

TRANSGL_API_VAR
PFNGLVERTEXARRAYATTRIBBINDINGPROC
CoreGl_VertexArrayAttribBinding;

TRANSGL_API_VAR
PFNGLVERTEXARRAYATTRIBFORMATPROC
CoreGl_VertexArrayAttribFormat;

TRANSGL_API_VAR
PFNGLVERTEXARRAYATTRIBIFORMATPROC
CoreGl_VertexArrayAttribIFormat;

TRANSGL_API_VAR
PFNGLVERTEXARRAYATTRIBLFORMATPROC
CoreGl_VertexArrayAttribLFormat;

TRANSGL_API_VAR
PFNGLVERTEXARRAYBINDINGDIVISORPROC
CoreGl_VertexArrayBindingDivisor;

TRANSGL_API_VAR
PFNGLGETVERTEXARRAYIVPROC
CoreGl_GetVertexArrayiv;

TRANSGL_API_VAR
PFNGLGETVERTEXARRAYINDEXEDIVPROC
CoreGl_GetVertexArrayIndexediv;

TRANSGL_API_VAR
PFNGLGETVERTEXARRAYINDEXED64IVPROC
CoreGl_GetVertexArrayIndexed64iv;

TRANSGL_API_VAR
PFNGLCREATESAMPLERSPROC
CoreGl_CreateSamplers;

TRANSGL_API_VAR
PFNGLCREATEPROGRAMPIPELINESPROC
CoreGl_CreateProgramPipelines;

TRANSGL_API_VAR
PFNGLCREATEQUERIESPROC
CoreGl_CreateQueries;

TRANSGL_API_VAR
PFNGLGETQUERYBUFFEROBJECTI64VPROC
CoreGl_GetQueryBufferObjecti64v;

TRANSGL_API_VAR
PFNGLGETQUERYBUFFEROBJECTIVPROC
CoreGl_GetQueryBufferObjectiv;

TRANSGL_API_VAR
PFNGLGETQUERYBUFFEROBJECTUI64VPROC
CoreGl_GetQueryBufferObjectui64v;

TRANSGL_API_VAR
PFNGLGETQUERYBUFFEROBJECTUIVPROC
CoreGl_GetQueryBufferObjectuiv;

TRANSGL_API_VAR
PFNGLMEMORYBARRIERBYREGIONPROC
CoreGl_MemoryBarrierByRegion;

TRANSGL_API_VAR
PFNGLGETTEXTURESUBIMAGEPROC
CoreGl_GetTextureSubImage;

TRANSGL_API_VAR
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC
CoreGl_GetCompressedTextureSubImage;

TRANSGL_API_VAR
PFNGLGETGRAPHICSRESETSTATUSPROC
CoreGl_GetGraphicsResetStatus;

TRANSGL_API_VAR
PFNGLGETNCOMPRESSEDTEXIMAGEPROC
CoreGl_GetnCompressedTexImage;

TRANSGL_API_VAR
PFNGLGETNTEXIMAGEPROC
CoreGl_GetnTexImage;

TRANSGL_API_VAR
PFNGLGETNUNIFORMDVPROC
CoreGl_GetnUniformdv;

TRANSGL_API_VAR
PFNGLGETNUNIFORMFVPROC
CoreGl_GetnUniformfv;

TRANSGL_API_VAR
PFNGLGETNUNIFORMIVPROC
CoreGl_GetnUniformiv;

TRANSGL_API_VAR
PFNGLGETNUNIFORMUIVPROC
CoreGl_GetnUniformuiv;

TRANSGL_API_VAR
PFNGLREADNPIXELSPROC
CoreGl_ReadnPixels;

TRANSGL_API_VAR
PFNGLTEXTUREBARRIERPROC
CoreGl_TextureBarrier;

//---- ARB_ES2_compatibility ----

//---- ARB_ES3_1_compatibility ----

//---- ARB_ES3_compatibility ----

//---- ARB_arrays_of_arrays ----

//---- ARB_base_instance ----

//---- ARB_bindless_texture ----

TRANSGL_API_VAR
PFNGLGETTEXTUREHANDLEARBPROC
CoreGl_GetTextureHandleARB;

TRANSGL_API_VAR
PFNGLGETTEXTURESAMPLERHANDLEARBPROC
CoreGl_GetTextureSamplerHandleARB;

TRANSGL_API_VAR
PFNGLMAKETEXTUREHANDLERESIDENTARBPROC
CoreGl_MakeTextureHandleResidentARB;

TRANSGL_API_VAR
PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC
CoreGl_MakeTextureHandleNonResidentARB;

TRANSGL_API_VAR
PFNGLGETIMAGEHANDLEARBPROC
CoreGl_GetImageHandleARB;

TRANSGL_API_VAR
PFNGLMAKEIMAGEHANDLERESIDENTARBPROC
CoreGl_MakeImageHandleResidentARB;

TRANSGL_API_VAR
PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC
CoreGl_MakeImageHandleNonResidentARB;

TRANSGL_API_VAR
PFNGLUNIFORMHANDLEUI64ARBPROC
CoreGl_UniformHandleui64ARB;

TRANSGL_API_VAR
PFNGLUNIFORMHANDLEUI64VARBPROC
CoreGl_UniformHandleui64vARB;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC
CoreGl_ProgramUniformHandleui64ARB;

TRANSGL_API_VAR
PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC
CoreGl_ProgramUniformHandleui64vARB;

TRANSGL_API_VAR
PFNGLISTEXTUREHANDLERESIDENTARBPROC
CoreGl_IsTextureHandleResidentARB;

TRANSGL_API_VAR
PFNGLISIMAGEHANDLERESIDENTARBPROC
CoreGl_IsImageHandleResidentARB;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBL1UI64ARBPROC
CoreGl_VertexAttribL1ui64ARB;

TRANSGL_API_VAR
PFNGLVERTEXATTRIBL1UI64VARBPROC
CoreGl_VertexAttribL1ui64vARB;

TRANSGL_API_VAR
PFNGLGETVERTEXATTRIBLUI64VARBPROC
CoreGl_GetVertexAttribLui64vARB;

//---- ARB_blend_func_extended ----

//---- ARB_buffer_storage ----

//---- ARB_cl_event ----

TRANSGL_API_VAR
PFNGLCREATESYNCFROMCLEVENTARBPROC
CoreGl_CreateSyncFromCLeventARB;

//---- ARB_clear_buffer_object ----

//---- ARB_clear_texture ----

//---- ARB_clip_control ----

//---- ARB_compressed_texture_pixel_storage ----

//---- ARB_compute_shader ----

//---- ARB_compute_variable_group_size ----

TRANSGL_API_VAR
PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC
CoreGl_DispatchComputeGroupSizeARB;

//---- ARB_conditional_render_inverted ----

//---- ARB_conservative_depth ----

//---- ARB_copy_buffer ----

//---- ARB_copy_image ----

//---- ARB_cull_distance ----

//---- ARB_debug_output ----

TRANSGL_API_VAR
PFNGLDEBUGMESSAGECONTROLARBPROC
CoreGl_DebugMessageControlARB;

TRANSGL_API_VAR
PFNGLDEBUGMESSAGEINSERTARBPROC
CoreGl_DebugMessageInsertARB;

TRANSGL_API_VAR
PFNGLDEBUGMESSAGECALLBACKARBPROC
CoreGl_DebugMessageCallbackARB;

TRANSGL_API_VAR
PFNGLGETDEBUGMESSAGELOGARBPROC
CoreGl_GetDebugMessageLogARB;

//---- ARB_depth_buffer_float ----

//---- ARB_depth_clamp ----

//---- ARB_derivative_control ----

//---- ARB_direct_state_access ----

//---- ARB_draw_buffers_blend ----

TRANSGL_API_VAR
PFNGLBLENDEQUATIONIARBPROC
CoreGl_BlendEquationiARB;

TRANSGL_API_VAR
PFNGLBLENDEQUATIONSEPARATEIARBPROC
CoreGl_BlendEquationSeparateiARB;

TRANSGL_API_VAR
PFNGLBLENDFUNCIARBPROC
CoreGl_BlendFunciARB;

TRANSGL_API_VAR
PFNGLBLENDFUNCSEPARATEIARBPROC
CoreGl_BlendFuncSeparateiARB;

//---- ARB_draw_elements_base_vertex ----

//---- ARB_draw_indirect ----

//---- ARB_enhanced_layouts ----

//---- ARB_explicit_attrib_location ----

//---- ARB_explicit_uniform_location ----

//---- ARB_fragment_coord_conventions ----

//---- ARB_fragment_layer_viewport ----

//---- ARB_framebuffer_no_attachments ----

//---- ARB_framebuffer_object ----

//---- ARB_framebuffer_sRGB ----

//---- ARB_get_program_binary ----

//---- ARB_get_texture_sub_image ----

//---- ARB_gpu_shader5 ----

//---- ARB_gpu_shader_fp64 ----

//---- ARB_half_float_vertex ----

//---- ARB_imaging ----

//---- ARB_indirect_parameters ----

TRANSGL_API_VAR
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC
CoreGl_MultiDrawArraysIndirectCountARB;

TRANSGL_API_VAR
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC
CoreGl_MultiDrawElementsIndirectCountARB;

//---- ARB_internalformat_query ----

//---- ARB_internalformat_query2 ----

//---- ARB_invalidate_subdata ----

//---- ARB_map_buffer_alignment ----

//---- ARB_map_buffer_range ----

//---- ARB_multi_bind ----

//---- ARB_multi_draw_indirect ----

//---- ARB_occlusion_query2 ----

//---- ARB_pipeline_statistics_query ----

//---- ARB_program_interface_query ----

//---- ARB_provoking_vertex ----

//---- ARB_query_buffer_object ----

//---- ARB_robust_buffer_access_behavior ----

//---- ARB_robustness ----

TRANSGL_API_VAR
PFNGLGETGRAPHICSRESETSTATUSARBPROC
CoreGl_GetGraphicsResetStatusARB;

TRANSGL_API_VAR
PFNGLGETNTEXIMAGEARBPROC
CoreGl_GetnTexImageARB;

TRANSGL_API_VAR
PFNGLREADNPIXELSARBPROC
CoreGl_ReadnPixelsARB;

TRANSGL_API_VAR
PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC
CoreGl_GetnCompressedTexImageARB;

TRANSGL_API_VAR
PFNGLGETNUNIFORMFVARBPROC
CoreGl_GetnUniformfvARB;

TRANSGL_API_VAR
PFNGLGETNUNIFORMIVARBPROC
CoreGl_GetnUniformivARB;

TRANSGL_API_VAR
PFNGLGETNUNIFORMUIVARBPROC
CoreGl_GetnUniformuivARB;

TRANSGL_API_VAR
PFNGLGETNUNIFORMDVARBPROC
CoreGl_GetnUniformdvARB;

//---- ARB_robustness_isolation ----

//---- ARB_sample_shading ----

TRANSGL_API_VAR
PFNGLMINSAMPLESHADINGARBPROC
CoreGl_MinSampleShadingARB;

//---- ARB_sampler_objects ----

//---- ARB_seamless_cube_map ----

//---- ARB_seamless_cubemap_per_texture ----

//---- ARB_separate_shader_objects ----

//---- ARB_shader_atomic_counters ----

//---- ARB_shader_bit_encoding ----

//---- ARB_shader_draw_parameters ----

//---- ARB_shader_group_vote ----

//---- ARB_shader_image_load_store ----

//---- ARB_shader_image_size ----

//---- ARB_shader_precision ----

//---- ARB_shader_stencil_export ----

//---- ARB_shader_storage_buffer_object ----

//---- ARB_shader_subroutine ----

//---- ARB_shader_texture_image_samples ----

//---- ARB_shading_language_420pack ----

//---- ARB_shading_language_include ----

TRANSGL_API_VAR
PFNGLNAMEDSTRINGARBPROC
CoreGl_NamedStringARB;

TRANSGL_API_VAR
PFNGLDELETENAMEDSTRINGARBPROC
CoreGl_DeleteNamedStringARB;

TRANSGL_API_VAR
PFNGLCOMPILESHADERINCLUDEARBPROC
CoreGl_CompileShaderIncludeARB;

TRANSGL_API_VAR
PFNGLISNAMEDSTRINGARBPROC
CoreGl_IsNamedStringARB;

TRANSGL_API_VAR
PFNGLGETNAMEDSTRINGARBPROC
CoreGl_GetNamedStringARB;

TRANSGL_API_VAR
PFNGLGETNAMEDSTRINGIVARBPROC
CoreGl_GetNamedStringivARB;

//---- ARB_shading_language_packing ----

//---- ARB_sparse_buffer ----

TRANSGL_API_VAR
PFNGLBUFFERPAGECOMMITMENTARBPROC
CoreGl_BufferPageCommitmentARB;

TRANSGL_API_VAR
PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC
CoreGl_NamedBufferPageCommitmentEXT;

TRANSGL_API_VAR
PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC
CoreGl_NamedBufferPageCommitmentARB;

//---- ARB_sparse_texture ----

TRANSGL_API_VAR
PFNGLTEXPAGECOMMITMENTARBPROC
CoreGl_TexPageCommitmentARB;

//---- ARB_stencil_texturing ----

//---- ARB_sync ----

//---- ARB_tessellation_shader ----

//---- ARB_texture_barrier ----

//---- ARB_texture_buffer_object_rgb32 ----

//---- ARB_texture_buffer_range ----

//---- ARB_texture_compression_bptc ----

//---- ARB_texture_compression_rgtc ----

//---- ARB_texture_cube_map_array ----

//---- ARB_texture_gather ----

//---- ARB_texture_mirror_clamp_to_edge ----

//---- ARB_texture_multisample ----

//---- ARB_texture_query_levels ----

//---- ARB_texture_query_lod ----

//---- ARB_texture_rg ----

//---- ARB_texture_rgb10_a2ui ----

//---- ARB_texture_stencil8 ----

//---- ARB_texture_storage ----

//---- ARB_texture_storage_multisample ----

//---- ARB_texture_swizzle ----

//---- ARB_texture_view ----

//---- ARB_timer_query ----

//---- ARB_transform_feedback2 ----

//---- ARB_transform_feedback3 ----

//---- ARB_transform_feedback_instanced ----

//---- ARB_transform_feedback_overflow_query ----

//---- ARB_uniform_buffer_object ----

//---- ARB_vertex_array_bgra ----

//---- ARB_vertex_array_object ----

//---- ARB_vertex_attrib_64bit ----

//---- ARB_vertex_attrib_binding ----

//---- ARB_vertex_type_10f_11f_11f_rev ----

//---- ARB_vertex_type_2_10_10_10_rev ----

//---- ARB_viewport_array ----

//---- KHR_context_flush_control ----

//---- KHR_debug ----

//---- KHR_no_error ----

//---- KHR_robust_buffer_access_behavior ----

//---- KHR_robustness ----

//---- KHR_texture_compression_astc_hdr ----

//---- KHR_texture_compression_astc_ldr ----

//---- KHR_texture_compression_astc_sliced_3d ----

//----------------------------------------------------------------------------
