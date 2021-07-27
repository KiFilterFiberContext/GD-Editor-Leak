#pragma once

#include "CCNode.h"
#include "GJGameLevel.h"
#include "GJEffectManager.h"

// size 0x140
class LevelSettingsObject : public cocos2d::CCNode
{
public:
    GJEffectManager* colorManager_; // 0xF8
    int startMode_;
    int startSpeed_;
    bool miniMode_;
    bool startDualMode_;
    bool twoPlayerMode_;
    bool startPlatformerMode_;
    float songOffset_;
    bool fadeIn_;
    bool fadeOut_;
    bool gap10E[ 2 ];
    int BGIdx_;
    int GIdx_;
    int fontIdx_;
    int BG2Idx_;
    bool isStartPos_;
    bool gravityFlipped_;
    bool reversePlayer_;
    bool byte123;
    int dword124;
    GJGameLevel* gameLevel_;
    std::string guidelines_;
    bool byte130;
    bool gap131[ 3 ];
    int lastColorPage_;
    int GLineIdx_;
    bool byte13C;
    bool isVisible_;

public:
    LevelSettingsObject();
    virtual ~LevelSettingsObject();

    static LevelSettingsObject* create( );

    virtual bool init( void );
};