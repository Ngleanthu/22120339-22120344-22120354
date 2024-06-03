#include "Login.h"

std::string login()
{
    Result loginData = readCSV(loginDataFile, loginDataDirectory);
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
    CSVNode *current = list->head;

    while (current != nullptr)
    {
        if (username.compare(current->data->columns[0]) &&
            password.compare(current->data->columns[1]))
        {
            return true;
        }
        current = current->next;
    }
    return false;
}