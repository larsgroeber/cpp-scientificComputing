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
T templateProduct (T a, T b)
{
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
void tArrPrint (T (&array)[N]) {            //prints array from type T
    for (int i = 0; i < N; ++i) {
        cout<<"|"<< array[i];               //prints out the values of array
    }
    cout<<"|"<<endl<<"size of the array: "<<N<<endl;
}

/*
 (c) Re-write the function such that you can pass a two dimensional n × m
array. (3 Pts)
 */
template<typename T, int N, int M>
void tArrPrint2d (T (&array)[N][M]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << "|" << array[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<"size of the array: "<<N<<"x"<<M<<endl;
}

double aIn;
double bIn;

int main() {
    //a
    cout << "Please enter two numbers" << endl;
    cin>>aIn>>bIn;
    //cout<< typeid(aIn).name() <<" : "<<aIn<<" | "<< typeid(bIn).name()<<" : "<<bIn;
    cout<< aIn<<" | "<<bIn<<endl;
    cout<<templateProduct(aIn, bIn)<<endl;

    //b
    double arrD[3] = {1.5, 2.5, 3.5};
    int arrI[3] = {1,2,3};
    cout << "tArrPrint with double array:" << endl;
    tArrPrint(arrD);
    cout << "tArrPrint with int array:" << endl;
    tArrPrint(arrI);
    cout<<endl;

    //c
    double arrDouble2d[2][3] = {{1.5,2.5,3.5},{4.5,5.5,6.5}};
    int arrInt2d[2][3] = {{1,2,3},{4,5,6}};
    /*
    cout<<arrInt2d[0][0]<<endl;
    cout<<arrInt2d[0][1]<<endl;
    cout<<arrInt2d[0][2]<<endl;
    cout<<endl;
    cout<<arrInt2d[1][0]<<endl;
    cout<<arrInt2d[1][1]<<endl;
    cout<<arrInt2d[1][2]<<endl;
    cout<<endl;
    */

    cout << "tArrPrint2d with double array:" << endl;
    tArrPrint2d(arrDouble2d);
    cout << "tArrPrint2d with int array:" << endl;
    tArrPrint2d(arrInt2d);
    cout<<endl;

    return 0;
}