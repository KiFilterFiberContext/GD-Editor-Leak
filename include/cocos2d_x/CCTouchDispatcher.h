#pragma once

#include "GDAPI_Macros.h"

#include "CCTouchDelegateProtocol.h"
#include "CCObject.h"
#include "CCArray.h"

NS_CC_BEGIN

typedef enum
{
	ccTouchSelectorBeganBit = 1 << 0,
	ccTouchSelectorMovedBit = 1 << 1,
	ccTouchSelectorEndedBit = 1 << 2,
	ccTouchSelectorCancelledBit = 1 << 3,
	ccTouchSelectorAllBits = (ccTouchSelectorBeganBit | ccTouchSelectorMovedBit | ccTouchSelectorEndedBit | ccTouchSelectorCancelledBit),
} ccTouchSelectorFlag;

enum
{
	CCTOUCHBEGAN,
	CCTOUCHMOVED,
	CCTOUCHENDED,
	CCTOUCHCANCELLED,

	ccTouchMax,
};

class CCSet;
class CCEvent;

struct ccTouchHandlerHelperData
{
	int _type;
};

class CC_DLL EGLTouchDelegate
{
public:
	EGLTouchDelegate();
	virtual ~EGLTouchDelegate();

	virtual void touchesBegan(CCSet *touches, CCEvent *pEvent) = 0;
	virtual void touchesMoved(CCSet *touches, CCEvent *pEvent) = 0;
	virtual void touchesEnded(CCSet *touches, CCEvent *pEvent) = 0;
	virtual void touchesCancelled(CCSet *touches, CCEvent *pEvent) = 0;
};

class CCTouchHandler;

class CC_DLL CCTouchDispatcher : public CCObject, public EGLTouchDelegate
{
public:
	CCArray *_pTargetedHandlers, *_pStandardHandlers;
	bool _bLocked, _bToAdd, _bToRemove;
	CCArray *_pHandlersToAdd;
	ccCArray *_pHandlersToRemove;
	bool _bToQuit, _bDispatchEvents;
	ccTouchHandlerHelperData _sHandlerHelperData[ccTouchMax];
	char _forcePrio;
	int _targetPrio;

public:
	CCTouchDispatcher();
	virtual ~CCTouchDispatcher();
	
	void addStandardDelegate(CCTouchDelegate *, int);
	void addTargetedDelegate(CCTouchDelegate *, int, bool);
	void decrementForcePrio(int);
	CCTouchHandler *findHandler(CCTouchDelegate *);
	bool getForcePrio() const;
	int getTargetPrio() const;
	void incrementForcePrio(int);
	bool init();
	bool isDispatchEvents();
	void removeAllDelegates();
	void removeDelegate(CCTouchDelegate *);
	void setDispatchEvents(bool);
	void setForcePrio(bool);
	void setPriority(int, CCTouchDelegate *);
	void setTargetPrio(int);
	void touches(CCSet *, CCEvent *, unsigned int);

protected:
	CCTouchHandler *findHandler(CCArray *, CCTouchDelegate *);
	void forceAddHandler(CCTouchHandler *, CCArray *);
	void forceRemoveAllDelegates();
	void forceRemoveDelegate(CCTouchDelegate *);
	void rearrangeHandlers(CCArray *);

public:
	virtual void touchesBegan(CCSet *touches, CCEvent *pEvent);
	virtual void touchesMoved(CCSet *touches, CCEvent *pEvent);
	virtual void touchesEnded(CCSet *touches, CCEvent *pEvent);
	virtual void touchesCancelled(CCSet *touches, CCEvent *pEvent);
};

NS_CC_END