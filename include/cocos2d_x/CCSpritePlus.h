#pragma once

#include "CCSprite.h"

// robtop cocos extension

NS_CC_BEGIN

class CCSpritePlus : public cocos2d::CCSprite 
{
public:

public:
    CCSpritePlus();
    virtual ~CCSpritePlus();

    static CCSpritePlus* createWithSpriteFrameName( const char* frameName );
    static CCSpritePlus* createWithSpriteFrame( cocos2d::CCSpriteFrame* spriteFrame );
};

NS_CC_END