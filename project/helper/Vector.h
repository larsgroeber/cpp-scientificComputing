#ifndef TEST_GRAVITY_VECTOR_H
#define TEST_GRAVITY_VECTOR_H

namespace LH
{
    /**
     * \brief Struct which implements a simple 2D vector
     */
    struct Vector
    {
        Vector () : x ( 0 ), y ( 0 ) {};

        Vector ( long double x, long double y ) : x ( x ), y ( y ) {};

        long double dot_product ( const Vector& A ) const;

        long double size () const;

        Vector unit () const;

        Vector operator*  ( const Vector& A ) const;

        Vector operator+  ( const Vector& A ) const;

        Vector operator+= ( const Vector& A );

        Vector operator-  ( const Vector& A ) const;

        Vector operator-= ( const Vector& A );

        bool   operator== ( const Vector& A ) const;

        long double x;
        long double y;
    };

    // templates cannot be defined in separate .cpp file
    template <typename T1>
    Vector operator* ( const T1& a, const Vector& V )
    {
        return Vector( V.x * a, V.y * a );
    }

    template <typename T1>
    Vector operator* ( const Vector& V, const T1& a )
    {
        return Vector( V.x * a, V.y * a );
    }

    template <typename T2>
    Vector operator/ ( const Vector& V, const T2& a )
    {
        return Vector( V.x / a, V.y / a );
    }
}

#endif //TEST_GRAVITY_VECTOR_H
