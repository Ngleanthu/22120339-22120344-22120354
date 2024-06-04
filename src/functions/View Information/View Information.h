#pragma once
#include "global.h"
#include <sstream>

const int MAX = 150;

struct Student {
	std::string id;
	std::string first_name;
	std::string last_name;
	std::string gender;
	std::string dob;
	std::string social_id;
};


bool checkValidFileName(std::string name_of_file, std::string directory, std::string name);

void viewListOfClasses(SchoolYear school_year);
void viewStudentsInClass(const std::string& filename);
void viewListOfCourse(Course* head);
void viewStudentsInCourse(const std::string& filename);
void viewScoreBoardOfCourse(std::string course_name);