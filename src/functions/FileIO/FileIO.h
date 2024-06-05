#ifndef FILEIO_H
#define FILEIO_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>

struct CSVRow
{
    std::string *columns;
    int numColumns;
};

struct CSVNode
{
    CSVRow *data;
    CSVNode *next;
};

struct CSVList
{
    CSVNode *head;
    CSVNode *tail;
    int size;
};

struct ListResult
{
    CSVList *list;
    std::string errorMsg;
};

struct RowResult
{
    CSVRow *row;
    std::string errorMsg;
    int numColumns = 0;
};

ListResult readCSV(std::string filename, std::string directory);
void AddCSVRecord(CSVList *list, CSVRow *data);
CSVList *createCSVList();
RowResult SearchSingleCSVRecord(std::string filename,
                                std::string directory,
                                std::string searchValue);

void printCSVList(CSVList *list);

void UpdateCSVRecord(std::string filename,
                     std::string directory,
                     std::string columnName,
                     std::string replaceWith);
#endif