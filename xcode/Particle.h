//
//  Particle.h
//  TestApp
//
//  Created by Rory Shively on 2/17/18.
//

#ifndef Particle_h
#define Particle_h

#include <math.h>
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
//#include "cinder/app/BaseApp.h"

using namespace ci;
using namespace std;

vec2 diffVec(vec2 destVec, vec2 originVec)
{
    return destVec - originVec;
}

float vecMag(vec2 diffVec)
{
    return pow( ( pow((diffVec.x ), 2 ) + pow( ( diffVec.y ), 2) ), 0.5 );
}

class Particle
{
private:
    vec2 mGravityCenter;
    vec2 mLoc;
    vec2 mDir;
    Color mColor;
    float mVel;
    float mRadius;
    vec2 mMomentum;
    
public:
    Particle( vec2 loc, const Channel32f &channel );
    void update( const Channel32f &channel, const vec2 &mouseLoc );
    void draw();
};

Particle::Particle( vec2 loc, const Channel32f &channel ) {
    mLoc = loc;
    mGravityCenter = loc;
    mDir = vec2( 0, 0 );
    mVel = 0.0f;
    mMomentum = vec2( 0, 0 );
    mRadius = channel.getValue( mLoc ) * 4.0f;
    
    float gray = channel.getValue( mLoc );
    mColor = Color( 0, gray / 1.6, gray );
}



void Particle::update( const Channel32f &channel, const vec2 &mouseLoc ) {
    
//    cout << mouseLoc << endl;
    
    auto expelVec = diffVec( mLoc,  mouseLoc );
    float expelMagtitude = vecMag( expelVec );
    vec2 expelUnitVec = expelVec / expelMagtitude;
    float eForce = 30000 / ( pow( expelMagtitude, 2 ) + 600 );
    vec2 eVec = eForce * expelUnitVec;
    
    auto gravVec = diffVec( mGravityCenter, mLoc );
    if ( isnan(gravVec.x) || isnan(gravVec.y) )
    {
        gravVec = vec2( 0, 0 );
    }
    float gravMagtitude = vecMag( gravVec );
    vec2 gravUnitVec = gravVec / gravMagtitude;
    if ( isnan(gravUnitVec.x) || isnan(gravUnitVec.y) )
    {
        gravUnitVec = vec2( 0, 0 );
    }
    float gForce = log(gravMagtitude) * 2;
    vec2 gVec = gForce * gravUnitVec;
    if ( isnan(gVec.x) || isnan(gVec.y) )
    {
        gVec = vec2( 0, 0 );
    }
    
    
    mMomentum = eVec + gVec;
    
//    float gray = channel.getValue( mLoc );
//    mRadius = channel.getValue( mLoc ) * 4.0f;
//
//
    mLoc += mMomentum;
    
//    mColor = Color( gray, gray, gray );
    
}

void Particle::draw() {
    gl::color( mColor );
    gl::drawSolidCircle( mLoc, mRadius );
}


#endif /* Particle_h */
