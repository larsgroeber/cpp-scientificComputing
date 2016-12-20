#ifndef P9_1_SQUARE_H
#define P9_1_SQUARE_H

class Square
{
public:
    Square ( double a );

    /**
     * \brief Copy constructor.
     * \param s The target opject.
     */
    Square ( const Square& s );

    /**
     * \brief Destructor, only decrements the counter.
     */
    virtual ~Square ();
    // BS: ok!

    /**
     * \brief Prints the properties of this object to the screen.
     */
    virtual void printProperties () const;
    // BS: ok!

    /**
     * \brief Initializes area and perimeter.
     */
    virtual void initialize ();
    // BS: ok!

    /**
     * \brief Overloaded operator /
     * Operators cannot be virtual, thus we have to use the virtual function ratio.
     * \param s Square to compare to
     * \return The ratio of the areas of both squares.
     */
    double operator/ ( const Square& s ) const;
    // BS: this is the solution I was looking for!

    /** Counter */
    static int squareCounter;
    // BS: according to the problem sheet 
    // BS: this should not be public variable

protected:
    /** Length of the sides */
    const double a;
    /** Area of the square */
    double area;
    /** Perimeter of the square */
    double perimeter;
    // BS: perimeter variable should not be inherited!!    

    /**
     * \brief Function to calculate the ratio between the areas of this square and 's'.
     *        Is only called by the overloaded operator /.
     * \param s Square to compare to.
     * \return The ratio of the areas of both squares.
     */
    virtual double ratio ( const Square& s ) const;
    // BS: good!
};

#endif //P9_1_SQUARE_H
