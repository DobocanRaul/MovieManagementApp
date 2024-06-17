#include "Exceptions.h"

void MovieValidator::validate_movie(const std::string & title, const std::string & genre, const int & likes, const std::string & trailer)
{
    std::string errors = "";
    if (title == "")
        errors += "The title cannot be empty!\n";
    if (genre == "")
        errors += "The genre cannot be empty!\n";
    if (likes < 0)
        errors += "The number of likes cannot be negative!\n";
    if (trailer == "")
        errors += "The trailer cannot be empty!\n";
    if (errors != "")
        throw MovieValidatorException(errors);
}

const char * MovieValidatorException::what()
{
    return this->message.c_str();
}

MovieValidatorException::MovieValidatorException(const std::string & msg) : ValidatorException(msg)
{

}

const char * ValidatorException::what()
{
    return this->message.c_str();
}

ValidatorException::ValidatorException(const std::string & msg) : message(msg)
{
}
RepositoryException::RepositoryException() : exception{}, message{""}
{
}

RepositoryException::RepositoryException(const std::string & msg): message{msg}
{
}

const char * RepositoryException::what()
{
    return this->message.c_str();
}

const char * DuplicateMovieException::what()
{
    return "There is another movie with the same title and genre!";
}

const char * InexistentMovieException::what()
{
    return "There are no movies with the given title and genre!";
}
