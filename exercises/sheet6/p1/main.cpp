#include <iostream>
#include <typeinfo>     //used for typeid

using namespace std;

//T templateProduct (T a, T b);
//void tArrPrint (T (&array)[N]);
//void tArrPrint2d (T (&array)[N][M]);


/*
Problem 1 (Template functions) 7 Pts
For the following tasks, implement the requested functions and call them in
the main function.
 */

/*
 (a) Implement a function with a template type for the arguments and the
return value, which takes two numbers of the same template type (e. g.
int, double) and returns the product, which is of the same type. (2 Pts)
 */

template <typename T>
T templateProduct (T a, T b){
    return a*b;
}

/*
 (b) Extend the function so that it additionally has a templated integer pa-
rameter and takes an array of template type T and length N as argument.
The function shall print all entries of the array and the size of the array.
Hint: The function then looks like
template<typename T, int N> func name (T (&array)[N]) {...}. (2 Pts)
 */

template<typename T, int N>
void tArrPrint (T (&array)[N]) {
    for (int i = 0; i < N; ++i) {
        cout<<"|"<<&array[i];
    }
    cout<<"|"<<endl<<"size of the array: "<<N<<endl;
}

/*
 (c) Re-write the function such that you can pass a two dimensional n × m
array. (3 Pts)
 */
template<typename T, int N, int M>
void tArrPrint2d (T (&array)[N][M]) {
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            cout << "|" << &array[i][j];
        }
        cout<<endl;
    }
    cout<<"|"<<endl<<"size of the array: "<<N<<endl;
}

double aIn;
double bIn;

int main() {
    cin>>aIn>>bIn;
    //cout<< typeid(aIn).name() <<" : "<<aIn<<" | "<< typeid(bIn).name()<<" : "<<bIn;
    cout<< aIn<<" | "<<bIn;
    //templateProduct();
    return 0;
}