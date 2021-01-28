#include "include/core/utils.h"
#include "include/core/hook/veh.h"
#include "include/core/mem.h"

#define ENTRYPOINT void __attribute__(( constructor )) libentry( )

using namespace saber::core;
using namespace saber::utils;

ENTRYPOINT 
{
    auto addr = vm::get_proc_addr( "libcocos2dcpp.so", "_ZN9MenuLayer4initEv" );
    log( "New Saber! 0x%lx", addr );

    vm::write( addr + 1, vm::traps::TRAP_DATA_ARM_THUMB );
    log( "BYTES: 0x%lx", *(std::uint32_t*) addr );
}

