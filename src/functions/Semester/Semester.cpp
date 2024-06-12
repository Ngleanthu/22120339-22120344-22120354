#include "Semester.h"

void CreateSemester()
{
    unsigned int semesterNum;
    unsigned int schoolYearID;
    Date startDate;
    Date endDate;

    do 
    {
        std::cout << "Enter semester number: ";
        std::cin >> semesterNum;
        if (!checkValidSemester(semesterNum))
        {
            std::cout << "Invalid semester number! There are only 3 semesters in a year!" << std::endl;
            continue;
        }
    } while (!checkValidSemester(semesterNum));

    do
    {
        printCSVList(readCSV(schoolYearFile, dataDirectory).list);
        std::cout << "Enter school year ID: ";
        std::cin >> schoolYearID;
        if (!checkValidSchoolYearID(schoolYearID))
        {
            std::cout << "Invalid school year ID!" << std::endl;
            continue;
        }
    } while (!checkValidSchoolYearID(schoolYearID));

    do
    {
        std::cout << "Enter start day: ";
        std::cin >> startDate.day;
        std::cout << "Enter start month: ";
        std::cin >> startDate.month;
        std::cout << "Enter start year: ";
        std::cin >> startDate.year;
        if (!checkValidDate(startDate))
        {
            std::cout << "Invalid start date!" << std::endl;
            continue;
        }        

    } while(!checkValidDate(startDate));

    do
    {
        std::cout << "Enter end day: ";
        std::cin >> endDate.day;
        std::cout << "Enter end month: ";
        std::cin >> endDate.month;
        std::cout << "Enter end year: ";
        std::cin >> endDate.year;
        if (!checkValidDate(endDate))
        {
            std::cout << "Invalid end date!" << std::endl;
            continue;
        }        

    } while(!checkValidDate(endDate));

    // Check if the semester already exists
    ListResult semesterList = readCSV(semesterFile, dataDirectory);
    if (semesterList.list->size == 0)
    {
        createNewCSVFile(semesterFile, dataDirectory, semesterHeader, 5);
    }
    CSVNode *current        = semesterList.list->head;
    for (int i = 0; i < semesterList.list->size; i++)
    {
        if (current->data->columns[1] == std::to_string(semesterNum) && current->data->columns[2] == std::to_string(schoolYearID))
        {
            std::cout << "The semester already exists!" << std::endl;
            return;
        }
        current = current->next;
    }

    // Format to CSVRow
    CSVRow *row     = new CSVRow();
    row->columns    = new std::string[5];
    row->columns[0] = std::to_string(getNextIdOfCSV(semesterFile, dataDirectory));
    row->columns[1] = std::to_string(semesterNum);
    row->columns[2] = std::to_string(schoolYearID);
    row->columns[3] = std::to_string(startDate.year) + "-" + std::to_string(startDate.month) + "-" + std::to_string(startDate.day);
    row->columns[4] = std::to_string(endDate.year) + "-" + std::to_string(endDate.month) + "-" + std::to_string(endDate.day);
    row->numColumns = 5;

    // To CSVNode
    CSVNode *node = new CSVNode();
    node->data    = row;
    node->next    = nullptr;

    // Create a new empty list
    CSVList *list = new CSVList();

    // Append to the list
    // If the list is empty
    // Set the header row to the first row
    if (semesterList.list->head->next == nullptr && semesterList.list->size == 0)
    {
        list->head = semesterList.list->head;
        list->head->next = node;
        list->size       = semesterList.list->size + 1;
    }
    else
    {
        list->head = semesterList.list->head;
        list->tail = node;
        list->size = semesterList.list->size + 1;
        CSVNode *current = semesterList.list->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = node;
    }

    // Write to file
    writeDataToCSV(semesterFile, dataDirectory, list);
    
    std::cout << "Semester created successfully!" << std::endl;
}

void DeleteSemester()
{
    unsigned int semesterID;
    do
    {
        std::cout << "Enter semester ID: ";
        std::cin >> semesterID;
        if (!checkValidSemesterID(semesterID))
        {
            std::cout << "Invalid semester ID!" << std::endl;
            continue;
        }
    } while (!checkValidSemesterID(semesterID));

    if (checkSemesterHasCourses(semesterID))
    {
        std::cout << "The semester has courses! Please delete all courses in the semester before deleting the semester!" << std::endl;
        return;
    }

    if (deleteCSVRow(semesterFile, dataDirectory, semesterID) == 0)
    {
        std::cout << "Semester deleted successfully!" << std::endl;
    }
    else
    {
        std::cout << "Failed to delete the school year!" << std::endl;
    }
}

bool checkValidSemester(unsigned int semester)
{
    if (semester < 1 || semester > 4)
    {
        return false;
    }
    return true;
}

bool checkValidSemesterID(unsigned int semesterID)
{
    ListResult semesterList = readCSV(semesterFile, dataDirectory);
    CSVNode *current        = semesterList.list->head;
    for (int i = 0; i < semesterList.list->size; i++)
    {
        if (current->data->columns[0] == std::to_string(semesterID))
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool checkSemesterHasCourses(unsigned int semesterID)
{
    ListResult courseList = readCSV(courseDataFile, dataDirectory);
    CSVNode *current      = courseList.list->head;
    for (int i = 0; i < courseList.list->size; i++)
    {
        if (current->data->columns[3] == std::to_string(semesterID))
        {
            return true;
        }
        current = current->next;
    }
    return false;
}