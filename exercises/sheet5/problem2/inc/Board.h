#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <ncurses.h>
#include <vector>
#include <string>

/**
 * Class which is responsible for drawing the board and keeping
 * track of the cursor position
 * @author Lars Gröber
 */
class Board
{
public:
    /**
     * @brief constructor
     * @param x x dimension of board
     * @param y y dimension of board
     * @param win window to draw on
     */
    Board ( unsigned int x, unsigned int y, WINDOW* win );

    /**
     * @brief function to draw the actual board onto window
     */
    void draw () const;

    /**
     * @brief check if board is full (no empty field)
     * @return boolean
     */
    bool is_board_full ();

    /**
     * @brief Function to print a message beneath the board
     * @param msg the message
     */
    void print_message ( const std::string& msg );

    //// SETTERS ////

    /**
     * @brief function which sets a field on the board
     * @param pos the position to set the field (local coords)
     * @param type string stating of which type the field should be
     * @return if the field was free
     */
    bool set_field ( const std::pair<int,int> pos, const std::string& type );

    /**
     * @brief Function to set the board to a new one
     * @param b the new board (correct type is important here)
     */
    void set_board ( std::vector<std::vector<std::string>>& b );

    //// GETTERS ////

    /**
     * @brief function which returns the board vector
     * @return board
     */
    std::vector<std::vector<std::string>> get_board () const;

    /**
     * @brief functions which returns the dimensions of the board
     * @return dim
     */
    std::pair<int,int> get_dim () const;

    /**
     * @brief Function which returns the Boards window
     * @return window
     */
    WINDOW* get_window () const;

    /**
     * @brief Function to return the sysmbols for both players.
     * @return a pair of strings containing the symbols
     */
    std::pair<std::string,std::string> get_player_sym () const;

private:
    /** dimensions of the board (x,y) */
    const std::pair<unsigned int, unsigned int> dim;
    /** starting pos of the board in global coords */
    mutable std::pair<int, int> bStartGlobal;

    /** window to draw on */
    WINDOW* window;

    /** vector holding all information about the board */
    std::vector<std::vector<std::string>> board;

    /** variables which define the look of the board */
    std::string fieldSeparate;
    std::string fieldFree;
    std::string fieldPlayer1;
    std::string fieldPlayer2;
    unsigned int vSpace;

    /** message */
    std::string message;

    /**
     * @brief this function does all updating which needs to be done between drawings
     *        like set boardStart according to terminal size
     */
    void update () const;

    /**
     * @brief template helper function to print a vector to a string
     * @param vector the vector of type T to be printed
     * @param separate the separation string
     */
    template <typename T>
    std::string vector_to_string ( const std::vector<T>& vector, const std::string& separate ) const;
};


#endif //BATTLESHIP_BOARD_H
