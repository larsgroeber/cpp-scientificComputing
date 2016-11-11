#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include "../inc/Game.h"
#include "../inc/Error.h"

#define MY_KEY_ENTER 10     // for some reason KEY_ENTER does not work

using namespace std;

//// PUBLIC METHODS ////

Game::Game ( Board* b )
    : mBoard ( b )
    , dim ( b->get_dim() )
{
    mBoard->set_score( 0, 0 );

    // seed random number generator
    srand( time( NULL ) );
}

/**
 * Main game loop
 */
void Game::run ()
{
    int ch;

    // randomize ships positions
    randomize();

    // draw board for the first time
    mBoard->draw();
    refresh();

    // main game loop
    while ( ( ch = getch() ) != KEY_F(2) )
    {
        switch ( ch )
        {
            case MY_KEY_ENTER:
            {
                // redraw board
                mBoard->draw();
                refresh();
                break;
            }
            case KEY_F(12):
                show_debug();
                break;
            default:
               break;

        }

        if ( has_user_won() )
        {
            // show confirmation for player
            mBoard->print_message( "  You have won!  " );
            getch();
            break;
        }
    }
}

/**
 * simple implemention: just check if there are ships left alive
 */
bool Game::has_user_won ()
{
    if ( mBoard->is_board_full() )
    {
        throw Error ( "Board is full Game::has_user_won!" );
    }



    return false;
}

/**
 * This function follows this pattern:
 * 1) choose a random position on the board (startPos)
 * 2) check if ship can be placed there (using check_placement())
 *      A) if not: move one field to the right (or down if at end of row)
 *      - goto 2) -
 *      B) otherwise set ships positions and add to ships
 * 4) repeat at 1) for all ships in shipSizes
 * done
 */
bool Game::randomize ()
{
    return true;
}

//// PRIVATE METHODS ////


/**
 * Here we loop through all existing ships and check if one of their position
 * lies too close or on the given position.
 */
bool Game::check_position ( std::pair<int, int> pos ) const
{
    // first check if pos is on board (its allowed to be on the edge)
    if ( pos.first  < 1 || pos.first  > dim.first
      || pos.second < 1 || pos.second > dim.second)
    {
        return false;
    }


    return true;
}

/**
 * Shows user a new board only consisting of the ships positions
 */
void Game::show_debug () const
{
    Board debug = *mBoard;
    vector<vector<string>> newBoard ( dim.second );


    debug.draw();
    refresh();
}