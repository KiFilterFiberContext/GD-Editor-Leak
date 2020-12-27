#pragma once

#include "GDAPI_Macros.h"

#include "CCEGLViewProtocol.h"

struct GLFWwindow;
struct GLFWvidmode;
struct GLFWmonitor;

NS_CC_BEGIN

#pragma pack(push, 1)
//TODO: Add class members to CCEGLView for Windows
class CC_DLL CCEGLView : public CCEGLViewProtocol, public CCObject
{
public:
	char _unk3[4];
	int _retinaFactor;
	char _unk2[4];
	float _frameZoomFactor;
	struct GLFWwindow *_glfwWindow;
	int _unk1;
	CCSize _windowedSize;
	int _unk0[2];
	bool _isFullscreen, _shouldHideCursor, _shouldCallGLFinish;

protected:
	CCEGLView();
	virtual ~CCEGLView();

public:
	static CCEGLView *create(const std::string &);
	static CCEGLView *createWithFullScreen(const std::string &);
	static CCEGLView *createWithFullScreen(const std::string &, const struct GLFWvidmode &, const struct GLFWmonitor *);
	static CCEGLView *createWithRect(const std::string &, CCRect, float);
	static CCEGLView *sharedOpenGLView();

	void capture();
	void centerWindow();
	void checkErrorGL(const char *);
	void enableRetina(bool);
	CCSize getDisplaySize();
	float getFrameZoomFactor();
	bool getIsFullscreen() const;
	int getRetinaFactor() const;
	bool getShouldCallGLFinish() const;
	bool getShouldHideCursor() const;
	struct GLFWwindow *getWindow() const;
	CCSize getWindowedSize() const;
	void iconify();
	bool isRetinaEnabled() const;
	void pollEvents();
	void releaseCapture();
	void resizeWindow(int, int);
	void setFrameZoomFactor(float);
	void setShouldCallGLFinish(bool);
	void setWindowedSize(CCSize);
	void showCursor(bool);
	void showMessage(std::string);
	void toggleFullScreen(bool);
	void updateDesignSize(int, int);
	void updateWindow(int, int);
	bool windowShouldClose();

protected:
	bool initGlew();
	bool initWithFullScreen(const std::string &);
	bool initWithFullscreen(const std::string &, const struct GLFWvidmode &, struct GLFWmonitor *);
	bool initWithRect(const std::string &, CCRect, float);
	void onGLFWCharCallback(struct GLFWwindow *, unsigned int);
	void onGLFWCursorEnterFunCallback(struct GLFWwindow *, int);
	void onGLFWDeviceChangeFunCallback(struct GLFWwindow *);
	void onGLFWError(int, const char *);
	void onGLFWKeyCallback(struct GLFWwindow *, int, int, int, int);
	void onGLFWMouseCallBack(struct GLFWwindow *, int, int, int);
	void onGLFWMouseMoveCallBack(struct GLFWwindow *, double, double);
	void onGLFWMouseScrollCallback(struct GLFWwindow *, double, double);
	void onGLFWWindowCloseFunCallback(struct GLFWwindow *);
	void onGLFWWindowIconifyFunCallback(struct GLFWwindow *, int);
	void onGLFWWindowPosCallback(struct GLFWwindow *, int, int);
	void onGLFWWindowSizeFunCallback(struct GLFWwindow *, int, int);
	void onGLFWframebuffersize(struct GLFWwindow *, int, int);
	void setupWindow(CCRect);
	void updateFrameSize();

public:
	virtual void end();
	virtual bool isOpenGLReady();
	virtual void swapBuffers();
	virtual void setIMEKeyboardState(bool);
	virtual void setFrameSize(float, float);
	virtual void setViewPortInPoints(float, float, float, float);
	virtual void setScissorInPoints(float, float, float, float);
};
#pragma pack(pop)

NS_CC_END