#pragma once

#include "CCObject.h"
#include "GameObject.h"

enum class UndoCommand 
{
    UNKNOWN = 1,
    UndoCmd = 2,
};

class UndoObject : public cocos2d::CCObject
{
public:
    UndoObject();
    virtual ~UndoObject();

    static UndoObject* create( GameObject* g, UndoCommand cmd );

    
};