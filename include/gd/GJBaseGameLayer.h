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
#include "CCSpriteBatchNode.h"
#include "UndoObject.h"

class GJBaseGameLayer : public cocos2d::CCLayer
{
public:
    uint8_t _pad[ 0x14 ];
    int dword130;
    int dword134;
    int dword138;
    int dword13C;
    int dword140;
    OBB2D *obb2; // 0x144
    GJEffectManager *colorManager_; // 0xx148
    cocos2d::CCLayer *gameLayer_; // 0x14C
    bool gap150[56];
    cocos2d::CCSpriteBatchNode *batchNodeAddTop_; // 0x188
    bool gap18C[32];
    cocos2d::CCSpriteBatchNode *batchNode_; // 0x1AC
    cocos2d::CCSpriteBatchNode *batchNodeAdd_; // 0x1B0
    cocos2d::CCSpriteBatchNode *effectBatchNodeAddGlow_; // 0x1B4
    bool gap1B8[28];
    cocos2d::CCSpriteBatchNode *batchNodePlayer_; // 0x1D4
    cocos2d::CCSpriteBatchNode *batchNodeAddPlayer_; // 0x1D8
    bool gap1DC[4];
    cocos2d::CCSpriteBatchNode *batchNodeAddMid_; // 0x1E0
    cocos2d::CCSpriteBatchNode *batchNodeBottom_; // 0x1E4
    cocos2d::CCSpriteBatchNode *batchNodeAddBottom_; // 0x1E8
    cocos2d::CCSpriteBatchNode *batchNodeAddBottomGlow_; // 0x1EC
    bool gap1F0[12];
    cocos2d::CCSpriteBatchNode *effectBatchNode_; // 0x1FC
    cocos2d::CCSpriteBatchNode *effectBatchNodeAdd_; // 0x200
    bool gap204[8];
    cocos2d::CCSpriteBatchNode *batchNodeBottom2_; // 0x20C
    cocos2d::CCSpriteBatchNode *batchNodeAddBottom2_; // 0x210
    cocos2d::CCSpriteBatchNode *batchNodeAddBottom2Glow_; // 0x214
    bool gap218[88];
    cocos2d::CCSpriteBatchNode *batchNodeAddText_; // 0x270
    bool gap274[16];
    PlayerObject* p1; // 0x284
    PlayerObject* p2; // 0x288
    LevelSettingsObject* settingsObject_; // 0x28C
    uint32_t _pad290; // 0x290
    cocos2d::CCArray* allObjects_; // 0x294 of GameObject*
    cocos2d::CCArray* sections_; // 0x298
    unsigned char _pad3[ 0xac ]; // 0x29C
    bool quickUpdatePos_; // 0x348
    uint8_t _pad4[ 0x1f ]; // 0x349
    bool platformerMode_; // 0x368
    uint8_t _pad369[ 0x5b ]; // 0x369
    cocos2d::CCArray* collisionBlocks_; // 0x3C4
    cocos2d::CCArray* someArray15; // 0x3C8
    uint8_t _pad3cc[ 0x14 ]; // 0x3CC
    cocos2d::CCArray* actionArray_; // 0x3E0

public:
    GJBaseGameLayer();
    virtual ~GJBaseGameLayer();

    void releaseButton( int a1, bool b2 );
    void pushButton( int a1, bool b2 );

    void updateTimeWarp( float dt );

    void setupLayers( );
    void createTextLayers( );
    void enableHighCapacityMode( );
    void resetGroupCounters( bool reset );

    GameObject* parentForZLayer( int a1, bool a2, int a3 );

    virtual void __unknown19( );
    virtual void __unknown20( );
    virtual void __unknown21( );
    virtual void __unknown22( );
    virtual void __unknown23( );
    virtual void __unknown24( );
    virtual void __unknown25( );
    virtual void __unknown26( );
    virtual void __unknown27( );
    virtual void __unknown28( );
    virtual void __unknown29( );

    virtual void addToSection( GameObject* g ); // 0x250
}; 