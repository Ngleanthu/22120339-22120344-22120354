#include "Login.h"

std::string login()
{
    ListResult loginData = readCSV(loginDataFile, loginDataDirectory);
    if (loginData.errorMsg != "")
    {
        std::cout << loginData.errorMsg << std::endl;
        return "";
    }
    std::string username;
    std::string password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    if (findUserInCSVList(loginData.list, username, password))
    {
        return username;
    }
    return "";
}

bool findUserInCSVList(CSVList *list, std::string username, std::string password)
{
    RowResult searchResult = SearchSingleCSVRecord(loginDataFile, loginDataDirectory, username);
    if (searchResult.errorMsg != "")
    {
        std::cout << searchResult.errorMsg << std::endl;
        return false;
    }

    if (searchResult.row == nullptr)
    {
        std::cout << "This user does not exist!" << std::endl;
        return false;
    }

    if (password.compare(searchResult.row->columns[1]))
    {
        return true;
    }
    else
    {
        std::cout << "Wrong password!" << std::endl;
        return false;
    }
}

// TODO: Đổi Pass + Logout