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
    static ButtonSprite* create( char const* a1 , int a2, int a3, float a4, bool a5, char const* a7, char const* a8,float a9 );
};