#pragma once
#include "Movie.h"
#include <vector>
using namespace std;
class Repository {
private:
    vector<Movie> movies;
public:
    Repository();
    void add_movie(Movie);
    void update_movie(Movie,int);
    void delete_movie(int);
    Movie* get_all_movies();
    int get_number_of_movies();
    Movie get_movie_by_title(std::string);
    void print_all_movies();
    int get_movie_by_genre(int,std::string);
    Movie get_movie_on_position(int);
    vector<Movie> get_movies();
};

