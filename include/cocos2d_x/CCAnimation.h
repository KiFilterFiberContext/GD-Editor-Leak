#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCDictionary.h"

NS_CC_BEGIN

class CCRect;
class CCTexture2D;
class CCSpriteFrame;

class CC_DLL CCAnimationFrame : public CCObject
{
public:
	CCSpriteFrame *_pSpriteFrame;
	float _fDelayUnits;
	CCDictionary *_pUserInfo;

public:
	CCAnimationFrame();
	virtual ~CCAnimationFrame();

	float getDelayUnits() const;
	CCSpriteFrame *getSpriteFrame() const;
	CCDictionary *getUserInfo() const;
	bool initWithSpriteFrame(CCSpriteFrame *, float, CCDictionary *);
	void setDelayUnits(float);
	void setSpriteFrame(CCSpriteFrame *);
	void setUserInfo(CCDictionary *);

	virtual CCObject *copyWithZone(CCZone *);
};

class CC_DLL CCAnimation : public CCObject
{
public:
	float _fTotalDelayUnits, _fDelayPerUnit, _fDuration;
	CCArray *_pFrames;
	bool _bRestoreOriginalFrame;
	unsigned int _uLoops;

public:
	CCAnimation();
	virtual ~CCAnimation();

	static CCAnimation *create(CCArray *, float);
	static CCAnimation *create(CCArray *, float, unsigned int);
	static CCAnimation *create();
	static CCAnimation *createWithSpriteFrames(CCArray *, float);

	void addSpriteFrame(CCSpriteFrame *);
	void addSpriteFrameWithFileName(const char *);
	void addSpriteFrameWithTexture(CCTexture2D *, const CCRect &);
	float getDelayPerUnit() const;
	CCArray *getFrames() const;
	unsigned int getLoops() const;
	bool getRestoreOriginalFrame() const;
	float getTotalDelayUnits() const;
	bool init();
	bool initWithAnimationFrames(CCArray *, float, unsigned int);
	bool initWithSpriteFrames(CCArray *, float);
	void setDelayPerUnit(float);
	void setFrames(CCArray *);
	void setLoops(unsigned int);
	void setRestoreOriginalFrame(bool);

	virtual CCObject *copyWithZone(CCZone *);

	virtual float getDuration();
};

NS_CC_END