#pragma once

#include "PlayerObject.h"
#include "GJGameLevel.h"
#include "GJEffectManager.h"
#include "GJBaseGameLayer.h"

class PlayLayer : public GJBaseGameLayer // GJBaseGameLayer
{
public:
    unsigned char _pad2[0x284]; // 0x3e4
    GJGameLevel* level; // 0x668

public:
    PlayLayer();
    virtual ~PlayLayer();

    static PlayLayer* create( GJGameLevel* level, bool a2, bool a3 );

    void toggleInfoLabel( );
    void stopRecording( );
    void removeAllObjects();
};