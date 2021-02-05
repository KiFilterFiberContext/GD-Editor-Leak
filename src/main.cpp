#include "include/core/utils.h"
#include "include/core/hook/veh.h"
#include "include/core/mem.h"

#define ENTRYPOINT void __attribute__(( constructor )) libentry( )

using namespace saber::core;
using namespace saber::logging;
using namespace saber::core::hook;

#include <cocos2d_x/CCLayer.h>
#include <cocos2d_x/CCSprite.h>
#include <thread>

static void default_handler( int signal, siginfo_t* si, void* reserved )
{
    auto ctx = reinterpret_cast< ucontext_t* >( reserved );

    saber::logging::log( "GETTING ORIGINAL PC HANDLED FROM: 0x%lx", ctx->uc_mcontext.arm_pc );

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
}
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

    std::thread t1([] {
        saber::logging::log( "IN THR: %i", hook::hk_list.size() );
    });

    t1.join();
}

