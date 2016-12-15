#ifndef P9_1_CUBE_H
#define P9_1_CUBE_H


#include "Square.h"

class Cube : public Square
{
public:
    Cube ( double a );

    virtual ~Cube ();

    void printProperties () const;

    void initialize ();

    static int cubeCounter;

protected:
    double volume;
    double surface;

    double ratio ( const Square& c ) const;
};


#endif //P9_1_CUBE_H
