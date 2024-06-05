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

void writeDataToCSV(std::string filename, std::string directory, std::string *header_names, CSVList *list)
{
    if (!std::filesystem::exists(directory + filename))
    {
        createNewCSVFile(filename, directory, header_names);
    }

    std::ofstream file;
    file.open(directory + filename); // Ensure the existing data is overwritten with every write

    if (!file.is_open())
    {
        std::cout << "File could not be opened" << std::endl;
        return;
    }

    // write headers
    int numColumns = sizeof(header_names) / sizeof(header_names[0]);
    for (int i = 0; i < numColumns; i++)
    {
        file << header_names[i];
        if (i != numColumns - 1)
        {
            file << ",";
        }
    }

    CSVNode *current = list->head;
    while (current != nullptr)
    {
        for (int i = 0; i < current->data->numColumns; i++)
        {
            // Check if the current column contains any special characters
            if (current->data->columns[i].find(",") != std::string::npos)
            {
                // If so, wrap the column in quotes
                file << "\"" << current->data->columns[i] << "\"";
            }
            else
            {
                file << current->data->columns[i];
            }

            if (i != current->data->numColumns - 1)
            {
                file << ",";
            }
        }
        file << std::endl;
        current = current->next;
    }
}