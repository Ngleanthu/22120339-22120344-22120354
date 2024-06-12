#pragma once
#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "../../constants.h"
#include "../../struct_definitions/User.h"
#include "../FileIO/FileIO.h"
#include "../Misc/Misc.h"

#include "../ChangePassword/ChangePassword.h"
#include "../Logout/Logout.h"
#include "../Profile/Profile.h"
#include "../SchoolYear/SchoolYear.h"
#include "../Semester/Semester.h"


void MainMenu(std::string &username);

void AccountMenu(std::string &username, User &currentUserProfile);

void SchoolYearMenu();
void PromptNoSchoolYear();
void PromptChoiceSchoolYear();

void SemesterMenu();
void PromptNoSemester();
void PromptChoiceSemester();
bool checkValidDate(Date date);

void ClassManagementMenu();

#endif