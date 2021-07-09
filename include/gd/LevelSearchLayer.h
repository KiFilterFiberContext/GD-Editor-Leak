#pragma once

#include "CCLayer.h"
#include "CCScene.h"

#include "FLAlertLayer.h"
#include "CCMenuItemSpriteExtra.h"

USING_NS_CC;

class CCTextInputNode;

class LevelSearchLayer : public CCLayer, public FLAlertLayerProtocol // TextInputProtocol, DemonFilterDelegate
{
public:
	CCTextInputNode* inputNode_; // 0x134 TODO: Implement CCTextInputNode
	CCSprite* starFilter_; // 0x138
	CCArray* diffFilters_; // 0x13C
	CCArray* timeFilters_; // 0x140
	CCDictionary* searchDict_; // 0x144
	CCSprite* demonFilter_; // 0x148
	CCMenuItemSpriteExtra* specialDemonBtn_; // 0x14C

public:
	virtual ~LevelSearchLayer( );

	CCScene* scene( );
	static LevelSearchLayer* create( );

	void onClose( CCObject* ref );
	void onBack( CCObject* ref );
	void obMostDownloaded( CCObject* ref );
	void onMostLikes( CCObject* ref );
	void onTrending( CCObject* ref );
	void onMagic( CCObject* ref );
	void onMostRecent( CCObject* ref );
	void onLatestStars( CCObject* ref );
	void onFriends( CCObject* ref );
	void onFollowed( CCObject* ref );
	void onStarAward( CCObject* ref );
	void onSearch( CCObject* ref );
	void onSearchUser( CCObject* ref );
	void onMoreOptions( CCObject* ref );
	void onSpecialDemon( CCObject* ref );

	virtual bool init( );
	virtual void keyBackClicked( );

	// TODO: Implement text node and protocols
	// TODO2: Implement demon protocol

	virtual void demonFilterSelectClosed( int unknown );
};
