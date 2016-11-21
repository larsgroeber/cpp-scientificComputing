#include <iostream>

using namespace std;

double calcFac (double n);

double facIn;

int main() {
    // a
    cout<<"//// task a ////"<<endl;
    cout<<"please input a number to calculate the factorial of:"<<endl;
    cin>>facIn;
    cout<<calcFac(facIn);
    return 0;

    //b ???

}

// factorial calculator (recursive) (copied from sheet 5 problem 1)
double calcFac (double n){
    if (n == 1 || n == 0)
        return 1;
    return n*calcFac(n-1);
}