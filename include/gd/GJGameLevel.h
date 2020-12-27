#pragma once

#include "CCLayer.h"

class GJGameLevel : public cocos2d::CCNode 
{
public:
    unsigned char _pad1[ 0x24 ];
    std::string levelString; // 0x110 not sure what this is
    
public:
    GJGameLevel();
    virtual ~GJGameLevel();

    static GJGameLevel* create( );

};