#include <iostream>
#include <vector>

#include "ExoPlanets.h"

int main ()
{
    std::vector<std::vector<std::string>> data;
    std::vector<std::string> comment;

    if ( ! ExoPlanets::readFile( "../../p1/exoplanet.eu_catalog.dat", data, comment ) )
    {
        fprintf( stderr, "Something went wrong..." );
    }

    ExoPlanets::writeFile( "../planets.dat", data, comment );

    return 0;
}