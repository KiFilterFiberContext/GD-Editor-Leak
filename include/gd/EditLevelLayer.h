#pragma once

#include "LevelEditorLayer.h"

class EditLevelLayer : public cocos2d::CCLayer 
{
public:
    unsigned char _pad1[ 0x24 ];
    GJGameLevel* level; // 0x140
    cocos2d::CCArray* a1; // 0x144
    cocos2d::CCArray* a2; // 0x148
    bool inEditorLayer_; // 0x14C

public:
    EditLevelLayer();
    virtual ~EditLevelLayer();

    void closeTextInputs( );
    void verifyLevelName( );
};