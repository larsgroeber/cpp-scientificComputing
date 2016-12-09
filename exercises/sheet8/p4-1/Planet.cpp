#include <sstream>
#include "Planet.h"

/**
 * Here we assume that we still have '\t' as the field delimiter
 */
Planet::Planet ( const std::string& data, unsigned length )
    : _length ( length )
      , myName ( data.substr( 0, data.find( '\t' ) ) )
      , _myData ( new std::string[length] )
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
            // for p4 we did a fix here, otherwise stod throws an error
            // stod -> string-to-double
            if ( _myData[i] == "" )
            {
                return 0;
            }
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
}
