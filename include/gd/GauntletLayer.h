#pragma once

#include "CCLayer.h"
#include "CCScene.h"

#include "LevelManagerDelegate.h"
#include "CCMenuItemSpriteExtra.h"
#include "GJGroundLayer.h"
#include "LoadingLayer.h"
#include "TextArea.h"
#include "LoadingCircle.h"

enum GauntletType
{
	Fire = 1,
	Ice,
	Poison,
	Shadow,
	Lava,
	Bonus,
	Chaos,
	Demon,
	Time,
	Crystal,
	Magic,
	Spike,
	Monster,
	Doom,
	Death,
	Forest,
	Rune,
	Force,
	Spooky,
	Dragon,
	Water,
	Haunted,
	Acid,
	Witch,
	Power,
	Potion,
	Snake,
	Toxic,
	Halloween,
	Treasure,
	Ghost,
	Spider,
	Gem,
	Inferno,
	Portal,
	Strange,
	Fantasy,
	Christmas,
	Surprise,
	Mystery,
	Cursed,
	Cyborg,
	Castle,
	Grave,
	Temple,
};

class GauntletLayer : public cocos2d::CCLayer, LevelManagerDelegate
{
public:
	cocos2d::CCArray* levels_;
	LoadingCircle* loadingCircle_;
	GauntletType gauntletType_;
	cocos2d::CCSprite* bgTexture_;
	GJGroundLayer* groundLayer_;
	CCMenuItemSpriteExtra* onLevelBtn_;
	cocos2d::CCArray* gauntletInfo_;
	TextArea* loadFailedText_;

public:
	virtual ~GauntletLayer( void );

	static cocos2d::CCScene* scene( GauntletType type );

	bool init( GauntletType type );

	void onLevel( cocos2d::CCObject* ref );
	void onBack( cocos2d::CCObject* ref );

	void unlockActiveItem( cocos2d::CCObject* ref );

	void setupGauntlet( cocos2d::CCArray* gauntletInfo );

	virtual void keyBackClicked( );

	virtual void loadLevelsFinished( cocos2d::CCArray*, const char* );
	virtual void loadLevelsFailed( const char* );
} __attribute__( (aligned( 4 )) );
