//
//  ParticleController.cpp
//  TestApp
//
//  Created by Rory Shively on 2/20/18.
//

#include <stdio.h>
#include "ParticleController.h"

ParticleController::ParticleController( cinder::ImageSourceRef &img )
{
    auto channel = Channel32f( img );
    
    for( int y=0; y<( img->getWidth() / 10 ); y++ )
    {
        for( int x=0; x<( img->getHeight() / 10 ); x++ )
        {
            addParticle( y, x, channel );
        }
    }
}

void ParticleController::update( const Channel32f &channel, const vec2 &mouseLoc )
{
    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p )
    {
        p->update( channel, mouseLoc );
    }
}

void ParticleController::draw()
{
    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p )
    {
        p->draw();
    }
}

void ParticleController::addParticle( int xi, int yi, const Channel32f &channel ) {
    float x = ( xi + 0.5f ) * 10.0f;
    float y = ( yi + 0.5f ) * 10.0f;
    mParticles.push_back( Particle( vec2( x, y ), channel ) );
}
