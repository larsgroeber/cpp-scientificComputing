/**
 * (this main.cpp file just shows how to use the class and can be deleted)
 */

#include <iostream>
#include "Planet.h"

std::string Planet::dataName[2] = { "test", "test2" };

int main ()
{
    Planet p ( "name\t1.2\t1.5", 2 );

    std::cout << p.myName << std::endl;
    std::cout << p.get_value( "test" ) << std::endl;

    p.print_data();
    return 0;
}