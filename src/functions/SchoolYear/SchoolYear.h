#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H

#include <iostream>
#include "../FileIO/FileIO.h"
#include "../../constants.h"


void CreateSchoolYear();
void DeleteSchoolYear();
bool checkValidYear(unsigned int year);
int getNextSchoolYearID();
#endif