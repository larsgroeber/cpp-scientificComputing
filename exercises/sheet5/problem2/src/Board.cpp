#include <sstream>
#include <iostream>

#include "../inc/Board.h"
#include "../inc/Error.h"

using namespace std;

//// PUBLIC METHODS ////

/**
 * constructs the object, initialise all variables which are important
 * for the look of the board and set the board to its initial state
 */
Board::Board ( unsigned int x, unsigned int y, WINDOW* win )
    : dim     ( x, y )
    , window  ( win )
    , board ( dim.second ) // y_dim is the # of cols, so the vectors in *board* represent the rows
    , vSpace    ( 1 )
{
    // set some cosmetics
    fieldSeparate = "  ";  // horizontal separation of fields
    fieldFree     =  " ";  // symbol for a field which is free
    fieldPlayer1  =  "X";  // symbol for a field that belongs to player 1
    fieldPlayer2  =  "O";  // symbol for a field that belongs to player 2

    // build vector *board*
    // remember x are the columns and y the rows
    for ( int row = 0; row < dim.second; ++row )
    {
        // initialise row vector
        board[row] = vector<string> ( dim.first );
        for ( int col = 0; col < dim.first; ++col )
        {
            board[row][col] = fieldFree;
        }
    }
}

/**
 * prints the board in the middle of the window and adds numbers to cols and letters to rows
 */
void Board::draw () const
{
    update();

    // draw the first line with numbers
    vector<string> firstLine ( dim.first + 1 );
    firstLine[0] = " ";
    for ( int i = 1; i < firstLine.size(); ++i ) {
        firstLine[i] = to_string(i);
    }
    mvprintw( bStartGlobal.second, bStartGlobal.first
            , "%s", vector_to_string(firstLine, fieldSeparate).c_str() );

    // draw the board onto the window with the first character in each row being a letter
    for ( unsigned int row = 0; row < board.size(); ++row ) {
        mvprintw ( bStartGlobal.second + vSpace * row + 1, bStartGlobal.first
                 , "%c%s", (const char)( 'A' + row ), fieldSeparate.c_str() );
        printw ( "%s", vector_to_string( board[row], fieldSeparate ).c_str() );
    }

    // add score and message
    if ( score != nullptr )
    {
        mvprintw( bStartGlobal.second + vSpace * board.size() + 2, bStartGlobal.first
                , "%i/%i sunk | %s", score->first, score->second, message.c_str() );
    }
}

/**
 * loop through board and check if you find a field which is still free
 */
bool Board::is_board_full ()
{
    for ( int row = 0; row < board.size(); ++row ) {
        for ( int col = 0; col < board[row].size(); ++col ) {
            if ( board[row][col] == fieldFree )
                return false;
        }
    }
    return true;
}

void Board::print_message ( const std::string& msg )
{
    message = msg;
    draw();
    refresh();
}

void Board::advance_score ()
{
    score->first++;
}

//// SETTERS ////

void Board::set_score ( int stonesPlayer1, int stonesPlayer2 )
{
    if ( score == nullptr )
    {
        score = new pair<int,int> { stonesPlayer1, stonesPlayer2 };
    }
    else
    {
        score->first = stonesPlayer1;
        score->second = stonesPlayer2;
    }

}

bool Board::set_field ( const std::pair<int, int> pos, const std::string& type )
{
    // is pos on the board?
    if ( pos.first  < 1 || pos.first  > dim.first
      || pos.second < 1 || pos.second > dim.second )
    {
        throw Error ( "Position is not on board in Board::set_field!" );
    }

    // otherwise replace the field
    string replace;
    if ( type == "PLAYER1" )
    {
        replace = fieldPlayer1;
    }
    else if ( type == "PLAYER2" )
    {
        replace = fieldPlayer2;
    }
    else
    {
        throw Error ( "Wrong replacement type in Board::set_field!" );
    }
    board[pos.second - 1][pos.first - 1] = replace;
    return true;
}

void Board::set_board ( std::vector<std::vector<std::string>>& b )
{
    board = b;
}

//// Getters ////

std::vector<std::vector<std::string>> Board::get_board () const
{
    return board;
}

std::pair<int, int> Board::get_dim () const
{
    return dim;
}

WINDOW* Board::get_window () const {
    return window;
}

//// PRIVATE METHODS ////

/**
 * This function is very important as it translates from global coordinates of the terminal
 * to local coordinated of the board
 */
bool Board::move_local ( std::pair<int, int> pos ) const
{
    // check if position is on the board
    if ( pos.first  < 1 || pos.first  > dim.first
      || pos.second < 1 || pos.second > dim.second)
    {
        return false;
    }
    else
    {
        // otherwise move the cursor to a position on the board in local coordinates
        int sepLength = (int)fieldSeparate.length();
        move( pos.second + bStartGlobal.second
            , bStartGlobal.first + pos.first * ( sepLength + 1 ) );
        posCursor = pos;
        return true;
    }
}


void Board::update () const
{
    // first get maximal dimensions of window
    int maxX, maxY;
    getmaxyx( window, maxY, maxX );

    int sepLength = (int)fieldSeparate.length();

    // starting pos (you need to add 1 to x/y_dim for the actual size of the board
    bStartGlobal = make_pair( ( maxX - dim.first * ( sepLength + 1 ) - 1 ) / 2
            , ( maxY - dim.second - 1 ) / 2 );
}


/**
 * helper function
 */
template <typename T>
string Board::vector_to_string ( const vector<T>& vector, const string& separate ) const
{
    // use streams as they are heavily overloaded
    stringstream finalStrStr;

    for ( int i = 0; i < vector.size(); ++i ) {
        finalStrStr << vector[i] << separate;
    }

    return finalStrStr.str();
}

