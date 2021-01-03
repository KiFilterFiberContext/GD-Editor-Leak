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
    static ButtonSprite* create( char const* label, int type, int a1, float size, bool a2 );
    static ButtonSprite* create( char const* label , int a2, int a3, float fontSize, bool dontMatchSize, char const* font, char const* btnTexture, float height );
};