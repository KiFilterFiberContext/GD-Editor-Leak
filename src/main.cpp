#include "photon_sdk.h"

#include "LoadingLayer.h"
#include "GameManager.h"
#include "LevelInfoLayer.h"
#include "CCMenuItemSpriteExtra.h"
#include "CCMenuItem.h"
#include "CCDirector.h"
#include "PlayLayer.h"

#include "LevelSearchLayer.h"
#include "SearchButton.h"
#include "extensions/network/HttpClient.h"
#include "GameLevelManager.h"
#include "EditLevelLayer.h"
#include "GameSoundManager.h"
#include "CCTransition.h"
#include "ZipUtils.h"

#include "ObjectToolbox.h"

using photon::core::softbp;

using photon::utils::debug_print;
using photon::utils::print;
using photon::utils::str_replace;


USING_NS_CC;
USING_NS_CC_EXT;

bool ex_callback( LoadingLayer* p, bool useDefault )
{
	auto gm = GameManager::sharedState( );

	gm->setGameVariable( "0109", true ); // info label
	gm->setGameVariable( "0115", true ); // fps label
	gm->setGameVariable( "0116", true ); // enable custom fps
	gm->setGameVariable( "0114", true ); // player option?
	gm->setGameVariable( "0045", true ); // debug draw
	gm->setGameVariable( "0053", false ); // more games
	
	gm->setHasRatingPower( 2 );

	return p->init( useDefault );
}

bool controller_callback( void* p )
{
	return false;
}

bool unlocked_gauntlet_callback( void* p, bool a )
{
	return true;
}

void (*onedit_ori)(EditLevelLayer*, CCObject*) = 0;
void onedit_callback( EditLevelLayer* p, CCObject* ref )
{
    if ( !p->isPlaying_ )
    {
        p->closeTextInputs( );

        p->isPlaying_ = true;
        GM->lastScene_ = LastGameScene::Info;

        p->verifyLevelName( );

        GSM->playBackgroundMusic( p->gameLevel_->getAudioFileName( ), false, true, false );

        auto dir = CCDirector::sharedDirector( );
        auto scene = CCTransitionFade::create(
            0.5,
            LevelEditorLayer::scene( p->gameLevel_ ) );

        dir->pushScene( scene ); // replaceScene fix ~EditLevelLayer
    }
}

GameObject* ( *gameobj_ori ) (int) = 0;
GameObject* gameobj_callback( int key )
{
    // debug_print( "key: %i\n", key );
    auto tb = ObjectToolbox::sharedState( )->intKeyToFrame( key );

    if ( strstr( tb, "gdh" ) != NULL
        || strstr( tb, "fireball" ) != NULL
        || strstr( tb, "fire_b" ) != NULL
        || strstr( tb, "gj22_anim" ) != NULL
        || strstr( tb, "pixel" ) != NULL
        || strstr( tb, "gjHand2" ) != NULL )
        return gameobj_ori( 1 );

    return gameobj_ori( key );
}

