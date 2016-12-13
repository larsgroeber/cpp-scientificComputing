#include <iostream>
#include "Square.h"

int Square::squareCounter = 0;

int main ()
{
    Square s1 ( 1. );
    Square* s2 = new Square ( 2. );

    s1.initialize();
    s2->initialize();

    s1.printProperties();
    s2->printProperties();

    /*
     * For s1 was memory allocated on the stack. To check that you can do:
     * int* ptr;
     * int i;
     * And compare 'ptr' to '&i' because usually the heap is allocated
     * upwards of the stack (but that is architecture dependent).
     */

    // so:
    std::cout << "Is s1 allocated on the stack? - " << ((s2 < &s1) ? "True" : "False") << std::endl;

    // To release the memory on the heap, one can use 'delete':
    delete s2; // destructor of s2 is called

    // usage of copy constructor
    Square s3 ( s1 );



    return 0;
} // destructor of s1 is called