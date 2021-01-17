#pragma once

#include "CCNode.h"

class ObjectToolbox : public cocos2d::CCNode 
{
public:
    uint8_t ccnode_pad_E4[ 0xC ]; // 0xE4
    cocos2d::CCDictionary* objectFrameNameDict_; // 0xF8 CCString <=> std::string
    cocos2d::CCDictionary* objectIDFrameDict_; // 0xFC int <=> CCString

public:
    ObjectToolbox();
    virtual ~ObjectToolbox();

    static ObjectToolbox* sharedState( );
    bool init( );

    const char* intKeyToFrame( int key );
};