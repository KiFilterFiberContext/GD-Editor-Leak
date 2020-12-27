#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"

NS_CC_BEGIN

class CC_DLL CCMouseDelegate
{
public:
	virtual void rightKeyDown();
	virtual void rightKeyUp();
	virtual void scrollWheel(float, float);
};

class CC_DLL CCMouseHandler : public CCObject
{
public:
	CCMouseDelegate *_pDelegate;

public:
	CCMouseHandler();
	virtual ~CCMouseHandler();

	static CCMouseHandler *handlerWithDelegate(CCMouseDelegate *);

	CCMouseDelegate *getDelegate();
	void setDelegate(CCMouseDelegate *);

	virtual bool initWithDelegate(CCMouseDelegate *);
};

class CC_DLL CCMouseDispatcher : public CCObject
{
public:
	CCArray *_pDelegates;
	bool _bLocked, _bToAdd, _bToRemove;
	_ccCArray *_pHandlersToAdd, *_pHandlersToRemove;

public:
	CCMouseDispatcher();
	virtual ~CCMouseDispatcher();

	void addDelegate(CCMouseDelegate *);
	bool dispatchScrollMSG(float, float);
	void forceAddDelegate(CCMouseDelegate *);
	void forceRemoveDelegate(CCMouseDelegate *);
	void removeDelegate(CCMouseDelegate *);
};

NS_CC_END