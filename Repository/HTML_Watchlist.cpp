#include "HTML_Watchlist.h"
#include <Windows.h>
#include <shellapi.h>
#include <fstream>

HTMLWatchlist::HTMLWatchlist() = default;


HTMLWatchlist::~HTMLWatchlist() = default;

void HTMLWatchlist::SaveToFile()
{
    std::ofstream f(R"(C:\Users\vladm\OneDrive\Documente\GitHub\a5-6-914-Marti-Nicolae-Vlad\Files\Watchlist.html)");//

    f << "<!DOCTYPE html>" << "\n";
    f << "<html>" << "\n";

    f << "<head>" << "\n";
    f << "<title>Movie List</title>" << "\n";
    f << "</head>" << "\n";

    f << "<body>" << "\n";

    f << "<table border=\"1\">" << "\n";

    f << "<tr>" << "\n";
    f << "<td>Title</td>" << "\n";
    f << "<td>Genre</td>" << "\n";
    f << "<td>Year</td>" << "\n";
    f << "<td>Likes</td>" << "\n";
    f << "<td>Trailer</td>" << "\n";
    f << "</tr>" << "\n";

    for (const auto& movie : this->movies)
    {
        f << "<tr>" << "\n";

        f << "<td>" << movie.getTitle() << "</td>" << "\n";
        f << "<td>" << movie.getGenre() << "</td>" << "\n";
        f << "<td>" << movie.getYear() << "</td>" << "\n";
        f << "<td>" << movie.getLikes() << "</td>" << "\n";
        f << "<td><a href =" << movie.getTrailer() << ">Link</a></td>";

        f << "</tr>" << "\n";
    }

    f << "</table>" << "\n";

    f << "</body>" << "\n";

    f << "</html>" << "\n";
    f.close();

}

void HTMLWatchlist::OpenInApp()
{
    ShellExecuteA(nullptr, nullptr, "microsoftedge.exe", R"(C:\Users\vladm\OneDrive\Documente\GitHub\a5-6-914-Marti-Nicolae-Vlad\Files\Watchlist.html)", nullptr, SW_SHOWMAXIMIZED);
    system("PAUSE");
}

