#pragma once

#include "CCLayer.h"
#include "LevelFeatureLayer.h"

class LevelInfoLayer : public cocos2d::CCLayer 
{
public:


public:
    LevelInfoLayer();
    virtual ~LevelInfoLayer();

    void onRate( cocos2d::CCObject* ref );
    void onRateStarsMod( cocos2d::CCObject* ref );

    void onPlay( cocos2d::CCObject* ref );
    void onPlayReplay( cocos2d::CCObject* ref );
};