#include "Repository.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Repository::Repository()
{
}

void Repository::add_movie(Movie m)
{
    for (auto i = this->movies.begin(); i != this->movies.end(); ++i)
    {
        if ((*i).get_movie_title() == m.get_movie_title())
        {
            throw std::exception();
        }
    }
    this->movies.push_back(m);
}

void Repository::update_movie(Movie m, int position)
{
    this->movies[position]=m;
}

void Repository::delete_movie(int position)
{
    this->movies.erase(movies.begin()+position);
}

Movie* Repository::get_all_movies()
{
    return this->movies.data();
}

int Repository::get_number_of_movies()
{
    return this->movies.size();
}

Movie Repository::get_movie_by_title(std::string title)
{
    for(auto i=this->movies.begin();i!=this->movies.end();++i)
    {
        if((*i).get_movie_title()==title)
        {
            return *i;
        }
    }
}
Movie Repository::get_movie_on_position(int position)
{
    return this->movies.at(position);
}
int Repository::get_movie_by_genre(int index,std::string genre)
{
    Movie* all_movies = this->get_all_movies();
    for(auto i=this->movies.begin()+index;i!=this->movies.end();++i)
    {
        if((*i).get_movie_genre()==genre||genre=="")
        {
            return i-this->movies.begin();
        }
    }
    return -1;
}

void Repository::print_all_movies()
{
    for(auto i=this->movies.begin();i!=this->movies.end();++i)
    {
        (*i).print_movie();
        std::cout<<"\n";
    }
}
vector<Movie> Repository::get_movies()
{
    return this->movies;
}

