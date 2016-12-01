/*
 * Solution to problem 2 sheet 7 by Lars Groeber, Robert Soeder and Hendrik Edelmann
 *
 * For a change I used pure c.
 *
 * To compile:
 * make
 *
 * To run:
 * ./problem2
 */

#include <tgmath.h>
#include <stdio.h>
#include <ctype.h>

/*
(a) - see pdf-document
*/

/*
(b)
*/

const long double default_a = 1;

/*
 * Function to return the integral for n = 0
 */
long double get_I0 ( long double a )
{
    return 1 / a * ( expl( a ) - 1 );
}

/*
 * Function to solve the integral using backward recursion
 */
long double backward_integrate ( int n, long double a )
{
    if ( n == 0 )
    {
        return get_I0( a );
    }
    else
    {
        return expl( a ) / a - ( n / a ) * backward_integrate( n - 1, a );
    }
}

/*
 * Function to solve the integral using forward recursion
 */
long double forward_integrate ( int endN, long double a )
{
    long double result = get_I0( a );
    for ( int n = 1; n <= endN; n++ )
    {
        result = expl( a ) / a - ( n / a ) * result;
    }
    return result;
}

/*
(c)
*/

/*
 * Helper function to calculate a factorial
 */
long double fac ( long double a )
{
    return ( a == 0 ) ? 1 : a * fac( a -1 );
}

/*
 * Function to solve the integral by using the series representation
 */
long double series_integrate ( int n, long double a )
{
    long double result = 0;
    for ( int i = 0; i <= n; ++i )
    {
        result += powl( -1., i ) * fac( n ) / fac( n - i ) * 1 / powl( a, i + 1 ) * expl( a );
    }
    /* at the end add the extra term to result */
    return result + powl( -1., n + 1 ) * fac( n ) / powl( a, n + 1 );
}

/*
(d)
 */

/*
 * Function to print all values starting at n = 0 up to n = N
 */
void print_range ( int N, long double a )
{
    printf( "\nAll values for a = %.2Lf up to n = %d:\n", a, N );

    printf( "n\tb\tf\ts\n" );

    for ( int i = 0; i <= N; ++i )
    /* for all n in the given range */
    {
        printf( "%d\t%.5Lf\t%.5Lf\t%.5Lf\n"
                , i
                , backward_integrate( i, a )
                , forward_integrate( i, a )
                , series_integrate( i, a ) );
    }
}

/*
 * Function to check a range of a for the value of n at which the recursion breaks down
 */
void check_range ( int N, long double min_a, long double max_a, long double step )
{
    printf( "The next table shows at which value of n the integration using the three methods breaks down\n"
            "(a zero denotes that there was no instability found):\n" );
    printf( "a\tb\tf\ts\n" );

    for ( long double a = min_a; a <= max_a; a += step )
    /* for all a's in the given range */
    {
        /* a = 0 would lead to a division by zero */
        if ( a == 0. )
        {
            continue;
        }

        int breaks_down[3] = { 0, 0, 0 };   /* values for n at which the methods break down */
        long double result[3];              /* results for the three methods */

        for ( int n = 0; n <= N; ++n )
        /* for all n in the given range */
        {
            result[0] = backward_integrate( n, a );
            result[1] = forward_integrate( n, a );
            result[2] = series_integrate( n, a );

            for ( int i = 0; i < 3; ++i )
            {
                /*
                 * this is a fairly crude way to check if the recursion breaks down
                 * the integral is never smaller than zero and goes to 0 for bigger n
                 */
                if ( breaks_down[i] == 0 && ( result[i] < 0 || result[i] > get_I0( a ) ) )
                {
                    breaks_down[i] = n;
                }
            }
        }

        /* print the results */
        printf( "%.2Lf\t%d\t%d\t%d\n"
                , a
                , breaks_down[0]
                , breaks_down[1]
                , breaks_down[2] );
    }
}

int main ()
{
    /* Problem b) */
    printf( "Hi, I am now going to integrate the function x^n*e^(ax) from 0 to 1 for a = 1\n"
            "using backward and forward recursion as well as a series representation.\n\n" );

    char c[10];
    int N;

    while ( 1 )
    {
        printf( "Please specify n (needs to be a positive integer or 0).\n" );

        fgets( c, sizeof c, stdin );

        /* convert c to N and check if its bigger than 0 */
        if ( sscanf( c, "%d", &N ) == 0 || N < 0 )
        {
            printf( "ERROR: Please give a positive integer!\n" );
            continue;
        }

        printf( "Backward recursion:           %.5Lf\n", backward_integrate( N, default_a ) );
        printf( "Forward recursion:            %.5Lf\n", forward_integrate( N, default_a ) );
        printf( "Integration using the series: %.5Lf\n", series_integrate( N, default_a ) );

        printf( "\nEnter another number? [Y/n]\n" );

        fgets( c, sizeof c, stdin );

        /* check user input */
        if ( c[0] != '\n' && tolower( c[0] ) != 'y' )
        {
            break;
        }
    }

    /* Problem d) */

    /* default values */
    int max_n = 30;
    long double min_a = -5;
    long double max_a = 5;
    long double step = 0.5;
    long double a;

    printf( "\nI can now a) print all values for the three methods for one a or \n"
            "          b) check for a range of a at which point the methods break down.\n" );

    while ( 1 )
    {
        /* get users choice */
        printf( "\nPlease type a or b: " );
        fgets( c, sizeof c, stdin );

        /* get the value of n */
        char c2[10];
        printf( "\nI will use %d as the limit for n. Press ENTER to use this value or give another one."
                , max_n );
        fgets( c2, sizeof c2, stdin );
        /* only writes into max_n if input is a number */
        if ( sscanf( c2, "%d", &max_n ) == 0 || max_n < 0 )
        {
            fprintf( stderr, "ERROR: Please give a positive integer!\n" );
            continue;
        }

        /* just print the values for a given a */
        if ( tolower( c[0] ) == 'a' )
        {
            printf( "\nPlease give a value of a: " );
            fgets( c, sizeof c, stdin );
            if ( sscanf( c, "%Lf", &a ) == 0 )
            {
                fprintf( stderr, "ERROR: Please give a number!\n" );
                continue;
            }

            print_range( max_n, a );
        }
        /* find the point at which the recursion breaks down */
        else if ( tolower( c[0] ) == 'b' )
        {
            printf( "\nI will use %.2Lf as the lower boundary and %.2Lf as the upper one with"
                    "a step size of %.2Lf.\n", min_a, max_a, step );
            printf( "Press ENTER to use these or give your own (format: min_a max_a step).\n" );
            fgets( c, sizeof c, stdin );

            if ( sscanf( c, "%Lf %Lf %Lf", &min_a, &max_a, &step ) == 0 )
            {
                printf( "ERROR: Please give at least one number!\n" );
                continue;
            }

            check_range( max_n, min_a, max_a, step );
        }

        /* ask if user wants to continue */
        printf( "\nExit? [y/N]" );

        fgets( c, sizeof c, stdin );

        if ( c[0] != '\n' && tolower( c[0] ) != 'n' )
        {
            break;
        }
    }

    return 0;
}