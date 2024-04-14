/*
Author: Ben Sailor
Name: File
Date written: 04/14/2024
Updated:
    - By: Ben Sailor on 04/14/2024
*/

#ifndef FILE_H
#define FILE_H

#include <string>

bool exists(const std::string account_num);

class File {
private:
    std::string fileName;
public:
    File();
    File(const std::string& account_num);
    void create();
    bool write(const double data);
    double read();
    bool deleteFile();
};

#endif