#include <cstdio>
#include <iostream>
#include "Square.h"

Square::Square ( double a )
        : a ( a )
{
    squareCounter++;
}

Square::Square ( const Square& s )
    : a ( s.a )
    , area ( s.area )
    , perimeter ( s.perimeter )
{
    squareCounter++;
}

void Square::printProperties () const
{
    printf( "Edge length: %.2lf\n", a );
    printf( "Area:        %.2lf\n", area );
    printf( "Perimeter:   %.2lf\n", perimeter );
}

void Square::initialize ()
{
    area = a * a;
    perimeter = 4 * a;
}

double Square::operator/ ( const Square& s ) const
{
    return ratio( s );
}

double Square::ratio ( const Square& s ) const
{
    return area / s.area;
}

Square::~Square ()
{
    squareCounter--;
    printf( "Square destroyed.\n" );
}
