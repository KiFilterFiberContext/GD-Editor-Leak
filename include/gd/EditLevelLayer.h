#pragma once

#include "LevelEditorLayer.h"

class EditLevelLayer : public cocos2d::CCLayer 
{
public:
    unsigned char _pad1[ 0x24 ];
    GJGameLevel* level; // 0x140

public:
    EditLevelLayer();
    virtual ~EditLevelLayer();

    void closeTextInputs( );
    void verifyLevelName( );
};