#pragma once

#include "CCLayer.h"

class GJGroundLayer : public cocos2d::CCLayer 
{
public:

public:
    GJGroundLayer();
    virtual ~GJGroundLayer();

    static GJGroundLayer *create( int a1, int a2 );
};