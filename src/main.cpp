#include "functions/FileIO/FileIO.h"
#include "functions/Login/Login.h"
#include "global.h"
int main()
{
    std::string loggedInUsername = login();

    if (loggedInUsername == "")
    {
        std::cout << "Login failed" << std::endl;
        return 0;
    }
    std::cout << "Login successful" << std::endl;
}