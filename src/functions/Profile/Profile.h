#pragma once
#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>
#include "../../constants.h"
#include "../../struct_definitions/User.h"
#include "../FileIO/FileIO.h"
void GetProfile(std::string username, User &currentUserProfile);
void SplitDates(std::string date, Date &dateObject);
void PrintProfile(User &userProfile);

#endif