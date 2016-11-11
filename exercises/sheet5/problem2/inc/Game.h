#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H

#include "Board.h"

/**
 * @brief Class making the actual game run.
 * @author Lars Groeber
 */
class Game
{
public:
    /**
     * @brief Constructor
     * @param b pointer to Board object
     */
    Game ( Board* b );

    /**
     * @brief Main game function
     * Is the only function being called from outside to start the game
     * also includes the actual game loop.
     */
    void run ();

    /**
     * @brief Function that randomizes the ships positions.
     * Uses check_placement() and check_position()
     * @return bool if placement was successful
     */
    bool randomize ();

    /**
     * @brief Function which checks if user has won.
     * @return bool
     */
    bool has_user_won ();

private:
    /** Pointer to the board being used */
    Board* mBoard;
    /** Dimensions of the board (x,y) */
    const std::pair<unsigned int, unsigned int> dim;

    void player1_play ();

    void player2_play ();

    void update_board ();

    /**
     * @brief Function which shows debug information
     * (for now only the ships location)
     */
    void show_debug () const;

    /**
     * @brief check if a postion is valid for a new ship.
     *        That means: a) the pos is on the board
     *                    b) the pos is free (there is no ship there)
     *                    c) there is no ship within one tile
     * @param pos the pos to be checkesd (local coords)
     * @return bool if pos is valid
     */
    bool check_position ( std::pair<int, int> pos ) const;
};


#endif //BATTLESHIP_GAME_H
