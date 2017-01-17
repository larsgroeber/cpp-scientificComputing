#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <memory>
#include <algorithm>
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
     * \brief Function to measure the time a function took to execute
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
 * \param N    Max Number
 */
template <typename F, typename... Args>
void my_fill ( F& func, Args& ... args, int N )
{
    for ( int i = 0; i < N; ++i )
    {
        std::stringstream ss;
        ss << std::hex << i;
        func ( args..., i, ss.str() );
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
template <typename F, typename... Args>
void lookup ( F& func, Args&... args, int K, int N )
{
    srand( time(NULL) );

    for ( int i = 0; i < K; ++i )
    {
        int r = rand() % N;
//        std::stringstream ss;
//        ss << std::hex << i;
        //printf( "%d\n", i );
        func( args..., r );
    }
};

std::string lookup_vector ( std::shared_ptr<Vector> v, int i )
{
    return (*v)[i];
}

std::string lookup_map ( std::shared_ptr<Map> m, int i )
{
    return m->find( i )->second;
}

std::string lookup_list ( std::shared_ptr<List> l, int i )
{
    auto it = l->begin();
    for ( int j = 0; j < i; ++j )
    {
        ++it;
    }
    return *it;
}

std::string lookup_array ( std::shared_ptr<Array> a, int i )
{
    return (*a)[i];
}


int main ()
{
    ////////// a) //////////
    std::cout << std::endl << "////////// Task 10.1.a //////////" << "\n\n";
    // the limits
    std::vector<unsigned> limitsN { 100000, 1000000, 10000000, 100000000 };

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
        printf( "Vector: %lf\n", Measure::duration( my_fill<decltype( insert_vector ), decltype( v )>, insert_vector, v, n ) );
        v.reset(); // deleting v here reduces memory usage
        printf( "Map:    %lf\n", Measure::duration( my_fill<decltype( insert_map ), decltype( m )>, insert_map, m, n ) );
        m.reset();
        printf( "List:   %lf\n", Measure::duration( my_fill<decltype( insert_list ), decltype( l )>, insert_list, l, n ) );
        m.reset();
        printf( "Array:  %lf\n", Measure::duration( my_fill<decltype( insert_array ), decltype( a )>, insert_array, a, n ) );
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
    printf("size of 100 000 strings: %d byte\n", storageSize);

    ////////// b) //////////
    std::cout << std::endl << "////////// Task 10.1.b //////////" << "\n\n";
    {
        // to speed things up, we use N = 100000
        int N = 100000;
        int K = 1000000;
        int K_list = 10000;
        std::shared_ptr<Vector> v( new Vector( N ) );
        std::shared_ptr<Map> m( new Map );
        std::shared_ptr<List> l( new List );
        std::shared_ptr<Array> a( new Array );

        printf( "Access times: filling containers...\n" );

        my_fill<decltype( insert_vector ), decltype( v )>( insert_vector, v, N );
        my_fill<decltype( insert_map ), decltype( m )>( insert_map, m, N );
        my_fill<decltype( insert_list ), decltype( l )>( insert_list, l, N );
        my_fill<decltype( insert_array ), decltype( a )>( insert_array, a, N );

        std::cout << ( *a )[1] << std::endl;

        printf( "Measuring now the access times for %d values:\n", N );
        printf( "Vector: %lfs\n", Measure::duration( lookup<decltype( lookup_vector ), decltype( v )>
                                                     , lookup_vector, v, K, N ) );
        printf( "Map:    %lfs\n", Measure::duration( lookup<decltype( lookup_map ), decltype( m )>
                                                     , lookup_map, m, K, N ) );
        printf( "Array:  %lfs\n", Measure::duration( lookup<decltype( lookup_array ), decltype( a )>
                                                     , lookup_array, a, K, N ) );


        ////////// c) //////////
        printf( "Measuring now a list with %d values:\n", K_list );
        printf( "List:   %lfs\n", Measure::duration( lookup<decltype( lookup_list ), decltype( l )>
                                                     , lookup_list, l, K_list, N ) );

        printf( "\nThe map takes longer then vector and array (and list)"
                "because it has a key and a value instead of just a value" );
    }

    ////////// d) //////////
    {
        std::ofstream file ( "access_times.dat" );

        //if (  )
    }


    return 0;
}