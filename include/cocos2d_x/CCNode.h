#pragma once

#include "GDAPI_Macros.h"

#include "CCObject.h"
#include "CCAffineTransform.h"
#include "ccGLStateCache.h"
#include "CCCamera.h"
#include "CCArray.h"
#include "CCProtocols.h"
#include "CCScheduler.h"
#include "CCGeometry.h"
#include "CCGL.h"
#include "CCComponentContainer.h"

NS_CC_BEGIN

class CCGridBase;
class CCTouch;
class CCComponent;
class CCActionManager;
class CCGLProgram;
class CCAction;

enum
{
	kCCNodeTagInvalid = -1,
};

enum
{
	kCCNodeOnEnter,
	kCCNodeOnExit,
	kCCNodeOnEnterTransitionDidFinish,
	kCCNodeOnExitTransitionDidStart,
	kCCNodeOnCleanup
};

//
// size == 0xF8
//
class CC_DLL __attribute__( (aligned( 4 )) ) CCNode : public CCObject
{
public:
	float m_fRotationX;
	float m_fRotationY;
	float m_fScaleX;
	float m_fScaleY;
	float m_vertexZ;
	cocos2d::CCPoint m_position;
	float m_fSkewX;
	float m_fSkewY;
	cocos2d::CCPoint m_obAnchorPointInPoints;
	cocos2d::CCPoint m_obAnchorPoint;
	cocos2d::CCSize m_obContentSize;
	CCAffineTransform m_sAdditionalTransform;
	CCAffineTransform m_sTransform;
	CCAffineTransform m_sInverse;
	cocos2d::CCCamera* m_pCamera;
	cocos2d::CCGridBase* m_grid;
	int m_ZOrder;
	cocos2d::CCArray* m_pChildren;
	cocos2d::CCNode* m_parent;
	void* m_userData;
	cocos2d::CCObject* m_userObject;
	cocos2d::CCGLProgram* m_pShaderProgram;
	ccGLServerState m_eGLServerState;
	unsigned int m_orderOfArrival;
	cocos2d::CCScheduler* m_scheduler;
	cocos2d::CCActionManager* m_pActionManager;
	bool m_bRunning;
	bool m_bTransformDirty;
	char byteD6;
	char field_D7;
	int field_D8;
	int field_DC;
	char m_bInverseDirty;
	char m_bAdditionalTransformDirty;
	bool m_visible;
	char m_bIgnoreAnchorPointForPosition;
	char m_bReorderChildDirty;
	char field_E5;
	char field_E6;
	char field_E7;
	int field_E8;
	int m_nScriptHandler;
	int m_eScriptType;
	cocos2d::CCComponentContainer* m_pComponentContainer;

public:
	CCNode();
	virtual ~CCNode();

	static CCNode *create();

	CCRect boundingBox();
	CCPoint convertToNodeSpace(const CCPoint &);
	CCPoint convertToNodeSpaceAR(const CCPoint &);
	CCPoint convertToWorldSpace(const CCPoint &);
	CCPoint convertToWorldSpaceAR(const CCPoint &);
	CCPoint convertTouchToNodeSpace(CCTouch *);
	CCPoint convertTouchToNodeSpaceAR(CCTouch *);
	const char *description();
	CCAction *getActionByTag(int);
	CCComponent *getComponent(const char *) const;
	int getScriptHandler();
	unsigned int numberOfRunningActions();
	void pauseSchedulerAndActions();
	void resumeSchedulerAndActions();
	CCAction *runAction(CCAction *);
	void schedule(SEL_SCHEDULE);
	void schedule(SEL_SCHEDULE, float);
	void schedule(SEL_SCHEDULE, float, unsigned int, float);
	void scheduleOnce(SEL_SCHEDULE, float);
	void scheduleUpdate();
	void scheduleUpdateWithPriority(int);
	void scheduleUpdateWithPriorityLua(int, int);
	void setAdditionalTransform(const CCAffineTransform &);
	void stopAction(CCAction *);
	void stopActionByTag(int);
	void stopAllActions();
	void transform();
	void transformAncestors();
	void unschedule(SEL_SCHEDULE);
	void unscheduleAllSelectors();
	void unscheduleUpdate();

private:
	void childrenAlloc();
	CCPoint convertToWindowSpace(const CCPoint &);
	void detachChild(CCNode *, bool);
	void insertChild(CCNode *, int);

public:
	virtual void update(float dt);

