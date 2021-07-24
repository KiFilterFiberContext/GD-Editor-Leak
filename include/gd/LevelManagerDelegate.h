#pragma once

#include "CCLayer.h"

class LevelManagerDelegate
{
public:
	virtual void loadLevelsFinished( cocos2d::CCArray*, const char* ) = 0;
	virtual void loadLevelsFailed( const char* ) = 0;
	virtual void setupPageInfo( std::string, const char* ) = 0;
};