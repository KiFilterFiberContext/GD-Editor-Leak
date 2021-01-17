#pragma once

#include "CCNode.h"

class EditButtonBar : public cocos2d::CCNode 
{
public:
    int page_; // 0x100
    bool a1; // 0x104
    uint8_t _pad105[ 0x3 ]; // 0x105
    cocos2d::CCArray* createBtnArray_; // 0x108
    // ...

public:
    EditButtonBar();
    virtual ~EditButtonBar();

    static EditButtonBar *create( cocos2d::CCArray* objectArray, cocos2d::CCPoint pos, int tabIndex, bool a1, int buttonWidth, int buttonHeight );
};