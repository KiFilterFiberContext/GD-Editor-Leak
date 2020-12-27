#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCGeometry.h"

NS_CC_BEGIN

enum
{
	kCCActionTagInvalid = -1,
};

class CC_DLL CCAction : public CCObject
{
public:
	CCNode *_pOriginalTarget, *_pTarget;
	int _nTag;
	float _fSpeedMod;

public:
	CCAction();
	virtual ~CCAction();

	static CCAction *create();
	
	const char *description();
	CCNode *getOriginalTarget();
	float getSpeedMod() const;
	int getTag();
	CCNode *getTarget();
	void setOriginalTarget(CCNode *pNode);
	void setSpeedMod(float speed);
	void setTarget(CCNode *pNode);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void update(float dt);
	virtual void setTag(int tag);

	virtual bool isDone();
	virtual void startWithTarget(CCNode *pNode);
	virtual void stop();
	virtual void step(float dt);
};

class CC_DLL CCFiniteTimeAction : public CCAction
{
public:
	float _fDuration;

public:
	CCFiniteTimeAction();
	virtual ~CCFiniteTimeAction();

	float getDuration();
	void setDuration(float duration);

	virtual CCFiniteTimeAction *reverse();
};

class CCActionInterval;
class CCRepeatForever;

class CC_DLL CCSpeed : public CCAction
{
public:
	float _fSpeed;
	CCActionInterval *_pInnerAction;

public:
	CCSpeed();
	virtual ~CCSpeed();

	static CCSpeed *create(CCActionInterval *pAction, float speed);

	CCActionInterval *getInnerAction();
	float getSpeed();
	bool initWithAction(CCActionInterval *pAction, float speed);
	void setInnerAction(CCActionInterval *pAction);
	void setSpeed(float speed);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual bool isDone();
	virtual void startWithTarget(CCNode *pNode);
	virtual void stop();
	virtual void step(float dt);

	virtual CCActionInterval *reverse();
};

class CC_DLL CCFollow : public CCAction
{
public:
	CCNode *_pFollowedNode;
	bool _bBoundarySet, _bBoundaryFullyCovered;
	CCPoint _obHalfScreenSize, _obFullScreenSize;
	float _fLeftBoundary, _fRightBoundary, _fTopBoundary, _fBottomBoundary;

public:
	CCFollow();
	virtual ~CCFollow();

	static CCFollow *create(CCNode *pNode, const CCRect &rect);

	bool initWithTarget(CCNode *pNode, const CCRect &rect);
	bool isBoundarySet();
	void setBoudarySet(bool);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual bool isDone();
	virtual void stop();
	virtual void step(float dt);
};

NS_CC_END