#include <iostream>

using namespace std;

double calcFac (double n);

int facIn;
int facInMain;
double facProdMain;
const int arrLength = 1000;
int arrCounter = 0;
double facProdArr[arrLength];
double dinnerIsServed = 1;
bool skipTaskA = true;
bool firstCall = true;
bool lastCall = false;

int main() {
    if(skipTaskA) {
        // a
        cout << "//// task a ////" << endl;
        cout << "please input a number to calculate the factorial of:" << endl;
        cin >> facIn;
        cout << calcFac(facIn)<<endl<<endl;
        skipTaskA = false;
    }

    /*
    (b) Now write the same code by recursively calling the main function. (4 Pts)
    Disclaimer: Mind that recursively calling the main function is declared
    illegal in the C++11 documentation §3.6.1/3. We request this here for
    academic purpose only.
    */
    //b ???

    if(firstCall) {
        cout << "//// task b ////" << endl;
        cout << "please input a number to calculate the factorial of:" << endl;
        cin >> facInMain;
        firstCall=false;
    }
    if (facInMain == 1 || facInMain == 0) {
        facProdArr[arrCounter] = facInMain;
        //lastCall = true;
        return 1;
    }
    else {
        cout<<endl;
        cout<<"result in exit code";
        return facInMain-- * main();
    }
}

/*
 (a) Write a programm that calculates the factorial of a given number recur-
sively, i. e. by involving function that calls itself. (3 Pts)
 */
// factorial calculator (recursive) (copied from sheet 5 problem 1)
double calcFac (double n){
    if (n == 1 || n == 0)
        return 1;
    return n*calcFac(n-1);
}

