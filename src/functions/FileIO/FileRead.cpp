#include "./FileIO.h"

Result readCSV(std::string filename, std::string directory)
{
    Result result;

    std::filesystem::path path = directory + filename;
    if (!std::filesystem::exists(path))
    {
        result.list = nullptr;
        std::cout << "File does not exist" << std::endl;
        return result;
    }

    std::ifstream file;
    file.open(path);
    if (!file.is_open())
    {
        result.list = nullptr;
        std::cout << "File could not be opened" << std::endl;
        return result;
    }

    std::string header;
    std::getline(file, header);
    std::stringstream headerStream(header);
    std::string columnName;

    int numColumns = 0;
    while (std::getline(headerStream, columnName, ','))
    {
        numColumns++;
    }

    CSVList *dataList = createCSVList();

    std::string data;
    int row = 0;
    while (std::getline(file, data))
    {
        std::stringstream dataStream(data);

        CSVRow *rowData     = new CSVRow();
        rowData->columns    = new std::string[numColumns];
        rowData->numColumns = numColumns;

        std::string columnValue;
        int column = 0;

        while (std::getline(dataStream, columnValue, ','))
        {
            // Remove quotes from around column value if they exist
            if ((!columnValue.empty()) &&
                ((columnValue[0] == '"' && columnValue[columnValue.length() - 1] == '"') ||
                 (columnValue[0] == '\'' && columnValue[columnValue.length() - 1] == '\'')))
            {
                columnValue = columnValue.substr(1, columnValue.size() - 2);
            }
            rowData->columns[column] = columnValue;
            column++;
        }

        AddCSVRecord(dataList, rowData);
        row++;
    }
    result.list = dataList;
    return result;
}

CSVList *createCSVList()
{
    CSVList *list = new CSVList();
    list->head    = nullptr;
    list->tail    = nullptr;
    list->size    = 0;
    return list;
}

void AddCSVRecord(CSVList *list, CSVRow *data)
{
    CSVNode *node = new CSVNode();
    node->data    = data;
    node->next    = nullptr;

    if (list->head == nullptr)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail       = node;
    }
    list->size++;
}