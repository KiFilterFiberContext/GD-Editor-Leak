#pragma once

#include "GDAPI_Macros.h"

#include "CCNode.h"
#include "CCSprite.h"

NS_CC_BEGIN

typedef enum eImageFormat
{
	kCCImageFormatJPEG = 0,
	kCCImageFormatPNG = 1,
} tCCImageFormat;

class CC_DLL CCRenderTexture : public CCNode
{
public:
	CCSprite *_pSprite;
	GLuint _uFBO;
	GLuint _uDepthRenderBufffer;
	GLint _nOldFBO;
	CCTexture2D *_pTexture, *_pTextureCopy;
	CCImage *_pUITextureImage;
	GLenum _ePixelFormat;
	GLbitfield _uClearFlags;
	ccColor4F _sClearColor;
	GLclampf _fClearDepth;
	GLint _nClearStencil;
	bool _bAutoDraw;

public:
	CCRenderTexture();
	virtual ~CCRenderTexture();

	static CCRenderTexture *create(int w, int h);
	static CCRenderTexture *create(int w, int h, CCTexture2DPixelFormat);
	static CCRenderTexture *create(int w, int h, CCTexture2DPixelFormat, unsigned int uDepthStencilFormat);

	void begin();
	void beginWithClear(float, float, float, float);
	void beginWithClear(float, float, float, float, float);
	void beginWithClear(float, float, float, float, float, int);
	void clear(float, float, float, float);
	void clearDepth(float);
	void clearStencil(int);
	void end();
	void endToLua();
	_ccColor4F const &getClearColor() const;
	float getClearDepth() const;
	unsigned int getClearFlags() const;
	int getClearStencil() const;
	bool initWithWidthAndHeight(int, int, CCTexture2DPixelFormat);
	bool initWithWidthAndHeight(int, int, CCTexture2DPixelFormat, unsigned int);
	bool isAutoDraw() const;
	void listenToBackground(CCObject *);
	void listenToForeground(CCObject *);
	CCImage *newCCImage(bool);
	bool saveToFile(const char *);
	bool saveToFile(const char *, eImageFormat);
	void setAutoDraw(bool);
	void setClearColor(const _ccColor4F &);
	void setClearDepth(float);
	void setClearFlags(unsigned int);
	void setClearStencil(float);

private:
	void beginWithClear(float, float, float, float, float, int, unsigned int);

public:
	virtual void draw();
	virtual void visit();
	
	virtual CCSprite *getSprite();
	virtual void setSprite(CCSprite *);
};

NS_CC_END