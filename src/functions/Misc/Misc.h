#pragma once
#ifndef MISC_H
#define MISC_H
#include <iostream>
#include "../../struct_definitions/struct.h"
#include "../FileIO/FileIO.h"

void wait_for_enter();
void clear_screen();
void removeHiddenNewlineChar(std::string &str);
void SplitDates(std::string date, Date &dateObject);
bool checkValidDate(Date date);
int getNextIdOfCSV(std::string filename, std::string directory);
#endif