#pragma once

#include "CCNode.h"
#include "GManager.h"
#include "MenuLayer.h"
#include "GameRateDelegate.h"
#include "GJBaseGameLayer.h"
#include "LevelEditorLayer.h"

class LevelSelectLayer;
class GJShopLayer;
class DailyLevelPage;

enum IconType
{
    Player,
    Ship,
    Ball,
    Bird,
    Dart,
    Robot,
    Swing,
};

enum LastGameScene
{
    Menu,
    Creator,
    MyLevels,
    Info,
    LevelBrowser = 7,
    WorldSelect = 9,
    SecretLayer2 = 12,
};

class __attribute__( (packed, aligned( 4 )) ) GameManager : public GManager
{
public:
    bool doingQuickSave_;   // 0xFE
    cocos2d::CCDictionary* animNameDict_;
    cocos2d::CCDictionary* animColorNameDict_;
    cocos2d::CCDictionary* animDurationDict_;
    cocos2d::CCDictionary* animTypeDict_;
    bool fullScreen_;
    bool usingFullScreen_;
    bool isLoading_;
    uint8_t byte113;
    uint8_t byte114;
    cocos2d::CCDictionary* valueKeeper_;
    cocos2d::CCDictionary* unlockValueKeeper_;
    cocos2d::CCDictionary* customObjDict_;
    uint8_t gap124[ 4 ];
    double adTimer_;
    double cacheAdTimer_;
    bool didShowInterstitial_;
    uint8_t gap139[ 7 ];
    double videoAdTime_;
    int dword148;
    int dword14C;
    bool didLoad_;
    bool didSyncAchievement_;
    std::string editorCopyString_;
    GJBaseGameLayer* playLayer_;
    void* editorLayer_;
    LevelSelectLayer* levelSelectLayer_;
    MenuLayer* menuLayer_;
    bool mainMenuActive_;
    void* premiumPopup_;
    bool firstSetup_;
    bool showedMenu_;
    uint8_t byte172;
    uint8_t byte173;
    std::string playerUDID_;
    std::string playerName_;
    bool playerScoreValid_;
    int playerUserIDRandSum_;
    int playerUserIDRand_;
    int playerUserID_;
    float bgVolume_;
    float effectsVolume_;
    float volume_;
    uint8_t didRateGame_;
    bool didLikeFB_;
    bool didFollowTwitter_;
    bool didSubYT_;
    bool didFollowTwitch_;
    uint8_t didJoinDiscord_;
    double followTime_;
    bool didPausedBGMusic_;
    uint8_t wasHigh_;
    uint8_t editMode_;
    LastGameScene lastScene_;
    LastGameScene lastScene2_;
    bool returnToSearch_;
    int playerFrameRandSum_;
    int playerFrameRand_;
    int playerFrame_;
    int playerShipRandSum_;
    int playerShipRand_;
    int playerShip_;
    int playerBallRandSum_;
    int playerBallRand_;
    int playerBall_;
    int playerBirdRandSum_;
    int playerBirdRand_;
    int playerBird_;
    int playerDartRandSum_;
    int playerDartRand_;
    int playerDart_;
    int playerRobotRandSum_;
    int playerRobotRand_;
    int playerRobot_;
    int playerSpiderRandSum_;
    int playerSpiderRand_;
    int playerSpider_;
    int playerSwingRandSum_;
    int playerSwingRand_;
    int playerSwing_;
    int playerColorRandSum_;
    int playerColorRand_;
    int playerColor_;
    int playerColor2RandSum_;
    int playerColor2Rand_;
    int playerColor2_;
    int playerStreakRandSum_;
    int playerStreakRand_;
    int playerStreak_;
    int playerDeathEffectRandSum_;
    int playerDeathEffectRand_;
    int playerDeathEffect_;
    int playerJetpackRandSum_;
    int playerJetpackRand_;
    int playerJetpack_;
    int encodedSecretNumber_;
    int secretNumber_;
    int secretNumRandSum_;
    int secretNumRand_;
    bool playerGlow_;
    IconType playerIconType_;
    bool didSetupEveryplay_;
    uint8_t showSongMarkers_;
    uint8_t showBPMMarkers_;
    uint8_t recordGameplay_;
    uint8_t showProgressBar_;
    bool perfMode_;
    bool commentSortRecent_;
    uint8_t clickedGarage_;
    uint8_t clickedEditor_;
    uint8_t clickedName_;
    uint8_t clickedPractice_;
    uint8_t showedEditorGuide_;
    uint8_t showedRateDiffDialog_;
    uint8_t showedRateStarDialog_;
    bool showedLowDetailDialog_;
    GameRateDelegate* rateDelegate_;
    int lastLevelID_;
    uint8_t gap284[ 4 ];
    int lastCustomColorIdx_;
    int dword28C;
    int lastGroupID_;
    int bgTexture_;
    int fgTexture_;
    int GTexture_;
    int loadedFontIdx_;
    int dword2A4;
    int totalAttemptsShadow_;
    int totalAttempts_;
    int bootups_;
    bool hasRatedGame_;
    uint8_t didPlayGame_;
    bool isResetting_;
    uint8_t showingPromo_;
    bool testSmoothFix_;
    int ratingPowerRandSum_;
    int ratingPowerRand_;
    int ratingPower_;
    bool getLevelSaveData_;
    int resolution_;
    int texQuality_;
    uint8_t byte2D4;
    DailyLevelPage* dailyLevelPage_;
    uint8_t byte2DC;
    uint8_t gap2DD[ 2 ];
    char field_2DF;
    int field_2E0;
    int lastPage_;
    GJShopLayer* shopLayer_;
    char field_2EC;
    int videoReward_;
    uint8_t byte2F4;
    float deltaTime_;
    float customFPSTarget_;
    uint8_t byte300;
    int customMenuSongID_;
    int customPracticeSongID_;

public:
    GameManager();
    virtual ~GameManager();

    static GameManager* sharedState( );

    bool getGameVariable( const char* g_var );
    void setGameVariable( const char* g_var, bool toggle );

    bool hasRatingPower( );
    void setHasRatingPower( int ratingPower );

    void addGameAnimation( int animationID, int animationType, float duration, std::string animationName, std::string animationColorName );

    cocos2d::ccColor3B colorForIdx( int id ); 
};

#define GM GameManager::sharedState()
#define PL GameManager::sharedState()->playLayer_
