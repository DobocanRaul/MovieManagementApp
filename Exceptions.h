#pragma once
#include <exception>
#include <string>
using namespace std;
class RepositoryException:public std::exception{
protected:
    std::string message;
public:
    RepositoryException();
    RepositoryException(const std::string& msg);
    virtual ~RepositoryException() {}
    virtual const char* what();
};

class DuplicateMovieException:public RepositoryException{
public:
    const char* what();
};

class InexistentMovieException:public RepositoryException{
public:
    const char* what();
};

class ValidatorException:public std::exception{
protected:
    std::string message;
public:
    ValidatorException(const std::string& msg);
    virtual const char* what();
};

class MovieValidatorException:public ValidatorException{
public:
    MovieValidatorException(const std::string& msg);
    const char* what();
};

class MovieValidator{
public:
    void validate_movie(const std::string& title,const std::string& genre,const int& likes,const std::string& trailer);
};

