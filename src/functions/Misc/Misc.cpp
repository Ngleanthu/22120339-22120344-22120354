#include "Misc.h"

void wait_for_enter()
{
    std::cout << "Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void clear_screen()
{
    std::cout << "\033[2J\033[1;1H";
}

void removeHiddenNewlineChar(std::string &str)
{
    // Classic newline
    if (str[str.length() - 1] == '\n')
    {
        str.erase(str.length() - 1);
    }

    // Windows newline
    if (str[str.length() - 1] == '\r')
    {
        str.erase(str.length() - 1);
    }
}