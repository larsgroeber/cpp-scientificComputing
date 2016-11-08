/**
 * small application which implements a caesar-cipher and asks the user
 * to enter the to-be-shifted message and key
 *
 * To run the program, execute in build directory of the project:
 * cmake .. && make && ./caesar_cipher
 * or in root directory
 * g++ --std=c++11 inc/* src/*
 */

/*************************************************
*	Comments by Bulcsu Sandor: "// BS: "
*	Points: 6/6
*************************************************/

// BS: nicely readable code
// BS: would be useful to print that negative key 
//     is also accepted

#include <iostream>

#include "../inc/Cipher.h"

using namespace std;

int main()
{
    cout << "Welcome to Caesar-Cipher 1.1" << endl;
    cout << "Please enter your message:" << endl;

    string inputSentence;
    int key;

    // get input
    getline( cin, inputSentence );

    cout << "Please enter the key:" << endl;

    cin >> key;

    // check if user entered an integer
    if ( ! cin )
    {
        cerr << "Please enter a number!" << endl;
        return 1;
    }

    // instantiate Cipher
    // BS: well, a method would be simpler :p
    Cipher c ( key );

    cout << "Your shifted message reads:" << endl;
    cout << c.shiftMessage( inputSentence ) << endl;

    return 0;
}
