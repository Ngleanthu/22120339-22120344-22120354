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