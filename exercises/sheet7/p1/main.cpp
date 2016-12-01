#include <iostream>
#include <cstdio>
#include <typeinfo>

using namespace std;

void proofEquality();
template <typename T>
T sumOneToN(T n);
void printSumOneToN (float finalSum);
void printSumOneToN (double finalSum);
void printSumOneToN (long double finalSum);

int main() {
    cout<<"////task a ////"<<endl;
    int sixteen = 16;
    int hundret = 100;
    int threeee = 333;
    sumOneToN(float(sixteen));
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

    cout<<endl<<"////task b ////"<<endl;
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

template <typename T>
T sumOneToN(T n){
    T finalSum = 0;
    for (int i = 0; i < n; ++i) {
        finalSum += 1/n;
    }

    printSumOneToN(finalSum);

    //string outFormat;
    //cout<< typeid(finalSum).name()<<endl;

    /*
    if(typeid(finalSum) == typeid(float)){
        //cout << "type: float" << endl;
        //outFormat = "float: %f";
        //cout<<outFormat;
        printf("type: float: %f \n", finalSum);

    }
    else if (typeid(finalSum) == typeid(double)){
        //cout << "type: double" << endl;
        //outFormat = "double: %f";
        printf("type: double: %f \n", finalSum);
    }
    else if (typeid(finalSum) == typeid(long double)){
        //cout << "type: long double" << endl;
        //outFormat = "long double: %lf";
        printf("type: long double: %lf \n", finalSum);
    }
    //printf("type: %s", outFormat, finalSum);
    //cout << finalSum << endl;
     */
}

void printSumOneToN (float finalSum){
    printf("type: float: %f \n", finalSum);
}
void printSumOneToN (double finalSum){
    printf("type: double: %lf \n", finalSum);
}
void printSumOneToN (long double finalSum){
    printf("type: long double: %Lf \n", finalSum);
}

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
    cout<<endl<<"because of the datatype \"double\" for all variables we get inaccurate results"<<endl;
}
