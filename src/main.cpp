#include "include/core/utils.h"
#include "include/core/hook/veh.h"
#include "include/core/mem.h"

#define ENTRYPOINT void __attribute__(( constructor )) libentry( )

using namespace saber::core;
using namespace saber::utils;
using namespace saber::core::hook;

static std::array<uint8_t, 2> old_bytes = { 0x00, 0xBF };
static std::uintptr_t old_addr = 0x0;

#include <cocos2d_x/CCLayer.h>
#include <cocos2d_x/CCSprite.h>


bool hk( cocos2d::CCLayer* p1 )
{
    dynamic_cast< cocos2d::CCLayer* >( p1 )->init();
    log( "how how!" );

    p1->addChild( cocos2d::CCSprite::createWithSpriteFrameName( "GJ_logo_001.png" ), 100  );

    return true;
}

class MyClass : public cocos2d::CCLayer 
{
public:
    bool myInit( )
    {
        return true;
    }
};

void handler( int signal, siginfo_t* si, void* reserved )
{
    auto ctx = reinterpret_cast< ucontext_t* >( reserved );
    log( "***2 SIGNAL HANDLED FROM: 0x%lx", ctx->uc_mcontext.arm_pc );

    vm::write( old_addr, old_bytes );

    ctx->uc_mcontext.arm_lr = ( std::uintptr_t ) hk;

    vm::write( old_addr, vm::traps::TRAP_DATA_THUMB );

    log( "Bytes written!" );
    ctx->uc_mcontext.arm_pc = ctx->uc_mcontext.arm_lr;
}

ENTRYPOINT 
{
    auto addr = vm::get_proc_addr( "libcocos2dcpp.so", "_ZN9MenuLayer4initEv" );
    old_addr = addr;

    log("0ADDR: %lx %lx", old_addr, addr);

    vm::read( addr, old_bytes );

    hook::veh veh( { sig::TRAP, sig::ILL }  );
    veh.load_handler( handler );
    
    vm::write( addr, vm::traps::TRAP_DATA_THUMB );
}

