#pragma once

#include <cstdint>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <array>
#include <initializer_list>

#include <dlfcn.h>
#include <cstring>
#include "utils.h"

namespace saber::core::vm 
{
    struct traps 
    {
        static constexpr std::array<std::uint8_t, 2> TRAP_DATA_X86          = { 0xCD, 0x03 };                   // int 3
        static constexpr std::array<std::uint8_t, 2> TRAP_DATA_X86_2        = { 0x0F, 0x0B };                   // UD2

        static constexpr std::array<std::uint8_t, 4> TRAP_DATA_ARM          = { 0xF1, 0x00, 0xF0, 0xE7 };       // UDF #1
        static constexpr std::array<std::uint8_t, 2> TRAP_DATA_THUMB        = { 0x1, 0xDE };                    // UDF #1

        static constexpr std::array<std::uint8_t, 2> NOP_DATA_THUMB         = { 0x00, 0xBF };                   // NOP
    };

    enum page_prot
    {
        r = 1,  // 0x1 READ
        w,      // 0x2 WRITE
        rw,
        x,      // 0x4 EXEC
        rx,
        wx,
        rwx,
    };

#ifndef PAGE_SIZE
    static constexpr std::size_t PAGE_SIZE = 0x1000;
#endif

    static inline auto PAGE_START = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( ~( PAGE_SIZE - 1 ) & (addr) ); };
    static inline auto SET_BIT0 = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( addr | 1 ); };
    static inline auto CLEAR_BIT0 = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( addr & 0xFFFFFFFE ); };
    static inline auto TEST_BIT0 = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( addr & 1 ); };

    inline void change_page_protect( const std::uintptr_t address, page_prot protection )
    {
        mprotect( 
            reinterpret_cast<void*>( PAGE_START( CLEAR_BIT0( address ) ) ),
            PAGE_SIZE * 2,
            protection
         );
    }

    template <bool flush = false>
    void write( const std::uintptr_t address, const std::vector<uint8_t>& bytes )
    {
        change_page_protect( address, page_prot::rwx );

        if ( TEST_BIT0( address ) )
            std::memcpy( (void*) CLEAR_BIT0( address ), (void*) bytes.data(), bytes.size() );
        else 
            std::memcpy( (void*) address, (void*) bytes.data(), bytes.size() );

        change_page_protect( address, page_prot::rx );

        if constexpr ( flush )
            cacheflush( CLEAR_BIT0( address ), CLEAR_BIT0( address ) + bytes.size(), 0 );
    }

    template <bool flush = false, std::size_t N>
    void write( const std::uintptr_t address, const std::array<uint8_t, N> bytes )
    {
        change_page_protect( address, page_prot::rwx );

        if ( TEST_BIT0( address ) )
            std::memcpy( (void*) CLEAR_BIT0( address ), (void*) bytes.data(), bytes.size() );
        else 
            std::memcpy( (void*) address, (void*) bytes.data(), bytes.size() );

        change_page_protect( address, page_prot::rx );

        if constexpr ( flush )
            cacheflush( CLEAR_BIT0( address ), CLEAR_BIT0( address ) + bytes.size(), 0 );
    }

    template <std::size_t N>
    inline void write_unchecked( const std::uintptr_t address, const std::array<uint8_t, N> bytes )
    {
        if ( TEST_BIT0( address ) )
            std::memcpy( (void*) CLEAR_BIT0( address ), (void*) bytes.data(), bytes.size() );
        else 
            std::memcpy( (void*) address, (void*) bytes.data(), bytes.size() );
    }

    template <std::size_t N>
    void read( const std::uintptr_t address, std::array<std::uint8_t, N>& out )
    {
        if ( TEST_BIT0( address ) )
            std::memcpy( (void*) out.data(), (void*) CLEAR_BIT0( address ), out.size() );
        else 
            std::memcpy( (void*) out.data(), (void*) address, out.size() );
    }

    void read( const std::uintptr_t address, std::vector<std::uint8_t>& out )
    {
        if ( TEST_BIT0( address ) )
            std::memcpy( (void*) out.data(), (void*) CLEAR_BIT0( address ), out.size() );
        else 
            std::memcpy( (void*) out.data(), (void*) address, out.size() );
    }

    std::uintptr_t get_proc_addr( const char* lib, const char* sym )
    {
        auto handle = dlopen( lib, RTLD_LAZY );
        if( handle == nullptr )
            return 0;

        return reinterpret_cast< std::uintptr_t >( dlsym( handle, sym ) );
    }
}
