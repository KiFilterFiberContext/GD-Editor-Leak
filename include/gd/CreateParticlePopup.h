#pragma once

#include "FLAlertLayer.h"
#include "GameObject.h"

class ParticleGameObject : public GameObject 
{
public:
    ParticleGameObject();
    virtual ~ParticleGameObject();

    static ParticleGameObject* create(  );
};

class CreateParticlePopup : public FLAlertLayer
{
public:
    CreateParticlePopup();
    virtual ~CreateParticlePopup();

    static CreateParticlePopup* create( ParticleGameObject* a1, cocos2d::CCArray* a2 );

};
