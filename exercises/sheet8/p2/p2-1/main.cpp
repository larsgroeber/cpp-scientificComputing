/*
 * this program reads a file and throws away specific columns containing a string. the columns are seperated by tabulator
 */
#include <iostream>     // standard IO
#include <fstream>      // file streams
#include <sstream>
#include <vector>

using namespace std;

const string filterString = "error";
const string inputDataPath = "C:/Users/Hendrik/ClionProjects/cpp-scientificComputing/exercises/sheet8/p1/exoplanet.eu_catalog.dat"; ///"../p1/exoplanet.eu_catalog.dat";

void readData(vector<vector<string>> vectorMatrix);
void filterData(vector<vector<string>> vectorMatrix);

int main () {
    vector <vector<string>> vectorMatrix; // 2d vector containing the data matrix //bad behaviour -> put in main function and pass to function
    readData(vectorMatrix);
    return 0;
}


void readData(vector<vector<string>> vectorMatrix) {
    ifstream rawDataInput(inputDataPath);

    if (rawDataInput.fail())
    {
        cout << "1.error after opening file" << endl;
        return;
    }
    string lines;
    if (rawDataInput.is_open()) {
        while (getline(rawDataInput, lines))
        {
            vector <string> rowVector;
            stringstream lineStream(lines);
            string line;
            int colNr = 0;
            while ( getline( lineStream, line, '\t' ) )
            {
                if ( lines[0] == '#' )
                {
                    if ( line[0] == '#' )
                    {
                        line = line.substr( 2, line.size() - 2 ); /// rowVector.push_back( line.substr ( 2, line.size()-2 ) );
                    }
                }
                else if ( vectorMatrix[0][colNr++].find( "error" ) != string::npos )
                {
                    continue;
                }
                rowVector.push_back( line );
            }
            vectorMatrix.push_back(rowVector);
        }
//        filterData(vectorMatrix);
    }
    else
    {
        cout << "coudl open file ERROR!!!" << endl;
    }
}

void filterData( vector<vector<string>> vectorMatrix )
{
    for ( int i = 0; i < vectorMatrix[0].size(); ++i )
    {
        if ( vectorMatrix[0][i].find( "error" ) != string::npos )
        {
            vectorMatrix[0][i].erase();
        }
    }
}

//checks if the array has empty entries -> there should be no empty entries
void checkArrayForEmpty() {

}

//prints the Data nicely readable
void prettyPrint() {

}

/*
 Problem 2 (Streams) 4 Pts
The table you downloaded in Problem 1 contains data about more than 3000
exoplanets, each described by over 80 quantities and corresponding error es-
timates. As you are at ﬁrst glance only interested in the given quantities, e. g.
mass, radius, excentricity etc.,
 -> get rid of all the error estimates. Therefore
-> read in the ﬁle formatted using a ﬁle stream and string streams and print
out only those columns that are actual quantities (no error estimates) into a
new ﬁle.

 Hint: In the ﬁrst line of the data, i. e. the table header with the column
names, you have to deal with the comment character ’#’. For reading the
columns of every line you may use the getline function and specify the tab
character ’\t’ as ﬁeld delimiter.
 */