bool editor_callback( LevelEditorLayer* p, GJGameLevel* level )
{
	if ( !dynamic_cast< GJBaseGameLayer* >( p )->init( ) )
		return false;

	auto gm = GameManager::sharedState( );

	p->quickUpdatePos_ = true;
    p->editorInit_ = true;

	gm->editMode_ = true;

    gm->setGameVariable( "0036", false ); // temporary fix for color mode

	p->smoothFix_ = gm->getGameVariable( "0102" );
	p->updateOptions( );


	p->setObjectCount( 0 );
	GSM->stopBackgroundMusic( );

	p->gameLevel_ = level;
	gm->editorLayer_ = p;

	p->gameLevel_->retain( );

	p->stickyGroupDict_ = CCDictionary::create( );
	p->stickyGroupDict_->retain( );

    p->someArray1 = CCArray::create( );
    p->someArray1->retain( );

    p->someArray2 = CCArray::create( );
    p->someArray2->retain( );

    p->someArray3 = CCArray::create( );
    p->someArray3->retain( );

    p->triggerGroupDict_ = CCDictionary::create( );
    p->triggerGroupDict_->retain( );

    p->dict3 = CCDictionary::create( );
    p->dict3->retain( );

    p->dict4 = CCDictionary::create( );
    p->dict4->retain( );

    p->someArray4 = CCArray::create( );
    p->someArray4->retain( );

    p->someArray5 = CCArray::create( );
    p->someArray5->retain( );

    p->colorObjects_ = CCArray::create( );
    p->colorObjects_->retain( );

    p->someArray7 = CCArray::create( );
    p->someArray7->retain( );

    p->someArray8 = CCArray::create( );
    p->someArray8->retain( );

    p->dict5 = CCDictionary::create( );
    p->dict5->retain( );

    p->someArray9 = CCArray::create( );
    p->someArray9->retain( );

    p->someArray10 = CCArray::create( );
    p->someArray10->retain( );

    p->enabledGroups_ = CCArray::createWithCapacity( 100 );
    p->enabledGroups_->retain( );

    p->dict6 = CCDictionary::create( );
    p->dict6->retain( );

    p->someArray11 = CCArray::create( );
    p->someArray11->retain( );

    p->someArray12 = CCArray::create( );
    p->someArray12->retain( );

    p->dict7 = CCDictionary::create( );
    p->dict7->retain( );

    p->undoList_ = CCArray::create( );
    p->undoList_->retain( );

    p->redoList_ = CCArray::create( );
    p->redoList_->retain( );

    p->crashThing = CCArray::create( );
    p->crashThing->retain( );

    // new 2.2
    p->someArray14 = CCArray::create( );
    p->someArray14->retain( );

    p->spawnObjects_ = CCArray::create( );
    p->spawnObjects_->retain( );

    p->collisionBlocks_ = CCArray::create( );
    p->collisionBlocks_->retain( );

    // vectors

    p->objectVector_.reserve( 9999 );
    p->nestedObjects_.reserve( 9999 );
    p->groupsToggled_.reserve( 9999 );
    p->lockedLayers_.reserve( 9999 );
    p->toggledGroups_.reserve( 9999 );

    // more

    p->blendColors_.reserve( 9999 );
    p->blendObjects_.reserve( 9999 );
    p->triggerGroups_.reserve( 9999 );
    p->other3.reserve( 9999 );
    p->other5.reserve( 9999 );
    p->previewGroups_.reserve( 9999 );

    for ( size_t i = 0; i < 9999; ++i )
    {
        p->objectVector_[ i ] = nullptr;
        p->nestedObjects_[ i ] = nullptr;

        p->groupsToggled_[ i ] = false;
        p->lockedLayers_[ i ] = false;
        p->toggledGroups_[ i ] = 0;

        p->blendColors_[ i ] = false;
        p->blendObjects_[ i ] = false;
        p->other3[ i ] = false;
        p->triggerGroups_[ i ] = nullptr;
        p->other5[ i ] = nullptr;
        p->previewGroups_[ i ] = 0.0;
    }

    // continue
    p->obb2d2_ = OBB2D::create( CCPoint( 1, 1 ), 1.0, 1.0, 0.0 );
    p->obb2d2_->retain( );

    p->weirdAlloc = new int[ 0xC80 ];

    dynamic_cast< GJBaseGameLayer* >( p )->setupLayers( );

    p->gridLayer_ = DrawGridLayer::create( p->gameLayer_, p );
    p->gameLayer_->addChild( p->gridLayer_, gm->getGameVariable( "0039" ) ? 99 : -100 );

    p->player_ = PlayerObject::create(
        gm->playerFrame_,
        gm->playerShip_,
        p->gameLayer_ );

    auto prim_color = gm->colorForIdx( gm->playerColor_ );
    auto secondary_color = gm->colorForIdx( gm->playerColor2_ );

    p->player_->setColor( prim_color );
    p->player_->setSecondColor( secondary_color );
    p->player_->updateGlowColor( );
    p->player_->retain( );

    p->batchNodePlayer_->addChild( p->player_, 10 );
    p->player_->setVisible( false );

    p->player2_ = PlayerObject::create(
        gm->playerFrame_,
        gm->playerShip_,
        p->gameLayer_ );

    p->player2_->setColor( secondary_color );
    p->player2_->setSecondColor( prim_color );
    p->player2_->updateGlowColor( );
    p->player2_->retain( );

    p->player2_->setOpacity( 0 );

    p->dCross_ = CCSprite::createWithSpriteFrameName( "d_cross_01_001.png" );

    p->batchNode_->addChild( p->dCross_, 10 );
    p->dCross_->setColor( ccc3( 255, 255, 255 ) );
    p->dCross_->setVisible( false );
    p->dCross_->setScale( 0.7 );

    std::string level_string = ZipUtils::decompressString( p->gameLevel_->levelString_, false, 11 );
    p->levelString_ = level_string;

    p->createObjectsFromSetup( level_string );

    dynamic_cast< GJBaseGameLayer* >( p )->createTextLayers( );

    if ( gm->getGameVariable( "0066" ) )
        dynamic_cast< GJBaseGameLayer* >( p )->enableHighCapacityMode( );

    if ( !p->levelSettings_ )
    {
        p->levelSettings_ = LevelSettingsObject::create( );
        p->levelSettings_->gameLevel_ = p->gameLevel_;

        p->levelSettings_->retain( );
    }

    p->editorUI_ = EditorUI::create( p );
    p->addChild( p->editorUI_, 100 );

    p->createGroundLayer( );
    p->gridLayer_->updateTimeMarkers( );

    // todo: initialize background2 textures
    p->createBackground( );
    p->createBackground2( );

    p->editorUI_->updateSlider( );
    p->updateGroundWidth( );

    dynamic_cast< GJBaseGameLayer* >( p )->resetGroupCounters( false );
    p->sortStickyGroups( );

    p->levelSettingsUpdated( );
    p->updateEditorMode( );

    p->schedule( schedule_selector( LevelEditorLayer::updateVisibility ), 0.05 );
    p->schedule( schedule_selector( LevelEditorLayer::updateGround ) );

    p->editorInit_ = false;

	return true;
}

__attribute__( (constructor) )
void phsdk_libmain( void )
{
	debug_print( "**Loaded Library**\n\n" );
	softbp::setup( softbp::sig_handler, false );

	softbp::hook_with_entry( "_ZN16LevelEditorLayer4initEP11GJGameLevel", ( void* ) editor_callback );
	photon::utils::do_inline_hook( "_ZN10GameObject13createWithKeyEi", gameobj_callback, &gameobj_ori );
	photon::utils::do_inline_hook( "_ZN14EditLevelLayer6onEditEPN7cocos2d8CCObjectE", onedit_callback, &onedit_ori );

	softbp::hook_with_entry( "_ZN12LoadingLayer4initEb", (void*) ex_callback );
	softbp::hook_with_entry( "_ZN15PlatformToolbox21isControllerConnectedEv", ( void* ) controller_callback );	
	softbp::hook_with_entry( "_ZN16GameStatsManager25hasCompletedGauntletLevelEi", ( void* ) unlocked_gauntlet_callback );
}
