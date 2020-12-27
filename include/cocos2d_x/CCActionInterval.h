#pragma once

#include "GDAPI_Macros.h"

#include "CCAction.h"
#include "CCSpriteFrame.h"
#include <vector>
#include "CCAnimation.h"
#include "CCGL.h"
#include "support/ccTypes.h"

NS_CC_BEGIN

class CC_DLL CCActionInterval : public CCFiniteTimeAction
{
public:
	float _elapsed;
	bool _bFirstTick;

public:
	CCActionInterval();
	virtual ~CCActionInterval();

	static CCActionInterval *create(float);

	float getAmplitudeRate();
	float getElapsed();
	bool getM_bFirstTick() const;
	bool initWithDuration(float);
	void setAmplitudeRate(float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual bool isDone();
	virtual void startWithTarget(CCNode *);
	virtual void step(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCSequence : public CCActionInterval
{
public:
	CCFiniteTimeAction *_pActions[2];
	float _split;
	int _last;

public:
	CCSequence();
	virtual ~CCSequence();

	static CCSequence *create(CCArray *);
	static CCSequence *create(CCFiniteTimeAction *, ...);
	static CCSequence *createWithTwoActions(CCFiniteTimeAction *, CCFiniteTimeAction *);
	static CCSequence *createWithVariableList(CCFiniteTimeAction *, va_list args);

	bool initWithTwoActions(CCFiniteTimeAction *, CCFiniteTimeAction *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual void stop();
	virtual CCActionInterval *reverse();
};

class CC_DLL CCRepeat : public CCActionInterval
{
public:
	unsigned int _uTimes;
	unsigned int _uTotal;
	float _fNextDt;
	bool _bActionInstant;
	CCFiniteTimeAction *_pInnerAction;

public:
	CCRepeat();
	virtual ~CCRepeat();

	static CCRepeat *create(CCFiniteTimeAction *, unsigned int);

	CCFiniteTimeAction *getInnerAction();
	bool initWithAction(CCFiniteTimeAction *, unsigned int);
	void setInnerAction(CCFiniteTimeAction *);
	
	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual bool isDone();
	virtual void startWithTarget(CCNode *);
	virtual void stop();
	virtual CCActionInterval *reverse();
};

class CC_DLL CCRepeatForever : public CCActionInterval
{
public:
	CCActionInterval *_pInnerAction;

public:
	CCRepeatForever();
	virtual ~CCRepeatForever();

	static CCRepeatForever *create(CCActionInterval *);

	CCActionInterval *getInnerAction();
	bool initWithAction(CCActionInterval *);
	void setInnerAction(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual bool isDone();
	virtual void startWithTarget(CCNode *);
	virtual void step(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCSpawn : public CCActionInterval
{
public:
	CCFiniteTimeAction *_pOne;
	CCFiniteTimeAction *_pTwo;

public:
	CCSpawn();
	virtual ~CCSpawn();

	static CCSpawn *create(CCArray *);
	static CCSpawn *create(CCFiniteTimeAction *, ...);
	static CCSpawn *createWithTwoActions(CCFiniteTimeAction *, CCFiniteTimeAction *);
	static CCSpawn *createWithVariableList(CCFiniteTimeAction *, va_list args);

	bool initWithTwoActions(CCFiniteTimeAction *, CCFiniteTimeAction *);
	
	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual void stop();
	virtual CCActionInterval *reverse();
};

class CC_DLL CCRotateTo : public CCActionInterval
{
public:
	float _fDstAngleX;
	float _fStartAngleX;
	float _fDiffAngleX;
	float _fDstAngleY;
	float _fStartAngleY;
	float _fDiffAngleY;

public:
	CCRotateTo();
	virtual ~CCRotateTo();

	bool initWithDuration(float, float);

	static CCRotateTo *create(float, float);
	static CCRotateTo *create(float, float, float);
	
	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);

	virtual bool initWithDuration(float, float, float);
};

class CC_DLL CCRotateBy : public CCActionInterval
{
public:
	float _fAngleX;
	float _fStartAngleX;
	float _fAngleY;
	float _fStartAngleY;

public:
	CCRotateBy();
	virtual ~CCRotateBy();

	static CCRotateBy *create(float, float);
	static CCRotateBy *create(float, float, float);

	bool initWithDuration(float, float);
	bool initWithDuration(float, float, float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCMoveBy : public CCActionInterval
{
public:
	CCPoint _positionDelta;
	CCPoint _startPosition;
	CCPoint _previousPosition;

public:
	CCMoveBy();
	virtual ~CCMoveBy();

	static CCMoveBy *create(float, const CCPoint &);

	bool initWithDuration(float, const CCPoint &);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCMoveTo : public CCMoveBy
{
public:
	CCPoint _endPosition;

public:
	CCMoveTo();
	virtual ~CCMoveTo();

	static CCMoveTo *create(float, const CCPoint &);

	bool initWithDuration(float, const CCPoint &);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void startWithTarget(CCNode *);
};

class CC_DLL CCSkewTo : public CCActionInterval
{
public:
	float _fSkewX;
	float _fSkewY;
	float _fStartSkewX;
	float _fStartSkewY;
	float _fEndSkewX;
	float _fEndSkewY;
	float _fDeltaX;
	float _fDeltaY;

public:
	CCSkewTo();
	virtual ~CCSkewTo();

	static CCSkewTo *create(float t, float sx, float sy);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual bool initWithDuration(float t, float sx, float sy);
};

class CC_DLL CCSkewBy : public CCSkewTo
{
public:
	CCSkewBy();
	virtual ~CCSkewBy();

	static CCSkewBy *create(float t, float deltaSkewX, float deltaSkewY);

	virtual void startWithTarget(CCNode *);
	virtual CCActionInterval *reverse();
	virtual bool initWithDuration(float t, float sx, float sy);
};

class CC_DLL CCJumpBy : public CCActionInterval
{
public:
	CCPoint _startPosition;
	CCPoint _delta;
	float _height;
	unsigned int _nJumps;
	CCPoint _previousPos;

public:
	CCJumpBy();
	virtual ~CCJumpBy();

	static CCJumpBy *create(float, const CCPoint &, float, unsigned int);

	bool initWithDuration(float, const CCPoint &, float, unsigned int);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCJumpTo : public CCJumpBy
{
public:
	CCJumpTo();
	virtual ~CCJumpTo();

	static CCJumpTo *create(float, const CCPoint &, float, int);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void startWithTarget(CCNode *);
};

typedef struct _ccBezierConfig
{
	CCPoint endPosition;
	CCPoint controlPoint_1;
	CCPoint controlPoint_2;
} ccBezierConfig;

class CC_DLL CCBezierBy : public CCActionInterval
{
public:
	ccBezierConfig _sConfig;
	CCPoint _startPosition;
	CCPoint _previousPosition;

public:
	CCBezierBy();
	virtual ~CCBezierBy();

	static CCBezierBy *create(float, const _ccBezierConfig &);

	bool initWithDuration(float, const _ccBezierConfig &);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCBezierTo : public CCBezierBy
{
public:
	ccBezierConfig _sToConfig;

public:
	CCBezierTo();
	virtual ~CCBezierTo();

	static CCBezierTo *create(float, const _ccBezierConfig &);

	bool initWithDuration(float, const _ccBezierConfig &);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void startWithTarget(CCNode *);
};

class CC_DLL CCScaleTo : public CCActionInterval
{
public:
	float _fScaleX;
	float _fScaleY;
	float _fStartScaleX;
	float _fStartScaleY;
	float _fEndScaleX;
	float _fEndScaleY;
	float _fDeltaX;
	float _fDeltaY;

public:
	CCScaleTo();
	virtual ~CCScaleTo();

	static CCScaleTo *create(float duration, float s);
	static CCScaleTo *create(float duration, float sx, float sy);

	bool initWithDuration(float, float);
	bool initWithDuration(float, float, float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
};

class CC_DLL CCScaleBy : public CCScaleTo
{
public:
	CCScaleBy();
	virtual ~CCScaleBy();

	static CCScaleBy *create(float, float);
	static CCScaleBy *create(float, float, float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void startWithTarget(CCNode *);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCBlink : public CCActionInterval
{
public:
	unsigned int _nTimes;
	bool _bOriginalState;

public:
	CCBlink();
	virtual ~CCBlink();

	static CCBlink *create(float, unsigned int);

	bool initWithDuration(float, unsigned int);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual void stop();
	virtual CCActionInterval *reverse();
};

class CC_DLL CCFadeIn : public CCActionInterval
{
public:
	CCFadeIn();
	virtual ~CCFadeIn();

	static CCFadeIn *create(float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCFadeOut : public CCActionInterval
{
public:
	CCFadeOut();
	virtual ~CCFadeOut();

	static CCFadeOut *create(float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCFadeTo : public CCActionInterval
{
public:
	GLubyte _toOpacity, _fromOpacity;

public:
	CCFadeTo();
	virtual ~CCFadeTo();

	static CCFadeTo *create(float, unsigned char);

	bool initWithDuration(float, unsigned char);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
};

class CC_DLL CCTintTo : public CCActionInterval
{
public:
	ccColor3B _to;
	ccColor3B _from;

public:
	CCTintTo();
	virtual ~CCTintTo();

	static CCTintTo *create(float, unsigned char, unsigned char, unsigned char);

	bool initWithDuration(float, unsigned char, unsigned char, unsigned char);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
};

class CC_DLL CCTintBy : public CCActionInterval
{
public:
	GLshort m_deltaR;
	GLshort m_deltaG;
	GLshort m_deltaB;
	GLshort m_fromR;
	GLshort m_fromG;
	GLshort m_fromB;

public:
	CCTintBy();
	virtual ~CCTintBy();

	static CCTintBy *create(float, short, short, short);

	bool initWithDuration(float, short, short, short);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCDelayTime : public CCActionInterval
{
public:
	CCDelayTime();
	virtual ~CCDelayTime();

	static CCDelayTime *create(float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCReverseTime : public CCActionInterval
{
public:
	CCFiniteTimeAction *_pOther;

public:
	CCReverseTime();
	virtual ~CCReverseTime();

	static CCReverseTime *create(CCFiniteTimeAction *);

	bool initWithAction(CCFiniteTimeAction *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual void stop();
	virtual CCActionInterval *reverse();
};

class CCTexture2D;

class CC_DLL CCAnimate : public CCActionInterval
{
public:
	CCAnimation *_pAnimation;
	std::vector<float> *_pSplitTimes;
	int _nNextFrame;
	CCSpriteFrame *_pOrigFrame;
	unsigned int _uExecutedLoops;
	bool _bRecenterChildren;

public:
	CCAnimate();
	virtual ~CCAnimate();

	static CCAnimate *create(CCAnimation *);

	CCAnimation *getAnimation() const;
	bool getRecenterChildren() const;
	bool getRecenterFrames() const;
	bool initWithAnimation(CCAnimation *);
	void setAnimation(CCAnimation *);
	void setRecenterChildren(bool);
	void setRecenterFrames(bool);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual void stop();
	virtual CCActionInterval *reverse();
};

class CC_DLL CCTargetedAction : public CCActionInterval
{
public:
	CCNode *_pForcedTarget;
	CCFiniteTimeAction *_pAction;

public:
	CCTargetedAction();
	virtual ~CCTargetedAction();

	static CCTargetedAction *create(CCNode *, CCFiniteTimeAction *);

	CCNode *getForcedTarget() const;
	bool initWithTarget(CCNode *, CCFiniteTimeAction *);
	void setForcedTarget(CCNode *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual void stop();
};

NS_CC_END