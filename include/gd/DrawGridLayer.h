#pragma once

#include "LevelEditorLayer.h"

class DrawGridLayer : public cocos2d::CCLayer
{
public:
    DrawGridLayer();
    virtual ~DrawGridLayer();

    static DrawGridLayer* create( CCNode* a1, LevelEditorLayer* a2 );

    void updateTimeMarkers( );
};