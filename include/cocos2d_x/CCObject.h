#pragma once

#include "GDAPI_Macros.h"

class DS_Dictionary;

NS_CC_BEGIN

class CCZone;
class CCObject;
class CCNode;
class CCEvent;
class CCDataVisitor;

enum CCObjectType
{

};

class CC_DLL CCCopying
{
public:
	virtual CCObject *copyWithZone(CCZone *pZone);
};

class CC_DLL CCObject : public CCCopying
{
public:
	unsigned int _uID;
	int _nLuaID;
	int _nTag;
	unsigned int _uReference;
	unsigned int _uAutoReleaseCount;
	CCObjectType _eObjType;
	int _unk0; //TODO: Rename last argument in CCObject

public:
	CCObject();
	virtual ~CCObject();

	static CCObject *createWithCoder(DS_Dictionary *pDS_Dict);

	CCObject *autorelease();
	CCObject *copy();
	CCObjectType getObjType();
	bool isSingleReference();
	void release();
	void retain();
	unsigned int retainCount();
	void setObjType(CCObjectType eObjType);

	virtual bool isEqual(const CCObject *pObject);
	virtual void acceptVisitor(CCDataVisitor &rDataVisitor);
	virtual void update(float dt);
	virtual void encodeWithCoder(DS_Dictionary *pDS_Dict);
	virtual bool canEncode();
	virtual int getTag() const;
	virtual void setTag(int tag);
};

typedef void (CCObject::*SEL_SCHEDULE)(float);
typedef void (CCObject::*SEL_CallFunc)();
typedef void (CCObject::*SEL_CallFuncN)(CCNode*);
typedef void (CCObject::*SEL_CallFuncND)(CCNode*, void*);
typedef void (CCObject::*SEL_CallFuncO)(CCObject*);
typedef void (CCObject::*SEL_MenuHandler)(CCObject*);
typedef void (CCObject::*SEL_EventHandler)(CCEvent*);
typedef int (CCObject::*SEL_Compare)(CCObject*);

#define schedule_selector(_SELECTOR) (SEL_SCHEDULE)(&_SELECTOR)
#define callfunc_selector(_SELECTOR) (SEL_CallFunc)(&_SELECTOR)
#define callfuncN_selector(_SELECTOR) (SEL_CallFuncN)(&_SELECTOR)
#define callfuncND_selector(_SELECTOR) (SEL_CallFuncND)(&_SELECTOR)
#define callfuncO_selector(_SELECTOR) (SEL_CallFuncO)(&_SELECTOR)
#define menu_selector(_SELECTOR) (SEL_MenuHandler)(&_SELECTOR)
#define event_selector(_SELECTOR) (SEL_EventHandler)(&_SELECTOR)
#define compare_selector(_SELECTOR) (SEL_Compare)(&_SELECTOR)

NS_CC_END