#pragma once

#include "CCSprite.h"
#include "WorldSelectLayer.h"

class CreatorLayer : public cocos2d::CCLayer 
{
public:

public:
    CreatorLayer();
    virtual ~CreatorLayer();


};

class CreatorLayerExt : public CreatorLayer 
{
public:
    void onWorld( cocos2d::CCObject* ref )
    {
        auto dir = CCDirector::sharedDirector();
        dir->pushScene( cocos2d::CCTransitionFade::create(0.5, WorldSelectLayer::scene( 0 ) ) );

        GM->editorScene_ = true;
    }
};