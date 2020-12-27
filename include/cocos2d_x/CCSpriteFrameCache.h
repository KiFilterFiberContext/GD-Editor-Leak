#pragma once

#include "GDAPI_Macros.h"

#include <string>
#include <set>
#include "CCObject.h"
#include "CCSpriteFrame.h"

NS_CC_BEGIN

class CCDictionary;

class CC_DLL CCSpriteFrameCache : public CCObject
{
public:
	CCDictionary *_pSpriteFrames;
	CCDictionary *_pSpriteFramesAliases;
	std::set<std::string> *_pLoadedFileNames;

protected:
	CCSpriteFrameCache();

public:
	virtual ~CCSpriteFrameCache();

	static void purgeSharedSpriteFrameCache();
	static CCSpriteFrameCache *sharedSpriteFrameCache();

	void addSpriteFrame(CCSpriteFrame *, const char *);
	void addSpriteFramesWithFile(const char *, const char *);
	void addSpriteFramesWithFile(const char *);
	void addSpriteFramesWithFile(const char *, CCTexture2D *);
	bool init();
	void removeSpriteFrameByName(const char *);
	void removeSpriteFrames();
	void removeSpriteFramesFromFile(const char *);
	void removeSpriteFramesFromTexture(CCTexture2D *);
	void removeUnusedSpriteFrames();
	CCSpriteFrame *spriteFrameByName(const char *);

private:
	void addSpriteFramesWithDictionary(CCDictionary *, CCTexture2D *);
	void removeSpriteFramesFromDictionary(CCDictionary *);
};

NS_CC_END