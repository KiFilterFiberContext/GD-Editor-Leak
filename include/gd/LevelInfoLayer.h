#pragma once

#include "CCLayer.h"
#include "LevelFeatureLayer.h"
#include "gd/CCMenuItemSpriteExtra.h"
#include "GJGameLevel.h"
#include "LoadingLayer.h"

class LevelInfoLayer : public cocos2d::CCLayer 
{
public:
    uint8_t padding[ 0x2C ]; // 0x11C
    bool isInvalid_; // 0x148

    cocos2d::CCMenu* playMenu_; // 0x14C
    GJGameLevel* gameLevel_; // 0x150
    cocos2d::CCArray* coins_; // 0x154

    CCMenuItemSpriteExtra* likeBtn_; // 0x158
    CCMenuItemSpriteExtra* rateStarsBtn_; // 0x15C
    CCMenuItemSpriteExtra* rateDemonBtn_; // 0x160

    void* unknown0; // 0x164
    void* lowDetailToggle_; // 0x168 CCMenuItemToggler*
    cocos2d::CCNode* child_; // 0x16C

    cocos2d::CCLabelBMFont* lengthLabel_; // 0x170
    cocos2d::CCLabelBMFont* downloadsLabel_; // 0x174
    cocos2d::CCLabelBMFont* likesLabel_; // 0x178
    cocos2d::CCLabelBMFont* currencyLabel_; // 0x17C
    cocos2d::CCLabelBMFont* folderLabel_; // 0x180
    CCMenuItemSpriteExtra* cloneLevelBtn_; // 0x184

    void* unknown3; // 0x188
    cocos2d::CCSprite* likesIcon_; // 0x18C
    cocos2d::CCSprite* currencyIcon_; // 0x190

    int levelType_; // 0x194
    bool didDownloadLevel_; // 0x198
    void* loadingCircle_; // 0x19C LoadingCircle*

    cocos2d::CCSprite* difficultyIcon_; // 0x1A0
    cocos2d::CCSprite* starsIcon_; // 0x1A4
    cocos2d::CCLabelBMFont* starsLabel_; // 0x1A8
    cocos2d::CCSprite* featuredCoin_; // 0x1AC

    cocos2d::CCLabelBMFont* levelInfoLabel_; // 0x1B0
    float infoLabelOffset_; // 0x1B4
    cocos2d::CCPoint infoLabelPosition_; // 0x1B8

    bool isGauntletLevel_; // 0x1C4
    cocos2d::CCScene* playScene_; // 0x1C8
    cocos2d::CCSprite* playBtn_; // 0x1CC

    float loadPercentage_; // 0x1D0
    void* songWidget_; // 0x1D4 CustomSongWidget*
        
public:
    LevelInfoLayer();
    virtual ~LevelInfoLayer();

    bool init( GJGameLevel* level, bool isGauntletSpecial );

    void onRate( cocos2d::CCObject* ref );
    void onRateStarsMod( cocos2d::CCObject* ref );

    void onPlay( cocos2d::CCObject* ref );
    void onPlayReplay( cocos2d::CCObject* ref );

    void onFeatured( cocos2d::CCObject* ref );
};
