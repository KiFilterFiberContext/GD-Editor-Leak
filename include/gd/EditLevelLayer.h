#pragma once

#include "LevelEditorLayer.h"
#include "TextInputDelegate.h"
#include "UploadActionDelegate.h"
#include "UploadPopupDelegate.h"
#include "SetIDPopupDelegate.h"
#include "UploadActionPopup.h"


// size 0x15C
class EditLevelLayer : public cocos2d::CCLayer, TextInputDelegate, FLAlertLayerProtocol, UploadActionDelegate, UploadPopupDelegate, SetIDPopupDelegate
{
public:
    cocos2d::CCMenu* btnMenu_; // 0x13C
    GJGameLevel* gameLevel_;
    cocos2d::CCArray* placeholderInput_;
    cocos2d::CCLabelBMFont* folderLabel_;
    bool isPlaying_;
    bool lowDetailMode_;
    int levelType_;
    std::string levelName_;
    UploadActionPopup* uploadPopup_;

public:
    EditLevelLayer();
    virtual ~EditLevelLayer();

    static EditLevelLayer* create( GJGameLevel* level );

    void closeTextInputs( );
    void verifyLevelName( );

    virtual void keyBackClicked( void );
};