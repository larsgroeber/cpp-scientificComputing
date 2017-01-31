/*************************************************
*	Comments by Bulcsu Sandor: "// BS: "
*	Points: 8/8
*************************************************/

/**
 * Solution to problem 2 of sheet 11
 * by Lars Gröber, Hendrik Edelmann
 *
 * Compile with g++ main.cpp -larmadillo
 */

#include <iostream>
#include <armadillo>

int main ()
{
    // set up A and b
    arma::Mat<double> A ( 30, 30 );
    A.randn();

    arma::Col<double> b ( 30 );
    b.randn();

    // print them on the screen (lots of output)
    std::cout << "This is the matrix A:" << std::endl;
    A.print();
    std::cout << std::endl << "This the vector b:" << std::endl;
    b.print();
    // BS: the following also works
    std::cout << std::endl << "This the vector b:" << std::endl;
    std::cout << b << std::endl;

    ////// a) //////
    // calculate determinant and trace
    std::cout << "det(A)  = " << arma::det( A ) << std::endl;
    std::cout << "tr(A)   = " << arma::trace( A ) << std::endl;

    ////// b) //////
    std::cout << std::endl;
    // calculate modulus of b
    std::cout << "|b|     = " << arma::norm( b ) << std::endl;

    ////// c) //////
    std::cout << std::endl;
    // solve the equation A*x = b for x
    std::cout << "Solving A*x = b...";
    std::fflush( stdout );

    arma::Col<double> X = arma::solve( A, b );

    std::cout << "Done" << std::endl;

    // check if A*X = b
    std::cout << "|b-A*x| = " << arma::norm( b - A * X ) << std::endl;
    // BS: good!
}
