#include <iostream>
#include "Square.h"

Square::Square ( double a )
        : a ( a )
{
    squareCounter++;
}

/**
 * Copy constructor which just copies all values from s to this square and increments the counter.
 */
Square::Square ( const Square& s )
    : a ( s.a )
    , area ( s.area )
    , perimeter ( s.perimeter )
{
    squareCounter++;
}
// BS: ok!

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

/**
 * Here we just call the function 'ratio' which is virtual.
 */
double Square::operator/ ( const Square& s ) const
{
    return ratio( s );
}

double Square::ratio ( const Square& s ) const
{
   // BS: for tesing:
   std::cout << "oprator / of Square class called " << std::endl;
   return area / s.area;
}
// BS: good!

Square::~Square ()
{
    squareCounter--;
}
