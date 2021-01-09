#pragma once

#include "GJGameLevel.h"
#include "GJBaseGameLayer.h"
#include "CCScene.h"
#include "DrawGridLayer.h"
#include "PlayerObject.h"
#include "GameObject.h"
#include "LevelSettingsObject.h"
#include "EditorUI.h"
#include "obb2d.h"
#include "GameObject.h"
#include "ZipUtils.h"
#include "UndoObject.h"
#include "GJGroundLayer.h"

class DrawGridLayer;

class LevelEditorLayer : public GJBaseGameLayer 
{
public:
    unsigned char _pad10[ 0x18 ]; // 0x3E4

    bool ignoreDamage; // 0x3FC
    bool followPlayer; // 0x3FD
    bool drawTriggerBoxes; // 0x3FE
    bool debugDraw; // 0x3FF
    bool toggleEditorGrid; // 0x400
    bool hideGrid; // 0x401
    bool effectLines; // 0x402
    bool editorGround; // 0x403
    bool toggleEffectDuration; // 0x404
    bool maxUndo; // 0x405
    bool toggleEditorBG; // 0x406
    bool layerLocking; // 0x407
    bool recordOrder; // 0x408
    bool previewParticles; // 0x409
    bool _unk2; // 0x40A
    bool smoothFix; // 0x40B

    uint32_t _unk20; // 0x40C
    uint32_t _unk21; // 0x410
    uint32_t _unk22; // 0x414

    cocos2d::CCArray* someArray1; // 0x418
    cocos2d::CCArray* someArray2; // 0x41C
    cocos2d::CCDictionary* stickyObjectDict_; // 0x420

    void* _unk3; // 0x424

    cocos2d::CCArray* someArray3; // 0x428
    cocos2d::CCArray* someArray5; // 0x42C
    cocos2d::CCArray* someArray6; // 0x430
    cocos2d::CCArray* someArray7; // 0x434
    cocos2d::CCArray* someArray8; // 0x438
    cocos2d::CCArray* someArray12; // 0x43C

    cocos2d::CCArray* someArray14; // 0x440
    cocos2d::CCArray* crashThing; // 0x444

    cocos2d::CCDictionary* dict5; // 0x448
    cocos2d::CCArray* arrayWithCap; // 0x44C
    GameObject* pasteObject_; // 0x450 
    cocos2d::CCDictionary* dict6; // 0x454
    cocos2d::CCArray* someArray11; // 0x458

    uint32_t _unk23; // 0x45C
    int coinCountRand_; // 0x460
    int coinCountSeed_; // 0x464
    int coinCount_; // 0x468 
    bool dirtTrigger1; // 0x46C
    bool dirtTrigger2; // 0x46D
    bool dirtTrigger3; // 0x46E
    bool dirtTrigger4; // 0x46F
    bool dirtTrigger5; // 0x470

    uint8_t _unk26; // 0x471
    uint8_t _unk27; // 0x472
    uint8_t _unk28; // 0x473

    cocos2d::CCArray* someArray9; // 0x474
    void* _unk6; // 0x478
    cocos2d::CCArray* someArray10; // 0x47C
    void* _unk7; // 0x480
    cocos2d::CCDictionary* dict3; // 0x484
    cocos2d::CCDictionary* dict4; // 0x488
    uint8_t firstThing2; // 0x48C

    uint8_t _unk14; // 0x48D
    uint32_t _unk15; // 0x48E
    uint32_t _unk16; // 0x492
    uint8_t _unk17; // 0x496
    uint8_t _unk18; // 0x497

    GameObject* startPosObject; // 0x498 
    OBB2D* obb2d; // 0x4A0

    uint32_t _unk29; // 0x4A4
    cocos2d::CCSprite* dCross; // 0x4A8

    uint32_t _unk30; // 0x4AC
    uint32_t _unk31; // 0x4B0
    uint32_t _unk32; // 0x4B4
    uint32_t _unk33; // 0x4B8
    uint32_t _unk34; // 0x4BC
    uint32_t _unk35; // 0x4C0

    EditorUI* editorUI; // 0x4C4
    cocos2d::CCSprite* BGLayer; // 0x4C8
    cocos2d::CCArray* someArray13; // 0x4CC
    cocos2d::CCArray* redoList_; // 0x4D0

    void* _unk13; // 0x4D4
    void* _unk12; // 0x4D8
    int objCountRand_; // 0x4DC
    int objCountSeed_; // 0x4E0
    int objectCount; // 0x4E4
    DrawGridLayer* drawGridLayer; // 0x4E8
    GJGameLevel* level; // 0x4EC
    int IDCount; // 0x4F0
    void* _unk8; // 0x4F4
    void* _unk9; // 0x4F8
    cocos2d::CCDictionary* dict7; // 0x4FC

    bool editorColor_; // 0x500
    bool hasColor_; // 0x501 
    bool _idk2[ 2 ]; // 0x502
    GJGroundLayer* groundLayer_; // 0x504
    std::string* oldLevelString_; // 0x508
    int* drawNodes_; // 0x50C  CCPoint**
    std::vector<GameObject*> objectVector_; // 0x510
    std::vector<GameObject*> other5; // 0x51C
    std::vector<cocos2d::CCArray*> nestedArray1; // 0x528
    cocos2d::CCDictionary* dict2; // 0x534
    std::vector<cocos2d::CCArray*> other4; // 0x538
    unsigned char _pad36[ 0x4 ]; // 0x53C
    std::vector<bool> other3; // 0x548
    std::vector<bool> allGroupsToggled; // 0x55C
    std::vector<bool> lockedLayersList_; // 0x570
    std::vector<bool> other2; // 0x584
    std::vector<bool> other1; // 0x598
    std::vector<uint8_t> toggledGroups; // 0x5AC
    std::vector<float> groupPreviewV; // 0x5B8
    unsigned char _pad5bc[ 0xc ]; // 0x5BC
    cocos2d::CCArray* someArray4; // 0x5D0
    
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
    void sortStickyGroups( );

    void updateVisibility( float a1 );
    void updateGround( float a1 );

    bool shouldBlend( int id );

    void updateGroundWidth();

    void addSpecial( GameObject* gameObj );
    void addToUndoList( UndoObject* undoObj, bool add );
    
    // padding 
    virtual void _placeholder0( );
    virtual void _placeholder1( );
    virtual void _placeholder2( );
    virtual void _placeholder3( );
    virtual void _placeholder4( );
    virtual void _placeholder5( );
    virtual void _placeholder6( );
    virtual void _placeholder7( );
    virtual void _placeholder8( );
    virtual void _placeholder9( );
    virtual void _placeholder10( );
    virtual void _placeholder11( );
    virtual void _placeholder12( );
    virtual void _placeholder13( );
    virtual void _placeholder14( );
    virtual void _placeholder15( );
    virtual void _placeholder16( );
    virtual void _placeholder17( );
    virtual void _placeholder18( );
    virtual void _placeholder19( );
    virtual void _placeholder20( );
    virtual void _placeholder21( );
    virtual void _placeholder22( );
    virtual void _placeholder23( );
    virtual void _placeholder24( );
    virtual void _placeholder25( );
    virtual void _placeholder26( );
    virtual void _placeholder27( );
    virtual void _placeholder28( );
    virtual void _placeholder29( );
    virtual void _placeholder30( );
    virtual void _placeholder31( );

    virtual void levelSettingsUpdated( ); // 0x2A4
};