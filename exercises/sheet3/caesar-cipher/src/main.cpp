/**
 * small application which implements a caesar-cipher and asks the user
 * to enter the to-be-shifted message and key
 *
 * To run the program, execute in root directory of the project:
 * cmake . && make && ./caesar_cipher
 * or
 * g++ --std=c++11 inc/* src/*
 *
 * IDEAS: while-loop to enter multiple messages,
 *        don't capitalize all characters
 */

#include <iostream>

#include "../inc/Cipher.h"

using namespace std;

int main()
{
    cout << "Welcome to Caesar-Cipher 1.0." << endl;
    cout << "Please enter your message:" << endl;

    string inputSentence;
    int key;

    getline( cin, inputSentence );

    cout << "Please enter the key:" << endl;

    cin >> key;

    Cipher c ( key );

    cout << "Your shifted message reads:" << endl;
    cout << c.shiftMessage( inputSentence ) << endl;

    return 0;
}