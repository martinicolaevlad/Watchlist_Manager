#pragma once
#include "Watchlist.h"

class HTMLWatchlist : public WatchList
{
public:
    HTMLWatchlist();
    ~HTMLWatchlist();

    void SaveToFile() override;
    void OpenInApp() override;
};
