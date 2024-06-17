#pragma once
#include <string>
class Movie{
private:
    std::string title;
    std::string genre;
    int likes;
    std::string trailer;
public:
    Movie();
    void update_movie(std::string,std::string,int,std::string);
    std::string get_movie_title();
    std::string get_movie_genre();
    int get_number_of_likes();
    std::string get_movie_trailer();
    void set_movie_title(std::string);
    void set_movie_genre(std::string);
    void set_number_of_likes(int);
    void set_movie_trailer(std::string);
    void print_movie();
};