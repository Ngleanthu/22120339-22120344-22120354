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

struct Result
{
    CSVList *list;
    std::string errorMsg;
};

Result readCSV(std::string filename, std::string directory);
void AddCSVRecord(CSVList *list, CSVRow *data);
CSVList *createCSVList();

#endif