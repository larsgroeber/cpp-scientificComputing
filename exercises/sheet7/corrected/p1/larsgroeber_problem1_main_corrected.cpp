/*************************************************
*	Comments by Bulcsu Sandor: "// BS: "
*	Points: 4/4
*************************************************/

#include <iostream>
#include <cstdio>
#include <limits>
#include <math.h>

using namespace std;

void proofEquality();

template <typename T>
T sumOneToN(T n);

void printSumOneToN (float finalSum);
void printSumOneToN (double finalSum);
void printSumOneToN (long double finalSum);

int main() {
    cout << "Non-sign bits in float: " << numeric_limits<float>::digits << '\n';
    cout << "Non-sign bits in double: " << numeric_limits<double>::digits << '\n';
    cout << "Non-sign bits in long double: " << numeric_limits<long double>::digits << endl<<endl;

    cout<<"////task a ////"<<endl;      //shows how unaccurate it is calculating with float, double, long double
    int sixteen = 16;
    int hundret = 100;
    int threeee = 333;
    sumOneToN(float(sixteen));          //casting int so we dont have to create 9 variables but just 3

    // BS: very good point!

    sumOneToN(float(hundret));
    sumOneToN(float(threeee));
    cout<<endl;
    sumOneToN(double(sixteen));
    sumOneToN(double(hundret));
    sumOneToN(double(threeee));
    cout<<endl;
    sumOneToN((long double)sixteen);
    sumOneToN((long double)hundret);
    sumOneToN((long double)threeee);

    cout<<endl<<"////task b ////"<<endl;    //also shows us that we can get false results when calculating
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

// BS: good!
template <typename T>                                   //template for being able to use float, double and long double in one method
T sumOneToN(T n){
    T finalSum = 0;                                     //initializing finalSum!!
    for (int i = 0; i < n; ++i) {
        finalSum += 1/n;
    }

    printSumOneToN(finalSum);                           //calls the print function (thats specific for each datatype)
}
                                                        //print functions for different datatypes
void printSumOneToN (float finalSum){
    printf("type: float: %.24f \n", finalSum);          //printf with data formatting instructions (compare to line 16-18)
}
void printSumOneToN (double finalSum){
    printf("type: double: %.53lf \n", finalSum);
}
void printSumOneToN (long double finalSum){
    printf("type: long double: %.64Lf \n", finalSum);
}
// BS: ok!

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
    //
    // BS: you have 10^9+2 and 10^9-1
    // BS: not the same as:
    //
    //double a = pow(10.,8.)+2.;
    //double b = pow(10.,8.)-1.;

    printf("a = %lf\n", a);
    printf("b = %lf\n",b);
                                            //small functions to make f1-f3 more clear
    double aMinusb = a-b;
    double aPlusb = a+b;
    double asPbs = a*a+(b*b);
    double asMbs =  a*a-(b*b);
                                            //the acutal calculations
    double f1 = (aPlusb*aMinusb) * (aPlusb*aMinusb);
    double f2 = asPbs*asPbs-(4*(a*b)*(a*b));
    double f3 = asMbs*asMbs;

    // BS: note you get slightly different result 
    // BS: without setting the precision/type for printing
    printf("%lf\n",f1);
    printf("%lf\n",f2);
    printf("%lf\n",f3);

    cout<<f1<<endl;
    cout<<f2<<endl;
    cout<<f3<<endl;
    cout<<endl<<"because of the datatype \"double\" for all variables we get inaccurate results"<<endl;
}
