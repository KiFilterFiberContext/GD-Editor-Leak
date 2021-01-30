#include "include/core/utils.h"
#include "include/core/hook/veh.h"
#include "include/core/mem.h"

#define ENTRYPOINT void __attribute__(( constructor )) libentry( )

using namespace saber::core;
using namespace saber::utils;
using namespace saber::core::hook;

static std::array<uint8_t, 2> old_bytes = { 0x00, 0xBF };
static std::uintptr_t old_addr = 0x0;

void handler( int signal, siginfo_t* si, void* reserved )
{
    auto ctx = reinterpret_cast< ucontext_t* >( reserved );
    log<log_type::error>( "***SIGNAL (%i - %i) HANDLED FROM: 0x%lx (ORI: 0x%lx)", signal, si->si_code, ctx->uc_mcontext.arm_pc, old_addr );

    vm::write( old_addr, old_bytes );
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

