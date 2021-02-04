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
        
        template <hook_type T = hook_type::function, typename F>
        void add_hook( const std::uintptr_t address, F func, bool register_hook ) noexcept
        { 
            auto hook = std::make_shared<veh_hook_t>( );

            hook->function_hk = reinterpret_cast< void* >( func );
            hook->registered = register_hook;
            hook->trap_address = address;
            hook->type = T;

            saber::logging::log( "OLD: %lx", hook->trap_address );

            std::vector<uint8_t> buff( 2 );
            vm::read( address, buff );

            if ( register_hook )
                vm::write( hook->trap_address, vm::traps::TRAP_DATA_THUMB );
            
            hk_list.emplace( address, std::make_shared<veh_hook_t>( veh_hook_t { 
                reinterpret_cast< void* >( func ), true, address, std::move( buff )
            } ) );
        }

        static void clear_hooks( )
        {
            hk_list.clear( );
        }

        static void default_handler( int signal, siginfo_t* si, void* reserved )
        {
            auto ctx = reinterpret_cast< ucontext_t* >( reserved );

            auto trap_ip = ( std::uintptr_t ) ctx->uc_mcontext.arm_pc;
            auto hook = hook::hk_list[ trap_ip ];

            saber::logging::log( "***3 SIGNAL HANDLED FROM: 0x%lx OR 0x%lx (0x%lx)", ctx->uc_mcontext.arm_pc, hook->trap_address, hook->function_hk );

            vm::write( trap_ip, hook->old_bytes );

            ctx->uc_mcontext.arm_pc = ( std::uintptr_t ) hook->function_hk;

           // vm::write( trap_ip, vm::traps::TRAP_DATA_THUMB );
        }
    };
}