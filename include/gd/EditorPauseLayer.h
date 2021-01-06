#pragma once

#include "CCLayer.h"

#include "LevelEditorLayer.h"

class EditorPauseLayer : public cocos2d::CCLayerColor
{
public:
    uint8_t _pad198[ 0x14 ]; // 0x198
    bool inEditor_; // 0x1AC
    uint8_t _pad1AB[ 0xb ]; // 0x1AC
    LevelEditorLayer* editor_; // 0x1B8

public:
    EditorPauseLayer();
    virtual ~EditorPauseLayer();

    static EditorPauseLayer* create( LevelEditorLayer* a1 ); 

    void onOptions( CCObject* ref );
    void onSave( CCObject* ref );

};
