#pragma once

#include <android/log.h>

namespace saber::logging 
{
    static constexpr bool DEBUG_ENABLED = true;
    static constexpr auto DEBUG_TAG = "**Saber**";

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

    /* FOREGROUND */
    #define RST  "\x1B[0m"
    #define KRED  "\x1B[31m"
    #define KGRN  "\x1B[32m"
    #define KYEL  "\x1B[33m"
    #define KBLU  "\x1B[34m"
    #define KMAG  "\x1B[35m"
    #define KCYN  "\x1B[36m"
    #define KWHT  "\x1B[37m"

    #define FRED(x) KRED x RST
    #define FGRN(x) KGRN x RST
    #define FYEL(x) KYEL x RST
    #define FBLU(x) KBLU x RST
    #define FMAG(x) KMAG x RST
    #define FCYN(x) KCYN x RST
    #define FWHT(x) KWHT x RST

    #define BOLD(x) "\x1B[1m" x RST
    #define UNDL(x) "\x1B[4m" x RST

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