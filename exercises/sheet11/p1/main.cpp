#include <iostream>
#include <random>
#include <map>
#include <fstream>

/**
 * \brief Implements a gaussian and exponential random generator.
 */
class Random
{
public:
    Random ()
    {
        std::random_device rd;
        _gen.seed( rd() );
    }

    double gaussian ()
    {
        return _gaussian( _gen );
    }

    double exponential ()
    {
        return _exponential( _gen );
    }

    void init_gaussian ( double mu, double sig )
    {
        _gaussian = std::normal_distribution<> ( mu, sig );
    }

    void init_exponential ( double lambda )
    {
        _exponential = std::exponential_distribution<> ( lambda );
    }

private:
    /** A mersenne twister engine generator */
    std::mt19937 _gen;
    std::normal_distribution<> _gaussian;
    std::exponential_distribution<> _exponential;
};

int main ()
{
    /////// a) ///////
    // setup generators
    Random r;
    r.init_exponential( 1.5 );
    r.init_gaussian( 6., 0.5 );

    /////// b) ///////
    int N = 10000;
    int av_per_bin = 200;
    int bin_num = N / av_per_bin;
    double x_min = 0;
    double x_max = 10;
    double bin_size = (x_max - x_min) / bin_num;

    std::map<int,int> hist_gauss;   // (bin number | bin count)
    std::map<int,int> hist_exp;

    std::cout << "Generating " << N << " random numbers...";

    // generate random numbers
    for ( int i = 0; i < N; ++i )
    {
        double gauss = r.gaussian();
        ++hist_gauss[static_cast<int>(gauss / bin_size)];   // only create index if necessary

        double exp = r.exponential();
        ++hist_exp[static_cast<int>(exp / bin_size)];
    }

    std::cout << "Done" << std::endl;

    // write data to file
    std::ofstream file ( "hist.dat", std::ios_base::out );

    if ( ! file.is_open() )
    {
        std::cerr << "Could not open file!" << std::endl;
        return 1;
    }

    file << "# bin\tgauss_counts\tgauss_mean\texp_counts\texp_mean" << std::endl;

    for ( int j = 0; j < bin_num; ++j )
    {
        file << j << "\t" << hist_gauss[j] << "\t" << hist_gauss[j] / bin_num << "\t" << hist_exp[j] << "\t" << hist_exp[j] / bin_num << std::endl;
    }

    std::cout << "Done writing histogram to file." << std::endl;

    file.close();
}