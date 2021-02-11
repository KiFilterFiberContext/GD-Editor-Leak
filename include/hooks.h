#pragma once


#include <vector>
#include "DrawGridLayer.h"
#include "LevelEditorLayer.h"
#include "EditLevelLayer.h"
#include "CCDirector.h"
#include "CCTransition.h"
#include "LevelSettingsLayer.h"
#include "EditorUI.h"
#include "CCMenu.h"
#include "GameManager.h"
#include "GameSoundManager.h"
#include "ZipUtils.h"
#include "ObjectToolbox.h"
#include "GameObject.h"
#include "UILayer.h"
#include "CreateParticlePopup.h"
#include "PauseLayer.h"
#include "GameToolbox.h"
#include "CCMenuItemSpriteExtra.h"
#include "ButtonSprite.h"
#include "LevelInfoLayer.h"
#include "ParticlePreviewLayer.h"
#include <iostream>

#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <MenuLayer.h>

// C signal handlers cannot access static/global variables because it's UB

/*
    auto pc = (std::uintptr_t) ctx->uc_mcontext.arm_pc;
    auto trap_ip = vm::TEST_BIT0( pc ) ? vm::CLEAR_BIT0( pc ) : pc;

    saber::logging::log( "GETTING MAP VALUE FROM: 0x%lx (MAP SIZE: %i)", trap_ip, hk_list.size( ) );

    try 
    {
        auto hk = hk_list.at( trap_ip ); 

        saber::logging::log( "HOOK DATA INFO:\n- Trap: 0x%lx\n- Registered: %i\n- Hook Addr: 0x%lx", 
            hk->trap_address, hk->registered, (std::uintptr_t) hk->function_hk );

        vm::write( hk->trap_address, hk->old_bytes );
        ctx->uc_mcontext.arm_pc = ( std::uintptr_t ) hk->function_hk;

        vm::write( trap_ip, vm::traps::TRAP_DATA_THUMB );
    }
    catch ( const std::out_of_range& e) 
    {
        saber::logging::log( "VALUE NOT FOUND" );
        exit(EXIT_FAILURE);
    }
*/

using namespace cocos2d;

bool (*old3)(LevelEditorLayer*, GJGameLevel*) = nullptr;
void (*old)(EditLevelLayer*, cocos2d::CCObject*) = nullptr;
void (*old2)(LevelEditorLayer*) = nullptr;

GameObject* (*old4)(int) = nullptr;

void onedit_hk( EditLevelLayer* ptr, cocos2d::CCObject* sender )
{
    if ( !ptr->inEditorLayer_ )
    {
        ptr->closeTextInputs( );
        // ptr->setKeypadEnabled( false ); 0x20C not 0x204

        ptr->inEditorLayer_ = true;
        GM->editorScene_ = 3;

        ptr->verifyLevelName();

        GSM->playBackgroundMusic( ptr->level->getAudioFileName(), false, true, false );

        auto dir = CCDirector::sharedDirector( );
        auto scene = CCTransitionFade::create( 
            0.5, 
            LevelEditorLayer::scene( ptr->level ) );

        dir->pushScene( scene );
    }
}

class MenuLayerExt : public MenuLayer 
{
public:
    void OnBlaze( cocos2d::CCObject* selector) 
    {
        auto app = cocos2d::CCApplication::sharedApplication( );
        auto url = "https://www.youtube.com/channel/UCcfPtuop90e_JzxPkiZ6Q5Q";

        app->openURL(url);
    }
};

bool menuinit_hk(MenuLayer* ptr)
{
    auto m = dynamic_cast< MenuLayer* >( ptr )->init( );

    auto pos = CCDirector::sharedDirector()->getWinSize( );

    auto menu = CCMenu::create( );
    auto btn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create( "Download Hentai", 0.35 ),
        nullptr,
        ptr,
        menu_selector(MenuLayerExt::OnBlaze)
    );
    menu->addChild( btn );
    menu->setPosition( (pos.width / 2) - 220, (pos.height / 2) - 72.5 );

    ptr->addChild( menu, 1000 );

    return m;
}

