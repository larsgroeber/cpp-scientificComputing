/**
 * \brief Contains all constants necessary for running the simulation.
 * All variables in this file need to be const!
 */

#ifndef ROCHE_LIMIT_CONSTANTS_H
#define ROCHE_LIMIT_CONSTANTS_H

#include <string>

#include "../../helper/include/Vector.h"

// time duration
const long double MAX_TIME = 20;

// time step
const long double TIME_STEP = .01;

// gravitational constant (can be used to translate between units)
const long double GRAVITY_CONSTANT = 1;



// mass of the planet
const long double PLANET_MASS = 10000;

// size of planet (radius)
const long double PLANET_RADIUS_START = 100;

// position of the planet (which does not change)
const LH::Vector PLANET_POS ( 0 , 0 );

// starting velocity of planet
const LH::Vector PLANET_VEL_START ( 0 , 0 );



// size of asteroid (radius)
//const long double ASTEROID_RADIUS_START = 10;

// total mass of the asteroid
const long double ASTEROID_MASS_TOTAL = 1;

// starting positon of the asteroid
const LH::Vector ASTEROID_POS_START ( 0 , 100 );

// starting velocity of asteroid, TODO: consider giving only orbital parameters
const LH::Vector ASTEROID_VEL_START ( 2 , 0 );



// number of mass points for the asteroid
const long double MASSPOINTS_NUM = 10;

// size of masspoints (radius)
const long double MASSPOINTS_RADIUS = .5; //0.302593388348611302909204224934; //for 8 http://hydra.nat.uni-magdeburg.de/packing/cci/

// mass of each asteroid rock (all rocks have the same weight)
const long double MASSPOINTS_MASS = ASTEROID_MASS_TOTAL / MASSPOINTS_NUM;



// file to write results into
const std::string DATA_FILE = "./data/data.dat";

#endif //ROCHE_LIMIT_CONSTANTS_H