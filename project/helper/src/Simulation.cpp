
#include <tgmath.h>

#include "../include/Simulation.h"
#include "../include/Constants.h"
#include "../include/IOManager.h"

LH::Simulation::Simulation ()
{
    LH::Body* planet = new LH::Body;

    planet->pos      = PLANET_POS;
    planet->mass     = PLANET_MASS;
    planet->radius   = PLANET_RADIUS_START; // 0;
    planet->vel      = PLANET_VEL_START; // LH::Vector ( 0, 0 );

    _massPoints.push_back( planet );


    LH::Body *asteroid = new LH::Body;

    asteroid->mass = MASSPOINTS_MASS;
    asteroid->radius = MASSPOINTS_RADIUS;
    asteroid->vel = ASTEROID_VEL_START;
    asteroid->pos = ASTEROID_POS_START;

    _massPoints.push_back (asteroid);

}

void LH::Simulation::run ()
{
    LH::IOManager io ( DATA_FILE );
    io << "# time    planetX    planetY    asteroidX    asteroidY";
    char c[100];

    for ( long double t = 0; t < MAX_TIME; t += TIME_STEP )
    {
        std::string s = "";

        for ( LH::Body* o : _massPoints )
        {
            for ( LH::Body* v : _massPoints )
            {
                if ( o == v )
                {
                    continue;
                }

                LH::Vector force = gravity( o, v );
                o->vel += TIME_STEP * (force / o->mass);
                o->pos += TIME_STEP * o->vel;
            }
        }

        // TODO: add this to the loop
        snprintf( c, sizeof( c ), "\n%Lf\t%Lf\t%LF\t%Lf\t%LF"
                , t
                , _massPoints[0]->pos.x, _massPoints[0]->pos.y
                , _massPoints[1]->pos.x, _massPoints[1]->pos.y );
        io << c;
    }
}

LH::Vector LH::Simulation::gravity ( const LH::Body* A, const LH::Body* B ) const
{
    LH::Vector dist = B->pos - A->pos;
    return GRAVITY_CONSTANT * ((A->mass * B->mass) / pow( dist.size(), 2 )) * dist.unit();
}

LH::Simulation::~Simulation ()
{
    for ( auto o : _massPoints )
    {
        delete o;
    }
}

    /*
     * place first body in center ASTEROID_POS_START=( 0 , 10 )
     * BLACKBOX: random search for free space in sphere
     *
     * if body intersects with another body or asteroid radius
     * ( calculate the distance between the center of all objects AND between the new object and the whole asteroid )
     * -> reduce distance from center by radius and recheck
     *
     * if unsuccessful reduce radius by 1/2 ( the whole method has to be within a try )
     */
    // TODO: is the order of the masspoints inside the asteroid important? does it have to be random or can we simply sort them nicely?
void LH::Simulation::massPointsInit( Vector massPoints )
    {
        for ( int i = 0; i < MASSPOINTS_NUM - 1; ++ i )
        {
            LH::Body *masspoint = new LH::Body;

            masspoint->mass = MASSPOINTS_MASS;
            masspoint->radius = MASSPOINTS_RADIUS;
            masspoint->vel = ASTEROID_VEL_START;

            masspoint->pos = ASTEROID_POS_START; // TODO: some random position
            // a² + b² = c² | c² <! RADIUS
            // (1.) +-M_R < a < +-A_R - (M_R/2) | (2.) 0 < b < +-sqrt( c² -a² )
            // TODO: check for intersection -> if -> replace -> keep

            for ( int j = 1; j < MASSPOINTS_NUM +1; ++ j ) // skip first element of _masspoints because it is the planet
            {
                LH::Body *prevBody = _massPoints[j];
                LH::Vector distanceVector = masspoint->pos - prevBody->pos;
                // TODO: is size() unsigned?
                if ( distanceVector.size () >= MASSPOINTS_RADIUS ) // checks if distance between the two objects is below 2*radius
                {
                    // TODO:
                }
            }
            _massPoints.push_back (masspoint);
        }

    }