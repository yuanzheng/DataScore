#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "../inc/TrainFile.h"

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

string getColumnNames(string file)
{
    string line;
    ifstream myfile (file);

    if (myfile.is_open())
    {
        getline(myfile, line); 
        myfile.close();
    }
    else 
    {
        cout << "Unable to open file"; 
    }

    return line;
}

/*
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
*/

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

size_t countCharacter(string& line, char c)
{
    string field;
    stringstream ss(line);
    size_t counter = 0;

    while(getline(ss, field, c))
        counter++;

    return counter;
}

size_t numberOfColumns(string file)
{   
    string line;
    ifstream myfile (file);
    size_t counter = 0;

    if (myfile.is_open())
    {
        getline(myfile, line); 
        
        counter = countCharacter(line, ',');

        myfile.close();
    }
    else 
    {
        cout << "Unable to open file"; 
    }

    return counter;
}

void BasicInfo(string file_path)
{

    string line;
    ifstream myfile (file_path);
    size_t n_columns = 0;
    size_t n_rows = 0;

    if (myfile.is_open())
    {
        getline(myfile, line);

        vector<string> fields;
        split( fields, line, is_any_of( "," ) );
        n_columns = fields.size();   
        
        while ( getline(myfile, line) )
            n_rows++;

        myfile.close();
    }
    else 
    {
        cout << "Unable to open file"; 
    }

    cout << "Total " << n_rows << " rows" << endl;
    cout << "Total " << n_columns << " columns" << endl;

}

void PrintRows(string file_path, int start = 1, int end = -1)
{
    string line;
    ifstream myfile (file_path);
    size_t counter = 0;
    string rows = "";

    // TODO : start should not less than 1

    if (myfile.is_open())
    {
        // column names
        //getline(myfile, line);
        
        // data
        while ( getline(myfile, line) )
        {
            // start from
            if (counter >= start)
            {
                rows += line + "\n";
            }

            // quit
            if (counter == end)
                break;

            counter++;
        }
        myfile.close();
    }
    else 
    {
        cout << "Unable to open file"; 
    }

    cout << rows <<endl;
}

/*
 * @param x, row
 * @param y, column
 */
void PrintOneColumn(string file_path, size_t x = 1, size_t y = 1)
{
    string line;
    ifstream myfile (file_path);
    // TODO : start should not less than 1

    string column = "";
    
    if (myfile.is_open())
    {
        size_t count_row = 0;
        // read the entire line into a string
        while ( getline(myfile, line) )
        {
            // column names
            size_t numberOfColumns = countCharacter(line, ',');

            if (x > numberOfColumns)
            {
                myfile.close();
                return;
            }

            string field;
            size_t counter = 0;

            // To separate the each column out of the line
            stringstream ss(line);
            while(getline(ss, field, ','))
            {
                counter++;
                if (x == counter)
                    break;
            }
            //cout << field << endl;
            
            if (count_row == 0)
                column += field;
            else
                column += "," + field;

            count_row++;
            break;
        }
        myfile.close();

        cout << "checkout: \n" << column << endl;
    }
    else 
    {
        cout << "Unable to open file"; 
    }
}


void PrintOneColumn(string file_path, size_t index = 1)
{
    string line;
    ifstream myfile (file_path);
    // TODO : start should not less than 1

    string column = "";
    
    if (myfile.is_open())
    {
        size_t count_row = 0;
        // read the entire line into a string
        while ( getline(myfile, line) )
        {
            // column names
            size_t numberOfColumns = countCharacter(line, ',');

            if (index > numberOfColumns)
            {
                myfile.close();
                return;
            }

            string field;
            size_t counter = 0;

            // To separate the each column out of the line
            stringstream ss(line);
            while(getline(ss, field, ','))
            {
                counter++;
                if (index == counter)
                    break;
            }
            //cout << field << endl;
            
            if (count_row == 0)
                column += field;
            else
                column += "," + field;

            count_row++;
            break;
        }
        myfile.close();

        cout << "checkout: \n" << column << endl;
    }
    else 
    {
        cout << "Unable to open file"; 
    }
/*
    string tmp;
    size_t counter = 0;
    stringstream xx(column);
    while(getline(xx, tmp, ','))
        counter++;
    cout << "found: " << counter << endl;
*/
}

