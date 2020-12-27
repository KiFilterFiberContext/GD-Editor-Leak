#pragma once

#include "GDAPI_Macros.h"

#include "CCNode.h"

NS_CC_BEGIN

class CC_DLL CCScene : public CCNode
{
public:
	int _unk0; //TODO: Rename argument in CCScene

public:
	CCScene();
	virtual ~CCScene();

	static CCScene *create();

	int getHighestChildZ();

	virtual bool init();
};

class CC_DLL CCSceneDelegate
{
public:
	virtual void willSwitchToScene(CCScene *pScene);
};

class CC_DLL CCSceneTransitionDelegate
{
public:
	virtual void sceneWillResume();
};

NS_CC_END