#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCArray.h"

NS_CC_BEGIN

class CC_DLL CCKeypadDelegate
{
public:
	virtual void keyBackClicked();
	virtual void keyMenuClicked();
};

class CC_DLL CCKeypadHandler : public CCObject
{
public:
	CCKeypadDelegate *_pDelegate;

public:
	CCKeypadHandler();
	virtual ~CCKeypadHandler();

	static CCKeypadHandler *handlerWithDelegate(CCKeypadDelegate *);

	CCKeypadDelegate *getDelegate();
	void setDelegate(CCKeypadDelegate *);

	virtual bool initWithDelegate(CCKeypadDelegate *);
};

typedef enum
{
	kTypeBackClicked = 1,
	kTypeMenuClicked,
} ccKeypadMSGType;

class CC_DLL CCKeypadDispatcher : public CCObject
{
public:
	CCArray *_pDelegates;
	bool _bLocked, _bToAdd, _bToRemove;
	_ccCArray *_pHandlersToAdd, *_pHandlersToRemove;

public:
	CCKeypadDispatcher();
	virtual ~CCKeypadDispatcher();

	void addDelegate(CCKeypadDelegate *);
	bool dispatchKeypadMSG(ccKeypadMSGType);
	void forceAddDelegate(CCKeypadDelegate *);
	void forceRemoveDelegate(CCKeypadDelegate *);
	void removeDelegate(CCKeypadDelegate *);
};

NS_CC_END