#pragma once

#include "FLAlertLayer.h"

class FLAlertLayer;

class FLAlertLayerProtocol
{
public:
    virtual void FLAlert_Clicked( FLAlertLayer*, bool ) = 0;
};
