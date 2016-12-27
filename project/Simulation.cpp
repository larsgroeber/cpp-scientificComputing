
#include <tgmath.h>

#include "Simulation.h"
#include "Constants.h"
#include "helper/IOManager.h"

LH::Simulation::Simulation ()
{
    _planet.pos      = PLAMET_POS;
    _planet.mass     = PLANET_MASS;
    _planet.radius   = 0;
    _planet.vel      = LH::Vector ( 0 , 0 );

    _asteroid.pos    = ASTEROID_POS_START;
    _asteroid.mass   = ASTEROID_MASS_TOTAL;
    _asteroid.radius = ASTEROID_RADIUS_START;
    _asteroid.vel    = ASTEROID_VEL_START;
}

void LH::Simulation::run ()
{
    LH::IOManager io ( DATA_FILE );

    char c[100];

    //snprintf( c, sizeof( c ),"%d\t%llf\t%llf\n", 0, sun.x, sun.y );

    //io << c;

    for ( long double t = 0; t < MAX_TIME; t += TIME_STEP )
    {
        LH::Vector force = gravity( _asteroid, _planet );
        // apply acceleration
        _asteroid.vel += TIME_STEP * (force / _asteroid.mass);

        // apply velocity
        _asteroid.pos += TIME_STEP * _asteroid.vel;

        snprintf( c, sizeof( c ),"%Lf\t%Lf\t%LF\n", t, _planet.pos.x, _planet.pos.y );

        io << c;
    }
}

LH::Vector LH::Simulation::gravity ( const LH::Object& A, const LH::Object& B ) const
{
    LH::Vector dist = B.pos - A.pos;
    return GRAVITY_CONSTANT * ((A.mass * B.mass) / pow( dist.size(), 2 )) * dist.unit();
}
