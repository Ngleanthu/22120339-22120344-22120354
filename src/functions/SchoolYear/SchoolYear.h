#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H

#include <iostream>
#include "../../constants.h"
#include "../FileIO/FileIO.h"
#include "../Misc/Misc.h"

void CreateSchoolYear();
void DeleteSchoolYear();
bool checkValidYear(unsigned int year);
bool checkValidSchoolYearID(unsigned int schoolYearID);
bool checkSchoolYearHasSemester(unsigned int id);

#endif