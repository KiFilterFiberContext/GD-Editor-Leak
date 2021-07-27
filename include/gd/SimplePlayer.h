#pragma once

#include "CCSprite.h"

class GJRobotSprite;
class GJSpiderSprite;

class __attribute__( (aligned( 4 )) ) SimplePlayer : public cocos2d::CCSprite
{
public:
	cocos2d::CCSprite* player_;				// 0x1F4
	cocos2d::CCSprite* playerOutline_;
	cocos2d::CCSprite* playerOutline2_;
	cocos2d::CCSprite* playerGlow_;
	cocos2d::CCSprite* playerOutline3_;
	GJRobotSprite* robot_; 
	GJSpiderSprite* spider_;
	int special_;
	bool useGlow_;

public:
	SimplePlayer( void );
	virtual ~SimplePlayer( void );

	static SimplePlayer* create( int icon );
};