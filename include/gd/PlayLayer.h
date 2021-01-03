#pragma once

#include "PlayerObject.h"
#include "GJGameLevel.h"
#include "GJEffectManager.h"
#include "GJBaseGameLayer.h"

class PlayLayer : public GJBaseGameLayer // GJBaseGameLayer
{
public:
    unsigned char _pad3[0xd8]; // 0x290
    bool platformerMode; // 0x368

    unsigned char _pad2[0x2ff]; // 0x369
    GJGameLevel* level; // 0x668

public:
    PlayLayer();
    virtual ~PlayLayer();

    static PlayLayer* create( GJGameLevel* level, bool a2, bool a3 );

    void toggleInfoLabel( );
};