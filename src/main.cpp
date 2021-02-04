#include "include/core/utils.h"
#include "include/core/hook/veh.h"
#include "include/core/mem.h"

#define ENTRYPOINT void __attribute__(( constructor )) libentry( )

using namespace saber::core;
using namespace saber::logging;
using namespace saber::core::hook;

#include <cocos2d_x/CCLayer.h>
#include <cocos2d_x/CCSprite.h>


bool hk( cocos2d::CCLayer* p1 )
{
    dynamic_cast< cocos2d::CCLayer* >( p1 )->init();
    log( "how how!" );

    p1->addChild( cocos2d::CCSprite::createWithSpriteFrameName( "GJ_logo_001.png" ), 100  );

    return true;
}

ENTRYPOINT 
{
    veh::clear_hooks( );

    veh veh_handler( { sig::ILL, sig::TRAP } );
    veh_handler.load_handler( veh::default_handler );

    auto addr = vm::get_proc_addr( "libcocos2dcpp.so", "_ZN9MenuLayer4initEv" );
    veh_handler.add_hook( addr, hk, true );
}

