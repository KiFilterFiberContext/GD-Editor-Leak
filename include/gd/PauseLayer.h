#pragma once

#include "GDAPI_Macros.h"
#include "CCBlockLayer.h"
#include "CCMenuItem.h"

class GD_DLL PauseLayer : public cocos2d::CCBlockLayer
{
public:
    bool showAd_; // 0x1A6
    bool backClicked_; // 0x1A7

public:
    PauseLayer();
    virtual ~PauseLayer();
    
    static PauseLayer *create( bool a1 );

    void createToggleButton( std::string label, SEL_MenuHandler SEL, bool toggle, cocos2d::CCMenu* menu, cocos2d::CCPoint position );
    void goEdit( );

    void musicSliderChanged( cocos2d::CCObject* ref );
    void onAutoCheckpoints( cocos2d::CCObject* ref );
    void onAutoRetry( cocos2d::CCObject* ref );
    void onEdit( cocos2d::CCObject* ref );
    void onHelp( cocos2d::CCObject* ref );
    void onInfoLabel( cocos2d::CCObject* ref );
    void onNormalMode( cocos2d::CCObject* ref );
    void onPracticeMode( cocos2d::CCObject* ref );
    void onProgressBar( cocos2d::CCObject* ref );
    void onQuit( cocos2d::CCObject* ref );
    void onRecordReplays( cocos2d::CCObject* ref );
    void onRestart( cocos2d::CCObject* ref );
    void onResume( cocos2d::CCObject* ref );
    void onTime( cocos2d::CCObject* ref );
    void sfxSliderChanged( cocos2d::CCObject* ref );

    void setpuProgressBars( );
    void tryShowBanner( float duration );

    virtual void keyBackClicked( );
    virtual void keyDown( cocos2d::enumKeyCodes keyCode );
    virtual void customSetup( );
    virtual void keyUp( cococs2d::enumKeyCodes keyCode );
}