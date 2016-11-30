#include <iostream>
#include <math.h>
#include <cstring>


/*
 Problem 2 (Recursive functions) 7 Pts
(a) Find a reduction formula for the following integral. (1)
(Hint: Integration by parts)
*/



/*
(b) Implement forward and backward recursion, setting the parameter a = 1.
(Hint: For the backward recursion you can assume the Integral to be ≈ 0
for n = 50.)
*/

const long double default_a = 1;
const long double start = 0;     // TODO: use these!
const long double end = 1;

long double get_I0 ( long double a )
{
    return 1 / a * ( exp( a ) - 1 );
}

long double backward_integrate ( int n, long double a )
{
    if ( n == 0 )
    {
        return get_I0( a );
    }
    else if ( n >= 50 )
    {
        return 0;
    }
    else
    {
        return exp( a ) / a - ( n / a ) * backward_integrate( n - 1, a );
    }
}

long double forward_integrate ( int endN, long double a )
{
    long double result = get_I0( a );
    for ( int n = 1; n <= endN; n++ )
    {
        result = exp ( a ) / a - ( n / a ) * result;
    }
    return result;
}

/*
(c) By successively reinserting the reduction formula into itself, i.e.(2)
ﬁnd a series representation for the integral and write a program to im-
plement this series!
*/

long double fac ( long double a )
{
    return ( a == 0 ) ? 1 : a * fac( a -1 );
}

long double series ( int n, long double a )
{
    long double result = 0;
    for ( int i = 0; i <= n; ++i )
    {
        result += pow( -1., i ) * fac( n ) / fac( n - i ) * 1 / pow( a, i + 1 ) * exp( a );
    }
    return result + pow( -1., n + 1 ) * fac( n ) / pow( a, n + 1 );
}

/*
(d) Print the forward, backward recursion and the series representation for
a range of n for a < 1 and a > 1. Where do the single methods brake
down? What is the reason? How is the stability of the formulas related
to the parameter a?
 */

void print_range ( int N, long double a )
{
    printf( "\n\nI will now print all values for a = %.2Lf up to n = %d", a, N );
    getchar();

    printf( "n\tBackward Forward Series\n" );

    for ( int i = 0; i <= N; ++i )
    {
        printf( "%d\t%.5Lf\t%.5Lf\t%.5Lf\n"
                , i
                , backward_integrate( i, a )
                , forward_integrate( i, a )
                , series( i, a ) );
    }
}

int main() {
    printf( "Hi, I am now going to integrate the function x^n*e^(ax) from 0 to 1 for a = 1\n"
            "using backward and forward recursion as well as a series representation.\n" );

    char c[10];
    int N;

    while ( true )
    {
        printf( "Please specify n (needs to be a positive integer or 0).\n" );

        fgets( c, sizeof c, stdin );

        if ( sscanf( c, "%d", &N ) == 0 || N < 0 )
        {
            fprintf( stderr, "ERROR: Please give a positive integer!\n" );
            return 1;
        }

        printf( "Backward integration:         %.5Lf\n", backward_integrate( N, default_a ) );
        printf( "Forward integration:          %.5Lf\n", forward_integrate( N, default_a ) );
        printf( "Integration using the series: %.5Lf\n", series( N, default_a ) );

        printf( "\nEnter another number? [Y/n]\n" );

        fgets( c, sizeof c, stdin );

        if ( c[0] != '\n' && tolower( c[0] ) != 'y' )
        {
            break;
        }
    }

    int max_n = 30;
    double min_a = -5;
    double max_a = 1;

    print_range( max_n, max_a );
    print_range( max_n, min_a );

    return 0;
}