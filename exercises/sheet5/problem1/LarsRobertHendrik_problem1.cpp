#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int arrSize = 21;//sizeof(intArr)/ sizeof(*intArr);//sizeof(intArr) / sizeof(intArr[0]);
int intArr[arrSize] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,27,18,19,20};
int facInput;
double binomVarN;
double binomVarK;
int doLoop =1;
int passwordLength;
//char* passwordInput;

void replacEverySecondElementInAnArrayByZero(int a[]);
void printArray(int a[]);
void printOddNumSmallerThanTwenty (int array[], int len);
void calcLargestFacWithUperLimit (double lim);
double calcBinomialcoefficient(double n, double k);
double calcFac (double n);
void pwCheck(int passXtimes, int pwLength);//, char passIn);
void guessNrBetweenOneAndOneHundredButThisNameStillIsntLongEnough();

int main() {
    //a
    cout<<" ////task a //// (the 1st line shows the original array used before running the method)"<<endl;
    printArray(intArr);
    cout<<endl;
    replacEverySecondElementInAnArrayByZero(intArr);
    printArray(intArr);

    //b
    cout<<endl<<endl<<"//// task b //// (the 1st line shows the original array used before running the method)"<<endl;
    int intArr[arrSize] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,25,26,27,28,29,30};
    printArray(intArr);
    cout<<endl;
    printOddNumSmallerThanTwenty(intArr, arrSize);

    //c
    cout<<endl<<endl<<"//// task c ////"<<endl<<"please enter a number bigger then zero:"<<endl;

    cin>>facInput;
    calcLargestFacWithUperLimit (facInput);

    // d
    cout<<endl<<endl<<"//// task d ////"<<endl;
    //for (int i = 1; i < 6; ++i) { cout<<calcFac(i)<<endl; } //calcFac test
    while (doLoop == 1) {                       //repeats the method as long as you enter 1 and exits the loop when you enter 2
        cout<<"please enter n and k (seperated by a space)"<<endl;
        cin >> binomVarN >> binomVarK;          //explanation on line above in cout
        if (binomVarN<binomVarK){
            cout<<"please choose an n bigger than k. try again:"<<endl;
            continue;
        }
        cout<<calcBinomialcoefficient(binomVarN, binomVarK)<<endl;
        cout<<"enter ""1"" for retry or ""2"" for abort:"<<endl;
        cin >> doLoop;
    }
//    for (int j = 4; j < 8; ++j) { cout<<calcBinomialcoefficient(j, 2)<<endl;    } //for testing

    //e
    cout<<"//// task e ////"<<endl;
    cout << "please enter your maximum passwordlength (as integer):" << endl;
    cin >> passwordLength;
    pwCheck(5, passwordLength);//) *passwordInput);
    cout<<endl<<endl<<endl;

    //f
    cout<<"//// task f ////"<<endl;
    guessNrBetweenOneAndOneHundredButThisNameStillIsntLongEnough();
    cout<<endl;


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
void calcLargestFacWithUperLimit (double lim){
    if (lim < 1){
        cout<<"please enter a number BIGGER than zero:"<<endl;
        int youWannaSeeTheWorldBurnDontYou;
        cin>>youWannaSeeTheWorldBurnDontYou;
        calcLargestFacWithUperLimit(youWannaSeeTheWorldBurnDontYou);
    }
    else {
        double facProd = 1;
        double facProd2 = 1;                   //saves the previous factorial for output
        double facVar = 0;
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
double calcBinomialcoefficient(double n, double k){
//    cout<<"n: "<<calcFac(n)<<endl<<"k: "<<calcFac(k)<<endl<<"n-k: "<<calcFac((n-k))<<endl; // for testing prints the 3 factorials
    return calcFac(n)/(calcFac(k)*calcFac((n-k)));  //binomial coefficient
}

// factorial calculator (recursive) used for calcBinomialcoefficient
double calcFac (double n){
    if (n == 1 || n == 0)
    return 1;
    return n*calcFac(n-1);
}


//(e) Password prompt
// Write a program that asks the user to enter a password. The user may only enter the password
// a speciﬁed number of times. The program should check the password every time and exit if the
// correct password was given or the maximal limit is reached.
void pwCheck(int passXtimes, int pwLength){//, char passIn){
    //char passConfirm;
    int passXcounter = 0;                                   //counts the tries to reenter the pw
    char passIn[pwLength];                                  //char[] for the reentered pw
    /*string stringvar;                                     //alternatively one could use strings (C++)
    cin >> stringvar;                                       //thats what it would look like.... somehow
    if (stringvar == EinandererString)
    */

    cout << "please enter a password:" << endl;
    cin >> passIn;                                          //store the reentered pw in passIn[]
    cout<< "you entered your pw successfully"<<endl;

    while (passXcounter < passXtimes) {                     //gives you limited tries as long as you dont reach the limit (passXtimes)
        //char *passConfirm[pwLength*10] = new char;
        char *passConfirm = new char[pwLength*10];          //creates a new char[] for the next try to enter the pw
        cout<<"please confirm your pw ("<<passXtimes-passXcounter<<" times left) (please input less than "
            << pwLength*10+1<<" characters) :"<<endl;
        cin>> passConfirm;                                  // input pw again

        if (strcmp(passConfirm, passIn) == 0){              // compares the input arrays //passConfirm == passIn){
            cout<<"youve entered the password correctly";
            break;}

        ++passXcounter;                                     // increase pw counter
        delete passConfirm;                                 // delete the reentered pw
        cout<<"you have "<<passXtimes-passXcounter<<" tries  left"<<endl;
    }
    //cout<<"you have reached the maximum input attempts";
}

//(f) The guessing game
//Write program that randomly generates a number between 1 and 100 and
//the user has to guess this number. If the user guesses too high/low the
//program outputs ”too high/low” until the user hits the correct number.
void guessNrBetweenOneAndOneHundredButThisNameStillIsntLongEnough(){
    srand( (unsigned)time(NULL));
    int randomNr = rand() % 100 + 1;            //generating rando number between 1 and 100
    int randGuess = randomNr + 1;
    /*for (int i = 0; i < 1000; ++i) {          //testing
        int x;
        x = rand() % 100 + 1;
        printf("%3d|",x);
    }*/
    //cout<<endl<<randomNr<<endl;                 //print random nr
    while (randomNr != randGuess) {
        cout << "please enter your guess:" << endl;
        cin >> randGuess;                       //input guess
        if(randomNr < randGuess)                //testing if wrong guess -> too high/low
            cout<<"too high"<<endl;
        else if (randomNr > randGuess)
            cout<<"too low"<<endl;
    }
    cout<<"entered correctly"<<endl;
}