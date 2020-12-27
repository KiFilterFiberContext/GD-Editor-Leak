#pragma once

#include "GDAPI_Macros.h"

#include "CCSpriteBatchNode.h"
#include <set>

NS_CC_BEGIN

enum
{
	kCCLabelAutomaticWidth = -1,
};

struct _FontDefHashElement;

typedef struct _BMFontDef
{
	unsigned int charID;
	CCRect rect;
	short xOffset, yOffset;
	short xAdvance;
} ccBMFontDef;

typedef struct _BMFontPadding
{
	int left, top, right, bottom;
} ccBMFontPadding;

typedef struct _FontDefHashElement
{
	unsigned int key;
	ccBMFontDef fontDef;
	unsigned char hh[8 * sizeof(int)]; //TODO: Add UT_hash_handle type to hh
} tCCFontDefHashElement;

typedef struct _KerningHashElement
{
	int key, amount;
	unsigned char hh[8 * sizeof(int)]; //TODO: Add UT_hash_handle type to hh
} tCCKerningHashElement;

class CC_DLL CCBMFontConfiguration : public CCObject
{
public:
	tCCFontDefHashElement *_pFontDefDictionary;
	int _nCommonHeight;
	ccBMFontPadding _tPadding;
	std::string _sAtlasName;
	tCCKerningHashElement *_pKerningDictionary;
	std::set<unsigned int> *_pCharacterSet;

public:
	CCBMFontConfiguration();
	virtual ~CCBMFontConfiguration();

	static CCBMFontConfiguration *create(const char *FNTfile);

	const char *description();
	const char *getAtlasName();
	std::set<unsigned int> *getCharacterSet() const;
	bool initWithFNTfile(const char *);
	void setAtlasName(const char *);

private:
	void parseCharacterDefinition(std::string, _BMFontDef *);
	void parseCommonArguments(std::string);
	std::set<unsigned int> *parseConfigFile(const char *);
	void parseImageFileName(std::string, const char *);
	void parseInfoArguments(std::string);
	void parseKerningEntry(std::string);
	void purgeFontDefDictionary();
	void purgeKerningDictionary();
};

class CC_DLL CCLabelBMFont : public CCSpriteBatchNode, public CCLabelProtocol, public CCRGBAProtocol
{
public:
	unsigned short *_sString;
	std::string _sFntFile;
	unsigned short *_sInitialString;
	std::string _sInitialStringUTF8;
	CCTextAlignment _pAlignment;
	float _fWidth;
	CCBMFontConfiguration *_pConfiguration;
	bool _bLineBreakWithoutSpaces;
	CCPoint _tImageOffset;
	CCSprite *_pReusedChar;
	GLubyte _cDisplayedOpacity, _cRealOpacity;
	ccColor3B _tDisplayedColor, _tRealColor;
	bool _bCascadeColorEnabled, _bCascadeOpacityEnabled, _bIsOpacityModifyRGB;
	bool _isBatched;
	CCArray *_targetArray;
	int _unk0; //TODO: Add last argument to CCLabelBMFont

public:
	CCLabelBMFont();
	virtual ~CCLabelBMFont();

	static CCLabelBMFont *create(const char *text, const char *font);
	static CCLabelBMFont *create(const char *text, const char *font, float fontSize);
	static CCLabelBMFont *create(const char *text, const char *font, float fontSize, CCTextAlignment);
	static CCLabelBMFont *create(const char *text, const char *font, float fontSize, CCTextAlignment, CCPoint);
	static CCLabelBMFont *create();
	static CCLabelBMFont *createBatched(const char *, const char *, CCArray *);
	static void __cdecl purgeCachedData();

	void createFontChars();
	CCBMFontConfiguration *getConfiguration() const;
	const char *getFntFile();
	bool getIsBatched() const;
	CCArray *getTargetArray() const;
	bool initWithString(const char *text, const char *font, float fontSize, CCTextAlignment, CCPoint);
	void limitLabelWidth(float, float, float);
	void setFntFile(const char *);
	void setIsBatched(bool);
	void setTargetArray(CCArray *);

private:
	float getLetterPosXLeft(CCSprite *);
	float getLetterPosXRight(CCSprite *);
	int kerningAmountForFirst(unsigned short, unsigned short);

public:
	virtual bool init();
	virtual void setScaleX(float);
	virtual void setScaleY(float);
	virtual void setScale(float);
	virtual void setAnchorPoint(const CCPoint &);

	virtual void setString(const char *);
	virtual void setString(const char *, bool);
	virtual const char *getString();
	virtual void setCString(const char *);
	virtual void updateLabel();
	virtual void setAlignment(CCTextAlignment);
	virtual void setWidth(float);
	virtual void setLineBreakWithoutSpace(bool);

	virtual bool isOpacityModifyRGB();
	virtual void setOpacityModifyRGB(bool);
	virtual unsigned char getOpacity();
	virtual unsigned char getDisplayedOpacity();
	virtual void setOpacity(unsigned char);
	virtual void updateDisplayedOpacity(unsigned char);
	virtual bool isCascadeOpacityEnabled();
	virtual void setCascadeOpacityEnabled(bool);
	virtual const _ccColor3B &getColor();
	virtual const _ccColor3B &getDisplayedColor();
	virtual void setColor(const _ccColor3B &);
	virtual void updateDisplayedColor(const _ccColor3B &);
	virtual bool isCascadeColorEnabled();
	virtual void setCascadeColorEnabled(bool);
	
protected:
	virtual void setString(unsigned short *, bool);
};

CC_DLL CCBMFontConfiguration *FNTConfigLoadFile(const char *file);
CC_DLL void FNTConfigRemoveCache();

NS_CC_END