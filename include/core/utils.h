#pragma once

#include <android/log.h>

namespace saber::utils 
{
    static constexpr bool DEBUG_ENABLED = true;
    static constexpr auto DEBUG_TAG = "** Saber **";

    enum log_type 
    {
        unknown,
        normal, // DEFAULT
        verbose,
        debug,
        info,
        warn,
        error,
        fatal,
        silent
    };

    template <log_type T = log_type::debug, typename... Args>
    inline void log( const char* fmt, Args... args )
    {
        if constexpr ( !DEBUG_ENABLED )
            return;
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-security"
    __android_log_print( T, DEBUG_TAG, fmt, args... );
#pragma clang diagnostic pop
    }
}