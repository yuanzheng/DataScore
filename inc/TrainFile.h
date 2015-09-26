#ifndef TRAIN_H
#define TRAIN_H
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;
using namespace boost;

class TrainFile {
    public:
        TrainFile(const string file);
        ~TrainFile();

        bool loadFile();
        int countRows();

    private:
        vector<string> rows;
        size_t numberOfRows;
        size_t numberOfColumns;
        string file_path;
};


#endif

