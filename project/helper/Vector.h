#ifndef TEST_GRAVITY_VECTOR_H
#define TEST_GRAVITY_VECTOR_H

namespace LH
{
    struct Vector
    {
        Vector ( long double x, long double y );

        long double dot_product ( const Vector& A ) const;

        long double size () const;

        Vector unit () const;

        Vector operator*  ( const Vector& A ) const;

        template <typename T1>
        Vector operator*  ( const T1& a ) const;

        template <typename T2>
        Vector operator/  ( const T2& a ) const;

        Vector operator+  ( const Vector& A ) const;

        Vector operator-  ( const Vector& A ) const;

        bool   operator== ( const Vector& A ) const;

        long double x;
        long double y;
    };


    // templates cannot be defined in separate .cpp file
    template <typename T1>
    Vector Vector::operator* ( const T1& a ) const
    {
        return Vector( x * a, y * a );
    }

    template <typename T2>
    Vector Vector::operator/ ( const T2& a ) const
    {
        return Vector( x / a, y / a );
    }
}

#endif //TEST_GRAVITY_VECTOR_H
