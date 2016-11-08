#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int m = 5;                        // rows
const int n = 10;                       // columns
const int multFac = 2;                  // factor to multiply the matrix with
int arr[m][n];
int arr2[];

void fillArr (int arr[][n]);
void multArr (int arr[][n]);
void showArr (int arr[][n]);
void printArray(int arr2[], int len);

int main() {
    fillArr(arr);
    cout << endl << "m x n Matrix" << endl << endl;
    showArr(arr);
    multArr(arr);
    cout << endl << "m x n Matrix multiplied by " << multFac << endl << endl;
    showArr(arr);
    return 0;
}


void fillArr (int arr[][n]){
    for (int i = 0; i < m; ++i) {      //sizeof(arr)/sizeof(arr[0][3])
        for (int j = 0; j < n; ++j) {
            arr[i][j] = rand()%10;
        }
    }
}

void multArr(int arr[m][n]) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr [i][j] = arr [i][j] * multFac;
        }
    }
};

void showArr(int arr[m][n]) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("|%2d" , arr [i][j]);
        }
        cout << "|" << endl;
    }
}


// Additionally write a function void printArray(int arr[], int len) that takes a one-dimensional array and its length.
// Then call the function giving one row of the previously deﬁned matrix as an argument.
void printArray(int arr2[], int len) {
    cout << "row from matrix" << endl;
    
}