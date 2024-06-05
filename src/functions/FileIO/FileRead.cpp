#include "./FileIO.h"

ListResult readCSV(std::string filename, std::string directory)
{
    ListResult result;

    std::filesystem::path path = directory + filename;
    if (!std::filesystem::exists(path))
    {
        result.list = nullptr;
        std::cout << "File does not exist" << std::endl;
        exit(0);
    }

    std::ifstream file;
    file.open(path);
    if (!file.is_open())
    {
        result.list = nullptr;
        std::cout << "File could not be opened" << std::endl;
        exit(0);
    }

    std::string header;
    std::getline(file, header);
    std::stringstream headerStream(header);
    std::string columnName;

    CSVList *dataList = createCSVList();

    int numColumns = 0;
    while (std::getline(headerStream, columnName, ','))
    {
        // Add the header name to the head of the dataList
        numColumns++;

        CSVRow *rowData     = new CSVRow();
        rowData->columns    = new std::string[numColumns];
        rowData->numColumns = numColumns;

        rowData->columns[0] = columnName;
        AddCSVRecord(dataList, rowData);
    }

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
            if (columnValue.length() > 0 && (columnValue[0] == '"' || columnValue[0] == '\''))
            {
                // If the cell is quoted, read in characters until we find the matching end quote
                char quoteChar              = columnValue[0];
                std::string quotedCellValue = columnValue.substr(1);  // Skip the opening quote
                bool endQuoteFound          = false;

                while (std::getline(dataStream, columnValue, ',') && !endQuoteFound)
                {
                    quotedCellValue += "," + columnValue;  // Add the comma back to the cell value
                    if (columnValue.length() > 0 &&
                        columnValue[columnValue.length() - 1] == quoteChar)
                    {
                        // Found the matching end quote, remove it and stop reading the cell
                        endQuoteFound = true;
                        quotedCellValue.erase(quotedCellValue.length() - 1, 1);
                    }
                }

                columnValue = quotedCellValue;
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

RowResult SearchSingleCSVRecord(std::string filename,
                                std::string directory,
                                std::string searchValue)
{
    ListResult tempFileData = readCSV(filename, directory);

    RowResult searchResult;

    if (tempFileData.errorMsg != "")
    {
        std::cout << tempFileData.errorMsg << std::endl;
        searchResult.errorMsg   = tempFileData.errorMsg;
        searchResult.row        = nullptr;
        searchResult.numColumns = 0;

        return searchResult;
    }

    CSVList *dataList = tempFileData.list;
    CSVNode *current  = dataList->head;

    // skip the header row
    current = current->next;

    while (current != nullptr)
    {
        if (searchValue == current->data->columns[0])
        {
            searchResult.row        = current->data;
            searchResult.errorMsg   = "";
            searchResult.numColumns = current->data->numColumns;
            return searchResult;
        }
        current = current->next;
    }
    searchResult.errorMsg = "Record not found";
    searchResult.row      = nullptr;
    return searchResult;
}

void printCSVList(CSVList *list)
{
    CSVNode *current = list->head;
    while (current != nullptr)
    {
        for (int i = 0; i < current->data->numColumns; i++)
        {
            std::cout << current->data->columns[i] << " ";
        }
        std::cout << std::endl;
        current = current->next;
    }
}