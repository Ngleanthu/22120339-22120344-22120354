#include "Menu.h"
void AccountMenu(std::string &username, User &currentUserProfile)
{
    int choice;
    do
    {
        std::cout << "1. View Profile" << std::endl
                  << "2. Change Password" << std::endl
                  << "3. Logout" << std::endl
                  << "0. Back" << std::endl
                  << "Enter your choice: ";
        std::cin >> choice;
        if (choice == 1)
        {
            PrintProfile(currentUserProfile);
        }
        else if (choice == 2)
        {
            changePassword(username);
        }
        else if (choice == 3)
        {
            Logout(username, currentUserProfile);
            return;
        }
        else if (choice == 0)
        {
            return;
        }
        else
        {
            std::cout << "Invalid input";
        }
        wait_for_enter();
        clear_screen();
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 0);
}