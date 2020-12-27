#pragma once

#include "GDAPI_Macros.h"

#include <string>
#include "../CCGeometry.h"
#include "../CCGL.h"

NS_CC_BEGIN

typedef struct _ccColor3B
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
} ccColor3B;

static inline ccColor3B ccc3(const GLubyte r, const GLubyte g, const GLubyte b) {
	ccColor3B c = { r, g, b };
	return c;
}

static const ccColor3B ccWHITE = { 255, 255, 255 };
static const ccColor3B ccYELLOW = { 255, 255, 0 };
static const ccColor3B ccBLUE = { 0, 0, 255 };
static const ccColor3B ccGREEN = { 0, 255, 0 };
static const ccColor3B ccRED = { 255, 0, 0 };
static const ccColor3B ccMAGENTA = { 255, 0, 255 };
static const ccColor3B ccBLACK = { 0, 0, 0 };
static const ccColor3B ccORANGE = { 255, 127, 0 };
static const ccColor3B ccGRAY = { 166, 166, 166 };

typedef struct _ccColor4B
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
} ccColor4B;

static inline ccColor4B ccc4(const GLubyte r, const GLubyte g, const GLubyte b, const GLubyte o) {
	ccColor4B c = { r, g, b, o };
	return c;
}

typedef struct _ccColor4F
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
} ccColor4F;

static inline ccColor4F ccc4FFromccc3B(ccColor3B c) {
	ccColor4F c4 = { c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, 1.0f };
	return c4;
}

static inline ccColor4F ccc4f(const GLfloat r, const GLfloat g, const GLfloat b, const GLfloat a) {
	ccColor4F c4 = { r, g, b, a };
	return c4;
}

static inline ccColor4F ccc4FFromccc4B(ccColor4B c) {
	ccColor4F c4 = { c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f };
	return c4;
}

static inline bool ccc4FEqual(ccColor4F a, ccColor4F b) {
	return a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a;
}

typedef struct _ccVertex2F
{
	GLfloat x;
	GLfloat y;
} ccVertex2F;

static inline ccVertex2F vertex2(const float x, const float y) {
	ccVertex2F c = { x, y };
	return c;
}

typedef struct _ccVertex3F
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
} ccVertex3F;

static inline ccVertex3F vertex3(const float x, const float y, const float z) {
	ccVertex3F c = { x, y, z };
	return c;
}

typedef struct _ccTex2F
{
	GLfloat u;
	GLfloat v;
} ccTex2F;

static inline ccTex2F tex2(const float u, const float v) {
	ccTex2F t = { u , v };
	return t;
}

typedef struct _ccPointSprite
{
	ccVertex2F pos;
	ccColor4B color;
	GLfloat size;
} ccPointSprite;

typedef struct _ccQuad2
{
	ccVertex2F tl;
	ccVertex2F tr;
	ccVertex2F bl;
	ccVertex2F br;
} ccQuad2;

typedef struct _ccQuad3
{
	ccVertex3F bl;
	ccVertex3F br;
	ccVertex3F tl;
	ccVertex3F tr;
} ccQuad3;

typedef struct _ccGridSize
{
	int x;
	int y;
} ccGridSize;

static inline ccGridSize ccg(const int x, const int y) {
	ccGridSize v = { x, y };
	return v;
}

typedef struct _ccV2F_C4B_T2F
{
	ccVertex2F vertices;
	ccColor4B colors;
	ccTex2F texCoords;
} ccV2F_C4B_T2F;

typedef struct _ccV2F_C4F_T2F
{
	ccVertex2F vertices;
	ccColor4F colors;
	ccTex2F texCoords;
} ccV2F_C4F_T2F;

typedef struct _ccV3F_C4B_T2F
{
	ccVertex3F vertices;
	ccColor4B colors;
	ccTex2F texCoords;
} ccV3F_C4B_T2F;

typedef struct _ccV2F_C4B_T2F_Quad
{
	ccV2F_C4B_T2F bl;
	ccV2F_C4B_T2F br;
	ccV2F_C4B_T2F tl;
	ccV2F_C4B_T2F tr;
} ccV2F_C4B_T2F_Quad;

typedef struct _ccV3F_C4B_T2F_Quad
{
	ccV3F_C4B_T2F tl;
	ccV3F_C4B_T2F bl;
	ccV3F_C4B_T2F tr;
	ccV3F_C4B_T2F br;
} ccV3F_C4B_T2F_Quad;

typedef struct _ccV2F_C4F_T2F_Quad
{
	ccV2F_C4F_T2F bl;
	ccV2F_C4F_T2F br;
	ccV2F_C4F_T2F tl;
	ccV2F_C4F_T2F tr;
} ccV2F_C4F_T2F_Quad;

typedef struct _ccBlendFunc
{
	GLenum src;
	GLenum dst;
} ccBlendFunc;

typedef enum
{
	kCCVerticalTextAlignmentTop,
	kCCVerticalTextAlignmentCenter,
	kCCVerticalTextAlignmentBottom
} CCVerticalTextAlignment;

typedef enum
{
	kCCTextAlignmentLeft,
	kCCTextAlignmentCenter,
	kCCTextAlignmentRight
} CCTextAlignment;

typedef struct _ccT2F_Quad
{
	ccTex2F bl;
	ccTex2F br;
	ccTex2F tl;
	ccTex2F tr;
} ccT2F_Quad;

typedef struct
{
	ccT2F_Quad texCoords;
	float delay;
	CCSize size;
} ccAnimationFrameData;

typedef struct _ccFontShadow
{
public:
	_ccFontShadow() : m_shadowEnabled(false) {}

	bool m_shadowEnabled;
	CCSize m_shadowOffset;
	float m_shadowBlur;
	float m_shadowOpacity;

} ccFontShadow;

typedef struct _ccFontStroke
{
public:
	_ccFontStroke() : m_strokeEnabled(false) {}

	bool m_strokeEnabled;
	ccColor3B m_strokeColor;
	float m_strokeSize;

} ccFontStroke;

typedef struct _ccFontDefinition
{
public:
	_ccFontDefinition() :
		m_alignment(kCCTextAlignmentCenter),
		m_vertAlignment(kCCVerticalTextAlignmentTop),
		m_fontFillColor(ccWHITE) { m_dimensions = CCSize(0, 0); }

	std::string m_fontName;
	int m_fontSize;
	CCTextAlignment m_alignment;
	CCVerticalTextAlignment m_vertAlignment;
	CCSize m_dimensions;
	ccColor3B m_fontFillColor;
	ccFontShadow m_shadow;
	ccFontStroke m_stroke;
} ccFontDefinition;

NS_CC_END