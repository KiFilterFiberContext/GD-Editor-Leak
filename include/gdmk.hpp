#pragma once

#include "inlineHook.h"

#include <dlfcn.h>
#include <string>
#include <tuple>


/*
    const auto [ addr14, err14 ] = gdmk::get_proc_addr(OB("_ZN16GameStatsManager14isItemUnlockedE10UnlockTypei"));
    gdmk::do_inline_hook( addr14, unlocked_hk, &unlocked);

    const auto [ addr16, _16 ] = gdmk::get_proc_addr( OB("_ZN16EditorPauseLayer8onResumeEPN7cocos2d8CCObjectE") );
    gdmk::do_inline_hook( addr16, updateOptions_hk, &updateOptions );

    const auto [ addr11, err11 ]= gdmk::get_proc_addr(OB("_ZN12LoadingLayer16getLoadingStringEv"));
    gdmk::do_inline_hook( addr11, loading_hk, &loading );

    const auto [ addr, _ ] = gdmk::get_proc_addr( OB("_ZN14EditLevelLayer6onEditEPN7cocos2d8CCObjectE") );
    gdmk::do_inline_hook( addr, onEdit_hk, &old );

    const auto [ addr3, _3] = gdmk::get_proc_addr( OB("_ZN16LevelEditorLayer4initEP11GJGameLevel") );
    gdmk::do_inline_hook( addr3, init_hk, &old3 );

    const auto [ addr4, _4 ] = gdmk::get_proc_addr( OB("_ZN10GameObject13createWithKeyEi") );
    gdmk::do_inline_hook( addr4, create_hk, &old4 );

    const auto [ addr5, _5 ] = gdmk::get_proc_addr( OB("_ZN7cocos2d18CCSpriteFrameCache17spriteFrameByNameEPKc") );

    gdmk::do_inline_hook( addr5, sprite_hk, &old5 );

    const auto [ addr10, _10 ] = gdmk::get_proc_addr( OB("_ZN10PauseLayer11customSetupEv") );
    gdmk::do_inline_hook( addr10, pauseSetup_hk, &pauseSetup );

    const auto [ addr12, _11 ] = gdmk::get_proc_addr( OB("_ZN14LevelInfoLayer4initEP11GJGameLevelb") );
    gdmk::do_inline_hook( addr12, levelinfoinit_hk, &levelinfoinit );

    const auto [ addr13, _13 ] = gdmk::get_proc_addr( OB("_ZN7cocos2d12CCDictionary9setObjectEPNS_8CCObjectEi") );
    gdmk::do_inline_hook( addr13, dict_hk, &dict );

    const auto [ addr15, _15 ] = gdmk::get_proc_addr( OB("_ZN12CreatorLayer4initEv") );
    gdmk::do_inline_hook( addr15, world_hk, &world );

    const auto [ addr19, _19 ] = gdmk::get_proc_addr( OB("_ZN10PauseLayer6onEditEPN7cocos2d8CCObjectE") );
    gdmk::do_inline_hook( addr19, exitEdit_hk, &exitEdit );

    const auto addr17 = std::get<0>( gdmk::get_proc_addr(OB("_ZN9MenuLayer4initEv")));
    // gdmk::do_inline_hook( addr17, menu_hk, &menu);

    const auto addr18 = std::get<0>( gdmk::get_proc_addr(OB("_ZN7UILayer12ccTouchBeganEPN7cocos2d7CCTouchEPNS0_7CCEventE")) );
    gdmk::do_inline_hook( addr18, cctouch_hk, &cctouch );

    const auto addr20 = std::get<0>( gdmk::get_proc_addr(OB("_ZN7UILayer12ccTouchEndedEPN7cocos2d7CCTouchEPNS0_7CCEventE")));
    gdmk::do_inline_hook( addr20, touchend_hk, &touchend);

    const auto addr21 = std::get<0>( gdmk::get_proc_addr( OB( "_ZN13ObjectToolbox11sharedStateEv" ) ) );
    gdmk::do_inline_hook( addr21, toolbox_hk, &toolbox );
    
    const auto addr23 = std::get<0>( gdmk::get_proc_addr( OB( "glScissor" ) ) );
    gdmk::do_inline_hook( addr23, clippingRect_hk, &clippingRect );

    // const auto addr22 = std::get<0>( gdmk::get_proc_addr( "_ZN9MenuLayer12onGameCenterEPN7cocos2d8CCObjectE" ) );
    // gdmk::do_inline_hook( addr22, buttonBar_hk, &buttonBar );
*/




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
