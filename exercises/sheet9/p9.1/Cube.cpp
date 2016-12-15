#include <iostream>
#include "Cube.h"

/**
 * Constructor constructs a Square to initialize a.
 */
Cube::Cube ( double a )
        : Square ( a )
{
    cubeCounter++;
}

void Cube::printProperties () const
{
    printf( "Edge length: %.2lf\n", a );
    printf( "Area:        %.2lf\n", area );
    printf( "Surface:     %.2lf\n", surface );
    printf( "Volume:      %.2lf\n", volume );
}

void Cube::initialize ()
{
    Square::initialize();   // initializes area
    volume = a * a * a;
    surface = 6 * area;     // using area of square
}

/**
 * We know that s is actually a cube, so we cast it
 * to one and have access to it's volume.
 * This of course could lead to problems comparing
 * cubes to actual squares. Dynamic cast will throw
 * if s is not a cube.
 */
double Cube::ratio ( const Square& s ) const
{
    const Cube* c = dynamic_cast<const Cube*>(&s);
    return volume / c->volume;
}

Cube::~Cube ()
{
    cubeCounter--;
}