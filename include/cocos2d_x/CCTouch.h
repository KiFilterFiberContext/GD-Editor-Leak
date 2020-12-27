#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCGeometry.h"

NS_CC_BEGIN

class CC_DLL CCTouch : public CCObject
{
public:
	int _nId;
	bool _startPointCaptured;
	CCPoint _startPoint, _point, _prevPoint;

public:
	CCTouch();
	virtual ~CCTouch();

	CCPoint getDelta() const;
	int getID() const;
	CCPoint getLocation() const;
	CCPoint getLocationInView() const;
	CCPoint getPreviousLocation() const;
	CCPoint getPreviousLocationInView() const;
	CCPoint getStartLocation() const;
	CCPoint getStartLocationInView() const;
	void setTouchInfo(int, float, float);
};

class CC_DLL CCEvent : public CCObject
{
public:
	CCEvent();
	virtual ~CCEvent();
};

NS_CC_END