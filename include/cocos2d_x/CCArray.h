#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCString.h"

NS_CC_BEGIN

typedef struct _ccArray {
	unsigned int num, max;
	CCObject **arr;
} ccArray;

typedef struct _ccCArray {
	unsigned int num, max;
	void **arr;
} ccCArray;

class CC_DLL CCArray : public CCObject
{
public:
	ccArray *_data;

public:
	CCArray();
	CCArray(unsigned int capacity);
	virtual ~CCArray();

	static CCArray *create(CCObject *firstObject, ...);
	static CCArray *create();
	static CCArray *createWithArray(CCArray *pArray);
	static CCArray *createWithCapacity(unsigned int capacity);
	static CCArray *createWithContentsOfFile(const char *path);
	static CCArray *createWithContentsOfFileThreadSafe(const char *path);
	static CCArray *createWithObject(CCObject *pObject);

	void addObject(CCObject *pObject);
	void addObjectNew(CCObject *pObject);
	void addObjectsFromArray(CCArray *pArray);
	unsigned int capacity() const;
	bool containsObject(CCObject *pObject) const;
	unsigned int count() const;
	void exchangeObject(CCObject *pObject1, CCObject *pObject2);
	void exchangeObjectAtIndex(unsigned int index1, unsigned int index2);
	void fastRemoveObject(CCObject *pObject);
	void fastRemoveObjectAtIndex(unsigned int index);
	void fastRemoveObjectAtIndexNew(unsigned int index);
	unsigned int indexOfObject(CCObject *pObject) const;
	bool init();
	bool initWithArray(CCArray *pArray);
	bool initWithCapacity(unsigned int capacity);
	bool initWithObject(CCObject *pObject);
	bool __cdecl initWithObjects(CCObject *firstObject, ...);
	void insertObject(CCObject *pObject, unsigned int index);
	bool isEqualToArray(CCArray *pArray);
	CCObject *lastObject();
	CCObject *objectAtIndex(unsigned int index);
	CCObject *randomObject();
	void reduceMemoryFootprint();
	void removeAllObjects();
	void removeLastObject(bool cleanup);
	void removeObject(CCObject *pObject, bool cleanup);
	void removeObjectAtIndex(unsigned int index, bool cleanup);
	void removeObjectsInArray(CCArray *pArray);
	void replaceObjectAtIndex(unsigned int index, CCObject *pNewObject, bool cleanup);
	void reverseObjects();
	CCString *stringAtIndex(unsigned int index);

	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual void acceptVisitor(CCDataVisitor &rDataVisitor);
};

NS_CC_END