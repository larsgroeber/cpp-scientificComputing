#include <iostream>
#include <cstdio>
using namespace std;

int intArr[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int arrSize = 21;//sizeof(intArr)/ sizeof(*intArr);//sizeof(intArr) / sizeof(intArr[0]);

void replacEverySecondElementInAnArrayByZero(int a[]);
void printArray(int a[]);

int main() {
    //a
    cout<<"task a";
    for (int i = 1; i < arrSize; ++i) {
        printf("|%2d" , intArr[i]);
    }
    replacEverySecondElementInAnArrayByZero(intArr);
    //printArray(intArr);
    for (int i = 1; i < arrSize; ++i) {
        printf("|%2d" , intArr[i]);
    }
    return 0;
}

// (a) Write a program that replaces every second element of an array by zero,
// using a for loop and iterating with step size two.
void replacEverySecondElementInAnArrayByZero (int intArr[]) {
    for (int i = 1; i < arrSize; ++i) {
        intArr[i] = 0;
    }
}

void printArray(int array[]){
    for (int i = 0; i < arrSize; ++i) {       // rows
            printf("|%2d" , array[i]);// printing out every element as a two digit number
    }
    cout<<"|";
}

// (b) Write a program that prints out all odd numbers smaller than 20 by
// using a loop and the continue statements.

//(c) Write a program that calculates the largest factorial smaller than a given
//upper limit. Therefore use a loop and the break statement to exit, when
//the next number is larger than the limit.

//(d) Binomial coeﬃcient
//Write a program that computes the binomial coeﬃcient  (n k)
//where n and k are speciﬁed by the user.

//(e) Password prompt
//Write a program that asks the user to enter a password. The user may
//only enter the password a speciﬁed number of times. The program should
//check the password every time and exit if the correct password was given
//or the maximal limit is reached.

//(f) The guessing game
//Write program that randomly generates a number between 1 and 100 and
//the user has to guess this number. If the user guesses too high/low the
//program outputs ”too high/low” until the user hits the correct number.