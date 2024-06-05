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
    if (schoolYearList.list->size == 0)
    {
        createNewCSVFile(schoolYearFile, dataDirectory, schoolYearCSVHeader, 4);
    }

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
    // Format to CSVRow
    CSVRow *row     = new CSVRow();
    row->columns    = new std::string[4];
    row->numColumns = 4;
    row->columns[0] = std::to_string(getNextIdOfCSV(schoolYearFile, dataDirectory));
    row->columns[1] = schoolYearName;
    row->columns[2] = std::to_string(startYear);
    row->columns[3] = std::to_string(endYear);

    // Convert the row to the CSVNode
    CSVNode *node = new CSVNode();
    node->data    = row;
    node->next    = nullptr;

    CSVList *list = new CSVList();
    // Append to the list
    // If the list is empty
    // Set the header row to the first row
    if (schoolYearList.list->head->next == nullptr && schoolYearList.list->size == 0)
    {
        list->head = schoolYearList.list->head;
        list->head->next = node;
        list->size       = schoolYearList.list->size + 1;
    }
    else
    {
        list->head = schoolYearList.list->head;
        list->tail = node;
        list->size = schoolYearList.list->size + 1;
        CSVNode *current = schoolYearList.list->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = node;
    }


    writeDataToCSV(schoolYearFile, dataDirectory, schoolYearList.list);

    std::cout << "School year created successfully!" << std::endl;
}

void DeleteSchoolYear()
{
    unsigned int id;
    do
    {
        std::cout << "Enter the school year ID: ";
        std::cin >> id;
        if (!checkValidSchoolYearID(id))
        {
            std::cout << "The school year doesn't exist!" << std::endl;
            continue;
        }
    } while (!checkValidSchoolYearID(id));

    if (checkSchoolYearHasSemester(id))
    {
        std::cout << "The school year has semester(s)!" << std::endl;
        return;
    }

    if (deleteCSVRow(schoolYearFile, dataDirectory, id) == 0)
    {
        std::cout << "School year deleted successfully!" << std::endl;
    }
    else
    {
        std::cout << "Failed to delete the school year!" << std::endl;
    }


}

bool checkValidYear(unsigned int year)
{
    return (year >= 1900 && year <= 9999);
}
bool checkValidSchoolYearID(unsigned int id)
{
    // Read the school year file
    ListResult schoolYearList = readCSV(schoolYearFile, dataDirectory);

    // Check if the school year exists
    CSVNode *current = schoolYearList.list->head->next;
    for (int i = 0; i < schoolYearList.list->size; i++)
    {
        if (std::stoi(current->data->columns[0]) == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool checkSchoolYearHasSemester(unsigned int id)
{
    // Read the semester file
    ListResult semesterList = readCSV(semesterFile, dataDirectory);

    // Check if the school year has semester(s)
    CSVNode *current = semesterList.list->head->next;
    for (int i = 0; i < semesterList.list->size; i++)
    {
        if (std::stoi(current->data->columns[1]) == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}