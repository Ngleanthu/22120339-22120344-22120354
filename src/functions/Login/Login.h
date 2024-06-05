#ifndef LOGIN_H
#define LOGIN_H
#pragma once

#include <string>
#include "../../constants.h"
#include "../FileIO/FileIO.h"
#include "../Misc/Misc.h"

std::string login();
bool findUserInCSVList(CSVList *list, std::string username, std::string password);

#endif