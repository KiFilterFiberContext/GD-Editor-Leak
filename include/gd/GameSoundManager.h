#pragma once

#include "CCNode.h"

class GameSoundManager : public cocos2d::CCNode
{
public:
    GameSoundManager();
    virtual ~GameSoundManager();

    static GameSoundManager* sharedManager( );

    void playBackgroundMusic( std::string audio, bool a1, bool a2, bool a3 );
    void stopBackgroundMusic( );
};

#define GSM GameSoundManager::sharedManager()