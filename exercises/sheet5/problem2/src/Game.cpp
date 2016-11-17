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
    , p1_sym ( b->get_player_sym().first )
    , p2_sym ( b->get_player_sym().second )
{
    // seed random number generator
    srand( time( NULL ) );
}

/**
 * Main game loop
 */
void Game::run ()
{
    // randomize ships positions
    randomize();

    // draw board for the first time
    mBoard->draw();
    refresh();

    mBoard->print_message( "Initial stone placement, press any key to continue." );
    getch();
    
    mBoard->print_message( "           Now playing, wait until done.           " );

    int sleepTime ( 1 );

    for ( int i = 0; i < 10; ++i )
    {
        player1_play();
        sleep( sleepTime );
        mBoard->draw();
        refresh();

        player2_play();
        sleep( sleepTime );
        mBoard->draw();
        refresh();
    }

    mBoard->print_message( "               Board after 20 moves.               " );
    getch();
}

/**
 * This function adds 10 stones randomly to the board.
 */
bool Game::randomize ()
{
    int maxTries = 10;
    // set 10 random pieces
    for ( int i = 0; i < 10; ++i )
    {
        int tries ( 0 );

        pair<int,int> randomPos { 1, 1 };

        while ( ! check_position( randomPos ) )
        {
            if ( tries >= maxTries )
            {
                throw Error ( "Could not place stone, maxTries exceeded in Game::randomize()!" );
            }

            randomPos = get_random_pos();

            tries++;
        }

        string player;
        if ( i % 2 == 0 )
        {
            player = "PLAYER1";
            p1_stones.push_back( randomPos );
        }
        else
        {
            player = "PLAYER2";
            p2_stones.push_back( randomPos );
        }
        mBoard->set_field( randomPos, player );
    }
    return true;
}

//// PRIVATE METHODS ////


/**
 * Here we check if pos is on the board and if the position is still free
 */
bool Game::check_position ( std::pair<int, int> pos ) const
{
    // first check if pos is on board (its allowed to be on the edge)
    if ( pos.first  < 1 || pos.first  > dim.first
      || pos.second < 1 || pos.second > dim.second)
    {
        return false;
    }

    for ( auto p : p1_stones )
    {
        if ( p == pos ) { return false; }
    }

    for ( auto p : p2_stones )
    {
        if ( p == pos ) { return false; }
    }

    return true;
}

/**
 * This player places his stones such that there is at least one
 * of his stone on an adjacent point.
 *
 * Implementation is similar to the one used for the battleship problem:
 * 1) choose a random position on the board (startPos)
 * 2) check if stone can be placed there (using check_psoition() and own rules)
 *      A) if not: move one field to the right (or down if at end of row)
 *      - goto 2) -
 *      B) otherwise use position for next stone
 * done
 */
void Game::player1_play ()
{
    pair<int,int> startPos = get_random_pos();
    pair<int,int> pos = startPos;

    bool stonePlaced = false;

    int tries ( 0 );

    while ( ! stonePlaced )
    {
        // throw an Error if we could be in an endless loop
        if ( pos == startPos && tries != 0 )
        {
            throw Error ( "Was not able to set stone, got back to startPos in Game::player1_play()!" );
        }

        // move one pos - see 2.A)
        pos.first = pos.first % dim.first + 1;
        pos.second = ( pos.first == dim.first ) ? pos.second % dim.second + 1 : pos.second;

        // see step 2)
        if ( check_position( pos ) )
        {
            for ( auto p : p1_stones )
            {
                if ( ( pos.first + 1 == p.first && pos.second     == p.second )
                  || ( pos.first     == p.first && pos.second + 1 == p.second )
                  || ( pos.first - 1 == p.first && pos.second     == p.second )
                  || ( pos.first     == p.first && pos.second - 1 == p.second ) )
                {
                    stonePlaced = true;
                }
            }
        }

        tries++;
    }
    mBoard->set_field( pos, "PLAYER1" );
    p1_stones.push_back( pos );
}

/**
 * This player places his stones on one of the fields with
 * the highest number of opponent’s stones on theneighbour
 * points, but less then four.
 *
 * Algorithm is similar to player1_play().
 */
void Game::player2_play ()
{
    pair<int,int> startPos = get_random_pos();
    pair<int,int> pos = startPos;

    bool stonePlaced = false;

    int tries ( 0 );

    pair<pair<int,int>,int> bestPos { { 0, 0 }, 0 };    // ( pos, # of stones nearby )

    while ( ! stonePlaced )
    {
        if ( pos == startPos && tries != 0 )
        {
            // throw an Error if we could be in an endless loop (if bestPos was not changed)
            if ( bestPos == make_pair( make_pair( 0, 0 ), 0 ) )
            {
                throw Error ( "Was not able to set stone, got back to startPos in Game::player2_play()!" );
            }
            else
            {
                // if it was changed we have found a new position for the stone
                stonePlaced = true;
            }
        }

        // move one pos - see 2.A)
        pos.first = pos.first % dim.first + 1;
        pos.second = ( pos.first == dim.first ) ? pos.second % dim.second + 1 : pos.second;

        // see step 2)
        if ( check_position( pos ) )
        {
            int stonesNearby ( 0 );
            for ( auto p : p1_stones )
            {
                if ( ( pos.first + 1 == p.first && pos.second     == p.second )
                  || ( pos.first     == p.first && pos.second + 1 == p.second )
                  || ( pos.first - 1 == p.first && pos.second     == p.second )
                  || ( pos.first     == p.first && pos.second - 1 == p.second ) )
                {
                    // if p is nearby
                    stonesNearby++;
                }
            }
            // if pos is a stone with more stones nearby, save it
            bestPos = ( stonesNearby > bestPos.second && stonesNearby < 4 ) ?
                        make_pair( pos, stonesNearby ) : bestPos;
        }

        tries++;
    }
    mBoard->set_field( bestPos.first, "PLAYER2" );
    p2_stones.push_back( bestPos.first );
}

std::pair<int,int> Game::get_random_pos () const
{
    return make_pair( rand() % dim.first + 1, rand() % dim.second + 1 );
}