bool (*cctouch)(UILayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
bool cctouch_hk(UILayer* ptr, cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
    auto t = ptr->ccTouchBegan( pTouch, pEvent );
    auto pos = ptr->convertToNodeSpace( pTouch->getLocation( ) );

    if ( ptr->platformerMode_ )
        if ( pos.x > 200.0 || pos.y > 100.0 )
            GameManager::sharedState( )->playLayer->p1->pushButton(PlayerButton::Jump);

    return t;
}

bool (*touchend)(UILayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
void touchend_hk(UILayer* ptr, cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
    ptr->ccTouchEnded( pTouch, pEvent );
    if ( ptr->platformerMode_ )
        GameManager::sharedState( )->playLayer->p1->releaseButton(PlayerButton::Jump);
}

#include "CCMenuItemSpriteExtra.h"
#include "ButtonSprite.h"

#include "CCApplication.h"



#include "CCActionInterval.h"
#include "CCActionInstant.h"

void (*exitEdit)(PauseLayer*);
void exitEdit_hk( PauseLayer* ptr )
{
    auto pl = GM->playLayer;

    pl->stopRecording( );
    pl->stopAllActions();
    pl->unscheduleAllSelectors();
    GSM->stopBackgroundMusic();

     auto dir = cocos2d::CCDirector::sharedDirector();
    dir->getScheduler()->_fTimeScale = 1;

    pl->removeAllObjects();
    ptr->goEdit();
}
#include "include/core/debug.h"

void onmoregames_hk( MenuLayer* ptr, cocos2d::CCObject* selector )
{
    auto path = cocos2d::CCFileUtils::sharedFileUtils()->getWritablePath() + "crashdump.log";

    std::ifstream ifs( path );
    std::string content = "File not found.";

    std::stringstream ss;

    if ( ifs.good() )
    {
        std::string sLine;

        int i = 0;
        while ( i < 19 )
        {
            getline(ifs, sLine);
            ss << sLine << std::endl;
            i++;
        }
    }
    else 
        ss << "File not found.";

    ifs.close( );

    FLAlertLayer::create( nullptr, "Stack Trace", ss.str(), "Exit", nullptr, 450., true, 300. )->show( );
}


bool editorinit_hk( LevelEditorLayer* ptr, GJGameLevel* level )
{
    if( !dynamic_cast< GJBaseGameLayer* >( ptr )->init( ) )
        return false;

    ptr->quickUpdatePos_ = true;
    ptr->firstThing2 = 1;

    auto gm = GameManager::sharedState( );
    gm->inEditor_ = true;

    ptr->smoothFix = gm->getGameVariable( "0102" );

    ptr->ignoreDamage = gm->getGameVariable( "0009" );
    ptr->followPlayer = gm->getGameVariable( "0001" );
    ptr->drawTriggerBoxes = gm->getGameVariable( "0044" );
    ptr->debugDraw = gm->getGameVariable( "0045" );
    ptr->toggleEditorGrid = gm->getGameVariable( "0038" );
    ptr->effectLines = gm->getGameVariable( "0043" );
    ptr->editorGround = gm->getGameVariable( "0037" );
    ptr->toggleEffectDuration = gm->getGameVariable( "0058" );
    ptr->maxUndo = gm->getGameVariable( "0013" );
    ptr->hasColor_ = gm->getGameVariable( "0036" );
    ptr->toggleEditorBG = gm->getGameVariable( "0078" );
    ptr->hideGrid = gm->getGameVariable( "0079" );
    ptr->layerLocking = gm->getGameVariable( "0103" );
    ptr->recordOrder = gm->getGameVariable( "0104" );

    ptr->setObjectCount( 0 );
    GSM->stopBackgroundMusic( );

    ptr->level = level;
    gm->editorLayer = ptr;
    
    ptr->level->retain( );

    ptr->stickyObjectDict_ = CCDictionary::create( );
    ptr->stickyObjectDict_->retain( );

    ptr->someArray1 = CCArray::create( );
    ptr->someArray1->retain( );

    ptr->someArray2 = CCArray::create( );
    ptr->someArray2->retain( );

    ptr->someArray3 = CCArray::create( );
    ptr->someArray3->retain( );

    ptr->dict2 = CCDictionary::create( );
    ptr->dict2->retain( );

    ptr->dict3 = CCDictionary::create( );
    ptr->dict3->retain( );

    ptr->dict4 = CCDictionary::create( );
    ptr->dict4->retain( );

    ptr->someArray4 = CCArray::create( );
    ptr->someArray4->retain( );

    ptr->someArray5 = CCArray::create( );
    ptr->someArray5->retain( );

    ptr->someArray6 = CCArray::create( );
    ptr->someArray6->retain( );

    ptr->someArray7 = CCArray::create( );
    ptr->someArray7->retain( );

    ptr->someArray8 = CCArray::create( );
    ptr->someArray8->retain( );

    ptr->dict5 = CCDictionary::create( );
    ptr->dict5->retain( );

    ptr->someArray9 = CCArray::create( );
    ptr->someArray9->retain( );

    ptr->someArray10 = CCArray::create( );
    ptr->someArray10->retain( );

    ptr->arrayWithCap = CCArray::createWithCapacity( 100 );
    ptr->arrayWithCap->retain( );
    
    ptr->dict6 = CCDictionary::create( );
    ptr->dict6->retain( );

    ptr->someArray11 = CCArray::create( );
    ptr->someArray11->retain( );

    ptr->someArray12 = CCArray::create( );
    ptr->someArray12->retain( );

    ptr->dict7 = CCDictionary::create( );
    ptr->dict7->retain( );

    ptr->someArray13 = CCArray::create( );
    ptr->someArray13->retain( );

    ptr->redoList_ = CCArray::create( );
    ptr->redoList_->retain( );

    ptr->crashThing = CCArray::create( );
    ptr->crashThing->retain( );

    // new 2.2
    ptr->someArray14 = CCArray::create();
    ptr->someArray14->retain();

    ptr->someArray15 = CCArray::create();
    ptr->someArray15->retain();

    ptr->collisionBlocks_ = CCArray::create();
    ptr->collisionBlocks_->retain();

    // vectors :L

    ptr->objectVector_.reserve(9999);
    ptr->nestedArray1.reserve(9999);
    ptr->allGroupsToggled.reserve(9999);
    ptr->lockedLayersList_.reserve(9999);
    ptr->toggledGroups.reserve(9999);

    ptr->other1.reserve(9999);
    ptr->other2.reserve(9999);
    ptr->other4.reserve(9999);
    ptr->other3.reserve(9999);
    ptr->other5.reserve(9999);
    ptr->groupPreviewV.reserve(9999);

    for ( int i = 0; i < 9999; i++ )
    {
        ptr->objectVector_[i] = nullptr;
        ptr->nestedArray1[i] = nullptr;

        ptr->allGroupsToggled[i]= false;
        ptr->lockedLayersList_[i] = false;
        ptr->toggledGroups[i] = 0;

        ptr->other1[i] = false;
        ptr->other2[i] = false;
        ptr->other3[i] = false;
        ptr->other4[i] = nullptr;
        ptr->other5[i] = nullptr;
        ptr->groupPreviewV[i] = 0.0;
    }

    // continue
    ptr->obb2d = OBB2D::create( CCPoint( 1, 1 ), 1.0, 1.0, 0.0 ); 
    ptr->obb2d->retain( );

    ptr->drawNodes_ = new int[ 0xC80 ]; 

    dynamic_cast< GJBaseGameLayer* >( ptr )->setupLayers( );

    ptr->drawGridLayer = DrawGridLayer::create( ptr->gameLayer_, ptr );
    ptr->gameLayer_->addChild( ptr->drawGridLayer, gm->getGameVariable("0039") ? 99 : -100 );

    ptr->p1 = PlayerObject::create( 
        gm->playerFrame2 - gm->playerFrame1,
        gm->shipFrame2 - gm->shipFrame1,
        ptr->gameLayer_ );

    auto prim_color = gm->colorForIdx( gm->primaryColorID_2 - gm->primaryColorID_1 );
    auto secondary_color = gm->colorForIdx( gm->secondaryColorID_2 - gm->secondaryColorID_1 );

    ptr->p1->setColor( prim_color );
    ptr->p1->setSecondColor( secondary_color );
    ptr->p1->updateGlowColor( );

    ptr->batchNodePlayer_->addChild( ptr->p1, 10 );
    ptr->p1->field304 = 1;

    ptr->p1->setVisible( false );

    ptr->p2 = PlayerObject::create(
        gm->playerFrame2 - gm->playerFrame1,
        gm->shipFrame2 - gm->shipFrame1,
        ptr->gameLayer_ );

    ptr->p2->setColor( secondary_color );
    ptr->p2->setSecondColor( prim_color );
    ptr->p2->updateGlowColor( );
    ptr->p2->retain();

    ptr->p2->field6f8 = 1;
    ptr->p2->field304 = 2;
    ptr->p2->setOpacity( 0 );

    ptr->dCross = CCSprite::createWithSpriteFrameName( "d_cross_01_001.png" );

    ptr->batchNode_->addChild( ptr->dCross, 10 );
    ptr->dCross->setColor( ccc3(255, 255, 255) );
    ptr->dCross->setVisible( false ); // false
    ptr->dCross->setScale( 0.7 );
    
    // LOGD("LEVEL STRING: %s", (char*) ptr->level->levelString_);
    std::string a = ZipUtils::decompressString( std::string( (char*) ptr->level->levelString_ ), false, 11 );
    ptr->oldLevelString_ = new std::string( a );

    ptr->createObjectsFromSetup( a );

    dynamic_cast< GJBaseGameLayer* >( ptr )->createTextLayers( );

    if( gm->getGameVariable( "0066" ) )
        dynamic_cast< GJBaseGameLayer* >( ptr )->enableHighCapacityMode( );

    if( !ptr->settingsObject_ )
    {
        ptr->settingsObject_ = LevelSettingsObject::create( );
        ptr->settingsObject_->gameLevel = ptr->level;

        ptr->settingsObject_->retain( );
    } 

    auto c_action1 = ptr->settingsObject_->effectManager->getColorAction( 0x3ED );
    c_action1->thing1 = 0;
    c_action1->thing5 = 1;

    auto c_action2 = ptr->settingsObject_->effectManager->getColorAction( 0x3EE );
    c_action2->thing1 = 0;
    c_action2->thing5 = 1;

    ptr->editorUI = EditorUI::create( ptr );
    ptr->addChild( ptr->editorUI, 100 );

    ptr->createGroundLayer( );
    ptr->drawGridLayer->updateTimeMarkers( );
    ptr->createBackground( );

    ptr->editorUI->updateSlider();
    ptr->updateGroundWidth();

    dynamic_cast< GJBaseGameLayer* >( ptr )->resetGroupCounters( false );
    ptr->sortStickyGroups( );

    ptr->levelSettingsUpdated( );
    // ptr->updateEditorMode( );

    ptr->schedule( schedule_selector( LevelEditorLayer::updateVisibility ), 0.05 );
    ptr->schedule( schedule_selector( LevelEditorLayer::updateGround ) );

    ptr->firstThing2 = 0;

    return true;
}

#include <cstdlib>

inline long mid_num(const std::string& s) {
    return std::strtol(&s[s.find('_') + 1], nullptr, 10);
}

CreateMenuItem* gameobjcreate_hk( EditorUI* ptr, int key, int btn_type )
{
    saber::logging::log("ID: %i", key);
    return ptr->getCreateBtn( 1, btn_type );
}

bool isGauntlet = true;

#include "CCSpriteFrameCache.h"

bool spritecachename_hk( CCSprite* ptr, const char* s )
{
    saber::logging::log("SPRITE: %s", s );

/*
    if ( !strcmp( s, "pixelb_03_01_color_001.png" ) )
        return ptr->initWithSpriteFrameName( "pixelb_03_01_001.png" );

    if ( !strcmp( s, "pixelb_03_02_color_001.png" ) )
        return ptr->initWithSpriteFrameName( "pixelb_03_02_001.png" );

    if ( !strcmp( s, "pixelart_045_color_001.png" ) )
        return ptr->initWithSpriteFrameName( "pixelart_045_001.png" );

    if ( !strcmp( s, "pixelart_016_color_001.png" ) )
        return ptr->initWithSpriteFrameName( "pixelart_016_001.png" );

    if ( !strcmp( s, "pixelart_044_color_001.png" ) )
        return ptr->initWithSpriteFrameName( "pixelart_044_001.png" );

    if( !strcmp( s, "GJ_fullBtn_001.png" )  )
        return ptr->initWithSpriteFrameName( "GJ_creatorBtn_001.png" );
    
    if( !strcmp( s, "GJ_freeStuffBtn_001.png" )  )
        return ptr->initWithSpriteFrameName( "GJ_dailyRewardBtn_001.png" );

    if( !strcmp( s, "GJ_freeLevelsBtn_001.png" )  )
        return ptr->initWithSpriteFrameName( "GJ_moreGamesBtn_001.png" );

    if ( !strcmp( s, "GJ_gauntletsBtn_001.png" ) )
    {
        if( !isGauntlet )
        {
            isGauntlet = true;
            return ptr->initWithSpriteFrameName( "GJ_versusBtn_001.png" );
        }
        {
            isGauntlet = false;
            return ptr->initWithSpriteFrameName( "GJ_gauntletsBtn_001.png" );
        }
    }
*/
    return ptr->initWithSpriteFrameName( s );
}

bool (*unlocked)(void*, int, int);
bool unlocked_hk(void* ptr, int a1, int a2)
{
    return true;
}

const char* (*loading)(cocos2d::CCLayer*);
const char* loading_hk( CCLayer* ptr )
{
    GM->setGameVariable( "0115", true ); // FPS Label
    GM->setGameVariable( "0109", true ); // PlayLayer infoLabel
    // GM->setHasRatingPower( 2 );
    
    return "Mod developed by Blaze";
}

void (*dict)( CCDictionary*, CCObject*, int);
void dict_hk( cocos2d::CCDictionary* d, CCObject* obj, int key )
{
    switch( key )
    {
    case 0x7DF: // add if statement for string check
        return dict( d, CCString::create( "edit_eRotateBtn_001.png" ), key );
        break;

    case 0x814:
        return dict( d, CCString::create( "edit_eAdvRandomBtn_001.png" ), key );
        break;

    case 0x7E0:
        return dict( d, CCString::create( "edit_eGuideBtn_001.png" ), key );
        break;

    case 0xA8D:
        return dict( d, CCString::create( "edit_ePauseMoverBtn_001.png" ), key );
        break;

    case 0x80E:
        return dict( d, CCString::create( "edit_eEdgeBtn_001.png" ), key );
        break;

    default:

        dict( d, obj, key );
        break;
    }
}

void (*ISetup)(PauseLayer*);
void pausesetup_hk( PauseLayer* ptr )
{
    ptr->customSetup( );

    auto menu = CCMenu::create( );

    auto size = CCDirector::sharedDirector()->getWinSize();
    auto bottom = CCDirector::sharedDirector()->getScreenBottom();

    ptr->createToggleButton(
        std::string("%"), 
        menu_selector(PauseLayer::onProgressBar), 
        false, menu, 
        CCPoint( (size.width / 2) + 160, bottom + 25. ) );
    ptr->addChild( menu );

    auto top = CCDirector::sharedDirector()->getScreenTop();
    auto right = CCDirector::sharedDirector()->getScreenRight();

    auto timeBtns = CCArray::create();

    auto slowBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create( "Slow", 0, 0, 0.65, false, "goldFont.fnt", "GJ_button_01.png", 30. ), nullptr,
        ptr,
        menu_selector(PauseLayerExt::onSlow) );
    menu->addChild( slowBtn );

    auto normBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create( "Normal", 0, 0, 0.45, false, "goldFont.fnt", "GJ_button_01.png", 30. ), nullptr,
        ptr,
        menu_selector(PauseLayerExt::onNorm) );
    menu->addChild( normBtn );

    auto fastBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create( "Fast", 0, 0, 0.65, false, "goldFont.fnt", "GJ_button_01.png", 30. ), nullptr,
        ptr,
        menu_selector(PauseLayerExt::onFast) );
    menu->addChild( fastBtn );

    timeBtns->addObject( fastBtn );
    timeBtns->addObject( normBtn );
    timeBtns->addObject( slowBtn );

    GameToolbox::alignItemsVertically( 
        timeBtns, 
        10, 
        menu->convertToNodeSpace( CCPoint( size.width - 75, size.height - 80 ) ) );

}

