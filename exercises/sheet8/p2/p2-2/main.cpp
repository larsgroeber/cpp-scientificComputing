#include <iostream>
#include <vector>

#include "IO.h"

int main ()
{
    std::vector<std::vector<std::string>> data;
    std::vector<std::string> comment;

    if ( ! IO::readFile( "../../../p1/exoplanet.eu_catalog.dat", data, comment ) )
    {
        fprintf( stderr, "Something went wrong..." );
    }

    std::cout << data[0][4] << std::endl;

    IO::writeFile( "../planets.dat", data, comment );

    return 0;
}