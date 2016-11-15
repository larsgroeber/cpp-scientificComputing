/*************************************************
*	Comments by Bulcsu Sandor: "// BS: "
*	Points: 6/6
*************************************************/

/**
 * a program to create n x m matrices with random numbers and to multiply them by a factor
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int m = 5;                        // rows
const int n = 20;                       // columns
//const int o = 10;                       // length of arr2
const int p = 0;                        // used for 2b; nuber of row used
const int multFac = 2;                  // factor to multiply the matrix with
int arr[m][n];                          // first array
//int arr2[o];                          // second array

void fillArr (int arr[][n]);            // calling all the used methods...
void multArr (int arr[][n]);
void showArr (int arr[][n]);
void printArray(int arr2[], int len);

int main() {
    fillArr(arr);
    cout << endl << m<<" x "<<n<<" Matrix" << endl << endl;
    showArr(arr);
    multArr(arr);
    cout << endl << m<<" x "<<n<<" Matrix multiplied by " << multFac << endl << endl;
    showArr(arr);

// Aufgabe 2 b
    cout << endl << endl<< "problem 2b"<<endl;
    printArray(arr[p], sizeof(arr[p])/ sizeof(*arr[p]));

    return 0;
}

// filling the array with random values between 0 and 9
void fillArr (int arr[][n]){
    for (int i = 0; i < m; ++i) {       // rows //sizeof(arr)/sizeof(arr[0][3])
        for (int j = 0; j < n; ++j) {   // columns
            arr[i][j] = rand()%10;      // assigning each element a number between 0 and 9
        }
    }
    // BS: ok!
}

// multiplying the array by multFac
void multArr(int arr[m][n]) {
    for (int i = 0; i < m; ++i) {       // rows
        for (int j = 0; j < n; ++j) {   // columns
            arr [i][j] *= multFac;      // multiplying each element by multFac
        }
    }
    // BS: ok!
};

// printing the array human readable
void showArr(int arr[m][n]) {
    for (int i = 0; i < m; ++i) {       // rows
        for (int j = 0; j < n; ++j) {   // columns
            printf("|%2d" , arr [i][j]);// printing out every element as a two digit number
        }
        cout << "|" << endl;
    }
    // BS: nice!
}



// Aufgabe 2 b

// Additionally write a function void printArray(int arr[], int len) that takes a one-dimensional array and its length.
// Then call the function giving one row of the previously deﬁned matrix as an argument.
void printArray(int arr2[], int len) {
    cout<<"len: "<<len<<endl;
    for (int i = 0; i < len; ++i) {
        //cout<<"|"<<arr2[i];
        printf("|%2d" , arr2[i]);
    }
    cout<<"|"<<endl;
}
