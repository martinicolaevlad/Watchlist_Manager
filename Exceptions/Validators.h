#pragma once
#include <exception>
#include <string>
#include <vector>
#include "../Domain/Movie.h"

class Validator
{
public:
    Validator();
    ~Validator();
    static void validate_movie(const Movie& movie);
    static void validate_pos(int pos);
};

class MovieException : public std::exception
{
private:
    std::vector<std::string> errors;
public:
    std::vector<std::string> getErrors() const;
    explicit MovieException(std::vector<std::string> errors);
};