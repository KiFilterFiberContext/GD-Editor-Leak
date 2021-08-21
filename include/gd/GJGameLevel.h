#pragma once

#include "CCLayer.h"

// size 0x2F4
class GJGameLevel : public cocos2d::CCNode
{
public:
    cocos2d::CCDictionary* lastBuildSave_; // 0xF8
    int levelIDRand_;
    int levelIDEnc_;
    int levelID_;
    std::string levelName_;
    std::string levelDesc_;
    std::string* levelString_;
    std::string userName_;
    std::string recordString_;
    int dword11C;
    int dword120;
    int dword124;
    int userIDEnc_;
    int userIDRand_;
    int userID_;
    int accountIDEnc_;
    int accountIDRand_;
    int accountID_;
    int difficulty_;
    int audioTrack_;
    int songID_;
    int levelRev_;
    bool isUnlisted_;
    bool friendsOnly_;
    int objectCountEnc_;
    int objectCountRand_;
    int objectCount_;
    int levelOrder_;
    int ratings_;
    int ratingsSum_;
    int downloads_;
    bool isEditable_;
    bool isGauntlet_;
    bool isGauntlet2_;
    int wt_;
    int wt2_;
    bool lowDetailMode_;
    bool toggleLowDetail_;
    bool byte17E;
    bool byte17F;
    int isVerifiedEnc_;
    int isVerifiedRand_;
    bool isVerified_;
    bool isUploaded_;
    bool hasBeenModified_;
    int levelVersion_;
    int gameVersion_;
    int attemptsEnc_;
    int attemptsRand_;
    int attempts_;
    int jumpsEnc_;
    int jumpsRand_;
    int jumps_;
    int clicksEnc_;
    int clicksRand_;
    int clicks_;
    int attemptTimeEnc_;
    int attemptTimeRand_;
    int attemptTime_;
    int levelScoreSeed_;
    bool isChkValid_;
    bool anticheat_;
    int normPercent_;
    int normPercentRand_;
    int normPercentEnc_;
    int newNormPercentEnc_;
    int newNormPercentRand_;
    int newNormPercent_;
    int newNormPercent2Enc_;
    int newNormPercent2Rand_;
    int newNormPercent2_;
    int practicePercent_;
    int likes_;
    int dislikes_;
    int levelLength_;
    int featured_;
    int epic_;
    bool isHearted_;
    int levelFolder_;
    int dailyIDEnc_;
    int dailyIDRand_;
    int dailyID_;
    int demonEnc_;
    int demonRand_;
    int demon_;
    int demonDifficulty_;
    int starsEnc_;
    int starsRand_;
    int stars_;
    bool autoLevel_;
    int coins_;
    int coinsVerifiedEnc_;
    int coinsVerifiedRand_;
    int coinsVerified_;
    int passwordEnc_;
    int passwordRand_;
    int originalLevelEnc_;
    int originalLevelRand_;
    int originalLevel_;
    bool twoPlayerMode_;
    int failedPasswordAttempts_;
    int coin1VerifiedEnc_;
    int coin1VerifiedRand_;
    int coin1Verified_;
    int coin2VerifiedEnc_;
    int coin2VerifiedRand_;
    int coin2Verified_;
    int coin3VerifiedEnc_;
    int coin3VerifiedRand_;
    int coin3Verified_;
    int requiredStars_;
    bool showedStarWarning_;
    int starRatings_;
    int starRatingsSum_;
    int maxStarRatings_;
    int minStarRatings_;
    int demonVotes_;
    int rateStars_;
    bool rateFeature_;
    std::string rateUser_;
    bool dontSave_;
    bool isHidden_;
    int requiredCoins_;
    bool isUnlocked_;
    cocos2d::CCPoint lastCameraPos_;
    float lastEditorZoom;
    int lastBuildTab_;
    int lastBuildPage_;
    int lastBuildGroupID_;
    int levelType_;
    int M_ID;
    std::string tempName_;
    std::string capacityString_;
    bool highObjectCount_;
    bool byte2E9;
    std::string levelSeed_;
    int dword2F0;

    
public:
    GJGameLevel();
    virtual ~GJGameLevel();

    static GJGameLevel* create( );

    std::string getAudioFileName( void );

    virtual void encodeWithCoder( DS_Dictionary* dict );
    virtual bool canEncode( void );
    virtual bool init( void );
};
