#pragma once

#include "CCNode.h"

class GameSoundManager : public cocos2d::CCNode
{
public:
    GameSoundManager();
    virtual ~GameSoundManager();

    static GameSoundManager* sharedManager( );

    void stopBackgroundMusic( );
};