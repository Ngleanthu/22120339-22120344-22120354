#pragma once
#include <iostream>
#include "../../constants.h"
#include "../../struct_definitions/User.h"
#include "../ChangePassword/ChangePassword.h"
#include "../FileIO/FileIO.h"
#include "../Logout/Logout.h"
#include "../Misc/Misc.h"
#include "../Profile/Profile.h"

void MainMenu(std::string &username);
void AccountMenu(std::string &username, User &currentUserProfile);