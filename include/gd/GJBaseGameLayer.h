#pragma once

#include "CCLayer.h"
#include "GameObject.h"

class GJBaseGameLayer : public cocos2d::CCLayer
{
public:

public:
    GJBaseGameLayer();
    virtual ~GJBaseGameLayer();

    void releaseButton( int a1, bool b2 );
    void pushButton( int a1, bool b2 );

    void updateTimeWarp( float dt );

    void setupLayers( );
    void createTextLayers( );
    void enableHighCapacityMode( );
    void resetGroupCounters( bool reset );

    GameObject* parentForZLayer( int a1, bool a2, int a3 );

    virtual void __unknown19( );
    virtual void __unknown20( );
    virtual void __unknown21( );
    virtual void __unknown22( );
    virtual void __unknown23( );
    virtual void __unknown24( );
    virtual void __unknown25( );
    virtual void __unknown26( );
    virtual void __unknown27( );
    virtual void __unknown28( );
    virtual void __unknown29( );

    virtual void addToSection( GameObject* g ); // 0x250
}; 