bool (*levelinfoinit)( LevelInfoLayer*, GJGameLevel*, bool );
bool levelinfoinit_hk( LevelInfoLayer* ptr, GJGameLevel* level, bool a3 )
{
    auto r = levelinfoinit( ptr, level, a3 );

    auto menu = CCMenu::create();
    ptr->addChild( menu, 100 );

    auto play = cocos2d::CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png");
    play->setScale( 0.7 );

    auto replayBtn = CCMenuItemSpriteExtra::create(
        play, nullptr,
        ptr,
        menu_selector(LevelInfoLayer::onPlayReplay) );
    menu->addChild( replayBtn );

    auto size = CCDirector::sharedDirector()->getWinSize();
    menu->setPosition( ( size.width / 2 ) + 100, ( size.height / 2 ) + 51 );

    return r;
}

#include "CreatorLayer.h"

bool (*world)( CreatorLayer* );
bool world_hk( CreatorLayer* ptr ) 
{
    auto r = ptr->init( );

    auto right = CCDirector::sharedDirector()->getScreenRight();
    auto top = CCDirector::sharedDirector()->getScreenTop();

    auto arr = CCSprite::createWithSpriteFrameName( "GJ_arrow_01_001.png" );
    arr->setFlipX(true);

    auto menu = CCMenu::create();
    auto worldBtn = CCMenuItemSpriteExtra::create(
        arr, nullptr,
        ptr,
        menu_selector(CreatorLayerExt::onWorld)
    );

    ptr->addChild( menu, 100 );
    menu->addChild( worldBtn );

    menu->setPosition( right - 50, top / 2 );
    return r;
}

