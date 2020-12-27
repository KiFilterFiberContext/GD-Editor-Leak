#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCArray.h"

NS_CC_BEGIN

class CC_DLL CCAutoreleasePool : public CCObject
{
public:
	CCArray *_pManagedObjectArray;

public:
	CCAutoreleasePool();
	virtual ~CCAutoreleasePool();

	void addObject(CCObject *pObject);
	void clear();
	void removeObject(CCObject *pObject);
};

class CC_DLL CCPoolManager
{
public:
	CCArray *_pReleasePoolStack;
	CCAutoreleasePool *_pCurReleasePool;

public:
	CCPoolManager();
	~CCPoolManager();

	static CCPoolManager *sharedPoolManager();
	static void purgePoolManager();

	void addObject(CCObject *pObject);
	void finalize();
	void pop();
	void push();
	void removeObject(CCObject *pObject);

private:
	CCAutoreleasePool *getCurReleasePool();
};

NS_CC_END