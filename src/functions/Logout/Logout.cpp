#include "Logout.h"

void Logout(std::string &username, User &currentUserProfile)
{
    std::cout << "Logging out..." << std::endl;
    username           = "";
    currentUserProfile = {};
    return;
}