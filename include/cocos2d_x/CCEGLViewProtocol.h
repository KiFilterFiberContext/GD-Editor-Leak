#pragma once

#include "GDAPI_Macros.h"
#include "CCTouchDispatcher.h"
#include "CCGeometry.h"

enum ResolutionPolicy
{
	kResolutionExactFit,
	kResolutionNoBorder,
	kResolutionShowAll,
	kResolutionFixedHeight,
	kResolutionFixedWidth,

	kResolutionUnKnown,
};

NS_CC_BEGIN

class CC_DLL CCEGLViewProtocol
{
public:
	EGLTouchDelegate *_pDelegate;
	CCSize _obScreenSize;
	CCSize _obDesignResolutionSize;
	CCRect _obViewPortRect;
	char _szViewName[50];
	float _fScaleX, _fScaleY;
	ResolutionPolicy _eResolutionPolicy;

public:
	CCEGLViewProtocol();
	virtual ~CCEGLViewProtocol();

	float getScaleX() const;
	float getScaleY() const;
	const char *getViewName();
	const CCRect &getViewPortRect() const;

protected:
	void updateDesignResolutionSize();

private:
	void getSetOfTouchesEndOrCancel(CCSet &, int, const int *, const float *, const float *);

public:
	virtual void end() = 0;
	virtual bool isOpenGLReady() = 0;
	virtual void swapBuffers() = 0;
	virtual void setIMEKeyboardState(bool bOpen) = 0;
	virtual const CCSize &getFrameSize() const;
	virtual void setFrameSize(float, float);
	virtual CCSize getVisibleSize() const;
	virtual CCPoint getVisibleOrigin() const;
	virtual void setDesignResolutionSize(float, float, ResolutionPolicy);
	virtual const CCSize &getDesignResolutionSize() const;
	virtual void setTouchDelegate(EGLTouchDelegate *);
	virtual void setViewPortInPoints(float, float, float, float);
	virtual void setScissorInPoints(float, float, float, float);
	virtual bool isScissorEnabled();
	virtual CCRect getScissorRect();
	virtual void setViewName(const char *);
	virtual void handleTouchesBegin(int, const int *, const float *, const float *);
	virtual void handleTouchesMove(int, const int *, const float *, const float *);
	virtual void handleTouchesEnd(int, const int *, const float *, const float *);
	virtual void handleTouchesCancel(int, const int *, const float *, const float *);
	virtual void pollInputEvents();
};

NS_CC_END