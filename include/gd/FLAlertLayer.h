#pragma once

#include "CCLayer.h"

class FLAlertLayerProtocol { };


class FLAlertLayer : public cocos2d::CCLayerColor
{
public:
    FLAlertLayer();
    virtual ~FLAlertLayer();

    static FLAlertLayer* create( FLAlertLayerProtocol* protocol, const char* title, std::string caption, const char* button_title, const char* unknown );
    
    virtual void placeholder1();
    virtual void placeholder2();

    virtual void show( );
};
