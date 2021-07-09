#include "photon_sdk.h"

using photon::core::softbp;

using photon::utils::debug_print;
using photon::utils::print;
using photon::utils::str_replace;

//
// there will be code conflicts due to merging new and older debugging code however the core is still intact
//

//
// example 
//

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

USING_NS_CC;
USING_NS_CC_EXT;

__attribute__((constructor))
void phsdk_libmain( void )
{
	debug_print( "**Loaded Library**\n\n" );

	softbp::setup( softbp::sig_handler, false );

	//
	// no examples for individual instruction traps are published
	//
	
	softbp::hook_with_entry( "_ZN12LoadingLayer4initEb", (void*) ex_callback );
	softbp::hook_with_entry( "_ZN14LevelInfoLayer4initEP11GJGameLevelb", ( void* ) replay_callback );
	softbp::hook_with_entry( "_ZN14LevelInfoLayer10onFeaturedEPN7cocos2d8CCObjectE", ( void* ) feature_callback );
	softbp::hook_with_entry( "_ZN16LevelSearchLayer4initEv", ( void* ) levelsearch_callback );
	softbp::hook_with_entry( "_ZN15PlatformToolbox21isControllerConnectedEv", ( void* ) controller_callback );
        // implement the others...	
}

