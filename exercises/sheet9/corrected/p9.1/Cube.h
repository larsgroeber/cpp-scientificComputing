#ifndef P9_1_CUBE_H
#define P9_1_CUBE_H

#include "Square.h"

class Cube : public Square
{
public:
    Cube ( double a );

    /**
     * \brief Destructor which just decrements the counter.
     */
    virtual ~Cube ();

    /**
     * \brief Prints the properties of this cube to the screen.
     * Does not need to be virtual here, but improves readability.
     */
    virtual void printProperties () const;

    /**
     * \brief Initiliazes volume and surface.
     */
    virtual void initialize ();

    /** Counter */
    static int cubeCounter;
    // BS: no public member variable

protected:
    /** Volume of the cube */
    double volume;
    /** Surface (the combined area of all six sides) of the cube. */
    double surface;

    /**
     * \brief Calculates the ratio between this cube's volume and c's volume.
     * \param c Cube (Square) to compare to.
     * \return The ratio.
     */
    virtual double ratio ( const Square& c ) const;
    // BS: good!
};

#endif //P9_1_CUBE_H
