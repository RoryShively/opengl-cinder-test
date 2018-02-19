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
private:
    gl::BatchRef            mParticleShapes[800000];
    gl::GlslProgRef         mShader;
    
public:
    ParticleController();
    ParticleController( int mYRes, int mXRes );
    void update( const Channel32f &channel );
    void draw();
    void addParticles( int amt );
    void addParticle( int xi, int yi );
    void removeParticles( int amt );
//    std::list<Particle> mParticles;
};

ParticleController::ParticleController()
{
    ParticleController::ParticleController( 800, 600);
}

ParticleController::ParticleController( int mYRes, int mXRes )
{
    auto lambert = gl::ShaderDef().color();
    mShader = gl::getStockShader( lambert );
    
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
////    mParticleShapes[8000] = gl::BatchRef;
//    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p )
//    {
//        p->update( channel );
//    }
}

void ParticleController::draw()
{
//    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p )
    for( int i = 0; i < (800 * 600); i++ )
    {
//        p->draw();
        mParticleShapes[i]->draw();
    }
}

void ParticleController::addParticle( int xi, int yi ) {
    float x = ( xi + 0.5f ) * 10.0f;
    float y = ( yi + 0.5f ) * 10.0f;
    auto particle = Particle( vec2( x, y ) );
    float r = particle.getRadius();
//    mParticles.push_back( particle );
    
    auto circle = geom::Circle().center( vec2( y, x ) ).radius( r );
    int i = (int) ( ( ( xi + 1 ) * ( yi + 1 ) ) - 1 );
    cout << i <<endl;
    mParticleShapes[i] = gl::Batch::create( circle, mShader );
    
}


#endif /* ParticleController_h */
