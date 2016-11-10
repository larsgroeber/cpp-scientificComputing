#include <iostream>

using namespace std;

int myfunc(int* firstIntPtr, int* secondIntPtr);
int myfunc(int& a, int& b);

double scalarProduct(double* arr1, double* arr2);
void outerProduct(double* arr1, double* arr2, double* result);

int main ()
{
    //problem 1a
    // pointer for 3 different data types that should  point to arrays
    int*            integerPtr;
    double*         double_Ptr;
    long double*    ldoublePtr;

    //those are the corresponding arrays (see above)
    int intArr[] = { 1,2,3,4 };
    double doubleArr[] = { 1.5, 2.5, 3.5, 4.5285547,5,5,5,5,5 };
    long double ldoubleArr[] = { 1.25, 2.25, 3.25, 4.3785675682356 };

    //variabes needed for 1b
    int x = 7;
    int y = 3;
    int* xPtr = &x;
    int* yPtr = &y;

    //assigning the arrays to the pointers
    integerPtr = intArr;
    double_Ptr = doubleArr;
    ldoublePtr = ldoubleArr;

    //printing the addresses and the values the pointer are pointing at
    cout << "addresses and the values the pointer are pointing at" << endl<<endl;
    cout << "integerPtr = " << integerPtr << ", *integerPtr = " << *integerPtr << endl;
    cout << "double_Ptr = " << double_Ptr << ", *double_Ptr = " << *double_Ptr << endl;
    cout << "ldoublePtr = " << ldoublePtr << ", *ldoublePtr = " << *ldoublePtr << endl;

    //incrementing the pointer and printing out the same as above
    integerPtr++;
    double_Ptr++;
    ldoublePtr++;
    cout<<endl<<endl<<"incrementing the pointer gives following result:"<<endl<<endl;
    cout << "integerPtr = " << integerPtr << ", *integerPtr = " << *integerPtr << endl;
    cout << "double_Ptr = " << double_Ptr << ", *double_Ptr = " << *double_Ptr << endl;
    cout << "ldoublePtr = " << ldoublePtr << ", *ldoublePtr = " << *ldoublePtr << endl;

    // output of problem 1b
    cout<< endl<<endl<<"calling function from 1b with references and x=7, y=3:"<<endl;
    cout << myfunc(x, y) << endl;
    cout<< "calling function from 1b with pointers:"<<endl;
    cout << myfunc(xPtr, yPtr) << endl;

    // output of problem 1c
    cout << "\n\n" << "scalar product of (1,2,3) and (4,5,6)" << endl;
    double arr1[] = { 1, 2, 3 };
    double arr2[] = { 4, 5, 6 };
    // arr1 and arr2 are pointers pointing to the arrays
    cout << scalarProduct(arr1,arr2) << endl;

    // output for problem 1d
    cout << "\n\n" << "outer product of (1,2,3) and (4,5,6)" << endl;
    double result[3];
    outerProduct(arr1,arr2,result);
    cout << "(" << result[0] << "," << result[1] << "," << result[2] << ")" << endl; 
}

//// problem 1b ////
// multiplying two integers by using their references
int myfunc(int& a, int& b){
    return a * b;
}

// multiplying two integers by using their pointers
int myfunc(int* a, int* b){
    return *a * *b;
}

//// problem 1c ////
// consider only 3-dim vectors
double scalarProduct(double* arr1, double* arr2){
    double result = 0;
    for (int i=0; i < 3; ++i){
        result += arr1[i] * arr2[i];
    }
    return result;
}

//// problem 1d ////
void outerProduct(double* arr1, double* arr2, double* result){
    for (int i=0; i < 3; ++i){
        result[i] += arr1[(i+1)%3] * arr2[(i+2)%3] - arr1[(i+2)%3] * arr2[(i+1)%3];
    }
}
