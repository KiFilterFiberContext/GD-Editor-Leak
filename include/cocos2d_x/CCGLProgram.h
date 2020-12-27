#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCGL.h"

NS_CC_BEGIN

enum
{
	kCCVertexAttrib_Position,
	kCCVertexAttrib_Color,
	kCCVertexAttrib_TexCoords,

	kCCVertexAttrib_MAX,
};

enum
{
	kCCUniformPMatrix,
	kCCUniformMVMatrix,
	kCCUniformMVPMatrix,
	kCCUniformTime,
	kCCUniformSinTime,
	kCCUniformCosTime,
	kCCUniformRandom01,
	kCCUniformSampler,

	kCCUnifor_MAX,
};

#define kCCShader_PositionTextureColor "ShaderPositionTextureColor"
#define kCCShader_PositionTextureColorAlphaTest "ShaderPositionTextureColorAlphaTest"
#define kCCShader_PositionColor "ShaderPositionColor"
#define kCCShader_PositionTexture "ShaderPositionTexture"
#define kCCShader_PositionTexture_uColor "ShaderPositionTexture_uColor"
#define kCCShader_PositionTextureA8Color "ShaderPositionTextureA8Color"
#define kCCShader_Position_uColor "ShaderPosition_uColor"
#define kCCShader_PositionLengthTexureColor "ShaderPositionLengthTextureColor"
#define kCCShader_ControlSwitch "Shader_ControlSwitch"

#define kCCUniformPMatrix_s "CC_PMatrix"
#define kCCUniformMVMatrix_s "CC_MVMatrix"
#define kCCUniformMVPMatrix_s "CC_MVPMatrix"
#define kCCUniformTime_s "CC_Time"
#define kCCUniformSinTime_s "CC_SinTime"
#define kCCUniformCosTime_s "CC_CosTime"
#define kCCUniformRandom01_s "CC_Random01"
#define kCCUniformSampler_s "CC_Texture0"
#define kCCUniformAlphaTestValue "CC_alpha_value"

#define kCCAttributeNameColor "a_color"
#define kCCAttributeNamePosition "a_position"
#define kCCAttributeNameTexCoord "a_texCoord"

typedef void(*GLInfoFunction)(GLuint program, GLenum pname, GLint *params);
typedef void(*GLLogFunction) (GLuint program, GLsizei bufsize, GLsizei *length, GLchar *infolog);

class CC_DLL CCGLProgram : public CCObject
{
public:
	GLuint _uProgram;
	GLuint _uVertShader;
	GLuint _uFragShader;
	GLint _uUniforms[kCCUnifor_MAX];
	struct _hashUniformEntry *_pHashForUniforms;
	bool _bUsesTime;
	bool _hasShaderCompiler;

public:
	CCGLProgram();
	virtual ~CCGLProgram();

	void addAttribute(const char *, unsigned int);
	const char *fragmentShaderLog();
	unsigned int const getProgram();
	int getUniformLocationForName(const char *);
	bool initWithVertexShaderByteArray(const char *, const char *);
	bool initWithVertexShaderFilename(const char *, const char *);
	bool link();
	const char *logForOpenGLObject(unsigned int, GLInfoFunction, GLLogFunction);
	const char *programLog();
	void reset();
	void setUniformLocationWith1f(int, float);
	void setUniformLocationWith1i(int, int);
	void setUniformLocationWith2f(int, float, float);
	void setUniformLocationWith2fv(int, float *, unsigned int);
	void setUniformLocationWith2i(int, int, int);
	void setUniformLocationWith2iv(int, int *, unsigned int);
	void setUniformLocationWith3f(int, float, float, float);
	void setUniformLocationWith3fv(int, float *, unsigned int);
	void setUniformLocationWith3i(int, int, int, int);
	void setUniformLocationWith3iv(int, int *, unsigned int);
	void setUniformLocationWith4f(int, float, float, float, float);
	void setUniformLocationWith4fv(int, float *, unsigned int);
	void setUniformLocationWith4i(int, int, int, int, int);
	void setUniformLocationWith4iv(int, int *, unsigned int);
	void setUniformLocationWithMatrix3fv(int, float *, unsigned int);
	void setUniformLocationWithMatrix4fv(int, float *, unsigned int);
	void setUniformsForBuiltins();
	void updateUniforms();
	void use();
	const char *vertexShaderLog();

private:
	bool compileShader(unsigned int *, unsigned int, const char *);
	const char *description();
	bool updateUniformLocation(int, void *, unsigned int);
};

NS_CC_END