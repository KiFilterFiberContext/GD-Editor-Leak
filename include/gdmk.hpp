#pragma once

#include "inlineHook.h"

#include <dlfcn.h>
#include <string>
#include <tuple>

#include <android/log.h>

#define TAG "GDKit"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,      TAG, __VA_ARGS__)

struct gdmk 
{
    enum SymError 
    {
        INVALID_HANDLE,
        INVALID_SYMBOL,
        SUCCESS,
    };
    
    static std::tuple< uint32_t, SymError > get_proc_addr( const char* sym );

    // template < typename T >
    // uuint32_t T replacement, T* old

    template < typename T >
    static bool do_inline_hook( uint32_t address, T replacement, T* old ) 
    {
        const auto reg_result = registerInlineHook( address, (uint32_t) replacement, (uint32_t **) old ); // &old
        if ( reg_result != ELE7EN_OK )
            return false;

        const auto hook_result = inlineHook( address );
        if( hook_result != ELE7EN_OK )
            return false;

        return true;
    }

    #define DECLARE_DECORATOR(ret, fnName, args) \
        typedef ret (* fnName##_t)( args ); \
        static void fnName##_HYPERDASH_init_decorator_(); \
        ret fnName##_real( args ); \
        ret fnName##_decorator( args ); 

    #define DEFINE_DECORATOR(ret, className, fnName, args) \
        ret className::fnName##_real( args ) { \
            return ( ret ) 0; \
        } \
        template <typename T> \
        uint32_t get_addr (T f) { \
            union dirty { \
                T pmf; \
                uint32_t words[2]; \
            }; \
            dirty d; \
            d.pmf = f; \
            return d.words[0]; \
        } \
        template<typename M> \
        inline void* GetMethodPointer(M ptr) { \
            return *reinterpret_cast<void**>(&ptr); \
        } \
        void className::fnName##_HYPERDASH_init_decorator_() { \
            static ret (className::*ptr1)( args ); \
            static ret (className::*ptr2)( args ); \
            auto p1 = (uint32_t) GetMethodPointer(&className::fnName##_decorator); \
            gdmk::do_inline_hook( get_addr(&className::fnName), p1, &ptr1); \
            auto p2 = (uint32_t) GetMethodPointer(ptr1); \
            gdmk::do_inline_hook( get_addr(&className::fnName##_real), p2, &ptr2 ); \
        } \
        ret className::fnName##_decorator( args )
};
