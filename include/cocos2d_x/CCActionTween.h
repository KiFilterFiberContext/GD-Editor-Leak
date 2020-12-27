#pragma once

#include "GDAPI_Macros.h"

#include "CCActionInterval.h"

NS_CC_BEGIN

class CC_DLL CCActionTweenDelegate
{
public:
	virtual ~CCActionTweenDelegate();

	virtual void updateTweenAction(float value, const char *key) = 0;
};

class CC_DLL CCActionTween : public CCActionInterval
{
public:
	std::string _strKey;
	float _fFrom, _fTo, _fDelta;

public:
	CCActionTween();
	virtual ~CCActionTween();

	static CCActionTween *create(float aDuration, const char *key, float from, float to);

	bool initWithDuration(float aDuration, const char *key, float from, float to);

	virtual void update(float dt);
	virtual void startWithTarget(CCNode *pTarget);
	virtual CCActionInterval *reverse();
};

NS_CC_END