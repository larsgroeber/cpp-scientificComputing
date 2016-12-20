#include <iostream>
#include <tgmath.h>

#include "IOManager.h"
#include "Vector.h"

using namespace LH;

const LH::Vector sun ( 0., 0. );    // pos of the sun
const long double mSun = 2800;      // mass of the sun

const LH::Vector startv ( 10, 0 );  // starting velocity of the planet
const long double mPlanet = 1;      // mass of the planet

const double dt = 0.001;            // time step
const int maxTime = 100;            // maximal time

const std::string dataFile = "./test.dat";


// simple implementation of gravity
Vector gravity ( Vector object, Vector sun, long double M )
{
    Vector dist = sun - object;
    return (M / pow( dist.size(), 2 )) * dist.unit();
}

int main ()
{
    LH::IOManager io ( dataFile );

    Vector planet ( 0, 20 );        // starting pos of the planet
    Vector v = startv;

    char c[100];

    //snprintf( c, sizeof( c ),"%d\t%llf\t%llf\n", 0, sun.x, sun.y );

    //io << c;

    for ( double t = 0; t < maxTime; t += dt )
    {
        // calculate gravity
        Vector force = gravity( planet, sun, mSun );

        // apply acceleration
        v += dt * (force / mPlanet);

        // apply velocity
        planet += dt * v;

        snprintf( c, sizeof( c ),"%lf\t%llf\t%llf\n", t, planet.x, planet.y );

        io << c;
    }

    return 0;
}

