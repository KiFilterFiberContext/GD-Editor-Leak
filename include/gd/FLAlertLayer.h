#pragma once

#include "CCLayer.h"
#include "CCMenu.h"
#include "CCNode.h"

#include "ButtonSprite.h"
#include "FLAlertLayerProtocol.h"

class FLAlertLayer : public cocos2d::CCLayerColor
{
public:
    cocos2d::CCMenu* btnMenu_;
    int controlConnected_;
    FLAlertLayerProtocol* PParent_;
    cocos2d::CCNode* targetScene_;
    bool reverseKeyBack_;
    cocos2d::ccColor3B color_;
    cocos2d::CCLayer* internalLayer_;
    int ZValue_;
    bool showInstant_;
    cocos2d::ccColor3B color2_;
    ButtonSprite* btn1_;
    ButtonSprite* btn2_;
    void* scrollingLayer_;
    int joystickConnected_;
    bool containsActions_;
    bool noBtnAction_;

public:
    FLAlertLayer();
    virtual ~FLAlertLayer();

    static FLAlertLayer* create( FLAlertLayerProtocol* protocol, const char* title, std::string caption, const char* button_title, const char* button2_title );
    static FLAlertLayer* create( FLAlertLayerProtocol* protocol, const char* title, std::string caption, const char* b1_title, const char* b2_title, float x_size, bool add_border, float y_size );

    virtual void placeholder1();
    virtual void placeholder2();

    virtual void show( );
};
