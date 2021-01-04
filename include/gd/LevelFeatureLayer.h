#pragma once

#include "FLAlertLayer.h"

class LevelFeatureLayer : public FLAlertLayer
{
public:

public:
    LevelFeatureLayer();
    virtual ~LevelFeatureLayer();

    static LevelFeatureLayer* create( int levelID );
};