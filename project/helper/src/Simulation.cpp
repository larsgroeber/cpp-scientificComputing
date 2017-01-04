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
    planet->radius   = PLANET_RADIUS_START; // 0;
    planet->vel      = PLANET_VEL_START; // LH::Vector ( 0, 0 );

    _massPoints.push_back( planet );

//    LH::Body *asteroid = new LH::Body;
//
//    asteroid->mass = ASTEROID_MASS_TOTAL; //MASSPOINTS_MASS;
//    asteroid->radius = MASSPOINTS_RADIUS;
//    asteroid->vel = ASTEROID_VEL_START;
//    asteroid->pos = ASTEROID_POS_START;
//
//    _massPoints.push_back (asteroid);

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

    long double a = .321660216662
                    * MASSPOINTS_RADIUS;

    long double pi = atan ( 1 ) * 4;

    for ( int i = 0; i < MASSPOINTS_NUM; ++ i )
    {
        LH::Body *bodyElementB = new LH::Body;
//        LH::Vector bodyElementV ( 0, 0 );

        r = a * phi;
        x = r * cos( phi );
        y = r * sin( phi );

        bodyElementB->mass = MASSPOINTS_MASS;
        bodyElementB->radius = MASSPOINTS_RADIUS;
        bodyElementB->vel = ASTEROID_VEL_START;
        bodyElementB->pos = LH::Vector ( x, y );

        // writing the elements into a vector
//        _bodyCloud.push_back ( bodyElementB );
        _massPoints.push_back ( bodyElementB );

//    long double delta = 6.8;
        long double delta = 1 / r;

//        phi += 1 / r; //pow( r, 2 );
        phi += delta;

//        char c[100];
//        snprintf (c, sizeof (c), "\n%Lf\t%LF"
//                  , _bodyCloud[i]->pos.x, _bodyCloud[i]->pos.y);
//        io << c;
    }

    // calculating the distance between all points
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

//void LH::Simulation::buildAsteroid ()
//{
//    std::vector<String> trajectory;
//    LH::IOManager io ( "data/asteroid/test.dat" );
//    io << "# time    coreX    coreY    particleX    particleY";
//    char c[100];
//
//    for ( long double i = 0; i < 100; i += 1 )
//    {
//        std::string s = "";
//
//        for ( LH::Body* o : _asteroidCloud )
//        {
////            for ( LH::Body* v : _asteroidCloud )
////            {
////                if ( o == v )
////                {
////                    continue;
////                }
//
//            LH::Vector force = gravity( o, _masspoints[1] );
//            o->vel += TIME_STEP * (force / o->mass);
//            o->pos += TIME_STEP * o->vel;
//
//            if ()
////            }
//        }
//
////        snprintf( c, sizeof( c ), "\n%Lf\t%Lf\t%LF\t%Lf\t%LF", i, _masspoints[1]->pos.x, _masspoints[1]->pos.y, _asteroidCloud[0]->pos.x, _asteroidCloud[0]->pos.y );
//        io << c;
//    }
//}

//void bodyCloudInit ( Vector massPoints, int n, double diam )
//    {
////        for ( int i = 0; i < MASSPOINTS_NUM - 1; ++ i )
////        {
//            LH::Body *masspoint = new LH::Body;
//
//            // first particle in the middle of the asteroid
//            masspoint->mass = MASSPOINTS_MASS * 1000000; // has to be set back to 1 * MASSPOINTS_MASS
//            masspoint->radius = MASSPOINTS_RADIUS;
//            masspoint->vel = ASTEROID_VEL_START;
//            masspoint->pos = ASTEROID_POS_START;
//
//            _massPoints.push_back (masspoint);
//            _asteroidCloud.push_back (masspoint);
//
//            if ( MASSPOINTS_NUM > 1 )
//            {
////                double circleExtent = MASSPOINTS_NUM * MASSPOINTS_RADIUS * 2 + MASSPOINTS_RADIUS * 3;
//                double circleExtent = MASSPOINTS_RADIUS * 2,5;
//                LH::Body *masspoint = new LH::Body;
//
//                masspoint->mass = MASSPOINTS_MASS;
//                masspoint->radius = MASSPOINTS_RADIUS;
//                masspoint->vel = ASTEROID_VEL_START;
//                masspoint->pos = ASTEROID_POS_START + LH::Vector ( 0, circleExtent );
//
//                _asteroidCloud.push_back (masspoint);
//
//                int pairs =  ( MASSPOINTS_NUM - 2 ) / 6;
//                if ( ( ( MASSPOINTS_NUM - 2 ) % 6 ) != 0 )
//                {
//                    pairs++;
//                }
//
//                for ( int j = 2; j < pairs; ++ j )
//                {
//
//
//                }
//            }

//            LH::Simulation::buildAsteroid();

//            for ( int j = 1; j < MASSPOINTS_NUM +1; ++ j ) // skip first element of _masspoints because it is the planet
//            {
//                LH::Body *prevBody = _massPoints[j];
//
//                masspoint->mass = MASSPOINTS_MASS;
//                masspoint->radius = MASSPOINTS_RADIUS;
//                masspoint->vel = ASTEROID_VEL_START;
//                masspoint->pos = ASTEROID_POS_START + LH::Vector ( MASSPOINTS_RADIUS*MASSPOINTS_NUM, MASSPOINTS_RADIUS*MASSPOINTS_NUM ); // for honeycomb.... delete
//
//                LH::Vector distanceVector = masspoint->pos - prevBody->pos;
////                // TODO: is size() unsigned?
////                if ( distanceVector.size () >= MASSPOINTS_RADIUS ) // checks if distance between the two objects is below 2*radius
////                {}
//
//                _massPoints.push_back (prevBody);
//            }
//        }
//
//    }

//void LH::Simulation::HoneycombBodyCloud ( Vector massPoints, int n, double diam )
//{
//    LH::Body *masspoint = new LH::Body;
//    masspoint->mass = MASSPOINTS_MASS;
//    masspoint->radius = MASSPOINTS_RADIUS;
//    masspoint->vel = ASTEROID_VEL_START;
//    masspoint->pos = ASTEROID_POS_START; //place first particle in the middle
//    _massPoints.push_back (masspoint);
//    for ( int i = 2; i < n+1; ++ i ) // first element is the heavy object, second element is the first particle
//    {
//        LH::Body *masspoint = new LH::Body;
//        masspoint->mass = MASSPOINTS_MASS;
//        masspoint->radius = MASSPOINTS_RADIUS;
//        masspoint->vel = ASTEROID_VEL_START;
//            masspoint->pos =
//        _massPoints.push_back (masspoint);
//    }
//}