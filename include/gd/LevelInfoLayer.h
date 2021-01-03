#pragma once

#include "CCLayer.h"

class LevelInfoLayer : public cocos2d::CCLayer 
{
public:

public:
    LevelInfoLayer();
    virtual ~LevelInfoLayer();

    void onPlay( cocos2d::CCObject* ref );
    void onPlayReplay( cocos2d::CCObject* ref );
};