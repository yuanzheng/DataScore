#include "TrainFile.h"
#include "../inc/TrainFile.h"

TrainFile::TrainFile(const string file) {
    this->file_path = file;
    //ows = vector<string>();
    numberOfRows = 0;
    numberOfColumns = 0;

}

TrainFile::~TrainFile() {
    //if (this->rows != NULL)
        cout << "TrainFile destructor" << endl;
        //delete this->rows;
}


bool TrainFile::loadFile() {
    cout << "Loading ... " << endl;

    string line;
    ifstream myfile (file_path);

    // TODO : start should not less than 1

    if (myfile.is_open())
    {
        // data
        while ( getline(myfile, line) )
        {
            rows.push_back(line);
            numberOfRows++;
        }
        myfile.close();
    }
    else 
    {
        cout << "Unable to open file"; 
        return false;
    }

    cout << "Total " << numberOfRows << " have been loaded!" << endl;
    vector<string> columns = splitString(rows.front(), ",");
    numberOfColumns = columns.size();
    cout << "Total " << numberOfColumns << " colmuns!" << endl;
    return true;
}

void TrainFile::print( vector <string> & v )
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

vector<string>& TrainFile::getRows()
{
    cout << "Origin rows address " << &rows << endl;
    return rows;
}

vector<string> TrainFile::splitString(string& str, string delimiter) {

    cout<< "Start spliting" <<endl;
    vector<string> fields;
    split( fields, str, is_any_of( delimiter ) );
    print(fields);
    //cout << "Total " << fields.size() << " elements" << endl;

    return fields;
}

int TrainFile::countRows()
{
    if (numberOfRows != 0)
        return numberOfRows;

    ifstream myfile(this->file_path);
    int rows_size = 0;

    if (myfile.is_open())
    {
        cout << "Recout ... " << endl;
        rows_size = count(std::istreambuf_iterator<char>(myfile),
                          std::istreambuf_iterator<char>(), '\n');

        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    numberOfRows = rows_size-1;

    return rows_size;
}