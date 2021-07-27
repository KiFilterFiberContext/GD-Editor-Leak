#pragma once

#include "obb2d.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "LevelSettingsObject.h"

#include "CCSpriteBatchNode.h"
#include "CCLayer.h"
#include "CCScene.h"
#include "TriggerEffectDelegate.h"
#include "GameObject.h"
#include "GJEffectManager.h"
#include "particle_nodes/CCParticleSystemQuad.h"

// size 0x3F8
class __attribute__( (aligned( 4 )) ) GJBaseGameLayer : public cocos2d::CCLayer, TriggerEffectDelegate
{
public:
    cocos2d::CCNode* dword130;  // 0x130
    cocos2d::CCNode* dword134;
    cocos2d::CCNode* dword138;
    cocos2d::CCNode* dword13C;
    cocos2d::CCNode* dword140;
    OBB2D* obb2d_;
    GJEffectManager* colorManager_;
    cocos2d::CCLayer* gameLayer_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeTop3_;
    cocos2d::CCSpriteBatchNode* field_154;
    cocos2d::CCSpriteBatchNode* field_158;
    cocos2d::CCSpriteBatchNode* batchNodeAddTop3_;
    cocos2d::CCSpriteBatchNode* batchNodeAddGlowTop3_;
    cocos2d::CCSpriteBatchNode* batchNodeAddTop4_;
    cocos2d::CCSpriteBatchNode* field_168;
    cocos2d::CCSpriteBatchNode* batchNodeTextAddTop3_;
    cocos2d::CCSpriteBatchNode* batchNodeTextTop2;
    cocos2d::CCSpriteBatchNode* effectBatchNodeAddTop3_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeTop2_;
    cocos2d::CCSpriteBatchNode* field_17C;
    cocos2d::CCSpriteBatchNode* field_180;
    cocos2d::CCSpriteBatchNode* batchNodeAddGlowTop2_;
    cocos2d::CCSpriteBatchNode* batchNodeAddTop_;
    cocos2d::CCSpriteBatchNode* batchNodeTop3_;
    cocos2d::CCSpriteBatchNode* field_190;
    cocos2d::CCSpriteBatchNode* batchNodeTextAddTop2_;
    cocos2d::CCSpriteBatchNode* batchNodeTextTop1_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeAddTop2_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeTop1_;
    cocos2d::CCSpriteBatchNode* field_1A4;
    cocos2d::CCSpriteBatchNode* field_1A8;
    cocos2d::CCSpriteBatchNode* batchNode_;
    cocos2d::CCSpriteBatchNode* batchNodeAdd_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeAddGlow_;
    cocos2d::CCSpriteBatchNode* field_1B8;
    cocos2d::CCSpriteBatchNode* batchNodeTextAddTop1_;
    cocos2d::CCSpriteBatchNode* batchNodeText_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeAddTop1_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeBot2_;
    cocos2d::CCSpriteBatchNode* field_1CC;
    cocos2d::CCSpriteBatchNode* field_1D0;
    cocos2d::CCSpriteBatchNode* batchNodePlayer_;
    cocos2d::CCSpriteBatchNode* batchNodeAddPlayer_;
    cocos2d::CCSpriteBatchNode* field_1DC;
    cocos2d::CCSpriteBatchNode* batchNodeAddMid_;
    cocos2d::CCSpriteBatchNode* batchNodeBottom_;
    cocos2d::CCSpriteBatchNode* batchNodeAddBottom_;
    cocos2d::CCSpriteBatchNode* batchNodeAddBottomGlow_;
    cocos2d::CCSpriteBatchNode* field_1F0;
    cocos2d::CCSpriteBatchNode* batchNodeAddText_;
    cocos2d::CCSpriteBatchNode* batchNodeTextBot2_;
    cocos2d::CCSpriteBatchNode* effectBatchNode_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeAdd_;
    cocos2d::CCSpriteBatchNode* field_204;
    cocos2d::CCSpriteBatchNode* field_208;
    cocos2d::CCSpriteBatchNode* batchNodeBottom2_;
    cocos2d::CCSpriteBatchNode* batchNodeAddBottom2_;
    cocos2d::CCSpriteBatchNode* batchNodeAddBottom2Glow_;
    cocos2d::CCSpriteBatchNode* field_218;
    cocos2d::CCSpriteBatchNode* batchNodeAddTextBot2_;
    cocos2d::CCSpriteBatchNode* batchNodeTextBot3_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeAddBot2_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeBot3_;
    cocos2d::CCSpriteBatchNode* field_22C;
    cocos2d::CCSpriteBatchNode* field_230;
    cocos2d::CCSpriteBatchNode* batchNodeAddBottom3_;
    cocos2d::CCSpriteBatchNode* batchNodeAddBottom3Glow_;
    cocos2d::CCSpriteBatchNode* batchNodeTop2_;
    cocos2d::CCSpriteBatchNode* field_240;
    cocos2d::CCSpriteBatchNode* batchNodeAddTextBot3_;
    cocos2d::CCSpriteBatchNode* BatchNodeTextBot4_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeAddBot3_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeBot4_;
    cocos2d::CCSpriteBatchNode* field_254;
    cocos2d::CCSpriteBatchNode* field_258;
    cocos2d::CCSpriteBatchNode* batchNodeAddBottom4_;
    cocos2d::CCSpriteBatchNode* batchNodeAddBottom4Glow_;
    cocos2d::CCSpriteBatchNode* batchNodeBottom3_;
    cocos2d::CCSpriteBatchNode* field_268;
    cocos2d::CCSpriteBatchNode* batchNodeAddTextBot5_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeAddTop4_;
    cocos2d::CCSpriteBatchNode* effectBatchNodeAddBot4_;
    cocos2d::CCSpriteBatchNode* batchNodeTextTop3_;
    cocos2d::CCSpriteBatchNode* field_27C;
    cocos2d::CCSpriteBatchNode* field_280;
    PlayerObject* player_;
    PlayerObject* player2_;
    LevelSettingsObject* levelSettings_;
    int field_290;
    cocos2d::CCArray* gameObjects;
    cocos2d::CCArray* sectionObjects_;
    cocos2d::CCArray* sections_;
    cocos2d::CCArray* collisionBlocks_;
    cocos2d::CCArray* spawnObjects_;
    cocos2d::CCArray* dword2A8;
    cocos2d::CCNode* dword2AC;
    std::vector<GameObject*> gameObjects1_;
    std::vector<GameObject*> disabledObjects_;
    std::vector<GameObject*> gameObjects3_;
    int maxGameObjects1_;
    int currentDisabledObject_;
    int maxGameObjects3_;
    int gameObjects1Index_;
    int maxDisabledObjects_;
    int gameObjects3Index_;
    cocos2d::CCDictionary* groupDict_;
    cocos2d::CCDictionary* staticGroupDict_;
    cocos2d::CCDictionary* optimizedGroupDict_;
    std::vector<cocos2d::CCArray*> groups_;
    std::vector<cocos2d::CCArray*> staticGroups_;
    std::vector<cocos2d::CCArray*> optimizedGroups_;
    cocos2d::CCNode* dword31C;
    cocos2d::CCArray* dword320;
    cocos2d::CCArray* moveActions_;
    cocos2d::CCDictionary* queuedLabels_;
    cocos2d::CCDictionary* dword32C;
    bool didUpdateNormalCapacity_;
    bool twoPlayer_;
    bool field_332;
    bool field_333;
    int activeEnterEffect_;
    bool hasActiveDualTouch_;
    char field_339;
    char field_33A;
    char field_33B;
    int clicks_;
    int field_340;
    int field_344;
    bool quickUpdatePos_;
    bool didUpdateColor_;
    uint8_t gap34A[ 10 ];
    float zoomDuration_;
    float zoom_;
    int zoomLevel_;
    float screenRotateDuration_;
    float screenRotate_;
    bool platformerMode_;
    cocos2d::CCPoint cameraOffset_;
    cocos2d::CCPoint cameraOffset2_;
    cocos2d::CCPoint field_37C;
    cocos2d::CCPoint field_384;
    cocos2d::CCPoint field_38C;
    bool field_394;
    bool field_395;
    bool field_396;
    bool field_397;
    int field_398;
    int field_39C;
    int field_3A0;
    int field_3A4;
    int field_3A8;
    int field_3AC;
    bool reversedDirection_;
    float timeWarp_;
    bool toggleStreakBlend_;
    char field_3B9;
    float field_3BC;
    float loadPosition_;
    GameObject* objectSection_;
    cocos2d::CCArray* portalTargets_;
    int maxParticles_;
    cocos2d::CCDictionary* particles_;
    cocos2d::CCDictionary* customParticles_;
    cocos2d::CCDictionary* customParticleSystems_;
    cocos2d::CCArray* particleSystems_;
    cocos2d::CCArray* actions_;
    int field_3E4;
    int field_3E8;
    float bgMusicTimeMiliseconds_;
    float songOffset_;
    float songXPos_;

public:
    GJBaseGameLayer();
    virtual ~GJBaseGameLayer();

