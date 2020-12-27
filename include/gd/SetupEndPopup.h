#pragma once

#include "FLAlertLayer.h"
#include "GameObject.h"

class SetupEndPopup : public FLAlertLayer
{
public:
    SetupEndPopup();
    virtual ~SetupEndPopup();

    static SetupEndPopup* create( EffectGameObject* a1, cocos2d::CCArray* a2 );

};

class SetupAnimationPopup : public FLAlertLayer
{
public:
    SetupAnimationPopup();
    virtual ~SetupAnimationPopup();

    static SetupAnimationPopup* create( EffectGameObject* a1, cocos2d::CCArray* a2 );

};