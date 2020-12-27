#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"

NS_CC_BEGIN

class CC_DLL CCImage : public CCObject
{
public:
	typedef enum
	{
		kFmtJpg = 0,
		kFmtPng,
		kFmtTiff,
		kFmtWebp,
		kFmtRawData,
		kFmtUnKnown
	} EImageFormat;
	typedef enum
	{
		kAlignCenter = 0x33,
		kAlignTop = 0x13,
		kAlignTopRight = 0x12,
		kAlignRight = 0x32,
		kAlignBottomRight = 0x22,
		kAlignBottom = 0x23,
		kAlignBottomLeft = 0x21,
		kAlignLeft = 0x31,
		kAlignTopLeft = 0x11
	} ETextAlign;

public:
	unsigned short _nWidth, _nHeight;
	int _nBitsPerComponent;
	unsigned char *_pData;
	bool _bHasAlpha, _bPreMulti;

public:
	CCImage();
	virtual ~CCImage();

	int getBitsPerComponent() const;
	unsigned char *getData();
	int getDataLen();
	unsigned short getHeight() const;
	unsigned short getWidth() const;
	bool hasAlpha();
	bool initWithImageData(void *, int, EImageFormat, int, int, int);
	bool initWithImageFile(const char *, EImageFormat);
	bool initWithImageFileThreadSafe(const char *, EImageFormat);
	bool initWithString(const char *, int, int, ETextAlign, const char *, int);
	bool isPremultipliedAlpha();
	bool saveToFile(const char *, bool);

protected:
	bool _initWithJpgData(void *, int);
	bool _initWithPngData(void *, int);
	bool _initWithRawData(void *, int, int, int, int, bool);
	bool _initWithTiffData(void *, int);
	bool _initWithWebpData(void *, int);
	bool _saveImageToJPG(const char *);
	bool _saveImageToPNG(const char *, bool);
};

NS_CC_END