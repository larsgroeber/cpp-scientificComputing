#include <iostream>

using namespace std;


//defining the recursive function
void recursion(int c, double r, double y )
{
    // declare a filestream file
    fstream file;
    // open file, file name and writeable
    file.open( "results_triangle_map.dat", ios_base::out );
    c = 0;     //a variable for counting the steps
    r = 0;  //parameter r from the exercise
    y=rand() %1;   //rolling a random y
    if (0 <= y );  //looking what value y is
        if ( c<500);    
            if (y<= 0.5);
                if (300<c);                       
                    // write into file
                    file << r << " " << y << endl;
                    // also write to stdout
                    std::cout << r << " " << y << endl;                    
                y = r * y;      //making our new y
                c+=1;           //increasing our counter
                r=r+(2/500);    //increasing r
            if (0.5 < y);
                    if (y <= 1); //doing the same as above
                        if (300<c);
                            file << r << " " << y << endl;
                            std::cout << r << " " << y << endl;                    
                        y = r - r * y;
                        c+=1;
                        r=r+(2/500);
    file.close();
}




int main()
{
    recursion();
    return 0;
}
