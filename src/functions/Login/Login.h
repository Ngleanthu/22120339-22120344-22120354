#ifndef LOGIN_H
#define LOGIN_H
#pragma once

#include <string>
#include "../FileIO/FileIO.h"

const std::string loginDataFile      = "login.csv";
const std::string loginDataDirectory = "../../db/";

std::string login();
bool findUserInCSVList(CSVList *list, std::string username, std::string password);

#endif