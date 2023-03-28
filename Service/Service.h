#pragma once
#include "../Repository/Repository.h"
#include "../Repository/WatchList.h"
#include <vector>
class Service {
private:
    Repository repository;
    WatchList *watchList;

public:
    explicit Service(const Repository& repository, WatchList *watch_list);
//    ~Service() = default;

    void addRepository(const Movie& movie);
    void deleteRepository(int position);
    void updateRepository(int position, const Movie& movie);

    void addWatchList(const Movie& movie);
    void deleteWatchList(int position);
    WatchList* filterMoviesByGenre(const std::string& genre, const std::string& type);

    std::vector<Movie> getAllWatchList() { return this->watchList->getMovies(); }
    std::vector<Movie> getAllRepository() { return this->repository.getMovies(); }
    Repository getRepository() { return this->repository; }
    WatchList* getWatchList() { return this->watchList; }
    std::string getType(){ return this->watchList->getType(); }
    void saveCart();
    void openInAppWatchlist();
    int resize();
};
