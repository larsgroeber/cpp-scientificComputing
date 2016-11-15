#include <iostream>
#include <cstdio>
using namespace std;

const int arrSize = 21;//sizeof(intArr)/ sizeof(*intArr);//sizeof(intArr) / sizeof(intArr[0]);
int intArr[arrSize] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,27,18,19,20};
int facInput;
int binomVarN;
int binomVarK;
int doLoop =1;

void replacEverySecondElementInAnArrayByZero(int a[]);
void printArray(int a[]);
void printOddNumSmallerThanTwenty (int array[], int len);
void calcLargestFacWithUperLimit (int lim);
int calcBinomialcoefficient(int n, int k);
int calcFac (int n);

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
    cout<<endl<<endl<<"task c"<<endl<<"please enter a number bigger then zero:"<<endl;

    cin>>facInput;
    calcLargestFacWithUperLimit (facInput);

    // d
    cout<<endl<<"task d"<<endl;
    for (int i = 1; i < 6; ++i) { cout<<calcFac(i)<<endl; } //calcFac test
    while (doLoop == 1) {                       //repeats the method as long as you enter 1 and exits the loop when you enter 2
        cout<<"please enter n and k (seperated by a space)"<<endl;
        cin >> binomVarN >> binomVarK;          //explanation on line above in cout
        cout<<calcBinomialcoefficient(binomVarN, binomVarK)<<endl;
        cout<<"enter ""1"" for retry or ""2"" for abort:"<<endl;
        cin >> doLoop;
    }
//    for (int j = 4; j < 8; ++j) { cout<<calcBinomialcoefficient(j, 2)<<endl;    } //for testing
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
        cout<<"please enter a number BIGGER than zero"<<endl;
    }
    else {
        int facProd = 1;
        int facProd2 = 1;                   //saves the previous factorial for output
        int facVar;
        for (int i = 1; i < lim; ++i) {     //loop to calc factorial
            facProd *= i;
            if (facProd >= lim) {
                break;
            }
            facProd2 *= i;                  // used for output
            facVar = i;                     // used for output
        }
        cout << "the biggest factorial smaller than   " << lim << " :  " << facVar << "! = " << facProd2;
    }
}

//(d) Binomial coeﬃcient
//Write a program that computes the binomial coeﬃcient  (n k)
//where n and k are speciﬁed by the user.
// (n k) = n!/k!*(n-k)!
int calcBinomialcoefficient(int n, int k){
//    cout<<"n: "<<calcFac(n)<<endl<<"k: "<<calcFac(k)<<endl<<"n-k: "<<calcFac((n-k))<<endl; // for testing prints the 3 factorials
    return calcFac(n)/(calcFac(k)*calcFac((n-k)));  //binomial coefficient
}

// factorial calculator (recursive) used for calcBinomialcoefficient
int calcFac (int n){
    if (n == 1 || n == 0)
    return 1;
    return n*calcFac(n-1);
}


//(e) Password prompt
//Write a program that asks the user to enter a password. The user may
//only enter the password a speciﬁed number of times. The program should
//check the password every time and exit if the correct password was given
//or the maximal limit is reached.


//(f) The guessing game
//Write program that randomly generates a number between 1 and 100 and
//the user has to guess this number. If the user guesses too high/low the
//program outputs ”too high/low” until the user hits the correct number.