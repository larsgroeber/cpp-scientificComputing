/**
 * \brief Contains all constants necessary for running the simulation.
 * All variables in this file need to be const!
 */

#ifndef ROCHE_LIMIT_CONSTANTS_H
#define ROCHE_LIMIT_CONSTANTS_H

// uncomment this to enable graphics and use 'make graphic' (you might have to change the cmake file, too)
//#define GRAPHICS

// just uncomment one to enable!
//#define DEFAULT
#define MOON_EARTH

#include <string>

#include "../helper/include/Vector.h"


// file to write results into
const std::string POS_FILE = "./data/position.dat";
const std::string DAT_FILE = "./data/data.dat";

// how many frames should we wait between printing information?
const unsigned int OUTPUT_FRAMES = 200;


#ifdef DEFAULT
// time duration
const long double MAX_TIME = 20;

// time step
const long double TIME_STEP = .001;

// gravitational constant (can be used to translate between units)
const long double GRAVITY_CONSTANT = 1;

// number of collision passes (of complexity O(n^2))
const unsigned int COLLISION_PASSES = 1;



// mass of the planet
const long double PLANET_MASS = 100000;

// size of planet (radius)
const long double PLANET_RADIUS_START = 10;

// position of the planet (which does not change)
const LH::Vector PLANET_POS ( 0 , 0 );

// starting velocity of planet
const LH::Vector PLANET_VEL_START ( 0 , 0 );
const LH::Vector PLANET_VEL_START ( 0 , 0 );



// size of asteroid (radius)
//const long double ASTEROID_RADIUS_START = 10;

// total mass of the asteroid
const long double ASTEROID_MASS_TOTAL = 10;

// starting positon of the asteroid
const LH::Vector ASTEROID_POS_START ( 0 , 300 );

// starting velocity of asteroid, TODO: consider giving only orbital parameters
const LH::Vector ASTEROID_VEL_START ( 1.5 , 0 );



// number of mass points for the asteroid
const long double MASSPOINTS_NUM = 100;

// size of masspoints (radius)
const long double MASSPOINTS_RADIUS = .5; //0.302593388348611302909204224934; //for 8 http://hydra.nat.uni-magdeburg.de/packing/cci/

// mass of each asteroid rock (all rocks have the same weight)
const long double MASSPOINTS_MASS = ASTEROID_MASS_TOTAL / MASSPOINTS_NUM;
#endif

#ifdef MOON_EARTH
// time duration
const long double MAX_TIME = 120;

// time step
const long double TIME_STEP = .001;

// gravitational constant (can be used to translate between units)
// actually: 6.67 * 10^-11 m^3 / (kg * s^2)
const long double GRAVITY_CONSTANT = 6.67; // (10^5m)^3/(10^22kg * 10^4s) = 10^-11 m^3 / (kg * s^2)

// number of collision passes (of complexity O(n^2))
const unsigned int COLLISION_PASSES = 1;

/*
 * MOON:
 * Mass: 7.342*10^22 kg
 * Radius: 1738km
 *
 * EARTH:
 * Mass: 6 * 10^24 kg
 * Radius: 6356km
 *
 * Distance Moon-Earth: 384400km
 * Speed: 1.022km/s
 *
 * UNITS:
 * Length: 100km
 * Mass: 10^22kg
 * Time: 100s
 */

// mass of the planet
const long double PLANET_MASS = 600;

// size of planet (radius)
const long double PLANET_RADIUS_START = 63.56;

// position of the planet (which does not change)
const LH::Vector PLANET_POS ( 0 , 0 );

// starting velocity of planet
const LH::Vector PLANET_VEL_START ( 0 , 0 );



// size of asteroid (radius)
const long double ASTEROID_RADIUS_START = 17.28;

// total mass of the asteroid
const long double ASTEROID_MASS_TOTAL = 7.342;

// starting positon of the asteroid
const LH::Vector ASTEROID_POS_START ( -200, 0 );

// starting velocity of asteroid, TODO: consider giving only orbital parameters
const LH::Vector ASTEROID_VEL_START ( 0, 3.022 );



// number of mass points for the asteroid
const long double MASSPOINTS_NUM = 100;

// size of masspoints (radius) -> for 100 points there are about 11 along the radius
const long double MASSPOINTS_RADIUS = ASTEROID_RADIUS_START / 10; //.5

// mass of each asteroid rock (all rocks have the same weight)
const long double MASSPOINTS_MASS = ASTEROID_MASS_TOTAL / MASSPOINTS_NUM;
#endif





#endif //ROCHE_LIMIT_CONSTANTS_H