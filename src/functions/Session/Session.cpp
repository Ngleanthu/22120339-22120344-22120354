#include "Session.h"

const int SESSION_TIMEOUT_HOURS          = 3;
const std::string SESSION_FILE_NAME      = "session.txt";
const std::string SESSION_FILE_DIRECTORY = "./";

void saveSession(std::string username)
{
    unsigned long long int savedEpoch = std::chrono::duration_cast<std::chrono::seconds>(
                                            std::chrono::system_clock::now().time_since_epoch())
                                            .count();
    unsigned long long int timeoutEpoch = savedEpoch + (SESSION_TIMEOUT_HOURS * 60 * 60);

    // Create session file if not exist
    if (!std::filesystem::exists(SESSION_FILE_DIRECTORY + SESSION_FILE_NAME))
    {
        std::ofstream sessionFile;
        sessionFile.open(SESSION_FILE_DIRECTORY + SESSION_FILE_NAME, std::ios::in | std::ios::app);
        sessionFile.close();
        return;
    }

    std::ofstream sessionFile;
    sessionFile.open("session.txt");

    if (!sessionFile.is_open())
    {
        std::cout << "Session file is corrupted!" << std::endl;
        std::cout << "You'll need to log in the next time you restart the app." << std::endl;
        return;
    }

    sessionFile << username << std::endl;
    sessionFile << savedEpoch << std::endl;
    sessionFile << timeoutEpoch << std::endl;
    sessionFile.close();
}

void readSession(std::string &username)
{
    std::fstream sessionFile;

    if (!std::filesystem::exists("session.txt"))
    {
        return;
    }

    if (sessionFile.peek() == std::ifstream::traits_type::eof())
    {
        return;
    }
    sessionFile.open("session.txt");
    if (!sessionFile.is_open())
    {
        std::cout << "Session file is corrupted!" << std::endl;
        std::cout << "Please log in again." << std::endl;
        return;
    }

    unsigned long long int savedEpoch;
    unsigned long long int timeoutEpoch;

    sessionFile >> username;
    sessionFile >> savedEpoch;
    sessionFile >> timeoutEpoch;

    sessionFile.close();

    if (checkTimeout(timeoutEpoch))
    {
        std::cout << "Session has timed out!" << std::endl;
        std::cout << "Please log in again." << std::endl;

        // Clear session file
        sessionFile.open("session.txt");
        sessionFile.close();

        username     = "";
        savedEpoch   = 0;
        timeoutEpoch = 0;
    }
}

void clearSession()
{
    std::ofstream sessionFile;
    sessionFile.open("session.txt");
    sessionFile.close();
}
bool checkTimeout(unsigned long long int timeoutEpoch)
{
    unsigned long long int currentEpoch = std::chrono::duration_cast<std::chrono::seconds>(
                                              std::chrono::system_clock::now().time_since_epoch())
                                              .count();
    if (currentEpoch > timeoutEpoch)
    {
        return true;
    }
    return false;
}