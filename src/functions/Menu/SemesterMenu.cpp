#include "Menu.h"

bool displayingSemesterMenu = true;
bool skipInitialPromptSemesterMenu = false;

void SemesterMenu()
{
    while (displayingSemesterMenu)
    {
        std::filesystem::path semesterDB = dataDirectory + semesterFile;

        if (!std::filesystem::exists(semesterDB))
        {
            createNewCSVFile(semesterFile, dataDirectory, semesterHeader,
                             sizeof(semesterHeader) / sizeof(semesterHeader[0]));
        }

        // Read the school year file, and display the list of school years
        ListResult schoolYearList = readCSV(semesterFile, dataDirectory);

        if (schoolYearList.list->size <= 0 && !skipInitialPromptSemesterMenu)
        {
            PromptNoSemester();
        }

        std::cout << "Currently there are " << schoolYearList.list->size - 1
                  << " semesters: " << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        printCSVList(schoolYearList.list);
        std::cout << "----------------------------------------" << std::endl;
        PromptChoiceSemester();
    }
}


void PromptNoSemester()
{
    std::cout << "There isn't any semester created!" << std::endl;
    std::cout << "Do you want to create a new semester? (Y/N): ";
    char choice;
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        CreateSemester();
    }
    else if (choice == 'N' || choice == 'n')
    {
        skipInitialPromptSemesterMenu = true;
        return;
    }
    else
    {
        std::cout << "Invalid input!" << std::endl;
        PromptNoSemester();
    }
}

void PromptChoiceSemester()
{
        std::cout << "1. Create a new semester" << std::endl;
        std::cout << "2. Delete a semester" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "Your choice: ";
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            CreateSemester();
            break;
        case 2:
            DeleteSemester();
            break;
        case 0:
            displayingSemesterMenu = false;
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            PromptChoiceSemester();
        }
}