    void releaseButton( int a1, bool b2 );
    void pushButton( int a1, bool b2 );

    void setupLayers( void );
    void createTextLayers( void );
    void enableHighCapacityMode( void );
    void resetGroupCounters( bool reset );

    GameObject* parentForZLayer( int a1, bool a2, int a3 );

    void tweenValue( float from, float to, int tag, std::string property_key, float duration, int action, float f_rate );

    virtual bool init( void );

    virtual void updateTweenAction( float, const char* );
    virtual void objectsCollided( int, int );
    virtual cocos2d::CCObject* createMoveCommand( cocos2d::CCPoint, int, float, int, float, bool, bool, bool, bool, float, float, int );
    virtual void updateColor( cocos2d::_ccColor3B, float, int, bool, float, int, int, bool, int, cocos2d::CCObject* );
    virtual void flipGravity( PlayerObject*, bool, bool );
    virtual void calculateColorValues( cocos2d::CCObject*, cocos2d::CCObject*, int, float, ColorActionSprite*, GJEffectManager* );
    virtual void toggleGroupTriggered( int, bool, int );
    virtual void spawnGroup( int, int );
    virtual void activateEndTrigger( int, bool, bool );
    virtual void activatePlayerControlTrigger( void );
    virtual void addToSection( GameObject* );
    virtual void addToGroup( GameObject*, int, bool );
    virtual void removeFromGroup( GameObject*, int );
    virtual void toggleGroundVisibility( bool );
    virtual void updateZoom( int, float, int, float );
    virtual void updateScreenRotation( int, float, int, float );
    virtual void updateCameraOffsetX( float, float, int, float );
    virtual void updateCameraOffsetY( float, float, int, float );
    virtual bool playerReversedDirection( GameObject* );
    virtual void reverseDirection( GameObject* );
    virtual void updateTimeWarp( float );
    virtual void playGravityEffect( bool );
    virtual cocos2d::CCParticleSystemQuad* createCustomParticle( std::string );
    virtual cocos2d::CCParticleSystemQuad* claimCustomParticle( std::string, int, int );
    virtual void unclaimCustomParticle( std::string, cocos2d::CCParticleSystemQuad* );
}; 