/**
 * Solution to problem2
 *
 * Run with
 * cmake . && make && ./LarsRobertHendrik_problem2
 * or
 * g++ -o LarsRobertHendrik_problem2 LarsRobertHendrik_problem2.cpp
 */

/*************************************************
*	Comments by Bulcsu Sandor: "// BS: "
*	Points: 8/8
*************************************************/

// BS: message:
// BS: CMake Error at CMakeLists.txt:1 (cmake_minimum_required):
//     CMake 3.6 or higher is required.  You are running version 2.8.12.2
// BS: g++ -std=c++11 LarsRobertHendrik_problem2_corrected.cpp works!
// BS: nicely commented!

#include <iostream>
#include <cmath>

using namespace std;                                // if eg cout used only once one can also write std::cout

void divWithRem ( int a, int b);                    // defined the function for task c
double myfunc ( double a, double b) ;                // defined the function for task d

int main() {

    //
    // Task (a)
    //
    printf("--------------------\n----- Task (a) -----\n--------------------\n\n");

    int myArray[5] = {1, 3, 5, 7, 9};

    for (int i = 0; i <= 4; ++i) {                   //added "int" to the integer i // changed "i <= 6" to 4
        cout << " myArray [" << i << "] = " << myArray[i] << endl;
    }
    cout << endl << endl;


    //
    //Task (b)
    //
    printf("--------------------\n----- Task (b) -----\n--------------------");
    cout << endl << endl;

    double f, x;                                    //added ";"
    x = 1;
    f = sin(x) ;                                    //added "#include <cmath>" on the top
    printf ("sin ( %.4f ) = %.4f", x, f) ;          //added "#include <stdio.h>"

    cout << endl << endl;


    //
    //Task (c)
    //
    printf("--------------------\n----- Task (c) -----\n--------------------\n\n");

    divWithRem (7 , 2) ;                            //changed the float to integer

    cout << endl << endl;


    //
    //Task (d)
    //
    printf("--------------------\n----- Task (d) -----\n--------------------\n\n");

    double result = myfunc (5 , 2) ;                // changed *int* to *double*
    cout << result;

}

void divWithRem ( int a, int b) {
    int h = a/b;                                    // auxiliar variable    // added missing bs
    cout << a << " / " << b << " = " << h;          // changed "<" to "<<"
    cout << ", remainder : " << a%b << endl ;
}

double myfunc ( double a, double b) {
    return a*a+b*b;
}
