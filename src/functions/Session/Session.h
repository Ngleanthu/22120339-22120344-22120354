#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>

void saveSession(std::string username);
void readSession(std::string &username);
bool checkTimeout(unsigned long long int timeoutEpoch);