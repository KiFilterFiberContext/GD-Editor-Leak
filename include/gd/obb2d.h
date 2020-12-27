#pragma once

#include "CCNode.h"

class OBB2D : public cocos2d::CCNode 
{
public:
    OBB2D();
    virtual ~OBB2D();

    static OBB2D* create( cocos2d::CCPoint, float, float, float );
};