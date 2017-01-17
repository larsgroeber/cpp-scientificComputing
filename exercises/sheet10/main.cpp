/**
 * Exercise 1 of sheet 10
 * by Lars Gröber, Hendrik Edelmann
 *
 * You might have to compile it using -std=c++11.
 */

#include <iostream>     // printf
#include <chrono>       // std::chrono
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <memory>       // std::shared_ptr
#include <fstream>

const int SIZE_ARRAY = 100000000;

// define our containers
// the last one is the STL implementation of a c-array
// as we cannot define it at runtime, we chose to always go with the maximum size
typedef std::vector<std::string> Vector;
typedef std::map<int,std::string> Map;
typedef std::list<std::string> List;
typedef std::array<std::string,SIZE_ARRAY> Array;

struct Measure
{
    /**
     * \brief Function to measure the time a function takes to execute.
     * \param func  The function to measure
     * \param args  The function's arguments
     * \return      Time the function took in seconds
     */
    template <typename F, typename... Args>
    static double duration ( F& func, Args&... args )
    {
        auto start = std::chrono::steady_clock::now();
        func( args... );
        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration<double>( end - start ).count();
    }
};

/**
 * \brief Helper function to fill a container with hexadecimal numbers
 * \param func Function to insert one element into the container
 * \param args The container
 * \param N    Number of elements
 */
template <typename F, typename Args>
void fill_loop ( F& func, Args& args, int N )
{
    for ( int i = 0; i < N; ++i )
    {
        std::stringstream ss;
        ss << std::hex << i;
        func ( args, i, ss.str() );
    }
}

/**
 * The next functions are used to insert one element into the different containers.
 */
void insert_vector ( std::shared_ptr<Vector> v, int i, std::string s )
{
    (*v)[i] = s;
}

void insert_map ( std::shared_ptr<Map> m, int i, std::string s )
{
    m->insert( std::make_pair( i, s ) );
}

void insert_list ( std::shared_ptr<List> l, int i, std::string s )
{
    l->push_back( s );
}

void insert_array ( std::shared_ptr<Array> array, int i, std::string s )
{
    (*array)[i] = s;
}

/**
 * The next functions are used to look up values in different containers
 */
template <typename F, typename Args>
void access_loop ( F& func, Args& args, int K, int N )
{
    srand( time(NULL) );

    // generate K random numbers between 0 and N - 1 to access
    for ( int i = 0; i < K; ++i )
    {
        int r = rand() % N;

        func( args, r );
    }
};

std::string access_vector ( std::shared_ptr<Vector> v, int i )
{
    // random access is O(1)
    return (*v)[i];
}

std::string access_map ( std::shared_ptr<Map> m, int i )
{
    // O(log(n)) - binary search
    return m->find( i )->second;
}

std::string access_list ( std::shared_ptr<List> l, int i )
{
    // complexity is equal to i
    auto it = l->begin();
    std::advance( it, i );
    return *it;
}

std::string access_array ( std::shared_ptr<Array> a, int i )
{
    // similar to vector, O(1)
    return (*a)[i];
}


