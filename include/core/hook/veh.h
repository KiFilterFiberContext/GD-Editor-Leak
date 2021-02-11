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
#include <mutex>
#include <shared_mutex>
#include <csignal>
#include <ucontext.h>
#include <setjmp.h>
#include <list>
#include <algorithm>
#include <future>

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
    static uint8_t alternate_stack[65536];

    //
    // mutex works in our thread but not when trapping from hooks
    //
    class hook_list_t 
    {
    public:
        using read_lock = std::shared_lock<std::shared_timed_mutex>;
        using write_lock = std::unique_lock<std::shared_timed_mutex>;

    private:
        mutable std::shared_timed_mutex mtx;
        std::map<int, int> data;

    public:
        template <typename T>
        auto read_data( T key ) noexcept
        {
            read_lock( mtx );
            return data[ key ];
        }

        void clear( ) noexcept
        {
            write_lock( mtx );
            data.clear( );
        }

        template <typename T, typename K>
        void write_data( T key, K value ) noexcept
        {
            write_lock( mtx );
            data.emplace( key, value );
        }

        int size( ) const noexcept 
        {
            read_lock( mtx );
            return data.size( );
        }
    };

    class veh
    {
    public:
        struct sigaction si;
        std::vector<sig> sigs;
    
    public:
        veh( const std::initializer_list<sig> signals ) : si( { 0 } ), sigs( signals ) { }

        void load_handler( veh_handler_t handler ) noexcept
        {
            stack_t ss = { 
                .ss_sp = reinterpret_cast<void*>( alternate_stack ),
                .ss_size =  65536,
                .ss_flags = 0
            };
            sigaltstack( &ss, nullptr );

            si.sa_flags = SA_SIGINFO | SA_ONSTACK;
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