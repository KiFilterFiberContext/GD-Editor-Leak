#pragma once

#include "CCSprite.h"

enum PlayerButton 
{
    Jump = 1,
};

class PlayerObject : public cocos2d::CCSprite  // GameObject->CCSpritePlus
{
public:
    unsigned char _pad1[0x8a0]; // padding for CCSprite + 0x10
    int32_t platformerMode; // 0xA84

public:
    PlayerObject();
    virtual ~PlayerObject();

    static PlayerObject* create( int playerFrame, int shipFrame, cocos2d::CCLayer* a3 );

    void updatePlayerShipFrame( int a1 );

    void updateGlowColor( );
    void setSecondColor( const cocos2d::ccColor3B& color );

    void pushButton(PlayerButton btn);
    void releaseButton(PlayerButton btn);
    void switchedDirTo(PlayerButton btn);
    
    // virtual void setVisible( bool visible ); // 0xA8

    virtual void placeholder1();
    virtual void placeholder2();

    virtual void setColor( const cocos2d::ccColor3B& color ); // 0x1D4
};