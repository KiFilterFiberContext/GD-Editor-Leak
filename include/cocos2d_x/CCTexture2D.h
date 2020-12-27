#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCGeometry.h"
#include "support/ccTypes.h"

NS_CC_BEGIN

class CCImage;

typedef enum
{
	kCCTexture2DPixelFormat_RGBA8888,
	kCCTexture2DPixelFormat_RGB888,
	kCCTexture2DPixelFormat_RGB565,
	kCCTexture2DPixelFormat_A8,
	kCCTexture2DPixelFormat_I8,
	kCCTexture2DPixelFormat_AI88,
	kCCTexture2DPixelFormat_RGBA4444,
	kCCTexture2DPixelFormat_RGB5A1,
	kCCTexture2DPixelFormat_PVRTC4,
	kCCTexture2DPixelFormat_PVRTC2,

	kCCTexture2DPixelFormat_Default = kCCTexture2DPixelFormat_RGBA8888,

	kTexture2DPixelFormat_RGBA8888 = kCCTexture2DPixelFormat_RGBA8888,
	kTexture2DPixelFormat_RGB888 = kCCTexture2DPixelFormat_RGB888,
	kTexture2DPixelFormat_RGB565 = kCCTexture2DPixelFormat_RGB565,
	kTexture2DPixelFormat_A8 = kCCTexture2DPixelFormat_A8,
	kTexture2DPixelFormat_RGBA4444 = kCCTexture2DPixelFormat_RGBA4444,
	kTexture2DPixelFormat_RGB5A1 = kCCTexture2DPixelFormat_RGB5A1,
	kTexture2DPixelFormat_Default = kCCTexture2DPixelFormat_Default

} CCTexture2DPixelFormat;

class CCGLProgram;

typedef struct _ccTexParams
{
	GLuint minFilter;
	GLuint magFilter;
	GLuint wrapS;
	GLuint wrapT;
} ccTexParams;

class CC_DLL CCTexture2D : public CCObject
{
public:
	bool _bPVRHaveAlphaPremultiplied;
	CCTexture2DPixelFormat _ePixelFormat;
	unsigned int _uPixelsWide, _uPixelsHigh;
	GLuint _uName;
	GLfloat _fMaxS, _fMaxT;
	CCSize _tContentSize;
	bool _bHasPremultipliedAlpha, _bHasMipmaps;
	CCGLProgram *_pShaderProgram;

public:
	CCTexture2D();
	virtual ~CCTexture2D();

	static void PVRImagesHavePremultipliedAlpha(bool);
	static CCTexture2DPixelFormat defaultAlphaPixelFormat();
	static void setDefaultAlphaPixelFormat(CCTexture2DPixelFormat);

	unsigned int bitsPerPixelForFormat(CCTexture2DPixelFormat);
	unsigned int bitsPerPixelForFormat();
	const char *description();
	void drawAtPoint(const CCPoint &);
	void drawInRect(const CCRect &);
	void generateMipmap();
	const CCSize &getContentSizeInPixels();
	bool hasMipmaps();
	bool hasPremultipliedAlpha();
	bool initWithData(void const *, CCTexture2DPixelFormat, unsigned int, unsigned int, const CCSize &);
	bool initWithETCFile(const char *);
	bool initWithImage(CCImage *);
	bool initWithPVRFile(const char *);
	bool initWithString(const char *, const char *, float);
	bool initWithString(const char *, const char *, float, const CCSize &, CCTextAlignment, CCVerticalTextAlignment);
	bool initWithString(const char *, _ccFontDefinition *);
	void *keepData(void *, unsigned int);
	void releaseData(void *);
	void releaseGLTexture();
	void setAliasTexParameters();
	void setAntiAliasTexParameters();
	void setTexParameters(_ccTexParams *);
	const char *stringForFormat();

private:
	bool initPremultipliedATextureWithImage(CCImage *, unsigned int, unsigned int);

public:
	virtual CCTexture2DPixelFormat getPixelFormat();
	virtual unsigned int getPixelsWide();
	virtual unsigned int getPixelsHigh();
	virtual unsigned int getName();
	virtual float getMaxS();
	virtual void setMaxS(float);
	virtual float getMaxT();
	virtual void setMaxT(float);
	virtual CCSize getContentSize();
	virtual CCGLProgram *getShaderProgram();
	virtual void setShaderProgram(CCGLProgram *);
};

NS_CC_END