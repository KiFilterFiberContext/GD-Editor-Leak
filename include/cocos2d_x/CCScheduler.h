#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"

NS_CC_BEGIN

#define kCCPrioritySystem INT_MIN

#define kCCPriorityNonSystemMin (kCCPrioritySystem + 1)

class CCSet;

class CC_DLL CCTimer : public CCObject
{
public:
	CCObject *_pTarget;
	float _fElapsed;
	bool _bRunForever, _bUseDelay;
	unsigned int _uTimesExecuted, _uRepeat;
	float _fDelay, _fInterval;
	SEL_SCHEDULE _pfnSelector;
	int _nScriptHandler;

public:
	CCTimer();
	virtual ~CCTimer();

	static CCTimer *timerWithTarget(CCObject *, SEL_SCHEDULE);
	static CCTimer *timerWithTarget(CCObject *, SEL_SCHEDULE, float);
	static CCTimer *timerWithScriptHandler(int, float);

	float getInterval() const;
	int getScriptHandler();
	bool initWithTarget(CCObject *, SEL_SCHEDULE);
	bool initWithTarget(CCObject *, SEL_SCHEDULE, float);
	bool initWithScriptHandler(int, float);
	void setInterval(float);
	
	virtual void update(float dt);
};

struct _listEntry;
struct _hashSelectorEntry;

class CCArray;

class CC_DLL CCScheduler : public CCObject
{
public:
	float _fTimeScale;
	struct _listEntry *_pUpdatesNegList, *_pUpdates0List, *_pUpdatesPosList;
	struct _hashUpdateEntry *_pHashForUpdates;
	struct _hashSelectorEntry *_pHashForTimers, *_pCurrentTarget;
	bool _bCurrentTargetSalvaged, _bUpdateHashLocked;
	CCArray *_pScriptHandlerEntries;

public:
	CCScheduler();
	virtual ~CCScheduler();

	float getTimeScale();
	bool isTargetPaused(CCObject *);
	CCSet *pauseAllTargets();
	CCSet *pauseAllTargetsWithMinPriority(int);
	void pauseTarget(CCObject *);
	void resumeTarget(CCObject *);
	void resumeTargets(CCSet *);
	unsigned int scheduleScriptFunc(unsigned int, float, bool);
	void scheduleSelector(SEL_SCHEDULE, CCObject *, float, bool);
	void scheduleSelector(SEL_SCHEDULE, CCObject *, float, unsigned int, float, bool);
	void scheduleUpdateForTarget(CCObject *, int, bool);
	void setTimeScale(float);
	void unscheduleAll();
	void unscheduleAllForTarget(CCObject *);
	void unscheduleAllWithMinPriority(int);
	void unscheduleScriptEntry(unsigned int);
	void unscheduleSelector(SEL_SCHEDULE, CCObject *);
	void unscheduleUpdateForTarget(const CCObject *);

private:
	void appendIn(_listEntry **, CCObject *, bool);
	void priorityIn(_listEntry **, CCObject *, int, bool);
	void removeHashElement(_hashSelectorEntry *);
	void removeUpdateFromHash(_listEntry *);

public:
	virtual void update(float dt);
};

NS_CC_END