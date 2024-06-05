#include "FileIO.h"

void createNewCSVFile(std::string filename, std::string directory, std::string *columnNames)
{
    if (std::filesystem::exists(directory + filename))
    {
        std::cout << "This file already exists!" << std::endl;
        return;
    }

    if (!std::filesystem::exists(directory))
    {
        std::filesystem::create_directory(directory);
    }

    std::ofstream file;
    file.open(directory + filename);

    if (!file.is_open())
    {
        std::cout << "File could not be created" << std::endl;
        return;
    }

    int numColumns = sizeof(columnNames) / sizeof(columnNames[0]);
    for (int i = 0; i < numColumns; i++)
    {
        file << columnNames[i];
        if (i != numColumns - 1)
        {
            file << ",";
        }
    }
}