#pragma once

#include "CCLayer.h"
#include "particle_nodes/CCParticleSystemQuad.h"

class ParticlePreviewLayer : public cocos2d::CCLayerColor 
{
public:
    int mode_; // 0x1A4
    int mainSliderValue_; // 0x1A8
    cocos2d::CCParticleSystemQuad* particleSystem_; // 0x1AC
    bool gravityMode_; // 0x1B0

public:
    ParticlePreviewLayer();
    virtual ~ParticlePreviewLayer();

    static ParticlePreviewLayer* create( cocos2d::CCParticleSystemQuad* p );
    bool init( cocos2d::CCParticleSystemQuad* p );

    void preVisitWithClippingRect( cocos2d::CCRect box );
    void postVisit( void );

    virtual void draw( void );
    virtual void visit( void );
};