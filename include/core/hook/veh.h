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
#include <map>

#include "../mem.h"
#include <sync.h>


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

    enum hook_type
    {
        function,
        inlined
    };

    using veh_handler_t = void ( int, siginfo_t*, void* );

    struct veh_hook_t 
    {
        void* function_hk;
        bool registered;

        std::uintptr_t trap_address;
        std::vector<uint8_t> old_bytes;

        hook_type type;
    };
    std::map<std::uintptr_t, std::shared_ptr<veh_hook_t>> hk_list;

    class veh
    {
    public:
        struct sigaction si;
        std::vector<sig> sigs;

    
    public:
        veh( const std::initializer_list<sig> signals ) : si( { 0 } ), sigs( signals ) { }

        void load_handler( veh_handler_t handler ) noexcept
        {
            si.sa_flags = SA_SIGINFO;
            sigemptyset(&si.sa_mask);

            si.sa_sigaction = handler;
            
            for ( const auto signal : sigs ) 
                sigaction(signal, &si, NULL);
        }
        
        template <hook_type T = hook_type::function, std::size_t N>
        void add_hook( const std::uintptr_t address, std::array<std::uint8_t, N>& old_bytes ) noexcept
        { 
            vm::read( address, old_bytes );
            vm::write( address, vm::traps::TRAP_DATA_THUMB );
        }

        template <hook_type T = hook_type::function, std::size_t N>
        void add_hook( const char* sig, std::array<std::uint8_t, N>& old_bytes ) noexcept
        { 
            const auto addr = vm::get_proc_addr( "libcocos2dcpp.so", sig );
            
            vm::read( addr, old_bytes );
            vm::write( addr, vm::traps::TRAP_DATA_THUMB );
        }

        static void clear_hooks( )
        {
            hk_list.clear( );
        }
    };
}