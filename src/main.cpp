#include "global.h"

int main()
{
    while (true)
    {
        runLogic();
    }
}

void runLogic()
{
    std::string loggedInUsername;

    readSession(loggedInUsername);
    if (!loggedInUsername.empty())
    {
        std::cout << "Welcome back, " << loggedInUsername << "!" << std::endl;
        MainMenu(loggedInUsername);
        return;
    }

    std::cout << "Welcome to Student Management System!" << std::endl;
    std::cout << "Please log in to continue." << std::endl;

    loggedInUsername = login();
    if (loggedInUsername.empty())
    {
        std::cout << "Login failed!" << std::endl;
        return;
    }

    saveSession(loggedInUsername);
    std::cout << "Login successful!" << std::endl;

    MainMenu(loggedInUsername);
    // TODO: Hiển thị menu:
    // TODO: Gồm: xem profile người dùng hiện tại (từ file CSV), Logout, đổi pass
    // TODO: Và menu cho các phần liên quan đến Giáo vụ
}