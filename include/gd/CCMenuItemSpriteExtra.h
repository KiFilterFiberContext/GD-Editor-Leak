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
