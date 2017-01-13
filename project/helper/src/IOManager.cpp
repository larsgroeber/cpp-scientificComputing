#include "../include/IOManager.h"


LH::IOManager::IOManager ( const std::string fileName )
{
    file = std::ofstream( fileName.c_str() );

    if ( file.fail() )
    {
        fprintf( stderr, "Could not open file '%s'", fileName.c_str() );
    }
}

LH::IOManager::~IOManager ()
{
    file.close();
}