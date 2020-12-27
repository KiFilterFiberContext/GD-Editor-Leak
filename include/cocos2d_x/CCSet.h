#pragma once

#include "GDAPI_Macros.h"

#include <set>
#include "CCObject.h"

NS_CC_BEGIN

typedef std::set<CCObject *>::iterator CCSetIterator;

class CC_DLL CCSet : public CCObject
{
public:
	std::set<CCObject*> *_pSet;

public:
	CCSet();
	virtual ~CCSet();

	static CCSet *create();

	void addObject(CCObject *pObject);
	CCObject *anyObject();
	CCSetIterator begin();
	bool containsObject(CCObject *pObject);
	CCSet *copy();
	int count();
	CCSetIterator end();
	CCSet *mutableCopy();
	void removeAllObjects();
	void removeObject(CCObject *pObject);

	virtual void acceptVisitor(CCDataVisitor &rDataVisitor);
};

NS_CC_END