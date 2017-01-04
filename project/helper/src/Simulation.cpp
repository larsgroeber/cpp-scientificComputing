#include <tgmath.h>

#include "../include/Simulation.h"
#include "../include/Constants.h"
#include "../include/IOManager.h"
//#include "../include/BodyCloud.h"

LH::Simulation::Simulation ()
{
    LH::Body* planet = new LH::Body;

    planet->pos      = PLANET_POS;
    planet->mass     = PLANET_MASS;
    planet->radius   = PLANET_RADIUS_START;
    planet->vel      = PLANET_VEL_START;

    _massPoints.push_back( planet );

    // adding a cloud of masspoints representing the asteroid to _masspoints
    buildSpiral ();
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

        // TODO: add all masspoints X & Y to the file (additional rows)
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

void LH::Simulation::buildSpiral ()
{
//    LH::IOManager io ("./data/BodyCloud.gplt");
//    io << "# BodyElementX BodyElementY";
//    LH::IOManager distFile ("./data/distFIle.gplt");
//    distFile << "# distances between all points";

    long double phi = 3.;
    long double r;
    long double x;
    long double y;

    // TODO: find the right value for a (if you vary MASSPOINTS_RADIUS it wont work anymore
    long double a = .321660216662
                    * MASSPOINTS_RADIUS;

    long double pi = atan ( 1 ) * 4;

    for ( int i = 0; i < MASSPOINTS_NUM; ++ i )
    {
        LH::Body *bodyElementB = new LH::Body;

        r = a * phi;
        x = r * cos( phi );
        y = r * sin( phi );

        bodyElementB->mass = MASSPOINTS_MASS;
        bodyElementB->radius = MASSPOINTS_RADIUS;
        bodyElementB->vel = ASTEROID_VEL_START;
        bodyElementB->pos = LH::Vector ( x, y ) + ASTEROID_POS_START;

        // writing the elements into a vector
//        _bodyCloud.push_back ( bodyElementB );
        _massPoints.push_back ( bodyElementB );

        // TODO: find the right value for delta
//    long double delta = 6.8;
        long double delta = 1 / r;

//        phi += 1 / r; //pow( r, 2 );
        phi += delta;

//        char c[100];
//        snprintf (c, sizeof (c), "\n%Lf\t%LF"
//                  , _bodyCloud[i]->pos.x, _bodyCloud[i]->pos.y);
//        io << c;
    }

    // calculating the distance between all points to check if none are overlapping
//    for ( int j = 0; j < MASSPOINTS_NUM; ++ j )
//    {
//        for ( int k = 0; k < MASSPOINTS_NUM; ++ k )
//        {
//            if ( j == k )
//            {
//                continue;
//            }
//            LH::Vector dist;
//            dist = _bodyCloud[j]->pos - _bodyCloud[k]->pos;
//            char d[10];
//            snprintf (d, sizeof (d), "\n%Lf"
//                      , dist.size ());
//            distFile << d;
            // sort file with: sort -g data/distFIle.gplt -o data/distFIleSORT.gplt
//        }
//    }
}