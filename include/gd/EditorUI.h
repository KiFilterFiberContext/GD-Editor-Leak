#pragma once

#include "LevelEditorLayer.h"

class LevelEditorLayer;

class EditorUI : public cocos2d::CCLayer
{
public:
    

public:
    EditorUI();
    virtual ~EditorUI();

    static EditorUI* create( LevelEditorLayer* a1 );

    void updateSlider( );
    
    void updateGroupIDLabel( );
    void toggleStickyControls( bool toggle );
};