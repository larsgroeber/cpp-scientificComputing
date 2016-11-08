#include <iostream>

using namespace std;


int main ()
{
    int* intPtr;
    double* doublePtr;
    long double* ldoublePtr;

    int intArr[] = { 1,2,3,4 };
    double doubleArr[] = { 1.5, 2.5, 3.5, 4.5285547,5,5,5,5,5 };
    long double ldoubleArr[] = { 1.25, 2.25, 3.25, 4.3785675682356 };

    intPtr = intArr;
    doublePtr = doubleArr;
    ldoublePtr = ldoubleArr;

    cout << "intPtr = " << intPtr << ", *intPtr = " << *intPtr << endl;     
    cout << "doublePtr = " << doublePtr << ", *doublePtr = " << *doublePtr << endl;     
    // hier fehlt noch was
    
    cout << "intPtr++ = " << intPtr++ << ", *(intPtr++) = " << *(intPtr++) << endl;     
    cout << "doublePtr++ = " << doublePtr++ << ", *(doublePtr++) = " << *(doublePtr++) << endl;     
}
