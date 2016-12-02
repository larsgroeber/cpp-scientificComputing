#include <iostream>

using namespace std;


//defining the recursive function
void recursion()
{
    int c = 0;     //a variable for counting the steps
    double r = 0;  //parameter r from the exercise
    double y;
    y=rand() %1;   //rolling a random y
    if (0 <= y , c<500 );  //looking what value y is and checking the counter
        if (y<= 0.5);
            y = r * y;
            c+=1;  //increasing our counter
            r=r+(2/500);
        if (0.5 < y);
            if (y <= 1)
                y = r - r * y;
                c+=1;
                r=r+(2/500);
}




int main()
{
    recursion();
}
