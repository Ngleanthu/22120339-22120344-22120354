#include "FileIO.h"

void updateCSVRecord(std::string filename,
                     std::string directory,
                     std::string columnToSearch,
                     CSVRow *updatedRow)
{
    ListResult tempFileData = readCSV(filename, directory);

    // Get the headers as well, since it's just updating, we can just get it directly from the file
    CSVRow *headers = tempFileData.list->head->data;

    if (tempFileData.errorMsg != "")
    {
        std::cout << tempFileData.errorMsg << std::endl;
        return;
    }

    CSVList *dataList = tempFileData.list;
    CSVNode *current  = dataList->head;

    while (current != nullptr)
    {
        if (columnToSearch.compare(current->data->columns[0]) == 0)
        {
            current->data = updatedRow;
            break;
        }
        current = current->next;
    }

    std::string path = directory + "/" + filename;

    std::ofstream file(path);

    if (!file.is_open())
    {
        std::cout << "Error: Could not open file " << path << std::endl;
        return;
    }

    current = dataList->head;
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

    file.close();
}