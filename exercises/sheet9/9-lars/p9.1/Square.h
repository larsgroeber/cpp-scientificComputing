#ifndef P9_1_SQUARE_H
#define P9_1_SQUARE_H


class Square
{
public:
    Square ( double a );

    Square ( const Square& s );

    virtual ~Square ();

    virtual void printProperties () const;

    virtual void initialize ();

    /**
     * \brief overloaded operator /
     * Operators cannot be virtual, thus we have to use the virtual function ratio.
     * \param s
     * \return ratio of the areas of both squares
     */
    double operator/ ( const Square& s ) const;

    static int squareCounter;

protected:
    const double a;
    double area;
    double perimeter;

    virtual double ratio ( const Square& s ) const;
};


#endif //P9_1_SQUARE_H
