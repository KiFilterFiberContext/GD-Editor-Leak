#pragma once

#include "GDAPI_Macros.h"

#include "CCScene.h"

NS_CC_BEGIN

class CCActionInterval;
class CCNode;

class CC_DLL CCTransitionEaseScene
{
public:
	virtual CCActionInterval *easeActionWithAction(CCActionInterval *action) = 0;
};

typedef enum
{
	kCCTransitionOrientationLeftOver = 0,
	kCCTransitionOrientationRightOver = 1,
	kCCTransitionOrientationUpOver = 0,
	kCCTransitionOrientationDownOver = 1,
} tOrientation;

class CC_DLL CCTransitionScene : public CCScene
{
public:
	CCScene *_pInScene, *_pOutScene;
	float _fDuration;
	bool _bIsInSceneOnTop, _bIsSendCleanupToScene;

public:
	CCTransitionScene();
	virtual ~CCTransitionScene();

	static CCTransitionScene *create(float, CCScene *);

	void finish();
	void hideOutShowIn();
	
private:
	void setNewScene(float);

public:
	virtual void onEnter();
	virtual void onExit();
	virtual void cleanup();
	virtual void draw();

	virtual bool initWithDuration(float, CCScene *);

protected:
	virtual void sceneOrder();
};

class CC_DLL CCTransitionSceneOriented : public CCTransitionScene
{
public:
    tOrientation _eOrientation;

public:
    CCTransitionSceneOriented();
    virtual ~CCTransitionSceneOriented();

    static CCTransitionSceneOriented *create(float t, CCScene* scene, tOrientation orientation);

    virtual bool initWithDuration(float t, CCScene* scene, tOrientation orientation);
};

class CC_DLL CCTransitionRotoZoom : public CCTransitionScene
{
public:
    CCTransitionRotoZoom();
    virtual ~CCTransitionRotoZoom();

	static CCTransitionRotoZoom *create(float t, CCScene *scene);

    virtual void onEnter();
};

class CC_DLL CCTransitionJumpZoom : public CCTransitionScene
{
public:
    CCTransitionJumpZoom();
    virtual ~CCTransitionJumpZoom();

	static CCTransitionJumpZoom *create(float t, CCScene *scene);

    virtual void onEnter();
};

class CC_DLL CCTransitionMoveInL : public CCTransitionScene, public CCTransitionEaseScene
{
public:
    CCTransitionMoveInL();
    virtual ~CCTransitionMoveInL();

	static CCTransitionMoveInL *create(float t, CCScene *scene);

	virtual void onEnter();

    virtual void initScenes();
	virtual CCActionInterval *action();
	virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);
};

class CC_DLL CCTransitionMoveInR : public CCTransitionMoveInL
{
public:
    CCTransitionMoveInR();
    virtual ~CCTransitionMoveInR();

	static CCTransitionMoveInR *create(float t, CCScene *scene);

    virtual void initScenes();
};

class CC_DLL CCTransitionMoveInT : public CCTransitionMoveInL 
{
public:
    CCTransitionMoveInT();
    virtual ~CCTransitionMoveInT();

	static CCTransitionMoveInT *create(float t, CCScene *scene);

    virtual void initScenes();
};

class CC_DLL CCTransitionMoveInB : public CCTransitionMoveInL
{
public:
    CCTransitionMoveInB();
    virtual ~CCTransitionMoveInB();

	static CCTransitionMoveInT *create(float t, CCScene *scene);
    
    virtual void initScenes();
};

class CC_DLL CCTransitionSlideInL : public CCTransitionScene, public CCTransitionEaseScene
{
public:
    CCTransitionSlideInL();
    virtual ~CCTransitionSlideInL();

	static CCTransitionSlideInL *create(float t, CCScene *scene);

	virtual void onEnter();

protected:
	virtual void sceneOrder();

public:
    virtual void initScenes();
	virtual CCActionInterval *action();
	virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);
};

class CC_DLL CCTransitionSlideInR : public CCTransitionSlideInL 
{
public:
    CCTransitionSlideInR();
    virtual ~CCTransitionSlideInR();

	static CCTransitionSlideInR *create(float t, CCScene *scene);

protected:
	virtual void sceneOrder();

public:
    virtual void initScenes();
	virtual CCActionInterval *action();
};

class CC_DLL CCTransitionSlideInB : public CCTransitionSlideInL
{
public:
    CCTransitionSlideInB();
    virtual ~CCTransitionSlideInB();

	static CCTransitionSlideInB *create(float t, CCScene *scene);

protected:
	virtual void sceneOrder();

public:
	virtual void initScenes();
	virtual CCActionInterval *action();
};

class CC_DLL CCTransitionSlideInT : public CCTransitionSlideInL
{
public:
    CCTransitionSlideInT();
    virtual ~CCTransitionSlideInT();

    static CCTransitionSlideInT* create(float t, CCScene* scene);

protected:
	virtual void sceneOrder();

public:
	virtual void initScenes();
	virtual CCActionInterval *action();
};

class CC_DLL CCTransitionShrinkGrow : public CCTransitionScene , public CCTransitionEaseScene
{
public:
    CCTransitionShrinkGrow();
    virtual ~CCTransitionShrinkGrow();

	static CCTransitionShrinkGrow *create(float t, CCScene *scene);

    virtual void onEnter();

	virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);
};

class CC_DLL CCTransitionFlipX : public CCTransitionSceneOriented
{
public:
    CCTransitionFlipX();
    virtual ~CCTransitionFlipX();

	static CCTransitionFlipX *create(float t, CCScene *s);
	static CCTransitionFlipX *create(float t, CCScene *s, tOrientation o);
	
    virtual void onEnter();
};

