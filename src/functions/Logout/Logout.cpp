#include "Logout.h"

void Logout(std::string &username, User &currentUserProfile)
{
    std::cout << "Logging out..." << std::endl;
    username           = "";
    currentUserProfile = {};
    clearSession();
    std::cout << "Logged out successfully!" << std::endl;
    wait_for_enter();
    clear_screen();
    return;
}