#include <iostream>     // cout, endl
#include <fstream>      // fstream

#include "main.h"

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
    eval( func_ptr, 5, 1, 2 );
    return 0;
}
