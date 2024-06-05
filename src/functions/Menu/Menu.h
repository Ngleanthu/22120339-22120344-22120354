#pragma once
#include <iostream>
#include "../../struct_definitions/User.h"
#include "../FileIO/FileIO.h"

void MainMenu(std::string &username);
void AccountMenu(std::string &username, User &currentUserProfile);