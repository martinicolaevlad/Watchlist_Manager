#include "Validators.h"

Validator::Validator() = default;
Validator::~Validator() = default;

void Validator::validate_movie(const Movie &movie) {
    std::vector<std::string> errors;
    if(movie.getYear() > 2022)
        errors.emplace_back("Enter a valid year!\n");
    if(movie.getGenre().empty())
        errors.emplace_back("You can not leave this empty!\n");
    if(movie.getTitle().empty())
        errors.emplace_back("You can not leave this empty!\n");

    unsigned long long posWWW = movie.getTrailer().find("www");
    unsigned long long posHTTP = movie.getTrailer().find("http");

    if (posWWW != 0 && posHTTP != 0)
        errors.emplace_back("The trailer's link must start with one of the following strings: \"www\" or \"http\"\n");

    if(!errors.empty())
        throw MovieException(errors);
}

void Validator::validate_pos(int pos){
    std::vector<std::string> errors;
    if(pos < 0)
        errors.emplace_back("Enter a valid position!\n");
}

MovieException::MovieException(std::vector<std::string> _errors)
{
    this->errors = std::move(_errors);
}

std::vector<std::string> MovieException::getErrors() const
{
    return this->errors;
}