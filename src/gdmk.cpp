#include "gdmk.hpp"


std::tuple< uint32_t, gdmk::SymError > gdmk::get_proc_addr( const char* sym )
{
    void* handle = dlopen( "libcocos2dcpp.so", RTLD_LAZY );
    if( handle == nullptr )
        return std::make_tuple( 0, gdmk::INVALID_HANDLE );

    auto addr = reinterpret_cast< uint32_t >( dlsym( handle, sym ) );
    if( addr == 0 ) 
        return std::make_tuple( 0, gdmk::INVALID_SYMBOL );

    return std::make_tuple( addr, gdmk::SUCCESS );
}

