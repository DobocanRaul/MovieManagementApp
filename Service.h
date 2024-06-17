#pragma once
#include "Repository.h"
#include "TextFile.h"
class Service {
private:
    Repository repository;
    Repository watchlist;
    TextFile* textfile;
public:
    Service():textfile(new CSVFile("movie.csv")){this->read_from_file("movies1.txt");};
    Service(TextFile* new_textfile):textfile(new_textfile){};
    void add_movie_service(std::string,std::string,int,std::string);
    void update_movie_service(std::string,std::string,int,std::string,int);
    void delete_movie(int);
    Movie* get_all_movies();
    int get_number_of_movies();
    Movie get_movie_by_title(std::string);
    void print_all_movies_service();
    void add_movies_to_watchlist(int,std::string);
    Movie* return_watchlist();
    void remove_from_watchlist(int);
    void read_from_file(std::string path);
    void write_to_file(std::string path);
    void write_to_textfile();
};
