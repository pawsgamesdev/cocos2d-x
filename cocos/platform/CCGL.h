/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2013-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __PLATFORM_CCGL_H__
#define __PLATFORM_CCGL_H__
/// @cond DO_NOT_SHOW

#include "platform/CCPlatformConfig.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/CCGL-android.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "platform/win32/CCGL-win32.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#include "platform/linux/CCGL-linux.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC
// cocos2d-x 4.0 uses Metal on Apple platforms — the OpenGL ES / OpenGL
// frameworks are not needed.  These typedef aliases are still referenced by
// legacy vertex-data code (e.g. GLubyte for opacity, GLfloat for trig,
// GLushort for index buffers); they map 1-to-1 to standard C types.
#include <stdint.h>
#include <stddef.h>
typedef void             GLvoid;
typedef unsigned char    GLboolean;
typedef unsigned char    GLubyte;
typedef signed char      GLbyte;
typedef unsigned short   GLushort;
typedef short            GLshort;
typedef unsigned int     GLuint;
typedef int              GLint;
typedef unsigned int     GLenum;
typedef unsigned int     GLbitfield;
typedef int              GLsizei;
typedef float            GLfloat;
typedef float            GLclampf;
typedef double           GLdouble;
typedef double           GLclampd;
typedef ptrdiff_t        GLintptr;
typedef ptrdiff_t        GLsizeiptr;
#endif

/// @endcond
#endif /* __PLATFORM_CCPLATFORMDEFINE_H__*/
