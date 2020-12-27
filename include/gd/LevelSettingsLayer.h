#pragma once

#include "FLAlertLayer.h"
#include "LevelEditorLayer.h"
#include "LevelSettingsObject.h"

class LevelSettingsLayer : public FLAlertLayer 
{
public:
    LevelSettingsLayer();
    virtual ~LevelSettingsLayer();

    static LevelSettingsLayer* create( LevelSettingsObject* a1, LevelEditorLayer* a2 );
};