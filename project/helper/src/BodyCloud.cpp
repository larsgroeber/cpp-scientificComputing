#include <tgmath.h>

#include "../include/BodyCloud.h"
#include "../include/Simulation.h"
#include "../include/Constants.h"

//LH::BodyCloud::BodyCloud ()
//{
//
//}

void LH::BodyCloud::buildSpiral ()
{
    double phi = 0;
    double r;
    double x;
    double y;

    double a = 0;

    double deltaPhi;
//    double spiralDist;
//    double CircleRad;

    for ( int i = 0; i < MASSPOINTS_NUM; ++ i )
    {
        LH::Body *bodyElementB = new LH::Body;
        LH::Vector bodyElementV ( 0, 0 );

        r = a * phi;
        x = r * cos( phi );
        y = r * sin( phi );

        bodyElementB->mass = MASSPOINTS_MASS;
        bodyElementB->radius = MASSPOINTS_RADIUS;
        bodyElementB->vel = ASTEROID_VEL_START;
        bodyElementB->pos = LH::Vector ( x, y );

        _bodyCloud.push_back ( bodyElementB );
//        _massPoints.push_back ( bodyElementB );

        phi += deltaPhi;
        a += 1;
    }


    LH::IOManager io ( "./data/BodyCloud.dat" );
    io << "# BodyElementX BodyElementY X Y X Y X Y X Y and so on";
    char c[100];
    snprintf( c, sizeof( c ), "\n%Lf\t%LF\t%Lf\t%LF"
              , _bodyCloud[i]->pos.x, _bodyCloud[i]->pos.y );
    io << c;
}

//LH::BodyCloud::~BodyCloud ()
//{
//    for ( auto o : _bodyCloud )
//    {
//        delete o;
//    }
//}