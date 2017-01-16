#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <boost/shared_ptr.hpp>

const int SIZE_ARRAY = 100000000;

typedef std::vector<std::string> Vector;
typedef std::map<int,std::string> Map;
typedef std::list<std::string> List;
typedef std::array<std::string,SIZE_ARRAY> Array;

struct Measure
{
    template <typename F, typename... Args>
    static double duration ( F& func, Args&... args )
    {
        auto start = std::chrono::steady_clock::now();
        func( args... );
        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration<double>( end - start ).count();
    }
};

template <typename F, typename... Args>
void fill ( F& func, Args&... args, int N )
{
    for ( int i = 0; i < N; ++i )
    {
        std::stringstream ss;
        ss << std::hex << i;
        func ( args..., i, ss.str() );
    }
};

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
    (*array)[i];
}

int main ()
{
    std::vector<unsigned > limitsN { 100000, 1000000, 10000000, 100000000 };

    for ( auto&& n : limitsN )
    {
        std::shared_ptr<Vector> v ( new Vector ( n ) );
        std::shared_ptr<Map> m ( new Map );
        std::shared_ptr<List> l ( new List );
        std::shared_ptr<Array> a ( new Array );

        printf( "Measuring now for N = %d\n", n );
        printf( "Vector: %lf\n", Measure::duration( fill<decltype(insert_vector), decltype(v)>, insert_vector, v, n ) );
        printf( "Map:    %lf\n", Measure::duration( fill<decltype(insert_map), decltype(m)>, insert_map, m, n ) );
        printf( "List:   %lf\n", Measure::duration( fill<decltype(insert_list), decltype(l)>, insert_list, l, n ) );
        printf( "Array:  %lf\n", Measure::duration( fill<decltype(insert_array),decltype(a)>, insert_array, a, n ) );
    }

    return 0;
}