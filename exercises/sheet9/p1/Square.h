//
// Created by Hendrik on 13.12.2016.
//

#ifndef P1_SQUARE_H
#define P1_SQUARE_H


class Square
{                                           // by default all members are private

    static int squareCounter;               // counter for number of elements of this class
    double area;
    double perimeter;

public:

    /**
     * @brief initialize a with a value given as argument to the constructor and increase the counter
     * @param edgeLengthA
     * @return
     */
    Square ( const double edgeLengthA );

    /**
     * @brief decreases the counter again and prints out the number of remaining class objects
     */
    ~Square ();

    /**
     * @brief calculate the remaining undeﬁned parameters
     */
    void initialize ();

    /**
     * @brief print all properties of the square
     */
    void printProperties () const;
};


#endif //P1_SQUARE_H