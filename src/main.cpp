#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;
using namespace boost;

void print( vector <string> & v )
{
    /*
     * size_t. Unsigned integral type. Alias of one of the fundamental unsigned integer types. 
     * It is a type able to represent the size of any object in bytes: size_t is the type 
     * returned by the sizeof operator and is widely used in the standard library to represent sizes and counts.
     */
    size_t n = 0;

    for (; n < v.size(); n++)
        cout << v[ n ] << endl;

    cout << endl;
}

vector<string> splitString(string& str, string delimiter) {

    cout<< "Start spliting" <<endl;
    vector<string> fields;
    split( fields, str, is_any_of( delimiter ) );
    print(fields);
    cout << "Total " << fields.size() << " elements" << endl;

    return fields;
}
/*
ifstream & OpenBigFile(string file) {
    
    ifstream in = new ifstream( file );
   
    return in;
}
*/
string getColumns(string file)
{
    string line;
    ifstream myfile (file);

    //vector<string> columns;    
    if (myfile.is_open())
    {
        //size_t n = 0;
        getline(myfile, line); 
        /*
        while ( getline(myfile, line) )
        {
            //cout << line << endl;
            //splitString(line, ",");
            //break;
            n++;
        }
        */
        myfile.close();
        
        //columns = splitString(line, ",");
        //cout<< "size: " << columns.size() << endl;
        //cout<< "Total " << n << " rows" << endl;
    }
    else 
    {
        cout << "Unable to open file"; 
    }

    return line;
}

size_t numberOfRows(string file)
{
    string line;
    ifstream myfile (file);
    size_t n = 0;

    if (myfile.is_open())
    {
        while ( getline(myfile, line) )
            n++;

        myfile.close();
    }
    else 
    {
        cout << "Unable to open file"; 
    }

    return n;
}

int countRows(string file)
{
    ifstream myfile(file);
    int rows_size = 0;
     
    if (myfile.is_open())
    {
        rows_size = count(std::istreambuf_iterator<char>(myfile), 
                           std::istreambuf_iterator<char>(), '\n');

        myfile.close();
    }
    else 
    {
        cout << "Unable to open file"; 
    }

    return rows_size;
}

size_t numberOfColumns(string file)
{   
    string line;
    ifstream myfile (file);
    size_t n = 0;

    if (myfile.is_open())
    {
        getline(myfile, line); 
        myfile.close();
        vector<string> fields;
        split( fields, line, is_any_of( "," ) );
        n = fields.size();   
    }
    else 
    {
        cout << "Unable to open file"; 
    }

    return n;
}
    

int main() {
    cout << "Hello, World!" << endl;
    string file_path = "files/train.csv";
    string columns = getColumns(file_path);
    cout << columns << endl;

    size_t column_size = numberOfColumns(file_path);
    cout<< "Total " << column_size << " columns" << endl;

    int x = countRows(file_path);
    cout<< "Total " << x << " rows" << endl;

    /*
    size_t row_size = numberOfRows(file_path);
    cout<< "Total " << row_size << " rows" << endl;
    */
    return 0;
}
