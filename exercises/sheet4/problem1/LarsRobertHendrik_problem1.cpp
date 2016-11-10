#include <iostream>

using namespace std;

int myfunc(int* firstIntPtr, int* secondIntPtr);

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
    cout << "integerPtr++ = " << integerPtr << ", *(integerPtr++) = " << *integerPtr << endl;
    cout << "double_Ptr++ = " << double_Ptr << ", *(double_Ptr++) = " << *double_Ptr << endl;
    cout << "ldoublePtr++ = " << ldoublePtr << ", *(ldoublePtr++) = " << *ldoublePtr << endl;

    cout<< endl<<endl<<"calling function from 1b:"<<endl;
    cout << myfunc(xPtr, yPtr);


}

//problem 1b
// multiplying two integers by using their pointers
int myfunc(int* firstIntPtr, int* secondIntPtr){
    return *firstIntPtr * *secondIntPtr;
}
