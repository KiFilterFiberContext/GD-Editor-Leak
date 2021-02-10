#include "include/core/utils.h"
#include "include/core/hook/veh.h"
#include "include/core/mem.h"
#include "include/core/debug.h"

#define ENTRYPOINT void __attribute__(( constructor )) libentry( )

using namespace saber::core;
using namespace saber::logging;
using namespace saber::core::hook;

#include <cocos2d_x/CCLayer.h>
#include <cocos2d_x/CCSprite.h>
#include <thread>

#include <sync.h>
#include <hooks.h>
#include <mutex>


#define CREATE_HOOK( name, sym ) \
        veh_handler.add_hook( sym, b_##name );

#define HANDLE_TRAP( name ) \
        if ( arm_pc == name##_ptr ) \
        { \
            vm::write( arm_pc, b_##name ); \
            ctx->uc_mcontext.arm_pc = ( std::uintptr_t ) name##_hk; \
        }

static void* trap_watchdog( void* arg ) 
{
    while ( true )
    {
        if ( is_done )
        {
            vm::write( old_ptr, vm::traps::TRAP_DATA_THUMB );
            is_done = false;
        }
    }

    return nullptr;
}

static void default_handler( int signal, siginfo_t* si, void* reserved )
{
    auto ctx = reinterpret_cast< ucontext_t* >( reserved );
    auto arm_pc = ( std::uintptr_t ) vm::CLEAR_BIT0( ctx->uc_mcontext.arm_pc );

    if ( signal == sig::SEGV )
        saber::debug::dump( ctx );

    HANDLE_TRAP( menuinit )
    HANDLE_TRAP( spritecachename )
    HANDLE_TRAP( onedit )
    HANDLE_TRAP( editorinit )
    HANDLE_TRAP( gameobjcreate )
    HANDLE_TRAP( unlocked )
    HANDLE_TRAP( updateoptions )
    HANDLE_TRAP( loading )
    HANDLE_TRAP( world )
    HANDLE_TRAP( cctouch )
    HANDLE_TRAP( touchend )
    HANDLE_TRAP( onmoregames )

    old_ptr = arm_pc;
    is_done = true;
}

ENTRYPOINT 
{
    veh veh_handler( { sig::ILL, sig::TRAP, sig::SEGV } );
    veh_handler.load_handler( default_handler );


    CREATE_HOOK( loading, "_ZN12LoadingLayer16getLoadingStringEv" )
    CREATE_HOOK( menuinit, "_ZN9MenuLayer4initEv" )
    CREATE_HOOK( onedit, "_ZN14EditLevelLayer6onEditEPN7cocos2d8CCObjectE" )
    CREATE_HOOK( editorinit, "_ZN16LevelEditorLayer4initEP11GJGameLevel" )
    CREATE_HOOK( gameobjcreate, "_ZN10GameObject13createWithKeyEi" )
    CREATE_HOOK( spritecachename, "_ZN7cocos2d18CCSpriteFrameCache17spriteFrameByNameEPKc" )
    CREATE_HOOK( unlocked, "_ZN16GameStatsManager14isItemUnlockedE10UnlockTypei" )
    CREATE_HOOK( updateoptions, "_ZN16EditorPauseLayer8onResumeEPN7cocos2d8CCObjectE" )
    // CREATE_HOOK( pausesetup, "_ZN10PauseLayer11customSetupEv" )
    CREATE_HOOK( world, "_ZN12CreatorLayer4initEv" )   
    CREATE_HOOK( cctouch, "_ZN7UILayer12ccTouchBeganEPN7cocos2d7CCTouchEPNS0_7CCEventE" )
    CREATE_HOOK( touchend, "_ZN7UILayer12ccTouchEndedEPN7cocos2d7CCTouchEPNS0_7CCEventE" )
    CREATE_HOOK( onmoregames, "_ZN9MenuLayer11onMoreGamesEPN7cocos2d8CCObjectE" )

    pthread_t tid;
    pthread_create( &tid, nullptr, &trap_watchdog, nullptr );
}

