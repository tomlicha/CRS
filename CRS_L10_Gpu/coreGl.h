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

#ifndef TRANSGL_COREGL_H
#define TRANSGL_COREGL_H 1

// #include "TransGl/api.h"
//
// The preceding inclusion can be commented out in order to make this code
// independant from the TransProg library.
// In this case, the following settings are required.
// They may need some adjustments on some platforms.
//

#if !defined TRANSGL_API_H // TransProg library was not used here

#include "platformAdapter.h"

# if !defined TRANSGL_API_VAR
#   define TRANSGL_API_VAR // visibility range is current binary
# endif

# if !defined TRANSGL_API
#   define TRANSGL_API EXTERN_C_SYMBOL TRANSGL_API_VAR
# endif

#endif // not TRANSGL_API_H

//----------------------------------------------------------------------------

#ifndef __glcorearb_h_
#define __glcorearb_h_ 1

#ifdef __cplusplus
extern "C" {
#endif

/*
** Copyright (c) 2013-2015 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/
/*
** This header is generated from the Khronos OpenGL / OpenGL ES XML
** API Registry. The current version of the Registry, generator scripts
** used to make the header, and the header can be found at
**   http://www.opengl.org/registry/
**
** Khronos $Revision: 32155 $ on $Date: 2015-10-22 23:25:39 -0400 (Thu, 22 Oct 2015) $
*/

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

/* glcorearb.h is for use with OpenGL core profile implementations.
** It should should be placed in the same directory as gl.h and
** included as <GL/glcorearb.h>.
**
** glcorearb.h includes only APIs in the latest OpenGL core profile
** implementation together with APIs in newer ARB extensions which 
** can be supported by the core profile. It does not, and never will
** include functionality removed from the core profile, such as
** fixed-function vertex and fragment processing.
**
** Do not #include both <GL/glcorearb.h> and either of <GL/gl.h> or
** <GL/glext.h> in the same source file.
*/

/* Generated C header for:
 * API: gl
 * Profile: core
 * Versions considered: .*
 * Versions emitted: .*
 * Default extensions included: glcore
 * Additional extensions included: _nomatch_^
 * Extensions removed: _nomatch_^
 */

#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1
typedef void GLvoid;
typedef unsigned int GLenum;
typedef float GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef unsigned char GLubyte;
typedef void (APIENTRYP PFNGLCULLFACEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLFRONTFACEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLHINTPROC) (GLenum target, GLenum mode);
typedef void (APIENTRYP PFNGLLINEWIDTHPROC) (GLfloat width);
typedef void (APIENTRYP PFNGLPOINTSIZEPROC) (GLfloat size);
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC) (GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLSCISSORPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC) (GLenum buf);
typedef void (APIENTRYP PFNGLCLEARPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLCLEARCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC) (GLint s);
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC) (GLdouble depth);
typedef void (APIENTRYP PFNGLSTENCILMASKPROC) (GLuint mask);
typedef void (APIENTRYP PFNGLCOLORMASKPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFNGLDEPTHMASKPROC) (GLboolean flag);
typedef void (APIENTRYP PFNGLDISABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLENABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLFINISHPROC) (void);
typedef void (APIENTRYP PFNGLFLUSHPROC) (void);
typedef void (APIENTRYP PFNGLBLENDFUNCPROC) (GLenum sfactor, GLenum dfactor);
typedef void (APIENTRYP PFNGLLOGICOPPROC) (GLenum opcode);
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC) (GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILOPPROC) (GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC) (GLenum func);
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLREADBUFFERPROC) (GLenum src);
typedef void (APIENTRYP PFNGLREADPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC) (GLenum pname, GLboolean *data);
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC) (GLenum pname, GLdouble *data);
typedef GLenum (APIENTRYP PFNGLGETERRORPROC) (void);
typedef void (APIENTRYP PFNGLGETFLOATVPROC) (GLenum pname, GLfloat *data);
typedef void (APIENTRYP PFNGLGETINTEGERVPROC) (GLenum pname, GLint *data);
typedef const GLubyte *(APIENTRYP PFNGLGETSTRINGPROC) (GLenum name);
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC) (GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC) (GLenum target, GLint level, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC) (GLdouble near, GLdouble far);
typedef void (APIENTRYP PFNGLVIEWPORTPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glCullFace (GLenum mode);
GLAPI void APIENTRY glFrontFace (GLenum mode);
GLAPI void APIENTRY glHint (GLenum target, GLenum mode);
GLAPI void APIENTRY glLineWidth (GLfloat width);
GLAPI void APIENTRY glPointSize (GLfloat size);
GLAPI void APIENTRY glPolygonMode (GLenum face, GLenum mode);
GLAPI void APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glDrawBuffer (GLenum buf);
GLAPI void APIENTRY glClear (GLbitfield mask);
GLAPI void APIENTRY glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void APIENTRY glClearStencil (GLint s);
GLAPI void APIENTRY glClearDepth (GLdouble depth);
GLAPI void APIENTRY glStencilMask (GLuint mask);
GLAPI void APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI void APIENTRY glDepthMask (GLboolean flag);
GLAPI void APIENTRY glDisable (GLenum cap);
GLAPI void APIENTRY glEnable (GLenum cap);
GLAPI void APIENTRY glFinish (void);
GLAPI void APIENTRY glFlush (void);
GLAPI void APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor);
GLAPI void APIENTRY glLogicOp (GLenum opcode);
GLAPI void APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void APIENTRY glDepthFunc (GLenum func);
GLAPI void APIENTRY glPixelStoref (GLenum pname, GLfloat param);
GLAPI void APIENTRY glPixelStorei (GLenum pname, GLint param);
GLAPI void APIENTRY glReadBuffer (GLenum src);
GLAPI void APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLAPI void APIENTRY glGetBooleanv (GLenum pname, GLboolean *data);
GLAPI void APIENTRY glGetDoublev (GLenum pname, GLdouble *data);
GLAPI GLenum APIENTRY glGetError (void);
GLAPI void APIENTRY glGetFloatv (GLenum pname, GLfloat *data);
GLAPI void APIENTRY glGetIntegerv (GLenum pname, GLint *data);
GLAPI const GLubyte *APIENTRY glGetString (GLenum name);
GLAPI void APIENTRY glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI void APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI GLboolean APIENTRY glIsEnabled (GLenum cap);
GLAPI void APIENTRY glDepthRange (GLdouble near, GLdouble far);
GLAPI void APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
#endif
#endif /* GL_VERSION_1_0 */

#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1
typedef float GLclampf;
typedef double GLclampd;
#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_COLOR_BUFFER_BIT               0x00004000
#define GL_FALSE                          0
#define GL_TRUE                           1
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308
#define GL_NONE                           0
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_FRONT                          0x0404
#define GL_BACK                           0x0405
#define GL_LEFT                           0x0406
#define GL_RIGHT                          0x0407
#define GL_FRONT_AND_BACK                 0x0408
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_OUT_OF_MEMORY                  0x0505
#define GL_CW                             0x0900
#define GL_CCW                            0x0901
#define GL_POINT_SIZE                     0x0B11
#define GL_POINT_SIZE_RANGE               0x0B12
#define GL_POINT_SIZE_GRANULARITY         0x0B13
#define GL_LINE_SMOOTH                    0x0B20
#define GL_LINE_WIDTH                     0x0B21
#define GL_LINE_WIDTH_RANGE               0x0B22
#define GL_LINE_WIDTH_GRANULARITY         0x0B23
#define GL_POLYGON_MODE                   0x0B40
#define GL_POLYGON_SMOOTH                 0x0B41
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_FRONT_FACE                     0x0B46
#define GL_DEPTH_RANGE                    0x0B70
#define GL_DEPTH_TEST                     0x0B71
#define GL_DEPTH_WRITEMASK                0x0B72
#define GL_DEPTH_CLEAR_VALUE              0x0B73
#define GL_DEPTH_FUNC                     0x0B74
#define GL_STENCIL_TEST                   0x0B90
#define GL_STENCIL_CLEAR_VALUE            0x0B91
#define GL_STENCIL_FUNC                   0x0B92
#define GL_STENCIL_VALUE_MASK             0x0B93
#define GL_STENCIL_FAIL                   0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#define GL_STENCIL_REF                    0x0B97
#define GL_STENCIL_WRITEMASK              0x0B98
#define GL_VIEWPORT                       0x0BA2
#define GL_DITHER                         0x0BD0
#define GL_BLEND_DST                      0x0BE0
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLEND                          0x0BE2
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_DRAW_BUFFER                    0x0C01
#define GL_READ_BUFFER                    0x0C02
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
#define GL_COLOR_CLEAR_VALUE              0x0C22
#define GL_COLOR_WRITEMASK                0x0C23
#define GL_DOUBLEBUFFER                   0x0C32
#define GL_STEREO                         0x0C33
#define GL_LINE_SMOOTH_HINT               0x0C52
#define GL_POLYGON_SMOOTH_HINT            0x0C53
#define GL_UNPACK_SWAP_BYTES              0x0CF0
#define GL_UNPACK_LSB_FIRST               0x0CF1
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_PACK_SWAP_BYTES                0x0D00
#define GL_PACK_LSB_FIRST                 0x0D01
#define GL_PACK_ROW_LENGTH                0x0D02
#define GL_PACK_SKIP_ROWS                 0x0D03
#define GL_PACK_SKIP_PIXELS               0x0D04
#define GL_PACK_ALIGNMENT                 0x0D05
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_MAX_VIEWPORT_DIMS              0x0D3A
#define GL_SUBPIXEL_BITS                  0x0D50
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_POLYGON_OFFSET_UNITS           0x2A00
#define GL_POLYGON_OFFSET_POINT           0x2A01
#define GL_POLYGON_OFFSET_LINE            0x2A02
#define GL_POLYGON_OFFSET_FILL            0x8037
#define GL_POLYGON_OFFSET_FACTOR          0x8038
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_TEXTURE_RED_SIZE               0x805C
#define GL_TEXTURE_GREEN_SIZE             0x805D
#define GL_TEXTURE_BLUE_SIZE              0x805E
#define GL_TEXTURE_ALPHA_SIZE             0x805F
#define GL_DONT_CARE                      0x1100
#define GL_FASTEST                        0x1101
#define GL_NICEST                         0x1102
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_DOUBLE                         0x140A
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_CLEAR                          0x1500
#define GL_AND                            0x1501
#define GL_AND_REVERSE                    0x1502
#define GL_COPY                           0x1503
#define GL_AND_INVERTED                   0x1504
#define GL_NOOP                           0x1505
#define GL_XOR                            0x1506
#define GL_OR                             0x1507
#define GL_NOR                            0x1508
#define GL_EQUIV                          0x1509
#define GL_INVERT                         0x150A
#define GL_OR_REVERSE                     0x150B
#define GL_COPY_INVERTED                  0x150C
#define GL_OR_INVERTED                    0x150D
#define GL_NAND                           0x150E
#define GL_SET                            0x150F
#define GL_TEXTURE                        0x1702
#define GL_COLOR                          0x1800
#define GL_DEPTH                          0x1801
#define GL_STENCIL                        0x1802
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02
#define GL_KEEP                           0x1E00
#define GL_REPLACE                        0x1E01
#define GL_INCR                           0x1E02
#define GL_DECR                           0x1E03
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064
#define GL_REPEAT                         0x2901
#define GL_R3_G3_B2                       0x2A10
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB8                           0x8051
#define GL_RGB10                          0x8052
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGB5_A1                        0x8057
#define GL_RGBA8                          0x8058
#define GL_RGB10_A2                       0x8059
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_VERTEX_ARRAY                   0x8074
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC) (GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLGETPOINTERVPROC) (GLenum pname, void **params);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC) (GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC) (GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC) (GLsizei n, const GLuint *textures);
typedef void (APIENTRYP PFNGLGENTEXTURESPROC) (GLsizei n, GLuint *textures);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC) (GLuint texture);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count);
GLAPI void APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices);
GLAPI void APIENTRY glGetPointerv (GLenum pname, void **params);
GLAPI void APIENTRY glPolygonOffset (GLfloat factor, GLfloat units);
GLAPI void APIENTRY glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void APIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void APIENTRY glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glBindTexture (GLenum target, GLuint texture);
GLAPI void APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures);
GLAPI void APIENTRY glGenTextures (GLsizei n, GLuint *textures);
GLAPI GLboolean APIENTRY glIsTexture (GLuint texture);
#endif
#endif /* GL_VERSION_1_1 */

#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLAPI void APIENTRY glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif
#endif /* GL_VERSION_1_2 */

#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC) (GLfloat value, GLboolean invert);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint level, void *img);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glActiveTexture (GLenum texture);
GLAPI void APIENTRY glSampleCoverage (GLfloat value, GLboolean invert);
GLAPI void APIENTRY glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glGetCompressedTexImage (GLenum target, GLint level, void *img);
#endif
#endif /* GL_VERSION_1_3 */

