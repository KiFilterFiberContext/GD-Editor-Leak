#pragma once

#include "GDAPI_Macros.h"

#include "CCAction.h"
#include "CCProtocols.h"

NS_CC_BEGIN

class CC_DLL CCActionInstant : public CCFiniteTimeAction
{
public:
	CCActionInstant();
	virtual ~CCActionInstant();

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void update(float time);
	virtual bool isDone();
	virtual void step(float dt);
	virtual CCFiniteTimeAction *reverse();
};

class CC_DLL CCShow : public CCActionInstant
{
public:
	CCShow();
	virtual ~CCShow();

	static CCShow *create();

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void update(float time);
	virtual CCFiniteTimeAction *reverse();
};

class CC_DLL CCHide : public CCActionInstant
{
public:
	CCHide();
	virtual ~CCHide();

	static CCHide *create();

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void update(float time);
	virtual CCFiniteTimeAction *reverse();
};

class CC_DLL CCToggleVisibility : public CCActionInstant
{
public:
	CCToggleVisibility();
	virtual ~CCToggleVisibility();

	static CCToggleVisibility *create();

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void update(float time);
};

class CC_DLL CCRemoveSelf : public CCActionInstant
{
public:
	bool _bIsNeedCleanUp;

public:
	CCRemoveSelf();
	virtual ~CCRemoveSelf();

	static CCRemoveSelf *create(bool isNeedCleanUp = true);

	bool init(bool isNeedCleanUp);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void update(float time);
	virtual CCFiniteTimeAction *reverse();
};

class CC_DLL CCFlipX : public CCActionInstant
{
public:
	bool _bFlipX;

public:
	CCFlipX();
	virtual ~CCFlipX();

	static CCFlipX *create(bool x);

	bool initWithFlipX(bool x);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void update(float time);
	virtual CCFiniteTimeAction *reverse();
};

class CC_DLL CCFlipY : public CCActionInstant
{
public:
	bool _bFlipY;

public:
	CCFlipY();
	virtual ~CCFlipY();

	static CCFlipY *create(bool y);

	bool initWithFlipY(bool y);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void update(float time);
	virtual CCFiniteTimeAction *reverse();
};

class CC_DLL CCPlace : public CCActionInstant
{
public:
	CCPoint _tPosition;

public:
	CCPlace();
	virtual ~CCPlace();

	static CCPlace *create(const CCPoint &pos);

	bool initWithPosition(const CCPoint &pos);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void update(float time);
};

class CC_DLL CCCallFunc : public CCActionInstant
{
public:
	CCObject *_pSelectorTarget;
	int _nScriptHandler;
	union
	{
		SEL_CallFunc _pCallFunc;
		SEL_CallFuncN _pCallFuncN;
		SEL_CallFuncND _pCallFuncND;
		SEL_CallFuncO _pCallFuncO;
	};

public:
	CCCallFunc();
	virtual ~CCCallFunc();

	static CCCallFunc *create(CCObject *pSelectorTarget, SEL_CallFunc selector);
	static CCCallFunc *create(int nHandler);

	int getScriptHandler();
	CCObject *getTargetCallback();
	void setTargetCallback(CCObject *pSel);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void update(float time);
	virtual bool initWithTarget(CCObject *pSelectorTarget);
	virtual void execute();
};

class CC_DLL CCCallFuncN : public CCCallFunc, public TypeInfo
{
public:
	CCCallFuncN();
	virtual ~CCCallFuncN();

	static CCCallFuncN *create(CCObject *pSelectorTarget, SEL_CallFuncN selector);
	static CCCallFuncN *create(int nHandler);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void execute();
	virtual bool initWithTarget(CCObject *pSelectorTarget, SEL_CallFuncN selector);
	virtual long getClassTypeInfo();
};

class CC_DLL CCCallFuncND : public CCCallFuncN
{
public:
	void *_pData;

public:
	CCCallFuncND();
	virtual ~CCCallFuncND();

	static CCCallFuncND *create(CCObject *pSelectorTarget, SEL_CallFuncND selector, void *pData);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void execute();
	virtual bool initWithTarget(CCObject *pSelectorTarget, SEL_CallFuncND selector, void *pData);
	virtual long getClassTypeInfo();
};

class CC_DLL CCCallFuncO : public CCCallFunc, public TypeInfo
{
public:
	CCObject *_pObject;

public:
	CCCallFuncO();
	virtual ~CCCallFuncO();

	static CCCallFuncO *create(CCObject *pSelectorTarget, SEL_CallFuncO selector, CCObject *pObject);

	CCObject *getObject();
	void setObject(CCObject *pObj);

	virtual CCObject* copyWithZone(CCZone *pZone);
	virtual void execute();
	virtual bool initWithTarget(CCObject *pSelectorTarget, SEL_CallFuncO selector, CCObject *pObject);
	virtual long getClassTypeInfo();
};

NS_CC_END