#pragma once

#include "GDAPI_Macros.h"

#include "CCProtocols.h"
#include "CCTouchDelegateProtocol.h"
#include "CCAccelerometer.h"
#include "CCKeypadDispatcher.h"
#include "CCNode.h"
#include "CCKeyboardDispatcher.h"
#include "CCMouseDispatcher.h"

NS_CC_BEGIN

typedef enum
{
	kCCTouchesAllAtOnce,
	kCCTouchesOneByOne,
} ccTouchesMode;

class CCTouchScriptHandlerEntry;
class CCScriptHandlerEntry;

class CC_DLL CCLayer : public CCNode, public CCTouchDelegate, public CCAccelerometerDelegate, public CCKeypadDelegate, public CCKeyboardDelegate, public CCMouseDelegate
{
public:
	bool _bTouchEnabled, _bAccelerometerEnabled, _bKeypadEnabled, _bKeyboardEnabled, _bMouseEnabled;
	CCTouchScriptHandlerEntry *_pScriptTouchHandlerEntry;
	CCScriptHandlerEntry *_pScriptKeypadHandlerEntry, *_pScriptAccelerateHandlerEntry;
	int _nTouchPriority;
	ccTouchesMode _eTouchMode;

public:
	CCLayer();
	virtual ~CCLayer();

	static CCLayer *create();

	CCScriptHandlerEntry *getScriptAccelerateHandlerEntry();
	CCScriptHandlerEntry *getScriptKeypadHandlerEntry();
	CCTouchScriptHandlerEntry *getScriptTouchHandlerEntry();
	void registerScriptAccelerateHandler(int);
	void registerScriptKeypadHandler(int);
	void unregisterScriptAccelerateHandler();
	void unregisterScriptKeypadHandler();

private:
	int excuteScriptTouchHandler(int, CCSet *);
	int excuteScriptTouchHandler(int, CCTouch *);

public:
	virtual bool init();
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
	virtual void didAccelerate(CCAcceleration *pAccelerationValue);

	virtual void registerWithTouchDispatcher();
	virtual void registerScriptTouchHandler(int, bool, int, bool);
	virtual void unregisterScriptTouchHandler();
	virtual bool isTouchEnabled();
	virtual void setTouchEnabled(bool);
	virtual void setTouchMode(ccTouchesMode);
	virtual int getTouchMode();
	virtual void setTouchPriority(int);
	virtual int getTouchPriority();
	virtual bool isAccelerometerEnabled();
	virtual void setAccelerometerEnabled(bool);
	virtual void setAccelerometerInterval(double);
	virtual bool isKeypadEnabled();
	virtual void setKeypadEnabled(bool);
	virtual bool isKeyboardEnabled();
	virtual void setKeyboardEnabled(bool);
	virtual bool isMouseEnabled();
	virtual void setMouseEnabled(bool);
	
	virtual void keyBackClicked();
	virtual void keyMenuClicked();
	virtual void keyDown(enumKeyCodes);
};

class CC_DLL CCLayerRGBA : public CCLayer, public CCRGBAProtocol
{
public:
	GLubyte _displayedOpacity, _realOpacity;
	ccColor3B _displayedColor, _realColor;
	bool _cascadeOpacityEnabled, _cascadeColorEnabled;

public:
	CCLayerRGBA();
	virtual ~CCLayerRGBA();

	static CCLayerRGBA *create();

	virtual bool init();
	virtual GLubyte getOpacity();
	virtual GLubyte getDisplayedOpacity();
	virtual void setOpacity(GLubyte opacity);
	virtual void updateDisplayedOpacity(GLubyte opacity);
	virtual bool isCascadeOpacityEnabled();
	virtual void setCascadeOpacityEnabled(bool bValue);
	virtual const ccColor3B &getColor();
	virtual const ccColor3B &getDisplayedColor();
	virtual void setColor(const ccColor3B &color);
	virtual void updateDisplayedColor(const ccColor3B &color);
	virtual bool isCascadeColorEnabled();
	virtual void setCascadeColorEnabled(bool bValue);
	virtual void setOpacityModifyRGB(bool bValue);
	virtual bool isOpacityModifyRGB();
};

class CC_DLL CCLayerColor : public CCLayerRGBA, public CCBlendProtocol
{
public:
	ccVertex2F _pSquareVertices[4];
	ccColor4F _pSquareColors[4];
	ccBlendFunc _tBlendFunc;

public:
	CCLayerColor();
	virtual ~CCLayerColor();

	static CCLayerColor *create();
	static CCLayerColor *create(const _ccColor4B &, float, float);
	static CCLayerColor *create(const _ccColor4B &);

	void changeHeight(float);
	void changeWidth(float);
	void changeWidthAndHeight(float, float);

	virtual bool init();
	virtual void setContentSize(const CCSize &);
	virtual void draw();
	virtual void setOpacity(unsigned char);
	virtual void setColor(const _ccColor3B &);

	virtual bool initWithColor(const _ccColor4B &, float, float);
	virtual bool initWithColor(const _ccColor4B &);

	virtual _ccBlendFunc getBlendFunc();
	virtual void setBlendFunc(_ccBlendFunc);
	
protected:
	virtual void updateColor();
};

class CC_DLL CCLayerGradient : public CCLayerColor
{
public:
	ccColor3B _startColor, _endColor;
	GLubyte _cStartOpacity, _cEndOpacity;
	CCPoint _AlongVector;
	bool _bCompressedInterpolation;

public:
	CCLayerGradient();
	virtual ~CCLayerGradient();

	static CCLayerGradient *create();
	static CCLayerGradient *create(const _ccColor4B &, const _ccColor4B &);
	static CCLayerGradient *create(const _ccColor4B &, const _ccColor4B &, const CCPoint &);
	
	virtual bool init();

protected:
	virtual void updateColor();

public:
	virtual bool initWithColor(const _ccColor4B &, const _ccColor4B &);
	virtual bool initWithColor(const _ccColor4B &, const _ccColor4B &, const CCPoint &);
	virtual const _ccColor3B &getStartColor();
	virtual void setStartColor(const _ccColor3B &);
	virtual const _ccColor3B &getEndColor();
	virtual void setEndColor(const _ccColor3B &);
	virtual unsigned char getStartOpacity();
	virtual void setStartOpacity(unsigned char);
	virtual unsigned char getEndOpacity();
	virtual void setEndOpacity(unsigned char);
	virtual const CCPoint &getVector();
	virtual void setVector(const CCPoint &);
	virtual void setCompressedInterpolation(bool);
	virtual bool isCompressedInterpolation();
};

class CC_DLL CCLayerMultiplex : public CCLayer
{
public:
	unsigned int _nEnabledLayer;
	CCArray *_pLayers;

public:
	CCLayerMultiplex();
	virtual ~CCLayerMultiplex();

	static CCLayerMultiplex *create();
	static CCLayerMultiplex *create(CCLayer *, ...);
	static CCLayerMultiplex *createWithArray(CCArray *);
	static CCLayerMultiplex *createWithLayer(CCLayer *);

	void addLayer(CCLayer *);
	bool initWithArray(CCArray *);
	bool initWithLayers(CCLayer *, char *);
	void switchTo(unsigned int);
	void switchToAndReleaseMe(unsigned int);
};

NS_CC_END