#include "include/core/utils.h"
#include "include/core/hook/veh.h"
#include "include/core/mem.h"

#define ENTRYPOINT void __attribute__(( constructor )) libentry( )

using namespace saber::core;
using namespace saber::utils;
using namespace saber::core::hook;

void handler( int signal, siginfo_t* si, ucontext_t* ctx )
{
    log<log_type::error>( "***SIGNAL (%i - %i) HANDLED FROM: 0x%lx", signal, si->si_code, ctx->uc_mcontext.arm_pc );

    exit(EXIT_FAILURE);
}

ENTRYPOINT 
{
    auto addr = vm::get_proc_addr( "libcocos2dcpp.so", "_ZN9MenuLayer4initEv" );
    log("0ADDR: %lx", (std::uintptr_t)addr);

    hook::veh veh( { sig::TRAP, sig::ILL }  );
    veh.load_veh( handler );

    vm::write( addr, vm::traps::TRAP_DATA_THUMB );
}

