#pragma once

#include "CCMenuItem.h"

typedef void(cocos2d::CCObject::*SEL_MenuHandler)(cocos2d::CCObject *);

class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite 
{
public:
    CCMenuItemSpriteExtra();
    virtual ~CCMenuItemSpriteExtra();
    
    static CCMenuItemSpriteExtra* create( cocos2d::CCNode* sprite, cocos2d::CCNode* a2, cocos2d::CCObject* parentNode, SEL_MenuHandler selector );
};

class Base {
public:
    bool a;

public:
    bool getValue(int v);
};

class Extension : public Base {
public:
    DECLARE_DECORATOR(bool, getValue, int v);
};

DEFINE_DECORATOR(bool, Extension, getValue, int v) {
    if(v == 11)
        return true;

    return getValue_real(v);
}