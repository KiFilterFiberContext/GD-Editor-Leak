#pragma once

#include "GDAPI_Macros.h"

#include <string>
#include "CCGeometry.h"

NS_CC_BEGIN

typedef enum LanguageType
{
	kLanguageEnglish = 0,
	kLanguageChinese,
	kLanguageFrench,
	kLanguageItalian,
	kLanguageGerman,
	kLanguageSpanish,
	kLanguageDutch,
	kLanguageRussian,
	kLanguageKorean,
	kLanguageJapanese,
	kLanguageHungarian,
	kLanguagePortuguese,
	kLanguageArabic
} ccLanguageType;

enum TargetPlatform
{
	kTargetWindows = 0,
	kTargetAndroid = 3
};

class CC_DLL CCApplicationProtocol
{
public:
	CCApplicationProtocol();
	virtual ~CCApplicationProtocol();

	virtual bool applicationDidFinishLaunching() = 0;
	virtual void applicationDidEnterBackground() = 0;
	virtual void applicationWillEnterForeground() = 0;
	virtual void applicationWillBecomeActive();
	virtual void applicationWillResignActive();
	virtual void trySaveGame();
	virtual void gameDidSave();
	virtual void setAnimationInterval(double interval) = 0;
	virtual ccLanguageType getCurrentLanguage() = 0;
	virtual TargetPlatform getTargetPlatform() = 0;
	virtual void openURL(const char *);
};

#if defined(GDAPI_WINDOWS)

//TODO: Add class members to CCApplication for Windows
class CC_DLL CCApplication : public CCApplicationProtocol
{
public:
	HINSTANCE _instance;
	unsigned char _unknown[6 * sizeof(int)];
	std::string _resourceRootPath, _startupScriptFilename;
	int _unk8;
	bool _updatingController, _shutdownCalled;
	char _unk7;
	char _unk5[10], _unk6[4];
	int _unk4;
	CCSize _unk2, _unk3;
	bool _mouseControl, _unk1;
	LARGE_INTEGER _animationInterval;
	bool _verticalSyncEnabled, _unk0;
	bool _sleepMode, _forceTimer, _smoothFix, _fullscreen;

public:
	CCApplication();
	virtual ~CCApplication();

	static CCApplication *sharedApplication();

	bool getControllerConnected() const;
	bool getForceTimer() const;
	bool getFullscreen() const;
	const std::string &getResourceRootPath();
	bool getShutdownCalled() const;
	bool getSleepMode() const;
	bool getSmoothFix() const;
	const std::string &getStartupScriptFilename();
	bool getVerticalSyncEnabled() const;
	void leftMouseDown();
	void leftMouseUp();
	void moveMouse(int, int);
	void setForceTimer(bool);
	void setFullscreen(bool);
	void setResourceRootPath(const std::string &);
	void setShutdownCalled(bool);
	void setSleepMode(bool);
	void setSmoothFix(bool);
	void setStartupScriptFilename(const std::string &);
	void setupVerticalSync();
	void shutdownApplication();
	void toggleMouseControl(bool);
	void toggleVerticalSync(bool);
	void updateController();
	void updateControllerKeys();
	void updateMouseControl();
	void updateVerticalSync();

	virtual void gameDidSave();
	virtual void setAnimationInterval(double);
	virtual LanguageType getCurrentLanguage();
	virtual TargetPlatform getTargetPlatform();
	virtual void openURL(const char *);

	virtual int run();
	virtual void setupGLView();
	virtual void platformShutdown();
};

#else

class CC_DLL CCApplication : public CCApplicationProtocol
{
public:
	CCApplication();
	virtual ~CCApplication();

	static CCApplication *sharedApplication();

	int run();

	virtual void setAnimationInterval(double);
	virtual LanguageType getCurrentLanguage();
	virtual TargetPlatform getTargetPlatform();
	virtual void openURL(const char *);
};

#endif

NS_CC_END