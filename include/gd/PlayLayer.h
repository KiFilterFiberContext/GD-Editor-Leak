#pragma once

#include "PlayerObject.h"
#include "GJGameLevel.h"

class PlayLayer : cocos2d::CCLayer // GJBaseGameLayer
{
public:
    unsigned char _pad1[0x168]; 
    PlayerObject* player1_; // 0x284
    PlayerObject* player2_; // 0x288
    LevelSettingsObject* settings_; // 0x28C
    
    unsigned char _pad3[0xd8]; // 0x290
    bool platformerMode; // 0x368

    unsigned char _pad2[0x2ff]; // 0x369
    GJGameLevel* level; // 0x668

public:
    PlayLayer();
    virtual ~PlayLayer();

    static PlayLayer* create( GJGameLevel* level, bool a2, bool a3 );

};