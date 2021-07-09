#pragma once

#include "CCNode.h"

// 
// 2.0 definition
//
// class ColorAction : public CCNode
// {
//  char byteE8;
//  cocos2d::ccColor3B currentColor_;
//  float currentOpacity_;
//  float deltaTime_;
//  cocos2d::ccColor3B fromColor_;
//  cocos2d::ccColor3B toColor_;
//  float duration;
//  bool blend;
//  _DWORD custom;
//  _DWORD index;
//  float fromOpacity;
//  float toOpacity_;
//  _DWORD HSVValue_;
//  _DWORD dword118;
//  _DWORD dword11C;
//  _DWORD dword120;
//  int inheritColorIndex;
//  _BYTE didProcess;
//  _BYTE copyOpacity;
//  _BYTE ignore;
//  _BYTE ignoreCopyColor;
// };

//
class ColorAction : public cocos2d::CCNode 
{
public:
    unsigned char _pad1[ 0x18 ];
    uint8_t thing2; // 0x108
    uint8_t thing3; // 0x109
    uint8_t thing4; // 0x10A

    uint32_t _unk1; // 0x10B
    uint8_t _unk2; // 0x10F

    uint32_t thing1; // 0x110
    uint8_t thing5; // 0x114

public:
    ColorAction();
    virtual ~ColorAction();

    static ColorAction* create( );
    static ColorAction* create( cocos2d::ccColor3B, bool, int );
};

class ColorActionSprite : public cocos2d::CCNode 
{
public:
    unsigned char _pad1[ 0x18 ];
    uint32_t actionID; // 0x104

public:
    ColorActionSprite();
    virtual ~ColorActionSprite();

    static ColorActionSprite* create( );


};
