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

    /**
     * \brief Prints the properties of this object to the screen.
     */
    virtual void printProperties () const;

    /**
     * \brief Initializes area and perimeter.
     */
    virtual void initialize ();

    /**
     * \brief Overloaded operator /
     * Operators cannot be virtual, thus we have to use the virtual function ratio.
     * \param s Square to compare to
     * \return The ratio of the areas of both squares.
     */
    double operator/ ( const Square& s ) const;

    /** Counter */
    static int squareCounter;

protected:
    /** Length of the sides */
    const double a;
    /** Area of the square */
    double area;
    /** Perimeter of the square */
    double perimeter;

    /**
     * \brief Function to calculate the ratio between the areas of this square and 's'.
     *        Is only called by the overloaded operator /.
     * \param s Square to compare to.
     * \return The ratio of the areas of both squares.
     */
    virtual double ratio ( const Square& s ) const;
};

#endif //P9_1_SQUARE_H
