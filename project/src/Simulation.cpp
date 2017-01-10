#include <tgmath.h>
#include <iostream>
#include <algorithm>

#include "../include/Simulation.h"
#include "../include/Constants.h"
#include "../helper/include/IOManager.h"
#include "../graphics/graphic.h"

LH::Simulation::Simulation ()
#ifdef GRAPHICS
    : _graphic ( 1000, 1000, 500 ) // window width and height as well as the target framerate
#endif

{
#ifdef GRAPHICS
    // initialize camera
    _graphic.set_viewing_pos( ASTEROID_POS_START );
    _graphic.set_viewing_scale( 30.0f );
#endif

    // initialize the planet
    _planet = new LH::Body;

    _planet->pos      = PLANET_POS;
    _planet->mass     = PLANET_MASS;
    _planet->radius   = PLANET_RADIUS_START;
    _planet->vel      = PLANET_VEL_START;

    _massPoints.push_back( _planet );

    // adding a cloud of masspoints representing the asteroid to _masspoints
    buildSpiral ();

    // seed the RNG
    srand( time(NULL) );
}

void LH::Simulation::run ()
{
    // setup the view
   _view = _massPoints[1];

    // only needed for a run w/o graphics
//    LH::IOManager io ( DATA_FILE );
//
//    io << "# time\tplanetX\tplanetY";
//    for ( int i = 0; i < MASSPOINTS_NUM; ++ i )
//    {
//        io << "\tbodyX_";
//        io << i;
//        io << "\tbodyY_";
//        io << i;
//    }
//    io << "\n";

//    int charSize = ( MASSPOINTS_NUM + 1 ) * 20;
    char c[100];

    int J = 0;

    // main loop (w/o maxtime if using graphics)
    for ( long double t = 0; 1; t += TIME_STEP )
    {
        int i = 0;

        for ( LH::Body* o : _massPoints )
        {
            for ( LH::Body* v : _massPoints )
            {
                if ( o == v )
                {
                    continue;
                }
                // calculate gravity
                LH::Vector force = gravity( o, v );
                // apply acceleration
                o->vel += TIME_STEP * (force / o->mass);
                // apply velocity
                o->pos += TIME_STEP * o->vel;
            }
            snprintf( c, sizeof( c ), "\t%Lf\t%LF"
                    , _massPoints[i]->pos.x, _massPoints[i]->pos.y );
            //io << c;
            i++;
        }
        //io << "\n";

        // might help to minimize rotation of the asteroid
        //std::random_shuffle( _massPoints.begin(), _massPoints.end() );

        // collision passes
        for ( int j = 0; j < COLLISION_PASSES; ++j )
        {
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
        }

        // fix planet (only if some masspoints hit it -> would otherwise fly away
        //_planet->pos = PLANET_POS;

        // print information every 100th frame
        if ( J++ == 100 )
        {
            LH::Vector total_momentum = _massPoints[0]->mass * _massPoints[0]->vel;
            double av_distance = 0.0;
            for ( int j = 1; j < _massPoints.size(); ++j )
            {
                total_momentum += _massPoints[j]->mass * _massPoints[j]->vel;
                for ( int k = 1; k < _massPoints.size(); ++k )
                {
                    av_distance += (_massPoints[j]->pos - _massPoints[k]->pos).size();
                }
            }
            printf( "Momentum: %Lf; Average distance: %Lf\n", total_momentum.size(), av_distance / MASSPOINTS_NUM );
            J = 0;
        }

#ifdef GRAPHICS
        make_graphics();

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

    // set active sprites
    _graphic.set_sprites( sprites );
    _graphic.set_viewing_pos( _view->pos );

    // actual drawing
    _graphic.draw();
}
#endif

LH::Vector LH::Simulation::gravity ( const LH::Body* A, const LH::Body* B ) const
{
    LH::Vector dist = B->pos - A->pos;
    return GRAVITY_CONSTANT * ((A->mass * B->mass) / pow( dist.size(), 2 )) * dist.unit();
}

void LH::Simulation::collision ( LH::Body* A, LH::Body* B )
{
    LH::Vector dist = B->pos - A->pos;
    long double diff = B->radius + A->radius - dist.size();
    if ( diff < 0 )
    {
        return;
    }

    LH::Vector pos_response = dist.unit() * diff;
    // resolve collision
    A->pos -= 0.5 * pos_response;
    B->pos += 0.5 * pos_response;
    // calculate relative velocity along dist
    LH::Vector vel_response = dist.unit() * (A->vel - B->vel).dot_product( dist.unit() );
    // apply relative velocity on both objects (they have the same mass) to achieve an inelastic collision
    A->vel -= 0.5 * vel_response;
    B->vel += 0.5 * vel_response;
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