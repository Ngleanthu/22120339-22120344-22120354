#include "FileIO.h"

void createNewCSVFile(std::string filename,
                      std::string directory,
                      const std::string *columnNames,
                      int headerRowSize)
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
    if (columnNames == nullptr)
    {
        return;
    }
    for (int i = 0; i < headerRowSize; i++)
    {
        file << columnNames[i];
        if (i != headerRowSize - 1)
        {
            file << ",";
        }
    }
}

void writeDataToCSV(std::string filename,
                    std::string directory,
                    CSVList *list,
                    const std::string *header_names,
                    int headerRowSize)
{
    // Note: this is only useful for writing massive amounts of data to a file
    if (!std::filesystem::exists(directory + filename))
    {
        createNewCSVFile(filename, directory, header_names, headerRowSize);
    }

    std::ofstream file;
    file.open(directory + filename);  // Ensure the existing data is overwritten with every write

    if (!file.is_open())
    {
        std::cout << "File could not be opened" << std::endl;
        return;
    }

    // If the header is not null, write it to the file
    if (header_names != nullptr)
    {
        for (int i = 0; i < headerRowSize; i++)
        {
            file << header_names[i];
            if (i != headerRowSize - 1)
            {
                file << ",";
            }
        }
        file << std::endl;
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
