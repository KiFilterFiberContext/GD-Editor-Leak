#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"

NS_CC_BEGIN

class CCDictionary;
class CCAnimation;

class CC_DLL CCAnimationCache : public CCObject
{
public:
	CCDictionary *_pAnimations;

public:
	CCAnimationCache();
	virtual ~CCAnimationCache();

	static CCAnimationCache *sharedAnimationCache();
	static void purgeSharedAnimationCache();

	void addAnimation(CCAnimation *animation, const char  *name);
	void addAnimationsWithDictionary(CCDictionary *dictionary, const char *plist = 0);
	void addAnimationsWithFile(const char *plist);
	CCAnimation *animationByName(const char *name);
	bool init();
	void removeAnimationByName(const char *name);

private:
	void parseVersion1(CCDictionary *animations);
	void parseVersion2(CCDictionary *animations);
};

NS_CC_END