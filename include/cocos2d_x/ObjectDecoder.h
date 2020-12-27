#pragma once

#include "GDAPI_Macros.h"

#include "CCNode.h"
#include "DS_Dictionary.h"

typedef cocos2d::CCObject *(__stdcall **ObjectDecoderFunction)(int, DS_Dictionary *);

class CC_DLL ObjectDecoderDelegate
{
public:
	virtual cocos2d::CCObject *getDecodedObject(int, DS_Dictionary *) = 0;
};

class CC_DLL ObjectDecoder : public cocos2d::CCNode
{
public:
	ObjectDecoderFunction _func;

public:
	ObjectDecoder();
	virtual ~ObjectDecoder();

	static class ObjectDecoder *sharedDecoder();

	cocos2d::CCObject *getDecodedObject(int, DS_Dictionary *);
	ObjectDecoderDelegate *getDelegate() const;
	void setDelegate(ObjectDecoderDelegate *);

	virtual bool init();
};
