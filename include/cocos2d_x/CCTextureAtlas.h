#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "support/ccTypes.h"

NS_CC_BEGIN

class CCTexture2D;

class CC_DLL CCTextureAtlas : public CCObject
{
public:
	GLushort *_pIndices;
	GLuint _pBuffersVBO[2];
	bool _bDirty;
	unsigned int _uTotalQuads, _uCapacity;
	CCTexture2D *_pTexture;
	ccV3F_C4B_T2F_Quad *_pQuads;
	unsigned int _uTotalQuads2;

public:
	CCTextureAtlas();
	virtual ~CCTextureAtlas();

	static CCTextureAtlas *create(const char *, unsigned int);
	static CCTextureAtlas *createWithTexture(CCTexture2D *, unsigned int);

	const char *description();
	void drawNumberOfQuads(unsigned int);
	void drawNumberOfQuads(unsigned int, unsigned int);
	void drawQuads();
	void fillWithEmptyQuadsFromIndex(unsigned int, unsigned int);
	void increaseTotalQuadsWith(unsigned int);
	bool initWithFile(const char *, unsigned int);
	bool initWithTexture(CCTexture2D *, unsigned int);
	void insertQuad(_ccV3F_C4B_T2F_Quad *, unsigned int);
	void insertQuadFromIndex(unsigned int, unsigned int);
	void insertQuads(_ccV3F_C4B_T2F_Quad *, unsigned int, unsigned int);
	bool isDirty();
	void listenBackToForeground(CCObject *);
	void moveQuadsFromIndex(unsigned int, unsigned int);
	void moveQuadsFromIndex(unsigned int, unsigned int, unsigned int);
	void removeAllQuads();
	void removeQuadAtIndex(unsigned int);
	void removeQuadsAtIndex(unsigned int, unsigned int);
	bool resizeCapacity(unsigned int);
	void setDirty(bool);
	void updateQuad(_ccV3F_C4B_T2F_Quad *, unsigned int);

private:
	void mapBuffers();
	void setupIndices();
	void setupVBO();

public:
	virtual unsigned int getTotalQuads();
	virtual unsigned int getCapacity();
	virtual CCTexture2D *getTexture();
	virtual void setTexture(CCTexture2D *);
	virtual _ccV3F_C4B_T2F_Quad *getQuads();
	virtual void setQuads(_ccV3F_C4B_T2F_Quad *);
};

NS_CC_END