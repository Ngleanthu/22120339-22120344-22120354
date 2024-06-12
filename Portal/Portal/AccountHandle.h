#pragma once
#include<iostream>
#include<fstream>
#include<string>

bool RegisterSuccess(std::string username, std::string password);
bool LoginSuccess(std::string username, std::string password);
bool isStaff(std::string username);
bool ChangePassword(std::string username , std::string password , std::string newpass);
