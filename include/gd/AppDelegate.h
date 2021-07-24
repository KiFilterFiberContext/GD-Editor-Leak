#pragma once

#include "CCApplication.h"
#include "CCScene.h"

class AppDelegate : public cocos2d::CCApplication, cocos2d::CCSceneDelegate
{
public:
	bool setupGLView_;
	bool paused_;
	cocos2d::CCScene* scenePointer_; 
	bool loadingFinished_;
	bool managersLoaded_;
	bool isIOS_;
	bool isLowMemoryDevice_;
	bool enableFPSTricks_;

public:
	AppDelegate( );
	virtual ~AppDelegate( void );

	static AppDelegate* get( void );

	void platformShutdown( void );
	void setupGLView( void );

	float bgScale( void );
	void pauseGame( void );

	virtual bool applicationDidFinishLaunching( void );
	virtual void applicationDidEnterBackground( void );
	virtual void applicationWillEnterForeground( void );

	virtual void applicationWillBecomeActive( void );
	virtual void applicationWillResignActive( void );

	virtual void trySaveGame( void );
	virtual void willSwitchToScene( cocos2d::CCScene* p_scene );
} __attribute__( (aligned( 4 )) );;