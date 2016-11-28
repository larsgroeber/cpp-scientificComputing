#include <iostream>

using namespace std;

void proofEquality();

int main() {
    proofEquality();
    return 0;
}

/*
 Problem 1 (Truncation errors) 4 Pts
(a) Write a loop to sum over ... Repeat that
using the data types float, double and long double. Print the output
in a formatted way, considering the number of digits that are relevant
for variables of the respective data type.
*/

/*
 (b) Show that the following expressions are equivalent
 ((a + b) (a − b))^2
 (a 2 + b 2 )^2 − 4 (ab)^2
 (a 2 − b 2 )^2
We choose a = 10 8 + 2 and b = 10 8 − 1. Write a code to calculate the
above expressions, using data type double.Why does one of the results
diﬀer strongly?
 */
void proofEquality (){
    double a = 1000000002;
    double b = 999999999;

    double aMinusb = a-b;
    double aPlusb = a+b;
    double asPbs = a*a+(b*b);
    double asMbs =  a*a-(b*b);

    double f1 = (aPlusb*aMinusb) * (aPlusb*aMinusb);
    double f2 = asPbs*asPbs-(4*(a*b)*(a*b));
    double f3 = asMbs*asMbs;

    cout<<f1<<endl;
    cout<<f2<<endl;
    cout<<f3<<endl;
}