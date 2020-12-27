#pragma once

#include "GDAPI_Macros.h"

#ifdef GDAPI_WINDOWS
#include "external/glext/glew.h"
#else
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#endif

#define CC_GL_DEPTH24_STENCIL8 GL_DEPTH24_STENCIL8