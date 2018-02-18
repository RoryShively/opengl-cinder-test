//
//  Particle.h
//  TestApp
//
//  Created by Rory Shively on 2/17/18.
//

#ifndef Particle_h
#define Particle_h

#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
//#include "cinder/app/BaseApp.h"

using namespace ci;
using namespace std;

class Particle
{
private:
    vec2 mLoc;
    vec2 mDir;
    Color mColor;
    float mVel;
    float mRadius;
    
public:
    Particle( vec2 loc );
    void update( const Channel32f &channel );
    void draw();
};


Particle::Particle( vec2 loc ) {
    mLoc = loc;
    mDir = Rand::randVec2();
    mVel = Rand::randFloat( 5.0f );
//    mVel = 0;
    mRadius = 4.0f;
//    mRadius = Rand::randFloat( 1.0f, 5.0f );
//    mRadius = cos( mLoc.y * 0.1f ) + sin( mLoc.x * 0.1f ) + 2.0f;
}
void Particle::update( const Channel32f &channel ) {
    float gray = channel.getValue( mLoc );
    mRadius = channel.getValue( mLoc ) * 4.0f;
    mColor = Color( gray, gray, gray );
//    mLoc += mDir * mVel;
}
void Particle::draw() {
    gl::color( mColor );
    gl::drawSolidCircle( mLoc, mRadius );
}


#endif /* Particle_h */