#include "EditorPauseLayer.h"
void (*updateOptions)(EditorPauseLayer*, CCObject*);
void updateoptions_hk( EditorPauseLayer* self, CCObject* ref )
{
    if ( self->inEditor_ )
        return;

    auto gm = GameManager::sharedState();

    auto ptr = self->editor_;

    ptr->ignoreDamage = gm->getGameVariable( "0009" );
    ptr->followPlayer = gm->getGameVariable( "0001" );
    ptr->drawTriggerBoxes = gm->getGameVariable( "0044" );
    ptr->debugDraw = gm->getGameVariable( "0045" );
    ptr->toggleEditorGrid = gm->getGameVariable( "0038" );
    ptr->effectLines = gm->getGameVariable( "0043" );
    ptr->editorGround = gm->getGameVariable( "0037" );
    ptr->toggleEffectDuration = gm->getGameVariable( "0058" );
    ptr->maxUndo = gm->getGameVariable( "0013" );
    ptr->hasColor_ = gm->getGameVariable( "0036" );
    ptr->toggleEditorBG = gm->getGameVariable( "0078" );
    ptr->hideGrid = gm->getGameVariable( "0079" );
    ptr->layerLocking = gm->getGameVariable( "0103" );
    ptr->recordOrder = gm->getGameVariable( "0104" );

    if ( ptr->editorUI )
    {
        ptr->editorUI->updateGroupIDLabel( );
        ptr->editorUI->toggleStickyControls( gm->getGameVariable( "0097" ) );
    }

    if ( ptr->BGLayer )
        ptr->BGLayer->setVisible( ptr->toggleEditorBG ^ 1 );

    self->removeFromParentAndCleanup( true );
}

