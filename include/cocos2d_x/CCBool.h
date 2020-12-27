#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"

NS_CC_BEGIN

class CC_DLL CCBool : public CCObject
{
public:
	bool _bValue;

public:
	CCBool(bool v);
	virtual ~CCBool();

	static CCBool *create(bool v);

	bool getValue() const;

	virtual void acceptVisitor(CCDataVisitor &rDataVisitor);
};

NS_CC_END