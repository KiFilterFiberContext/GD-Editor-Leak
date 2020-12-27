#pragma once

#include "GDAPI_Macros.h"

NS_CC_BEGIN

typedef class
{
public:
	double x;
	double y;
	double z;
	double timestamp;
} CCAcceleration;

class CC_DLL CCAccelerometerDelegate
{
public:
	virtual void didAccelerate(CCAcceleration *pAccelerationValue);
};

class CC_DLL CCAccelerometer
{
public:
	CCAcceleration _obAccelerationValue;
	CCAccelerometerDelegate *_pAccelDelegate;

public:
	CCAccelerometer();
	~CCAccelerometer();

	void setAccelerometerInterval(float fInterval);
	void setDelegate(CCAccelerometerDelegate *pDelegate);
	void update(double x, double y, double z, double timestamp);
};

NS_CC_END