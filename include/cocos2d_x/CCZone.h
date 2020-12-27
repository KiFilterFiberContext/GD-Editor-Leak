#pragma once

#include "GDAPI_Macros.h"

NS_CC_BEGIN

class CCObject;

class CC_DLL CCZone
{
public:
	CCObject *_pCopyObject;

public:
	CCZone(CCObject *pObject = nullptr);
};

NS_CC_END