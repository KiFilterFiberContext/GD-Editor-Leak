#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCGeometry.h"
#include <string>

NS_CC_BEGIN

class CCTexture2D;
class CCZone;

class CC_DLL CCSpriteFrame : public CCObject
{
public:
	CCPoint _obOffset;
	CCSize _obOriginalSize;
	CCRect _obRectInPixels;
	bool _bRotated;
	CCRect _obRect;
	CCPoint _obOffsetInPixels;
	CCSize _obOriginalSizeInPixels;
	CCTexture2D *_pobTexture;
	std::string _strTextureFilename, _strFrameName;

public:
	CCSpriteFrame();
	virtual ~CCSpriteFrame();

	static CCSpriteFrame *create(const char *, const CCRect &);
	static CCSpriteFrame *create(const char *, const CCRect &, bool, const CCPoint &, const CCSize &);
	static CCSpriteFrame *createWithTexture(CCTexture2D *, const CCRect &);
	static CCSpriteFrame *createWithTexture(CCTexture2D *, const CCRect &, bool, const CCPoint &, const CCSize &);
	std::string getFrameName() const;
	const CCPoint &getOffset();
	const CCPoint &getOffsetInPixels();
	const CCSize &getOriginalSize();
	const CCSize &getOriginalSizeInPixels();
	const CCRect &getRect();
	const CCRect &getRectInPixels();
	CCTexture2D *getTexture();
	bool initWithTexture(CCTexture2D *, const CCRect &);
	bool initWithTexture(CCTexture2D *, const CCRect &, bool, const CCPoint &, const CCSize &);
	bool initWithTextureFilename(const char *, const CCRect &);
	bool initWithTextureFilename(const char *, const CCRect &, bool, const CCPoint &, const CCSize &);
	bool isRotated();
	void setFrameName(std::string);
	void setOffset(const CCPoint &);
	void setOffsetInPixels(const CCPoint &);
	void setOriginalSize(const CCSize &);
	void setOriginalSizeInPixels(const CCSize &);
	void setRect(const CCRect &);
	void setRectInPixels(const CCRect &);
	void setRotated(bool);
	void setTexture(CCTexture2D *);

	virtual CCObject *copyWithZone(CCZone *);
};

NS_CC_END