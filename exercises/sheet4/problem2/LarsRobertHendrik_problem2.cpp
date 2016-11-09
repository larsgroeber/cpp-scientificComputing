/**
 * a program to create n x m matrices with random numbers and to multiply them by a factor
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int m = 5;                        // rows
const int n = 10;                       // columns
const int o = 10;                       // length of arr2
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
    cout << endl << "strange second part of this problem..." << multFac << endl << endl;

// Aufgabe 2 b
    printArray(arr [0], sizeof(arr)/ sizeof(*arr));//arr.length());
//    return 0;
}

// filling the array with random values between 0 and 9
void fillArr (int arr[][n]){
    for (int i = 0; i < m; ++i) {       // rows //sizeof(arr)/sizeof(arr[0][3])
        for (int j = 0; j < n; ++j) {   // columns
            arr[i][j] = rand()%10;      // assigning each element a number between 0 and 9
        }
    }
}

// multiplying the array by multFac
void multArr(int arr[m][n]) {
    for (int i = 0; i < m; ++i) {       // rows
        for (int j = 0; j < n; ++j) {   // columns
            arr [i][j] *= multFac;      // multiplying each element by multFac
        }
    }
};

// printing the array human readable
void showArr(int arr[m][n]) {
    for (int i = 0; i < m; ++i) {       // rows
        for (int j = 0; j < n; ++j) {   // columns
            printf("|%2d" , arr [i][j]);// printing out every element as a two digit number
        }
        cout << "|" << endl;
    }
}



// Aufgabe 2 b

// Additionally write a function void printArray(int arr[], int len) that takes a one-dimensional array and its length.
// Then call the function giving one row of the previously deﬁned matrix as an argument.
void printArray(int arr2[], int len) {

}