#include "include/core/utils.h"
#include "include/core/hook/veh.h"

#define ENTRYPOINT void __attribute__(( constructor )) libentry( )

using namespace saber::core;
using namespace saber::utils;

ENTRYPOINT 
{
    log("how %i", saber::core::mem::PAGE_START(0x4000));
}

