//
//  Particle.h
//  TestApp
//
//  Created by Rory Shively on 2/17/18.
//

#pragma once

#include <math.h>
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace std;


class Particle
{
protected:
    vec2        mGravityCenter;
    vec2        mLoc;
    Color       mColor;
    float       mRadius;
    vec2        mMomentum;
    
public:
    Particle( vec2 loc, const Channel32f &channel );
    void update( const Channel32f &channel, const vec2 &mouseLoc );
    void draw();
};
