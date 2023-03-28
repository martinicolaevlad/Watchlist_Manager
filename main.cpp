#include "UI/UI.h"
#include "Tests/Tests.h"
#include "../Repository/CSV_Watchlist.h"
#include "../Repository/HTML_Watchlist.h"
int main() {
    //Tests::testAll();
//    Repository repository{};
//    Service service{ repository };
//    UI ui{ service };
//    ui.start();
//    return 0;
    std::string command;
    while (true)
    {
        std::cout<<"choose file type (csv/html) or exit";
        std::getline(std::cin, command);

        if(command == "e" || command == "exit")
        {
            std::cout<<"program end";
            break;
        }
        else if(command == "csv" || command == "html")
        {
            Repository repository { R"(C:\Users\vladm\OneDrive\Documente\GitHub\a5-6-914-Marti-Nicolae-Vlad\Files\movies.txt)" };
            WatchList *watchList;

            if(command == "csv")
            {
                watchList = new CSVWatchlist();
                watchList->setType("csv");
            }
            else
            {
                watchList = new HTMLWatchlist();
                watchList->setType("html");
            }

            Service service {repository, watchList};
            UI userInterface {service};
            userInterface.start();
            continue;
        }
        std::cout<<"ERROR!";

    }
    return 0;
}
