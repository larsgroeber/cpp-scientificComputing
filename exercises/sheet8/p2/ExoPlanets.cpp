#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include "ExoPlanets.h"

bool ExoPlanets::readFile ( const std::string& filePath, std::vector<std::vector<std::string>>& data, std::vector<std::string>& comment )
{
    int line_number ( 0 );

    std::fstream file ( filePath );

    // check if we where successful opening the file
    if ( file.fail() )
    {
        fprintf( stderr, "Could not open file %s!\n", filePath.c_str() );
        return 0;
    }

    char commentSymbol = '#';
    char fieldDelimiter = '\t';

    std::string line = "";

    std::stringstream lineSS;

    // read a line of the file into 'line'
    while ( getline( file, line ) )
    {
        int column_number ( 0 );
        lineSS = std::stringstream ( line );
        std::string word = "";

        // get the first line with comments
        if ( line[0] == commentSymbol )
        {
            // write each entry into 'comment'
            while ( getline( lineSS, word, fieldDelimiter ) )
            {
                if ( word[0] == commentSymbol )
                {
                    // for the first one, we have to strip '# '
                    comment.push_back( word.substr( 2, word.size() - 2 ) );
                    continue;
                }
                comment.push_back( word );
            }
            continue;
        }

        std::vector<std::string> lineVector;
        data.push_back( lineVector );

        // write each entry into 'data[line_number]'
        while ( getline( lineSS, word, fieldDelimiter ) )
        {
            // pray to god that we have already read the comment
            // ...ok, just in case, let's implement a check
            if ( comment.size() == 0 )
            {
                fprintf( stderr, "Hey, there is no comment on the first line!\n" );
                return 0;
            }

            // if there is the string 'error' in the corresponding comment, don't write the value into data
            if ( comment[column_number].find( "error" ) == std::string::npos )
            {
                data[line_number].push_back( word );
            }
            column_number++;
        }

        line_number++;
    }

    // clean the comment
    // why does this not work??? -> there are still fields with 'error' in them remaining
    for ( std::vector<std::string>::iterator it = comment.begin(); it != comment.end(); ++it )
    {
        if ( (*it).find( "error" ) != std::string::npos )
        {
            comment.erase( it );
        }
    }

    return 1;
}

bool ExoPlanets::writeFile ( const std::string& filePath, std::vector<std::vector<std::string>>& data, std::vector<std::string>& comment )
{
    std::fstream file ( filePath, std::ios::out );

    if ( file.fail() )
    {
        fprintf( stderr, "Could not open file %s!\n", filePath.c_str() );
        return 0;
    }

    char commentSymbol = '#';
    char fieldDelimiter = '\t';

    file << commentSymbol << " ";
    for ( int i = 0; i < comment.size(); ++i )
    {
        // as we were not successful cleaning the comment vector, implement another check
        if ( comment[i].find( "error" ) != std::string::npos )
        {
            continue;
        }
        file << comment[i] << fieldDelimiter;
    }
    file << "\n";

    for ( int j = 0; j < data.size(); ++j )
    {
        for ( int i = 0; i < data[j].size(); ++i )
        {
            file << data[j][i] << fieldDelimiter;
        }
        file << "\n";
    }

    return 1;
}
