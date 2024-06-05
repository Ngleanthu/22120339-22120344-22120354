#include "Menu.h"
#include "../../constants.h"
#include "../../struct_definitions/User.h"
#include "../Misc/Misc.h"
#include "../Profile/Profile.h"

void MainMenu(std::string &username)
{
    int choice;

    User currentUserProfile;
    GetProfile(username, currentUserProfile);

    if (currentUserProfile.is_staff == true)
    {
        do
        {
            std::cout << "1. Account settings" << std::endl
                      << "2. Class Management" << std::endl
                      << "3. Course Management" << std::endl
                      << "0. Exit" << std::endl
                      << "Enter your choice: ";
            std::cin >> choice;
            if (choice == 1)
            {
                AccountMenu(username, currentUserProfile);
            }
            else if (choice == 2)
            {}
            else if (choice == 3)
            {}
            else if (choice == 4)
            {
                exit(0);
            }
            else
            {
                std::cout << "Invalid input";
            }
            wait_for_enter();
            clear_screen();
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
    }
    else
    {
        do
        {
            std::cout << "1. Account settings" << std::endl
                      << "2. View course" << std::endl
                      << "3. Scoreboard" << std::endl
                      << "0. Exit" << std::endl
                      << "Enter your choice: ";
            std::cin >> choice;
            if (choice == 1)
            {
                AccountMenu(username, currentUserProfile);
            }
            else if (choice == 2)
            {}
            else if (choice == 3)
            {}
            else if (choice == 4)
            {
                exit(0);
            }
            else
            {
                std::cout << "Invalid input";
            }
            wait_for_enter();
            clear_screen();
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
    }
}

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
        {}
        else if (choice == 3)
        {}
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
    } while (choice != 1 && choice != 2);
}
