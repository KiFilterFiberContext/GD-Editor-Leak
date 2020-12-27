#pragma once

#include "CCSprite.h"
#include "GJEffectManager.h"

class GameObject : public cocos2d::CCSprite // CCSpritePlus
{
public:
    unsigned char _pad1[ 0x98 ];
    cocos2d::CCAction* action; // 0x27C

    unsigned char _pad2[ 0x1E4 ]; // 0x280
    GJEffectManager* effectManager; // 0x464

public:
    GameObject( );
    virtual ~GameObject();

    static GameObject* createWithKey( int key );
    static GameObject* createWithTexture( cocos2d::CCTexture2D* texture );
    static GameObject* createWithFrame( const char* frame );

    void setMyAction( cocos2d::CCAction* action );

    void addColorSprite( );
    void saveActiveColors( );

    virtual void __unknown0( );
    virtual void __unknown1( );
    virtual void __unknown2( );
    virtual void __unknown3( );

    virtual void customSetup( ); // 0x268
    virtual void setupCustomSprites( ); // 0x26C

    virtual void __unknown4( );
    virtual void __unknown5( );
    virtual void __unknown6( );
    virtual void __unknown7( );
    virtual void __unknown8( );
    virtual void __unknown9( );
    virtual void __unknown10( );
    virtual void __unknown11( );
    virtual void __unknown12( );
    virtual void __unknown13( );
    virtual void __unknown14( );

    virtual void setStartPos( cocos2d::CCPoint p ); // 0x29C
};