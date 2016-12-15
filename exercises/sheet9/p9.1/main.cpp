/**
 * Solution of problem 1, sheet 9.
 * by Lars Gröber, Hendrik Edelmann and Robert Söder
 */

#include <iostream>
#include "Square.h"
#include "Cube.h"

// initialize both counters to zero
int Square::squareCounter = 0;
int Cube::cubeCounter = 0;

int main ()
{
    // Problem b)
    // test if the square class works
    std::cout << "Problem b)" << std::endl;
    Square s1 ( 1. );
    Square* s2 = new Square ( 2. );

    s1.initialize();
    s2->initialize();

    s1.printProperties();
    std::cout << std::endl;
    s2->printProperties();
    std::cout << std::endl;

    /*
     * The destructor for s1 gets called at the end of main.
     * For s1 was memory allocated on the stack, for s2 on the heap.
     * To check that one can do:
     * int i;
     * int* ptr;
     * And compare 'ptr' to '&i' because usually the heap is allocated
     * upwards of the stack (but that is architecture dependent).
     */

    // so:
    std::cout << "Is s1 allocated on the stack? - " << ( (s2 < &s1) ? "True" : "False" ) << std::endl;

    // To release the memory on the heap, one can use 'delete':
    delete s2; // destructor of s2 is called

    // Problem c)
    // usage of copy constructor
    Square s3 ( s1 );

    // Problem d)
    std::cout << std::endl << "Problem e)" << std::endl;

    Square* geoms [6];
    for ( int i = 0; i < 3; ++i )
    {
        geoms[i] = new Square ( ( double )i + 1. );
        geoms[i]->initialize();
        geoms[i]->printProperties();
        std::cout << std::endl;
        geoms[i+3] = new Cube ( ( double )i + 1. );
        geoms[i+3]->initialize();
        geoms[i+3]->printProperties();
        std::cout << std::endl;
    }

    // Problem f)
    std::cout << std::endl << "Problem f)" << std::endl;
    printf( "geoms[0] / geoms[1] = %.2lf\n", *(geoms[0]) / *(geoms[1]) );
    printf( "geoms[3] / geoms[4] = %.2lf\n", *(geoms[3]) / *(geoms[4]) );

    /*
     * Doing *(geoms[3]) / *(geoms[2]) - comparing a Cube to a Square - returns (at least on my system)
     * infinity.
     */

    for ( int j = 0; j < 6; ++j )
    {
        delete geoms[j];
    }

    return 0;
}