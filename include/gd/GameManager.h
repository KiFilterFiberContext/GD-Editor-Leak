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

    unsigned char _pad2[ 0x4a ]; // 0x160
    bool inEditor_; // 0x1AA
    bool unk1AB; // 0x1AB
    int editorScene_; // 0x1AC

    uint8_t _pad1ab[ 0xB ]; // 0x1AD

    int playerFrame2; // 0x1B8
    int playerFrame1; // 0x1BC
    int playerFrame_; // 0x1C0
    int shipFrame2; // 0x1C4
    int shipFrame1; // 0x1C8

    unsigned char _pad3[ 0x4c ]; // 0x1cc
    int primaryColorID_2; // 0x218
    int primaryColorID_1; // 0x21C
    int primaryColorID_;  // 0x220
    int secondaryColorID_2; // 0x224
    int secondaryColorID_1; // 0x228

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