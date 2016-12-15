//
// Created by Hendrik on 13.12.2016.
//

#include "iostream"
#include "Square.h"

using namespace std;

Square::Square ( const double edgeLengthA )
{
    const double a = edgeLengthA;                         // a = edge length
    squareCounter ++;
}


Square::~Square ()
{
    printf ("%d", squareCounter);
}

int countNullVariables = 0;

void Square::initialize ()
{
    if ( char (squareCounter)   == '\0' ) { countNullVariables ++; }    // converts the variable to char and looks if it is empty ('\0' = escape character)
//    if ( char (a)               == '\0' ) { countNullVariables ++; }  // a is not in the scope
    if ( char (area)            == '\0' ) { countNullVariables ++; }
    if ( char (perimeter)       == '\0' ) { countNullVariables ++; }
//    cout << countNullVariables << endl;                               // not required for the task
}

void Square::printProperties () const
{
    // TODO: check formatting
    printf ("%d", squareCounter);
//    printf ();  // TODO: print a
    printf ("%f", area);
    printf ("%f", perimeter);
}