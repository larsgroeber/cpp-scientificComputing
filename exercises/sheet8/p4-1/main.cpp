#include <iostream>
#include <algorithm>

#include "Planet.h"
#include "ExoPlanets.h"

const std::string path_to_exoplanets = "../../p1/exoplanet.eu_catalog.dat";

std::string Planet::dataName[47];   // 47 = data[0].size() - 1

int main ()
{
    std::vector<std::vector<std::string>> data;
    std::vector<std::string> comment;

    ExoPlanets::readFile( path_to_exoplanets, data, comment );

    int c = 0;

    // fill dataName
    for ( int i = 1; i < comment.size(); ++i )
    {
        if ( comment[i].find( "error" ) == std::string::npos )
        {
            Planet::dataName[c++] = comment[i];
        }
    }

    Planet* pArray[data.size()];

    // initialize the array
    for ( int j = 0; j < data.size(); ++j )
    {
        std::string dataString = "";
        for ( std::string value : data[j] )
        {
            dataString += value + "\t";
        }
        pArray[j] = new Planet ( dataString, data[j].size() );
    }

    for ( int k = 0; k < 5; ++k )
    {
        std::cout << pArray[k]->get_value( "semi_major_axis" ) << std::endl;
    }

    // now sort the array
    std::sort( pArray, pArray + data.size(), []( Planet* &a, Planet* &b )
    {
        return b->get_value( "semi_major_axis" ) < a->get_value( "semi_major_axis" );
    });

    // 4.c)

    return 0;
}