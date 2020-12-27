#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCActionInterval.h"

NS_CC_BEGIN

class CC_DLL CCActionCamera : public CCActionInterval
{
public:
	float _fCenterXOrig, _fCenterYOrig, _fCenterZOrig;
	float _fEyeXOrig, _fEyeYOrig, _fEyeZOrig;
	float _fUpXOrig, _fUpYOrig, _fUpZOrig;

public:
	CCActionCamera();
	virtual ~CCActionCamera();

	virtual void startWithTarget(CCNode *pTarget);
	virtual CCActionInterval *reverse();
};

NS_CC_END