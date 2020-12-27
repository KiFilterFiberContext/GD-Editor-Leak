#pragma once

#include "CCNode.h"
#include "ColorAction.h"

class GJEffectManager : public cocos2d::CCNode
{
public:
    unsigned char _pad1[ 0x14 ];
    cocos2d::CCDictionary* cActionSpriteDict; // 0x100

    unsigned char _pa2[ 0x5C ]; // 0x104
    std::vector< ColorActionSprite* >* cActionSpriteArray; // 0x160

public:
    GJEffectManager();
    virtual ~GJEffectManager();

    static GJEffectManager* create( );

    ColorAction* getColorAction( int colorID );
    ColorActionSprite* getColorSprite( int colorID );
};