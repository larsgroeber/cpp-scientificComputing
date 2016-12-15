#include <iostream>

#include "Cube.h"

Cube::Cube ( double a )
        : Square ( a )
{
    cubeCounter++;
}

Cube::~Cube ()
{
    cubeCounter--;
    printf( "Cube destructed.\n" );
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
    volume = a * a * a;
    surface = 6 * area;     // using area of square
}

double Cube::ratio ( const Square& s ) const
{
    const Cube* c = (const Cube*)(&s);
    return volume / c->volume;
}
