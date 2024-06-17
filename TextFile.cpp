#include "TextFile.h"
#include <string>
#include "Movie.h"
#include <fstream>
using namespace std;

TextFile::TextFile(string filename)
{
    this->filename = filename;
}

TextFile::~TextFile()
{
}

CSVFile::CSVFile(string filename) : TextFile(filename)
{
}

void CSVFile::writeToFile(vector<Movie> movies,int length)
{
    ofstream f(this->filename);
    for (int i=0;i<length;i++)
    {
        f<<movies[i].get_movie_title()<<","<<movies[i].get_movie_genre()<<","<<movies[i].get_number_of_likes()<<","<<movies[i].get_movie_trailer()<<endl;
    }
    f.close();
}
CSVFile::~CSVFile()
{
}
HTMLFile::HTMLFile(string filename) : TextFile(filename)
{
}

void HTMLFile::writeToFile(vector<Movie> movies,int length)
{
    ofstream f(this->filename);
    f<<"<!DOCTYPE html>"<<endl;
    f<<"<html>"<<endl;
    f<<"<head>"<<endl;
    f<<"<title>Movie List</title>"<<endl;
    f<<"</head>"<<endl;
    f<<"<body>"<<endl;
    f<<"<table border=\"1\">"<<endl;
    f<<"<tr>"<<endl;
    f<<"<td>Title</td>"<<endl;
    f<<"<td>Genre</td>"<<endl;
    f<<"<td>Likes</td>"<<endl;
    f<<"<td>Trailer</td>"<<endl;
    f<<"</tr>"<<endl;
    for (int i=0;i<length;i++)
    {
        f<<"<tr>"<<endl;
        f<<"<td>"<<movies[i].get_movie_title()<<"</td>"<<endl;
        f<<"<td>"<<movies[i].get_movie_genre()<<"</td>"<<endl;
        f<<"<td>"<<movies[i].get_number_of_likes()<<"</td>"<<endl;
        f<<"<td><a href=\""<<movies[i].get_movie_trailer()<<"\">Link</a></td>"<<endl;
        f<<"</tr>"<<endl;
    }
    f<<"</table>"<<endl;
    f<<"</body>"<<endl;
    f<<"</html>"<<endl;
    f.close();
}
HTMLFile::~HTMLFile()
{
}