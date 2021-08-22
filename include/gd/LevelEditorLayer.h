#pragma once

#include "DrawGridLayer.h"
#include "GJGroundLayer.h"
#include "UndoObject.h"
#include "obb2d.h"
#include "EditorUI.h"
#include "GJBaseGameLayer.h"
#include "LevelSettingsDelegate.h"


// size 0x5E8
class LevelEditorLayer : public GJBaseGameLayer, LevelSettingsDelegate
{
public:
    bool ignoreDamage_; // 0x3FC
    bool followPlayer_;
    char drawTriggerBoxes_;
    char debugDraw_;
    char toggleEditorGrid_;
    char hideGrid_;
    char effectLines_;
    char editorGround_;
    char effectDuration_;
    char maxUndo_;
    char toggleEditorBG_;
    char toggleEditorBG2_;
    bool layerLocking_;
    bool recordOrder_;
    bool previewParticles_;
    bool byte40B;
    bool smoothFix_;
    bool byte40D;
    bool byte40E;
    bool field_40F;
    bool dword410;
    bool toggleCollisionBlock_;
    char field_415;
    char field_416;
    char field_417;
    cocos2d::CCArray* someArray1;
    cocos2d::CCArray* someArray2;
    cocos2d::CCDictionary* stickyGroupDict_;
    cocos2d::CCArray* stickyGroups_;
    cocos2d::CCArray* someArray3;
    cocos2d::CCArray* someArray5;
    cocos2d::CCArray* colorObjects_;
    cocos2d::CCArray* someArray7;
    cocos2d::CCArray* someArray8;
    cocos2d::CCArray* someArray12;
    cocos2d::CCArray* someArray14;
    cocos2d::CCArray* crashThing;
    cocos2d::CCDictionary* dict5;
    cocos2d::CCArray* enabledGroups_;
    GameObject* pasteObject_;
    cocos2d::CCDictionary* dict6;
    cocos2d::CCArray* someArray11;
    int byte45C;
    int coinCountEnc_;
    int coinCountRand_;
    int coinCount_;
    bool dirtTrigger1_;
    bool dirtTrigger2_;
    bool dirtTrigger3_;
    bool dirtTrigger4_;
    bool dirtTrigger5_;
    char field_471;
    char field_472;
    char field_473;
    cocos2d::CCArray* someArray9;
    int dword478;
    cocos2d::CCArray* someArray10;
    char byte480;
    char field_481;
    char field_482;
    char field_483;
    cocos2d::CCDictionary* dict3;
    cocos2d::CCDictionary* dict4;
    bool editorInit_;
    char byte48D;
    char field_48E;
    char field_48F;
    char dword490;
    int groupIDFilter_;
    GameObject* startPosObject_; // StartPosObject*
    int dword49C;
    OBB2D* obb2d2_;
    float dword4A4;
    cocos2d::CCSprite* dCross_;
    int dword4AC;
    int dword4B0;
    int dword4B4;
    bool byte4B8;
    bool objectsOverlap_;
    bool field_4BA;
    bool field_4BB;
    GameObject* modeObject_;
    GameObject* nextMode_;
    EditorUI* editorUI_;
    cocos2d::CCSprite* BGLayer_;
    cocos2d::CCSprite* FGLayer_; // background2
    cocos2d::CCSprite* FG2Layer_;
    cocos2d::CCArray* undoList_;
    cocos2d::CCArray* redoList_;
    cocos2d::CCPoint cocos2d__ccpoint4DC;
    int objectCountEnc_;
    int objectCountRand_;
    int objectCount_;
    DrawGridLayer* gridLayer_;
    GJGameLevel* gameLevel_;
    int playerState_;
    int dword4FC;
    int dword500;
    cocos2d::CCDictionary* dict7;
    bool byte508;
    bool editorColorMode_;
    bool field_50A;
    bool field_50B;
    GJGroundLayer* GLayer_;
    std::string* levelString_;
    int* weirdAlloc;
    std::vector<GameObject*> objectVector_;
    std::vector<GameObject*> other5;
    std::vector<cocos2d::CCArray*> nestedObjects_;
    cocos2d::CCDictionary* triggerGroupDict_;
    std::vector<cocos2d::CCArray*> triggerGroups_;
    int field_54C;
    std::vector<bool> other3;
    std::vector<bool> groupsToggled_;
    std::vector<bool> lockedLayers_;
    std::vector<bool> blendObjects_; // other2
    std::vector<bool> blendColors_; // other1
    std::vector<uint8_t> toggledGroups_;
    std::vector<float> previewGroups_;
    int qword5D0;
    cocos2d::CCArray* someArray4;
    char byte5DC;
    char field_5DD;
    char field_5DE;
    char field_5DF;
    int playback_;
    float BGMusicTimeMilli_; // 0x5E4
    
public:
    LevelEditorLayer();
    virtual ~LevelEditorLayer();

    static LevelEditorLayer* create( GJGameLevel* level );
    static cocos2d::CCScene* scene( GJGameLevel* level );
    
    void updateOptions( );
    void setObjectCount( int count );

    void createObjectsFromSetup( std::string setup );
    void resetToggledGroups( );

    void updateEditorMode( );


    void createGroundLayer( );
    void createBackground( );
    void createBackground2( );

    void sortStickyGroups( );

    void updateVisibility( float a1 );
    void updateGround( float a1 );

    bool shouldBlend( int id );

    void updateGroundWidth();

    void addSpecial( GameObject* gameObj );
    void addToUndoList( UndoObject* undoObj, bool add );
    
    virtual void update( float );
    virtual void draw( void );
    virtual void updateColor( cocos2d::_ccColor3B, float, int, bool, float, cocos2d::_ccColor3B, int, bool, int, GameObject* );
    virtual void flipGravity( PlayerObject*, bool, bool );
    virtual void calculateColorValues( GameObject*, GameObject*, int, float, ColorActionSprite*, GJEffectManager* );
    virtual void addToGroup( GameObject*, int, bool );
    virtual void timeForXPos( float, int, bool );
    virtual float xPosForTime( float );
    virtual void updateStaticCameraPosToGroup( int, bool, bool, float, int, float );
    virtual void updateStaticCameraPos( cocos2d::CCPoint, bool, bool, float, int, float );
    virtual void exitStaticCamera( bool, bool, float, int, float );
    virtual bool playerReversedDirection( GameObject* );
    virtual cocos2d::CCParticleSystemQuad* createCustomParticle( std::string );
    virtual cocos2d::CCParticleSystemQuad* claimCustomParticle( std::string, int, int );
    virtual void unclaimCustomParticle( std::string, cocos2d::CCParticleSystemQuad* );
    virtual void levelSettingsUpdated( void );
};
