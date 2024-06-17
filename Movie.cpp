#include "Movie.h"
#include <iostream>
#include <string>
using namespace std;

Movie::Movie()
{
}
void Movie::update_movie(std::string new_title,std::string new_genre,int new_likes,std::string new_trailer_link)
{
    this->title=new_title;
    this->genre=new_genre;
    this->likes=new_likes;
    this->trailer=new_trailer_link;
}
std::string Movie::get_movie_title()
{
    return this->title;
}

std::string Movie::get_movie_genre()
{
    return this->genre;
}

int Movie::get_number_of_likes()
{
    return this->likes;
}

std::string Movie::get_movie_trailer()
{
    return this->trailer;
}

void Movie::set_movie_title(std::string title)
{
    this->title = title;
}

void Movie::set_movie_genre(std::string genre)
{
    this->genre = genre;
}

void Movie::set_number_of_likes(int likes)
{
    this->likes = likes;
}

void Movie::set_movie_trailer(std::string trailer)
{
    this->trailer = trailer;
}

void Movie::print_movie()
{
    cout << "Title: " << this->title;
    cout << " Genre: " << this->genre;
    cout << " Likes: " << this->likes;
    cout << " Trailer: " << this->trailer;
}

