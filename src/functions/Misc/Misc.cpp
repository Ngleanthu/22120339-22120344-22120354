#include "Misc.h"

void wait_for_enter()
{
    std::cout << "Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void clear_screen()
{
    std::cout << "\033[2J\033[1;1H";
}

void removeHiddenNewlineChar(std::string &str)
{
    // Classic newline
    if (str[str.length() - 1] == '\n')
    {
        str.erase(str.length() - 1);
    }

    // Windows newline
    if (str[str.length() - 1] == '\r')
    {
        str.erase(str.length() - 1);
    }
}
void SplitDates(std::string date, Date &dateObject)
{
    std::string temp;
    int i          = 0;
    char delimiter = '-';
    while (date[i] != delimiter)
    {
        temp += date[i];
        i++;
    }
    dateObject.year = std::stoi(temp);

    temp = "";
    i++;

    while (date[i] != delimiter)
    {
        temp += date[i];
        i++;
    }

    dateObject.month = std::stoi(temp);

    temp = "";
    i++;

    while (i < date.length())
    {
        temp += date[i];
        i++;
    }

    dateObject.day = std::stoi(temp);
}
bool checkValidDate(Date date)
{
    if (date.day < 1 || date.day > 31)
    {
        return false;
    }
    if (date.month < 1 || date.month > 12)
    {
        return false;
    }
    if (date.year < 2000 || date.year > 2100)
    {
        return false;
    }
    return true;
}

int getNextIdOfCSV(std::string filename, std::string directory)
{
    ListResult fileContent = readCSV(filename, directory);

    // No data in the file
    if (fileContent.list->size == 0)
    {
        return 1;
    }

    // Get the ID of the last row
    CSVNode *current = fileContent.list->head->next; // Skip header

    for (int i = 0; i < fileContent.list->size - 1; i++)
    {
        current = current->next;
    }

    return std::stoi(current->data->columns[0]) + 1;
}