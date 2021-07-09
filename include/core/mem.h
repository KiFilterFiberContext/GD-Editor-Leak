#pragma once

#ifndef PAGE_SIZE
static constexpr size_t PAGE_SIZE = 0x1000;
#endif

static inline auto PAGE_START = [ ] ( const uintptr_t addr ) -> uintptr_t { return (~(PAGE_SIZE - 1) & (addr)); };
static inline auto TEST_BIT0 = [ ] ( const std::uintptr_t addr ) -> std::uintptr_t { return (addr & 1); };
static inline auto SET_BIT0 = [ ] ( const std::uintptr_t addr ) -> std::uintptr_t { return (addr | 1); };
static inline auto CLEAR_BIT0 = [ ] ( const std::uintptr_t addr ) -> std::uintptr_t { return (addr & 0xFFFFFFFE); };

static int vm_write( const uintptr_t address, const uint8_t* data )
{
	uintptr_t real_addr = TEST_BIT0( address ) ? CLEAR_BIT0( address ) : address;

	if ( mprotect( ( void* ) PAGE_START( real_addr ), PAGE_SIZE * 2, PROT_WRITE | PROT_READ | PROT_EXEC ) < 0 )
		return -1;

	memcpy( ( void* ) real_addr, ( void* ) data, sizeof( data ) );

	if ( mprotect( ( void* ) PAGE_START( real_addr ), PAGE_SIZE * 2, PROT_READ | PROT_EXEC ) < 0 )
		return -1;

	return 0;
}

// checks for ARM thumb mode instruction alignment
static inline uintptr_t get_thumb_address( const uintptr_t addr )
{
	return TEST_BIT0( addr ) ? CLEAR_BIT0( addr ) : addr;
}

void* get_lib_symbol( const char* symname )
{
	void* handle = dlopen( "libcocos2dcpp.so", RTLD_LAZY );
	if ( handle == nullptr )
		return 0;

	return dlsym( handle, symname );
}
