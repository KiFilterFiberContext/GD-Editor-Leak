#pragma once
/*
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
*/

#include "../mem.h"

/*
auto menu_layer = std::get<0>( gdmk::get_proc_addr( "_ZN9MenuLayer4initEv" ) );

mprotect((void *) PAGE_START(CLEAR_BIT0(menu_layer)), PAGE_SIZE * 2, PROT_READ | PROT_WRITE | PROT_EXEC);
*(uint8_t*) menu_layer = 0xCC; // current: SIGILL / want: SIGTRAP
mprotect((void *) PAGE_START(CLEAR_BIT0(menu_layer)), PAGE_SIZE * 2, PROT_READ | PROT_EXEC);
cacheflush(CLEAR_BIT0(menu_layer), CLEAR_BIT0(menu_layer) + 2, 0);

LOGD("F: %lx", (uint32_t)menu_layer);

struct sigaction sa;
sa.sa_flags = SA_SIGINFO;
sigemptyset(&sa.sa_mask);
sa.sa_sigaction = handler;

sigaction(SIGILL, &sa, NULL);
sigaction(SIGSEGV, &sa, NULL); // emulator
*/

namespace saber::core::hook
{
    struct veh
    {
        
    };
}