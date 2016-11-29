/*************************************************
*	Comments by Bulcsu Sandor: "// BS: "
*	Points: 4/6
*************************************************/

#include <iostream>     // cout, endl
#include <fstream>      // fstream

#include "main.h"
// BS: having just a header file is useless
// BS: the eval function source code should be defined 
// BS: entrielly in different file
// BS: and then compiled together

using namespace std;

double f ( double x )
{
    return x * x;
}

void eval ( double (*f)(double), int N, double a, double b )
{
    // declare a filestream file
    fstream file;
    // open file, file name and writeable
    file.open( "cpp_data.dat", ios_base::out );
    double x=(b-a)/N;
    double y=b-a;
    for ( double i = 0; i < y; i+=x )
    {
        // write into file
        file << i << " " << f(i) << endl;
        // also write to stdout
        std::cout << i << " " << f(i) << endl;
    }

    file.close();
}


int main ()
{
    // define a function pointer
    double (*func_ptr)(double);
    func_ptr = f;
    // BS: one should use a lot more points!
    eval( func_ptr, 1000, 1, 2 );
    return 0;
}
