#include "ChangePassword.h"

void changePassword(std::string username)
{
    RowResult userRow = SearchSingleCSVRecord(loginDataFile, dataDirectory, username);
    if (userRow.errorMsg != "")
    {
        std::cout << userRow.errorMsg << std::endl;
        return;
    }

    std::string oldPassword;
    std::string newPassword;
    std::string retypePassword;

    do
    {
        std::cout << "Enter your old password: ";
        std::cin >> oldPassword;
        if (oldPassword.compare(userRow.row->columns[1]))
        {
            std::cout << "Wrong password!" << std::endl;
        }
    } while (oldPassword.compare(userRow.row->columns[1]));

    do
    {
        std::cout << "Enter your new password: ";
        std::cin >> newPassword;
        std::cout << "Retype your new password: ";
        std::cin >> retypePassword;
        if (newPassword.compare(retypePassword))
        {
            std::cout << "Password does not match!" << std::endl;
        }
    } while (newPassword.compare(retypePassword));

    userRow.row->columns[1] = newPassword;

    updateCSVRecord(loginDataFile, dataDirectory, username, userRow.row);
}