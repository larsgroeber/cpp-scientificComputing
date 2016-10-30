#include "../inc/Cipher.h"

#include <sstream>


std::string Cipher::shiftMessage( const std::string& origMsg ) const
{
    std::string finalMsg;
    std::stringstream inputStream;

    // converting oirgMsg to stringstream makes extracting chars easier
    inputStream.str( origMsg );

    char c;
    char cFinal;

    // extract a single character from inputStream including whitespaces
    while ( inputStream >> std::noskipws >> c )
    {
        // if c is a valid letter, shift it, otherwise just add it to final msg
        if ( isalpha( c ) )
        {
            // to make shifting easier
            c = char( toupper( c ) );

            if ( key >= 0 )
            {
                // yes, you can subtract chars from other chars, they will be
                // implicitly converted to int
                cFinal = char( ( c - 'A' + key ) % 26 + 'A' );
            }
            else
            {
                cFinal = char( ( c - 'A' + 26 + key ) % 26 + 'A' );
            }
            // .append( size-of-char, char )
            finalMsg.append( 1, cFinal );
        }
        else
        {
            finalMsg.append( 1, c );
        }
    }

    return finalMsg;
}
