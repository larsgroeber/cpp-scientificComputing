#include "../inc/Cipher.h"

#include <sstream>
#include <iostream>

std::string Cipher::shiftMessage( const std::string& origMsg ) const
{
    std::string finalMsg;
    std::stringstream inputStream;
    inputStream.str( origMsg );
    char c;
    char cFinal;

    while ( inputStream >> c )
    {
        if ( c != ' ')
        {
            // for now
            c = char( toupper( c ) );

            // ASCII:
            // A: 65
            // Z: 90

            if ( key >= 0 )
            {
                cFinal = char( ( c - 'A' + key ) % 26 + 'A' );
            }
            else
            {
                cFinal = char( ( c - 'A' + 26 + key ) % 26 + 'A' );
            }

            finalMsg.append( 1, cFinal );
        }
        else
        {
            finalMsg.append( 1, ' ' );
        }
    }

    return finalMsg;
}
