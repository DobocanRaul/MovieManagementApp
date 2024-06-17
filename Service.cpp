#include "Service.h"
#include <iostream>
#include <fstream>
#include <string>
#include "textfile.h"
void Service::add_movie_service(std::string title,std::string genre,int likes,std::string trailer)
{
    Movie m;
    m.update_movie(title,genre,likes,trailer);
    this->repository.add_movie(m);
}

void Service::update_movie_service(std::string title,std::string genre,int likes,std::string trailer,int position)
{
    Movie m;
    m.update_movie(title,genre,likes,trailer);
    this->repository.update_movie(m,position);
}

void Service::delete_movie(int position)
{
    if(position>this->repository.get_number_of_movies()-1)
    {
        throw std::exception();
    }
    this->repository.delete_movie(position);
}

Movie* Service::get_all_movies()
{
    return this->repository.get_all_movies();
}

int Service::get_number_of_movies()
{
    return this->repository.get_number_of_movies();
}

Movie Service::get_movie_by_title(std::string title)
{
    return this->repository.get_movie_by_title(title);
}

void Service::print_all_movies_service()
{
    this->repository.print_all_movies();
}
Movie* Service::return_watchlist()
{
    this->watchlist.get_all_movies();
}
void Service::add_movies_to_watchlist(int position,std::string genre)
{
    int option;
    if(this->repository.get_movie_by_genre(position,genre)!=-1)
    {
        Movie m1=this->repository.get_movie_on_position(position);
        m1.print_movie();
        std::cout<<std::endl;
        std::cout<<"Do you want to add this movie to the watchlist? 1.Yes 2.No 3.Exit\n";
        std::cin>>option;
        if (option==3)
        {
            return;
        }
        if(option==1)
        {
            this->watchlist.add_movie(this->repository.get_movie_on_position(position));
        }


        int size=this->repository.get_number_of_movies();
        if(position<this->repository.get_number_of_movies()){
            this->add_movies_to_watchlist(position+1,genre);
        }
    }
    else{
        std::cout<<"No more movies to add to the watchlist\n";
        std::cout<<"Do you want to see the Movies again? 1.Yes 2.No\n";
        std::cin>>option;
        if(option==1)
        {
            this->add_movies_to_watchlist(0,genre);
        }

    }
}
void Service::remove_from_watchlist(int position)
{
    std::cout<<"Did you like the movie? 1.Yes 2.No\n";
    int option;
    std::cin>>option;
    Movie m=this->watchlist.get_movie_on_position(position);
    if(option==1)
    {
        m.set_number_of_likes(m.get_number_of_likes()+1);
    }
    else{
        m.set_number_of_likes(m.get_number_of_likes()-1);
    }
    Movie* all_movies = this->repository.get_all_movies();
    for(int i=0;i<this->repository.get_number_of_movies();i++) {
        if (all_movies[i].get_movie_title() == m.get_movie_title()) {
            this->repository.update_movie(m, i);
        }
    }
    this->watchlist.delete_movie(position);
}
void Service::read_from_file(std::string path)
{
    ifstream file(path);
    std::string title,genre,trailer;
    int likes;
    if (!file.is_open()){
        throw exception();
        return;
    }
    while(file>>title>>genre>>likes>>trailer)
    {
        Movie m;
        m.update_movie(title,genre,likes,trailer);
        this->repository.add_movie(m);
    }
    file.close();
}
void Service::write_to_file(std::string path)
{
    ofstream file(path);
    Movie* all_movies=this->repository.get_all_movies();
    for(int i=0;i<this->repository.get_number_of_movies();i++)
    {
        file<<all_movies[i].get_movie_title()<<" "<<all_movies[i].get_movie_genre()<<" "<<all_movies[i].get_number_of_likes()<<" "<<all_movies[i].get_movie_trailer()<<endl;
    }
    file.close();
}
void Service::write_to_textfile()
{
    this->textfile->writeToFile(this->watchlist.get_movies(),this->watchlist.get_number_of_movies());
}
