#include "FileIO.h"

bool deleteCSVRow(std::string filename, std::string directory, int delId)
{
    ListResult currentDatalist = readCSV(filename, directory);

    CSVNode *currentDataNode = currentDatalist.list->head->next;
    if (currentDataNode == nullptr)
    {
        std::cout << "No data to delete" << std::endl;
        return 1;
    }
    for (int i = 0; i < currentDatalist.list->size; i++)
    {
        if (std::stoi(currentDataNode->data->columns[0]) == delId)
        {
            CSVNode *previousDataNode = currentDatalist.list->head;
            while (previousDataNode->next != currentDataNode)
            {
                previousDataNode = previousDataNode->next;
            }
            previousDataNode->next = currentDataNode->next;
            currentDatalist.list->size--;
            writeDataToCSV(filename, directory, currentDatalist.list);
            return 0;
        }
        currentDataNode = currentDataNode->next;
    }
    return 1;
}

void deleteCSVFile(std::string filename, std::string directory)
{
    std::string path = directory + filename;
    if (remove(path.c_str()) != 0)
    {
        std::cout << "Error deleting file" << std::endl;
    }
    else
    {
        std::cout << "File successfully deleted" << std::endl;
    }
}