// TODO
void PrintColumns(string file_path, size_t start = 1, size_t end = 1)
{
    string line;
    ifstream myfile (file_path);
    // TODO : start should not less than 1

    string column = "";
    
    if (myfile.is_open())
    {
        size_t count_row = 0;
        // read the entire line into a string
        while ( getline(myfile, line) )
        {
            // column names
            size_t numberOfColumns = countCharacter(line, ',');

            if (start > numberOfColumns)
            {
                myfile.close();
                return;
            }

            string field;
            size_t counter = 0;

            // To separate the each column out of the line
            stringstream ss(line);
            while(getline(ss, field, ','))
            {
                counter++;
                if (counter == end)
                    break;
            }
            //cout << field << endl;
            
            if (count_row == 0)
                column += field;
            else
                column += "," + field;

            count_row++;
        }
        myfile.close();

        cout << "checkout: \n" << column << endl;
    }
    else 
    {
        cout << "Unable to open file"; 
    }
}

// TODO
void getCell(string file_path, string delimiter, size_t x = 1, size_t y = 1)
{
    string line;
    ifstream myfile (file_path);

    string column = "";
    
    if (myfile.is_open())
    {
        getline(myfile, line);

        // read the entire line into a string
        while ( getline(myfile, line) )
        {
            vector<string> fields;
            split( fields, line, is_any_of( delimiter ) );
            cout << "The last element: " << fields.back() << endl;
            break;
        }
        myfile.close();

    }
    else 
    {
        cout << "Unable to open file"; 
    }
}

void predict(string file_path)
{


}

int training(string file_path)
{
    TrainFile* f = new TrainFile(file_path);
    cout << "Training!" << endl;
    while (true)
    {
        string line;
        cout << "Options: " << endl;
        cout << "1. Load training file (Typing: 1 or quit)" << endl;
        cin >> line;

        if (line == "1")
        {
            if (f->loadFile())
                break;
            else
                cout << "Loading failed !" << endl;

        }
        else if (line == "quit")
        {
            delete f;
            return 0;
        }
    }
    
    while (true)
    {
        string option;
        
        cout << "2. Number of rows" << endl;
        cout << "3. Number of columns" << endl;
        cout << "4. Print column names" << endl;
        cout << "5. Print one row, (row number)" << endl;
        cout << "6. Print one column, (column number)" << endl;
        cout << "7. Split by columns, (number of columns in each file)" << endl;
        cout << "8. Split by rows, (number of rows in each file)" << endl;
        cout << "Tyeping quit, to quit" << endl;

        getline(cin, option);
        
        if (option == "2")
        {
            cout << "Total rows: " << f->countRows() << endl;
            vector<string> &theRows = f->getRows();
            cout << "Total rows from vector: " << theRows.size() << endl;
            cout << "TheRow address " << &theRows << endl;
        } 
        else if (option == "quit")
            break;

        cout << "see: " << option << endl;
         
    }

    cout << "delete f" << endl;
    delete f;

    return 0;
}


int main(int argc, char* argv[]) {
    cout << "Hello, World!" << endl;
    string file_path = "files/train.csv";
    
    cout << "argc = " << argc << "  " << (argc != 3) << endl;
    if (argc != 3)
    {
        cout << "Run taining:\nUSAGE: ./main -t train.csv" << endl;
        cout << "Run predicting:\nUSAGE: ./main -p test.csv" << endl;
        return -1;
    }
        

    if (strcmp(argv[1],"-t") == 0)
    {
        string file(argv[2]);
        training(file);

    }
    else if (strcmp(argv[1],"-p") == 0) 
    {
        cout << "Predict!" << endl;
        string file(argv[2]);
        predict(file);
    }
    else
    {
        cout << "Run taining:\nUSAGE: ./main -t train.csv" << endl;
        cout << "Run predicting:\nUSAGE: ./main -p test.csv" << endl;
    }


    //getCell(file_path, ",");
    //PrintOneColumn(file_path, 1934);
    //PrintRows(file_path, 1, 1);
    //BasicInfo(file_path);
    //string columns = getColumnNames(file_path);
    //cout << columns << endl;

    //size_t column_size = numberOfColumns(file_path);
    //cout<< "Total " << column_size << " columns" << endl;

    //int x = countRows(file_path);
    //cout<< "Total " << x << " rows" << endl;

    return 0;
}
