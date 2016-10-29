#include <iostream>

#include "../inc/Cipher.h"

using namespace std;

int main()
{
    cout << "Welcome to Caesar-Cipher 0.2" << endl;
    cout << "Please enter a sentence." << endl;

    string inputSentence;
    int k;

    getline( cin, inputSentence );

    cout << "Please enter the key." << endl;

    cin >> k;

    Cipher c ( k );

    cout << "Your shifted message reads:" << endl;
    cout << c.shiftMessage( inputSentence ) << endl;
}