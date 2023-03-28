#include "Service.h"
#include "../Exceptions/Validators.h"
#include "../Repository/CSV_Watchlist.h"
#include "../Repository/HTML_Watchlist.h"


Service::Service(const Repository& repository, WatchList *watch_list)
{
    this->repository = repository;
    this->watchList = watch_list;
}

void Service::addRepository(const Movie &movie) {


    Validator::validate_movie(movie);
    this->repository.addMovie(movie);
}

void Service::deleteRepository(int position) {

    Validator::validate_pos(position);
    this->repository.deleteMovie(position);
}

void Service::updateRepository(int position, const Movie &movie) {


    this->repository.updateMovie(position, movie);
}

void Service::saveCart()
{
    this->watchList->SaveToFile();
}

void Service::openInAppWatchlist()
{
    this->watchList->OpenInApp();
}

void Service::addWatchList(const Movie &movie) {

    this->watchList->addMovie(movie);
}

void Service::deleteWatchList(int position) {

    this->watchList->deleteMovieByPos(position);
}

WatchList* Service::filterMoviesByGenre(const std::string& genre, const std::string &type) {
//    WatchList l;
//    if (genre.empty()) {
//        for (int i = 0; i < this->repository.getSize(); ++i)
//            l.addMovie(this->repository[i]);
//        return l;
//    }
//    for (int i = 0; i < this->repository.getSize(); ++i) {
//        if (this->repository[i].getGenre() == genre)
//            l.addMovie(this->repository[i]);
//    }
//    return l;
    std::vector<Movie> movies;
//    if(genre == -1)
//    {
//        movies = this->repository.getMovies();
//    }
    for (const auto& movie : this->repository.getMovies())
    {
        if(movie.getGenre() == genre)
            movies.push_back(movie);
    }
    WatchList *newWL;

    if(type == "csv")
    {
        newWL = new CSVWatchlist();
        newWL->setType("csv");
    }
    else
    {
        newWL = new HTMLWatchlist();
        newWL->setType("html");
    }

    newWL->setMovie(movies);
    return newWL;
}
