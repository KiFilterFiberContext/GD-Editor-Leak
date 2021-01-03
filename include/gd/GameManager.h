#pragma once

#include "CCNode.h"
#include "PlayLayer.h"
#include "LevelEditorLayer.h"

class GameManager : public cocos2d::CCNode 
{
public:
    unsigned char _pad1[ 0x6c ]; 
    PlayLayer* playLayer; // 0x158
    LevelEditorLayer* editorLayer; // 0x15C

    unsigned char _pad2[ 0x58 ]; // 0x160
    uint32_t playerFrame2; // 0x1B8
    uint32_t playerFrame1; // 0x1BC
    uint32_t _unk1; // 0x1C0
    uint32_t shipFrame2; // 0x1C4
    uint32_t shipFrame1; // 0x1C8

    unsigned char _pad3[ 0x4c ]; // 0x1cc
    uint32_t primaryColorID_2; // 0x218
    uint32_t primaryColorID_1; // 0x21C
    uint32_t _unk2;  // 0x220
    uint32_t secondaryColorID_2; // 0x224
    uint32_t secondaryColorID_1; // 0x228

public:
    GameManager();
    virtual ~GameManager();

    static GameManager* sharedState( );

    bool getGameVariable( const char* g_var );
    void setGameVariable( const char* g_var, bool toggle );

    bool hasRatingPower( );
    void setHasRatingPower( int a1 );

    cocos2d::ccColor3B colorForIdx( int id ); // ccColor3B
};

#define GM GameManager::sharedState()
#define PL GameManager::sharedState()->playLayer