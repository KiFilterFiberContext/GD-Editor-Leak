#pragma once

#include "CCLayer.h"

class GJGroundLayer : public cocos2d::CCLayer 
{
public:

public:
    GJGroundLayer();
    virtual ~GJGroundLayer();

    static GJGroundLayer *create( int a1, int a2 );

    void updateGround01Color( cocos2d::ccColor3B color );
    void updateGround02Color( cocos2d::ccColor3B color );

    void updateLineBlend( bool update );
};