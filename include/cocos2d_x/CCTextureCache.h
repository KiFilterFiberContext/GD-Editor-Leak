#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCDictionary.h"
#include "CCTexture2D.h"

NS_CC_BEGIN

class CCLock;
class CCImage;

class CC_DLL CCTextureCache : public CCObject
{
public:
	CCDictionary *_pTextures;

public:
	CCTextureCache();
	virtual ~CCTextureCache();

	static void purgeSharedTextureCache();
	static void reloadAllTextures();
	static CCTextureCache *sharedTextureCache();

	CCTexture2D *addETCImage(const char *);
	CCTexture2D *addImage(const char *, bool);
	void addImageAsync(const char *, CCObject *, SEL_MenuHandler);
	CCTexture2D *addPVRImage(const char *);
	CCTexture2D *addUIImage(CCImage *, const char *);
	const char *description();
	void dumpCachedTextureInfo();
	bool reloadTexture(const char *);
	void removeAllTextures();
	void removeTexture(CCTexture2D *);
	void removeTextureForKey(const char *);
	void removeUnusedTextures();
	CCDictionary *snapshotTextures();
	CCTexture2D *textureForKey(const char *);

private:
	void addImageAsyncCallBack(float);
};

NS_CC_END