#include "SchoolYear.h"

void CreateSchoolYear()
{
    unsigned int startYear;
    unsigned int endYear;

    std::cout << "Creating a new school year..." << std::endl;
    do
    {
        std::cout << "Enter the start year: ";
        std::cin >> startYear;
        if (!checkValidYear(startYear))
        {
            std::cout << "Invalid year!" << std::endl;
            continue;
        }
    } while (!checkValidYear(startYear));

    do
    {
        std::cout << "Enter the end year: ";
        std::cin >> endYear;
        if (!checkValidYear(endYear))
        {
            std::cout << "Invalid year!" << std::endl;
            continue;
        }
    } while (!checkValidYear(endYear));

    std::string schoolYearName = std::to_string(startYear) + "-" + std::to_string(endYear);

    // Check if the school year already exists
    ListResult schoolYearList = readCSV(schoolYearFile, dataDirectory);
    CSVNode *current          = schoolYearList.list->head;
    for (int i = 0; i < schoolYearList.list->size; i++)
    {
        if (current->data->columns[1] == schoolYearName)
        {
            std::cout << "The school year already exists!" << std::endl;
            return;
        }
        current = current->next;
    }

    // Format to CSVList
    CSVRow *row     = new CSVRow();
    row->columns    = new std::string[4];
    row->numColumns = 4;
    row->columns[0] = std::to_string(getNextSchoolYearID());
    row->columns[1] = schoolYearName;
    row->columns[2] = std::to_string(startYear);
    row->columns[3] = std::to_string(endYear);

    // Convert the row to the CSVNode
    CSVNode *node = new CSVNode();
    node->data    = row;
    node->next    = NULL;

    // Write to file
    CSVList *list = new CSVList();

    // Append the new node to the list
    if (schoolYearList.list->size != 0)
    {
        schoolYearList.list->tail->next = node;
        schoolYearList.list->tail       = node;
        schoolYearList.list->size++;
    }
    else
    {
        schoolYearList.list->head = node;
        schoolYearList.list->tail = node;
        schoolYearList.list->size = 1;
    }

    writeDataToCSV(schoolYearFile, dataDirectory, schoolYearList.list);

    std::cout << "School year created successfully!" << std::endl;
}

void DeleteSchoolYear()
{
    std::cout << "Deleting a school year..." << std::endl;
    std::cout << "Enter the ID of the school year you want to delete: ";
    int id;
    std::cin >> id;

    // Read the school year file
    ListResult schoolYearList = readCSV(schoolYearFile, dataDirectory);

    // Check if the school year exists
    CSVNode *current = schoolYearList.list->head->next;
    for (int i = 0; i < schoolYearList.list->size; i++)
    {
        if (std::stoi(current->data->columns[0]) == id)
        {
            // Delete the school year
            if (schoolYearList.list->size == 1)
            {
                schoolYearList.list->head = NULL;
                schoolYearList.list->tail = NULL;
                schoolYearList.list->size = 0;
            }
            else if (current == schoolYearList.list->head)
            {
                schoolYearList.list->head = current->next;
                schoolYearList.list->size--;
            }
            else if (current == schoolYearList.list->tail)
            {
                CSVNode *prev = schoolYearList.list->head;
                for (int i = 0; i < schoolYearList.list->size - 2; i++)
                {
                    prev = prev->next;
                }
                prev->next                = NULL;
                schoolYearList.list->tail = prev;
                schoolYearList.list->size--;
            }
            else
            {
                CSVNode *prev = schoolYearList.list->head;
                for (int i = 0; i < schoolYearList.list->size - 2; i++)
                {
                    prev = prev->next;
                }
                prev->next = current->next;
                schoolYearList.list->size--;
            }

            // Write the new list to the file
            writeDataToCSV(schoolYearFile, dataDirectory, schoolYearList.list);

            std::cout << "School year deleted successfully!" << std::endl;
            return;
        }
        current = current->next;
    }

    std::cout << "The school year doesn't exist!" << std::endl;
}

bool checkValidYear(unsigned int year)
{
    return (year >= 1900 && year <= 9999);
}

int getNextSchoolYearID()
{
    // Get the ID of the last school year, and add 1 to it
    ListResult schoolYearList = readCSV(schoolYearFile, dataDirectory);
    int actualSize            = schoolYearList.list->size - 1;  // Subtract the header row
    if (actualSize == 0)
    {
        return 1;
    }
    CSVNode *current = schoolYearList.list->head;
    for (int i = 0; i < actualSize - 1; i++)
    {
        current = current->next;
    }
    return std::stoi(current->data->columns[0]) + 1;
}