#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"

NS_CC_BEGIN

class CC_DLL CCDouble : public CCObject
{
public:
	double _dValue;

public:
	CCDouble(double v);
	virtual ~CCDouble();

	static CCDouble *create(double v);

	double getValue() const;

	virtual void acceptVisitor(CCDataVisitor &rDataVisitor);
};

NS_CC_END