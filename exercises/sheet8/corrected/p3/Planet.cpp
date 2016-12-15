#include <sstream>
#include "Planet.h"

// BS: interestinlgy this only works with
// BS: g++ -std=c++11 Planet.cpp Planet.h main.cpp
// BS: but nor with -std=gnu++11 

/**
 * Here we assume that we still have '\t' as the field delimiter
 */
// BS: ok!
Planet::Planet ( const std::string& data, unsigned length )
    : _length ( length )
      , myName ( data.substr( 0, data.find( '\t' ) ) )
      , _myData ( new std::string[length] )
// BS: good!
{
    std::stringstream dataSS ( data );

    std::string value;

    // throw away the name
    std::getline( dataSS, value, '\t' );

    // initialize _myData
    for ( int i = 0; std::getline( dataSS, value, '\t' ); ++i )
    {
        _myData[i] = value;
    }
}

double Planet::get_value ( const std::string& name ) const
{
    for ( int i = 0; i < _length; ++i )
    {
        if ( dataName[i] == name )
        {
            // stod -> string-to-double
            return stod( _myData[i] );
        }
    }
    return 0; // indicating an error
}

void Planet::print_data () const
{
    printf( "%s\t", myName.c_str() );
    for ( int i = 0; i < _length; ++i )
    {
        printf( "%lf\t", stod( _myData[i] ) );
    }
    printf( "\n" );
}

Planet::~Planet ()
{
    delete[]( _myData );
    // BS: good!
}
