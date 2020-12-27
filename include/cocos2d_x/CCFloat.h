#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"

NS_CC_BEGIN

class CC_DLL CCFloat : public CCObject
{
public:
	float _fValue;

public:
	CCFloat(float v);
	virtual ~CCFloat();

	static CCFloat *create(float v);

	float getValue() const;

	virtual void acceptVisitor(CCDataVisitor &rDataVisitor);
};

NS_CC_END