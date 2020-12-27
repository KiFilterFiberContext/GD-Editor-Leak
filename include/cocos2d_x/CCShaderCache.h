#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCDictionary.h"
#include "CCGLProgram.h"

NS_CC_BEGIN

class CC_DLL CCShaderCache : public CCObject
{
public:
	CCDictionary *_pPrograms;

public:
	CCShaderCache();
	virtual ~CCShaderCache();

	static CCShaderCache *sharedShaderCache();
	static void purgeSharedShaderCache();

	void addProgram(CCGLProgram *program, const char *key);
	void loadDefaultShaders();
	CCGLProgram *programForKey(const char *key);
	void reloadDefaultShaders();

private:
	bool init();
	void loadDefaultShader(CCGLProgram *program, int type);
};

NS_CC_END