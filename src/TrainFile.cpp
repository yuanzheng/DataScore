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

    return true;
}

int TrainFile::countRows()
{
    if (numberOfRows != 0)
        return numberOfRows;

    ifstream myfile(this->file_path);
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
    numberOfRows = rows_size-1;

    return rows_size;
}