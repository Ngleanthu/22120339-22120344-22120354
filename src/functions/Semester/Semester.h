#ifndef SEMESTER_H
#define SEMESTER_H

#include <iostream>
#include "../FileIO/FileIO.h"
#include "../../constants.h"
#include "../SchoolYear/SchoolYear.h"
#include "../Misc/Misc.h"

#include "../../struct_definitions/struct.h"

void CreateSemester();
void DeleteSemester();
bool checkValidSemester(unsigned int semester);
bool checkValidSemesterID(unsigned int semesterID);
int getNextSemesterID();
bool checkSemesterHasCourses(unsigned int semesterID);

#endif