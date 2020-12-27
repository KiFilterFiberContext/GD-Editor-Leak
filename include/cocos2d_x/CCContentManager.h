#pragma once

#include "GDAPI_Macros.h"

#include "CCDictionary.h"

class CC_DLL CCContentManager : public cocos2d::CCObject
{
public:
	cocos2d::CCDictionary *_dictCache;

public:
	CCContentManager();
	virtual ~CCContentManager();

	static CCContentManager *sharedManager();

	void addDict(const char *path, bool);
	void addDictDS(const char *path);
	void clearCache();
	bool init();
};