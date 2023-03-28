#pragma once
#include "WatchList.h"

class CSVWatchlist : public WatchList
{
public:
    CSVWatchlist();
    ~CSVWatchlist();

    void SaveToFile() override;
    void OpenInApp() override;
};