#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_FUNC_ADD                       0x8006
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLBLENDCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI void APIENTRY glMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
GLAPI void APIENTRY glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
GLAPI void APIENTRY glPointParameterf (GLenum pname, GLfloat param);
GLAPI void APIENTRY glPointParameterfv (GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glPointParameteri (GLenum pname, GLint param);
GLAPI void APIENTRY glPointParameteriv (GLenum pname, const GLint *params);
GLAPI void APIENTRY glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void APIENTRY glBlendEquation (GLenum mode);
#endif
#endif /* GL_VERSION_1_4 */

#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
#include <stddef.h>
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#define GL_SRC1_ALPHA                     0x8589
typedef void (APIENTRYP PFNGLGENQUERIESPROC) (GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint *ids);
typedef GLboolean (APIENTRYP PFNGLISQUERYPROC) (GLuint id);
typedef void (APIENTRYP PFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
typedef void (APIENTRYP PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void *(APIENTRYP PFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, void **params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glGenQueries (GLsizei n, GLuint *ids);
GLAPI void APIENTRY glDeleteQueries (GLsizei n, const GLuint *ids);
GLAPI GLboolean APIENTRY glIsQuery (GLuint id);
GLAPI void APIENTRY glBeginQuery (GLenum target, GLuint id);
GLAPI void APIENTRY glEndQuery (GLenum target);
GLAPI void APIENTRY glGetQueryiv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params);
GLAPI void APIENTRY glBindBuffer (GLenum target, GLuint buffer);
GLAPI void APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers);
GLAPI void APIENTRY glGenBuffers (GLsizei n, GLuint *buffers);
GLAPI GLboolean APIENTRY glIsBuffer (GLuint buffer);
GLAPI void APIENTRY glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void APIENTRY glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void *APIENTRY glMapBuffer (GLenum target, GLenum access);
GLAPI GLboolean APIENTRY glUnmapBuffer (GLenum target);
GLAPI void APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetBufferPointerv (GLenum target, GLenum pname, void **params);
#endif
#endif /* GL_VERSION_1_5 */

#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
typedef char GLchar;
typedef short GLshort;
typedef signed char GLbyte;
typedef unsigned short GLushort;
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC) (GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
typedef void (APIENTRYP PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar *name);
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC) (void);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC) (GLenum type);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat *params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, void **pointer);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC) (GLuint program);
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glDrawBuffers (GLsizei n, const GLenum *bufs);
GLAPI void APIENTRY glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLAPI void APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask);
GLAPI void APIENTRY glAttachShader (GLuint program, GLuint shader);
GLAPI void APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar *name);
GLAPI void APIENTRY glCompileShader (GLuint shader);
GLAPI GLuint APIENTRY glCreateProgram (void);
GLAPI GLuint APIENTRY glCreateShader (GLenum type);
GLAPI void APIENTRY glDeleteProgram (GLuint program);
GLAPI void APIENTRY glDeleteShader (GLuint shader);
GLAPI void APIENTRY glDetachShader (GLuint program, GLuint shader);
GLAPI void APIENTRY glDisableVertexAttribArray (GLuint index);
GLAPI void APIENTRY glEnableVertexAttribArray (GLuint index);
GLAPI void APIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLAPI GLint APIENTRY glGetAttribLocation (GLuint program, const GLchar *name);
GLAPI void APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLAPI GLint APIENTRY glGetUniformLocation (GLuint program, const GLchar *name);
GLAPI void APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat *params);
GLAPI void APIENTRY glGetUniformiv (GLuint program, GLint location, GLint *params);
GLAPI void APIENTRY glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params);
GLAPI void APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer);
GLAPI GLboolean APIENTRY glIsProgram (GLuint program);
GLAPI GLboolean APIENTRY glIsShader (GLuint shader);
GLAPI void APIENTRY glLinkProgram (GLuint program);
GLAPI void APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GLAPI void APIENTRY glUseProgram (GLuint program);
GLAPI void APIENTRY glUniform1f (GLint location, GLfloat v0);
GLAPI void APIENTRY glUniform2f (GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glUniform1i (GLint location, GLint v0);
GLAPI void APIENTRY glUniform2i (GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glUniform3i (GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glValidateProgram (GLuint program);
GLAPI void APIENTRY glVertexAttrib1d (GLuint index, GLdouble x);
GLAPI void APIENTRY glVertexAttrib1dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib1f (GLuint index, GLfloat x);
GLAPI void APIENTRY glVertexAttrib1fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib1s (GLuint index, GLshort x);
GLAPI void APIENTRY glVertexAttrib1sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y);
GLAPI void APIENTRY glVertexAttrib2dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
GLAPI void APIENTRY glVertexAttrib2fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib2s (GLuint index, GLshort x, GLshort y);
GLAPI void APIENTRY glVertexAttrib2sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glVertexAttrib3dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glVertexAttrib3fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void APIENTRY glVertexAttrib3sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4Nbv (GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttrib4Niv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttrib4Nsv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void APIENTRY glVertexAttrib4Nubv (GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttrib4Nuiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttrib4Nusv (GLuint index, const GLushort *v);
GLAPI void APIENTRY glVertexAttrib4bv (GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glVertexAttrib4dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void APIENTRY glVertexAttrib4fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib4iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void APIENTRY glVertexAttrib4sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4ubv (GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttrib4uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttrib4usv (GLuint index, const GLushort *v);
GLAPI void APIENTRY glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
#endif
#endif /* GL_VERSION_2_0 */

#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#endif /* GL_VERSION_2_1 */

#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
typedef unsigned short GLhalf;
#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
#define GL_DEPTH_COMPONENT32F             0x8CAC
#define GL_DEPTH32F_STENCIL8              0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT            0x8218
#define GL_FRAMEBUFFER_UNDEFINED          0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#define GL_MAX_RENDERBUFFER_SIZE          0x84E8
#define GL_DEPTH_STENCIL                  0x84F9
#define GL_UNSIGNED_INT_24_8              0x84FA
#define GL_DEPTH24_STENCIL8               0x88F0
#define GL_TEXTURE_STENCIL_SIZE           0x88F1
#define GL_TEXTURE_RED_TYPE               0x8C10
#define GL_TEXTURE_GREEN_TYPE             0x8C11
#define GL_TEXTURE_BLUE_TYPE              0x8C12
#define GL_TEXTURE_ALPHA_TYPE             0x8C13
#define GL_TEXTURE_DEPTH_TYPE             0x8C16
#define GL_UNSIGNED_NORMALIZED            0x8C17
#define GL_FRAMEBUFFER_BINDING            0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#define GL_RENDERBUFFER_BINDING           0x8CA7
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#define GL_RENDERBUFFER_SAMPLES           0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED        0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_COLOR_ATTACHMENT16             0x8CF0
#define GL_COLOR_ATTACHMENT17             0x8CF1
#define GL_COLOR_ATTACHMENT18             0x8CF2
#define GL_COLOR_ATTACHMENT19             0x8CF3
#define GL_COLOR_ATTACHMENT20             0x8CF4
#define GL_COLOR_ATTACHMENT21             0x8CF5
#define GL_COLOR_ATTACHMENT22             0x8CF6
#define GL_COLOR_ATTACHMENT23             0x8CF7
#define GL_COLOR_ATTACHMENT24             0x8CF8
#define GL_COLOR_ATTACHMENT25             0x8CF9
#define GL_COLOR_ATTACHMENT26             0x8CFA
#define GL_COLOR_ATTACHMENT27             0x8CFB
#define GL_COLOR_ATTACHMENT28             0x8CFC
#define GL_COLOR_ATTACHMENT29             0x8CFD
#define GL_COLOR_ATTACHMENT30             0x8CFE
#define GL_COLOR_ATTACHMENT31             0x8CFF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_STENCIL_ATTACHMENT             0x8D20
#define GL_FRAMEBUFFER                    0x8D40
#define GL_RENDERBUFFER                   0x8D41
#define GL_RENDERBUFFER_WIDTH             0x8D42
#define GL_RENDERBUFFER_HEIGHT            0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#define GL_STENCIL_INDEX1                 0x8D46
#define GL_STENCIL_INDEX4                 0x8D47
#define GL_STENCIL_INDEX8                 0x8D48
#define GL_STENCIL_INDEX16                0x8D49
#define GL_RENDERBUFFER_RED_SIZE          0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES                    0x8D57
#define GL_FRAMEBUFFER_SRGB               0x8DB9
#define GL_HALF_FLOAT                     0x140B
#define GL_MAP_READ_BIT                   0x0001
#define GL_MAP_WRITE_BIT                  0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT       0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT      0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT         0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT         0x0020
#define GL_COMPRESSED_RED_RGTC1           0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1    0x8DBC
#define GL_COMPRESSED_RG_RGTC2            0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2     0x8DBE
#define GL_RG                             0x8227
#define GL_RG_INTEGER                     0x8228
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_VERTEX_ARRAY_BINDING           0x85B5
typedef void (APIENTRYP PFNGLCOLORMASKIPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC) (GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC) (GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFNGLENABLEIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEIPROC) (GLenum target, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC) (GLenum primitiveMode);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC) (GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC) (GLenum target, GLenum clamp);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC) (GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC) (void);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC) (GLuint index, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC) (GLuint index, GLint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC) (GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC) (GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC) (GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC) (GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC) (GLuint program, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC) (GLuint program, GLuint color, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC) (GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC) (GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC) (GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC) (GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte *(APIENTRYP PFNGLGETSTRINGIPROC) (GLenum name, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC) (GLuint renderbuffer);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC) (GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC) (GLsizei n, const GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC) (GLuint framebuffer);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC) (GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint *framebuffers);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC) (GLenum target);
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void *(APIENTRYP PFNGLMAPBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC) (GLuint array);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint *arrays);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC) (GLuint array);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI void APIENTRY glGetBooleani_v (GLenum target, GLuint index, GLboolean *data);
GLAPI void APIENTRY glGetIntegeri_v (GLenum target, GLuint index, GLint *data);
GLAPI void APIENTRY glEnablei (GLenum target, GLuint index);
GLAPI void APIENTRY glDisablei (GLenum target, GLuint index);
GLAPI GLboolean APIENTRY glIsEnabledi (GLenum target, GLuint index);
GLAPI void APIENTRY glBeginTransformFeedback (GLenum primitiveMode);
GLAPI void APIENTRY glEndTransformFeedback (void);
GLAPI void APIENTRY glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glBindBufferBase (GLenum target, GLuint index, GLuint buffer);
GLAPI void APIENTRY glTransformFeedbackVaryings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
GLAPI void APIENTRY glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glClampColor (GLenum target, GLenum clamp);
GLAPI void APIENTRY glBeginConditionalRender (GLuint id, GLenum mode);
GLAPI void APIENTRY glEndConditionalRender (void);
GLAPI void APIENTRY glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params);
GLAPI void APIENTRY glVertexAttribI1i (GLuint index, GLint x);
GLAPI void APIENTRY glVertexAttribI2i (GLuint index, GLint x, GLint y);
GLAPI void APIENTRY glVertexAttribI3i (GLuint index, GLint x, GLint y, GLint z);
GLAPI void APIENTRY glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void APIENTRY glVertexAttribI1ui (GLuint index, GLuint x);
GLAPI void APIENTRY glVertexAttribI2ui (GLuint index, GLuint x, GLuint y);
GLAPI void APIENTRY glVertexAttribI3ui (GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI void APIENTRY glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void APIENTRY glVertexAttribI1iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI2iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI3iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI4iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI1uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI2uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI3uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI4uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI4bv (GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttribI4sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttribI4ubv (GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttribI4usv (GLuint index, const GLushort *v);
GLAPI void APIENTRY glGetUniformuiv (GLuint program, GLint location, GLuint *params);
GLAPI void APIENTRY glBindFragDataLocation (GLuint program, GLuint color, const GLchar *name);
GLAPI GLint APIENTRY glGetFragDataLocation (GLuint program, const GLchar *name);
GLAPI void APIENTRY glUniform1ui (GLint location, GLuint v0);
GLAPI void APIENTRY glUniform2ui (GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glUniform1uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform2uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform3uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform4uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glTexParameterIiv (GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexParameterIuiv (GLenum target, GLenum pname, const GLuint *params);
GLAPI void APIENTRY glGetTexParameterIiv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTexParameterIuiv (GLenum target, GLenum pname, GLuint *params);
GLAPI void APIENTRY glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void APIENTRY glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void APIENTRY glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void APIENTRY glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI const GLubyte *APIENTRY glGetStringi (GLenum name, GLuint index);
GLAPI GLboolean APIENTRY glIsRenderbuffer (GLuint renderbuffer);
GLAPI void APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer);
GLAPI void APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers);
GLAPI void APIENTRY glGenRenderbuffers (GLsizei n, GLuint *renderbuffers);
GLAPI void APIENTRY glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI GLboolean APIENTRY glIsFramebuffer (GLuint framebuffer);
GLAPI void APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer);
GLAPI void APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers);
GLAPI void APIENTRY glGenFramebuffers (GLsizei n, GLuint *framebuffers);
GLAPI GLenum APIENTRY glCheckFramebufferStatus (GLenum target);
GLAPI void APIENTRY glFramebufferTexture1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTexture3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void APIENTRY glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLAPI void APIENTRY glGenerateMipmap (GLenum target);
GLAPI void APIENTRY glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI void APIENTRY glRenderbufferStorageMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void *APIENTRY glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void APIENTRY glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glBindVertexArray (GLuint array);
GLAPI void APIENTRY glDeleteVertexArrays (GLsizei n, const GLuint *arrays);
GLAPI void APIENTRY glGenVertexArrays (GLsizei n, GLuint *arrays);
GLAPI GLboolean APIENTRY glIsVertexArray (GLuint array);
#endif
#endif /* GL_VERSION_3_0 */

#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1
#define GL_SAMPLER_2D_RECT                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW         0x8B64
#define GL_SAMPLER_BUFFER                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT            0x8DCD
#define GL_INT_SAMPLER_BUFFER             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER    0x8DD8
#define GL_TEXTURE_BUFFER                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
#define GL_SIGNED_NORMALIZED              0x8F9C
#define GL_PRIMITIVE_RESTART              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX        0x8F9E
#define GL_COPY_READ_BUFFER               0x8F36
#define GL_COPY_WRITE_BUFFER              0x8F37
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS      0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS    0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS          0x8A36
#define GL_UNIFORM_TYPE                   0x8A37
#define GL_UNIFORM_SIZE                   0x8A38
#define GL_UNIFORM_NAME_LENGTH            0x8A39
#define GL_UNIFORM_BLOCK_INDEX            0x8A3A
#define GL_UNIFORM_OFFSET                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX                  0xFFFFFFFFu
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
typedef void (APIENTRYP PFNGLTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint index);
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC) (GLuint program, const GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstanced (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLAPI void APIENTRY glDrawElementsInstanced (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
GLAPI void APIENTRY glTexBuffer (GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glPrimitiveRestartIndex (GLuint index);
GLAPI void APIENTRY glCopyBufferSubData (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void APIENTRY glGetUniformIndices (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
GLAPI void APIENTRY glGetActiveUniformsiv (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetActiveUniformName (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLAPI GLuint APIENTRY glGetUniformBlockIndex (GLuint program, const GLchar *uniformBlockName);
GLAPI void APIENTRY glGetActiveUniformBlockiv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetActiveUniformBlockName (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
GLAPI void APIENTRY glUniformBlockBinding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#endif
#endif /* GL_VERSION_3_1 */

#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1
typedef struct __GLsync *GLsync;
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
typedef uint64_t GLuint64;
typedef int64_t GLint64;
#define GL_CONTEXT_CORE_PROFILE_BIT       0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D
#define GL_PROGRAM_POINT_SIZE             0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_GEOMETRY_VERTICES_OUT          0x8916
#define GL_GEOMETRY_INPUT_TYPE            0x8917
#define GL_GEOMETRY_OUTPUT_TYPE           0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES   0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS   0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS  0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS  0x9125
#define GL_CONTEXT_PROFILE_MASK           0x9126
#define GL_DEPTH_CLAMP                    0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION        0x8E4D
#define GL_LAST_VERTEX_CONVENTION         0x8E4E
#define GL_PROVOKING_VERTEX               0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS      0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT        0x9111
#define GL_OBJECT_TYPE                    0x9112
#define GL_SYNC_CONDITION                 0x9113
#define GL_SYNC_STATUS                    0x9114
#define GL_SYNC_FLAGS                     0x9115
#define GL_SYNC_FENCE                     0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE     0x9117
#define GL_UNSIGNALED                     0x9118
#define GL_SIGNALED                       0x9119
#define GL_ALREADY_SIGNALED               0x911A
#define GL_TIMEOUT_EXPIRED                0x911B
#define GL_CONDITION_SATISFIED            0x911C
#define GL_WAIT_FAILED                    0x911D
#define GL_TIMEOUT_IGNORED                0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT        0x00000001
#define GL_SAMPLE_POSITION                0x8E50
#define GL_SAMPLE_MASK                    0x8E51
#define GL_SAMPLE_MASK_VALUE              0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS          0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES                0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC) (GLenum mode);
typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC) (GLenum condition, GLbitfield flags);
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC) (GLsync sync);
typedef void (APIENTRYP PFNGLDELETESYNCPROC) (GLsync sync);
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC) (GLenum pname, GLint64 *data);
typedef void (APIENTRYP PFNGLGETSYNCIVPROC) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC) (GLenum target, GLuint index, GLint64 *data);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC) (GLenum target, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC) (GLenum pname, GLuint index, GLfloat *val);
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC) (GLuint maskNumber, GLbitfield mask);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawElementsBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI void APIENTRY glDrawRangeElementsBaseVertex (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
GLAPI void APIENTRY glMultiDrawElementsBaseVertex (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
GLAPI void APIENTRY glProvokingVertex (GLenum mode);
GLAPI GLsync APIENTRY glFenceSync (GLenum condition, GLbitfield flags);
GLAPI GLboolean APIENTRY glIsSync (GLsync sync);
GLAPI void APIENTRY glDeleteSync (GLsync sync);
GLAPI GLenum APIENTRY glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void APIENTRY glWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void APIENTRY glGetInteger64v (GLenum pname, GLint64 *data);
GLAPI void APIENTRY glGetSynciv (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
GLAPI void APIENTRY glGetInteger64i_v (GLenum target, GLuint index, GLint64 *data);
GLAPI void APIENTRY glGetBufferParameteri64v (GLenum target, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glFramebufferTexture (GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glTexImage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTexImage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glGetMultisamplefv (GLenum pname, GLuint index, GLfloat *val);
GLAPI void APIENTRY glSampleMaski (GLuint maskNumber, GLbitfield mask);
#endif
#endif /* GL_VERSION_3_2 */

#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR    0x88FE
#define GL_SRC1_COLOR                     0x88F9
#define GL_ONE_MINUS_SRC1_COLOR           0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA           0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS   0x88FC
#define GL_ANY_SAMPLES_PASSED             0x8C2F
#define GL_SAMPLER_BINDING                0x8919
#define GL_RGB10_A2UI                     0x906F
#define GL_TEXTURE_SWIZZLE_R              0x8E42
#define GL_TEXTURE_SWIZZLE_G              0x8E43
#define GL_TEXTURE_SWIZZLE_B              0x8E44
#define GL_TEXTURE_SWIZZLE_A              0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA           0x8E46
#define GL_TIME_ELAPSED                   0x88BF
#define GL_TIMESTAMP                      0x8E28
#define GL_INT_2_10_10_10_REV             0x8D9F
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC) (GLsizei count, GLuint *samplers);
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC) (GLsizei count, const GLuint *samplers);
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC) (GLuint sampler);
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC) (GLuint unit, GLuint sampler);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC) (GLuint sampler, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC) (GLuint sampler, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, const GLuint *param);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC) (GLuint id, GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC) (GLuint id, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC) (GLuint id, GLenum pname, GLuint64 *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC) (GLuint index, GLuint divisor);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBindFragDataLocationIndexed (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
GLAPI GLint APIENTRY glGetFragDataIndex (GLuint program, const GLchar *name);
GLAPI void APIENTRY glGenSamplers (GLsizei count, GLuint *samplers);
GLAPI void APIENTRY glDeleteSamplers (GLsizei count, const GLuint *samplers);
GLAPI GLboolean APIENTRY glIsSampler (GLuint sampler);
GLAPI void APIENTRY glBindSampler (GLuint unit, GLuint sampler);
GLAPI void APIENTRY glSamplerParameteri (GLuint sampler, GLenum pname, GLint param);
GLAPI void APIENTRY glSamplerParameteriv (GLuint sampler, GLenum pname, const GLint *param);
GLAPI void APIENTRY glSamplerParameterf (GLuint sampler, GLenum pname, GLfloat param);
GLAPI void APIENTRY glSamplerParameterfv (GLuint sampler, GLenum pname, const GLfloat *param);
GLAPI void APIENTRY glSamplerParameterIiv (GLuint sampler, GLenum pname, const GLint *param);
GLAPI void APIENTRY glSamplerParameterIuiv (GLuint sampler, GLenum pname, const GLuint *param);
GLAPI void APIENTRY glGetSamplerParameteriv (GLuint sampler, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetSamplerParameterIiv (GLuint sampler, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetSamplerParameterfv (GLuint sampler, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetSamplerParameterIuiv (GLuint sampler, GLenum pname, GLuint *params);
GLAPI void APIENTRY glQueryCounter (GLuint id, GLenum target);
GLAPI void APIENTRY glGetQueryObjecti64v (GLuint id, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glGetQueryObjectui64v (GLuint id, GLenum pname, GLuint64 *params);
GLAPI void APIENTRY glVertexAttribDivisor (GLuint index, GLuint divisor);
GLAPI void APIENTRY glVertexAttribP1ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP1uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP2ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP2uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP3ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP3uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP4ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP4uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
#endif
#endif /* GL_VERSION_3_3 */

#ifndef GL_VERSION_4_0
#define GL_VERSION_4_0 1
#define GL_SAMPLE_SHADING                 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE       0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY         0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY   0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY         0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW  0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY     0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_DRAW_INDIRECT_BUFFER           0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING   0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS    0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS             0x8E71
#define GL_DOUBLE_VEC2                    0x8FFC
#define GL_DOUBLE_VEC3                    0x8FFD
#define GL_DOUBLE_VEC4                    0x8FFE
#define GL_DOUBLE_MAT2                    0x8F46
#define GL_DOUBLE_MAT3                    0x8F47
#define GL_DOUBLE_MAT4                    0x8F48
#define GL_DOUBLE_MAT2x3                  0x8F49
#define GL_DOUBLE_MAT2x4                  0x8F4A
#define GL_DOUBLE_MAT3x2                  0x8F4B
#define GL_DOUBLE_MAT3x4                  0x8F4C
#define GL_DOUBLE_MAT4x2                  0x8F4D
#define GL_DOUBLE_MAT4x3                  0x8F4E
#define GL_ACTIVE_SUBROUTINES             0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS     0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH   0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES                0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES     0x8E4A
#define GL_COMPATIBLE_SUBROUTINES         0x8E4B
#define GL_PATCHES                        0x000E
#define GL_PATCH_VERTICES                 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL      0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL      0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES   0x8E75
#define GL_TESS_GEN_MODE                  0x8E76
#define GL_TESS_GEN_SPACING               0x8E77
#define GL_TESS_GEN_VERTEX_ORDER          0x8E78
#define GL_TESS_GEN_POINT_MODE            0x8E79
#define GL_ISOLINES                       0x8E7A
#define GL_FRACTIONAL_ODD                 0x8E7B
#define GL_FRACTIONAL_EVEN                0x8E7C
#define GL_MAX_PATCH_VERTICES             0x8E7D
#define GL_MAX_TESS_GEN_LEVEL             0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS      0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER         0x8E87
#define GL_TESS_CONTROL_SHADER            0x8E88
#define GL_TRANSFORM_FEEDBACK             0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING     0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC) (GLfloat value);
typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect);
typedef void (APIENTRYP PFNGLUNIFORM1DPROC) (GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLUNIFORM2DPROC) (GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLUNIFORM3DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLUNIFORM4DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC) (GLuint program, GLint location, GLdouble *params);
typedef GLint (APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) (GLuint program, GLenum shadertype, const GLchar *name);
typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC) (GLuint program, GLenum shadertype, const GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC) (GLenum shadertype, GLsizei count, const GLuint *indices);
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC) (GLenum shadertype, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC) (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC) (GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC) (GLenum pname, const GLfloat *values);
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC) (GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC) (GLuint id);
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC) (GLenum mode, GLuint id);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) (GLenum mode, GLuint id, GLuint stream);
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC) (GLenum target, GLuint index, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC) (GLenum target, GLuint index, GLenum pname, GLint *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMinSampleShading (GLfloat value);
GLAPI void APIENTRY glBlendEquationi (GLuint buf, GLenum mode);
GLAPI void APIENTRY glBlendEquationSeparatei (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glBlendFunci (GLuint buf, GLenum src, GLenum dst);
GLAPI void APIENTRY glBlendFuncSeparatei (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLAPI void APIENTRY glDrawArraysIndirect (GLenum mode, const void *indirect);
GLAPI void APIENTRY glDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect);
GLAPI void APIENTRY glUniform1d (GLint location, GLdouble x);
GLAPI void APIENTRY glUniform2d (GLint location, GLdouble x, GLdouble y);
GLAPI void APIENTRY glUniform3d (GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glUniform4d (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glUniform1dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform2dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform3dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform4dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glGetUniformdv (GLuint program, GLint location, GLdouble *params);
GLAPI GLint APIENTRY glGetSubroutineUniformLocation (GLuint program, GLenum shadertype, const GLchar *name);
GLAPI GLuint APIENTRY glGetSubroutineIndex (GLuint program, GLenum shadertype, const GLchar *name);
GLAPI void APIENTRY glGetActiveSubroutineUniformiv (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
GLAPI void APIENTRY glGetActiveSubroutineUniformName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glGetActiveSubroutineName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glUniformSubroutinesuiv (GLenum shadertype, GLsizei count, const GLuint *indices);
GLAPI void APIENTRY glGetUniformSubroutineuiv (GLenum shadertype, GLint location, GLuint *params);
GLAPI void APIENTRY glGetProgramStageiv (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
GLAPI void APIENTRY glPatchParameteri (GLenum pname, GLint value);
GLAPI void APIENTRY glPatchParameterfv (GLenum pname, const GLfloat *values);
GLAPI void APIENTRY glBindTransformFeedback (GLenum target, GLuint id);
GLAPI void APIENTRY glDeleteTransformFeedbacks (GLsizei n, const GLuint *ids);
GLAPI void APIENTRY glGenTransformFeedbacks (GLsizei n, GLuint *ids);
GLAPI GLboolean APIENTRY glIsTransformFeedback (GLuint id);
GLAPI void APIENTRY glPauseTransformFeedback (void);
GLAPI void APIENTRY glResumeTransformFeedback (void);
GLAPI void APIENTRY glDrawTransformFeedback (GLenum mode, GLuint id);
GLAPI void APIENTRY glDrawTransformFeedbackStream (GLenum mode, GLuint id, GLuint stream);
GLAPI void APIENTRY glBeginQueryIndexed (GLenum target, GLuint index, GLuint id);
GLAPI void APIENTRY glEndQueryIndexed (GLenum target, GLuint index);
GLAPI void APIENTRY glGetQueryIndexediv (GLenum target, GLuint index, GLenum pname, GLint *params);
#endif
#endif /* GL_VERSION_4_0 */

#ifndef GL_VERSION_4_1
#define GL_VERSION_4_1 1
#define GL_FIXED                          0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT                      0x8DF0
#define GL_MEDIUM_FLOAT                   0x8DF1
#define GL_HIGH_FLOAT                     0x8DF2
#define GL_LOW_INT                        0x8DF3
#define GL_MEDIUM_INT                     0x8DF4
#define GL_HIGH_INT                       0x8DF5
#define GL_SHADER_COMPILER                0x8DFA
#define GL_SHADER_BINARY_FORMATS          0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS      0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS     0x8DFB
#define GL_MAX_VARYING_VECTORS            0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS   0x8DFD
#define GL_RGB565                         0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH          0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS     0x87FE
#define GL_PROGRAM_BINARY_FORMATS         0x87FF
#define GL_VERTEX_SHADER_BIT              0x00000001
#define GL_FRAGMENT_SHADER_BIT            0x00000002
#define GL_GEOMETRY_SHADER_BIT            0x00000004
#define GL_TESS_CONTROL_SHADER_BIT        0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT     0x00000010
#define GL_ALL_SHADER_BITS                0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE              0x8258
#define GL_ACTIVE_PROGRAM                 0x8259
#define GL_PROGRAM_PIPELINE_BINDING       0x825A
#define GL_MAX_VIEWPORTS                  0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS         0x825C
#define GL_VIEWPORT_BOUNDS_RANGE          0x825D
#define GL_LAYER_PROVOKING_VERTEX         0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX               0x8260
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC) (void);
typedef void (APIENTRYP PFNGLSHADERBINARYPROC) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC) (GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC) (GLfloat d);
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC) (GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC) (GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC) (GLuint pipeline, GLuint program);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC) (GLenum type, GLsizei count, const GLchar *const*strings);
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC) (GLsizei n, const GLuint *pipelines);
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC) (GLuint pipeline, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC) (GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC) (GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC) (GLuint program, GLint location, GLdouble v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC) (GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC) (GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC) (GLuint first, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC) (GLuint first, GLsizei count, const GLint *v);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC) (GLuint first, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC) (GLuint index, GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC) (GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC) (GLenum target, GLuint index, GLdouble *data);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glReleaseShaderCompiler (void);
GLAPI void APIENTRY glShaderBinary (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
GLAPI void APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GLAPI void APIENTRY glDepthRangef (GLfloat n, GLfloat f);
GLAPI void APIENTRY glClearDepthf (GLfloat d);
GLAPI void APIENTRY glGetProgramBinary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
GLAPI void APIENTRY glProgramBinary (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
GLAPI void APIENTRY glProgramParameteri (GLuint program, GLenum pname, GLint value);
GLAPI void APIENTRY glUseProgramStages (GLuint pipeline, GLbitfield stages, GLuint program);
GLAPI void APIENTRY glActiveShaderProgram (GLuint pipeline, GLuint program);
GLAPI GLuint APIENTRY glCreateShaderProgramv (GLenum type, GLsizei count, const GLchar *const*strings);
GLAPI void APIENTRY glBindProgramPipeline (GLuint pipeline);
GLAPI void APIENTRY glDeleteProgramPipelines (GLsizei n, const GLuint *pipelines);
GLAPI void APIENTRY glGenProgramPipelines (GLsizei n, GLuint *pipelines);
GLAPI GLboolean APIENTRY glIsProgramPipeline (GLuint pipeline);
GLAPI void APIENTRY glGetProgramPipelineiv (GLuint pipeline, GLenum pname, GLint *params);
GLAPI void APIENTRY glProgramUniform1i (GLuint program, GLint location, GLint v0);
GLAPI void APIENTRY glProgramUniform1iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform1f (GLuint program, GLint location, GLfloat v0);
GLAPI void APIENTRY glProgramUniform1fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform1d (GLuint program, GLint location, GLdouble v0);
GLAPI void APIENTRY glProgramUniform1dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform1ui (GLuint program, GLint location, GLuint v0);
GLAPI void APIENTRY glProgramUniform1uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform2i (GLuint program, GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glProgramUniform2iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform2f (GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glProgramUniform2fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform2d (GLuint program, GLint location, GLdouble v0, GLdouble v1);
GLAPI void APIENTRY glProgramUniform2dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform2ui (GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glProgramUniform2uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform3i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glProgramUniform3iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform3f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY glProgramUniform3fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform3d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
GLAPI void APIENTRY glProgramUniform3dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform3ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glProgramUniform3uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform4i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glProgramUniform4iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform4f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glProgramUniform4fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform4d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
GLAPI void APIENTRY glProgramUniform4dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform4ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glProgramUniform4uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniformMatrix2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glValidateProgramPipeline (GLuint pipeline);
GLAPI void APIENTRY glGetProgramPipelineInfoLog (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glVertexAttribL1d (GLuint index, GLdouble x);
GLAPI void APIENTRY glVertexAttribL2d (GLuint index, GLdouble x, GLdouble y);
GLAPI void APIENTRY glVertexAttribL3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glVertexAttribL4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glVertexAttribL1dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL2dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL3dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL4dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribLPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glGetVertexAttribLdv (GLuint index, GLenum pname, GLdouble *params);
GLAPI void APIENTRY glViewportArrayv (GLuint first, GLsizei count, const GLfloat *v);
GLAPI void APIENTRY glViewportIndexedf (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLAPI void APIENTRY glViewportIndexedfv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glScissorArrayv (GLuint first, GLsizei count, const GLint *v);
GLAPI void APIENTRY glScissorIndexed (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
GLAPI void APIENTRY glScissorIndexedv (GLuint index, const GLint *v);
GLAPI void APIENTRY glDepthRangeArrayv (GLuint first, GLsizei count, const GLdouble *v);
GLAPI void APIENTRY glDepthRangeIndexed (GLuint index, GLdouble n, GLdouble f);
GLAPI void APIENTRY glGetFloati_v (GLenum target, GLuint index, GLfloat *data);
GLAPI void APIENTRY glGetDoublei_v (GLenum target, GLuint index, GLdouble *data);
#endif
#endif /* GL_VERSION_4_1 */

#ifndef GL_VERSION_4_2
#define GL_VERSION_4_2 1
#define GL_COPY_READ_BUFFER_BINDING       0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING      0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE      0x8E24
#define GL_TRANSFORM_FEEDBACK_PAUSED      0x8E23
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH  0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH  0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE   0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH    0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT   0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH    0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE     0x912E
#define GL_NUM_SAMPLE_COUNTS              0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT       0x90BC
#define GL_ATOMIC_COUNTER_BUFFER          0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING  0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START    0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE     0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS     0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS   0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS   0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS   0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS  0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER    0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT      0x00000002
#define GL_UNIFORM_BARRIER_BIT            0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT      0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT            0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT       0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT     0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT      0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT        0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT     0x00001000
#define GL_ALL_BARRIER_BITS               0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME             0x8F3A
#define GL_IMAGE_BINDING_LEVEL            0x8F3B
#define GL_IMAGE_BINDING_LAYERED          0x8F3C
#define GL_IMAGE_BINDING_LAYER            0x8F3D
#define GL_IMAGE_BINDING_ACCESS           0x8F3E
#define GL_IMAGE_1D                       0x904C
#define GL_IMAGE_2D                       0x904D
#define GL_IMAGE_3D                       0x904E
#define GL_IMAGE_2D_RECT                  0x904F
#define GL_IMAGE_CUBE                     0x9050
#define GL_IMAGE_BUFFER                   0x9051
#define GL_IMAGE_1D_ARRAY                 0x9052
#define GL_IMAGE_2D_ARRAY                 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY           0x9054
#define GL_IMAGE_2D_MULTISAMPLE           0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY     0x9056
#define GL_INT_IMAGE_1D                   0x9057
#define GL_INT_IMAGE_2D                   0x9058
#define GL_INT_IMAGE_3D                   0x9059
#define GL_INT_IMAGE_2D_RECT              0x905A
#define GL_INT_IMAGE_CUBE                 0x905B
#define GL_INT_IMAGE_BUFFER               0x905C
#define GL_INT_IMAGE_1D_ARRAY             0x905D
#define GL_INT_IMAGE_2D_ARRAY             0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY       0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE       0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D          0x9062
#define GL_UNSIGNED_INT_IMAGE_2D          0x9063
#define GL_UNSIGNED_INT_IMAGE_3D          0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT     0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE        0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER      0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY    0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY    0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES              0x906D
#define GL_IMAGE_BINDING_FORMAT           0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS      0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS    0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS    0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS    0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM     0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_TEXTURE_IMMUTABLE_FORMAT       0x912F
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC) (GLbitfield barriers);
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) (GLenum mode, GLuint id, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstancedBaseInstance (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
GLAPI void APIENTRY glGetInternalformativ (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
GLAPI void APIENTRY glGetActiveAtomicCounterBufferiv (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
GLAPI void APIENTRY glBindImageTexture (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLAPI void APIENTRY glMemoryBarrier (GLbitfield barriers);
GLAPI void APIENTRY glTexStorage1D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTexStorage2D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexStorage3D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glDrawTransformFeedbackInstanced (GLenum mode, GLuint id, GLsizei instancecount);
GLAPI void APIENTRY glDrawTransformFeedbackStreamInstanced (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#endif
#endif /* GL_VERSION_4_2 */

#ifndef GL_VERSION_4_3
#define GL_VERSION_4_3 1
typedef void (APIENTRY  *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_NUM_SHADING_LANGUAGE_VERSIONS  0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG       0x874E
#define GL_COMPRESSED_RGB8_ETC2           0x9274
#define GL_COMPRESSED_SRGB8_ETC2          0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC      0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC             0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC      0x9271
#define GL_COMPRESSED_RG11_EAC            0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC     0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX  0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX              0x8D6B
#define GL_COMPUTE_SHADER                 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS     0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS     0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS    0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT   0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE    0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE        0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER       0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT             0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS       0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION        0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM      0x8245
#define GL_DEBUG_SOURCE_API               0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM     0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER   0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY       0x8249
#define GL_DEBUG_SOURCE_APPLICATION       0x824A
#define GL_DEBUG_SOURCE_OTHER             0x824B
#define GL_DEBUG_TYPE_ERROR               0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR  0x824E
#define GL_DEBUG_TYPE_PORTABILITY         0x824F
#define GL_DEBUG_TYPE_PERFORMANCE         0x8250
#define GL_DEBUG_TYPE_OTHER               0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH       0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES      0x9144
#define GL_DEBUG_LOGGED_MESSAGES          0x9145
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_TYPE_MARKER              0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP          0x8269
#define GL_DEBUG_TYPE_POP_GROUP           0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH    0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH        0x826D
#define GL_BUFFER                         0x82E0
#define GL_SHADER                         0x82E1
#define GL_PROGRAM                        0x82E2
#define GL_QUERY                          0x82E3
#define GL_PROGRAM_PIPELINE               0x82E4
#define GL_SAMPLER                        0x82E6
#define GL_MAX_LABEL_LENGTH               0x82E8
#define GL_DEBUG_OUTPUT                   0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT         0x00000002
#define GL_MAX_UNIFORM_LOCATIONS          0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH      0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT     0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS     0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES    0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH          0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT         0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS         0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES        0x9318
#define GL_INTERNALFORMAT_SUPPORTED       0x826F
#define GL_INTERNALFORMAT_PREFERRED       0x8270
#define GL_INTERNALFORMAT_RED_SIZE        0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE      0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE       0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE      0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE      0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE    0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE     0x8277
#define GL_INTERNALFORMAT_RED_TYPE        0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE      0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE       0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE      0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE      0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE    0x827D
#define GL_MAX_WIDTH                      0x827E
#define GL_MAX_HEIGHT                     0x827F
#define GL_MAX_DEPTH                      0x8280
#define GL_MAX_LAYERS                     0x8281
#define GL_MAX_COMBINED_DIMENSIONS        0x8282
#define GL_COLOR_COMPONENTS               0x8283
#define GL_DEPTH_COMPONENTS               0x8284
#define GL_STENCIL_COMPONENTS             0x8285
#define GL_COLOR_RENDERABLE               0x8286
#define GL_DEPTH_RENDERABLE               0x8287
#define GL_STENCIL_RENDERABLE             0x8288
#define GL_FRAMEBUFFER_RENDERABLE         0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND              0x828B
#define GL_READ_PIXELS                    0x828C
#define GL_READ_PIXELS_FORMAT             0x828D
#define GL_READ_PIXELS_TYPE               0x828E
#define GL_TEXTURE_IMAGE_FORMAT           0x828F
#define GL_TEXTURE_IMAGE_TYPE             0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT       0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE         0x8292
#define GL_MIPMAP                         0x8293
#define GL_MANUAL_GENERATE_MIPMAP         0x8294
#define GL_AUTO_GENERATE_MIPMAP           0x8295
#define GL_COLOR_ENCODING                 0x8296
#define GL_SRGB_READ                      0x8297
#define GL_SRGB_WRITE                     0x8298
#define GL_FILTER                         0x829A
#define GL_VERTEX_TEXTURE                 0x829B
#define GL_TESS_CONTROL_TEXTURE           0x829C
#define GL_TESS_EVALUATION_TEXTURE        0x829D
#define GL_GEOMETRY_TEXTURE               0x829E
#define GL_FRAGMENT_TEXTURE               0x829F
#define GL_COMPUTE_TEXTURE                0x82A0
#define GL_TEXTURE_SHADOW                 0x82A1
#define GL_TEXTURE_GATHER                 0x82A2
#define GL_TEXTURE_GATHER_SHADOW          0x82A3
#define GL_SHADER_IMAGE_LOAD              0x82A4
#define GL_SHADER_IMAGE_STORE             0x82A5
#define GL_SHADER_IMAGE_ATOMIC            0x82A6
#define GL_IMAGE_TEXEL_SIZE               0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS      0x82A8
#define GL_IMAGE_PIXEL_FORMAT             0x82A9
#define GL_IMAGE_PIXEL_TYPE               0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE  0x82B3
#define GL_CLEAR_BUFFER                   0x82B4
#define GL_TEXTURE_VIEW                   0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS       0x82B6
#define GL_FULL_SUPPORT                   0x82B7
#define GL_CAVEAT_SUPPORT                 0x82B8
#define GL_IMAGE_CLASS_4_X_32             0x82B9
#define GL_IMAGE_CLASS_2_X_32             0x82BA
#define GL_IMAGE_CLASS_1_X_32             0x82BB
#define GL_IMAGE_CLASS_4_X_16             0x82BC
#define GL_IMAGE_CLASS_2_X_16             0x82BD
#define GL_IMAGE_CLASS_1_X_16             0x82BE
#define GL_IMAGE_CLASS_4_X_8              0x82BF
#define GL_IMAGE_CLASS_2_X_8              0x82C0
#define GL_IMAGE_CLASS_1_X_8              0x82C1
#define GL_IMAGE_CLASS_11_11_10           0x82C2
#define GL_IMAGE_CLASS_10_10_10_2         0x82C3
#define GL_VIEW_CLASS_128_BITS            0x82C4
#define GL_VIEW_CLASS_96_BITS             0x82C5
#define GL_VIEW_CLASS_64_BITS             0x82C6
#define GL_VIEW_CLASS_48_BITS             0x82C7
#define GL_VIEW_CLASS_32_BITS             0x82C8
#define GL_VIEW_CLASS_24_BITS             0x82C9
#define GL_VIEW_CLASS_16_BITS             0x82CA
#define GL_VIEW_CLASS_8_BITS              0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB       0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA      0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA      0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA      0x82CF
#define GL_VIEW_CLASS_RGTC1_RED           0x82D0
#define GL_VIEW_CLASS_RGTC2_RG            0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM          0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT          0x82D3
#define GL_UNIFORM                        0x92E1
#define GL_UNIFORM_BLOCK                  0x92E2
#define GL_PROGRAM_INPUT                  0x92E3
#define GL_PROGRAM_OUTPUT                 0x92E4
#define GL_BUFFER_VARIABLE                0x92E5
#define GL_SHADER_STORAGE_BLOCK           0x92E6
#define GL_VERTEX_SUBROUTINE              0x92E8
#define GL_TESS_CONTROL_SUBROUTINE        0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE     0x92EA
#define GL_GEOMETRY_SUBROUTINE            0x92EB
#define GL_FRAGMENT_SUBROUTINE            0x92EC
#define GL_COMPUTE_SUBROUTINE             0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM      0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM    0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM    0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM     0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING     0x92F4
#define GL_ACTIVE_RESOURCES               0x92F5
#define GL_MAX_NAME_LENGTH                0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES       0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH                    0x92F9
#define GL_TYPE                           0x92FA
#define GL_ARRAY_SIZE                     0x92FB
#define GL_OFFSET                         0x92FC
#define GL_BLOCK_INDEX                    0x92FD
#define GL_ARRAY_STRIDE                   0x92FE
#define GL_MATRIX_STRIDE                  0x92FF
#define GL_IS_ROW_MAJOR                   0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX    0x9301
#define GL_BUFFER_BINDING                 0x9302
#define GL_BUFFER_DATA_SIZE               0x9303
#define GL_NUM_ACTIVE_VARIABLES           0x9304
#define GL_ACTIVE_VARIABLES               0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER    0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER  0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER  0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER   0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE           0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE         0x930D
#define GL_LOCATION                       0x930E
#define GL_LOCATION_INDEX                 0x930F
#define GL_IS_PER_PATCH                   0x92E7
#define GL_SHADER_STORAGE_BUFFER          0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING  0x90D3
#define GL_SHADER_STORAGE_BUFFER_START    0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE     0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE  0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT     0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE     0x90EA
#define GL_TEXTURE_BUFFER_OFFSET          0x919D
#define GL_TEXTURE_BUFFER_SIZE            0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL         0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS        0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER         0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS        0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS       0x82DF
#define GL_VERTEX_ATTRIB_BINDING          0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET  0x82D5
#define GL_VERTEX_BINDING_DIVISOR         0x82D6
#define GL_VERTEX_BINDING_OFFSET          0x82D7
#define GL_VERTEX_BINDING_STRIDE          0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#define GL_VERTEX_BINDING_BUFFER          0x8F4F
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC) (GLintptr indirect);
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC) (GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC) (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC) (GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC) (GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC) (GLDEBUGPROC callback, const void *userParam);
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC) (void);
typedef void (APIENTRYP PFNGLOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC) (const void *ptr, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glClearBufferData (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearBufferSubData (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glDispatchCompute (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLAPI void APIENTRY glDispatchComputeIndirect (GLintptr indirect);
GLAPI void APIENTRY glCopyImageSubData (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
GLAPI void APIENTRY glFramebufferParameteri (GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glGetFramebufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetInternalformati64v (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
GLAPI void APIENTRY glInvalidateTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glInvalidateTexImage (GLuint texture, GLint level);
GLAPI void APIENTRY glInvalidateBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glInvalidateBufferData (GLuint buffer);
GLAPI void APIENTRY glInvalidateFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments);
GLAPI void APIENTRY glInvalidateSubFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glMultiDrawArraysIndirect (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI void APIENTRY glMultiDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI void APIENTRY glGetProgramInterfaceiv (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
GLAPI GLuint APIENTRY glGetProgramResourceIndex (GLuint program, GLenum programInterface, const GLchar *name);
GLAPI void APIENTRY glGetProgramResourceName (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glGetProgramResourceiv (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
GLAPI GLint APIENTRY glGetProgramResourceLocation (GLuint program, GLenum programInterface, const GLchar *name);
GLAPI GLint APIENTRY glGetProgramResourceLocationIndex (GLuint program, GLenum programInterface, const GLchar *name);
GLAPI void APIENTRY glShaderStorageBlockBinding (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
GLAPI void APIENTRY glTexBufferRange (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glTexStorage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTexStorage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureView (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
GLAPI void APIENTRY glBindVertexBuffer (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexAttribFormat (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribIFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribLFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribBinding (GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexBindingDivisor (GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glDebugMessageControl (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI void APIENTRY glDebugMessageInsert (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI void APIENTRY glDebugMessageCallback (GLDEBUGPROC callback, const void *userParam);
GLAPI GLuint APIENTRY glGetDebugMessageLog (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLAPI void APIENTRY glPushDebugGroup (GLenum source, GLuint id, GLsizei length, const GLchar *message);
GLAPI void APIENTRY glPopDebugGroup (void);
GLAPI void APIENTRY glObjectLabel (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
GLAPI void APIENTRY glGetObjectLabel (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
GLAPI void APIENTRY glObjectPtrLabel (const void *ptr, GLsizei length, const GLchar *label);
GLAPI void APIENTRY glGetObjectPtrLabel (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
#endif
#endif /* GL_VERSION_4_3 */

#ifndef GL_VERSION_4_4
#define GL_VERSION_4_4 1
#define GL_MAX_VERTEX_ATTRIB_STRIDE       0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING         0x8C2A
#define GL_MAP_PERSISTENT_BIT             0x0040
#define GL_MAP_COHERENT_BIT               0x0080
#define GL_DYNAMIC_STORAGE_BIT            0x0100
#define GL_CLIENT_STORAGE_BIT             0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE       0x821F
#define GL_BUFFER_STORAGE_FLAGS           0x8220
#define GL_CLEAR_TEXTURE                  0x9365
#define GL_LOCATION_COMPONENT             0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_QUERY_BUFFER                   0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT       0x00008000
#define GL_QUERY_BUFFER_BINDING           0x9193
#define GL_QUERY_RESULT_NO_WAIT           0x9194
#define GL_MIRROR_CLAMP_TO_EDGE           0x8743
typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC) (GLuint first, GLsizei count, const GLuint *samplers);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBufferStorage (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void APIENTRY glClearTexImage (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glBindBuffersBase (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
GLAPI void APIENTRY glBindBuffersRange (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
GLAPI void APIENTRY glBindTextures (GLuint first, GLsizei count, const GLuint *textures);
GLAPI void APIENTRY glBindSamplers (GLuint first, GLsizei count, const GLuint *samplers);
GLAPI void APIENTRY glBindImageTextures (GLuint first, GLsizei count, const GLuint *textures);
GLAPI void APIENTRY glBindVertexBuffers (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
#endif
#endif /* GL_VERSION_4_4 */

#ifndef GL_VERSION_4_5
#define GL_VERSION_4_5 1
#define GL_CONTEXT_LOST                   0x0507
#define GL_NEGATIVE_ONE_TO_ONE            0x935E
#define GL_ZERO_TO_ONE                    0x935F
#define GL_CLIP_ORIGIN                    0x935C
#define GL_CLIP_DEPTH_MODE                0x935D
#define GL_QUERY_WAIT_INVERTED            0x8E17
#define GL_QUERY_NO_WAIT_INVERTED         0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED  0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_MAX_CULL_DISTANCES             0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_TEXTURE_TARGET                 0x1006
#define GL_QUERY_TARGET                   0x82EA
#define GL_GUILTY_CONTEXT_RESET           0x8253
#define GL_INNOCENT_CONTEXT_RESET         0x8254
#define GL_UNKNOWN_CONTEXT_RESET          0x8255
#define GL_RESET_NOTIFICATION_STRATEGY    0x8256
#define GL_LOSE_CONTEXT_ON_RESET          0x8252
#define GL_NO_RESET_NOTIFICATION          0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
#define GL_CONTEXT_RELEASE_BEHAVIOR       0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC) (GLenum origin, GLenum depth);
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC) (GLuint xfb, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC) (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC) (GLuint xfb, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERPROC) (GLuint buffer, GLenum access);
typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC) (GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC) (GLuint buffer, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC) (GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC) (GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC) (GLuint framebuffer, GLenum buf);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC) (GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC) (GLuint framebuffer, GLenum src);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC) (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) (GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) (GLuint framebuffer, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) (GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC) (GLenum target, GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC) (GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC) (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC) (GLuint texture, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC) (GLuint texture, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC) (GLuint texture);
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC) (GLuint unit, GLuint texture);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC) (GLuint texture, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC) (GLuint texture, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC) (GLuint vaobj, GLuint buffer);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC) (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC) (GLuint vaobj, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC) (GLsizei n, GLuint *samplers);
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC) (GLenum target, GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC) (GLbitfield barriers);
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC) (void);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLREADNPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glClipControl (GLenum origin, GLenum depth);
GLAPI void APIENTRY glCreateTransformFeedbacks (GLsizei n, GLuint *ids);
GLAPI void APIENTRY glTransformFeedbackBufferBase (GLuint xfb, GLuint index, GLuint buffer);
GLAPI void APIENTRY glTransformFeedbackBufferRange (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glGetTransformFeedbackiv (GLuint xfb, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetTransformFeedbacki_v (GLuint xfb, GLenum pname, GLuint index, GLint *param);
GLAPI void APIENTRY glGetTransformFeedbacki64_v (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
GLAPI void APIENTRY glCreateBuffers (GLsizei n, GLuint *buffers);
GLAPI void APIENTRY glNamedBufferStorage (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void APIENTRY glNamedBufferData (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void APIENTRY glNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void APIENTRY glCopyNamedBufferSubData (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void APIENTRY glClearNamedBufferData (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearNamedBufferSubData (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void *APIENTRY glMapNamedBuffer (GLuint buffer, GLenum access);
GLAPI void *APIENTRY glMapNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI GLboolean APIENTRY glUnmapNamedBuffer (GLuint buffer);
GLAPI void APIENTRY glFlushMappedNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glGetNamedBufferParameteriv (GLuint buffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetNamedBufferParameteri64v (GLuint buffer, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glGetNamedBufferPointerv (GLuint buffer, GLenum pname, void **params);
GLAPI void APIENTRY glGetNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void APIENTRY glCreateFramebuffers (GLsizei n, GLuint *framebuffers);
GLAPI void APIENTRY glNamedFramebufferRenderbuffer (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void APIENTRY glNamedFramebufferParameteri (GLuint framebuffer, GLenum pname, GLint param);
GLAPI void APIENTRY glNamedFramebufferTexture (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glNamedFramebufferTextureLayer (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void APIENTRY glNamedFramebufferDrawBuffer (GLuint framebuffer, GLenum buf);
GLAPI void APIENTRY glNamedFramebufferDrawBuffers (GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLAPI void APIENTRY glNamedFramebufferReadBuffer (GLuint framebuffer, GLenum src);
GLAPI void APIENTRY glInvalidateNamedFramebufferData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
GLAPI void APIENTRY glInvalidateNamedFramebufferSubData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glClearNamedFramebufferiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void APIENTRY glClearNamedFramebufferuiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void APIENTRY glClearNamedFramebufferfv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void APIENTRY glClearNamedFramebufferfi (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI void APIENTRY glBlitNamedFramebuffer (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI GLenum APIENTRY glCheckNamedFramebufferStatus (GLuint framebuffer, GLenum target);
GLAPI void APIENTRY glGetNamedFramebufferParameteriv (GLuint framebuffer, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameteriv (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateRenderbuffers (GLsizei n, GLuint *renderbuffers);
GLAPI void APIENTRY glNamedRenderbufferStorage (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glNamedRenderbufferStorageMultisample (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetNamedRenderbufferParameteriv (GLuint renderbuffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateTextures (GLenum target, GLsizei n, GLuint *textures);
GLAPI void APIENTRY glTextureBuffer (GLuint texture, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glTextureBufferRange (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glTextureStorage1D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTextureStorage2D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTextureStorage3D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glTextureStorage2DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureStorage3DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCompressedTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCopyTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glCopyTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTextureParameterf (GLuint texture, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTextureParameterfv (GLuint texture, GLenum pname, const GLfloat *param);
GLAPI void APIENTRY glTextureParameteri (GLuint texture, GLenum pname, GLint param);
GLAPI void APIENTRY glTextureParameterIiv (GLuint texture, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTextureParameterIuiv (GLuint texture, GLenum pname, const GLuint *params);
GLAPI void APIENTRY glTextureParameteriv (GLuint texture, GLenum pname, const GLint *param);
GLAPI void APIENTRY glGenerateTextureMipmap (GLuint texture);
GLAPI void APIENTRY glBindTextureUnit (GLuint unit, GLuint texture);
GLAPI void APIENTRY glGetTextureImage (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetCompressedTextureImage (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetTextureLevelParameterfv (GLuint texture, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTextureLevelParameteriv (GLuint texture, GLint level, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTextureParameterfv (GLuint texture, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTextureParameterIiv (GLuint texture, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTextureParameterIuiv (GLuint texture, GLenum pname, GLuint *params);
GLAPI void APIENTRY glGetTextureParameteriv (GLuint texture, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateVertexArrays (GLsizei n, GLuint *arrays);
GLAPI void APIENTRY glDisableVertexArrayAttrib (GLuint vaobj, GLuint index);
GLAPI void APIENTRY glEnableVertexArrayAttrib (GLuint vaobj, GLuint index);
GLAPI void APIENTRY glVertexArrayElementBuffer (GLuint vaobj, GLuint buffer);
GLAPI void APIENTRY glVertexArrayVertexBuffer (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexArrayVertexBuffers (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
GLAPI void APIENTRY glVertexArrayAttribBinding (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexArrayAttribFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayAttribIFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayAttribLFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayBindingDivisor (GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glGetVertexArrayiv (GLuint vaobj, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetVertexArrayIndexediv (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetVertexArrayIndexed64iv (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
GLAPI void APIENTRY glCreateSamplers (GLsizei n, GLuint *samplers);
GLAPI void APIENTRY glCreateProgramPipelines (GLsizei n, GLuint *pipelines);
GLAPI void APIENTRY glCreateQueries (GLenum target, GLsizei n, GLuint *ids);
GLAPI void APIENTRY glGetQueryBufferObjecti64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectui64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectuiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glMemoryBarrierByRegion (GLbitfield barriers);
GLAPI void APIENTRY glGetTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetCompressedTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
GLAPI GLenum APIENTRY glGetGraphicsResetStatus (void);
GLAPI void APIENTRY glGetnCompressedTexImage (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetnTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetnUniformdv (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
GLAPI void APIENTRY glGetnUniformfv (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI void APIENTRY glGetnUniformiv (GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI void APIENTRY glGetnUniformuiv (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI void APIENTRY glReadnPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI void APIENTRY glTextureBarrier (void);
#endif
#endif /* GL_VERSION_4_5 */

#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
#endif /* GL_ARB_ES2_compatibility */

#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1
#endif /* GL_ARB_ES3_1_compatibility */

#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1
#endif /* GL_ARB_ES3_compatibility */

#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1
#endif /* GL_ARB_arrays_of_arrays */

#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
#endif /* GL_ARB_base_instance */

#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
typedef uint64_t GLuint64EXT;
#define GL_UNSIGNED_INT64_ARB             0x140F
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC) (GLuint texture);
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC) (GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLEARBPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC) (GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC) (GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC) (GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC) (GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC) (GLuint index, GLenum pname, GLuint64EXT *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint64 APIENTRY glGetTextureHandleARB (GLuint texture);
GLAPI GLuint64 APIENTRY glGetTextureSamplerHandleARB (GLuint texture, GLuint sampler);
GLAPI void APIENTRY glMakeTextureHandleResidentARB (GLuint64 handle);
GLAPI void APIENTRY glMakeTextureHandleNonResidentARB (GLuint64 handle);
GLAPI GLuint64 APIENTRY glGetImageHandleARB (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLAPI void APIENTRY glMakeImageHandleResidentARB (GLuint64 handle, GLenum access);
GLAPI void APIENTRY glMakeImageHandleNonResidentARB (GLuint64 handle);
GLAPI void APIENTRY glUniformHandleui64ARB (GLint location, GLuint64 value);
GLAPI void APIENTRY glUniformHandleui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glProgramUniformHandleui64ARB (GLuint program, GLint location, GLuint64 value);
GLAPI void APIENTRY glProgramUniformHandleui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
GLAPI GLboolean APIENTRY glIsTextureHandleResidentARB (GLuint64 handle);
GLAPI GLboolean APIENTRY glIsImageHandleResidentARB (GLuint64 handle);
GLAPI void APIENTRY glVertexAttribL1ui64ARB (GLuint index, GLuint64EXT x);
GLAPI void APIENTRY glVertexAttribL1ui64vARB (GLuint index, const GLuint64EXT *v);
GLAPI void APIENTRY glGetVertexAttribLui64vARB (GLuint index, GLenum pname, GLuint64EXT *params);
#endif
#endif /* GL_ARB_bindless_texture */

#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
#endif /* GL_ARB_blend_func_extended */

#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
#endif /* GL_ARB_buffer_storage */

#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
struct _cl_context;
struct _cl_event;
#define GL_SYNC_CL_EVENT_ARB              0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB     0x8241
typedef GLsync (APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC) (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLsync APIENTRY glCreateSyncFromCLeventARB (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
#endif
#endif /* GL_ARB_cl_event */

#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
#endif /* GL_ARB_clear_buffer_object */

#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
#endif /* GL_ARB_clear_texture */

#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1
#endif /* GL_ARB_clip_control */

#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1
#endif /* GL_ARB_compressed_texture_pixel_storage */

#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
#endif /* GL_ARB_compute_shader */

#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDispatchComputeGroupSizeARB (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#endif
#endif /* GL_ARB_compute_variable_group_size */

#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted 1
#endif /* GL_ARB_conditional_render_inverted */

#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1
#endif /* GL_ARB_conservative_depth */

#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
#endif /* GL_ARB_copy_buffer */

#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
#endif /* GL_ARB_copy_image */

#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance 1
#endif /* GL_ARB_cull_distance */

#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
typedef void (APIENTRY  *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB   0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB    0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB  0x8245
#define GL_DEBUG_SOURCE_API_ARB           0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB   0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB   0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB         0x824B
#define GL_DEBUG_TYPE_ERROR_ARB           0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB     0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB     0x8250
#define GL_DEBUG_TYPE_OTHER_ARB           0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB   0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB  0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB      0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB        0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB      0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB         0x9148
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC) (GLDEBUGPROCARB callback, const void *userParam);
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDebugMessageControlARB (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI void APIENTRY glDebugMessageInsertARB (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI void APIENTRY glDebugMessageCallbackARB (GLDEBUGPROCARB callback, const void *userParam);
GLAPI GLuint APIENTRY glGetDebugMessageLogARB (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
#endif
#endif /* GL_ARB_debug_output */

#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
#endif /* GL_ARB_depth_buffer_float */

#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1
#endif /* GL_ARB_depth_clamp */

#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control 1
#endif /* GL_ARB_derivative_control */

#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1
#endif /* GL_ARB_direct_state_access */

#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
typedef void (APIENTRYP PFNGLBLENDEQUATIONIARBPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIARBPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendEquationiARB (GLuint buf, GLenum mode);
GLAPI void APIENTRY glBlendEquationSeparateiARB (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glBlendFunciARB (GLuint buf, GLenum src, GLenum dst);
GLAPI void APIENTRY glBlendFuncSeparateiARB (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif
#endif /* GL_ARB_draw_buffers_blend */

#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
#endif /* GL_ARB_draw_elements_base_vertex */

#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
#endif /* GL_ARB_draw_indirect */

#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts 1
#endif /* GL_ARB_enhanced_layouts */

#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1
#endif /* GL_ARB_explicit_attrib_location */

#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1
#endif /* GL_ARB_explicit_uniform_location */

#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1
#endif /* GL_ARB_fragment_coord_conventions */

#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1
#endif /* GL_ARB_fragment_layer_viewport */

#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
#endif /* GL_ARB_framebuffer_no_attachments */

#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
#endif /* GL_ARB_framebuffer_object */

#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
#endif /* GL_ARB_framebuffer_sRGB */

#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
#endif /* GL_ARB_get_program_binary */

#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1
#endif /* GL_ARB_get_texture_sub_image */

#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1
#endif /* GL_ARB_gpu_shader5 */

#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
#endif /* GL_ARB_gpu_shader_fp64 */

#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
#endif /* GL_ARB_half_float_vertex */

#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#define GL_BLEND_COLOR                    0x8005
#define GL_BLEND_EQUATION                 0x8009
#endif /* GL_ARB_imaging */

#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
#define GL_PARAMETER_BUFFER_ARB           0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB   0x80EF
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC) (GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC) (GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMultiDrawArraysIndirectCountARB (GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI void APIENTRY glMultiDrawElementsIndirectCountARB (GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif
#endif /* GL_ARB_indirect_parameters */

#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
#endif /* GL_ARB_internalformat_query */

#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
#define GL_SRGB_DECODE_ARB                0x8299
#endif /* GL_ARB_internalformat_query2 */

#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
#endif /* GL_ARB_invalidate_subdata */

#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment 1
#endif /* GL_ARB_map_buffer_alignment */

#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
#endif /* GL_ARB_map_buffer_range */

#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1
#endif /* GL_ARB_multi_bind */

#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
#endif /* GL_ARB_multi_draw_indirect */

#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2 1
#endif /* GL_ARB_occlusion_query2 */

#ifndef GL_ARB_pipeline_statistics_query
#define GL_ARB_pipeline_statistics_query 1
#define GL_VERTICES_SUBMITTED_ARB         0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB       0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB  0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB  0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#endif /* GL_ARB_pipeline_statistics_query */

#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
#endif /* GL_ARB_program_interface_query */

#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
#endif /* GL_ARB_provoking_vertex */

#ifndef GL_ARB_query_buffer_object
#define GL_ARB_query_buffer_object 1
#endif /* GL_ARB_query_buffer_object */

#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior 1
#endif /* GL_ARB_robust_buffer_access_behavior */

#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB      0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB       0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB     0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB      0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB      0x8261
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC) (void);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEARBPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
typedef void (APIENTRYP PFNGLREADNPIXELSARBPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint lod, GLsizei bufSize, void *img);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLenum APIENTRY glGetGraphicsResetStatusARB (void);
GLAPI void APIENTRY glGetnTexImageARB (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
GLAPI void APIENTRY glReadnPixelsARB (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI void APIENTRY glGetnCompressedTexImageARB (GLenum target, GLint lod, GLsizei bufSize, void *img);
GLAPI void APIENTRY glGetnUniformfvARB (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI void APIENTRY glGetnUniformivARB (GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI void APIENTRY glGetnUniformuivARB (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI void APIENTRY glGetnUniformdvARB (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
#endif
#endif /* GL_ARB_robustness */

#ifndef GL_ARB_robustness_isolation
#define GL_ARB_robustness_isolation 1
#endif /* GL_ARB_robustness_isolation */

#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
#define GL_SAMPLE_SHADING_ARB             0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB   0x8C37
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGARBPROC) (GLfloat value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMinSampleShadingARB (GLfloat value);
#endif
#endif /* GL_ARB_sample_shading */

#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
#endif /* GL_ARB_sampler_objects */

#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map 1
#endif /* GL_ARB_seamless_cube_map */

#ifndef GL_ARB_seamless_cubemap_per_texture
#define GL_ARB_seamless_cubemap_per_texture 1
#endif /* GL_ARB_seamless_cubemap_per_texture */

#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
#endif /* GL_ARB_separate_shader_objects */

#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
#endif /* GL_ARB_shader_atomic_counters */

#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding 1
#endif /* GL_ARB_shader_bit_encoding */

#ifndef GL_ARB_shader_draw_parameters
#define GL_ARB_shader_draw_parameters 1
#endif /* GL_ARB_shader_draw_parameters */

#ifndef GL_ARB_shader_group_vote
#define GL_ARB_shader_group_vote 1
#endif /* GL_ARB_shader_group_vote */

#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
#endif /* GL_ARB_shader_image_load_store */

#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size 1
#endif /* GL_ARB_shader_image_size */

#ifndef GL_ARB_shader_precision
#define GL_ARB_shader_precision 1
#endif /* GL_ARB_shader_precision */

#ifndef GL_ARB_shader_stencil_export
#define GL_ARB_shader_stencil_export 1
#endif /* GL_ARB_shader_stencil_export */

#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
#endif /* GL_ARB_shader_storage_buffer_object */

#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
#endif /* GL_ARB_shader_subroutine */

#ifndef GL_ARB_shader_texture_image_samples
#define GL_ARB_shader_texture_image_samples 1
#endif /* GL_ARB_shader_texture_image_samples */

#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack 1
#endif /* GL_ARB_shading_language_420pack */

#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
#define GL_SHADER_INCLUDE_ARB             0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB        0x8DE9
#define GL_NAMED_STRING_TYPE_ARB          0x8DEA
typedef void (APIENTRYP PFNGLNAMEDSTRINGARBPROC) (GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
typedef void (APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name);
typedef void (APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC) (GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
typedef GLboolean (APIENTRYP PFNGLISNAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC) (GLint namelen, const GLchar *name, GLenum pname, GLint *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glNamedStringARB (GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
GLAPI void APIENTRY glDeleteNamedStringARB (GLint namelen, const GLchar *name);
GLAPI void APIENTRY glCompileShaderIncludeARB (GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
GLAPI GLboolean APIENTRY glIsNamedStringARB (GLint namelen, const GLchar *name);
GLAPI void APIENTRY glGetNamedStringARB (GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
GLAPI void APIENTRY glGetNamedStringivARB (GLint namelen, const GLchar *name, GLenum pname, GLint *params);
#endif
#endif /* GL_ARB_shading_language_include */

#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing 1
#endif /* GL_ARB_shading_language_packing */

#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1
#define GL_SPARSE_STORAGE_BIT_ARB         0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB    0x82F8
typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBufferPageCommitmentARB (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI void APIENTRY glNamedBufferPageCommitmentEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI void APIENTRY glNamedBufferPageCommitmentARB (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif
#endif /* GL_ARB_sparse_buffer */

#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
#define GL_TEXTURE_SPARSE_ARB             0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB    0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB          0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB     0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB        0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB        0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB        0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB    0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glTexPageCommitmentARB (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif
#endif /* GL_ARB_sparse_texture */

#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing 1
#endif /* GL_ARB_stencil_texturing */

#ifndef GL_ARB_sync
#define GL_ARB_sync 1
#endif /* GL_ARB_sync */

#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
#endif /* GL_ARB_tessellation_shader */

#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier 1
#endif /* GL_ARB_texture_barrier */

#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32 1
#endif /* GL_ARB_texture_buffer_object_rgb32 */

#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
#endif /* GL_ARB_texture_buffer_range */

#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc 1
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#endif /* GL_ARB_texture_compression_bptc */

#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1
#endif /* GL_ARB_texture_compression_rgtc */

#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array 1
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB     0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB     0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
#endif /* GL_ARB_texture_cube_map_array */

#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather 1
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#endif /* GL_ARB_texture_gather */

#ifndef GL_ARB_texture_mirror_clamp_to_edge
#define GL_ARB_texture_mirror_clamp_to_edge 1
#endif /* GL_ARB_texture_mirror_clamp_to_edge */

#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
#endif /* GL_ARB_texture_multisample */

#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels 1
#endif /* GL_ARB_texture_query_levels */

#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod 1
#endif /* GL_ARB_texture_query_lod */

#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1
#endif /* GL_ARB_texture_rg */

#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui 1
#endif /* GL_ARB_texture_rgb10_a2ui */

#ifndef GL_ARB_texture_stencil8
#define GL_ARB_texture_stencil8 1
#endif /* GL_ARB_texture_stencil8 */

#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
#endif /* GL_ARB_texture_storage */

#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
#endif /* GL_ARB_texture_storage_multisample */

#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle 1
#endif /* GL_ARB_texture_swizzle */

#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
#endif /* GL_ARB_texture_view */

#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
#endif /* GL_ARB_timer_query */

#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
#endif /* GL_ARB_transform_feedback2 */

#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
#endif /* GL_ARB_transform_feedback3 */

#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
#endif /* GL_ARB_transform_feedback_instanced */

#ifndef GL_ARB_transform_feedback_overflow_query
#define GL_ARB_transform_feedback_overflow_query 1
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED
#endif /* GL_ARB_transform_feedback_overflow_query */

#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
#endif /* GL_ARB_uniform_buffer_object */

#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra 1
#endif /* GL_ARB_vertex_array_bgra */

#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
#endif /* GL_ARB_vertex_array_object */

#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
#endif /* GL_ARB_vertex_attrib_64bit */

#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
#endif /* GL_ARB_vertex_attrib_binding */

#ifndef GL_ARB_vertex_type_10f_11f_11f_rev
#define GL_ARB_vertex_type_10f_11f_11f_rev 1
#endif /* GL_ARB_vertex_type_10f_11f_11f_rev */

#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
#endif /* GL_ARB_vertex_type_2_10_10_10_rev */

#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
#endif /* GL_ARB_viewport_array */

#ifndef GL_KHR_context_flush_control
#define GL_KHR_context_flush_control 1
#endif /* GL_KHR_context_flush_control */

#ifndef GL_KHR_debug
#define GL_KHR_debug 1
#endif /* GL_KHR_debug */

#ifndef GL_KHR_no_error
#define GL_KHR_no_error 1
#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR  0x00000008
#endif /* GL_KHR_no_error */

#ifndef GL_KHR_robust_buffer_access_behavior
#define GL_KHR_robust_buffer_access_behavior 1
#endif /* GL_KHR_robust_buffer_access_behavior */

#ifndef GL_KHR_robustness
#define GL_KHR_robustness 1
#define GL_CONTEXT_ROBUST_ACCESS          0x90F3
#endif /* GL_KHR_robustness */

#ifndef GL_KHR_texture_compression_astc_hdr
#define GL_KHR_texture_compression_astc_hdr 1
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR   0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR   0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR   0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR   0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR   0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR   0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR   0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR   0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR  0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR  0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR  0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#endif /* GL_KHR_texture_compression_astc_hdr */

#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_KHR_texture_compression_astc_ldr 1
#endif /* GL_KHR_texture_compression_astc_ldr */

#ifndef GL_KHR_texture_compression_astc_sliced_3d
#define GL_KHR_texture_compression_astc_sliced_3d 1
#endif /* GL_KHR_texture_compression_astc_sliced_3d */

#ifdef __cplusplus
}
#endif

#endif

//----------------------------------------------------------------------------

#if defined NDEBUG
# define ON_GL_ERROR(action) \
         do { ; } while(0)
#else
# define ON_GL_ERROR(action)                       \
         do                                        \
           {                                       \
           const char *__glErr=CoreGl_lastError(); \
           ON_ERROR(__glErr,__glErr,action);       \
           } while(0)
#endif

typedef struct _CoreGlComputeProperties
{
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
} CoreGlComputeProperties;

struct _CoreGlManager
{
bool initDone;
bool coreProfile;
bool embedded;
int majorVersion,minorVersion;
int shadingLanguageVersion;
int extensionCount;
char ** extensions;
bool hasTessControlShaders;
bool hasTessEvaluationShaders;
bool hasGeometryShaders;
bool hasComputeShaders;
CoreGlComputeProperties computeProperties;
bool has_VERSION_1_0;
bool has_VERSION_1_1;
bool has_VERSION_1_2;
bool has_VERSION_1_3;
bool has_VERSION_1_4;
bool has_VERSION_1_5;
bool has_VERSION_2_0;
bool has_VERSION_2_1;
bool has_VERSION_3_0;
bool has_VERSION_3_1;
bool has_VERSION_3_2;
bool has_VERSION_3_3;
bool has_VERSION_4_0;
bool has_VERSION_4_1;
bool has_VERSION_4_2;
bool has_VERSION_4_3;
bool has_VERSION_4_4;
bool has_VERSION_4_5;
bool has_ARB_ES2_compatibility;
bool has_ARB_ES3_1_compatibility;
bool has_ARB_ES3_compatibility;
bool has_ARB_arrays_of_arrays;
bool has_ARB_base_instance;
bool has_ARB_bindless_texture;
bool has_ARB_blend_func_extended;
bool has_ARB_buffer_storage;
bool has_ARB_cl_event;
bool has_ARB_clear_buffer_object;
bool has_ARB_clear_texture;
bool has_ARB_clip_control;
bool has_ARB_compressed_texture_pixel_storage;
bool has_ARB_compute_shader;
bool has_ARB_compute_variable_group_size;
bool has_ARB_conditional_render_inverted;
bool has_ARB_conservative_depth;
bool has_ARB_copy_buffer;
bool has_ARB_copy_image;
bool has_ARB_cull_distance;
bool has_ARB_debug_output;
bool has_ARB_depth_buffer_float;
bool has_ARB_depth_clamp;
bool has_ARB_derivative_control;
bool has_ARB_direct_state_access;
bool has_ARB_draw_buffers_blend;
bool has_ARB_draw_elements_base_vertex;
bool has_ARB_draw_indirect;
bool has_ARB_enhanced_layouts;
bool has_ARB_explicit_attrib_location;
bool has_ARB_explicit_uniform_location;
bool has_ARB_fragment_coord_conventions;
bool has_ARB_fragment_layer_viewport;
bool has_ARB_framebuffer_no_attachments;
bool has_ARB_framebuffer_object;
bool has_ARB_framebuffer_sRGB;
bool has_ARB_get_program_binary;
bool has_ARB_get_texture_sub_image;
bool has_ARB_gpu_shader5;
bool has_ARB_gpu_shader_fp64;
bool has_ARB_half_float_vertex;
bool has_ARB_imaging;
bool has_ARB_indirect_parameters;
bool has_ARB_internalformat_query;
bool has_ARB_internalformat_query2;
bool has_ARB_invalidate_subdata;
bool has_ARB_map_buffer_alignment;
bool has_ARB_map_buffer_range;
bool has_ARB_multi_bind;
bool has_ARB_multi_draw_indirect;
bool has_ARB_occlusion_query2;
bool has_ARB_pipeline_statistics_query;
bool has_ARB_program_interface_query;
bool has_ARB_provoking_vertex;
bool has_ARB_query_buffer_object;
bool has_ARB_robust_buffer_access_behavior;
bool has_ARB_robustness;
bool has_ARB_robustness_isolation;
bool has_ARB_sample_shading;
bool has_ARB_sampler_objects;
bool has_ARB_seamless_cube_map;
bool has_ARB_seamless_cubemap_per_texture;
bool has_ARB_separate_shader_objects;
bool has_ARB_shader_atomic_counters;
bool has_ARB_shader_bit_encoding;
bool has_ARB_shader_draw_parameters;
bool has_ARB_shader_group_vote;
bool has_ARB_shader_image_load_store;
bool has_ARB_shader_image_size;
bool has_ARB_shader_precision;
bool has_ARB_shader_stencil_export;
bool has_ARB_shader_storage_buffer_object;
bool has_ARB_shader_subroutine;
bool has_ARB_shader_texture_image_samples;
bool has_ARB_shading_language_420pack;
bool has_ARB_shading_language_include;
bool has_ARB_shading_language_packing;
bool has_ARB_sparse_buffer;
bool has_ARB_sparse_texture;
bool has_ARB_stencil_texturing;
bool has_ARB_sync;
bool has_ARB_tessellation_shader;
bool has_ARB_texture_barrier;
bool has_ARB_texture_buffer_object_rgb32;
bool has_ARB_texture_buffer_range;
bool has_ARB_texture_compression_bptc;
bool has_ARB_texture_compression_rgtc;
bool has_ARB_texture_cube_map_array;
bool has_ARB_texture_gather;
bool has_ARB_texture_mirror_clamp_to_edge;
bool has_ARB_texture_multisample;
bool has_ARB_texture_query_levels;
bool has_ARB_texture_query_lod;
bool has_ARB_texture_rg;
bool has_ARB_texture_rgb10_a2ui;
bool has_ARB_texture_stencil8;
bool has_ARB_texture_storage;
bool has_ARB_texture_storage_multisample;
bool has_ARB_texture_swizzle;
bool has_ARB_texture_view;
bool has_ARB_timer_query;
bool has_ARB_transform_feedback2;
bool has_ARB_transform_feedback3;
bool has_ARB_transform_feedback_instanced;
bool has_ARB_transform_feedback_overflow_query;
bool has_ARB_uniform_buffer_object;
bool has_ARB_vertex_array_bgra;
bool has_ARB_vertex_array_object;
bool has_ARB_vertex_attrib_64bit;
bool has_ARB_vertex_attrib_binding;
bool has_ARB_vertex_type_10f_11f_11f_rev;
bool has_ARB_vertex_type_2_10_10_10_rev;
bool has_ARB_viewport_array;
bool has_KHR_context_flush_control;
bool has_KHR_debug;
bool has_KHR_no_error;
bool has_KHR_robust_buffer_access_behavior;
bool has_KHR_robustness;
bool has_KHR_texture_compression_astc_hdr;
bool has_KHR_texture_compression_astc_ldr;
bool has_KHR_texture_compression_astc_sliced_3d;
};

TRANSGL_API struct _CoreGlManager _CoreGl_mgr;

TRANSGL_API
bool // success
CoreGl_init(void);

INLINE
bool // OpenGL core profile is supported
CoreGl_coreProfile(void)
{
return _CoreGl_mgr.coreProfile;
}

INLINE
bool // OpenGL is actually OpenGL ES
CoreGl_embedded(void)
{
return _CoreGl_mgr.embedded;
}

INLINE
int // OpenGL major version
CoreGl_majorVersion(void)
{
return _CoreGl_mgr.majorVersion;
}

INLINE
int // OpenGL minor version
CoreGl_minorVersion(void)
{
return _CoreGl_mgr.minorVersion;
}

INLINE
bool // success
CoreGl_isAtLeastVersion(int major,
                        int minor)
{
return (_CoreGl_mgr.majorVersion>major)||
       ((_CoreGl_mgr.majorVersion==major)&&
        (_CoreGl_mgr.minorVersion>=minor));
}

INLINE
int // GLSL version
CoreGl_shadingLanguageVersion(void)
{
return _CoreGl_mgr.shadingLanguageVersion;
}

INLINE
bool // tessellation evaluation shaders are available
CoreGl_hasTessEvaluationShaders(void)
{
return _CoreGl_mgr.hasTessEvaluationShaders;
}

INLINE
bool // tessellation control shaders are available
CoreGl_hasTessControlShaders(void)
{
return _CoreGl_mgr.hasTessControlShaders;
}

INLINE
bool // geometry shaders are available
CoreGl_hasGeometryShaders(void)
{
return _CoreGl_mgr.hasGeometryShaders;
}

INLINE
bool // compute shaders are available
CoreGl_hasComputeShaders(void)
{
return _CoreGl_mgr.hasComputeShaders;
}

INLINE
const CoreGlComputeProperties * // compute shader properties or 0
CoreGl_computeProperties(void)
{
return _CoreGl_mgr.hasComputeShaders ? &_CoreGl_mgr.computeProperties
                                     : (const CoreGlComputeProperties *)0;
}

INLINE
const char * const * // extension name array
CoreGl_extensions(int *out_extensionCount)
{
*out_extensionCount=_CoreGl_mgr.extensionCount;
return (const char * const *)_CoreGl_mgr.extensions;
}

TRANSGL_API
bool // success
CoreGl_hasExtension(const char *extensionName);

TRANSGL_API
void * // symbol or 0
CoreGl_extensionSymbol(const char *symbolName);

#define CoreGl_extensionFunction(out_function,fnctName) \
        do                                              \
          {                                             \
          void *_symb=CoreGl_extensionSymbol(fnctName); \
          memcpy((out_function),&_symb,sizeof(void *)); \
          } while(0)

TRANSGL_API
void * // symbol or 0
CoreGl_extensionSymbolWithSuffix(const char *symbolName,
                                 const char * const *suffixList);

#define CoreGl_extensionFunctionWithSuffix(out_function,fnctName,suffixList) \
        do                                                                   \
          {                                                                  \
          void *_symb=CoreGl_extensionSymbolWithSuffix(fnctName,suffixList); \
          memcpy((out_function),&_symb,sizeof(void *));                      \
          } while(0)

TRANSGL_API
const char * // last OpenGL error message if any
CoreGl_lastError(void);

TRANSGL_API
char * // allocated compilation/link error/warning message if any
CoreGl_shaderStatus(GLuint shader,
                    bool *out_error);

TRANSGL_API
GLuint // compiled shader-object or 0
CoreGl_compileShader(GLenum shaderKind,
                     const char *sourceCode,
                     bool addPreamble,
                     char **out_allocatedCompilationLog);

TRANSGL_API
GLuint // linked shader-program or 0
CoreGl_buildRenderShader(const char *vertexSrc,
                         const char *geometrySrc,
                         const char *fragmentSrc,
                         bool addPreamble,
                         char **out_allocatedBuildLog);

TRANSGL_API
GLuint // linked shader-program or 0
CoreGl_buildComputeShader(const char *computeSrc,
                          bool addPreamble,
                          char **out_allocatedBuildLog);

//---- VERSION_1_0 ----

INLINE
bool
CoreGl_has_VERSION_1_0(void)
{
return _CoreGl_mgr.has_VERSION_1_0;
}

TRANSGL_API
PFNGLCULLFACEPROC
CoreGl_CullFace;
#define glCullFace \
        CoreGl_CullFace

TRANSGL_API
PFNGLFRONTFACEPROC
CoreGl_FrontFace;
#define glFrontFace \
        CoreGl_FrontFace

TRANSGL_API
PFNGLHINTPROC
CoreGl_Hint;
#define glHint \
        CoreGl_Hint

TRANSGL_API
PFNGLLINEWIDTHPROC
CoreGl_LineWidth;
#define glLineWidth \
        CoreGl_LineWidth

TRANSGL_API
PFNGLPOINTSIZEPROC
CoreGl_PointSize;
#define glPointSize \
        CoreGl_PointSize

TRANSGL_API
PFNGLPOLYGONMODEPROC
CoreGl_PolygonMode;
#define glPolygonMode \
        CoreGl_PolygonMode

TRANSGL_API
PFNGLSCISSORPROC
CoreGl_Scissor;
#define glScissor \
        CoreGl_Scissor

TRANSGL_API
PFNGLTEXPARAMETERFPROC
CoreGl_TexParameterf;
#define glTexParameterf \
        CoreGl_TexParameterf

TRANSGL_API
PFNGLTEXPARAMETERFVPROC
CoreGl_TexParameterfv;
#define glTexParameterfv \
        CoreGl_TexParameterfv

TRANSGL_API
PFNGLTEXPARAMETERIPROC
CoreGl_TexParameteri;
#define glTexParameteri \
        CoreGl_TexParameteri

TRANSGL_API
PFNGLTEXPARAMETERIVPROC
CoreGl_TexParameteriv;
#define glTexParameteriv \
        CoreGl_TexParameteriv

TRANSGL_API
PFNGLTEXIMAGE1DPROC
CoreGl_TexImage1D;
#define glTexImage1D \
        CoreGl_TexImage1D

TRANSGL_API
PFNGLTEXIMAGE2DPROC
CoreGl_TexImage2D;
#define glTexImage2D \
        CoreGl_TexImage2D

TRANSGL_API
PFNGLDRAWBUFFERPROC
CoreGl_DrawBuffer;
#define glDrawBuffer \
        CoreGl_DrawBuffer

TRANSGL_API
PFNGLCLEARPROC
CoreGl_Clear;
#define glClear \
        CoreGl_Clear

TRANSGL_API
PFNGLCLEARCOLORPROC
CoreGl_ClearColor;
#define glClearColor \
        CoreGl_ClearColor

TRANSGL_API
PFNGLCLEARSTENCILPROC
CoreGl_ClearStencil;
#define glClearStencil \
        CoreGl_ClearStencil

TRANSGL_API
PFNGLCLEARDEPTHPROC
CoreGl_ClearDepth;
#define glClearDepth \
        CoreGl_ClearDepth

TRANSGL_API
PFNGLSTENCILMASKPROC
CoreGl_StencilMask;
#define glStencilMask \
        CoreGl_StencilMask

TRANSGL_API
PFNGLCOLORMASKPROC
CoreGl_ColorMask;
#define glColorMask \
        CoreGl_ColorMask

TRANSGL_API
PFNGLDEPTHMASKPROC
CoreGl_DepthMask;
#define glDepthMask \
        CoreGl_DepthMask

TRANSGL_API
PFNGLDISABLEPROC
CoreGl_Disable;
#define glDisable \
        CoreGl_Disable

TRANSGL_API
PFNGLENABLEPROC
CoreGl_Enable;
#define glEnable \
        CoreGl_Enable

TRANSGL_API
PFNGLFINISHPROC
CoreGl_Finish;
#define glFinish \
        CoreGl_Finish

TRANSGL_API
PFNGLFLUSHPROC
CoreGl_Flush;
#define glFlush \
        CoreGl_Flush

TRANSGL_API
PFNGLBLENDFUNCPROC
CoreGl_BlendFunc;
#define glBlendFunc \
        CoreGl_BlendFunc

TRANSGL_API
PFNGLLOGICOPPROC
CoreGl_LogicOp;
#define glLogicOp \
        CoreGl_LogicOp

TRANSGL_API
PFNGLSTENCILFUNCPROC
CoreGl_StencilFunc;
#define glStencilFunc \
        CoreGl_StencilFunc

TRANSGL_API
PFNGLSTENCILOPPROC
CoreGl_StencilOp;
#define glStencilOp \
        CoreGl_StencilOp

TRANSGL_API
PFNGLDEPTHFUNCPROC
CoreGl_DepthFunc;
#define glDepthFunc \
        CoreGl_DepthFunc

TRANSGL_API
PFNGLPIXELSTOREFPROC
CoreGl_PixelStoref;
#define glPixelStoref \
        CoreGl_PixelStoref

TRANSGL_API
PFNGLPIXELSTOREIPROC
CoreGl_PixelStorei;
#define glPixelStorei \
        CoreGl_PixelStorei

TRANSGL_API
PFNGLREADBUFFERPROC
CoreGl_ReadBuffer;
#define glReadBuffer \
        CoreGl_ReadBuffer

TRANSGL_API
PFNGLREADPIXELSPROC
CoreGl_ReadPixels;
#define glReadPixels \
        CoreGl_ReadPixels

TRANSGL_API
PFNGLGETBOOLEANVPROC
CoreGl_GetBooleanv;
#define glGetBooleanv \
        CoreGl_GetBooleanv

TRANSGL_API
PFNGLGETDOUBLEVPROC
CoreGl_GetDoublev;
#define glGetDoublev \
        CoreGl_GetDoublev

TRANSGL_API
PFNGLGETERRORPROC
CoreGl_GetError;
#define glGetError \
        CoreGl_GetError

TRANSGL_API
PFNGLGETFLOATVPROC
CoreGl_GetFloatv;
#define glGetFloatv \
        CoreGl_GetFloatv

TRANSGL_API
PFNGLGETINTEGERVPROC
CoreGl_GetIntegerv;
#define glGetIntegerv \
        CoreGl_GetIntegerv

TRANSGL_API
PFNGLGETSTRINGPROC
CoreGl_GetString;
#define glGetString \
        CoreGl_GetString

TRANSGL_API
PFNGLGETTEXIMAGEPROC
CoreGl_GetTexImage;
#define glGetTexImage \
        CoreGl_GetTexImage

TRANSGL_API
PFNGLGETTEXPARAMETERFVPROC
CoreGl_GetTexParameterfv;
#define glGetTexParameterfv \
        CoreGl_GetTexParameterfv

TRANSGL_API
PFNGLGETTEXPARAMETERIVPROC
CoreGl_GetTexParameteriv;
#define glGetTexParameteriv \
        CoreGl_GetTexParameteriv

TRANSGL_API
PFNGLGETTEXLEVELPARAMETERFVPROC
CoreGl_GetTexLevelParameterfv;
#define glGetTexLevelParameterfv \
        CoreGl_GetTexLevelParameterfv

TRANSGL_API
PFNGLGETTEXLEVELPARAMETERIVPROC
CoreGl_GetTexLevelParameteriv;
#define glGetTexLevelParameteriv \
        CoreGl_GetTexLevelParameteriv

TRANSGL_API
PFNGLISENABLEDPROC
CoreGl_IsEnabled;
#define glIsEnabled \
        CoreGl_IsEnabled

TRANSGL_API
PFNGLDEPTHRANGEPROC
CoreGl_DepthRange;
#define glDepthRange \
        CoreGl_DepthRange

TRANSGL_API
PFNGLVIEWPORTPROC
CoreGl_Viewport;
#define glViewport \
        CoreGl_Viewport

//---- VERSION_1_1 ----

INLINE
bool
CoreGl_has_VERSION_1_1(void)
{
return _CoreGl_mgr.has_VERSION_1_1;
}

TRANSGL_API
PFNGLDRAWARRAYSPROC
CoreGl_DrawArrays;
#define glDrawArrays \
        CoreGl_DrawArrays

TRANSGL_API
PFNGLDRAWELEMENTSPROC
CoreGl_DrawElements;
#define glDrawElements \
        CoreGl_DrawElements

TRANSGL_API
PFNGLGETPOINTERVPROC
CoreGl_GetPointerv;
#define glGetPointerv \
        CoreGl_GetPointerv

TRANSGL_API
PFNGLPOLYGONOFFSETPROC
CoreGl_PolygonOffset;
#define glPolygonOffset \
        CoreGl_PolygonOffset

TRANSGL_API
PFNGLCOPYTEXIMAGE1DPROC
CoreGl_CopyTexImage1D;
#define glCopyTexImage1D \
        CoreGl_CopyTexImage1D

TRANSGL_API
PFNGLCOPYTEXIMAGE2DPROC
CoreGl_CopyTexImage2D;
#define glCopyTexImage2D \
        CoreGl_CopyTexImage2D

TRANSGL_API
PFNGLCOPYTEXSUBIMAGE1DPROC
CoreGl_CopyTexSubImage1D;
#define glCopyTexSubImage1D \
        CoreGl_CopyTexSubImage1D

TRANSGL_API
PFNGLCOPYTEXSUBIMAGE2DPROC
CoreGl_CopyTexSubImage2D;
#define glCopyTexSubImage2D \
        CoreGl_CopyTexSubImage2D

TRANSGL_API
PFNGLTEXSUBIMAGE1DPROC
CoreGl_TexSubImage1D;
#define glTexSubImage1D \
        CoreGl_TexSubImage1D

TRANSGL_API
PFNGLTEXSUBIMAGE2DPROC
CoreGl_TexSubImage2D;
#define glTexSubImage2D \
        CoreGl_TexSubImage2D

TRANSGL_API
PFNGLBINDTEXTUREPROC
CoreGl_BindTexture;
#define glBindTexture \
        CoreGl_BindTexture

TRANSGL_API
PFNGLDELETETEXTURESPROC
CoreGl_DeleteTextures;
#define glDeleteTextures \
        CoreGl_DeleteTextures

TRANSGL_API
PFNGLGENTEXTURESPROC
CoreGl_GenTextures;
#define glGenTextures \
        CoreGl_GenTextures

TRANSGL_API
PFNGLISTEXTUREPROC
CoreGl_IsTexture;
#define glIsTexture \
        CoreGl_IsTexture

//---- VERSION_1_2 ----

INLINE
bool
CoreGl_has_VERSION_1_2(void)
{
return _CoreGl_mgr.has_VERSION_1_2;
}

TRANSGL_API
PFNGLDRAWRANGEELEMENTSPROC
CoreGl_DrawRangeElements;
#define glDrawRangeElements \
        CoreGl_DrawRangeElements

TRANSGL_API
PFNGLTEXIMAGE3DPROC
CoreGl_TexImage3D;
#define glTexImage3D \
        CoreGl_TexImage3D

TRANSGL_API
PFNGLTEXSUBIMAGE3DPROC
CoreGl_TexSubImage3D;
#define glTexSubImage3D \
        CoreGl_TexSubImage3D

TRANSGL_API
PFNGLCOPYTEXSUBIMAGE3DPROC
CoreGl_CopyTexSubImage3D;
#define glCopyTexSubImage3D \
        CoreGl_CopyTexSubImage3D

//---- VERSION_1_3 ----

INLINE
bool
CoreGl_has_VERSION_1_3(void)
{
return _CoreGl_mgr.has_VERSION_1_3;
}

TRANSGL_API
PFNGLACTIVETEXTUREPROC
CoreGl_ActiveTexture;
#define glActiveTexture \
        CoreGl_ActiveTexture

TRANSGL_API
PFNGLSAMPLECOVERAGEPROC
CoreGl_SampleCoverage;
#define glSampleCoverage \
        CoreGl_SampleCoverage

TRANSGL_API
PFNGLCOMPRESSEDTEXIMAGE3DPROC
CoreGl_CompressedTexImage3D;
#define glCompressedTexImage3D \
        CoreGl_CompressedTexImage3D

TRANSGL_API
PFNGLCOMPRESSEDTEXIMAGE2DPROC
CoreGl_CompressedTexImage2D;
#define glCompressedTexImage2D \
        CoreGl_CompressedTexImage2D

TRANSGL_API
PFNGLCOMPRESSEDTEXIMAGE1DPROC
CoreGl_CompressedTexImage1D;
#define glCompressedTexImage1D \
        CoreGl_CompressedTexImage1D

TRANSGL_API
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC
CoreGl_CompressedTexSubImage3D;
#define glCompressedTexSubImage3D \
        CoreGl_CompressedTexSubImage3D

TRANSGL_API
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC
CoreGl_CompressedTexSubImage2D;
#define glCompressedTexSubImage2D \
        CoreGl_CompressedTexSubImage2D

TRANSGL_API
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC
CoreGl_CompressedTexSubImage1D;
#define glCompressedTexSubImage1D \
        CoreGl_CompressedTexSubImage1D

TRANSGL_API
PFNGLGETCOMPRESSEDTEXIMAGEPROC
CoreGl_GetCompressedTexImage;
#define glGetCompressedTexImage \
        CoreGl_GetCompressedTexImage

//---- VERSION_1_4 ----

INLINE
bool
CoreGl_has_VERSION_1_4(void)
{
return _CoreGl_mgr.has_VERSION_1_4;
}

TRANSGL_API
PFNGLBLENDFUNCSEPARATEPROC
CoreGl_BlendFuncSeparate;
#define glBlendFuncSeparate \
        CoreGl_BlendFuncSeparate

TRANSGL_API
PFNGLMULTIDRAWARRAYSPROC
CoreGl_MultiDrawArrays;
#define glMultiDrawArrays \
        CoreGl_MultiDrawArrays

TRANSGL_API
PFNGLMULTIDRAWELEMENTSPROC
CoreGl_MultiDrawElements;
#define glMultiDrawElements \
        CoreGl_MultiDrawElements

TRANSGL_API
PFNGLPOINTPARAMETERFPROC
CoreGl_PointParameterf;
#define glPointParameterf \
        CoreGl_PointParameterf

TRANSGL_API
PFNGLPOINTPARAMETERFVPROC
CoreGl_PointParameterfv;
#define glPointParameterfv \
        CoreGl_PointParameterfv

TRANSGL_API
PFNGLPOINTPARAMETERIPROC
CoreGl_PointParameteri;
#define glPointParameteri \
        CoreGl_PointParameteri

TRANSGL_API
PFNGLPOINTPARAMETERIVPROC
CoreGl_PointParameteriv;
#define glPointParameteriv \
        CoreGl_PointParameteriv

TRANSGL_API
PFNGLBLENDCOLORPROC
CoreGl_BlendColor;
#define glBlendColor \
        CoreGl_BlendColor

TRANSGL_API
PFNGLBLENDEQUATIONPROC
CoreGl_BlendEquation;
#define glBlendEquation \
        CoreGl_BlendEquation

//---- VERSION_1_5 ----

INLINE
bool
CoreGl_has_VERSION_1_5(void)
{
return _CoreGl_mgr.has_VERSION_1_5;
}

TRANSGL_API
PFNGLGENQUERIESPROC
CoreGl_GenQueries;
#define glGenQueries \
        CoreGl_GenQueries

TRANSGL_API
PFNGLDELETEQUERIESPROC
CoreGl_DeleteQueries;
#define glDeleteQueries \
        CoreGl_DeleteQueries

TRANSGL_API
PFNGLISQUERYPROC
CoreGl_IsQuery;
#define glIsQuery \
        CoreGl_IsQuery

TRANSGL_API
PFNGLBEGINQUERYPROC
CoreGl_BeginQuery;
#define glBeginQuery \
        CoreGl_BeginQuery

TRANSGL_API
PFNGLENDQUERYPROC
CoreGl_EndQuery;
#define glEndQuery \
        CoreGl_EndQuery

TRANSGL_API
PFNGLGETQUERYIVPROC
CoreGl_GetQueryiv;
#define glGetQueryiv \
        CoreGl_GetQueryiv

TRANSGL_API
PFNGLGETQUERYOBJECTIVPROC
CoreGl_GetQueryObjectiv;
#define glGetQueryObjectiv \
        CoreGl_GetQueryObjectiv

TRANSGL_API
PFNGLGETQUERYOBJECTUIVPROC
CoreGl_GetQueryObjectuiv;
#define glGetQueryObjectuiv \
        CoreGl_GetQueryObjectuiv

TRANSGL_API
PFNGLBINDBUFFERPROC
CoreGl_BindBuffer;
#define glBindBuffer \
        CoreGl_BindBuffer

TRANSGL_API
PFNGLDELETEBUFFERSPROC
CoreGl_DeleteBuffers;
#define glDeleteBuffers \
        CoreGl_DeleteBuffers

TRANSGL_API
PFNGLGENBUFFERSPROC
CoreGl_GenBuffers;
#define glGenBuffers \
        CoreGl_GenBuffers

TRANSGL_API
PFNGLISBUFFERPROC
CoreGl_IsBuffer;
#define glIsBuffer \
        CoreGl_IsBuffer

TRANSGL_API
PFNGLBUFFERDATAPROC
CoreGl_BufferData;
#define glBufferData \
        CoreGl_BufferData

TRANSGL_API
PFNGLBUFFERSUBDATAPROC
CoreGl_BufferSubData;
#define glBufferSubData \
        CoreGl_BufferSubData

TRANSGL_API
PFNGLGETBUFFERSUBDATAPROC
CoreGl_GetBufferSubData;
#define glGetBufferSubData \
        CoreGl_GetBufferSubData

TRANSGL_API
PFNGLMAPBUFFERPROC
CoreGl_MapBuffer;
#define glMapBuffer \
        CoreGl_MapBuffer

TRANSGL_API
PFNGLUNMAPBUFFERPROC
CoreGl_UnmapBuffer;
#define glUnmapBuffer \
        CoreGl_UnmapBuffer

TRANSGL_API
PFNGLGETBUFFERPARAMETERIVPROC
CoreGl_GetBufferParameteriv;
#define glGetBufferParameteriv \
        CoreGl_GetBufferParameteriv

TRANSGL_API
PFNGLGETBUFFERPOINTERVPROC
CoreGl_GetBufferPointerv;
#define glGetBufferPointerv \
        CoreGl_GetBufferPointerv

//---- VERSION_2_0 ----

INLINE
bool
CoreGl_has_VERSION_2_0(void)
{
return _CoreGl_mgr.has_VERSION_2_0;
}

TRANSGL_API
PFNGLBLENDEQUATIONSEPARATEPROC
CoreGl_BlendEquationSeparate;
#define glBlendEquationSeparate \
        CoreGl_BlendEquationSeparate

TRANSGL_API
PFNGLDRAWBUFFERSPROC
CoreGl_DrawBuffers;
#define glDrawBuffers \
        CoreGl_DrawBuffers

TRANSGL_API
PFNGLSTENCILOPSEPARATEPROC
CoreGl_StencilOpSeparate;
#define glStencilOpSeparate \
        CoreGl_StencilOpSeparate

TRANSGL_API
PFNGLSTENCILFUNCSEPARATEPROC
CoreGl_StencilFuncSeparate;
#define glStencilFuncSeparate \
        CoreGl_StencilFuncSeparate

TRANSGL_API
PFNGLSTENCILMASKSEPARATEPROC
CoreGl_StencilMaskSeparate;
#define glStencilMaskSeparate \
        CoreGl_StencilMaskSeparate

TRANSGL_API
PFNGLATTACHSHADERPROC
CoreGl_AttachShader;
#define glAttachShader \
        CoreGl_AttachShader

TRANSGL_API
PFNGLBINDATTRIBLOCATIONPROC
CoreGl_BindAttribLocation;
#define glBindAttribLocation \
        CoreGl_BindAttribLocation

TRANSGL_API
PFNGLCOMPILESHADERPROC
CoreGl_CompileShader;
#define glCompileShader \
        CoreGl_CompileShader

TRANSGL_API
PFNGLCREATEPROGRAMPROC
CoreGl_CreateProgram;
#define glCreateProgram \
        CoreGl_CreateProgram

TRANSGL_API
PFNGLCREATESHADERPROC
CoreGl_CreateShader;
#define glCreateShader \
        CoreGl_CreateShader

TRANSGL_API
PFNGLDELETEPROGRAMPROC
CoreGl_DeleteProgram;
#define glDeleteProgram \
        CoreGl_DeleteProgram

TRANSGL_API
PFNGLDELETESHADERPROC
CoreGl_DeleteShader;
#define glDeleteShader \
        CoreGl_DeleteShader

TRANSGL_API
PFNGLDETACHSHADERPROC
CoreGl_DetachShader;
#define glDetachShader \
        CoreGl_DetachShader

TRANSGL_API
PFNGLDISABLEVERTEXATTRIBARRAYPROC
CoreGl_DisableVertexAttribArray;
#define glDisableVertexAttribArray \
        CoreGl_DisableVertexAttribArray

TRANSGL_API
PFNGLENABLEVERTEXATTRIBARRAYPROC
CoreGl_EnableVertexAttribArray;
#define glEnableVertexAttribArray \
        CoreGl_EnableVertexAttribArray

TRANSGL_API
PFNGLGETACTIVEATTRIBPROC
CoreGl_GetActiveAttrib;
#define glGetActiveAttrib \
        CoreGl_GetActiveAttrib

TRANSGL_API
PFNGLGETACTIVEUNIFORMPROC
CoreGl_GetActiveUniform;
#define glGetActiveUniform \
        CoreGl_GetActiveUniform

TRANSGL_API
PFNGLGETATTACHEDSHADERSPROC
CoreGl_GetAttachedShaders;
#define glGetAttachedShaders \
        CoreGl_GetAttachedShaders

TRANSGL_API
PFNGLGETATTRIBLOCATIONPROC
CoreGl_GetAttribLocation;
#define glGetAttribLocation \
        CoreGl_GetAttribLocation

TRANSGL_API
PFNGLGETPROGRAMIVPROC
CoreGl_GetProgramiv;
#define glGetProgramiv \
        CoreGl_GetProgramiv

TRANSGL_API
PFNGLGETPROGRAMINFOLOGPROC
CoreGl_GetProgramInfoLog;
#define glGetProgramInfoLog \
        CoreGl_GetProgramInfoLog

TRANSGL_API
PFNGLGETSHADERIVPROC
CoreGl_GetShaderiv;
#define glGetShaderiv \
        CoreGl_GetShaderiv

TRANSGL_API
PFNGLGETSHADERINFOLOGPROC
CoreGl_GetShaderInfoLog;
#define glGetShaderInfoLog \
        CoreGl_GetShaderInfoLog

TRANSGL_API
PFNGLGETSHADERSOURCEPROC
CoreGl_GetShaderSource;
#define glGetShaderSource \
        CoreGl_GetShaderSource

TRANSGL_API
PFNGLGETUNIFORMLOCATIONPROC
CoreGl_GetUniformLocation;
#define glGetUniformLocation \
        CoreGl_GetUniformLocation

TRANSGL_API
PFNGLGETUNIFORMFVPROC
CoreGl_GetUniformfv;
#define glGetUniformfv \
        CoreGl_GetUniformfv

TRANSGL_API
PFNGLGETUNIFORMIVPROC
CoreGl_GetUniformiv;
#define glGetUniformiv \
        CoreGl_GetUniformiv

TRANSGL_API
PFNGLGETVERTEXATTRIBDVPROC
CoreGl_GetVertexAttribdv;
#define glGetVertexAttribdv \
        CoreGl_GetVertexAttribdv

TRANSGL_API
PFNGLGETVERTEXATTRIBFVPROC
CoreGl_GetVertexAttribfv;
#define glGetVertexAttribfv \
        CoreGl_GetVertexAttribfv

TRANSGL_API
PFNGLGETVERTEXATTRIBIVPROC
CoreGl_GetVertexAttribiv;
#define glGetVertexAttribiv \
        CoreGl_GetVertexAttribiv

TRANSGL_API
PFNGLGETVERTEXATTRIBPOINTERVPROC
CoreGl_GetVertexAttribPointerv;
#define glGetVertexAttribPointerv \
        CoreGl_GetVertexAttribPointerv

TRANSGL_API
PFNGLISPROGRAMPROC
CoreGl_IsProgram;
#define glIsProgram \
        CoreGl_IsProgram

TRANSGL_API
PFNGLISSHADERPROC
CoreGl_IsShader;
#define glIsShader \
        CoreGl_IsShader

TRANSGL_API
PFNGLLINKPROGRAMPROC
CoreGl_LinkProgram;
#define glLinkProgram \
        CoreGl_LinkProgram

TRANSGL_API
PFNGLSHADERSOURCEPROC
CoreGl_ShaderSource;
#define glShaderSource \
        CoreGl_ShaderSource

TRANSGL_API
PFNGLUSEPROGRAMPROC
CoreGl_UseProgram;
#define glUseProgram \
        CoreGl_UseProgram

TRANSGL_API
PFNGLUNIFORM1FPROC
CoreGl_Uniform1f;
#define glUniform1f \
        CoreGl_Uniform1f

TRANSGL_API
PFNGLUNIFORM2FPROC
CoreGl_Uniform2f;
#define glUniform2f \
        CoreGl_Uniform2f

TRANSGL_API
PFNGLUNIFORM3FPROC
CoreGl_Uniform3f;
#define glUniform3f \
        CoreGl_Uniform3f

TRANSGL_API
PFNGLUNIFORM4FPROC
CoreGl_Uniform4f;
#define glUniform4f \
        CoreGl_Uniform4f

TRANSGL_API
PFNGLUNIFORM1IPROC
CoreGl_Uniform1i;
#define glUniform1i \
        CoreGl_Uniform1i

TRANSGL_API
PFNGLUNIFORM2IPROC
CoreGl_Uniform2i;
#define glUniform2i \
        CoreGl_Uniform2i

TRANSGL_API
PFNGLUNIFORM3IPROC
CoreGl_Uniform3i;
#define glUniform3i \
        CoreGl_Uniform3i

TRANSGL_API
PFNGLUNIFORM4IPROC
CoreGl_Uniform4i;
#define glUniform4i \
        CoreGl_Uniform4i

TRANSGL_API
PFNGLUNIFORM1FVPROC
CoreGl_Uniform1fv;
#define glUniform1fv \
        CoreGl_Uniform1fv

TRANSGL_API
PFNGLUNIFORM2FVPROC
CoreGl_Uniform2fv;
#define glUniform2fv \
        CoreGl_Uniform2fv

TRANSGL_API
PFNGLUNIFORM3FVPROC
CoreGl_Uniform3fv;
#define glUniform3fv \
        CoreGl_Uniform3fv

TRANSGL_API
PFNGLUNIFORM4FVPROC
CoreGl_Uniform4fv;
#define glUniform4fv \
        CoreGl_Uniform4fv

TRANSGL_API
PFNGLUNIFORM1IVPROC
CoreGl_Uniform1iv;
#define glUniform1iv \
        CoreGl_Uniform1iv

TRANSGL_API
PFNGLUNIFORM2IVPROC
CoreGl_Uniform2iv;
#define glUniform2iv \
        CoreGl_Uniform2iv

TRANSGL_API
PFNGLUNIFORM3IVPROC
CoreGl_Uniform3iv;
#define glUniform3iv \
        CoreGl_Uniform3iv

TRANSGL_API
PFNGLUNIFORM4IVPROC
CoreGl_Uniform4iv;
#define glUniform4iv \
        CoreGl_Uniform4iv

TRANSGL_API
PFNGLUNIFORMMATRIX2FVPROC
CoreGl_UniformMatrix2fv;
#define glUniformMatrix2fv \
        CoreGl_UniformMatrix2fv

TRANSGL_API
PFNGLUNIFORMMATRIX3FVPROC
CoreGl_UniformMatrix3fv;
#define glUniformMatrix3fv \
        CoreGl_UniformMatrix3fv

TRANSGL_API
PFNGLUNIFORMMATRIX4FVPROC
CoreGl_UniformMatrix4fv;
#define glUniformMatrix4fv \
        CoreGl_UniformMatrix4fv

TRANSGL_API
PFNGLVALIDATEPROGRAMPROC
CoreGl_ValidateProgram;
#define glValidateProgram \
        CoreGl_ValidateProgram

TRANSGL_API
PFNGLVERTEXATTRIB1DPROC
CoreGl_VertexAttrib1d;
#define glVertexAttrib1d \
        CoreGl_VertexAttrib1d

TRANSGL_API
PFNGLVERTEXATTRIB1DVPROC
CoreGl_VertexAttrib1dv;
#define glVertexAttrib1dv \
        CoreGl_VertexAttrib1dv

TRANSGL_API
PFNGLVERTEXATTRIB1FPROC
CoreGl_VertexAttrib1f;
#define glVertexAttrib1f \
        CoreGl_VertexAttrib1f

TRANSGL_API
PFNGLVERTEXATTRIB1FVPROC
CoreGl_VertexAttrib1fv;
#define glVertexAttrib1fv \
        CoreGl_VertexAttrib1fv

TRANSGL_API
PFNGLVERTEXATTRIB1SPROC
CoreGl_VertexAttrib1s;
#define glVertexAttrib1s \
        CoreGl_VertexAttrib1s

TRANSGL_API
PFNGLVERTEXATTRIB1SVPROC
CoreGl_VertexAttrib1sv;
#define glVertexAttrib1sv \
        CoreGl_VertexAttrib1sv

TRANSGL_API
PFNGLVERTEXATTRIB2DPROC
CoreGl_VertexAttrib2d;
#define glVertexAttrib2d \
        CoreGl_VertexAttrib2d

TRANSGL_API
PFNGLVERTEXATTRIB2DVPROC
CoreGl_VertexAttrib2dv;
#define glVertexAttrib2dv \
        CoreGl_VertexAttrib2dv

TRANSGL_API
PFNGLVERTEXATTRIB2FPROC
CoreGl_VertexAttrib2f;
#define glVertexAttrib2f \
        CoreGl_VertexAttrib2f

TRANSGL_API
PFNGLVERTEXATTRIB2FVPROC
CoreGl_VertexAttrib2fv;
#define glVertexAttrib2fv \
        CoreGl_VertexAttrib2fv

TRANSGL_API
PFNGLVERTEXATTRIB2SPROC
CoreGl_VertexAttrib2s;
#define glVertexAttrib2s \
        CoreGl_VertexAttrib2s

TRANSGL_API
PFNGLVERTEXATTRIB2SVPROC
CoreGl_VertexAttrib2sv;
#define glVertexAttrib2sv \
        CoreGl_VertexAttrib2sv

TRANSGL_API
PFNGLVERTEXATTRIB3DPROC
CoreGl_VertexAttrib3d;
#define glVertexAttrib3d \
        CoreGl_VertexAttrib3d

TRANSGL_API
PFNGLVERTEXATTRIB3DVPROC
CoreGl_VertexAttrib3dv;
#define glVertexAttrib3dv \
        CoreGl_VertexAttrib3dv

TRANSGL_API
PFNGLVERTEXATTRIB3FPROC
CoreGl_VertexAttrib3f;
#define glVertexAttrib3f \
        CoreGl_VertexAttrib3f

TRANSGL_API
PFNGLVERTEXATTRIB3FVPROC
CoreGl_VertexAttrib3fv;
#define glVertexAttrib3fv \
        CoreGl_VertexAttrib3fv

TRANSGL_API
PFNGLVERTEXATTRIB3SPROC
CoreGl_VertexAttrib3s;
#define glVertexAttrib3s \
        CoreGl_VertexAttrib3s

TRANSGL_API
PFNGLVERTEXATTRIB3SVPROC
CoreGl_VertexAttrib3sv;
#define glVertexAttrib3sv \
        CoreGl_VertexAttrib3sv

TRANSGL_API
PFNGLVERTEXATTRIB4NBVPROC
CoreGl_VertexAttrib4Nbv;
#define glVertexAttrib4Nbv \
        CoreGl_VertexAttrib4Nbv

TRANSGL_API
PFNGLVERTEXATTRIB4NIVPROC
CoreGl_VertexAttrib4Niv;
#define glVertexAttrib4Niv \
        CoreGl_VertexAttrib4Niv

TRANSGL_API
PFNGLVERTEXATTRIB4NSVPROC
CoreGl_VertexAttrib4Nsv;
#define glVertexAttrib4Nsv \
        CoreGl_VertexAttrib4Nsv

TRANSGL_API
PFNGLVERTEXATTRIB4NUBPROC
CoreGl_VertexAttrib4Nub;
#define glVertexAttrib4Nub \
        CoreGl_VertexAttrib4Nub

TRANSGL_API
PFNGLVERTEXATTRIB4NUBVPROC
CoreGl_VertexAttrib4Nubv;
#define glVertexAttrib4Nubv \
        CoreGl_VertexAttrib4Nubv

TRANSGL_API
PFNGLVERTEXATTRIB4NUIVPROC
CoreGl_VertexAttrib4Nuiv;
#define glVertexAttrib4Nuiv \
        CoreGl_VertexAttrib4Nuiv

TRANSGL_API
PFNGLVERTEXATTRIB4NUSVPROC
CoreGl_VertexAttrib4Nusv;
#define glVertexAttrib4Nusv \
        CoreGl_VertexAttrib4Nusv

TRANSGL_API
PFNGLVERTEXATTRIB4BVPROC
CoreGl_VertexAttrib4bv;
#define glVertexAttrib4bv \
        CoreGl_VertexAttrib4bv

TRANSGL_API
PFNGLVERTEXATTRIB4DPROC
CoreGl_VertexAttrib4d;
#define glVertexAttrib4d \
        CoreGl_VertexAttrib4d

TRANSGL_API
PFNGLVERTEXATTRIB4DVPROC
CoreGl_VertexAttrib4dv;
#define glVertexAttrib4dv \
        CoreGl_VertexAttrib4dv

TRANSGL_API
PFNGLVERTEXATTRIB4FPROC
CoreGl_VertexAttrib4f;
#define glVertexAttrib4f \
        CoreGl_VertexAttrib4f

TRANSGL_API
PFNGLVERTEXATTRIB4FVPROC
CoreGl_VertexAttrib4fv;
#define glVertexAttrib4fv \
        CoreGl_VertexAttrib4fv

TRANSGL_API
PFNGLVERTEXATTRIB4IVPROC
CoreGl_VertexAttrib4iv;
#define glVertexAttrib4iv \
        CoreGl_VertexAttrib4iv

TRANSGL_API
PFNGLVERTEXATTRIB4SPROC
CoreGl_VertexAttrib4s;
#define glVertexAttrib4s \
        CoreGl_VertexAttrib4s

TRANSGL_API
PFNGLVERTEXATTRIB4SVPROC
CoreGl_VertexAttrib4sv;
#define glVertexAttrib4sv \
        CoreGl_VertexAttrib4sv

TRANSGL_API
PFNGLVERTEXATTRIB4UBVPROC
CoreGl_VertexAttrib4ubv;
#define glVertexAttrib4ubv \
        CoreGl_VertexAttrib4ubv

TRANSGL_API
PFNGLVERTEXATTRIB4UIVPROC
CoreGl_VertexAttrib4uiv;
#define glVertexAttrib4uiv \
        CoreGl_VertexAttrib4uiv

TRANSGL_API
PFNGLVERTEXATTRIB4USVPROC
CoreGl_VertexAttrib4usv;
#define glVertexAttrib4usv \
        CoreGl_VertexAttrib4usv

TRANSGL_API
PFNGLVERTEXATTRIBPOINTERPROC
CoreGl_VertexAttribPointer;
#define glVertexAttribPointer \
        CoreGl_VertexAttribPointer

//---- VERSION_2_1 ----

INLINE
bool
CoreGl_has_VERSION_2_1(void)
{
return _CoreGl_mgr.has_VERSION_2_1;
}

TRANSGL_API
PFNGLUNIFORMMATRIX2X3FVPROC
CoreGl_UniformMatrix2x3fv;
#define glUniformMatrix2x3fv \
        CoreGl_UniformMatrix2x3fv

TRANSGL_API
PFNGLUNIFORMMATRIX3X2FVPROC
CoreGl_UniformMatrix3x2fv;
#define glUniformMatrix3x2fv \
        CoreGl_UniformMatrix3x2fv

TRANSGL_API
PFNGLUNIFORMMATRIX2X4FVPROC
CoreGl_UniformMatrix2x4fv;
#define glUniformMatrix2x4fv \
        CoreGl_UniformMatrix2x4fv

TRANSGL_API
PFNGLUNIFORMMATRIX4X2FVPROC
CoreGl_UniformMatrix4x2fv;
#define glUniformMatrix4x2fv \
        CoreGl_UniformMatrix4x2fv

TRANSGL_API
PFNGLUNIFORMMATRIX3X4FVPROC
CoreGl_UniformMatrix3x4fv;
#define glUniformMatrix3x4fv \
        CoreGl_UniformMatrix3x4fv

TRANSGL_API
PFNGLUNIFORMMATRIX4X3FVPROC
CoreGl_UniformMatrix4x3fv;
#define glUniformMatrix4x3fv \
        CoreGl_UniformMatrix4x3fv

//---- VERSION_3_0 ----

INLINE
bool
CoreGl_has_VERSION_3_0(void)
{
return _CoreGl_mgr.has_VERSION_3_0;
}

TRANSGL_API
PFNGLCOLORMASKIPROC
CoreGl_ColorMaski;
#define glColorMaski \
        CoreGl_ColorMaski

TRANSGL_API
PFNGLGETBOOLEANI_VPROC
CoreGl_GetBooleani_v;
#define glGetBooleani_v \
        CoreGl_GetBooleani_v

TRANSGL_API
PFNGLGETINTEGERI_VPROC
CoreGl_GetIntegeri_v;
#define glGetIntegeri_v \
        CoreGl_GetIntegeri_v

TRANSGL_API
PFNGLENABLEIPROC
CoreGl_Enablei;
#define glEnablei \
        CoreGl_Enablei

TRANSGL_API
PFNGLDISABLEIPROC
CoreGl_Disablei;
#define glDisablei \
        CoreGl_Disablei

TRANSGL_API
PFNGLISENABLEDIPROC
CoreGl_IsEnabledi;
#define glIsEnabledi \
        CoreGl_IsEnabledi

TRANSGL_API
PFNGLBEGINTRANSFORMFEEDBACKPROC
CoreGl_BeginTransformFeedback;
#define glBeginTransformFeedback \
        CoreGl_BeginTransformFeedback

TRANSGL_API
PFNGLENDTRANSFORMFEEDBACKPROC
CoreGl_EndTransformFeedback;
#define glEndTransformFeedback \
        CoreGl_EndTransformFeedback

TRANSGL_API
PFNGLBINDBUFFERRANGEPROC
CoreGl_BindBufferRange;
#define glBindBufferRange \
        CoreGl_BindBufferRange

TRANSGL_API
PFNGLBINDBUFFERBASEPROC
CoreGl_BindBufferBase;
#define glBindBufferBase \
        CoreGl_BindBufferBase

TRANSGL_API
PFNGLTRANSFORMFEEDBACKVARYINGSPROC
CoreGl_TransformFeedbackVaryings;
#define glTransformFeedbackVaryings \
        CoreGl_TransformFeedbackVaryings

TRANSGL_API
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC
CoreGl_GetTransformFeedbackVarying;
#define glGetTransformFeedbackVarying \
        CoreGl_GetTransformFeedbackVarying

TRANSGL_API
PFNGLCLAMPCOLORPROC
CoreGl_ClampColor;
#define glClampColor \
        CoreGl_ClampColor

TRANSGL_API
PFNGLBEGINCONDITIONALRENDERPROC
CoreGl_BeginConditionalRender;
#define glBeginConditionalRender \
        CoreGl_BeginConditionalRender

TRANSGL_API
PFNGLENDCONDITIONALRENDERPROC
CoreGl_EndConditionalRender;
#define glEndConditionalRender \
        CoreGl_EndConditionalRender

TRANSGL_API
PFNGLVERTEXATTRIBIPOINTERPROC
CoreGl_VertexAttribIPointer;
#define glVertexAttribIPointer \
        CoreGl_VertexAttribIPointer

TRANSGL_API
PFNGLGETVERTEXATTRIBIIVPROC
CoreGl_GetVertexAttribIiv;
#define glGetVertexAttribIiv \
        CoreGl_GetVertexAttribIiv

TRANSGL_API
PFNGLGETVERTEXATTRIBIUIVPROC
CoreGl_GetVertexAttribIuiv;
#define glGetVertexAttribIuiv \
        CoreGl_GetVertexAttribIuiv

TRANSGL_API
PFNGLVERTEXATTRIBI1IPROC
CoreGl_VertexAttribI1i;
#define glVertexAttribI1i \
        CoreGl_VertexAttribI1i

TRANSGL_API
PFNGLVERTEXATTRIBI2IPROC
CoreGl_VertexAttribI2i;
#define glVertexAttribI2i \
        CoreGl_VertexAttribI2i

TRANSGL_API
PFNGLVERTEXATTRIBI3IPROC
CoreGl_VertexAttribI3i;
#define glVertexAttribI3i \
        CoreGl_VertexAttribI3i

TRANSGL_API
PFNGLVERTEXATTRIBI4IPROC
CoreGl_VertexAttribI4i;
#define glVertexAttribI4i \
        CoreGl_VertexAttribI4i

TRANSGL_API
PFNGLVERTEXATTRIBI1UIPROC
CoreGl_VertexAttribI1ui;
#define glVertexAttribI1ui \
        CoreGl_VertexAttribI1ui

TRANSGL_API
PFNGLVERTEXATTRIBI2UIPROC
CoreGl_VertexAttribI2ui;
#define glVertexAttribI2ui \
        CoreGl_VertexAttribI2ui

TRANSGL_API
PFNGLVERTEXATTRIBI3UIPROC
CoreGl_VertexAttribI3ui;
#define glVertexAttribI3ui \
        CoreGl_VertexAttribI3ui

TRANSGL_API
PFNGLVERTEXATTRIBI4UIPROC
CoreGl_VertexAttribI4ui;
#define glVertexAttribI4ui \
        CoreGl_VertexAttribI4ui

TRANSGL_API
PFNGLVERTEXATTRIBI1IVPROC
CoreGl_VertexAttribI1iv;
#define glVertexAttribI1iv \
        CoreGl_VertexAttribI1iv

TRANSGL_API
PFNGLVERTEXATTRIBI2IVPROC
CoreGl_VertexAttribI2iv;
#define glVertexAttribI2iv \
        CoreGl_VertexAttribI2iv

TRANSGL_API
PFNGLVERTEXATTRIBI3IVPROC
CoreGl_VertexAttribI3iv;
#define glVertexAttribI3iv \
        CoreGl_VertexAttribI3iv

TRANSGL_API
PFNGLVERTEXATTRIBI4IVPROC
CoreGl_VertexAttribI4iv;
#define glVertexAttribI4iv \
        CoreGl_VertexAttribI4iv

TRANSGL_API
PFNGLVERTEXATTRIBI1UIVPROC
CoreGl_VertexAttribI1uiv;
#define glVertexAttribI1uiv \
        CoreGl_VertexAttribI1uiv

TRANSGL_API
PFNGLVERTEXATTRIBI2UIVPROC
CoreGl_VertexAttribI2uiv;
#define glVertexAttribI2uiv \
        CoreGl_VertexAttribI2uiv

TRANSGL_API
PFNGLVERTEXATTRIBI3UIVPROC
CoreGl_VertexAttribI3uiv;
#define glVertexAttribI3uiv \
        CoreGl_VertexAttribI3uiv

TRANSGL_API
PFNGLVERTEXATTRIBI4UIVPROC
CoreGl_VertexAttribI4uiv;
#define glVertexAttribI4uiv \
        CoreGl_VertexAttribI4uiv

TRANSGL_API
PFNGLVERTEXATTRIBI4BVPROC
CoreGl_VertexAttribI4bv;
#define glVertexAttribI4bv \
        CoreGl_VertexAttribI4bv

TRANSGL_API
PFNGLVERTEXATTRIBI4SVPROC
CoreGl_VertexAttribI4sv;
#define glVertexAttribI4sv \
        CoreGl_VertexAttribI4sv

TRANSGL_API
PFNGLVERTEXATTRIBI4UBVPROC
CoreGl_VertexAttribI4ubv;
#define glVertexAttribI4ubv \
        CoreGl_VertexAttribI4ubv

TRANSGL_API
PFNGLVERTEXATTRIBI4USVPROC
CoreGl_VertexAttribI4usv;
#define glVertexAttribI4usv \
        CoreGl_VertexAttribI4usv

TRANSGL_API
PFNGLGETUNIFORMUIVPROC
CoreGl_GetUniformuiv;
#define glGetUniformuiv \
        CoreGl_GetUniformuiv

TRANSGL_API
PFNGLBINDFRAGDATALOCATIONPROC
CoreGl_BindFragDataLocation;
#define glBindFragDataLocation \
        CoreGl_BindFragDataLocation

TRANSGL_API
PFNGLGETFRAGDATALOCATIONPROC
CoreGl_GetFragDataLocation;
#define glGetFragDataLocation \
        CoreGl_GetFragDataLocation

TRANSGL_API
PFNGLUNIFORM1UIPROC
CoreGl_Uniform1ui;
#define glUniform1ui \
        CoreGl_Uniform1ui

TRANSGL_API
PFNGLUNIFORM2UIPROC
CoreGl_Uniform2ui;
#define glUniform2ui \
        CoreGl_Uniform2ui

TRANSGL_API
PFNGLUNIFORM3UIPROC
CoreGl_Uniform3ui;
#define glUniform3ui \
        CoreGl_Uniform3ui

TRANSGL_API
PFNGLUNIFORM4UIPROC
CoreGl_Uniform4ui;
#define glUniform4ui \
        CoreGl_Uniform4ui

TRANSGL_API
PFNGLUNIFORM1UIVPROC
CoreGl_Uniform1uiv;
#define glUniform1uiv \
        CoreGl_Uniform1uiv

TRANSGL_API
PFNGLUNIFORM2UIVPROC
CoreGl_Uniform2uiv;
#define glUniform2uiv \
        CoreGl_Uniform2uiv

TRANSGL_API
PFNGLUNIFORM3UIVPROC
CoreGl_Uniform3uiv;
#define glUniform3uiv \
        CoreGl_Uniform3uiv

TRANSGL_API
PFNGLUNIFORM4UIVPROC
CoreGl_Uniform4uiv;
#define glUniform4uiv \
        CoreGl_Uniform4uiv

TRANSGL_API
PFNGLTEXPARAMETERIIVPROC
CoreGl_TexParameterIiv;
#define glTexParameterIiv \
        CoreGl_TexParameterIiv

TRANSGL_API
PFNGLTEXPARAMETERIUIVPROC
CoreGl_TexParameterIuiv;
#define glTexParameterIuiv \
        CoreGl_TexParameterIuiv

TRANSGL_API
PFNGLGETTEXPARAMETERIIVPROC
CoreGl_GetTexParameterIiv;
#define glGetTexParameterIiv \
        CoreGl_GetTexParameterIiv

TRANSGL_API
PFNGLGETTEXPARAMETERIUIVPROC
CoreGl_GetTexParameterIuiv;
#define glGetTexParameterIuiv \
        CoreGl_GetTexParameterIuiv

TRANSGL_API
PFNGLCLEARBUFFERIVPROC
CoreGl_ClearBufferiv;
#define glClearBufferiv \
        CoreGl_ClearBufferiv

TRANSGL_API
PFNGLCLEARBUFFERUIVPROC
CoreGl_ClearBufferuiv;
#define glClearBufferuiv \
        CoreGl_ClearBufferuiv

TRANSGL_API
PFNGLCLEARBUFFERFVPROC
CoreGl_ClearBufferfv;
#define glClearBufferfv \
        CoreGl_ClearBufferfv

TRANSGL_API
PFNGLCLEARBUFFERFIPROC
CoreGl_ClearBufferfi;
#define glClearBufferfi \
        CoreGl_ClearBufferfi

TRANSGL_API
PFNGLGETSTRINGIPROC
CoreGl_GetStringi;
#define glGetStringi \
        CoreGl_GetStringi

TRANSGL_API
PFNGLISRENDERBUFFERPROC
CoreGl_IsRenderbuffer;
#define glIsRenderbuffer \
        CoreGl_IsRenderbuffer

TRANSGL_API
PFNGLBINDRENDERBUFFERPROC
CoreGl_BindRenderbuffer;
#define glBindRenderbuffer \
        CoreGl_BindRenderbuffer

TRANSGL_API
PFNGLDELETERENDERBUFFERSPROC
CoreGl_DeleteRenderbuffers;
#define glDeleteRenderbuffers \
        CoreGl_DeleteRenderbuffers

TRANSGL_API
PFNGLGENRENDERBUFFERSPROC
CoreGl_GenRenderbuffers;
#define glGenRenderbuffers \
        CoreGl_GenRenderbuffers

TRANSGL_API
PFNGLRENDERBUFFERSTORAGEPROC
CoreGl_RenderbufferStorage;
#define glRenderbufferStorage \
        CoreGl_RenderbufferStorage

TRANSGL_API
PFNGLGETRENDERBUFFERPARAMETERIVPROC
CoreGl_GetRenderbufferParameteriv;
#define glGetRenderbufferParameteriv \
        CoreGl_GetRenderbufferParameteriv

TRANSGL_API
PFNGLISFRAMEBUFFERPROC
CoreGl_IsFramebuffer;
#define glIsFramebuffer \
        CoreGl_IsFramebuffer

TRANSGL_API
PFNGLBINDFRAMEBUFFERPROC
CoreGl_BindFramebuffer;
#define glBindFramebuffer \
        CoreGl_BindFramebuffer

TRANSGL_API
PFNGLDELETEFRAMEBUFFERSPROC
CoreGl_DeleteFramebuffers;
#define glDeleteFramebuffers \
        CoreGl_DeleteFramebuffers

TRANSGL_API
PFNGLGENFRAMEBUFFERSPROC
CoreGl_GenFramebuffers;
#define glGenFramebuffers \
        CoreGl_GenFramebuffers

TRANSGL_API
PFNGLCHECKFRAMEBUFFERSTATUSPROC
CoreGl_CheckFramebufferStatus;
#define glCheckFramebufferStatus \
        CoreGl_CheckFramebufferStatus

TRANSGL_API
PFNGLFRAMEBUFFERTEXTURE1DPROC
CoreGl_FramebufferTexture1D;
#define glFramebufferTexture1D \
        CoreGl_FramebufferTexture1D

TRANSGL_API
PFNGLFRAMEBUFFERTEXTURE2DPROC
CoreGl_FramebufferTexture2D;
#define glFramebufferTexture2D \
        CoreGl_FramebufferTexture2D

TRANSGL_API
PFNGLFRAMEBUFFERTEXTURE3DPROC
CoreGl_FramebufferTexture3D;
#define glFramebufferTexture3D \
        CoreGl_FramebufferTexture3D

TRANSGL_API
PFNGLFRAMEBUFFERRENDERBUFFERPROC
CoreGl_FramebufferRenderbuffer;
#define glFramebufferRenderbuffer \
        CoreGl_FramebufferRenderbuffer

TRANSGL_API
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC
CoreGl_GetFramebufferAttachmentParameteriv;
#define glGetFramebufferAttachmentParameteriv \
        CoreGl_GetFramebufferAttachmentParameteriv

TRANSGL_API
PFNGLGENERATEMIPMAPPROC
CoreGl_GenerateMipmap;
#define glGenerateMipmap \
        CoreGl_GenerateMipmap

TRANSGL_API
PFNGLBLITFRAMEBUFFERPROC
CoreGl_BlitFramebuffer;
#define glBlitFramebuffer \
        CoreGl_BlitFramebuffer

TRANSGL_API
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC
CoreGl_RenderbufferStorageMultisample;
#define glRenderbufferStorageMultisample \
        CoreGl_RenderbufferStorageMultisample

TRANSGL_API
PFNGLFRAMEBUFFERTEXTURELAYERPROC
CoreGl_FramebufferTextureLayer;
#define glFramebufferTextureLayer \
        CoreGl_FramebufferTextureLayer

TRANSGL_API
PFNGLMAPBUFFERRANGEPROC
CoreGl_MapBufferRange;
#define glMapBufferRange \
        CoreGl_MapBufferRange

TRANSGL_API
PFNGLFLUSHMAPPEDBUFFERRANGEPROC
CoreGl_FlushMappedBufferRange;
#define glFlushMappedBufferRange \
        CoreGl_FlushMappedBufferRange

TRANSGL_API
PFNGLBINDVERTEXARRAYPROC
CoreGl_BindVertexArray;
#define glBindVertexArray \
        CoreGl_BindVertexArray

TRANSGL_API
PFNGLDELETEVERTEXARRAYSPROC
CoreGl_DeleteVertexArrays;
#define glDeleteVertexArrays \
        CoreGl_DeleteVertexArrays

TRANSGL_API
PFNGLGENVERTEXARRAYSPROC
CoreGl_GenVertexArrays;
#define glGenVertexArrays \
        CoreGl_GenVertexArrays

TRANSGL_API
PFNGLISVERTEXARRAYPROC
CoreGl_IsVertexArray;
#define glIsVertexArray \
        CoreGl_IsVertexArray

//---- VERSION_3_1 ----

INLINE
bool
CoreGl_has_VERSION_3_1(void)
{
return _CoreGl_mgr.has_VERSION_3_1;
}

TRANSGL_API
PFNGLDRAWARRAYSINSTANCEDPROC
CoreGl_DrawArraysInstanced;
#define glDrawArraysInstanced \
        CoreGl_DrawArraysInstanced

TRANSGL_API
PFNGLDRAWELEMENTSINSTANCEDPROC
CoreGl_DrawElementsInstanced;
#define glDrawElementsInstanced \
        CoreGl_DrawElementsInstanced

TRANSGL_API
PFNGLTEXBUFFERPROC
CoreGl_TexBuffer;
#define glTexBuffer \
        CoreGl_TexBuffer

TRANSGL_API
PFNGLPRIMITIVERESTARTINDEXPROC
CoreGl_PrimitiveRestartIndex;
#define glPrimitiveRestartIndex \
        CoreGl_PrimitiveRestartIndex

TRANSGL_API
PFNGLCOPYBUFFERSUBDATAPROC
CoreGl_CopyBufferSubData;
#define glCopyBufferSubData \
        CoreGl_CopyBufferSubData

TRANSGL_API
PFNGLGETUNIFORMINDICESPROC
CoreGl_GetUniformIndices;
#define glGetUniformIndices \
        CoreGl_GetUniformIndices

TRANSGL_API
PFNGLGETACTIVEUNIFORMSIVPROC
CoreGl_GetActiveUniformsiv;
#define glGetActiveUniformsiv \
        CoreGl_GetActiveUniformsiv

TRANSGL_API
PFNGLGETACTIVEUNIFORMNAMEPROC
CoreGl_GetActiveUniformName;
#define glGetActiveUniformName \
        CoreGl_GetActiveUniformName

TRANSGL_API
PFNGLGETUNIFORMBLOCKINDEXPROC
CoreGl_GetUniformBlockIndex;
#define glGetUniformBlockIndex \
        CoreGl_GetUniformBlockIndex

TRANSGL_API
PFNGLGETACTIVEUNIFORMBLOCKIVPROC
CoreGl_GetActiveUniformBlockiv;
#define glGetActiveUniformBlockiv \
        CoreGl_GetActiveUniformBlockiv

TRANSGL_API
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC
CoreGl_GetActiveUniformBlockName;
#define glGetActiveUniformBlockName \
        CoreGl_GetActiveUniformBlockName

TRANSGL_API
PFNGLUNIFORMBLOCKBINDINGPROC
CoreGl_UniformBlockBinding;
#define glUniformBlockBinding \
        CoreGl_UniformBlockBinding

//---- VERSION_3_2 ----

INLINE
bool
CoreGl_has_VERSION_3_2(void)
{
return _CoreGl_mgr.has_VERSION_3_2;
}

TRANSGL_API
PFNGLDRAWELEMENTSBASEVERTEXPROC
CoreGl_DrawElementsBaseVertex;
#define glDrawElementsBaseVertex \
        CoreGl_DrawElementsBaseVertex

TRANSGL_API
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC
CoreGl_DrawRangeElementsBaseVertex;
#define glDrawRangeElementsBaseVertex \
        CoreGl_DrawRangeElementsBaseVertex

TRANSGL_API
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC
CoreGl_DrawElementsInstancedBaseVertex;
#define glDrawElementsInstancedBaseVertex \
        CoreGl_DrawElementsInstancedBaseVertex

TRANSGL_API
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC
CoreGl_MultiDrawElementsBaseVertex;
#define glMultiDrawElementsBaseVertex \
        CoreGl_MultiDrawElementsBaseVertex

TRANSGL_API
PFNGLPROVOKINGVERTEXPROC
CoreGl_ProvokingVertex;
#define glProvokingVertex \
        CoreGl_ProvokingVertex

TRANSGL_API
PFNGLFENCESYNCPROC
CoreGl_FenceSync;
#define glFenceSync \
        CoreGl_FenceSync

TRANSGL_API
PFNGLISSYNCPROC
CoreGl_IsSync;
#define glIsSync \
        CoreGl_IsSync

TRANSGL_API
PFNGLDELETESYNCPROC
CoreGl_DeleteSync;
#define glDeleteSync \
        CoreGl_DeleteSync

TRANSGL_API
PFNGLCLIENTWAITSYNCPROC
CoreGl_ClientWaitSync;
#define glClientWaitSync \
        CoreGl_ClientWaitSync

TRANSGL_API
PFNGLWAITSYNCPROC
CoreGl_WaitSync;
#define glWaitSync \
        CoreGl_WaitSync

TRANSGL_API
PFNGLGETINTEGER64VPROC
CoreGl_GetInteger64v;
#define glGetInteger64v \
        CoreGl_GetInteger64v

TRANSGL_API
PFNGLGETSYNCIVPROC
CoreGl_GetSynciv;
#define glGetSynciv \
        CoreGl_GetSynciv

TRANSGL_API
PFNGLGETINTEGER64I_VPROC
CoreGl_GetInteger64i_v;
#define glGetInteger64i_v \
        CoreGl_GetInteger64i_v

TRANSGL_API
PFNGLGETBUFFERPARAMETERI64VPROC
CoreGl_GetBufferParameteri64v;
#define glGetBufferParameteri64v \
        CoreGl_GetBufferParameteri64v

TRANSGL_API
PFNGLFRAMEBUFFERTEXTUREPROC
CoreGl_FramebufferTexture;
#define glFramebufferTexture \
        CoreGl_FramebufferTexture

TRANSGL_API
PFNGLTEXIMAGE2DMULTISAMPLEPROC
CoreGl_TexImage2DMultisample;
#define glTexImage2DMultisample \
        CoreGl_TexImage2DMultisample

TRANSGL_API
PFNGLTEXIMAGE3DMULTISAMPLEPROC
CoreGl_TexImage3DMultisample;
#define glTexImage3DMultisample \
        CoreGl_TexImage3DMultisample

TRANSGL_API
PFNGLGETMULTISAMPLEFVPROC
CoreGl_GetMultisamplefv;
#define glGetMultisamplefv \
        CoreGl_GetMultisamplefv

TRANSGL_API
PFNGLSAMPLEMASKIPROC
CoreGl_SampleMaski;
#define glSampleMaski \
        CoreGl_SampleMaski

//---- VERSION_3_3 ----

INLINE
bool
CoreGl_has_VERSION_3_3(void)
{
return _CoreGl_mgr.has_VERSION_3_3;
}

TRANSGL_API
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC
CoreGl_BindFragDataLocationIndexed;
#define glBindFragDataLocationIndexed \
        CoreGl_BindFragDataLocationIndexed

TRANSGL_API
PFNGLGETFRAGDATAINDEXPROC
CoreGl_GetFragDataIndex;
#define glGetFragDataIndex \
        CoreGl_GetFragDataIndex

TRANSGL_API
PFNGLGENSAMPLERSPROC
CoreGl_GenSamplers;
#define glGenSamplers \
        CoreGl_GenSamplers

TRANSGL_API
PFNGLDELETESAMPLERSPROC
CoreGl_DeleteSamplers;
#define glDeleteSamplers \
        CoreGl_DeleteSamplers

TRANSGL_API
PFNGLISSAMPLERPROC
CoreGl_IsSampler;
#define glIsSampler \
        CoreGl_IsSampler

TRANSGL_API
PFNGLBINDSAMPLERPROC
CoreGl_BindSampler;
#define glBindSampler \
        CoreGl_BindSampler

TRANSGL_API
PFNGLSAMPLERPARAMETERIPROC
CoreGl_SamplerParameteri;
#define glSamplerParameteri \
        CoreGl_SamplerParameteri

TRANSGL_API
PFNGLSAMPLERPARAMETERIVPROC
CoreGl_SamplerParameteriv;
#define glSamplerParameteriv \
        CoreGl_SamplerParameteriv

TRANSGL_API
PFNGLSAMPLERPARAMETERFPROC
CoreGl_SamplerParameterf;
#define glSamplerParameterf \
        CoreGl_SamplerParameterf

TRANSGL_API
PFNGLSAMPLERPARAMETERFVPROC
CoreGl_SamplerParameterfv;
#define glSamplerParameterfv \
        CoreGl_SamplerParameterfv

TRANSGL_API
PFNGLSAMPLERPARAMETERIIVPROC
CoreGl_SamplerParameterIiv;
#define glSamplerParameterIiv \
        CoreGl_SamplerParameterIiv

TRANSGL_API
PFNGLSAMPLERPARAMETERIUIVPROC
CoreGl_SamplerParameterIuiv;
#define glSamplerParameterIuiv \
        CoreGl_SamplerParameterIuiv

TRANSGL_API
PFNGLGETSAMPLERPARAMETERIVPROC
CoreGl_GetSamplerParameteriv;
#define glGetSamplerParameteriv \
        CoreGl_GetSamplerParameteriv

TRANSGL_API
PFNGLGETSAMPLERPARAMETERIIVPROC
CoreGl_GetSamplerParameterIiv;
#define glGetSamplerParameterIiv \
        CoreGl_GetSamplerParameterIiv

TRANSGL_API
PFNGLGETSAMPLERPARAMETERFVPROC
CoreGl_GetSamplerParameterfv;
#define glGetSamplerParameterfv \
        CoreGl_GetSamplerParameterfv

TRANSGL_API
PFNGLGETSAMPLERPARAMETERIUIVPROC
CoreGl_GetSamplerParameterIuiv;
#define glGetSamplerParameterIuiv \
        CoreGl_GetSamplerParameterIuiv

TRANSGL_API
PFNGLQUERYCOUNTERPROC
CoreGl_QueryCounter;
#define glQueryCounter \
        CoreGl_QueryCounter

TRANSGL_API
PFNGLGETQUERYOBJECTI64VPROC
CoreGl_GetQueryObjecti64v;
#define glGetQueryObjecti64v \
        CoreGl_GetQueryObjecti64v

TRANSGL_API
PFNGLGETQUERYOBJECTUI64VPROC
CoreGl_GetQueryObjectui64v;
#define glGetQueryObjectui64v \
        CoreGl_GetQueryObjectui64v

TRANSGL_API
PFNGLVERTEXATTRIBDIVISORPROC
CoreGl_VertexAttribDivisor;
#define glVertexAttribDivisor \
        CoreGl_VertexAttribDivisor

TRANSGL_API
PFNGLVERTEXATTRIBP1UIPROC
CoreGl_VertexAttribP1ui;
#define glVertexAttribP1ui \
        CoreGl_VertexAttribP1ui

TRANSGL_API
PFNGLVERTEXATTRIBP1UIVPROC
CoreGl_VertexAttribP1uiv;
#define glVertexAttribP1uiv \
        CoreGl_VertexAttribP1uiv

TRANSGL_API
PFNGLVERTEXATTRIBP2UIPROC
CoreGl_VertexAttribP2ui;
#define glVertexAttribP2ui \
        CoreGl_VertexAttribP2ui

TRANSGL_API
PFNGLVERTEXATTRIBP2UIVPROC
CoreGl_VertexAttribP2uiv;
#define glVertexAttribP2uiv \
        CoreGl_VertexAttribP2uiv

TRANSGL_API
PFNGLVERTEXATTRIBP3UIPROC
CoreGl_VertexAttribP3ui;
#define glVertexAttribP3ui \
        CoreGl_VertexAttribP3ui

TRANSGL_API
PFNGLVERTEXATTRIBP3UIVPROC
CoreGl_VertexAttribP3uiv;
#define glVertexAttribP3uiv \
        CoreGl_VertexAttribP3uiv

TRANSGL_API
PFNGLVERTEXATTRIBP4UIPROC
CoreGl_VertexAttribP4ui;
#define glVertexAttribP4ui \
        CoreGl_VertexAttribP4ui

TRANSGL_API
PFNGLVERTEXATTRIBP4UIVPROC
CoreGl_VertexAttribP4uiv;
#define glVertexAttribP4uiv \
        CoreGl_VertexAttribP4uiv

//---- VERSION_4_0 ----

INLINE
bool
CoreGl_has_VERSION_4_0(void)
{
return _CoreGl_mgr.has_VERSION_4_0;
}

TRANSGL_API
PFNGLMINSAMPLESHADINGPROC
CoreGl_MinSampleShading;
#define glMinSampleShading \
        CoreGl_MinSampleShading

TRANSGL_API
PFNGLBLENDEQUATIONIPROC
CoreGl_BlendEquationi;
#define glBlendEquationi \
        CoreGl_BlendEquationi

TRANSGL_API
PFNGLBLENDEQUATIONSEPARATEIPROC
CoreGl_BlendEquationSeparatei;
#define glBlendEquationSeparatei \
        CoreGl_BlendEquationSeparatei

TRANSGL_API
PFNGLBLENDFUNCIPROC
CoreGl_BlendFunci;
#define glBlendFunci \
        CoreGl_BlendFunci

TRANSGL_API
PFNGLBLENDFUNCSEPARATEIPROC
CoreGl_BlendFuncSeparatei;
#define glBlendFuncSeparatei \
        CoreGl_BlendFuncSeparatei

TRANSGL_API
PFNGLDRAWARRAYSINDIRECTPROC
CoreGl_DrawArraysIndirect;
#define glDrawArraysIndirect \
        CoreGl_DrawArraysIndirect

TRANSGL_API
PFNGLDRAWELEMENTSINDIRECTPROC
CoreGl_DrawElementsIndirect;
#define glDrawElementsIndirect \
        CoreGl_DrawElementsIndirect

TRANSGL_API
PFNGLUNIFORM1DPROC
CoreGl_Uniform1d;
#define glUniform1d \
        CoreGl_Uniform1d

TRANSGL_API
PFNGLUNIFORM2DPROC
CoreGl_Uniform2d;
#define glUniform2d \
        CoreGl_Uniform2d

TRANSGL_API
PFNGLUNIFORM3DPROC
CoreGl_Uniform3d;
#define glUniform3d \
        CoreGl_Uniform3d

TRANSGL_API
PFNGLUNIFORM4DPROC
CoreGl_Uniform4d;
#define glUniform4d \
        CoreGl_Uniform4d

TRANSGL_API
PFNGLUNIFORM1DVPROC
CoreGl_Uniform1dv;
#define glUniform1dv \
        CoreGl_Uniform1dv

TRANSGL_API
PFNGLUNIFORM2DVPROC
CoreGl_Uniform2dv;
#define glUniform2dv \
        CoreGl_Uniform2dv

TRANSGL_API
PFNGLUNIFORM3DVPROC
CoreGl_Uniform3dv;
#define glUniform3dv \
        CoreGl_Uniform3dv

TRANSGL_API
PFNGLUNIFORM4DVPROC
CoreGl_Uniform4dv;
#define glUniform4dv \
        CoreGl_Uniform4dv

TRANSGL_API
PFNGLUNIFORMMATRIX2DVPROC
CoreGl_UniformMatrix2dv;
#define glUniformMatrix2dv \
        CoreGl_UniformMatrix2dv

TRANSGL_API
PFNGLUNIFORMMATRIX3DVPROC
CoreGl_UniformMatrix3dv;
#define glUniformMatrix3dv \
        CoreGl_UniformMatrix3dv

TRANSGL_API
PFNGLUNIFORMMATRIX4DVPROC
CoreGl_UniformMatrix4dv;
#define glUniformMatrix4dv \
        CoreGl_UniformMatrix4dv

TRANSGL_API
PFNGLUNIFORMMATRIX2X3DVPROC
CoreGl_UniformMatrix2x3dv;
#define glUniformMatrix2x3dv \
        CoreGl_UniformMatrix2x3dv

TRANSGL_API
PFNGLUNIFORMMATRIX2X4DVPROC
CoreGl_UniformMatrix2x4dv;
#define glUniformMatrix2x4dv \
        CoreGl_UniformMatrix2x4dv

TRANSGL_API
PFNGLUNIFORMMATRIX3X2DVPROC
CoreGl_UniformMatrix3x2dv;
#define glUniformMatrix3x2dv \
        CoreGl_UniformMatrix3x2dv

TRANSGL_API
PFNGLUNIFORMMATRIX3X4DVPROC
CoreGl_UniformMatrix3x4dv;
#define glUniformMatrix3x4dv \
        CoreGl_UniformMatrix3x4dv

TRANSGL_API
PFNGLUNIFORMMATRIX4X2DVPROC
CoreGl_UniformMatrix4x2dv;
#define glUniformMatrix4x2dv \
        CoreGl_UniformMatrix4x2dv

TRANSGL_API
PFNGLUNIFORMMATRIX4X3DVPROC
CoreGl_UniformMatrix4x3dv;
#define glUniformMatrix4x3dv \
        CoreGl_UniformMatrix4x3dv

TRANSGL_API
PFNGLGETUNIFORMDVPROC
CoreGl_GetUniformdv;
#define glGetUniformdv \
        CoreGl_GetUniformdv

TRANSGL_API
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC
CoreGl_GetSubroutineUniformLocation;
#define glGetSubroutineUniformLocation \
        CoreGl_GetSubroutineUniformLocation

TRANSGL_API
PFNGLGETSUBROUTINEINDEXPROC
CoreGl_GetSubroutineIndex;
#define glGetSubroutineIndex \
        CoreGl_GetSubroutineIndex

TRANSGL_API
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC
CoreGl_GetActiveSubroutineUniformiv;
#define glGetActiveSubroutineUniformiv \
        CoreGl_GetActiveSubroutineUniformiv

TRANSGL_API
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC
CoreGl_GetActiveSubroutineUniformName;
#define glGetActiveSubroutineUniformName \
        CoreGl_GetActiveSubroutineUniformName

TRANSGL_API
PFNGLGETACTIVESUBROUTINENAMEPROC
CoreGl_GetActiveSubroutineName;
#define glGetActiveSubroutineName \
        CoreGl_GetActiveSubroutineName

TRANSGL_API
PFNGLUNIFORMSUBROUTINESUIVPROC
CoreGl_UniformSubroutinesuiv;
#define glUniformSubroutinesuiv \
        CoreGl_UniformSubroutinesuiv

TRANSGL_API
PFNGLGETUNIFORMSUBROUTINEUIVPROC
CoreGl_GetUniformSubroutineuiv;
#define glGetUniformSubroutineuiv \
        CoreGl_GetUniformSubroutineuiv

TRANSGL_API
PFNGLGETPROGRAMSTAGEIVPROC
CoreGl_GetProgramStageiv;
#define glGetProgramStageiv \
        CoreGl_GetProgramStageiv

TRANSGL_API
PFNGLPATCHPARAMETERIPROC
CoreGl_PatchParameteri;
#define glPatchParameteri \
        CoreGl_PatchParameteri

TRANSGL_API
PFNGLPATCHPARAMETERFVPROC
CoreGl_PatchParameterfv;
#define glPatchParameterfv \
        CoreGl_PatchParameterfv

TRANSGL_API
PFNGLBINDTRANSFORMFEEDBACKPROC
CoreGl_BindTransformFeedback;
#define glBindTransformFeedback \
        CoreGl_BindTransformFeedback

TRANSGL_API
PFNGLDELETETRANSFORMFEEDBACKSPROC
CoreGl_DeleteTransformFeedbacks;
#define glDeleteTransformFeedbacks \
        CoreGl_DeleteTransformFeedbacks

TRANSGL_API
PFNGLGENTRANSFORMFEEDBACKSPROC
CoreGl_GenTransformFeedbacks;
#define glGenTransformFeedbacks \
        CoreGl_GenTransformFeedbacks

TRANSGL_API
PFNGLISTRANSFORMFEEDBACKPROC
CoreGl_IsTransformFeedback;
#define glIsTransformFeedback \
        CoreGl_IsTransformFeedback

TRANSGL_API
PFNGLPAUSETRANSFORMFEEDBACKPROC
CoreGl_PauseTransformFeedback;
#define glPauseTransformFeedback \
        CoreGl_PauseTransformFeedback

TRANSGL_API
PFNGLRESUMETRANSFORMFEEDBACKPROC
CoreGl_ResumeTransformFeedback;
#define glResumeTransformFeedback \
        CoreGl_ResumeTransformFeedback

TRANSGL_API
PFNGLDRAWTRANSFORMFEEDBACKPROC
CoreGl_DrawTransformFeedback;
#define glDrawTransformFeedback \
        CoreGl_DrawTransformFeedback

TRANSGL_API
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC
CoreGl_DrawTransformFeedbackStream;
#define glDrawTransformFeedbackStream \
        CoreGl_DrawTransformFeedbackStream

TRANSGL_API
PFNGLBEGINQUERYINDEXEDPROC
CoreGl_BeginQueryIndexed;
#define glBeginQueryIndexed \
        CoreGl_BeginQueryIndexed

TRANSGL_API
PFNGLENDQUERYINDEXEDPROC
CoreGl_EndQueryIndexed;
#define glEndQueryIndexed \
        CoreGl_EndQueryIndexed

TRANSGL_API
PFNGLGETQUERYINDEXEDIVPROC
CoreGl_GetQueryIndexediv;
#define glGetQueryIndexediv \
        CoreGl_GetQueryIndexediv

//---- VERSION_4_1 ----

INLINE
bool
CoreGl_has_VERSION_4_1(void)
{
return _CoreGl_mgr.has_VERSION_4_1;
}

TRANSGL_API
PFNGLRELEASESHADERCOMPILERPROC
CoreGl_ReleaseShaderCompiler;
#define glReleaseShaderCompiler \
        CoreGl_ReleaseShaderCompiler

TRANSGL_API
PFNGLSHADERBINARYPROC
CoreGl_ShaderBinary;
#define glShaderBinary \
        CoreGl_ShaderBinary

TRANSGL_API
PFNGLGETSHADERPRECISIONFORMATPROC
CoreGl_GetShaderPrecisionFormat;
#define glGetShaderPrecisionFormat \
        CoreGl_GetShaderPrecisionFormat

TRANSGL_API
PFNGLDEPTHRANGEFPROC
CoreGl_DepthRangef;
#define glDepthRangef \
        CoreGl_DepthRangef

TRANSGL_API
PFNGLCLEARDEPTHFPROC
CoreGl_ClearDepthf;
#define glClearDepthf \
        CoreGl_ClearDepthf

TRANSGL_API
PFNGLGETPROGRAMBINARYPROC
CoreGl_GetProgramBinary;
#define glGetProgramBinary \
        CoreGl_GetProgramBinary

TRANSGL_API
PFNGLPROGRAMBINARYPROC
CoreGl_ProgramBinary;
#define glProgramBinary \
        CoreGl_ProgramBinary

TRANSGL_API
PFNGLPROGRAMPARAMETERIPROC
CoreGl_ProgramParameteri;
#define glProgramParameteri \
        CoreGl_ProgramParameteri

TRANSGL_API
PFNGLUSEPROGRAMSTAGESPROC
CoreGl_UseProgramStages;
#define glUseProgramStages \
        CoreGl_UseProgramStages

TRANSGL_API
PFNGLACTIVESHADERPROGRAMPROC
CoreGl_ActiveShaderProgram;
#define glActiveShaderProgram \
        CoreGl_ActiveShaderProgram

TRANSGL_API
PFNGLCREATESHADERPROGRAMVPROC
CoreGl_CreateShaderProgramv;
#define glCreateShaderProgramv \
        CoreGl_CreateShaderProgramv

TRANSGL_API
PFNGLBINDPROGRAMPIPELINEPROC
CoreGl_BindProgramPipeline;
#define glBindProgramPipeline \
        CoreGl_BindProgramPipeline

TRANSGL_API
PFNGLDELETEPROGRAMPIPELINESPROC
CoreGl_DeleteProgramPipelines;
#define glDeleteProgramPipelines \
        CoreGl_DeleteProgramPipelines

TRANSGL_API
PFNGLGENPROGRAMPIPELINESPROC
CoreGl_GenProgramPipelines;
#define glGenProgramPipelines \
        CoreGl_GenProgramPipelines

TRANSGL_API
PFNGLISPROGRAMPIPELINEPROC
CoreGl_IsProgramPipeline;
#define glIsProgramPipeline \
        CoreGl_IsProgramPipeline

TRANSGL_API
PFNGLGETPROGRAMPIPELINEIVPROC
CoreGl_GetProgramPipelineiv;
#define glGetProgramPipelineiv \
        CoreGl_GetProgramPipelineiv

TRANSGL_API
PFNGLPROGRAMUNIFORM1IPROC
CoreGl_ProgramUniform1i;
#define glProgramUniform1i \
        CoreGl_ProgramUniform1i

TRANSGL_API
PFNGLPROGRAMUNIFORM1IVPROC
CoreGl_ProgramUniform1iv;
#define glProgramUniform1iv \
        CoreGl_ProgramUniform1iv

TRANSGL_API
PFNGLPROGRAMUNIFORM1FPROC
CoreGl_ProgramUniform1f;
#define glProgramUniform1f \
        CoreGl_ProgramUniform1f

TRANSGL_API
PFNGLPROGRAMUNIFORM1FVPROC
CoreGl_ProgramUniform1fv;
#define glProgramUniform1fv \
        CoreGl_ProgramUniform1fv

TRANSGL_API
PFNGLPROGRAMUNIFORM1DPROC
CoreGl_ProgramUniform1d;
#define glProgramUniform1d \
        CoreGl_ProgramUniform1d

TRANSGL_API
PFNGLPROGRAMUNIFORM1DVPROC
CoreGl_ProgramUniform1dv;
#define glProgramUniform1dv \
        CoreGl_ProgramUniform1dv

TRANSGL_API
PFNGLPROGRAMUNIFORM1UIPROC
CoreGl_ProgramUniform1ui;
#define glProgramUniform1ui \
        CoreGl_ProgramUniform1ui

TRANSGL_API
PFNGLPROGRAMUNIFORM1UIVPROC
CoreGl_ProgramUniform1uiv;
#define glProgramUniform1uiv \
        CoreGl_ProgramUniform1uiv

TRANSGL_API
PFNGLPROGRAMUNIFORM2IPROC
CoreGl_ProgramUniform2i;
#define glProgramUniform2i \
        CoreGl_ProgramUniform2i

TRANSGL_API
PFNGLPROGRAMUNIFORM2IVPROC
CoreGl_ProgramUniform2iv;
#define glProgramUniform2iv \
        CoreGl_ProgramUniform2iv

TRANSGL_API
PFNGLPROGRAMUNIFORM2FPROC
CoreGl_ProgramUniform2f;
#define glProgramUniform2f \
        CoreGl_ProgramUniform2f

TRANSGL_API
PFNGLPROGRAMUNIFORM2FVPROC
CoreGl_ProgramUniform2fv;
#define glProgramUniform2fv \
        CoreGl_ProgramUniform2fv

TRANSGL_API
PFNGLPROGRAMUNIFORM2DPROC
CoreGl_ProgramUniform2d;
#define glProgramUniform2d \
        CoreGl_ProgramUniform2d

TRANSGL_API
PFNGLPROGRAMUNIFORM2DVPROC
CoreGl_ProgramUniform2dv;
#define glProgramUniform2dv \
        CoreGl_ProgramUniform2dv

TRANSGL_API
PFNGLPROGRAMUNIFORM2UIPROC
CoreGl_ProgramUniform2ui;
#define glProgramUniform2ui \
        CoreGl_ProgramUniform2ui

TRANSGL_API
PFNGLPROGRAMUNIFORM2UIVPROC
CoreGl_ProgramUniform2uiv;
#define glProgramUniform2uiv \
        CoreGl_ProgramUniform2uiv

TRANSGL_API
PFNGLPROGRAMUNIFORM3IPROC
CoreGl_ProgramUniform3i;
#define glProgramUniform3i \
        CoreGl_ProgramUniform3i

TRANSGL_API
PFNGLPROGRAMUNIFORM3IVPROC
CoreGl_ProgramUniform3iv;
#define glProgramUniform3iv \
        CoreGl_ProgramUniform3iv

TRANSGL_API
PFNGLPROGRAMUNIFORM3FPROC
CoreGl_ProgramUniform3f;
#define glProgramUniform3f \
        CoreGl_ProgramUniform3f

TRANSGL_API
PFNGLPROGRAMUNIFORM3FVPROC
CoreGl_ProgramUniform3fv;
#define glProgramUniform3fv \
        CoreGl_ProgramUniform3fv

TRANSGL_API
PFNGLPROGRAMUNIFORM3DPROC
CoreGl_ProgramUniform3d;
#define glProgramUniform3d \
        CoreGl_ProgramUniform3d

TRANSGL_API
PFNGLPROGRAMUNIFORM3DVPROC
CoreGl_ProgramUniform3dv;
#define glProgramUniform3dv \
        CoreGl_ProgramUniform3dv

TRANSGL_API
PFNGLPROGRAMUNIFORM3UIPROC
CoreGl_ProgramUniform3ui;
#define glProgramUniform3ui \
        CoreGl_ProgramUniform3ui

TRANSGL_API
PFNGLPROGRAMUNIFORM3UIVPROC
CoreGl_ProgramUniform3uiv;
#define glProgramUniform3uiv \
        CoreGl_ProgramUniform3uiv

TRANSGL_API
PFNGLPROGRAMUNIFORM4IPROC
CoreGl_ProgramUniform4i;
#define glProgramUniform4i \
        CoreGl_ProgramUniform4i

TRANSGL_API
PFNGLPROGRAMUNIFORM4IVPROC
CoreGl_ProgramUniform4iv;
#define glProgramUniform4iv \
        CoreGl_ProgramUniform4iv

TRANSGL_API
PFNGLPROGRAMUNIFORM4FPROC
CoreGl_ProgramUniform4f;
#define glProgramUniform4f \
        CoreGl_ProgramUniform4f

TRANSGL_API
PFNGLPROGRAMUNIFORM4FVPROC
CoreGl_ProgramUniform4fv;
#define glProgramUniform4fv \
        CoreGl_ProgramUniform4fv

TRANSGL_API
PFNGLPROGRAMUNIFORM4DPROC
CoreGl_ProgramUniform4d;
#define glProgramUniform4d \
        CoreGl_ProgramUniform4d

TRANSGL_API
PFNGLPROGRAMUNIFORM4DVPROC
CoreGl_ProgramUniform4dv;
#define glProgramUniform4dv \
        CoreGl_ProgramUniform4dv

TRANSGL_API
PFNGLPROGRAMUNIFORM4UIPROC
CoreGl_ProgramUniform4ui;
#define glProgramUniform4ui \
        CoreGl_ProgramUniform4ui

TRANSGL_API
PFNGLPROGRAMUNIFORM4UIVPROC
CoreGl_ProgramUniform4uiv;
#define glProgramUniform4uiv \
        CoreGl_ProgramUniform4uiv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX2FVPROC
CoreGl_ProgramUniformMatrix2fv;
#define glProgramUniformMatrix2fv \
        CoreGl_ProgramUniformMatrix2fv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX3FVPROC
CoreGl_ProgramUniformMatrix3fv;
#define glProgramUniformMatrix3fv \
        CoreGl_ProgramUniformMatrix3fv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX4FVPROC
CoreGl_ProgramUniformMatrix4fv;
#define glProgramUniformMatrix4fv \
        CoreGl_ProgramUniformMatrix4fv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX2DVPROC
CoreGl_ProgramUniformMatrix2dv;
#define glProgramUniformMatrix2dv \
        CoreGl_ProgramUniformMatrix2dv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX3DVPROC
CoreGl_ProgramUniformMatrix3dv;
#define glProgramUniformMatrix3dv \
        CoreGl_ProgramUniformMatrix3dv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX4DVPROC
CoreGl_ProgramUniformMatrix4dv;
#define glProgramUniformMatrix4dv \
        CoreGl_ProgramUniformMatrix4dv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC
CoreGl_ProgramUniformMatrix2x3fv;
#define glProgramUniformMatrix2x3fv \
        CoreGl_ProgramUniformMatrix2x3fv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC
CoreGl_ProgramUniformMatrix3x2fv;
#define glProgramUniformMatrix3x2fv \
        CoreGl_ProgramUniformMatrix3x2fv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC
CoreGl_ProgramUniformMatrix2x4fv;
#define glProgramUniformMatrix2x4fv \
        CoreGl_ProgramUniformMatrix2x4fv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC
CoreGl_ProgramUniformMatrix4x2fv;
#define glProgramUniformMatrix4x2fv \
        CoreGl_ProgramUniformMatrix4x2fv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC
CoreGl_ProgramUniformMatrix3x4fv;
#define glProgramUniformMatrix3x4fv \
        CoreGl_ProgramUniformMatrix3x4fv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC
CoreGl_ProgramUniformMatrix4x3fv;
#define glProgramUniformMatrix4x3fv \
        CoreGl_ProgramUniformMatrix4x3fv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC
CoreGl_ProgramUniformMatrix2x3dv;
#define glProgramUniformMatrix2x3dv \
        CoreGl_ProgramUniformMatrix2x3dv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC
CoreGl_ProgramUniformMatrix3x2dv;
#define glProgramUniformMatrix3x2dv \
        CoreGl_ProgramUniformMatrix3x2dv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC
CoreGl_ProgramUniformMatrix2x4dv;
#define glProgramUniformMatrix2x4dv \
        CoreGl_ProgramUniformMatrix2x4dv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC
CoreGl_ProgramUniformMatrix4x2dv;
#define glProgramUniformMatrix4x2dv \
        CoreGl_ProgramUniformMatrix4x2dv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC
CoreGl_ProgramUniformMatrix3x4dv;
#define glProgramUniformMatrix3x4dv \
        CoreGl_ProgramUniformMatrix3x4dv

TRANSGL_API
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC
CoreGl_ProgramUniformMatrix4x3dv;
#define glProgramUniformMatrix4x3dv \
        CoreGl_ProgramUniformMatrix4x3dv

TRANSGL_API
PFNGLVALIDATEPROGRAMPIPELINEPROC
CoreGl_ValidateProgramPipeline;
#define glValidateProgramPipeline \
        CoreGl_ValidateProgramPipeline

TRANSGL_API
PFNGLGETPROGRAMPIPELINEINFOLOGPROC
CoreGl_GetProgramPipelineInfoLog;
#define glGetProgramPipelineInfoLog \
        CoreGl_GetProgramPipelineInfoLog

TRANSGL_API
PFNGLVERTEXATTRIBL1DPROC
CoreGl_VertexAttribL1d;
#define glVertexAttribL1d \
        CoreGl_VertexAttribL1d

TRANSGL_API
PFNGLVERTEXATTRIBL2DPROC
CoreGl_VertexAttribL2d;
#define glVertexAttribL2d \
        CoreGl_VertexAttribL2d

TRANSGL_API
PFNGLVERTEXATTRIBL3DPROC
CoreGl_VertexAttribL3d;
#define glVertexAttribL3d \
        CoreGl_VertexAttribL3d

TRANSGL_API
PFNGLVERTEXATTRIBL4DPROC
CoreGl_VertexAttribL4d;
#define glVertexAttribL4d \
        CoreGl_VertexAttribL4d

TRANSGL_API
PFNGLVERTEXATTRIBL1DVPROC
CoreGl_VertexAttribL1dv;
#define glVertexAttribL1dv \
        CoreGl_VertexAttribL1dv

TRANSGL_API
PFNGLVERTEXATTRIBL2DVPROC
CoreGl_VertexAttribL2dv;
#define glVertexAttribL2dv \
        CoreGl_VertexAttribL2dv

TRANSGL_API
PFNGLVERTEXATTRIBL3DVPROC
CoreGl_VertexAttribL3dv;
#define glVertexAttribL3dv \
        CoreGl_VertexAttribL3dv

TRANSGL_API
PFNGLVERTEXATTRIBL4DVPROC
CoreGl_VertexAttribL4dv;
#define glVertexAttribL4dv \
        CoreGl_VertexAttribL4dv

TRANSGL_API
PFNGLVERTEXATTRIBLPOINTERPROC
CoreGl_VertexAttribLPointer;
#define glVertexAttribLPointer \
        CoreGl_VertexAttribLPointer

TRANSGL_API
PFNGLGETVERTEXATTRIBLDVPROC
CoreGl_GetVertexAttribLdv;
#define glGetVertexAttribLdv \
        CoreGl_GetVertexAttribLdv

TRANSGL_API
PFNGLVIEWPORTARRAYVPROC
CoreGl_ViewportArrayv;
#define glViewportArrayv \
        CoreGl_ViewportArrayv

TRANSGL_API
PFNGLVIEWPORTINDEXEDFPROC
CoreGl_ViewportIndexedf;
#define glViewportIndexedf \
        CoreGl_ViewportIndexedf

TRANSGL_API
PFNGLVIEWPORTINDEXEDFVPROC
CoreGl_ViewportIndexedfv;
#define glViewportIndexedfv \
        CoreGl_ViewportIndexedfv

TRANSGL_API
PFNGLSCISSORARRAYVPROC
CoreGl_ScissorArrayv;
#define glScissorArrayv \
        CoreGl_ScissorArrayv

TRANSGL_API
PFNGLSCISSORINDEXEDPROC
CoreGl_ScissorIndexed;
#define glScissorIndexed \
        CoreGl_ScissorIndexed

TRANSGL_API
PFNGLSCISSORINDEXEDVPROC
CoreGl_ScissorIndexedv;
#define glScissorIndexedv \
        CoreGl_ScissorIndexedv

TRANSGL_API
PFNGLDEPTHRANGEARRAYVPROC
CoreGl_DepthRangeArrayv;
#define glDepthRangeArrayv \
        CoreGl_DepthRangeArrayv

TRANSGL_API
PFNGLDEPTHRANGEINDEXEDPROC
CoreGl_DepthRangeIndexed;
#define glDepthRangeIndexed \
        CoreGl_DepthRangeIndexed

TRANSGL_API
PFNGLGETFLOATI_VPROC
CoreGl_GetFloati_v;
#define glGetFloati_v \
        CoreGl_GetFloati_v

TRANSGL_API
PFNGLGETDOUBLEI_VPROC
CoreGl_GetDoublei_v;
#define glGetDoublei_v \
        CoreGl_GetDoublei_v

//---- VERSION_4_2 ----

INLINE
bool
CoreGl_has_VERSION_4_2(void)
{
return _CoreGl_mgr.has_VERSION_4_2;
}

TRANSGL_API
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC
CoreGl_DrawArraysInstancedBaseInstance;
#define glDrawArraysInstancedBaseInstance \
        CoreGl_DrawArraysInstancedBaseInstance

TRANSGL_API
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC
CoreGl_DrawElementsInstancedBaseInstance;
#define glDrawElementsInstancedBaseInstance \
        CoreGl_DrawElementsInstancedBaseInstance

TRANSGL_API
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC
CoreGl_DrawElementsInstancedBaseVertexBaseInstance;
#define glDrawElementsInstancedBaseVertexBaseInstance \
        CoreGl_DrawElementsInstancedBaseVertexBaseInstance

TRANSGL_API
PFNGLGETINTERNALFORMATIVPROC
CoreGl_GetInternalformativ;
#define glGetInternalformativ \
        CoreGl_GetInternalformativ

TRANSGL_API
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC
CoreGl_GetActiveAtomicCounterBufferiv;
#define glGetActiveAtomicCounterBufferiv \
        CoreGl_GetActiveAtomicCounterBufferiv

TRANSGL_API
PFNGLBINDIMAGETEXTUREPROC
CoreGl_BindImageTexture;
#define glBindImageTexture \
        CoreGl_BindImageTexture

TRANSGL_API
PFNGLMEMORYBARRIERPROC
CoreGl_MemoryBarrier;
#define glMemoryBarrier \
        CoreGl_MemoryBarrier

TRANSGL_API
PFNGLTEXSTORAGE1DPROC
CoreGl_TexStorage1D;
#define glTexStorage1D \
        CoreGl_TexStorage1D

TRANSGL_API
PFNGLTEXSTORAGE2DPROC
CoreGl_TexStorage2D;
#define glTexStorage2D \
        CoreGl_TexStorage2D

TRANSGL_API
PFNGLTEXSTORAGE3DPROC
CoreGl_TexStorage3D;
#define glTexStorage3D \
        CoreGl_TexStorage3D

TRANSGL_API
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC
CoreGl_DrawTransformFeedbackInstanced;
#define glDrawTransformFeedbackInstanced \
        CoreGl_DrawTransformFeedbackInstanced

TRANSGL_API
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC
CoreGl_DrawTransformFeedbackStreamInstanced;
#define glDrawTransformFeedbackStreamInstanced \
        CoreGl_DrawTransformFeedbackStreamInstanced

//---- VERSION_4_3 ----

INLINE
bool
CoreGl_has_VERSION_4_3(void)
{
return _CoreGl_mgr.has_VERSION_4_3;
}

TRANSGL_API
PFNGLCLEARBUFFERDATAPROC
CoreGl_ClearBufferData;
#define glClearBufferData \
        CoreGl_ClearBufferData

TRANSGL_API
PFNGLCLEARBUFFERSUBDATAPROC
CoreGl_ClearBufferSubData;
#define glClearBufferSubData \
        CoreGl_ClearBufferSubData

TRANSGL_API
PFNGLDISPATCHCOMPUTEPROC
CoreGl_DispatchCompute;
#define glDispatchCompute \
        CoreGl_DispatchCompute

TRANSGL_API
PFNGLDISPATCHCOMPUTEINDIRECTPROC
CoreGl_DispatchComputeIndirect;
#define glDispatchComputeIndirect \
        CoreGl_DispatchComputeIndirect

TRANSGL_API
PFNGLCOPYIMAGESUBDATAPROC
CoreGl_CopyImageSubData;
#define glCopyImageSubData \
        CoreGl_CopyImageSubData

TRANSGL_API
PFNGLFRAMEBUFFERPARAMETERIPROC
CoreGl_FramebufferParameteri;
#define glFramebufferParameteri \
        CoreGl_FramebufferParameteri

TRANSGL_API
PFNGLGETFRAMEBUFFERPARAMETERIVPROC
CoreGl_GetFramebufferParameteriv;
#define glGetFramebufferParameteriv \
        CoreGl_GetFramebufferParameteriv

TRANSGL_API
PFNGLGETINTERNALFORMATI64VPROC
CoreGl_GetInternalformati64v;
#define glGetInternalformati64v \
        CoreGl_GetInternalformati64v

TRANSGL_API
PFNGLINVALIDATETEXSUBIMAGEPROC
CoreGl_InvalidateTexSubImage;
#define glInvalidateTexSubImage \
        CoreGl_InvalidateTexSubImage

TRANSGL_API
PFNGLINVALIDATETEXIMAGEPROC
CoreGl_InvalidateTexImage;
#define glInvalidateTexImage \
        CoreGl_InvalidateTexImage

TRANSGL_API
PFNGLINVALIDATEBUFFERSUBDATAPROC
CoreGl_InvalidateBufferSubData;
#define glInvalidateBufferSubData \
        CoreGl_InvalidateBufferSubData

TRANSGL_API
PFNGLINVALIDATEBUFFERDATAPROC
CoreGl_InvalidateBufferData;
#define glInvalidateBufferData \
        CoreGl_InvalidateBufferData

TRANSGL_API
PFNGLINVALIDATEFRAMEBUFFERPROC
CoreGl_InvalidateFramebuffer;
#define glInvalidateFramebuffer \
        CoreGl_InvalidateFramebuffer

TRANSGL_API
PFNGLINVALIDATESUBFRAMEBUFFERPROC
CoreGl_InvalidateSubFramebuffer;
#define glInvalidateSubFramebuffer \
        CoreGl_InvalidateSubFramebuffer

TRANSGL_API
PFNGLMULTIDRAWARRAYSINDIRECTPROC
CoreGl_MultiDrawArraysIndirect;
#define glMultiDrawArraysIndirect \
        CoreGl_MultiDrawArraysIndirect

TRANSGL_API
PFNGLMULTIDRAWELEMENTSINDIRECTPROC
CoreGl_MultiDrawElementsIndirect;
#define glMultiDrawElementsIndirect \
        CoreGl_MultiDrawElementsIndirect

TRANSGL_API
PFNGLGETPROGRAMINTERFACEIVPROC
CoreGl_GetProgramInterfaceiv;
#define glGetProgramInterfaceiv \
        CoreGl_GetProgramInterfaceiv

TRANSGL_API
PFNGLGETPROGRAMRESOURCEINDEXPROC
CoreGl_GetProgramResourceIndex;
#define glGetProgramResourceIndex \
        CoreGl_GetProgramResourceIndex

TRANSGL_API
PFNGLGETPROGRAMRESOURCENAMEPROC
CoreGl_GetProgramResourceName;
#define glGetProgramResourceName \
        CoreGl_GetProgramResourceName

TRANSGL_API
PFNGLGETPROGRAMRESOURCEIVPROC
CoreGl_GetProgramResourceiv;
#define glGetProgramResourceiv \
        CoreGl_GetProgramResourceiv

TRANSGL_API
PFNGLGETPROGRAMRESOURCELOCATIONPROC
CoreGl_GetProgramResourceLocation;
#define glGetProgramResourceLocation \
        CoreGl_GetProgramResourceLocation

TRANSGL_API
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC
CoreGl_GetProgramResourceLocationIndex;
#define glGetProgramResourceLocationIndex \
        CoreGl_GetProgramResourceLocationIndex

TRANSGL_API
PFNGLSHADERSTORAGEBLOCKBINDINGPROC
CoreGl_ShaderStorageBlockBinding;
#define glShaderStorageBlockBinding \
        CoreGl_ShaderStorageBlockBinding

TRANSGL_API
PFNGLTEXBUFFERRANGEPROC
CoreGl_TexBufferRange;
#define glTexBufferRange \
        CoreGl_TexBufferRange

TRANSGL_API
PFNGLTEXSTORAGE2DMULTISAMPLEPROC
CoreGl_TexStorage2DMultisample;
#define glTexStorage2DMultisample \
        CoreGl_TexStorage2DMultisample

TRANSGL_API
PFNGLTEXSTORAGE3DMULTISAMPLEPROC
CoreGl_TexStorage3DMultisample;
#define glTexStorage3DMultisample \
        CoreGl_TexStorage3DMultisample

TRANSGL_API
PFNGLTEXTUREVIEWPROC
CoreGl_TextureView;
#define glTextureView \
        CoreGl_TextureView

TRANSGL_API
PFNGLBINDVERTEXBUFFERPROC
CoreGl_BindVertexBuffer;
#define glBindVertexBuffer \
        CoreGl_BindVertexBuffer

TRANSGL_API
PFNGLVERTEXATTRIBFORMATPROC
CoreGl_VertexAttribFormat;
#define glVertexAttribFormat \
        CoreGl_VertexAttribFormat

TRANSGL_API
PFNGLVERTEXATTRIBIFORMATPROC
CoreGl_VertexAttribIFormat;
#define glVertexAttribIFormat \
        CoreGl_VertexAttribIFormat

TRANSGL_API
PFNGLVERTEXATTRIBLFORMATPROC
CoreGl_VertexAttribLFormat;
#define glVertexAttribLFormat \
        CoreGl_VertexAttribLFormat

TRANSGL_API
PFNGLVERTEXATTRIBBINDINGPROC
CoreGl_VertexAttribBinding;
#define glVertexAttribBinding \
        CoreGl_VertexAttribBinding

TRANSGL_API
PFNGLVERTEXBINDINGDIVISORPROC
CoreGl_VertexBindingDivisor;
#define glVertexBindingDivisor \
        CoreGl_VertexBindingDivisor

TRANSGL_API
PFNGLDEBUGMESSAGECONTROLPROC
CoreGl_DebugMessageControl;
#define glDebugMessageControl \
        CoreGl_DebugMessageControl

TRANSGL_API
PFNGLDEBUGMESSAGEINSERTPROC
CoreGl_DebugMessageInsert;
#define glDebugMessageInsert \
        CoreGl_DebugMessageInsert

TRANSGL_API
PFNGLDEBUGMESSAGECALLBACKPROC
CoreGl_DebugMessageCallback;
#define glDebugMessageCallback \
        CoreGl_DebugMessageCallback

TRANSGL_API
PFNGLGETDEBUGMESSAGELOGPROC
CoreGl_GetDebugMessageLog;
#define glGetDebugMessageLog \
        CoreGl_GetDebugMessageLog

TRANSGL_API
PFNGLPUSHDEBUGGROUPPROC
CoreGl_PushDebugGroup;
#define glPushDebugGroup \
        CoreGl_PushDebugGroup

TRANSGL_API
PFNGLPOPDEBUGGROUPPROC
CoreGl_PopDebugGroup;
#define glPopDebugGroup \
        CoreGl_PopDebugGroup

TRANSGL_API
PFNGLOBJECTLABELPROC
CoreGl_ObjectLabel;
#define glObjectLabel \
        CoreGl_ObjectLabel

TRANSGL_API
PFNGLGETOBJECTLABELPROC
CoreGl_GetObjectLabel;
#define glGetObjectLabel \
        CoreGl_GetObjectLabel

TRANSGL_API
PFNGLOBJECTPTRLABELPROC
CoreGl_ObjectPtrLabel;
#define glObjectPtrLabel \
        CoreGl_ObjectPtrLabel

TRANSGL_API
PFNGLGETOBJECTPTRLABELPROC
CoreGl_GetObjectPtrLabel;
#define glGetObjectPtrLabel \
        CoreGl_GetObjectPtrLabel

//---- VERSION_4_4 ----

INLINE
bool
CoreGl_has_VERSION_4_4(void)
{
return _CoreGl_mgr.has_VERSION_4_4;
}

TRANSGL_API
PFNGLBUFFERSTORAGEPROC
CoreGl_BufferStorage;
#define glBufferStorage \
        CoreGl_BufferStorage

TRANSGL_API
PFNGLCLEARTEXIMAGEPROC
CoreGl_ClearTexImage;
#define glClearTexImage \
        CoreGl_ClearTexImage

TRANSGL_API
PFNGLCLEARTEXSUBIMAGEPROC
CoreGl_ClearTexSubImage;
#define glClearTexSubImage \
        CoreGl_ClearTexSubImage

TRANSGL_API
PFNGLBINDBUFFERSBASEPROC
CoreGl_BindBuffersBase;
#define glBindBuffersBase \
        CoreGl_BindBuffersBase

TRANSGL_API
PFNGLBINDBUFFERSRANGEPROC
CoreGl_BindBuffersRange;
#define glBindBuffersRange \
        CoreGl_BindBuffersRange

TRANSGL_API
PFNGLBINDTEXTURESPROC
CoreGl_BindTextures;
#define glBindTextures \
        CoreGl_BindTextures

TRANSGL_API
PFNGLBINDSAMPLERSPROC
CoreGl_BindSamplers;
#define glBindSamplers \
        CoreGl_BindSamplers

TRANSGL_API
PFNGLBINDIMAGETEXTURESPROC
CoreGl_BindImageTextures;
#define glBindImageTextures \
        CoreGl_BindImageTextures

TRANSGL_API
PFNGLBINDVERTEXBUFFERSPROC
CoreGl_BindVertexBuffers;
#define glBindVertexBuffers \
        CoreGl_BindVertexBuffers

//---- VERSION_4_5 ----

INLINE
bool
CoreGl_has_VERSION_4_5(void)
{
return _CoreGl_mgr.has_VERSION_4_5;
}

TRANSGL_API
PFNGLCLIPCONTROLPROC
CoreGl_ClipControl;
#define glClipControl \
        CoreGl_ClipControl

TRANSGL_API
PFNGLCREATETRANSFORMFEEDBACKSPROC
CoreGl_CreateTransformFeedbacks;
#define glCreateTransformFeedbacks \
        CoreGl_CreateTransformFeedbacks

TRANSGL_API
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC
CoreGl_TransformFeedbackBufferBase;
#define glTransformFeedbackBufferBase \
        CoreGl_TransformFeedbackBufferBase

TRANSGL_API
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC
CoreGl_TransformFeedbackBufferRange;
#define glTransformFeedbackBufferRange \
        CoreGl_TransformFeedbackBufferRange

TRANSGL_API
PFNGLGETTRANSFORMFEEDBACKIVPROC
CoreGl_GetTransformFeedbackiv;
#define glGetTransformFeedbackiv \
        CoreGl_GetTransformFeedbackiv

TRANSGL_API
PFNGLGETTRANSFORMFEEDBACKI_VPROC
CoreGl_GetTransformFeedbacki_v;
#define glGetTransformFeedbacki_v \
        CoreGl_GetTransformFeedbacki_v

TRANSGL_API
PFNGLGETTRANSFORMFEEDBACKI64_VPROC
CoreGl_GetTransformFeedbacki64_v;
#define glGetTransformFeedbacki64_v \
        CoreGl_GetTransformFeedbacki64_v

TRANSGL_API
PFNGLCREATEBUFFERSPROC
CoreGl_CreateBuffers;
#define glCreateBuffers \
        CoreGl_CreateBuffers

TRANSGL_API
PFNGLNAMEDBUFFERSTORAGEPROC
CoreGl_NamedBufferStorage;
#define glNamedBufferStorage \
        CoreGl_NamedBufferStorage

TRANSGL_API
PFNGLNAMEDBUFFERDATAPROC
CoreGl_NamedBufferData;
#define glNamedBufferData \
        CoreGl_NamedBufferData

TRANSGL_API
PFNGLNAMEDBUFFERSUBDATAPROC
CoreGl_NamedBufferSubData;
#define glNamedBufferSubData \
        CoreGl_NamedBufferSubData

TRANSGL_API
PFNGLCOPYNAMEDBUFFERSUBDATAPROC
CoreGl_CopyNamedBufferSubData;
#define glCopyNamedBufferSubData \
        CoreGl_CopyNamedBufferSubData

TRANSGL_API
PFNGLCLEARNAMEDBUFFERDATAPROC
CoreGl_ClearNamedBufferData;
#define glClearNamedBufferData \
        CoreGl_ClearNamedBufferData

TRANSGL_API
PFNGLCLEARNAMEDBUFFERSUBDATAPROC
CoreGl_ClearNamedBufferSubData;
#define glClearNamedBufferSubData \
        CoreGl_ClearNamedBufferSubData

TRANSGL_API
PFNGLMAPNAMEDBUFFERPROC
CoreGl_MapNamedBuffer;
#define glMapNamedBuffer \
        CoreGl_MapNamedBuffer

TRANSGL_API
PFNGLMAPNAMEDBUFFERRANGEPROC
CoreGl_MapNamedBufferRange;
#define glMapNamedBufferRange \
        CoreGl_MapNamedBufferRange

TRANSGL_API
PFNGLUNMAPNAMEDBUFFERPROC
CoreGl_UnmapNamedBuffer;
#define glUnmapNamedBuffer \
        CoreGl_UnmapNamedBuffer

TRANSGL_API
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC
CoreGl_FlushMappedNamedBufferRange;
#define glFlushMappedNamedBufferRange \
        CoreGl_FlushMappedNamedBufferRange

TRANSGL_API
PFNGLGETNAMEDBUFFERPARAMETERIVPROC
CoreGl_GetNamedBufferParameteriv;
#define glGetNamedBufferParameteriv \
        CoreGl_GetNamedBufferParameteriv

TRANSGL_API
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC
CoreGl_GetNamedBufferParameteri64v;
#define glGetNamedBufferParameteri64v \
        CoreGl_GetNamedBufferParameteri64v

TRANSGL_API
PFNGLGETNAMEDBUFFERPOINTERVPROC
CoreGl_GetNamedBufferPointerv;
#define glGetNamedBufferPointerv \
        CoreGl_GetNamedBufferPointerv

TRANSGL_API
PFNGLGETNAMEDBUFFERSUBDATAPROC
CoreGl_GetNamedBufferSubData;
#define glGetNamedBufferSubData \
        CoreGl_GetNamedBufferSubData

TRANSGL_API
PFNGLCREATEFRAMEBUFFERSPROC
CoreGl_CreateFramebuffers;
#define glCreateFramebuffers \
        CoreGl_CreateFramebuffers

TRANSGL_API
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC
CoreGl_NamedFramebufferRenderbuffer;
#define glNamedFramebufferRenderbuffer \
        CoreGl_NamedFramebufferRenderbuffer

TRANSGL_API
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC
CoreGl_NamedFramebufferParameteri;
#define glNamedFramebufferParameteri \
        CoreGl_NamedFramebufferParameteri

TRANSGL_API
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC
CoreGl_NamedFramebufferTexture;
#define glNamedFramebufferTexture \
        CoreGl_NamedFramebufferTexture

TRANSGL_API
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC
CoreGl_NamedFramebufferTextureLayer;
#define glNamedFramebufferTextureLayer \
        CoreGl_NamedFramebufferTextureLayer

TRANSGL_API
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC
CoreGl_NamedFramebufferDrawBuffer;
#define glNamedFramebufferDrawBuffer \
        CoreGl_NamedFramebufferDrawBuffer

TRANSGL_API
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC
CoreGl_NamedFramebufferDrawBuffers;
#define glNamedFramebufferDrawBuffers \
        CoreGl_NamedFramebufferDrawBuffers

TRANSGL_API
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC
CoreGl_NamedFramebufferReadBuffer;
#define glNamedFramebufferReadBuffer \
        CoreGl_NamedFramebufferReadBuffer

TRANSGL_API
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC
CoreGl_InvalidateNamedFramebufferData;
#define glInvalidateNamedFramebufferData \
        CoreGl_InvalidateNamedFramebufferData

TRANSGL_API
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC
CoreGl_InvalidateNamedFramebufferSubData;
#define glInvalidateNamedFramebufferSubData \
        CoreGl_InvalidateNamedFramebufferSubData

TRANSGL_API
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC
CoreGl_ClearNamedFramebufferiv;
#define glClearNamedFramebufferiv \
        CoreGl_ClearNamedFramebufferiv

TRANSGL_API
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC
CoreGl_ClearNamedFramebufferuiv;
#define glClearNamedFramebufferuiv \
        CoreGl_ClearNamedFramebufferuiv

TRANSGL_API
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC
CoreGl_ClearNamedFramebufferfv;
#define glClearNamedFramebufferfv \
        CoreGl_ClearNamedFramebufferfv

TRANSGL_API
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC
CoreGl_ClearNamedFramebufferfi;
#define glClearNamedFramebufferfi \
        CoreGl_ClearNamedFramebufferfi

TRANSGL_API
PFNGLBLITNAMEDFRAMEBUFFERPROC
CoreGl_BlitNamedFramebuffer;
#define glBlitNamedFramebuffer \
        CoreGl_BlitNamedFramebuffer

TRANSGL_API
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC
CoreGl_CheckNamedFramebufferStatus;
#define glCheckNamedFramebufferStatus \
        CoreGl_CheckNamedFramebufferStatus

TRANSGL_API
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC
CoreGl_GetNamedFramebufferParameteriv;
#define glGetNamedFramebufferParameteriv \
        CoreGl_GetNamedFramebufferParameteriv

TRANSGL_API
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC
CoreGl_GetNamedFramebufferAttachmentParameteriv;
#define glGetNamedFramebufferAttachmentParameteriv \
        CoreGl_GetNamedFramebufferAttachmentParameteriv

TRANSGL_API
PFNGLCREATERENDERBUFFERSPROC
CoreGl_CreateRenderbuffers;
#define glCreateRenderbuffers \
        CoreGl_CreateRenderbuffers

TRANSGL_API
PFNGLNAMEDRENDERBUFFERSTORAGEPROC
CoreGl_NamedRenderbufferStorage;
#define glNamedRenderbufferStorage \
        CoreGl_NamedRenderbufferStorage

TRANSGL_API
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC
CoreGl_NamedRenderbufferStorageMultisample;
#define glNamedRenderbufferStorageMultisample \
        CoreGl_NamedRenderbufferStorageMultisample

TRANSGL_API
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC
CoreGl_GetNamedRenderbufferParameteriv;
#define glGetNamedRenderbufferParameteriv \
        CoreGl_GetNamedRenderbufferParameteriv

TRANSGL_API
PFNGLCREATETEXTURESPROC
CoreGl_CreateTextures;
#define glCreateTextures \
        CoreGl_CreateTextures

TRANSGL_API
PFNGLTEXTUREBUFFERPROC
CoreGl_TextureBuffer;
#define glTextureBuffer \
        CoreGl_TextureBuffer

TRANSGL_API
PFNGLTEXTUREBUFFERRANGEPROC
CoreGl_TextureBufferRange;
#define glTextureBufferRange \
        CoreGl_TextureBufferRange

TRANSGL_API
PFNGLTEXTURESTORAGE1DPROC
CoreGl_TextureStorage1D;
#define glTextureStorage1D \
        CoreGl_TextureStorage1D

TRANSGL_API
PFNGLTEXTURESTORAGE2DPROC
CoreGl_TextureStorage2D;
#define glTextureStorage2D \
        CoreGl_TextureStorage2D

TRANSGL_API
PFNGLTEXTURESTORAGE3DPROC
CoreGl_TextureStorage3D;
#define glTextureStorage3D \
        CoreGl_TextureStorage3D

TRANSGL_API
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC
CoreGl_TextureStorage2DMultisample;
#define glTextureStorage2DMultisample \
        CoreGl_TextureStorage2DMultisample

TRANSGL_API
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC
CoreGl_TextureStorage3DMultisample;
#define glTextureStorage3DMultisample \
        CoreGl_TextureStorage3DMultisample

TRANSGL_API
PFNGLTEXTURESUBIMAGE1DPROC
CoreGl_TextureSubImage1D;
#define glTextureSubImage1D \
        CoreGl_TextureSubImage1D

TRANSGL_API
PFNGLTEXTURESUBIMAGE2DPROC
CoreGl_TextureSubImage2D;
#define glTextureSubImage2D \
        CoreGl_TextureSubImage2D

TRANSGL_API
PFNGLTEXTURESUBIMAGE3DPROC
CoreGl_TextureSubImage3D;
#define glTextureSubImage3D \
        CoreGl_TextureSubImage3D

TRANSGL_API
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC
CoreGl_CompressedTextureSubImage1D;
#define glCompressedTextureSubImage1D \
        CoreGl_CompressedTextureSubImage1D

TRANSGL_API
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC
CoreGl_CompressedTextureSubImage2D;
#define glCompressedTextureSubImage2D \
        CoreGl_CompressedTextureSubImage2D

TRANSGL_API
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC
CoreGl_CompressedTextureSubImage3D;
#define glCompressedTextureSubImage3D \
        CoreGl_CompressedTextureSubImage3D

TRANSGL_API
PFNGLCOPYTEXTURESUBIMAGE1DPROC
CoreGl_CopyTextureSubImage1D;
#define glCopyTextureSubImage1D \
        CoreGl_CopyTextureSubImage1D

TRANSGL_API
PFNGLCOPYTEXTURESUBIMAGE2DPROC
CoreGl_CopyTextureSubImage2D;
#define glCopyTextureSubImage2D \
        CoreGl_CopyTextureSubImage2D

TRANSGL_API
PFNGLCOPYTEXTURESUBIMAGE3DPROC
CoreGl_CopyTextureSubImage3D;
#define glCopyTextureSubImage3D \
        CoreGl_CopyTextureSubImage3D

TRANSGL_API
PFNGLTEXTUREPARAMETERFPROC
CoreGl_TextureParameterf;
#define glTextureParameterf \
        CoreGl_TextureParameterf

TRANSGL_API
PFNGLTEXTUREPARAMETERFVPROC
CoreGl_TextureParameterfv;
#define glTextureParameterfv \
        CoreGl_TextureParameterfv

TRANSGL_API
PFNGLTEXTUREPARAMETERIPROC
CoreGl_TextureParameteri;
#define glTextureParameteri \
        CoreGl_TextureParameteri

TRANSGL_API
PFNGLTEXTUREPARAMETERIIVPROC
CoreGl_TextureParameterIiv;
#define glTextureParameterIiv \
        CoreGl_TextureParameterIiv

TRANSGL_API
PFNGLTEXTUREPARAMETERIUIVPROC
CoreGl_TextureParameterIuiv;
#define glTextureParameterIuiv \
        CoreGl_TextureParameterIuiv

TRANSGL_API
PFNGLTEXTUREPARAMETERIVPROC
CoreGl_TextureParameteriv;
#define glTextureParameteriv \
        CoreGl_TextureParameteriv

TRANSGL_API
PFNGLGENERATETEXTUREMIPMAPPROC
CoreGl_GenerateTextureMipmap;
#define glGenerateTextureMipmap \
        CoreGl_GenerateTextureMipmap

TRANSGL_API
PFNGLBINDTEXTUREUNITPROC
CoreGl_BindTextureUnit;
#define glBindTextureUnit \
        CoreGl_BindTextureUnit

TRANSGL_API
PFNGLGETTEXTUREIMAGEPROC
CoreGl_GetTextureImage;
#define glGetTextureImage \
        CoreGl_GetTextureImage

TRANSGL_API
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC
CoreGl_GetCompressedTextureImage;
#define glGetCompressedTextureImage \
        CoreGl_GetCompressedTextureImage

TRANSGL_API
PFNGLGETTEXTURELEVELPARAMETERFVPROC
CoreGl_GetTextureLevelParameterfv;
#define glGetTextureLevelParameterfv \
        CoreGl_GetTextureLevelParameterfv

TRANSGL_API
PFNGLGETTEXTURELEVELPARAMETERIVPROC
CoreGl_GetTextureLevelParameteriv;
#define glGetTextureLevelParameteriv \
        CoreGl_GetTextureLevelParameteriv

TRANSGL_API
PFNGLGETTEXTUREPARAMETERFVPROC
CoreGl_GetTextureParameterfv;
#define glGetTextureParameterfv \
        CoreGl_GetTextureParameterfv

TRANSGL_API
PFNGLGETTEXTUREPARAMETERIIVPROC
CoreGl_GetTextureParameterIiv;
#define glGetTextureParameterIiv \
        CoreGl_GetTextureParameterIiv

TRANSGL_API
PFNGLGETTEXTUREPARAMETERIUIVPROC
CoreGl_GetTextureParameterIuiv;
#define glGetTextureParameterIuiv \
        CoreGl_GetTextureParameterIuiv

TRANSGL_API
PFNGLGETTEXTUREPARAMETERIVPROC
CoreGl_GetTextureParameteriv;
#define glGetTextureParameteriv \
        CoreGl_GetTextureParameteriv

TRANSGL_API
PFNGLCREATEVERTEXARRAYSPROC
CoreGl_CreateVertexArrays;
#define glCreateVertexArrays \
        CoreGl_CreateVertexArrays

TRANSGL_API
PFNGLDISABLEVERTEXARRAYATTRIBPROC
CoreGl_DisableVertexArrayAttrib;
#define glDisableVertexArrayAttrib \
        CoreGl_DisableVertexArrayAttrib

TRANSGL_API
PFNGLENABLEVERTEXARRAYATTRIBPROC
CoreGl_EnableVertexArrayAttrib;
#define glEnableVertexArrayAttrib \
        CoreGl_EnableVertexArrayAttrib

TRANSGL_API
PFNGLVERTEXARRAYELEMENTBUFFERPROC
CoreGl_VertexArrayElementBuffer;
#define glVertexArrayElementBuffer \
        CoreGl_VertexArrayElementBuffer

TRANSGL_API
PFNGLVERTEXARRAYVERTEXBUFFERPROC
CoreGl_VertexArrayVertexBuffer;
#define glVertexArrayVertexBuffer \
        CoreGl_VertexArrayVertexBuffer

TRANSGL_API
PFNGLVERTEXARRAYVERTEXBUFFERSPROC
CoreGl_VertexArrayVertexBuffers;
#define glVertexArrayVertexBuffers \
        CoreGl_VertexArrayVertexBuffers

TRANSGL_API
PFNGLVERTEXARRAYATTRIBBINDINGPROC
CoreGl_VertexArrayAttribBinding;
#define glVertexArrayAttribBinding \
        CoreGl_VertexArrayAttribBinding

TRANSGL_API
PFNGLVERTEXARRAYATTRIBFORMATPROC
CoreGl_VertexArrayAttribFormat;
#define glVertexArrayAttribFormat \
        CoreGl_VertexArrayAttribFormat

TRANSGL_API
PFNGLVERTEXARRAYATTRIBIFORMATPROC
CoreGl_VertexArrayAttribIFormat;
#define glVertexArrayAttribIFormat \
        CoreGl_VertexArrayAttribIFormat

TRANSGL_API
PFNGLVERTEXARRAYATTRIBLFORMATPROC
CoreGl_VertexArrayAttribLFormat;
#define glVertexArrayAttribLFormat \
        CoreGl_VertexArrayAttribLFormat

TRANSGL_API
PFNGLVERTEXARRAYBINDINGDIVISORPROC
CoreGl_VertexArrayBindingDivisor;
#define glVertexArrayBindingDivisor \
        CoreGl_VertexArrayBindingDivisor

TRANSGL_API
PFNGLGETVERTEXARRAYIVPROC
CoreGl_GetVertexArrayiv;
#define glGetVertexArrayiv \
        CoreGl_GetVertexArrayiv

TRANSGL_API
PFNGLGETVERTEXARRAYINDEXEDIVPROC
CoreGl_GetVertexArrayIndexediv;
#define glGetVertexArrayIndexediv \
        CoreGl_GetVertexArrayIndexediv

TRANSGL_API
PFNGLGETVERTEXARRAYINDEXED64IVPROC
CoreGl_GetVertexArrayIndexed64iv;
#define glGetVertexArrayIndexed64iv \
        CoreGl_GetVertexArrayIndexed64iv

TRANSGL_API
PFNGLCREATESAMPLERSPROC
CoreGl_CreateSamplers;
#define glCreateSamplers \
        CoreGl_CreateSamplers

TRANSGL_API
PFNGLCREATEPROGRAMPIPELINESPROC
CoreGl_CreateProgramPipelines;
#define glCreateProgramPipelines \
        CoreGl_CreateProgramPipelines

TRANSGL_API
PFNGLCREATEQUERIESPROC
CoreGl_CreateQueries;
#define glCreateQueries \
        CoreGl_CreateQueries

TRANSGL_API
PFNGLGETQUERYBUFFEROBJECTI64VPROC
CoreGl_GetQueryBufferObjecti64v;
#define glGetQueryBufferObjecti64v \
        CoreGl_GetQueryBufferObjecti64v

TRANSGL_API
PFNGLGETQUERYBUFFEROBJECTIVPROC
CoreGl_GetQueryBufferObjectiv;
#define glGetQueryBufferObjectiv \
        CoreGl_GetQueryBufferObjectiv

TRANSGL_API
PFNGLGETQUERYBUFFEROBJECTUI64VPROC
CoreGl_GetQueryBufferObjectui64v;
#define glGetQueryBufferObjectui64v \
        CoreGl_GetQueryBufferObjectui64v

TRANSGL_API
PFNGLGETQUERYBUFFEROBJECTUIVPROC
CoreGl_GetQueryBufferObjectuiv;
#define glGetQueryBufferObjectuiv \
        CoreGl_GetQueryBufferObjectuiv

TRANSGL_API
PFNGLMEMORYBARRIERBYREGIONPROC
CoreGl_MemoryBarrierByRegion;
#define glMemoryBarrierByRegion \
        CoreGl_MemoryBarrierByRegion

TRANSGL_API
PFNGLGETTEXTURESUBIMAGEPROC
CoreGl_GetTextureSubImage;
#define glGetTextureSubImage \
        CoreGl_GetTextureSubImage

TRANSGL_API
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC
CoreGl_GetCompressedTextureSubImage;
#define glGetCompressedTextureSubImage \
        CoreGl_GetCompressedTextureSubImage

TRANSGL_API
PFNGLGETGRAPHICSRESETSTATUSPROC
CoreGl_GetGraphicsResetStatus;
#define glGetGraphicsResetStatus \
        CoreGl_GetGraphicsResetStatus

TRANSGL_API
PFNGLGETNCOMPRESSEDTEXIMAGEPROC
CoreGl_GetnCompressedTexImage;
#define glGetnCompressedTexImage \
        CoreGl_GetnCompressedTexImage

TRANSGL_API
PFNGLGETNTEXIMAGEPROC
CoreGl_GetnTexImage;
#define glGetnTexImage \
        CoreGl_GetnTexImage

TRANSGL_API
PFNGLGETNUNIFORMDVPROC
CoreGl_GetnUniformdv;
#define glGetnUniformdv \
        CoreGl_GetnUniformdv

TRANSGL_API
PFNGLGETNUNIFORMFVPROC
CoreGl_GetnUniformfv;
#define glGetnUniformfv \
        CoreGl_GetnUniformfv

TRANSGL_API
PFNGLGETNUNIFORMIVPROC
CoreGl_GetnUniformiv;
#define glGetnUniformiv \
        CoreGl_GetnUniformiv

TRANSGL_API
PFNGLGETNUNIFORMUIVPROC
CoreGl_GetnUniformuiv;
#define glGetnUniformuiv \
        CoreGl_GetnUniformuiv

TRANSGL_API
PFNGLREADNPIXELSPROC
CoreGl_ReadnPixels;
#define glReadnPixels \
        CoreGl_ReadnPixels

TRANSGL_API
PFNGLTEXTUREBARRIERPROC
CoreGl_TextureBarrier;
#define glTextureBarrier \
        CoreGl_TextureBarrier

//---- ARB_ES2_compatibility ----

INLINE
bool
CoreGl_has_ARB_ES2_compatibility(void)
{
return _CoreGl_mgr.has_ARB_ES2_compatibility;
}

//---- ARB_ES3_1_compatibility ----

INLINE
bool
CoreGl_has_ARB_ES3_1_compatibility(void)
{
return _CoreGl_mgr.has_ARB_ES3_1_compatibility;
}

//---- ARB_ES3_compatibility ----

INLINE
bool
CoreGl_has_ARB_ES3_compatibility(void)
{
return _CoreGl_mgr.has_ARB_ES3_compatibility;
}

//---- ARB_arrays_of_arrays ----

INLINE
bool
CoreGl_has_ARB_arrays_of_arrays(void)
{
return _CoreGl_mgr.has_ARB_arrays_of_arrays;
}

//---- ARB_base_instance ----

INLINE
bool
CoreGl_has_ARB_base_instance(void)
{
return _CoreGl_mgr.has_ARB_base_instance;
}

//---- ARB_bindless_texture ----

INLINE
bool
CoreGl_has_ARB_bindless_texture(void)
{
return _CoreGl_mgr.has_ARB_bindless_texture;
}

TRANSGL_API
PFNGLGETTEXTUREHANDLEARBPROC
CoreGl_GetTextureHandleARB;
#define glGetTextureHandleARB \
        CoreGl_GetTextureHandleARB

TRANSGL_API
PFNGLGETTEXTURESAMPLERHANDLEARBPROC
CoreGl_GetTextureSamplerHandleARB;
#define glGetTextureSamplerHandleARB \
        CoreGl_GetTextureSamplerHandleARB

TRANSGL_API
PFNGLMAKETEXTUREHANDLERESIDENTARBPROC
CoreGl_MakeTextureHandleResidentARB;
#define glMakeTextureHandleResidentARB \
        CoreGl_MakeTextureHandleResidentARB

TRANSGL_API
PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC
CoreGl_MakeTextureHandleNonResidentARB;
#define glMakeTextureHandleNonResidentARB \
        CoreGl_MakeTextureHandleNonResidentARB

TRANSGL_API
PFNGLGETIMAGEHANDLEARBPROC
CoreGl_GetImageHandleARB;
#define glGetImageHandleARB \
        CoreGl_GetImageHandleARB

TRANSGL_API
PFNGLMAKEIMAGEHANDLERESIDENTARBPROC
CoreGl_MakeImageHandleResidentARB;
#define glMakeImageHandleResidentARB \
        CoreGl_MakeImageHandleResidentARB

TRANSGL_API
PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC
CoreGl_MakeImageHandleNonResidentARB;
#define glMakeImageHandleNonResidentARB \
        CoreGl_MakeImageHandleNonResidentARB

TRANSGL_API
PFNGLUNIFORMHANDLEUI64ARBPROC
CoreGl_UniformHandleui64ARB;
#define glUniformHandleui64ARB \
        CoreGl_UniformHandleui64ARB

TRANSGL_API
PFNGLUNIFORMHANDLEUI64VARBPROC
CoreGl_UniformHandleui64vARB;
#define glUniformHandleui64vARB \
        CoreGl_UniformHandleui64vARB

TRANSGL_API
PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC
CoreGl_ProgramUniformHandleui64ARB;
#define glProgramUniformHandleui64ARB \
        CoreGl_ProgramUniformHandleui64ARB

TRANSGL_API
PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC
CoreGl_ProgramUniformHandleui64vARB;
#define glProgramUniformHandleui64vARB \
        CoreGl_ProgramUniformHandleui64vARB

TRANSGL_API
PFNGLISTEXTUREHANDLERESIDENTARBPROC
CoreGl_IsTextureHandleResidentARB;
#define glIsTextureHandleResidentARB \
        CoreGl_IsTextureHandleResidentARB

TRANSGL_API
PFNGLISIMAGEHANDLERESIDENTARBPROC
CoreGl_IsImageHandleResidentARB;
#define glIsImageHandleResidentARB \
        CoreGl_IsImageHandleResidentARB

TRANSGL_API
PFNGLVERTEXATTRIBL1UI64ARBPROC
CoreGl_VertexAttribL1ui64ARB;
#define glVertexAttribL1ui64ARB \
        CoreGl_VertexAttribL1ui64ARB

TRANSGL_API
PFNGLVERTEXATTRIBL1UI64VARBPROC
CoreGl_VertexAttribL1ui64vARB;
#define glVertexAttribL1ui64vARB \
        CoreGl_VertexAttribL1ui64vARB

TRANSGL_API
PFNGLGETVERTEXATTRIBLUI64VARBPROC
CoreGl_GetVertexAttribLui64vARB;
#define glGetVertexAttribLui64vARB \
        CoreGl_GetVertexAttribLui64vARB

//---- ARB_blend_func_extended ----

INLINE
bool
CoreGl_has_ARB_blend_func_extended(void)
{
return _CoreGl_mgr.has_ARB_blend_func_extended;
}

//---- ARB_buffer_storage ----

INLINE
bool
CoreGl_has_ARB_buffer_storage(void)
{
return _CoreGl_mgr.has_ARB_buffer_storage;
}

//---- ARB_cl_event ----

INLINE
bool
CoreGl_has_ARB_cl_event(void)
{
return _CoreGl_mgr.has_ARB_cl_event;
}

TRANSGL_API
PFNGLCREATESYNCFROMCLEVENTARBPROC
CoreGl_CreateSyncFromCLeventARB;
#define glCreateSyncFromCLeventARB \
        CoreGl_CreateSyncFromCLeventARB

//---- ARB_clear_buffer_object ----

INLINE
bool
CoreGl_has_ARB_clear_buffer_object(void)
{
return _CoreGl_mgr.has_ARB_clear_buffer_object;
}

//---- ARB_clear_texture ----

INLINE
bool
CoreGl_has_ARB_clear_texture(void)
{
return _CoreGl_mgr.has_ARB_clear_texture;
}

//---- ARB_clip_control ----

INLINE
bool
CoreGl_has_ARB_clip_control(void)
{
return _CoreGl_mgr.has_ARB_clip_control;
}

//---- ARB_compressed_texture_pixel_storage ----

INLINE
bool
CoreGl_has_ARB_compressed_texture_pixel_storage(void)
{
return _CoreGl_mgr.has_ARB_compressed_texture_pixel_storage;
}

//---- ARB_compute_shader ----

INLINE
bool
CoreGl_has_ARB_compute_shader(void)
{
return _CoreGl_mgr.has_ARB_compute_shader;
}

//---- ARB_compute_variable_group_size ----

INLINE
bool
CoreGl_has_ARB_compute_variable_group_size(void)
{
return _CoreGl_mgr.has_ARB_compute_variable_group_size;
}

TRANSGL_API
PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC
CoreGl_DispatchComputeGroupSizeARB;
#define glDispatchComputeGroupSizeARB \
        CoreGl_DispatchComputeGroupSizeARB

//---- ARB_conditional_render_inverted ----

INLINE
bool
CoreGl_has_ARB_conditional_render_inverted(void)
{
return _CoreGl_mgr.has_ARB_conditional_render_inverted;
}

//---- ARB_conservative_depth ----

INLINE
bool
CoreGl_has_ARB_conservative_depth(void)
{
return _CoreGl_mgr.has_ARB_conservative_depth;
}

//---- ARB_copy_buffer ----

INLINE
bool
CoreGl_has_ARB_copy_buffer(void)
{
return _CoreGl_mgr.has_ARB_copy_buffer;
}

//---- ARB_copy_image ----

INLINE
bool
CoreGl_has_ARB_copy_image(void)
{
return _CoreGl_mgr.has_ARB_copy_image;
}

//---- ARB_cull_distance ----

INLINE
bool
CoreGl_has_ARB_cull_distance(void)
{
return _CoreGl_mgr.has_ARB_cull_distance;
}

//---- ARB_debug_output ----

INLINE
bool
CoreGl_has_ARB_debug_output(void)
{
return _CoreGl_mgr.has_ARB_debug_output;
}

TRANSGL_API
PFNGLDEBUGMESSAGECONTROLARBPROC
CoreGl_DebugMessageControlARB;
#define glDebugMessageControlARB \
        CoreGl_DebugMessageControlARB

TRANSGL_API
PFNGLDEBUGMESSAGEINSERTARBPROC
CoreGl_DebugMessageInsertARB;
#define glDebugMessageInsertARB \
        CoreGl_DebugMessageInsertARB

TRANSGL_API
PFNGLDEBUGMESSAGECALLBACKARBPROC
CoreGl_DebugMessageCallbackARB;
#define glDebugMessageCallbackARB \
        CoreGl_DebugMessageCallbackARB

TRANSGL_API
PFNGLGETDEBUGMESSAGELOGARBPROC
CoreGl_GetDebugMessageLogARB;
#define glGetDebugMessageLogARB \
        CoreGl_GetDebugMessageLogARB

//---- ARB_depth_buffer_float ----

INLINE
bool
CoreGl_has_ARB_depth_buffer_float(void)
{
return _CoreGl_mgr.has_ARB_depth_buffer_float;
}

//---- ARB_depth_clamp ----

INLINE
bool
CoreGl_has_ARB_depth_clamp(void)
{
return _CoreGl_mgr.has_ARB_depth_clamp;
}

//---- ARB_derivative_control ----

INLINE
bool
CoreGl_has_ARB_derivative_control(void)
{
return _CoreGl_mgr.has_ARB_derivative_control;
}

//---- ARB_direct_state_access ----

INLINE
bool
CoreGl_has_ARB_direct_state_access(void)
{
return _CoreGl_mgr.has_ARB_direct_state_access;
}

//---- ARB_draw_buffers_blend ----

INLINE
bool
CoreGl_has_ARB_draw_buffers_blend(void)
{
return _CoreGl_mgr.has_ARB_draw_buffers_blend;
}

TRANSGL_API
PFNGLBLENDEQUATIONIARBPROC
CoreGl_BlendEquationiARB;
#define glBlendEquationiARB \
        CoreGl_BlendEquationiARB

TRANSGL_API
PFNGLBLENDEQUATIONSEPARATEIARBPROC
CoreGl_BlendEquationSeparateiARB;
#define glBlendEquationSeparateiARB \
        CoreGl_BlendEquationSeparateiARB

TRANSGL_API
PFNGLBLENDFUNCIARBPROC
CoreGl_BlendFunciARB;
#define glBlendFunciARB \
        CoreGl_BlendFunciARB

TRANSGL_API
PFNGLBLENDFUNCSEPARATEIARBPROC
CoreGl_BlendFuncSeparateiARB;
#define glBlendFuncSeparateiARB \
        CoreGl_BlendFuncSeparateiARB

//---- ARB_draw_elements_base_vertex ----

INLINE
bool
CoreGl_has_ARB_draw_elements_base_vertex(void)
{
return _CoreGl_mgr.has_ARB_draw_elements_base_vertex;
}

//---- ARB_draw_indirect ----

INLINE
bool
CoreGl_has_ARB_draw_indirect(void)
{
return _CoreGl_mgr.has_ARB_draw_indirect;
}

//---- ARB_enhanced_layouts ----

INLINE
bool
CoreGl_has_ARB_enhanced_layouts(void)
{
return _CoreGl_mgr.has_ARB_enhanced_layouts;
}

//---- ARB_explicit_attrib_location ----

INLINE
bool
CoreGl_has_ARB_explicit_attrib_location(void)
{
return _CoreGl_mgr.has_ARB_explicit_attrib_location;
}

//---- ARB_explicit_uniform_location ----

INLINE
bool
CoreGl_has_ARB_explicit_uniform_location(void)
{
return _CoreGl_mgr.has_ARB_explicit_uniform_location;
}

//---- ARB_fragment_coord_conventions ----

INLINE
bool
CoreGl_has_ARB_fragment_coord_conventions(void)
{
return _CoreGl_mgr.has_ARB_fragment_coord_conventions;
}

//---- ARB_fragment_layer_viewport ----

INLINE
bool
CoreGl_has_ARB_fragment_layer_viewport(void)
{
return _CoreGl_mgr.has_ARB_fragment_layer_viewport;
}

//---- ARB_framebuffer_no_attachments ----

INLINE
bool
CoreGl_has_ARB_framebuffer_no_attachments(void)
{
return _CoreGl_mgr.has_ARB_framebuffer_no_attachments;
}

//---- ARB_framebuffer_object ----

INLINE
bool
CoreGl_has_ARB_framebuffer_object(void)
{
return _CoreGl_mgr.has_ARB_framebuffer_object;
}

//---- ARB_framebuffer_sRGB ----

INLINE
bool
CoreGl_has_ARB_framebuffer_sRGB(void)
{
return _CoreGl_mgr.has_ARB_framebuffer_sRGB;
}

//---- ARB_get_program_binary ----

INLINE
bool
CoreGl_has_ARB_get_program_binary(void)
{
return _CoreGl_mgr.has_ARB_get_program_binary;
}

//---- ARB_get_texture_sub_image ----

INLINE
bool
CoreGl_has_ARB_get_texture_sub_image(void)
{
return _CoreGl_mgr.has_ARB_get_texture_sub_image;
}

//---- ARB_gpu_shader5 ----

INLINE
bool
CoreGl_has_ARB_gpu_shader5(void)
{
return _CoreGl_mgr.has_ARB_gpu_shader5;
}

//---- ARB_gpu_shader_fp64 ----

INLINE
bool
CoreGl_has_ARB_gpu_shader_fp64(void)
{
return _CoreGl_mgr.has_ARB_gpu_shader_fp64;
}

//---- ARB_half_float_vertex ----

INLINE
bool
CoreGl_has_ARB_half_float_vertex(void)
{
return _CoreGl_mgr.has_ARB_half_float_vertex;
}

//---- ARB_imaging ----

INLINE
bool
CoreGl_has_ARB_imaging(void)
{
return _CoreGl_mgr.has_ARB_imaging;
}

//---- ARB_indirect_parameters ----

INLINE
bool
CoreGl_has_ARB_indirect_parameters(void)
{
return _CoreGl_mgr.has_ARB_indirect_parameters;
}

TRANSGL_API
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC
CoreGl_MultiDrawArraysIndirectCountARB;
#define glMultiDrawArraysIndirectCountARB \
        CoreGl_MultiDrawArraysIndirectCountARB

TRANSGL_API
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC
CoreGl_MultiDrawElementsIndirectCountARB;
#define glMultiDrawElementsIndirectCountARB \
        CoreGl_MultiDrawElementsIndirectCountARB

//---- ARB_internalformat_query ----

INLINE
bool
CoreGl_has_ARB_internalformat_query(void)
{
return _CoreGl_mgr.has_ARB_internalformat_query;
}

//---- ARB_internalformat_query2 ----

INLINE
bool
CoreGl_has_ARB_internalformat_query2(void)
{
return _CoreGl_mgr.has_ARB_internalformat_query2;
}

//---- ARB_invalidate_subdata ----

INLINE
bool
CoreGl_has_ARB_invalidate_subdata(void)
{
return _CoreGl_mgr.has_ARB_invalidate_subdata;
}

//---- ARB_map_buffer_alignment ----

INLINE
bool
CoreGl_has_ARB_map_buffer_alignment(void)
{
return _CoreGl_mgr.has_ARB_map_buffer_alignment;
}

//---- ARB_map_buffer_range ----

INLINE
bool
CoreGl_has_ARB_map_buffer_range(void)
{
return _CoreGl_mgr.has_ARB_map_buffer_range;
}

//---- ARB_multi_bind ----

INLINE
bool
CoreGl_has_ARB_multi_bind(void)
{
return _CoreGl_mgr.has_ARB_multi_bind;
}

//---- ARB_multi_draw_indirect ----

INLINE
bool
CoreGl_has_ARB_multi_draw_indirect(void)
{
return _CoreGl_mgr.has_ARB_multi_draw_indirect;
}

//---- ARB_occlusion_query2 ----

INLINE
bool
CoreGl_has_ARB_occlusion_query2(void)
{
return _CoreGl_mgr.has_ARB_occlusion_query2;
}

//---- ARB_pipeline_statistics_query ----

INLINE
bool
CoreGl_has_ARB_pipeline_statistics_query(void)
{
return _CoreGl_mgr.has_ARB_pipeline_statistics_query;
}

//---- ARB_program_interface_query ----

INLINE
bool
CoreGl_has_ARB_program_interface_query(void)
{
return _CoreGl_mgr.has_ARB_program_interface_query;
}

//---- ARB_provoking_vertex ----

INLINE
bool
CoreGl_has_ARB_provoking_vertex(void)
{
return _CoreGl_mgr.has_ARB_provoking_vertex;
}

//---- ARB_query_buffer_object ----

INLINE
bool
CoreGl_has_ARB_query_buffer_object(void)
{
return _CoreGl_mgr.has_ARB_query_buffer_object;
}

//---- ARB_robust_buffer_access_behavior ----

INLINE
bool
CoreGl_has_ARB_robust_buffer_access_behavior(void)
{
return _CoreGl_mgr.has_ARB_robust_buffer_access_behavior;
}

//---- ARB_robustness ----

INLINE
bool
CoreGl_has_ARB_robustness(void)
{
return _CoreGl_mgr.has_ARB_robustness;
}

TRANSGL_API
PFNGLGETGRAPHICSRESETSTATUSARBPROC
CoreGl_GetGraphicsResetStatusARB;
#define glGetGraphicsResetStatusARB \
        CoreGl_GetGraphicsResetStatusARB

TRANSGL_API
PFNGLGETNTEXIMAGEARBPROC
CoreGl_GetnTexImageARB;
#define glGetnTexImageARB \
        CoreGl_GetnTexImageARB

TRANSGL_API
PFNGLREADNPIXELSARBPROC
CoreGl_ReadnPixelsARB;
#define glReadnPixelsARB \
        CoreGl_ReadnPixelsARB

TRANSGL_API
PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC
CoreGl_GetnCompressedTexImageARB;
#define glGetnCompressedTexImageARB \
        CoreGl_GetnCompressedTexImageARB

TRANSGL_API
PFNGLGETNUNIFORMFVARBPROC
CoreGl_GetnUniformfvARB;
#define glGetnUniformfvARB \
        CoreGl_GetnUniformfvARB

TRANSGL_API
PFNGLGETNUNIFORMIVARBPROC
CoreGl_GetnUniformivARB;
#define glGetnUniformivARB \
        CoreGl_GetnUniformivARB

TRANSGL_API
PFNGLGETNUNIFORMUIVARBPROC
CoreGl_GetnUniformuivARB;
#define glGetnUniformuivARB \
        CoreGl_GetnUniformuivARB

TRANSGL_API
PFNGLGETNUNIFORMDVARBPROC
CoreGl_GetnUniformdvARB;
#define glGetnUniformdvARB \
        CoreGl_GetnUniformdvARB

//---- ARB_robustness_isolation ----

INLINE
bool
CoreGl_has_ARB_robustness_isolation(void)
{
return _CoreGl_mgr.has_ARB_robustness_isolation;
}

//---- ARB_sample_shading ----

INLINE
bool
CoreGl_has_ARB_sample_shading(void)
{
return _CoreGl_mgr.has_ARB_sample_shading;
}

TRANSGL_API
PFNGLMINSAMPLESHADINGARBPROC
CoreGl_MinSampleShadingARB;
#define glMinSampleShadingARB \
        CoreGl_MinSampleShadingARB

//---- ARB_sampler_objects ----

INLINE
bool
CoreGl_has_ARB_sampler_objects(void)
{
return _CoreGl_mgr.has_ARB_sampler_objects;
}

//---- ARB_seamless_cube_map ----

INLINE
bool
CoreGl_has_ARB_seamless_cube_map(void)
{
return _CoreGl_mgr.has_ARB_seamless_cube_map;
}

//---- ARB_seamless_cubemap_per_texture ----

INLINE
bool
CoreGl_has_ARB_seamless_cubemap_per_texture(void)
{
return _CoreGl_mgr.has_ARB_seamless_cubemap_per_texture;
}

//---- ARB_separate_shader_objects ----

INLINE
bool
CoreGl_has_ARB_separate_shader_objects(void)
{
return _CoreGl_mgr.has_ARB_separate_shader_objects;
}

//---- ARB_shader_atomic_counters ----

INLINE
bool
CoreGl_has_ARB_shader_atomic_counters(void)
{
return _CoreGl_mgr.has_ARB_shader_atomic_counters;
}

//---- ARB_shader_bit_encoding ----

INLINE
bool
CoreGl_has_ARB_shader_bit_encoding(void)
{
return _CoreGl_mgr.has_ARB_shader_bit_encoding;
}

//---- ARB_shader_draw_parameters ----

INLINE
bool
CoreGl_has_ARB_shader_draw_parameters(void)
{
return _CoreGl_mgr.has_ARB_shader_draw_parameters;
}

//---- ARB_shader_group_vote ----

INLINE
bool
CoreGl_has_ARB_shader_group_vote(void)
{
return _CoreGl_mgr.has_ARB_shader_group_vote;
}

//---- ARB_shader_image_load_store ----

INLINE
bool
CoreGl_has_ARB_shader_image_load_store(void)
{
return _CoreGl_mgr.has_ARB_shader_image_load_store;
}

//---- ARB_shader_image_size ----

INLINE
bool
CoreGl_has_ARB_shader_image_size(void)
{
return _CoreGl_mgr.has_ARB_shader_image_size;
}

//---- ARB_shader_precision ----

INLINE
bool
CoreGl_has_ARB_shader_precision(void)
{
return _CoreGl_mgr.has_ARB_shader_precision;
}

//---- ARB_shader_stencil_export ----

INLINE
bool
CoreGl_has_ARB_shader_stencil_export(void)
{
return _CoreGl_mgr.has_ARB_shader_stencil_export;
}

//---- ARB_shader_storage_buffer_object ----

INLINE
bool
CoreGl_has_ARB_shader_storage_buffer_object(void)
{
return _CoreGl_mgr.has_ARB_shader_storage_buffer_object;
}

//---- ARB_shader_subroutine ----

INLINE
bool
CoreGl_has_ARB_shader_subroutine(void)
{
return _CoreGl_mgr.has_ARB_shader_subroutine;
}

//---- ARB_shader_texture_image_samples ----

INLINE
bool
CoreGl_has_ARB_shader_texture_image_samples(void)
{
return _CoreGl_mgr.has_ARB_shader_texture_image_samples;
}

//---- ARB_shading_language_420pack ----

INLINE
bool
CoreGl_has_ARB_shading_language_420pack(void)
{
return _CoreGl_mgr.has_ARB_shading_language_420pack;
}

//---- ARB_shading_language_include ----

INLINE
bool
CoreGl_has_ARB_shading_language_include(void)
{
return _CoreGl_mgr.has_ARB_shading_language_include;
}

TRANSGL_API
PFNGLNAMEDSTRINGARBPROC
CoreGl_NamedStringARB;
#define glNamedStringARB \
        CoreGl_NamedStringARB

TRANSGL_API
PFNGLDELETENAMEDSTRINGARBPROC
CoreGl_DeleteNamedStringARB;
#define glDeleteNamedStringARB \
        CoreGl_DeleteNamedStringARB

TRANSGL_API
PFNGLCOMPILESHADERINCLUDEARBPROC
CoreGl_CompileShaderIncludeARB;
#define glCompileShaderIncludeARB \
        CoreGl_CompileShaderIncludeARB

TRANSGL_API
PFNGLISNAMEDSTRINGARBPROC
CoreGl_IsNamedStringARB;
#define glIsNamedStringARB \
        CoreGl_IsNamedStringARB

TRANSGL_API
PFNGLGETNAMEDSTRINGARBPROC
CoreGl_GetNamedStringARB;
#define glGetNamedStringARB \
        CoreGl_GetNamedStringARB

TRANSGL_API
PFNGLGETNAMEDSTRINGIVARBPROC
CoreGl_GetNamedStringivARB;
#define glGetNamedStringivARB \
        CoreGl_GetNamedStringivARB

//---- ARB_shading_language_packing ----

INLINE
bool
CoreGl_has_ARB_shading_language_packing(void)
{
return _CoreGl_mgr.has_ARB_shading_language_packing;
}

//---- ARB_sparse_buffer ----

INLINE
bool
CoreGl_has_ARB_sparse_buffer(void)
{
return _CoreGl_mgr.has_ARB_sparse_buffer;
}

TRANSGL_API
PFNGLBUFFERPAGECOMMITMENTARBPROC
CoreGl_BufferPageCommitmentARB;
#define glBufferPageCommitmentARB \
        CoreGl_BufferPageCommitmentARB

TRANSGL_API
PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC
CoreGl_NamedBufferPageCommitmentEXT;
#define glNamedBufferPageCommitmentEXT \
        CoreGl_NamedBufferPageCommitmentEXT

TRANSGL_API
PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC
CoreGl_NamedBufferPageCommitmentARB;
#define glNamedBufferPageCommitmentARB \
        CoreGl_NamedBufferPageCommitmentARB

//---- ARB_sparse_texture ----

INLINE
bool
CoreGl_has_ARB_sparse_texture(void)
{
return _CoreGl_mgr.has_ARB_sparse_texture;
}

TRANSGL_API
PFNGLTEXPAGECOMMITMENTARBPROC
CoreGl_TexPageCommitmentARB;
#define glTexPageCommitmentARB \
        CoreGl_TexPageCommitmentARB

//---- ARB_stencil_texturing ----

INLINE
bool
CoreGl_has_ARB_stencil_texturing(void)
{
return _CoreGl_mgr.has_ARB_stencil_texturing;
}

//---- ARB_sync ----

INLINE
bool
CoreGl_has_ARB_sync(void)
{
return _CoreGl_mgr.has_ARB_sync;
}

//---- ARB_tessellation_shader ----

INLINE
bool
CoreGl_has_ARB_tessellation_shader(void)
{
return _CoreGl_mgr.has_ARB_tessellation_shader;
}

//---- ARB_texture_barrier ----

INLINE
bool
CoreGl_has_ARB_texture_barrier(void)
{
return _CoreGl_mgr.has_ARB_texture_barrier;
}

//---- ARB_texture_buffer_object_rgb32 ----

INLINE
bool
CoreGl_has_ARB_texture_buffer_object_rgb32(void)
{
return _CoreGl_mgr.has_ARB_texture_buffer_object_rgb32;
}

//---- ARB_texture_buffer_range ----

INLINE
bool
CoreGl_has_ARB_texture_buffer_range(void)
{
return _CoreGl_mgr.has_ARB_texture_buffer_range;
}

//---- ARB_texture_compression_bptc ----

INLINE
bool
CoreGl_has_ARB_texture_compression_bptc(void)
{
return _CoreGl_mgr.has_ARB_texture_compression_bptc;
}

//---- ARB_texture_compression_rgtc ----

INLINE
bool
CoreGl_has_ARB_texture_compression_rgtc(void)
{
return _CoreGl_mgr.has_ARB_texture_compression_rgtc;
}

//---- ARB_texture_cube_map_array ----

INLINE
bool
CoreGl_has_ARB_texture_cube_map_array(void)
{
return _CoreGl_mgr.has_ARB_texture_cube_map_array;
}

//---- ARB_texture_gather ----

INLINE
bool
CoreGl_has_ARB_texture_gather(void)
{
return _CoreGl_mgr.has_ARB_texture_gather;
}

//---- ARB_texture_mirror_clamp_to_edge ----

INLINE
bool
CoreGl_has_ARB_texture_mirror_clamp_to_edge(void)
{
return _CoreGl_mgr.has_ARB_texture_mirror_clamp_to_edge;
}

//---- ARB_texture_multisample ----

INLINE
bool
CoreGl_has_ARB_texture_multisample(void)
{
return _CoreGl_mgr.has_ARB_texture_multisample;
}

//---- ARB_texture_query_levels ----

INLINE
bool
CoreGl_has_ARB_texture_query_levels(void)
{
return _CoreGl_mgr.has_ARB_texture_query_levels;
}

//---- ARB_texture_query_lod ----

INLINE
bool
CoreGl_has_ARB_texture_query_lod(void)
{
return _CoreGl_mgr.has_ARB_texture_query_lod;
}

//---- ARB_texture_rg ----

INLINE
bool
CoreGl_has_ARB_texture_rg(void)
{
return _CoreGl_mgr.has_ARB_texture_rg;
}

//---- ARB_texture_rgb10_a2ui ----

INLINE
bool
CoreGl_has_ARB_texture_rgb10_a2ui(void)
{
return _CoreGl_mgr.has_ARB_texture_rgb10_a2ui;
}

//---- ARB_texture_stencil8 ----

INLINE
bool
CoreGl_has_ARB_texture_stencil8(void)
{
return _CoreGl_mgr.has_ARB_texture_stencil8;
}

//---- ARB_texture_storage ----

INLINE
bool
CoreGl_has_ARB_texture_storage(void)
{
return _CoreGl_mgr.has_ARB_texture_storage;
}

//---- ARB_texture_storage_multisample ----

INLINE
bool
CoreGl_has_ARB_texture_storage_multisample(void)
{
return _CoreGl_mgr.has_ARB_texture_storage_multisample;
}

//---- ARB_texture_swizzle ----

INLINE
bool
CoreGl_has_ARB_texture_swizzle(void)
{
return _CoreGl_mgr.has_ARB_texture_swizzle;
}

//---- ARB_texture_view ----

INLINE
bool
CoreGl_has_ARB_texture_view(void)
{
return _CoreGl_mgr.has_ARB_texture_view;
}

//---- ARB_timer_query ----

INLINE
bool
CoreGl_has_ARB_timer_query(void)
{
return _CoreGl_mgr.has_ARB_timer_query;
}

//---- ARB_transform_feedback2 ----

INLINE
bool
CoreGl_has_ARB_transform_feedback2(void)
{
return _CoreGl_mgr.has_ARB_transform_feedback2;
}

//---- ARB_transform_feedback3 ----

INLINE
bool
CoreGl_has_ARB_transform_feedback3(void)
{
return _CoreGl_mgr.has_ARB_transform_feedback3;
}

//---- ARB_transform_feedback_instanced ----

INLINE
bool
CoreGl_has_ARB_transform_feedback_instanced(void)
{
return _CoreGl_mgr.has_ARB_transform_feedback_instanced;
}

//---- ARB_transform_feedback_overflow_query ----

INLINE
bool
CoreGl_has_ARB_transform_feedback_overflow_query(void)
{
return _CoreGl_mgr.has_ARB_transform_feedback_overflow_query;
}

//---- ARB_uniform_buffer_object ----

INLINE
bool
CoreGl_has_ARB_uniform_buffer_object(void)
{
return _CoreGl_mgr.has_ARB_uniform_buffer_object;
}

//---- ARB_vertex_array_bgra ----

INLINE
bool
CoreGl_has_ARB_vertex_array_bgra(void)
{
return _CoreGl_mgr.has_ARB_vertex_array_bgra;
}

//---- ARB_vertex_array_object ----

INLINE
bool
CoreGl_has_ARB_vertex_array_object(void)
{
return _CoreGl_mgr.has_ARB_vertex_array_object;
}

//---- ARB_vertex_attrib_64bit ----

INLINE
bool
CoreGl_has_ARB_vertex_attrib_64bit(void)
{
return _CoreGl_mgr.has_ARB_vertex_attrib_64bit;
}

//---- ARB_vertex_attrib_binding ----

INLINE
bool
CoreGl_has_ARB_vertex_attrib_binding(void)
{
return _CoreGl_mgr.has_ARB_vertex_attrib_binding;
}

//---- ARB_vertex_type_10f_11f_11f_rev ----

INLINE
bool
CoreGl_has_ARB_vertex_type_10f_11f_11f_rev(void)
{
return _CoreGl_mgr.has_ARB_vertex_type_10f_11f_11f_rev;
}

//---- ARB_vertex_type_2_10_10_10_rev ----

INLINE
bool
CoreGl_has_ARB_vertex_type_2_10_10_10_rev(void)
{
return _CoreGl_mgr.has_ARB_vertex_type_2_10_10_10_rev;
}

//---- ARB_viewport_array ----

INLINE
bool
CoreGl_has_ARB_viewport_array(void)
{
return _CoreGl_mgr.has_ARB_viewport_array;
}

//---- KHR_context_flush_control ----

INLINE
bool
CoreGl_has_KHR_context_flush_control(void)
{
return _CoreGl_mgr.has_KHR_context_flush_control;
}

//---- KHR_debug ----

INLINE
bool
CoreGl_has_KHR_debug(void)
{
return _CoreGl_mgr.has_KHR_debug;
}

//---- KHR_no_error ----

INLINE
bool
CoreGl_has_KHR_no_error(void)
{
return _CoreGl_mgr.has_KHR_no_error;
}

//---- KHR_robust_buffer_access_behavior ----

INLINE
bool
CoreGl_has_KHR_robust_buffer_access_behavior(void)
{
return _CoreGl_mgr.has_KHR_robust_buffer_access_behavior;
}

//---- KHR_robustness ----

INLINE
bool
CoreGl_has_KHR_robustness(void)
{
return _CoreGl_mgr.has_KHR_robustness;
}

//---- KHR_texture_compression_astc_hdr ----

INLINE
bool
CoreGl_has_KHR_texture_compression_astc_hdr(void)
{
return _CoreGl_mgr.has_KHR_texture_compression_astc_hdr;
}

//---- KHR_texture_compression_astc_ldr ----

INLINE
bool
CoreGl_has_KHR_texture_compression_astc_ldr(void)
{
return _CoreGl_mgr.has_KHR_texture_compression_astc_ldr;
}

//---- KHR_texture_compression_astc_sliced_3d ----

INLINE
bool
CoreGl_has_KHR_texture_compression_astc_sliced_3d(void)
{
return _CoreGl_mgr.has_KHR_texture_compression_astc_sliced_3d;
}

#endif // TRANSGL_COREGL_H

//----------------------------------------------------------------------------
