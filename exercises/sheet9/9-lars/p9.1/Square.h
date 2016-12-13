#ifndef P9_1_SQUARE_H
#define P9_1_SQUARE_H


class Square
{
public:
    Square ( double a );

    Square ( const Square& s );

    virtual ~Square ();

    void printProperties () const;

    void initialize ();

    static int squareCounter;

private:
    const double a;
    double area;
    double perimeter;
};


#endif //P9_1_SQUARE_H
