#pragma once

#include "GDAPI_Macros.h"

#include "CCActionInterval.h"

NS_CC_BEGIN

class CC_DLL CCActionEase : public CCActionInterval
{
public:
	CCActionInterval *_pInner;

public:
	CCActionEase();
	virtual ~CCActionEase();

	static CCActionEase *create(CCActionInterval *);

	bool initWithAction(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual void startWithTarget(CCNode *);
	virtual void stop();
	virtual CCActionInterval *reverse();

	virtual CCActionInterval *getInnerAction();
};

class CC_DLL CCEaseRateAction : public CCActionEase
{
public:
	float _fRate;

public:
	CCEaseRateAction();
	virtual ~CCEaseRateAction();

	static CCEaseRateAction *create(CCActionInterval *, float);

	float getRate();
	bool initWithAction(CCActionInterval *, float);
	void setRate(float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseIn : public CCEaseRateAction
{
public:
	CCEaseIn();
	virtual ~CCEaseIn();

	static CCEaseIn *create(CCActionInterval *, float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseOut : public CCEaseRateAction
{
public:
	CCEaseOut();
	virtual ~CCEaseOut();

	static CCEaseOut *create(CCActionInterval *, float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseInOut : public CCEaseRateAction
{
public:
	CCEaseInOut();
	virtual ~CCEaseInOut();

	static CCEaseInOut *create(CCActionInterval *, float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseExponentialIn : public CCActionEase
{
public:
	CCEaseExponentialIn();
	virtual ~CCEaseExponentialIn();

	static CCEaseExponentialIn *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseExponentialOut : public CCActionEase
{
public:
	CCEaseExponentialOut();
	virtual ~CCEaseExponentialOut();

	static CCEaseExponentialOut *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseExponentialInOut : public CCActionEase
{
public:
	CCEaseExponentialInOut();
	virtual ~CCEaseExponentialInOut();

	static CCEaseExponentialInOut *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseSineIn : public CCActionEase
{
public:
	CCEaseSineIn();
	virtual ~CCEaseSineIn();

	static CCEaseSineIn *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseSineOut : public CCActionEase
{
public:
	CCEaseSineOut();
	virtual ~CCEaseSineOut();

	static CCEaseSineOut *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseSineInOut : public CCActionEase
{
public:
	CCEaseSineInOut();
	virtual ~CCEaseSineInOut();

	static CCEaseSineInOut *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseElastic : public CCActionEase
{
public:
	float _fPeriod;

public:
	CCEaseElastic();
	virtual ~CCEaseElastic();

	static CCEaseElastic *create(CCActionInterval *);
	static CCEaseElastic *create(CCActionInterval *, float);

	float getPeriod();
	bool initWithAction(CCActionInterval *, float);
	void setPeriod(float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseElasticIn : public CCEaseElastic
{
public:
	CCEaseElasticIn();
	virtual ~CCEaseElasticIn();

	static CCEaseElasticIn *create(CCActionInterval *);
	static CCEaseElasticIn *create(CCActionInterval *, float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseElasticOut : public CCEaseElastic
{
public:
	CCEaseElasticOut();
	virtual ~CCEaseElasticOut();

	static CCEaseElasticOut *create(CCActionInterval *);
	static CCEaseElasticOut *create(CCActionInterval *, float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseElasticInOut : public CCEaseElastic
{
public:
	CCEaseElasticInOut();
	virtual ~CCEaseElasticInOut();

	static CCEaseElasticInOut *create(CCActionInterval *);
	static CCEaseElasticInOut *create(CCActionInterval *, float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseBounce : public CCActionEase
{
public:
	CCEaseBounce();
	virtual ~CCEaseBounce();

	static CCEaseBounce *create(CCActionInterval *);

	float bounceTime(float);

	virtual CCObject *copyWithZone(CCZone *);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseBounceIn : public CCEaseBounce
{
public:
	CCEaseBounceIn();
	virtual ~CCEaseBounceIn();

	static CCEaseBounceIn *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseBounceOut : public CCEaseBounce
{
public:
	CCEaseBounceOut();
	virtual ~CCEaseBounceOut();

	static CCEaseBounceOut *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseBounceInOut : public CCEaseBounce
{
public:
	CCEaseBounceInOut();
	virtual ~CCEaseBounceInOut();

	static CCEaseBounceInOut *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseBackIn : public CCActionEase
{
public:
	CCEaseBackIn();
	virtual ~CCEaseBackIn();

	static CCEaseBackIn *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseBackOut : public CCActionEase
{
public:
	CCEaseBackOut();
	virtual ~CCEaseBackOut();

	static CCEaseBackOut *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

class CC_DLL CCEaseBackInOut : public CCActionEase
{
public:
	CCEaseBackInOut();
	virtual ~CCEaseBackInOut();

	static CCEaseBackInOut *create(CCActionInterval *);

	virtual CCObject *copyWithZone(CCZone *);
	virtual void update(float);
	virtual CCActionInterval *reverse();
};

NS_CC_END