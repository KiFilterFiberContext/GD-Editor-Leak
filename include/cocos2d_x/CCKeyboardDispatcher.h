#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCArray.h"

NS_CC_BEGIN

typedef enum
{
	kBackspace = 8,
	kTab,
	kClear = 12,
	kEnter,
	kShift = 16,
	kControl,
	kAlt,
	kPause,
	kCapsLock,
	kEscape = 27,
	kSpace = 32,
	kPageUp,
	kPageDown,
	kEnd,
	kHome,
	kLeft,
	kUp,
	kRight,
	kDown,
	kSelect,
	kPrint,
	kExecute,
	kPrintScreen,
	kInsert,
	kDelete,
	kHelp,
	k0,
	k1,
	k2,
	k3,
	k4,
	k5,
	k6,
	k7,
	k8,
	k9,
	kA = 65,
	kB,
	kC,
	kD,
	kE,
	kF,
	kG,
	kH,
	kI,
	kJ,
	kK,
	kL,
	kM,
	kN,
	kO,
	kP,
	kQ,
	kR,
	kS,
	kT,
	kU,
	kV,
	kW,
	kX,
	kY,
	kZ,
	kLeftWindowsKey,
	kRightWindowsKey,
	kApplicationsKey,
	kSleep = 95,
	kNumPad0,
	kNumPad1,
	kNumPad2,
	kNumPad3,
	kNumPad4,
	kNumPad5,
	kNumPad6,
	kNumPad7,
	kNumPad8,
	kNumPad9,
	kMultiply,
	kAdd,
	kSeparator,
	kSubtract,
	kDecimal,
	kDivide,
	kF1,
	kF2,
	kF3,
	kF4,
	kF5,
	kF6,
	kF7,
	kF8,
	kF9,
	kF10,
	kF11,
	kF12,
	kF13,
	kF14,
	kF15,
	kF16,
	kF17,
	kF18,
	kF19,
	kF20,
	kF21,
	kF22,
	kF23,
	kF24,
	kNumlock = 144,
	kScrollLock,
	kLeftShift = 160,
	kRightShift,
	kLeftControl,
	kRightContol,
	kLeftMenu,
	kRightMenu,
	kBrowserBack,
	kBrowserForward,
	kBrowserRefresh,
	kBrowserStop,
	kBrowserSearch,
	kBrowserFavorites,
	kBrowserHome,
	kVolumeMute,
	kVolumeDown,
	kVolumeUp,
	kNextTrack,
	kPreviousTrack,
	kStopMedia,
	kPlayPause,
	kLaunchMail,
	kSelectMedia,
	kLaunchApp1,
	kLaunchApp2,
	kOEMPlus = 184,
	kOEM1 = 186,
	kComma = 188,
	kMinus,
	kYen,
	kOEM2,
	kOEM3,
	kOEM4 = 219,
	kOEM5,
	kOEM6,
	kOEM7,
	kOEM8,
	kLess = 226,
	kProcess = 229,
	kPacket = 231,
	kAttn = 246,
	kCrSel,
	kExSel,
	kEraseEOF,
	kPlay,
	kZoom,
	kPA1 = 253,
	kOEMClear,
	kArrowUp = 283,
	kArrowDown,
	kArrowLeft,
	kArrowRight,
	kController_A = 1001,
	kController_B,
	kController_Y,
	kController_X,
	kController_Start,
	kController_Back,
	kController_RB,
	kController_LB,
	kController_RT,
	kController_LT,
	kController_Up,
	kController_Down,
	kController_Left,
	kController_Right,
} enumKeyCodes;

class CC_DLL CCKeyboardDelegate
{
public:
	virtual void keyDown(enumKeyCodes);
	virtual void keyUp(enumKeyCodes);
};

class CC_DLL CCKeyboardHandler : public CCObject
{
public:
	CCKeyboardDelegate *_pDelegate;

public:
	CCKeyboardHandler();
	virtual ~CCKeyboardHandler();

	static CCKeyboardHandler *handlerWithDelegate(CCKeyboardDelegate *);

	CCKeyboardDelegate *getDelegate();
	void setDelegate(CCKeyboardDelegate *);

	virtual bool initWithDelegate(CCKeyboardDelegate *);
};

class CC_DLL CCKeyboardDispatcher : public CCObject
{
public:
	CCArray *_pDelegates;
	bool _bLocked, _bToAdd, _bToRemove;
	_ccCArray *_pHandlersToAdd, *_pHandlersToRemove;
	bool _shiftKeyPressed, _controlKeyPressed, _altKeyPressed, _commandKeyPressed;

public:
	CCKeyboardDispatcher();
	virtual ~CCKeyboardDispatcher();

	void addDelegate(CCKeyboardDelegate *);
	enumKeyCodes convertKeyCode(enumKeyCodes);
	bool dispatchKeyboardMSG(enumKeyCodes, bool);
	void forceAddDelegate(CCKeyboardDelegate *);
	void forceRemoveDelegate(CCKeyboardDelegate *);
	bool getAltKeyPressed() const;
	bool getCommandKeyPressed() const;
	bool getControlKeyPressed() const;
	bool getShiftKeyPressed() const;
	const char *keyToString(enumKeyCodes);
	void removeDelegate(CCKeyboardDelegate *);
	void updateModifierKeys(bool shiftPressed, bool ctrlPressed, bool altPressed, bool cmdPressed);
};

NS_CC_END