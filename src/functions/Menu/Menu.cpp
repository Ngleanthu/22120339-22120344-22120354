#include "Menu.h"

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
                      << "2. School year management" << std::endl
                      << "3. Semester Management" << std::endl
                      << "4. Class Management" << std::endl
                      << "5. Course Management" << std::endl
                      << "0. Exit" << std::endl
                      << "Enter your choice: ";
            std::cin >> choice;
            if (choice == 1)
            {
                AccountMenu(username, currentUserProfile);
                return;
            }
            else if (choice == 2)
            {
                SchoolYearMenu();
            }
            else if (choice == 3)
            {
                SemesterMenu();
            }
            else if (choice == 4)
            {
                ClassManagementMenu();
            }
            else if (choice == 5)
            {}
            else if (choice == 0)
            {
                exit(0);
            }
            else
            {
                std::cout << "Invalid input\n";
            }
            wait_for_enter();
            clear_screen();
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0);
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
                return;
            }
            else if (choice == 2)
            {}
            else if (choice == 3)
            {}
            else if (choice == 0)
            {
                exit(0);
            }
            else
            {
                std::cout << "Invalid input\n";
            }
            wait_for_enter();
            clear_screen();
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 0);
    }
}
