#pragma once

#include "GDAPI_Macros.h"

#include "support/ccTypes.h"
#include "CCObject.h"
#include "CCDirector.h"

NS_CC_BEGIN

class CCTexture2D;
class CCGrabber;

class CC_DLL CCGridBase : public CCObject
{
public:
	bool _bActive;
	int _nReuseGrid;
	CCSize _sGridSize;
	CCTexture2D *_pTexture;
	CCPoint _obStep;
	CCGrabber *_pGrabber;
	bool _bIsTextureFlipped;
	CCGLProgram *_pShaderProgram;
	ccDirectorProjection _directorProjection;

public:
	CCGridBase();
	virtual ~CCGridBase();

	static CCGridBase *create(const CCSize &);
	static CCGridBase *create(const CCSize &, CCTexture2D *, bool);

	void afterDraw(CCNode *);
	void beforeDraw();
	const CCSize &getGridSize();
	int getReuseGrid();
	const CCPoint &getStep();
	bool initWithSize(const CCSize &);
	bool initWithSize(const CCSize &, CCTexture2D *, bool);
	bool isActive();
	bool isTextureFlipped();
	void set2DProjection();
	void setActive(bool);
	void setGridSize(const CCSize &);
	void setReuseGrid(int);
	void setStep(const CCPoint &);
	void setTextureFlipped(bool);

	virtual void blit();
	virtual void reuse();
	virtual void calculateVertexPoints();
};

class CC_DLL CCGrid3D : public CCGridBase
{
public:
	GLvoid *_pTexCoordinates;
	GLvoid *_pVertices;
	GLvoid *_pOriginalVertices;
	GLushort *_pIndices;

public:
	CCGrid3D();
	virtual ~CCGrid3D();

	static CCGrid3D *create(const CCSize &);
	static CCGrid3D *create(const CCSize &, CCTexture2D *, bool);

	ccVertex3F originalVertex(const CCPoint &pos);
	void setVertex(const CCPoint &, _ccVertex3F const &);
	ccVertex3F vertex(const CCPoint &pos);

	virtual void blit();
	virtual void reuse();
	virtual void calculateVertexPoints();
};

class CC_DLL CCTiledGrid3D : public CCGridBase
{
public:
	GLvoid *_pTexCoordinates;
	GLvoid *_pVertices;
	GLvoid *_pOriginalVertices;
	GLushort *_pIndices;

public:
	CCTiledGrid3D();
	virtual ~CCTiledGrid3D();

	static CCTiledGrid3D *create(const CCSize &);
	static CCTiledGrid3D *create(const CCSize &, CCTexture2D *, bool);

	ccQuad3 originalTile(const CCPoint &pos);
	void setTile(const CCPoint &, _ccQuad3 const &);
	ccQuad3 tile(const CCPoint &pos);

	virtual void blit();
	virtual void reuse();
	virtual void calculateVertexPoints();
};

NS_CC_END