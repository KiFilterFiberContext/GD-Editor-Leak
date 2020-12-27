#pragma once

#include "CCLayer.h"

#include "LevelEditorLayer.h"

class EditorPauseLayer : public cocos2d::CCLayerColor
{
public:
    EditorPauseLayer();
    virtual ~EditorPauseLayer();

    static EditorPauseLayer* create( LevelEditorLayer* a1 ); // LevelEditorLayer*

    void onOptions( CCObject* ref );
    void onSave( CCObject* ref );

};
