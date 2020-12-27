#pragma once

#include "GDAPI_Macros.h"

#include "CCMenuItem.h"
#include "CCLayer.h"

NS_CC_BEGIN

typedef enum
{
	kCCMenuStateWaiting,
	kCCMenuStateTrackingTouch
} tCCMenuState;

enum
{
	kCCMenuHandlerPriority = -128,
};

class CC_DLL CCMenu : public CCLayerRGBA
{
public:
	bool _bEnabled;
	tCCMenuState _eState;
	CCMenuItem *_pSelectedItem;

public:
	CCMenu();
	virtual ~CCMenu();
	
	static CCMenu *create();
	static CCMenu *create(CCMenuItem *item, ...);
	static CCMenu *createWithArray(CCArray *pArrayOfItems);
	static CCMenu *createWithItem(CCMenuItem *item);
	static CCMenu *createWithItems(CCMenuItem *firstItem, va_list args);

	void alignItemsHorizontally();
	void alignItemsHorizontallyWithPadding(float padding);
	void __cdecl alignItemsInColumns(unsigned int columns, ...);
	void alignItemsInColumns(unsigned int columns, va_list args);
	void alignItemsInColumnsWithArray(CCArray *rows);
	void __cdecl alignItemsInRows(unsigned int rows, ...);
	void alignItemsInRows(unsigned int rows, va_list args);
	void alignItemsInRowsWithArray(CCArray *columns);
	void alignItemsVertically();
	void alignItemsVerticallyWithPadding(float padding);
	bool initWithArray(CCArray *pArrayOfItems);
	void setHandlerPriority(int newPriority);

protected:
	CCMenuItem *itemForTouch(CCTouch *touch);

public:
	virtual bool init();
	virtual void addChild(CCNode *child);
	virtual void addChild(CCNode *child, int zOrder);
	virtual void addChild(CCNode *child, int zOrder, int tag);
	virtual void removeChild(CCNode *child, bool cleanup);
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
	virtual void ccTouchMoved(CCTouch *touch, CCEvent *event);
	virtual void ccTouchEnded(CCTouch *touch, CCEvent *event);
	virtual void ccTouchCancelled(CCTouch *touch, CCEvent *event);
	virtual void registerWithTouchDispatcher();
	virtual void setOpacityModifyRGB(bool bValue);
	virtual bool isOpacityModifyRGB();

	virtual bool isEnabled();
	virtual void setEnabled(bool value);
};

NS_CC_END