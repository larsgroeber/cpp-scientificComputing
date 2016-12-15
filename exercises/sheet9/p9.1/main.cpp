#include <iostream>
#include "Square.h"
#include "Cube.h"

int Square::squareCounter = 0;
int Cube::cubeCounter = 0;

int main ()
{
    Square s1 ( 1. );
    Square* s2 = new Square ( 2. );

    s1.initialize();
    s2->initialize();

    s1.printProperties();
    s2->printProperties();

    /*
     * The destructor for s1 gets called at the end of main.
     * For s1 was memory allocated on the stack. To check that you can do:
     * int* ptr;
     * int i;
     * And compare 'ptr' to '&i' because usually the heap is allocated
     * upwards of the stack (but that is architecture dependent).
     */

    // so:
    std::cout << "Is s1 allocated on the stack? - " << ( (s2 < &s1) ? "True" : "False" ) << std::endl;

    // To release the memory on the heap, one can use 'delete':
    delete s2; // destructor of s2 is called

    // usage of copy constructor
    Square s3 ( s1 );

    std::cout << std::endl << "Problem e)" << std::endl;

    Square* geoms [6];
    for ( int i = 0; i < 3; ++i )
    {
        geoms[i] = new Square ( ( double )i + 1. );
        geoms[i]->initialize();
        geoms[i]->printProperties();
        geoms[i+3] = new Cube ( ( double )i + 1. );
        geoms[i+3]->initialize();
        geoms[i+3]->printProperties();
    }

    printf( "geoms[0] / geoms[1] = %.2lf\n", *(geoms[0]) / *(geoms[1]) );
    printf( "geoms[3] / geoms[4] = %.2lf\n", *(geoms[3]) / *(geoms[4]) );

    for ( int j = 0; j < 6; ++j )
    {
        delete geoms[j];
    }

    return 0;
}