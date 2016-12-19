
#include <tgmath.h>
#include "../Vector.h"

LH::Vector::Vector ( long double x, long double y )
    : x ( x ), y ( y )
{
}

long double LH::Vector::dot_product ( const LH::Vector& A ) const
{
    return x * A.x + y * A.y;
}

LH::Vector LH::Vector::operator* ( const LH::Vector& A ) const
{
    return LH::Vector ( x * A.x, y * A.y );
}

LH::Vector LH::Vector::operator+ ( const LH::Vector& A ) const
{
    return LH::Vector ( x + A.x, y + A.y );
}

LH::Vector LH::Vector::operator- ( const LH::Vector& A ) const
{
    return LH::Vector ( x - A.x, y - A.y );
}

bool LH::Vector::operator== ( const LH::Vector& A ) const
{
    return x == A.x && y == A.y;
}

long double LH::Vector::size () const
{
    return sqrt( x * x + y * y );
}

LH::Vector LH::Vector::unit () const
{
    return *this / this->size();
}
