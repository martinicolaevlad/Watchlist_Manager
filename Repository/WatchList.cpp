#include "WatchList.h"

void WatchList::addMovie(const Movie& movie) {

    this->movies.push_back(movie);

}

void WatchList::deleteMovieByPos(int position) {
    this->movies.erase(this->movies.begin()+position);

}

void WatchList::deleteMovie(Movie& movie) {
    for (int i = 0; i < this->movies.size(); i++)
        if (this->movies[i].getGenre() == movie.getGenre() && this->movies[i].getTitle() == movie.getTitle() && this->movies[i].getYear() == movie.getYear())
            this->movies.erase(this->movies.begin()+i);
}

void WatchList::play() {
    this->movies[this->current].playTrailer();
}

void WatchList::next() {
    if (this->current + 1 == this->movies.size())
    {
        this->current = 0;
        return;
    }
    this->current++;
}

Movie WatchList::getCurrentMovie() {
    return this->movies[current];
}

bool WatchList::binarySearchMovie(const std::string& title, const std::string& genre, int year) {
    int left = 0, right = this->movies.size();
    while (left <= right){
        int mid = (left + right) / 2;
        if (compareIfSameMovie(this->movies[mid], title, genre, year))
            return true;
        else if (this->movies[mid].getTitle().compare(title) < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

bool WatchList::compareIfSameMovie(const Movie& movie, const std::string& title, const std::string& genre, int year) {
    if (movie.getTitle() == title && movie.getGenre() == genre && movie.getYear() == year)
        return true;
    return false;
}

Movie WatchList::operator[](int index) {
    return this->movies[index];
}

void WatchList::setMovie(const std::vector<Movie>& newMovies)
{
    this->movies = newMovies;
}