int main ()
{
    ////////// a) //////////

    printf( "\n////////// Task 10.1.a //////////\n\n");

    // the limits
    const std::vector<unsigned> limitsN { 100000, 1000000, 10000000, 100000000 };

    for ( auto&& n : limitsN )
    {
        printf( "Do you want to (continue to) measure insert times? [y/n]\n" );
        std::string s;
        std::cin >> s;
        if ( s != "y" )
        {
            break;
        }

        // our containers, we need to allocate the array on the heap (stack is too small)
        // so we allocate all of them on the heap
        // and use smart pointer to delete their contents once they are not needed anymore
        // on my system this code needed at least 10gb of RAM for the last value of n!
        std::shared_ptr<Vector> v ( new Vector ( n ) );
        std::shared_ptr<Map> m ( new Map );
        std::shared_ptr<List> l ( new List );
        std::shared_ptr<Array> a ( new Array );

        printf( "Measuring now for N = %d\n", n );
        printf( "Vector: %lf\n"
                , Measure::duration( fill_loop<decltype( insert_vector ), decltype( v )>, insert_vector, v, n ) );
        v.reset(); // deleting v here reduces memory usage
        printf( "Map:    %lf\n"
                , Measure::duration( fill_loop<decltype( insert_map )   , decltype( m )>, insert_map   , m, n ) );
        m.reset();
        printf( "List:   %lf\n"
                , Measure::duration( fill_loop<decltype( insert_list )  , decltype( l )>, insert_list  , l, n ) );
        l.reset();
        printf( "Array:  %lf\n"
                , Measure::duration( fill_loop<decltype( insert_array ) , decltype( a )>, insert_array , a, n ) );
    }

    /*
     * 1 char = 1Byte
     * Each string has at least 1 chars (#)
     * Considering 100000:
     * 100000 = 186A0
     * Memory = 15 * 1B + 15*16 * 2B + 15 * 16^2 * 3B + 15 * 16^3 * 4B + 15 * 16^4 * 5B
     */

    int storageSize = 0;
    for ( int i = 0; i < 100000; ++i )
    {
        std::stringstream ss;
        ss << std::hex << i;

        storageSize += ss.str().length();
    }
    printf("Size of 100 000 strings: %d byte\n", storageSize);

    ////////// b) //////////

    printf( "\n////////// Task 10.1.b //////////\n\n");

    {
        // to speed things up, we use N = 100000
        int N = 100000;
        int K = 1000000;
        int K_list = 10000;

        std::shared_ptr<Vector> v( new Vector( N ) );
        std::shared_ptr<Map> m( new Map );
        std::shared_ptr<List> l( new List );
        std::shared_ptr<Array> a( new Array );

        printf( "Access times: \nFilling containers..." );

        fill_loop<decltype( insert_vector ), decltype( v )>( insert_vector, v, N );
        fill_loop<decltype( insert_map ), decltype( m )>( insert_map, m, N );
        fill_loop<decltype( insert_list ), decltype( l )>( insert_list, l, N );
        fill_loop<decltype( insert_array ), decltype( a )>( insert_array, a, N );

        printf( "Done\n" );

        printf( "Measuring now the access times for %d values:\n", N );
        double access;

        access = Measure::duration( access_loop<decltype( access_vector ), decltype( v )>, access_vector, v, K, N );
        printf( "Vector: %lfs - %.10lfs / access\n", access, access / K );

        access = Measure::duration( access_loop<decltype( access_map )   , decltype( m )>, access_map   , m, K, N );
        printf( "Map:    %lfs - %.10lfs / access\n", access, access / K );

        access = Measure::duration( access_loop<decltype( access_array ) , decltype( a )>, access_array , a, K, N );
        printf( "Array:  %lfs - %.10lfs / access\n", access, access / K );


        ////////// c) //////////

        printf( "\n////////// Task 10.1.c //////////\n\n");
        printf( "Measuring now the list access for %d values:\n", K_list );
        access = Measure::duration( access_loop<decltype( access_list ), decltype( l )>, access_list, l, K_list, N );
        printf( "List:   %lfs - %.10lfs / access\n", access, access / K_list );

        printf( "\nThe map takes longer then vector and array because it uses binary search, O(log(n))"
                        ", instead of random access.\n"
                "The list is even slower because it neither provides random access nor binary search "
                        "(we have to iterate through the list to find the right value).\n");
    }

    ////////// d) //////////

    printf( "\n////////// Task 10.1.d //////////\n\n");

    {
        std::ofstream file ( "access_times.dat", std::ios_base::out );

        if ( ! file.is_open() )
        {
            fprintf( stderr, "Could not open file!\n" );
            exit( 1 );
        }

        int N = 100000;

        printf( "Single access times:\n" );
        printf( "Filling containers..." );

        std::shared_ptr<Vector> v( new Vector( N ) );
        std::shared_ptr<Map> m( new Map );
        std::shared_ptr<List> l( new List );
        std::shared_ptr<Array> a( new Array );

        fill_loop<decltype( insert_vector ), decltype( v )>( insert_vector, v, N );
        fill_loop<decltype( insert_map ), decltype( m )>( insert_map, m, N );
        fill_loop<decltype( insert_list ), decltype( l )>( insert_list, l, N );
        fill_loop<decltype( insert_array ), decltype( a )>( insert_array, a, N );

        printf( "Done\n" );

        int K = 1000;

        printf( "Measuring access times for %d strings...", K );
        char c[100];
        snprintf( c, sizeof( c ), "# r\tVector\tMap\tList\tArray\n" );
        file << c;

        //srand( time( NULL ) );

        for ( int i = 0; i < K; ++i )
        {
            int r = i;
            snprintf( c, sizeof( c ), "%d\t%.10lf\t%.10lf\t%.10lf\t%.10lf\n"
                    , r
                    , Measure::duration( access_vector, v, r )
                    , Measure::duration( access_map   , m, r )
                    , Measure::duration( access_list  , l, r )
                    , Measure::duration( access_array , a, r ) );
            file << c;
        }

        printf( "Done\n" );

        /*
         * There is a gnuplot script to plot the data to a png. (We have included the png for our system as well.)
         * You can see the vector and array having constant access time, the map's access time is constant as well
         * but higher. As expected the times for the list are rising linearly.
         *
         * Main advantages/disadvantages:
         *
         * + all except the array are resizable
         *
         * Vector:
         * + fast access
         * - slow lookup
         * - slow insertion/deletion in the middle
         *
         * Map:
         * + fast lookup (if you don't use the key as an index like we did)
         * + fast insertion/deletion
         * - no random access
         *
         * List:
         * + fast insertion
         * - slow access/lookup
         *
         * Array:
         * + fast access
         * - not resizable
         * - slow lookup
         */

        file.close();
    }


    return 0;
}