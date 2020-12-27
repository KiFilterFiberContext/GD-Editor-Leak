#pragma once

#include "CCSprite.h"

class ButtonSprite : public cocos2d::CCSprite 
{
public:

public:
    ButtonSprite();
    virtual ~ButtonSprite();

    static ButtonSprite* create( cocos2d::CCSprite* sprite );
    static ButtonSprite* create( const char* sprite );
    static ButtonSprite* create( const char* sprite, float size );
};