#include <map>

static const std::map<const char*, int> btnMapping = {
    { "edit_eShaderBtn_001.png", 2864 },
    { "edit_eShockWaveBtn_001.png", 2865 },
    { "edit_eShockLineBtn_001.png", 2866 },
    { "edit_eGlitchBtn_001.png", 2867 },
    { "edit_eChromaticBtn_001.png", 2868 },
    { "edit_eChromaticGlitchBtn_001.png", 2869 },
    { "edit_ePixelateBtn_001.png", 2870 },
    { "edit_eLensCircleBtn_001.png", 2871 },
    { "edit_eRadialBlurBtn_001.png", 2872 },
    { "edit_eMotionBlurBtn_001.png", 2873 },
    { "edit_eBulgeBtn_001.png", 2874 },
    { "edit_eGrayScaleBtn_001.png", 2875 },
    { "edit_eSepiaBtn_001.png", 2876 },
    { "edit_eInvertColorBtn_001.png", 2877 }
};

#include "ObjectToolbox.h"
#include "EditButtonBar.h"
#include "CreateMenuItem.h"

ObjectToolbox* (*toolbox)( );
ObjectToolbox* toolbox_hk( )
{
    // LOGD("HOW2");

    auto tb = toolbox( );

    for ( const auto [ texture, objectID ] : btnMapping )
    {
        tb->objectFrameNameDict_->setObject( CCString::create( texture ), std::string( texture ) );
        tb->objectIDFrameDict_->setObject( CCString::create( texture ), objectID );
    } 

    return tb;
}

CreateMenuItem* (*buttonBar)( EditorUI*, int, cocos2d::CCArray* );
CreateMenuItem* buttonBar_hk( EditorUI* editor, int id, cocos2d::CCArray* objectArray )
{
    for ( const auto [ texture, objectID ] : btnMapping )
        objectArray->addObject( editor->getCreateBtn( objectID, 4 ) );

    return editor->getCreateBtn( id, 4 );
}



void (*clippingRect)( GLint, GLint, GLsizei, GLsizei );
void clippingrect_hk( GLint x, GLint y, GLsizei width, GLsizei height )
{
    // LOGD( "SIZE: (%i, %i, %i, %i)", x, y, width, height );
    auto addr = ( void (*)(GLint, GLint, GLsizei, GLsizei ) ) vm::get_proc_addr("libcocos2dcpp.so", "glScissor");
    addr( x, y, 1000, 1000 );
}
