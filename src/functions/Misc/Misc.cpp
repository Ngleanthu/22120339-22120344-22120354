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