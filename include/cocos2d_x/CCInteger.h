#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"

NS_CC_BEGIN

class CC_DLL CCInteger : public CCObject
{
public:
	int _nValue;

public:
	CCInteger(int v);
	virtual ~CCInteger();

	static CCInteger *create(int v);

	int getValue() const;

	virtual void acceptVisitor(CCDataVisitor &rDataVisitor);
};

NS_CC_END