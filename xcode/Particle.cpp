//
//  Particle.cpp
//  TestApp
//
//  Created by Rory Shively on 2/20/18.
//

#include <stdio.h>
#include "Particle.h"


vec2 getDiffVec( vec2 destVec, vec2 originVec )
{
    auto dVec = destVec - originVec;
    if ( isnan(dVec.x) || isnan(dVec.y) ) return vec2( 0, 0 );
    return dVec;
}

float getVecMag( vec2 diffVec )
{
    return pow( ( pow((diffVec.x ), 2 ) + pow( ( diffVec.y ), 2) ), 0.5 );
}

vec2 getUnitVec( vec2 vec )
{
    auto uVec = vec / getVecMag(vec);
    if ( isnan(uVec.x) || isnan(uVec.y) ) return vec2( 0, 0 );
    return uVec;
}

vec2 getUnitVec( vec2 vec, float mag )
{
    auto uVec = vec / mag;
    if ( isnan( uVec.x ) || isnan( uVec.y ) ) return vec2( 0, 0 );
    return uVec;
}

vec2 scaleVec( vec2 vec, float mag )
{
    auto sVec = vec * mag;
    if ( isnan( sVec.x ) || isnan( sVec.y ) ) return vec2( 0, 0 );
    return sVec;
}


Particle::Particle( vec2 loc, const Channel32f &channel )
{
    mLoc = loc;
    mGravityCenter = loc;
    mMomentum = vec2( 0, 0 );
    mRadius = channel.getValue( loc ) * 4.0f;
    
    float gray = channel.getValue( loc );
    mColor = Color( 0, gray / 1.6, gray );
}

void Particle::update( const Channel32f &channel, const vec2 &mouseLoc )
{
    auto expelVec = getDiffVec( mLoc,  mouseLoc );
    float expelMagtitude = getVecMag( expelVec );
    vec2 expelUnitVec = getUnitVec( expelVec, expelMagtitude );
    float eForce = 30000 / ( pow( expelMagtitude, 2 ) + 600 );
    vec2 eVec = scaleVec( expelUnitVec, eForce );
    
    auto gravVec = getDiffVec( mGravityCenter, mLoc );
    float gravMagtitude = getVecMag( gravVec );
    vec2 gravUnitVec = getUnitVec( gravVec, gravMagtitude );
    float gForce = log( gravMagtitude ) * 2;
    vec2 gVec = scaleVec( gravUnitVec, gForce );

    mMomentum = eVec + gVec;
    mLoc += mMomentum;
}

void Particle::draw()
{
    gl::color( mColor );
    if ( mRadius > 1.0f )
    {
        gl::drawSolidCircle( mLoc, mRadius );
    }
}

