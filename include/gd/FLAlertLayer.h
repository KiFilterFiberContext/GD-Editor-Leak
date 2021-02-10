#pragma once

#include "CCLayer.h"

class FLAlertLayerProtocol { };


class FLAlertLayer : public cocos2d::CCLayerColor
{
public:
    FLAlertLayer();
    virtual ~FLAlertLayer();

    static FLAlertLayer* create( FLAlertLayerProtocol* protocol, const char* title, std::string caption, const char* button_title, const char* button2_title );
    static FLAlertLayer* create( FLAlertLayerProtocol* protocol, const char* title, std::string caption, const char* b1_title, const char* b2_title, float x_size, bool add_border, float y_size );
    
    virtual void placeholder1();
    virtual void placeholder2();

    virtual void show( );
};
