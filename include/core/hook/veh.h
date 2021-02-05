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

    class veh
    {
    public:
        struct sigaction si;
        std::vector<sig> sigs;

        std::map<std::uintptr_t, std::shared_ptr<veh_hook_t>> hk_list;
    
    public:
        veh( const std::initializer_list<sig> signals ) : si( { 0 } ), sigs( signals ), hk_list( { } ) { }

        void load_handler( veh_handler_t handler ) noexcept
        {
            si.sa_flags = SA_SIGINFO;
            sigemptyset(&si.sa_mask);

            si.sa_sigaction = handler;
            
            for ( const auto signal : sigs ) 
                sigaction(signal, &si, NULL);
        }
        
        template <hook_type T = hook_type::function, typename F>
        void add_hook( const std::uintptr_t address, F func, bool register_hook ) noexcept
        { 
            auto hk = std::make_shared<veh_hook_t>( );

            hk->trap_address = address;
            hk->registered = register_hook;
            hk->type = T;
            hk->function_hk = reinterpret_cast< void* >( func );

            saber::logging::log( "INSERTING INTO %lx or %lx", vm::CLEAR_BIT0( hk->trap_address ), hk->trap_address );

            std::vector<uint8_t> buff( 2 );
            vm::read( address, buff );

            hk->old_bytes = buff;

            if ( register_hook )
                vm::write( address, vm::traps::TRAP_DATA_THUMB );
            
            saber::logging::log( "A (MAP SIZE: %i)", hk_list.size( ) );
            hk_list.emplace( vm::CLEAR_BIT0( address ), hk );
            saber::logging::log( "B  (MAP SIZE: %i)", hk_list.size( ) );
        
        }

        static void clear_hooks( )
        {
            hk_list.clear( );
        }
    };
}