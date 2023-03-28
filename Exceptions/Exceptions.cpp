#include "Exceptions.h"
#include <exception>
#include <string>

FileExceptions::FileExceptions(std::string msg) : message(std::move(msg)){}
const char * FileExceptions::what() {
    return message.c_str();
}

RepositoryException::RepositoryException() : exception{} {}
RepositoryException::RepositoryException(std::string  msg) : message{std::move( msg )} {}
const char * RepositoryException::what()
{
    return this->message.c_str();
}

const char * DuplicateMovie::what()
{
    return "There ia another movie like this!!";
}

const char * MovieNotFound::what()
{
    return "Movie not found!";
}


const char * IncorrectPosition::what() {
    return "Incorrect Position";
}