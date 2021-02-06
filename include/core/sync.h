#pragma once

#include <signal.h>
#include <cstdlib>

#include "core/mem.h"

using namespace saber::core;

#define CREATE_MEM( name, sym ) \
        static std::uintptr_t name##_ptr = vm::CLEAR_BIT0( vm::get_proc_addr( "libcocos2dcpp.so", sym ) ); \
        static std::array<std::uint8_t, 2> b_##name = { 0x00, 0x00 };


volatile sig_atomic_t is_done = false;
volatile sig_atomic_t old_ptr = 0x0;

CREATE_MEM( menuinit, "_ZN9MenuLayer4initEv" )
CREATE_MEM( spritecachename, "_ZN7cocos2d18CCSpriteFrameCache17spriteFrameByNameEPKc" )
CREATE_MEM( onedit, "_ZN14EditLevelLayer6onEditEPN7cocos2d8CCObjectE" )
CREATE_MEM( editorinit, "_ZN16LevelEditorLayer4initEP11GJGameLevel" )
CREATE_MEM( gameobjcreate, "_ZN10GameObject13createWithKeyEi" )
CREATE_MEM( unlocked, "_ZN16GameStatsManager14isItemUnlockedE10UnlockTypei" )
CREATE_MEM( updateoptions, "_ZN16EditorPauseLayer8onResumeEPN7cocos2d8CCObjectE" )
CREATE_MEM( loading, "_ZN12LoadingLayer16getLoadingStringEv" )
CREATE_MEM( pausesetup, "_ZN10PauseLayer11customSetupEv" )
CREATE_MEM( world, "_ZN12CreatorLayer4initEv" )
CREATE_MEM( cctouch, "_ZN7UILayer12ccTouchBeganEPN7cocos2d7CCTouchEPNS0_7CCEventE" )
CREATE_MEM( touchend, "_ZN7UILayer12ccTouchEndedEPN7cocos2d7CCTouchEPNS0_7CCEventE" )
CREATE_MEM( clippingrect, "glScissor" )