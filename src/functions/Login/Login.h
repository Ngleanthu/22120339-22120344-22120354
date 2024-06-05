#ifndef LOGIN_H
#define LOGIN_H
#pragma once

#include <string>
#include "../FileIO/FileIO.h"


std::string login();
bool findUserInCSVList(CSVList *list, std::string username, std::string password);

#endif