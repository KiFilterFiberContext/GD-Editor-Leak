#pragma once

#include "GDAPI_Macros.h"

#include "CCTouchDelegateProtocol.h"
#include "CCObject.h"
#include "CCSet.h"

NS_CC_BEGIN

class CC_DLL CCTouchHandler : public CCObject
{
public:
	CCTouchDelegate *_pDelegate;
	int _nPriority;
	int _nEnabledSelectors;

public:
	CCTouchHandler();
	virtual ~CCTouchHandler();

	static CCTouchHandler *handlerWithDelegate(CCTouchDelegate *, int);

	CCTouchDelegate *getDelegate();
	int getEnabledSelectors();
	int getPriority();
	void setDelegate(CCTouchDelegate *);
	void setEnalbedSelectors(int);
	void setPriority(int);

	virtual bool initWithDelegate(CCTouchDelegate *, int);
};

class CC_DLL CCStandardTouchHandler : public CCTouchHandler
{
public:
	CCStandardTouchHandler();
	virtual ~CCStandardTouchHandler();

	static CCStandardTouchHandler *handlerWithDelegate(CCTouchDelegate *, int);

	virtual bool initWithDelegate(CCTouchDelegate *, int);
};

class CC_DLL CCTargetedTouchHandler : public CCTouchHandler
{
public:
	bool _bSwallowsTouches;
	CCSet *_pClaimedTouches;

public:
	CCTargetedTouchHandler();
	virtual ~CCTargetedTouchHandler();

	static CCTargetedTouchHandler *handlerWithDelegate(CCTouchDelegate *, int, bool);

	CCSet *getClaimedTouches();
	bool initWithDelegate(CCTouchDelegate *, int, bool);
	bool isSwallowsTouches();
	void setSwallowsTouches(bool);
};

NS_CC_END