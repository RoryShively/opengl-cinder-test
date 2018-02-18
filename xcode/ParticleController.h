//
//  ParticleController.h
//  TestApp
//
//  Created by Rory Shively on 2/17/18.
//

#ifndef ParticleController_h
#define ParticleController_h

#include "Particle.h"
#include <list>

class ParticleController
{
//private:
//    int mYRes;
//    int mXRes;
//
public:
    ParticleController();
    ParticleController( int mYRes, int mXRes );
    void update( const Channel32f &channel );
    void draw();
    void addParticles( int amt );
    void addParticle( int xi, int yi );
    void removeParticles( int amt );
    std::list<Particle> mParticles;
};

ParticleController::ParticleController()
{
    ParticleController::ParticleController( 800, 600);
}

ParticleController::ParticleController( int mYRes, int mXRes )
{
    for( int y=0; y<mYRes; y++ )
    {
        for( int x=0; x<mXRes; x++ )
        {
            addParticle( x, y );
        }
    }
}

void ParticleController::update( const Channel32f &channel )
{
    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p )
    {
        p->update( channel );
    }
}

void ParticleController::draw()
{
    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p )
    {
        p->draw();
    }
}

void ParticleController::addParticles( int amt )
{
    auto initPos = vec2( 400, 300 );
    for( int i = 0; i < amt; i ++ )
    {
        auto p = Particle( initPos );
        mParticles.push_back( p );
    }
}

void ParticleController::addParticle( int xi, int yi ) {
    float x = ( xi + 0.5f ) * 10.0f;
    float y = ( yi + 0.5f ) * 10.0f;
    mParticles.push_back( Particle( vec2( x, y ) ) );
}


#endif /* ParticleController_h */
