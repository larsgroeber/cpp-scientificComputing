
#include <tgmath.h>

#include "Simulation.h"
#include "Constants.h"
#include "helper/IOManager.h"

LH::Simulation::Simulation ()
{
    LH::Object* planet = new LH::Object;

    planet->pos      = PLANET_POS;
    planet->mass     = PLANET_MASS;
    planet->radius   = 0;
    planet->vel      = LH::Vector ( 0, 0 );

    LH::Object* asteroid = new LH::Object;

    asteroid->pos    = ASTEROID_POS_START;
    asteroid->mass   = ASTEROID_MASS_TOTAL;
    asteroid->radius = ASTEROID_RADIUS_START;
    asteroid->vel    = ASTEROID_VEL_START;

    _massPoints.push_back( planet );
    _massPoints.push_back( asteroid );
}

void LH::Simulation::run ()
{
    LH::IOManager io ( DATA_FILE );

    char c[100];

    for ( long double t = 0; t < MAX_TIME; t += TIME_STEP )
    {
        std::string s = "";

        for ( auto o : _massPoints )
        {
            for ( auto v : _massPoints )
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
        snprintf( c, sizeof( c ),"%Lf\t%Lf\t%LF\t%Lf\t%LF\n"
                , t
                , _massPoints[0]->pos.x, _massPoints[0]->pos.y
                , _massPoints[1]->pos.x, _massPoints[1]->pos.y );

        io << c;
    }
}

LH::Vector LH::Simulation::gravity ( const LH::Object* A, const LH::Object* B ) const
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
