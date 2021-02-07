#pragma once

#include "CCLayer.h"
#include "CCTouch.h"
#include "GDAPI_Macros.h"

NS_CC_BEGIN

class CC_DLL CCBlockLayer : public cocos2d::CCLayerColor
{
public:
    uint32_t _pad[ 0xC ]; // 0x198 (CCLayerColor extra members)
    bool removeOnExit_; // 0x1A4
    bool initForce_; // 0x1A5

public:
    CCBlockLayer();
    virtual ~CCBlockLayer();

    static CCBlockLayer *create( );

    virtual bool init( );
    virtual void draw( );

    virtual bool ccTouchBegan( cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent );
    virtual void ccTouchMoved( cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent );
    virtual void ccTouchEnded( cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent );
    virtual void ccTouchCancelled( cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent );

    virtual void registerWithTouchDispatch( );
    virtual void keyBackClicked( );

    virtual void customSetup( );
    virtual void enterLayer( );
    virtual void exitLayer( );
    virtual void showLayer( );
    virtual void hideLayer( );
    virtual void layerVisible( );
    virtual void layerHidden( );
    virtual void enterAnimFinished( );
    virtual void disableUI( );
    virtual void enableUI( );
};

NS_CC_END