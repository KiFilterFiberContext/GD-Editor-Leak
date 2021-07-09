#pragma once

#include "cocos2d_x/CCLayer.h"
#include "cocos2d_x/CCScene.h"
#include "cocos2d_x/CCLabelBMFont.h"

class LoadingLayer : public cocos2d::CCLayer, public cocos2d::CCTouchDelegate, public cocos2d::CCAccelerometerDelegate, public cocos2d::CCKeypadDelegate, public cocos2d::CCKeyboardDelegate, public cocos2d::CCMouseDelegate
{
public:
	bool finishedLoading_; // 0x129
	int progress_; // 0x12C
	cocos2d::CCLabelBMFont* loadingLabel_; // 0x130
	void* textArea_; // TextArea* 0x134
	cocos2d::CCSprite* sliderBar_; // 0x138
	float width_; // 0x13C
	float height_; // 0x140
	bool useDefaultString_; // 0x144

public:
	virtual ~LoadingLayer( );

	static LoadingLayer* create( bool useDefault );
	static cocos2d::CCScene* scene( bool useDefault );

	bool init( bool useDefault );

	const char* getLoadingString( );

	void loadAssets( );
	void loadingFinished( );

	void updateProgress( int progress );
};
