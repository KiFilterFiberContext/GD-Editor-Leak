#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCComponent.h"
#include "CCNode.h"
#include "CCDictionary.h"

NS_CC_BEGIN

class CC_DLL CCComponentContainer
{
public:
	CCDictionary *_pComponents;
	CCNode *_pOwner;

protected:
	CCComponentContainer(CCNode *pNode);

public:
	virtual ~CCComponentContainer();

	bool isEmpty() const;

private:
	void alloc();

public:
	virtual CCComponent *get(const char *name) const;
	virtual bool add(CCComponent *pComponent);
	virtual bool remove(CCComponent *pComponent);
	virtual bool remove(const char *name);
	virtual void removeAll();
	virtual void visit(float fDelta);
};

NS_CC_END