#pragma once
#include <string>
#include <vector>
#include "Movie.h"
using namespace std;

class TextFile {
protected:
    std::string filename;
public:
    TextFile(std::string filename);
    ~TextFile();
    virtual void writeToFile(vector<Movie> movies,int length)=0;
};

class CSVFile : public TextFile {
public:
    CSVFile(std::string filename);
    ~CSVFile();
    void writeToFile(vector<Movie> movies,int length) override;
};

class HTMLFile : public TextFile {
public:
    HTMLFile(std::string filename);
    ~HTMLFile();
    void writeToFile(vector<Movie> movies,int length) override;
};