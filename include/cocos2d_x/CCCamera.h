#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "kazmath/mat4.h"

NS_CC_BEGIN

class CC_DLL CCCamera : public CCObject
{
public:
	float _fEyeX, _fEyeY, _fEyeZ;
	float _fCenterX, _fCenterY, _fCenterZ;
	float _fUpX, _fUpY, _fUpZ;
	bool _bDirty;
	kmMat4 _lookupMatrix;

public:
	CCCamera();
	virtual ~CCCamera();

	static float getZEye();

	const char *description();
	void getCenterXYZ(float *x, float *y, float *z);
	void getEyeXYZ(float *x, float *y, float *z);
	void getUpXYZ(float *x, float *y, float *z);
	void init();
	bool isDirty();
	void locate();
	void restore();
	void setCenterXYZ(float x, float y, float z);
	void setDirty(bool bDirty);
	void setEyeXYZ(float x, float y, float z);
	void setUpXYZ(float x, float y, float z);
};

NS_CC_END