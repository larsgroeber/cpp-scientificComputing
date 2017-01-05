#include <tgmath.h>
#include <iostream>

#include "../include/Simulation.h"
#include "../include/Constants.h"
#include "../helper/include/IOManager.h"
#include "../include/graphic.h"
//#include "../include/BodyCloud.h"



LH::Simulation::Simulation ()
#ifdef GRAPHICS
    : _graphic ( 500, 500, 50 )
#endif

{
#ifdef GRAPHICS
    _graphic.set_viewing_pos( ASTEROID_POS_START );
    _graphic.set_viewing_scale( 30.0f );
#endif

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

    io << "# time\tplanetX\tplanetY";
    for ( int i = 0; i < MASSPOINTS_NUM; ++ i )
    {
        io << "\tbodyX_";
        io << i;
        io << "\tbodyY_";
        io << i;
    }
    io << "\n";

//    int charSize = ( MASSPOINTS_NUM + 1 ) * 20;
    char c[100];



    for ( long double t = 0; 1; t += TIME_STEP )
    {
//        std::string s = "";
//        snprintf( c, sizeof( c ), "\t%Lf", t);
//        io << c;
        int i = 0;

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
            snprintf( c, sizeof( c ), "\t%Lf\t%LF"
                    , _massPoints[i]->pos.x, _massPoints[i]->pos.y );
            //io << c;
            i++;
        }
        //io << "\n";

        for ( LH::Body* o : _massPoints )
        {
            for ( LH::Body* v : _massPoints )
            {
                if ( o == v )
                {
                    continue;
                }
                collision( o, v );
            }
        }

#ifdef GRAPHICS
        make_graphics();

        //std::cin >> c;

        // quit if user closed window
        if ( _graphic.get_state() == State::QUIT )
        {
            break;
        }
#endif
    }
}

#ifdef GRAPHICS
void LH::Simulation::make_graphics ()
{
    // vector to give pos, radius and path to texture/image file
    std::vector<std::tuple<LH::Vector,float,std::string>> sprites;

    for ( auto&& m : _massPoints )
    {
        sprites.emplace_back( m->pos, m->radius, "./graphics/black-circle.png" );
    }

    _graphic.set_sprites( sprites );

    _graphic.set_viewing_pos( _massPoints[1]->pos );

    _graphic.draw();
}
#endif

LH::Vector LH::Simulation::gravity ( const LH::Body* A, const LH::Body* B ) const
{
    LH::Vector dist = B->pos - A->pos;
    return GRAVITY_CONSTANT * ((A->mass * B->mass) / pow( dist.size(), 2 )) * dist.unit();
}

void LH::Simulation::collision ( LH::Body* A, const LH::Body* B )
{
    LH::Vector dist = B->pos - A->pos;
    if ( dist.size() > B->radius + A->radius || A->vel.dot_product( dist ) < 0 )
    {
        return;
    }

    A->pos += -1 * dist.unit() * (B->radius + A->radius - dist.size());
    A->vel = A->vel - dist.unit() * (A->vel - B->vel).dot_product( dist.unit() );
}

LH::Simulation::~Simulation ()
{
    for ( auto o : _massPoints )
    {
        delete o;
    }
}

// TODO: move to bodyCloud.cpp
void LH::Simulation::buildSpiral ()
{
    // for testing: used for creating text output of coordinates of the elements
//    LH::IOManager io ("./data/BodyCloud.gplt");
//    io << "# BodyElementX BodyElementY";
//    LH::IOManager distFile ("./data/distFIle.gplt");
//    distFile << "# distances between all points";

    // polar coordinates
    long double phi = 3.;
    long double r;
    // cartesian coordinates
    long double x;
    long double y;

    // TODO: find the right value for a (if you vary MASSPOINTS_RADIUS it wont work anymore
    // factor for calculating the archimedic spiral
    long double a = .321660216662 * MASSPOINTS_RADIUS;

    long double pi = atan ( 1 ) * 4;

    // looping over all bodyCloud elements and adding them to a vector
    for ( int i = 0; i < MASSPOINTS_NUM; ++ i )
    {
        LH::Body *bodyElementB = new LH::Body;

        // formula for archimedic spiral (polar + cartesian)
        r = a * phi;
        x = r * cos( phi );
        y = r * sin( phi );

        //creating a bodyCloud element
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

        // increment phi for the archimedic spiral
//        phi += 1 / r; //pow( r, 2 );
        phi += delta;

        // for testing: writes the coordinates of all _bodyCloud elements in a file (one element per row)
//        char c[100];
//        snprintf (c, sizeof (c), "\n%Lf\t%LF"
//                  , _bodyCloud[i]->pos.x, _bodyCloud[i]->pos.y);
//        io << c;
    }

    // for testing: calculating the distance between all points to check if none are overlapping
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