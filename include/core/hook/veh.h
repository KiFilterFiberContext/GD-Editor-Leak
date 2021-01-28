#pragma once

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <functional>
#include <vector>
#include <memory>
#include <unordered_map>

#include "../mem.h"

namespace saber::core::hook
{
    enum sig 
    {
        HUP = 1,
        INT,
        QUIT,
        ILL,
        TRAP,
        ABRT,
        EMT,
        FPE,
        KILL,
        BUS,
        SEGV,
        SYS,
        PIPE,
        ALRM,
        TERM,
        USR1,
        USR2,
        CHLD,
        PWR,
        WINCH,
        URG,
        POLL,
        STOP,
        TSTP,
        CONT,
        TTIN,
        TTOU,
        VTALRM,
        PROF,
        XCPU,
        XFSZ,
        WAITING,
        LWP,
        AIO,
    };

    using veh_handler_t = void ( int, siginfo_t*, ucontext_t* );

    class veh
    {
    private:
        struct sigaction si;

        std::vector<sig> sigs;
        std::unordered_map<std::uintptr_t, void*> hooks;
    
    public:
        veh( const std::initializer_list<sig> signals ) : si( { 0 } ), sigs( signals ) { }

        void load_veh( veh_handler_t handler )
        {
            si.sa_flags = SA_SIGINFO;
            sigemptyset(&si.sa_mask);
            si.sa_sigaction = handler;
            
            for ( const auto signal : sigs ) 
                sigaction(signal, &si, NULL);
        }
    };
}