#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include <string>

NS_CC_BEGIN

class CC_DLL CCComponent : public CCObject
{
public:
	CCNode *_pOwner;
    std::string _strName;
    bool _bEnabled;

protected:
	CCComponent();

public:
	virtual ~CCComponent();

	static CCComponent *create();

	const char *getName() const;
	CCNode *getOwner() const;
	void setName(const char *name);
	void setOwner(CCNode *pNode);

	virtual void update(float dt);

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual bool serialize(void *r);
	virtual bool isEnabled() const;
	virtual void setEnabled(bool enabled);
};

NS_CC_END