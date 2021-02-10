#pragma once

#include "include/core/utils.h"
#include "include/core/mem.h"

#include <signal.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <err.h>
#include <iomanip>

#include <unwind.h>
#include <dlfcn.h>
#include <cxxabi.h>

#include <string>
#include <fstream>
#include <memory>

#include <CCFileUtils.h>
#include <sys/stat.h>

using namespace saber::logging;

namespace saber::debug 
{
    //
    // https://stackoverflow.com/questions/8115192/android-ndk-getting-the-backtrace
    //
    struct android_backtrace_state
    {
        void **current;
        void **end;
    };

    static _Unwind_Reason_Code android_unwind_callback( _Unwind_Context* context, void* arg )
    {
        android_backtrace_state* state = (android_backtrace_state *)arg;
        uintptr_t pc = _Unwind_GetIP(context);
        if ( pc ) 
        {
            if (state->current == state->end) 
            {
                return _URC_END_OF_STACK;
            } 
            else 
            {
                *state->current++ = reinterpret_cast<void*>(pc);
            }
        }
        return _URC_NO_REASON;
    }

    template <typename T>
    std::string to_string(T value)
    {
        std::ostringstream os;
        os << value;
        return os.str();
    }

    inline bool file_exists(const std::string& name) {
        struct stat buffer;   
        return (stat (name.c_str(), &buffer) == 0); 
    }

    //
    // https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
    //
    template<typename ... Args>
    static std::string string_format( const std::string& format, Args ... args )
    {
        int size = snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
        if( size <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
        std::unique_ptr<char[]> buf( new char[ size ] ); 
        snprintf( buf.get(), size, format.c_str(), args ... );
        return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
    }

    static void dump( ucontext_t* ctx )
    {
        if constexpr ( !logging::DEBUG_ENABLED )
            exit(EXIT_FAILURE);
        
        auto path = cocos2d::CCFileUtils::sharedFileUtils()->getWritablePath() + "crashdump.log";
        std::ofstream outfile;

        if ( file_exists( path ) )
            outfile.open( path, std::ios::out | std::ios::app );
        else 
            outfile.open( path, std::ios::out );

        const int max = 100;
        void* buffer[max];

        android_backtrace_state state;
        state.current = buffer;
        state.end = buffer + max;

        _Unwind_Backtrace(android_unwind_callback, &state);

        int count = (int)(state.current - buffer);

        for (int idx = 0; idx < count; idx++) 
        {
            const void* addr = buffer[idx];
            const char* symbol = "";

            Dl_info info;
            if (dladdr(addr, &info) && info.dli_sname) 
                symbol = info.dli_sname;

            int status = 0; 
            char *demangled = __cxxabiv1::__cxa_demangle(symbol, 0, 0, &status); 

            auto data = string_format( "[ <cg>%02d</c> ] PC: <cr>%p</c>\nS: <cy>%s</c>", idx, addr, (NULL != demangled && 0 == status) ? demangled : symbol );
            saber::logging::log( "DATA: %s", data.c_str() );

            if ( demangled != nullptr )
                outfile << data << std::endl;

            if (NULL != demangled)
                free( demangled );        
        }

        outfile.close( );
        exit(EXIT_FAILURE);
    }
}