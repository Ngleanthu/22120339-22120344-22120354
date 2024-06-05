#include "Menu.h"
std::string schoolYearHeader[] = {"id", "school_year", "start_year", "end_year"};

bool skipInitialPrompt = false;
bool displaying = true;
void SchoolYearMenu()
{
    while (displaying)
    {
        std::filesystem::path schoolYearDB = dataDirectory + schoolYearFile;

        if (!std::filesystem::exists(schoolYearDB))
        {
            createNewCSVFile(schoolYearFile, dataDirectory, schoolYearHeader,
                             sizeof(schoolYearHeader) / sizeof(schoolYearHeader[0]));
        }

        // Read the school year file, and display the list of school years
        ListResult schoolYearList = readCSV(schoolYearFile, dataDirectory);

        if (schoolYearList.list->size - 1 == 0 && !skipInitialPrompt)
        {
            PromptNoSchoolYear();
        }

        std::cout << "Currently there are " << schoolYearList.list->size - 1
                  << " school years: " << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        printCSVList(schoolYearList.list);
        std::cout << "----------------------------------------" << std::endl;
        promptChoice();
    }
}

void PromptNoSchoolYear()
{
    std::cout << "There isn't any school year created!" << std::endl;
    std::cout << "Do you want to create a new school year? (Y/N): ";
    char choice;
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        CreateSchoolYear();
    }
    else if (choice == 'N' || choice == 'n')
    {
        skipInitialPrompt = true;
        return;
    }
    else
    {
        std::cout << "Invalid input!" << std::endl;
        PromptNoSchoolYear();
    }
}

void promptChoice()
{
    do
    {
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1. Create a new school year" << std::endl;
        std::cout << "2. Delete a school year" << std::endl;
        std::cout << "0. Go back" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            CreateSchoolYear();
            return;
        }
        else if (choice == 2)
        {
            DeleteSchoolYear();
            return;
        }
        else if (choice == 0)
        {
            displaying = false;
            return;
        }
        else
        {
            std::cout << "Invalid input!" << std::endl;
        }

    } while (true);
}

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

void PromptNewSchoolYear()
{
    std::cout << "There isn't any school year created!" << std::endl;
    std::cout << "Do you want to create a new school year? (Y/N): ";
    char choice;
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        CreateSchoolYear();
    }
    else if (choice == 'N' || choice == 'n')
    {
        return;
    }
    else
    {
        std::cout << "Invalid input!" << std::endl;
        PromptNewSchoolYear();
    }
}