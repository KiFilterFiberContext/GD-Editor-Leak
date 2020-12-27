#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCAction.h"

NS_CC_BEGIN

class CCSet;
struct _hashElement;

class CC_DLL CCActionManager : public CCObject
{
public:
	_hashElement *_pTargets, *_pCurrentTarget;
	bool _bCurrentTargetSalvaged;

public:
	CCActionManager();
	virtual ~CCActionManager();

	void addAction(CCAction *, CCNode *, bool);
	CCAction *getActionByTag(unsigned int, CCObject *);
	unsigned int numberOfRunningActionsInTarget(CCObject *);
	CCSet *pauseAllRunningActions();
	void pauseTarget(CCObject *);
	void removeAction(CCAction *);
	void removeActionByTag(unsigned int, CCObject *);
	void removeAllActions();
	void removeAllActionsFromTarget(CCObject *);
	void resumeTarget(CCObject *);
	void resumeTargets(CCSet *);

protected:
	void actionAllocWithHashElement(_hashElement *);
	void deleteHashElement(_hashElement *);
	void removeActionAtIndex(unsigned int, _hashElement *);

protected:
	virtual void update(float);
};

NS_CC_END