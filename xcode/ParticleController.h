//
//  ParticleController.h
//  TestApp
//
//  Created by Rory Shively on 2/17/18.
//

#pragma once
#include "Particle.h"
#include <list>

class ParticleController
{
protected:
    std::list<Particle> mParticles;
    
public:
    ParticleController();
    ParticleController( int mYRes, int mXRes, const Channel32f &channel );
    
    void update( const Channel32f &channel, const vec2 &mouseLoc );
    void draw();
    void addParticles( int amt );
    void addParticle( int xi, int yi, const Channel32f &channel );
    void removeParticles( int amt );
};
