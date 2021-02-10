#pragma once

#include "CCGeometry.h"
#include "CCNode.h"
#include "CCTouch.h"
#include "PlayerObject.h"
#include "CCLayer.h"

class UILayer : public cocos2d::CCLayerColor
{
public:
  uint8_t _pad[ 0x12 ];
  cocos2d::CCMenu *btnMenu_; // 0x1AC
  uint32_t pauseBtn_;
  bool byte1B4;
  bool byte1B5;
  bool byte1B6;
  bool byte1B7;
  bool byte1B8;
  bool gap1B9[3];
  uint32_t dword1BC;
  uint32_t dword1C0;
  uint32_t dword1C4;
  cocos2d::CCSprite *dpadBtn_;
  uint32_t dword1CC;
  cocos2d::CCRect* cocos2d__ccrect1D0; 
  bool gap1D4[12];
  cocos2d::CCRect* cocos2d__ccrect1E0;
  uint16_t gap1E4;
  bool gap1E6[15];
  char field_1F5;
  bool platformerMode_; // 0x1F6

public:
    UILayer( );
    virtual ~UILayer( );

    virtual bool init( );
    virtual void draw( );

    virtual bool ccTouchBegan( cocos2d::CCTouch*, cocos2d::CCEvent* );
    virtual void ccTouchMoved( cocos2d::CCTouch*, cocos2d::CCEvent* );
    virtual void ccTouchEnded( cocos2d::CCTouch*, cocos2d::CCEvent* );
    virtual void ccTouchCancelled( cocos2d::CCTouch*, cocos2d::CCEvent* );
    
};