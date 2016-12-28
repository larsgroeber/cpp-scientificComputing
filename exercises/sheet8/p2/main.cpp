/**
 * Solution to problem 2 sheet 8
 * by Lars Gröber and Hendrik Edelmann
 *
 * There is a makefile available.
 */

#include <iostream>
#include <vector>

#include "ExoPlanets.h"

int main ()
{
    // vector to hold the data
    std::vector<std::vector<std::string>> data;

    // vector to hold the comment
    std::vector<std::string> comment;

    if ( ! ExoPlanets::readFile( "../../p1/exoplanet.eu_catalog.dat", data, comment ) )
    {
        fprintf( stderr, "Something went wrong reading the file..." );
    }


    if ( ! ExoPlanets::writeFile( "../planets.dat", data, comment ) )
    {
        fprintf( stderr, "Something went wrong writing the file..." );
    }

    return 0;
}