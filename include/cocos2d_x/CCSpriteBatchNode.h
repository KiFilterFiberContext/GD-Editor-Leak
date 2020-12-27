#pragma once

#include "GDAPI_Macros.h"

#include "CCNode.h"
#include "CCTextureAtlas.h"

NS_CC_BEGIN

#define kDefaultSpriteBatchCapacity 29

class CCSprite;

class CC_DLL CCSpriteBatchNode : public CCNode, public CCTextureProtocol
{
public:
	CCTextureAtlas *_pobTextureAtlas;
	ccBlendFunc _blendFunc;
	CCArray *_pobDescendants;
	bool _manualSortChildren, _manualSortAllChildren;

public:
	CCSpriteBatchNode();
	virtual ~CCSpriteBatchNode();

	static CCSpriteBatchNode *create(const char *);
	static CCSpriteBatchNode *create(const char *, unsigned int);
	static CCSpriteBatchNode *createWithTexture(CCTexture2D *);
	static CCSpriteBatchNode *createWithTexture(CCTexture2D *, unsigned int);

	void appendChild(CCSprite *);
	unsigned int atlasIndexForChild(CCSprite *, int);
	int getAtlasCapacity();
	CCArray *getDescendants();
	bool getManualSortChildren() const;
	CCTextureAtlas *getTextureAtlas();
	int getUsedAtlasCapacity();
	unsigned int highestAtlasIndexInChild(CCSprite *);
	void increaseAtlasCapacity(unsigned int);
	void increaseAtlasCapacity();
	bool initWithFile(const char *, unsigned int);
	bool initWithTexture(CCTexture2D *, unsigned int);
	void insertChild(CCSprite *, unsigned int);
	unsigned int lowestAtlasIndexInChild(CCSprite *);
	void manualSortAllChildren();
	unsigned int rebuildIndexInOrder(CCSprite *, unsigned int);
	void removeChildAtIndex(unsigned int, bool);
	void removeSpriteFromAtlas(CCSprite *);
	void reorderBatch(bool);
	void setManualSortChildren(bool);
	void setTextureAtlas(CCTextureAtlas *);

protected:
	CCSpriteBatchNode *addSpriteWithoutQuad(CCSprite *, unsigned int, int);
	void insertQuadFromSprite(CCSprite *, unsigned int);
	void updateQuadFromSprite(CCSprite *, unsigned int);

private:
	void swap(int, int);
	void updateAtlasIndex(CCSprite *, int *);
	void updateBlendFunc();

public:
	virtual bool init();
	virtual void addChild(CCNode *);
	virtual void addChild(CCNode *, int);
	virtual void addChild(CCNode *, int, int);
	virtual void removeChild(CCNode *, bool);
	virtual void removeAllChildrenWithCleanup(bool);
	virtual void reorderChild(CCNode *, int);
	virtual void sortAllChildren();
	virtual void draw();
	virtual void visit();
	virtual CCTexture2D *getTexture();
	virtual void setTexture(CCTexture2D *);
	virtual void setBlendFunc(_ccBlendFunc);
	virtual _ccBlendFunc getBlendFunc();
};

NS_CC_END