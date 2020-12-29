#pragma once

#include "PlayerObject.h"
#include "GJGameLevel.h"
#include "GJEffectManager.h"

class PlayLayer : cocos2d::CCLayer // GJBaseGameLayer
{
public:
    unsigned char _pad1[0x2c]; 
    GJEffectManager* effectManager; // 0x148

    uint8_t _pad4[ 0x138 ]; // 0x14c

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