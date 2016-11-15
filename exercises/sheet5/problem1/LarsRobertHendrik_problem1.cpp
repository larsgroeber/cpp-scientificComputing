#include <iostream>
#include <cstdio>
using namespace std;

const int arrSize = 21;//sizeof(intArr)/ sizeof(*intArr);//sizeof(intArr) / sizeof(intArr[0]);
int intArr[arrSize] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,27,18,19,20};
//int facVar = 1;
int facInput;

void replacEverySecondElementInAnArrayByZero(int a[]);
void printArray(int a[]);
void printOddNumSmallerThanTwenty (int array[], int len);
void calcLargestFacWithUperLimit (int lim);

int main() {
    //a
    cout<<"task a (the 1st line shows the original array used before running the method)"<<endl;
    printArray(intArr);
    cout<<endl;
    replacEverySecondElementInAnArrayByZero(intArr);
    printArray(intArr);

    //b
    cout<<endl<<endl<<"task b (the 1st line shows the original array used before running the method)"<<endl;
    int intArr[arrSize] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,25,26,27,28,29,30};
    printArray(intArr);
    cout<<endl;
    printOddNumSmallerThanTwenty(intArr, arrSize);

    //c
    cout<<endl<<endl<<"task c"<<endl<<"please enter a number bigger then zero:";
    calcLargestFacWithUperLimit(2);
    calcLargestFacWithUperLimit(6);
    calcLargestFacWithUperLimit(15);
    calcLargestFacWithUperLimit(55);
    calcLargestFacWithUperLimit(200);
    cin>>facInput;
    calcLargestFacWithUperLimit (facInput);

    return 0;
}

// (a) Write a program that replaces every second element of an array by zero,
// using a for loop and iterating with step size two.
void replacEverySecondElementInAnArrayByZero (int intArr[]) {
    for (int i = 1; i < arrSize; i=i+2) {               //incerementing by 2
        intArr[i] = 0;
    }
}

//copied from exercise 4.2
void printArray(int array[]){
    for (int i = 0; i < arrSize; ++i) {         // rows
        printf("|%2d" , array[i]);              // printing out every element as a two digit number
    }
    cout<<"|";
}

// (b) Write a program that prints out all odd numbers smaller than 20 by
// using a loop and the continue statements.
void printOddNumSmallerThanTwenty (int array[], int len){
    for (int i = 0; i < len; ++i) {
        if (array[i]%2 != 0 && array[i] < 20)  {            //
            printf("|%2d", array[i]);
            continue;                                       //resume the for loop
        }
    }
    cout<<"|";
}

//(c) Write a program that calculates the largest factorial smaller than a given
//upper limit. Therefore use a loop and the break statement to exit, when
//the next number is larger than the limit.
void calcLargestFacWithUperLimit (int lim){
    if (lim < 1){
        cout<<"please enter a number BIGGER than zero";
    }
    int facVar;
    for (int i = 1; i < lim; ++i) {
        facVar *= i;
        if (facVar >= lim)
            break;
    }
    cout<<"this is the biggest factorial smaller than the given limit:"<<endl<<facVar;
}

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