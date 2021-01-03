#pragma once

#include "CCMenuItem.h"
#include "GDAPI_Macros.h"


class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite 
{
public:
    CCMenuItemSpriteExtra();
    virtual ~CCMenuItemSpriteExtra();
    
    static CCMenuItemSpriteExtra* create( cocos2d::CCNode* sprite, cocos2d::CCNode* a2, cocos2d::CCObject* parentNode, cocos2d::SEL_MenuHandler selector );
};
