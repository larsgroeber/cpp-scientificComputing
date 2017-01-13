/**
 * this is the main function for our project "Roche Limit"
 * by Lars & Hendrik
 */
#include "include/Simulation.h"
using namespace LH;

int main ()
{
    printf( "Starting simulation...\n" );

    LH::Simulation S;

    S.run();

    printf( "\nBye\n" );

    return 0;
}

