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
    int ch;

    // randomize ships positions
    randomize();

    // draw board for the first time
    mBoard->draw();
    refresh();

    mBoard->print_message( "Initial stone placement, press any key to continue." );
    getch();

    for ( int i = 0; i < 10; ++i )
    {
        player1_play();
        player2_play();

        mBoard->draw();
        refresh();
        getch();
    }

    mBoard->print_message( "Board after 20 rounds." );
    getch();
}


bool Game::has_user_won ()
{
    if ( mBoard->is_board_full() )
    {
        throw Error ( "Board is full Game::has_user_won!" );
    }



    return false;
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
    mBoard->set_score( 5, 5 );
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

    vector<vector<string>> board = mBoard->get_board();

    while ( ! stonePlaced )
    {
        // throw an Error if we could be in an endless loop
        if ( pos == startPos && tries != 0 )
        {
            throw Error ( "Was not able to set stone, got back to startPos in Game::player1_play()!" );
        }

        // move one pos - see 2.A)
        if ( pos.first == dim.first )
        {
            pos.first = 1;
            pos.second = pos.second % dim.second + 1;
        }
        else
        {
            pos.first++;
        }

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
    cout << "now after call set_field" << endl;
    p1_stones.push_back( pos );
}

void Game::player2_play ()
{

}

std::pair<int,int> Game::get_random_pos () const
{
    return make_pair( rand() % dim.first + 1, rand() % dim.second + 1 );
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