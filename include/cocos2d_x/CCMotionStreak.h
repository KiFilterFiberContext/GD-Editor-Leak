#pragma once

#include "GDAPI_Macros.h"

#include "CCTexture2D.h"
#include "CCProtocols.h"
#include "CCNode.h"

NS_CC_BEGIN

class CC_DLL CCMotionStreak : public CCNodeRGBA, public CCTextureProtocol
{
public:
	bool _bFastMode, _bStartingPositionInitialized, _bStrokeRunning;
	CCTexture2D *_pTexture;
	ccBlendFunc _tBlendFunc;
	CCPoint _tPositionR;
	float _fStroke, _fFadeDelta, _fMinSeg;
	unsigned int _uMaxPoints, _uNuPoints, _uPreviousNuPoints;
	CCPoint *_pPointVertexes;
	float *_pPointState;
	ccVertex2F *_pVertices;
	GLubyte *_pColorPointer;
	ccTex2F *_pTexCoords;
	bool _bRepeatMode;
	float _repeatModeValue;
	int _unk1; //TODO: Rename argument in CCMotionStreak
	char _unk0; //TODO: Rename argument in CCMotionStreak
	float _fMaxSeg;
	bool _dontOpacityFade;

public:
	CCMotionStreak();
	virtual ~CCMotionStreak();

	static CCMotionStreak *create(float, float, float, const ccColor3B &, CCTexture2D *);
	static CCMotionStreak *create(float, float, float, const ccColor3B &, const char *);

	void enableRepeatMode(float);
	bool getDontOpacityFade() const;
	float getM_fMaxSeg() const;
	bool initWithFade(float, float, float, const ccColor3B &, CCTexture2D *);
	bool initWithFade(float, float, float, const ccColor3B &, const char *);
	bool isFastMode();
	bool isStartingPositionInitialized();
	void reset();
	void resumeStroke();
	void setDontOpacityFade(bool);
	void setFastMode(bool);
	void setM_fMaxSeg(float);
	void setStartingPositionInitialized(bool);
	void setStroke(float);
	void stopStroke();
	void tintWithColor(ccColor3B);

	virtual void update(float);
	virtual void setPosition(const CCPoint &);
	virtual void draw();
	virtual unsigned char getOpacity();
	virtual void setOpacity(unsigned char);
	virtual void setOpacityModifyRGB(bool);
	virtual bool isOpacityModifyRGB();
	virtual CCTexture2D *getTexture();
	virtual void setTexture(CCTexture2D *);
	virtual void setBlendFunc(ccBlendFunc);
	virtual ccBlendFunc getBlendFunc();
};

NS_CC_END