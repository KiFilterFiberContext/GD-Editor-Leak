#pragma once

#include "GDAPI_Macros.h"

#include "CCNode.h"

NS_CC_BEGIN

class CCLabelTTF;
class CCLabelAtlas;
class CCSprite;
class CCSpriteFrame;

#define kCCItemSize 32

class CC_DLL CCMenuItem : public CCNodeRGBA
{
public:
	bool _bSelected, _bEnabled;
	CCObject *_pListener;
	SEL_MenuHandler _pfnSelector;
	int _nScriptTapHandler;

public:
	CCMenuItem();
	virtual ~CCMenuItem();

	static CCMenuItem *create();
	static CCMenuItem *create(CCObject *rec, SEL_MenuHandler selector);

	int getScriptTapHandler();
	bool initWithTarget(CCObject *rec, SEL_MenuHandler selector);
	CCRect rect();
	void setTarget(CCObject *rec, SEL_MenuHandler selector);

	virtual void activate();
	virtual void selected();
	virtual void unselected();
	virtual void registerScriptTapHandler(int nHandler);
	virtual void unregisterScriptTapHandler();
	virtual bool isEnabled();
	virtual void setEnabled(bool value);
	virtual bool isSelected();
};

class CC_DLL CCMenuItemLabel : public CCMenuItem
{
public:
	ccColor3B _tDisabledColor;
	CCNode *_pLabel;
	ccColor3B _tColorBackup;
	float _fOriginalScale;

public:
	CCMenuItemLabel();
	virtual ~CCMenuItemLabel();

	static CCMenuItemLabel *create(CCNode*label, CCObject *target, SEL_MenuHandler selector);
	static CCMenuItemLabel *create(CCNode *label);

	bool initWithLabel(CCNode *label, CCObject *target, SEL_MenuHandler selector);
	void setString(const char *label);

	virtual void activate();
	virtual void selected();
	virtual void unselected();
	virtual void setEnabled(bool enabled);

	virtual const _ccColor3B &getDisabledColor();
	virtual void setDisabledColor(const _ccColor3B &);
	virtual CCNode *getLabel();
	virtual void setLabel(CCNode *);
};

class CC_DLL CCMenuItemAtlasFont : public CCMenuItemLabel
{
public:
	CCMenuItemAtlasFont();
	virtual ~CCMenuItemAtlasFont();

	static CCMenuItemAtlasFont *create(const char *value, const char *charMapFile, int itemWidth, int itemHeight, char startCharMap);
	static CCMenuItemAtlasFont *create(const char *value, const char *charMapFile, int itemWidth, int itemHeight, char startCharMap, CCObject *target, SEL_MenuHandler selector);

	bool initWithString(const char *value, const char *charMapFile, int itemWidth, int itemHeight, char startCharMap, CCObject *target, SEL_MenuHandler selector);
};

class CC_DLL CCMenuItemFont : public CCMenuItemLabel
{
public:
	unsigned int _uFontSize;
	std::string _strFontName;

public:
	CCMenuItemFont();
	virtual ~CCMenuItemFont();

	static CCMenuItemFont *create(const char *value);
	static CCMenuItemFont *create(const char *value, CCObject *target, SEL_MenuHandler selector);
	static const char *fontName();
	static unsigned int fontSize();
	static void setFontName(const char *name);
	static void setFontSize(unsigned int s);

	const char *fontNameObj();
	unsigned int fontSizeObj();
	bool initWithString(const char *value, CCObject *target, SEL_MenuHandler selector);
	void setFontNameObj(const char *name);
	void setFontSizeObj(unsigned int s);

protected:
	void recreateLabel();
};

class CC_DLL CCMenuItemSprite : public CCMenuItem
{
public:
	CCNode *_pNormalImage, *_pSelectedImage, *_pDisabledImage;

public:
	CCMenuItemSprite();
	virtual ~CCMenuItemSprite();

	static CCMenuItemSprite *create(CCNode *normalSprite, CCNode *selectedSprite, CCNode *disabledSprite = nullptr);
	static CCMenuItemSprite *create(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, SEL_MenuHandler selector);
	static CCMenuItemSprite *create(CCNode *normalSprite, CCNode *selectedSprite, CCNode *disabledSprite, CCObject *target, SEL_MenuHandler selector);

	bool initWithNormalSprite(CCNode *normalSprite, CCNode *selectedSprite, CCNode *disabledSprite, CCObject *target, SEL_MenuHandler selector);

	virtual void selected();
	virtual void unselected();
	virtual void setEnabled(bool bEnabled);

	virtual CCNode *getNormalImage();
	virtual void setNormalImage(CCNode *);
	virtual CCNode *getSelectedImage();
	virtual void setSelectedImage(CCNode *);
	virtual CCNode *getDisabledImage();
	virtual void setDisabledImage(CCNode *);

protected:
	virtual void updateImagesVisibility();
};

class CC_DLL CCMenuItemImage : public CCMenuItemSprite
{
public:
	CCMenuItemImage();
	virtual ~CCMenuItemImage();

	static CCMenuItemImage *create();
	static CCMenuItemImage *create(const char *normalImage, const char *selectedImage);
	static CCMenuItemImage *create(const char *normalImage, const char *selectedImage, const char *disabledImage);
	static CCMenuItemImage *create(const char *normalImage, const char *selectedImage, CCObject *target, SEL_MenuHandler selector);
	static CCMenuItemImage *create(const char *normalImage, const char *selectedImage, const char *disabledImage, CCObject *target, SEL_MenuHandler selector);

	bool initWithNormalImage(const char *normalImage, const char *selectedImage, const char *disabledImage, CCObject *target, SEL_MenuHandler selector);
	void setDisabledSpriteFrame(CCSpriteFrame *frame);
	void setNormalSpriteFrame(CCSpriteFrame *frame);
	void setSelectedSpriteFrame(CCSpriteFrame *frame);
	
	virtual bool init();
};

class CC_DLL CCMenuItemToggle : public CCMenuItem
{
public:
	unsigned int _uSelectedIndex;
	CCArray *_pSubItems;

public:
	CCMenuItemToggle();
	virtual ~CCMenuItemToggle();

	static CCMenuItemToggle *create();
	static CCMenuItemToggle *create(CCMenuItem *item);
	static CCMenuItemToggle *createWithTarget(CCObject *target, SEL_MenuHandler selector, CCArray *menuItems);
	static CCMenuItemToggle *createWithTarget(CCObject *target, SEL_MenuHandler selector, CCMenuItem *item, ...);

	void addSubItem(CCMenuItem *item);
	bool initWithItem(CCMenuItem *item);
	bool initWithTarget(CCObject *target, SEL_MenuHandler selector, CCMenuItem *item, va_list args);
	CCMenuItem *selectedItem();

	virtual void activate();
	virtual void selected();
	virtual void unselected();
	virtual void setEnabled(bool var);

	virtual unsigned int getSelectedIndex();
	virtual void setSelectedIndex(unsigned int);
	virtual CCArray *getSubItems();
	virtual void setSubItems(CCArray *);
};

NS_CC_END