#pragma once

#include "CCSprite.h"
#include "CCLabelBMFont.h"

USING_NS_CC;

class SearchButton : public CCSprite
{
public:
	CCLabelBMFont* label_; // 0x1F4
	CCSprite* sprite_; // 0x1F8

public:
	virtual ~SearchButton( );

	static SearchButton* create( const char* buttonSprite, const char* label, float size, const char* sprite );

	bool init( const char* buttonSprite, const char* label, float size, const char* sprite );
};
