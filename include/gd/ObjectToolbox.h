#pragma once

#include "CCNode.h"

class ObjectToolbox : public cocos2d::CCNode 
{
public:
    ObjectToolbox();
    virtual ~ObjectToolbox();

    static ObjectToolbox* sharedState( );

    const char* intKeyToFrame( int key );
};