	virtual bool init();
	virtual void setZOrder(int);
	virtual void _setZOrder(int);
	virtual int getZOrder();
	virtual void setVertexZ(float);
	virtual float getVertexZ();
	virtual void setScaleX(float);
	virtual float getScaleX();
	virtual void setScaleY(float);
	virtual float getScaleY();
	virtual void setScale(float);
	virtual float getScale();
	virtual void setScale(float, float);
	virtual void setPosition(const CCPoint &);
	virtual const CCPoint &getPosition();
	virtual void setPosition(float, float);
	virtual void getPosition(float *, float *);
	virtual void setPositionX(float);
	virtual float getPositionX();
	virtual void setPositionY(float);
	virtual float getPositionY();
	virtual void setSkewX(float);
	virtual float getSkewX();
	virtual void setSkewY(float);
	virtual float getSkewY();
	virtual void setAnchorPoint(const CCPoint &);
	virtual const CCPoint &getAnchorPoint();
	virtual const CCPoint &getAnchorPointInPoints();
	virtual void setContentSize(const CCSize &);
	virtual const CCSize &getContentSize() const;
	virtual CCSize getScaledContentSize();
	virtual void setVisible(bool);
	virtual bool isVisible();
	virtual void setRotation(float);
	virtual float getRotation();
	virtual void setRotationX(float);
	virtual float getRotationX();
	virtual void setRotationY(float);
	virtual float getRotationY();
	virtual void setOrderOfArrival(unsigned int);
	virtual unsigned int getOrderOfArrival();
	virtual void setGLServerState(ccGLServerState);
	virtual ccGLServerState getGLServerState();
	virtual void ignoreAnchorPointForPosition(bool);
	virtual bool isIgnoreAnchorPointForPosition();
	virtual void addChild(CCNode *);
	virtual void addChild(CCNode *, int);
	virtual void addChild(CCNode *, int, int);
	virtual CCNode *getChildByTag(int);
	virtual CCArray *getChildren();
	virtual unsigned int getChildrenCount() const;
	virtual void setParent(CCNode *);
	virtual CCNode *getParent();
	virtual void removeFromParent();
	virtual void removeFromParentAndCleanup(bool);
	virtual void removeMeAndCleanup();
	virtual void removeChild(CCNode *);
	virtual void removeChild(CCNode *, bool);
	virtual void removeChildByTag(int);
	virtual void removeChildByTag(int, bool);
	virtual void removeAllChildren();
	virtual void removeAllChildrenWithCleanup(bool);
	virtual void reorderChild(CCNode *, int);
	virtual void sortAllChildren();
	virtual CCGridBase *getGrid();
	virtual void setGrid(CCGridBase *);
	virtual void *getUserData();
	virtual void setUserData(void *);
	virtual CCObject *getUserObject();
	virtual void setUserObject(CCObject *);
	virtual CCGLProgram *getShaderProgram();
	virtual void setShaderProgram(CCGLProgram *);
	virtual CCCamera *getCamera();
	virtual bool isRunning();
	virtual void registerScriptHandler(int);
	virtual void unregisterScriptHandler();
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual void onExitTransitionDidStart();
	virtual void cleanup();
	virtual void draw();
	virtual void visit();
	virtual void setActionManager(CCActionManager *);
	virtual CCActionManager *getActionManager();
	virtual void setScheduler(CCScheduler *);
	virtual CCScheduler *getScheduler();
	virtual void updateTransform();
	virtual const CCAffineTransform nodeToParentTransform();
	virtual const CCAffineTransform parentToNodeTransform();
	virtual CCAffineTransform nodeToWorldTransform();
	virtual CCAffineTransform worldToNodeTransform();
	virtual bool addComponent(CCComponent *);
	virtual bool removeComponent(const char *);
	virtual bool removeComponent(CCComponent *);
	virtual void removeAllComponents();
	virtual void updateTweenAction(float, const char *);
};

class CC_DLL CCNodeRGBA : public CCNode, public CCRGBAProtocol
{
public:
	GLubyte _displayedOpacity, _realOpacity;
	ccColor3B _displayedColor, _realColor;
	bool _cascadeColorEnabled, _cascadeOpacityEnabled;

public:
	CCNodeRGBA();
	virtual ~CCNodeRGBA();

	static CCNodeRGBA *create();

	virtual bool init();

	virtual GLubyte getOpacity();
	virtual GLubyte getDisplayedOpacity();
	virtual void setOpacity(GLubyte opacity);
	virtual void updateDisplayedOpacity(GLubyte opacity);
	virtual bool isCascadeOpacityEnabled();
	virtual void setCascadeOpacityEnabled(bool bValue);
	virtual const ccColor3B &getColor();
	virtual const ccColor3B &getDisplayedColor();
	virtual void setColor(const ccColor3B &color);
	virtual void updateDisplayedColor(const ccColor3B &color);
	virtual bool isCascadeColorEnabled();
	virtual void setCascadeColorEnabled(bool bValue);
	virtual void setOpacityModifyRGB(bool bValue);
	virtual bool isOpacityModifyRGB();
};

NS_CC_END
