#pragma once

#include "GDAPI_Macros.h"

#include "cocos2d_x/CCNode.h"

NS_CC_EXT_BEGIN

class CC_DLL CCScale9Sprite : public CCNodeRGBA
{
public:
	CCSize _originalSize, _preferredSize;
	CCRect _capInsets;
	float _insetLeft, _insetTop, _insetRight, _insetBottom;
	bool _bSpritesGenerated;
	CCRect _spriteRect;
	bool _bSpriteFrameRotated;
	CCRect _capInsetsInternal;
	bool _positionsAreDirty;
	CCSpriteBatchNode *_scale9Image;
	CCSprite *_topLeft, *_top, *_topRight, *_left, *_centre, *_right, *_bottomLeft, *_bottom, *_bottomRight;
	bool _opacityModifyRGB;
	GLubyte _opacity;
	ccColor3B _color;

public:
	CCScale9Sprite();
	virtual ~CCScale9Sprite();

	static CCScale9Sprite *create();
	static CCScale9Sprite *create(const char *file);
	static CCScale9Sprite *create(const char *file, CCRect rect);
	static CCScale9Sprite *create(const char *file, CCRect rect, CCRect capInsets);
	static CCScale9Sprite *create(CCRect capInsets, const char *file);
	static CCScale9Sprite *createWithSpriteFrame(CCSpriteFrame *spriteFrame);
	static CCScale9Sprite *createWithSpriteFrame(CCSpriteFrame *spriteFrame, CCRect capInsets);
	static CCScale9Sprite *createWithSpriteFrameName(const char *spriteFrameName);
	static CCScale9Sprite *createWithSpriteFrameName(const char *spriteFrameName, CCRect capInsets);

	CCSize getOriginalSize() const;
	CCScale9Sprite *resizableSpriteWithCapInsets(CCRect capInsets);
	void setBlendAdditive(bool);

protected:
	void updateCapInset();
	void updatePositions();

public:
	virtual bool init();
	virtual void setContentSize(const CCSize &size);
	virtual void visit();
	virtual GLubyte getOpacity();
	virtual void setOpacity(GLubyte opacity);
	virtual void updateDisplayedOpacity(GLubyte parentOpacity);
	virtual const ccColor3B &getColor();
	virtual void setColor(const ccColor3B &color);
	virtual void updateDisplayedColor(const cocos2d::ccColor3B& parentColor);
	virtual void setOpacityModifyRGB(bool bValue);
	virtual bool isOpacityModifyRGB();

	virtual CCSize getPreferredSize();
	virtual void setPreferredSize(CCSize);
	virtual CCRect getCapInsets();
	virtual void setCapInsets(CCRect);
	virtual float getInsetLeft();
	virtual void setInsetLeft(float);
	virtual float getInsetTop();
	virtual void setInsetTop(float);
	virtual float getInsetRight();
	virtual void setInsetRight(float);
	virtual float getInsetBottom();
	virtual void setInsetBottom(float);
	virtual bool initWithBatchNode(CCSpriteBatchNode *batchnode, CCRect rect, bool rotated, CCRect capInsets);
	virtual bool initWithBatchNode(CCSpriteBatchNode *batchnode, CCRect rect, CCRect capInsets);
	virtual bool initWithFile(const char *file, CCRect rect, CCRect capInsets);
	virtual bool initWithFile(const char *file, CCRect rect);
	virtual bool initWithFile(CCRect capInsets, const char *file);
	virtual bool initWithFile(const char *file);
	virtual bool initWithSpriteFrame(CCSpriteFrame *spriteFrame, CCRect capInsets);
	virtual bool initWithSpriteFrame(CCSpriteFrame *spriteFrame);
	virtual bool initWithSpriteFrameName(const char*spriteFrameName, CCRect capInsets);
	virtual bool initWithSpriteFrameName(const char*spriteFrameName);
	virtual bool updateWithBatchNode(CCSpriteBatchNode *batchnode, CCRect rect, bool rotated, CCRect capInsets);
	virtual void setSpriteFrame(CCSpriteFrame *spriteFrame);
};

NS_CC_EXT_END