#pragma once

#include "particle_nodes/CCParticleSystemQuad.h"

class GameToolbox 
{
public:
    static bool doWeHaveInternet();

    static std::string saveParticleToString( cocos2d::CCParticleSystemQuad* particleQuad );
    static cocos2d::CCParticleSystemQuad* particleFromString( std::string particleString );

    static void createHashString( std::string a1, int a2 );

    static float fast_rand();
    static float fast_srand();
    static float fast_rand_0_1();

    static void postClipVisit();

    static void alignItemsVertically( cocos2d::CCArray* items, float sep, cocos2d::CCPoint pos );
    static void alignItemsHorisontally( cocos2d::CCArray* items, float sep, cocos2d::CCPoint pos, bool a4 );
};