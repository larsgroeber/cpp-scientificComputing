#include <iostream>
#include <fstream>

double f ( double x )
{
    return x * x;
}

void eval ( double (*f)(double), int N, double a, double b )
{
    std::fstream file;
    file.open( "cpp_data.dat", std::ios_base::out );

    for ( int i = 0; i < N; ++i )
    {
        file << i << " " << f(i) << std::endl;
        std::cout << i << " " << f(i) << std::endl;
    }

    file.close();
}

int main ()
{
    double (*func_ptr)(double);
    func_ptr = f;
    eval( func_ptr, 5, 1, 2 );
    return 0;
}