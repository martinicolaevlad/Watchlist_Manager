#include <fstream>
#include "CSV_Watchlist.h"

CSVWatchlist::CSVWatchlist() = default;
CSVWatchlist::~CSVWatchlist() = default;

void CSVWatchlist::SaveToFile()
{
    std::ofstream f("Watchlist.csv");
    for(const auto& coat : this->movies)
        f << coat << "\n";
    f.close();
}

void CSVWatchlist::OpenInApp()
{
    system("notepad.exe Watchlist.csv");
}