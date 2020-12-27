#pragma once

#include "GDAPI_Macros.h"

#include "CCGL.h"

NS_CC_BEGIN

class CCGLProgram;

enum
{
	kCCVertexAttribFlag_None = 0,

	kCCVertexAttribFlag_Position = 1 << 0,
	kCCVertexAttribFlag_Color = 1 << 1,
	kCCVertexAttribFlag_TexCoords = 1 << 2,

	kCCVertexAttribFlag_PosColorTex = (kCCVertexAttribFlag_Position | kCCVertexAttribFlag_Color | kCCVertexAttribFlag_TexCoords),
};

typedef enum
{
	CC_GL_SCISSOR_TEST = 1 << 0,
	CC_GL_STENCIL_TEST = 1 << 1,
	CC_GL_DEPTH_TEST = 1 << 2,
	CC_GL_BLEND = 1 << 3,
	CC_GL_DITHER = 1 << 4,

	CC_GL_ALL = ( CC_GL_SCISSOR_TEST | CC_GL_STENCIL_TEST | CC_GL_DEPTH_TEST | CC_GL_BLEND | CC_GL_DITHER ),
} ccGLServerState;

void CC_DLL ccGLInvalidateStateCache();
void CC_DLL ccGLUseProgram(GLuint program);
void CC_DLL ccGLDeleteProgram(GLuint program);
void CC_DLL ccGLBlendFunc(GLenum sfactor, GLenum dfactor);
void CC_DLL ccSetProjectionMatrixDirty();
void CC_DLL ccGLEnableVertexAttribs(unsigned int flags);
void CC_DLL ccGLActiveTexture(GLenum textureEnum);
GLenum CC_DLL ccGLGetActiveTexture();
void CC_DLL ccGLBindTexture2D(GLuint textureId);
void CC_DLL ccGLBindTexture2DN(GLuint nId, GLuint textureId);
void CC_DLL ccGLDeleteTexture(GLuint textureId);
void CC_DLL ccGLDeleteTextureN(GLuint nId, GLuint textureId);
void CC_DLL ccGLEnable(ccGLServerState flags);

NS_CC_END