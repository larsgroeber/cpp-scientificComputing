/**
 * \brief Contains all constants necessary for running the simulation.
 * All variables in this file need to be const!
 */

#ifndef ROCHE_LIMIT_CONSTANTS_H
#define ROCHE_LIMIT_CONSTANTS_H

#include <string>

#include "helper/Vector.h"

// time duration
const long double MAX_TIME = 100;

// time step
const long double TIME_STEP = .001;

// gravitational constant (can be used to translate between units)
const long double GRAVITY_CONSTANT = 1;

// mass of the planet
const long double PLANET_MASS = 1000;

// position of the planet (which does not change)
const LH::Vector PLANET_POS ( 0 , 0 );

// total mass of the asteroid
const long double ASTEROID_MASS_TOTAL = 1;

// number of mass points for the asteroid
const long double MASSPOINTS_NUM = 100;

// size of asteroid (radius)
const long double ASTEROID_RADIUS_START = 10;

// starting positon of the asteroid
const LH::Vector ASTEROID_POS_START ( 0 , 10 );

// starting velocity of asteroid, TODO: consider giving only orbital parameters
const LH::Vector ASTEROID_VEL_START ( 10 , 0 );

// file to write results into
const std::string DATA_FILE = "./data/data.dat";

#endif //ROCHE_LIMIT_CONSTANTS_H
