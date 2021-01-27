#pragma once

#include <cstdint>
#include <arm-linux-androideabi/asm/mman.h>
#include <array>

namespace saber::core::mem 
{
    struct traps 
    {
        static constexpr std::array<std::uint8_t, 2> TRAP_DATA_X86      = { 0xCD, 0x03 };                   // int 3
        static constexpr std::array<std::uint8_t, 2> TRAP_DATA_X86_2    = { 0x0F, 0x0B };                   // UD2

        static constexpr std::array<std::uint8_t, 4> TRAP_DATA_ARM      = { 0xF9, 0x06, 0xF0, 0xE7 };       // UDF #0x69
        static constexpr std::array<std::uint8_t, 2> TRAP_DATA_THUMB    = { 0x69, 0xDE };                   // UDF #0x69
    };

#ifndef PAGE_SIZE
    static constexpr std::size_t PAGE_SIZE = 0x1000;
#endif

    static constexpr auto PAGE_START = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( ~( PAGE_SIZE - 1 ) & (addr) ); };
    static constexpr auto SET_BIT0 = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( addr | 1 ); };
    static constexpr auto CLEAR_BIT0 = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( addr & 0xFFFFFFFE ); };
    static constexpr auto TEST_BIT0 = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( addr & 1 ); };
}