class CC_DLL CCTransitionFlipY : public CCTransitionSceneOriented
{
public:
    CCTransitionFlipY();
    virtual ~CCTransitionFlipY();

	static CCTransitionFlipY *create(float t, CCScene *s);
	static CCTransitionFlipY *create(float t, CCScene *s, tOrientation o);

    virtual void onEnter();
};

class CC_DLL CCTransitionFlipAngular : public CCTransitionSceneOriented
{
public:
    CCTransitionFlipAngular();
    virtual ~CCTransitionFlipAngular();

	static CCTransitionFlipAngular *create(float t, CCScene *s);
	static CCTransitionFlipAngular *create(float t, CCScene *s, tOrientation o);

	virtual void onEnter();
};

class CC_DLL CCTransitionZoomFlipX : public CCTransitionSceneOriented
{
public:
	CCTransitionZoomFlipX();
	virtual ~CCTransitionZoomFlipX();
	
	static CCTransitionZoomFlipX *create(float t, CCScene *s);
	static CCTransitionZoomFlipX *create(float t, CCScene *s, tOrientation o);

	virtual void onEnter();
};

class CC_DLL CCTransitionZoomFlipY : public CCTransitionSceneOriented
{
public:
	CCTransitionZoomFlipY();
	virtual ~CCTransitionZoomFlipY();

	static CCTransitionZoomFlipY *create(float t, CCScene *s);
	static CCTransitionZoomFlipY *create(float t, CCScene *s, tOrientation o);
	
	virtual void onEnter();
};

class CC_DLL CCTransitionZoomFlipAngular : public CCTransitionSceneOriented
{
public:
	CCTransitionZoomFlipAngular();
	virtual ~CCTransitionZoomFlipAngular();

	static CCTransitionZoomFlipAngular *create(float t, CCScene *s);
	static CCTransitionZoomFlipAngular *create(float t, CCScene *s, tOrientation o);

	virtual void onEnter();
};

class CC_DLL CCTransitionFade : public CCTransitionScene
{
public:
	ccColor4B _tColor;

public:
	CCTransitionFade();
	virtual ~CCTransitionFade();

	static CCTransitionFade *create(float duration, CCScene *scene);
	static CCTransitionFade *create(float duration, CCScene *scene, const ccColor3B &color);

	virtual void onEnter();
	virtual void onExit();

	virtual bool initWithDuration(float t, CCScene *scene);
	virtual bool initWithDuration(float t, CCScene *scene, const ccColor3B &color);
};

class CC_DLL CCTransitionCrossFade : public CCTransitionScene
{
public:
	CCTransitionCrossFade();
	virtual ~CCTransitionCrossFade();

	static CCTransitionCrossFade *create(float t, CCScene *scene);

	virtual void onEnter();
	virtual void onExit();
	virtual void draw();
};

class CC_DLL CCTransitionTurnOffTiles : public CCTransitionScene, public CCTransitionEaseScene
{
public:
	CCTransitionTurnOffTiles();
	virtual ~CCTransitionTurnOffTiles();

	static CCTransitionTurnOffTiles *create(float t, CCScene *scene);

	virtual void onEnter();

protected:
	virtual void sceneOrder();

public:
	virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);
};

class CC_DLL CCTransitionSplitCols : public CCTransitionScene, public CCTransitionEaseScene
{
public:
	CCTransitionSplitCols();
	virtual ~CCTransitionSplitCols();

	static CCTransitionSplitCols *create(float t, CCScene *scene);

	virtual void onEnter();

	virtual CCActionInterval *action();
	virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);
};

class CC_DLL CCTransitionSplitRows : public CCTransitionSplitCols
{
public:
	CCTransitionSplitRows();
	virtual ~CCTransitionSplitRows();

	static CCTransitionSplitRows *create(float t, CCScene *scene);

	virtual CCActionInterval *action();
};

class CC_DLL CCTransitionFadeTR : public CCTransitionScene, public CCTransitionEaseScene
{
public:
	CCTransitionFadeTR();
	virtual ~CCTransitionFadeTR();

	static CCTransitionFadeTR *create(float t, CCScene *scene);

	virtual void onEnter();

protected:
	virtual void sceneOrder();

public:
	virtual CCActionInterval *actionWithSize(const CCSize &size);
	virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);
};

class CC_DLL CCTransitionFadeBL : public CCTransitionFadeTR
{
public:
	CCTransitionFadeBL();
	virtual ~CCTransitionFadeBL();

	static CCTransitionFadeBL *create(float t, CCScene *scene);

	virtual CCActionInterval *actionWithSize(const CCSize &size);
};

class CC_DLL CCTransitionFadeUp : public CCTransitionFadeTR
{
public:
	CCTransitionFadeUp();
	virtual ~CCTransitionFadeUp();

	static CCTransitionFadeUp *create(float t, CCScene *scene);

	virtual CCActionInterval *actionWithSize(const CCSize &size);
};

class CC_DLL CCTransitionFadeDown : public CCTransitionFadeTR
{
public:
	CCTransitionFadeDown();
	virtual ~CCTransitionFadeDown();

	static CCTransitionFadeDown *create(float t, CCScene *scene);

	virtual CCActionInterval *actionWithSize(const CCSize &size);
};

class CC_DLL CCTransitionPageTurn : public CCTransitionScene
{
public:
	bool _bBack;

public:
	CCTransitionPageTurn();
	virtual ~CCTransitionPageTurn();

	static CCTransitionPageTurn *create(float t, CCScene *scene, bool backwards);

	CCActionInterval *actionWithSize(const CCSize &vector);

	virtual void onEnter();

protected:
	virtual void sceneOrder();

public:
	virtual bool initWithDuration(float t, CCScene *scene, bool backwards);
};

NS_CC_END