#include "Profile.h"


void GetProfile(std::string username, User &currentUserProfile)
{
    RowResult currentUserData = SearchSingleCSVRecord(profileDataFile, dataDirectory, username);

    if (currentUserData.errorMsg != "")
    {
        std::cout << currentUserData.errorMsg << std::endl;
        return;
    }

    currentUserProfile.id         = std::stoi(currentUserData.row->columns[0]);
    currentUserProfile.first_name = currentUserData.row->columns[1];
    currentUserProfile.last_name  = currentUserData.row->columns[2];
    SplitDates(currentUserData.row->columns[3], currentUserProfile.date_of_birth);
    currentUserProfile.gender     = static_cast<Gender>(std::stoi(currentUserData.row->columns[4]));
    currentUserProfile.social_id  = currentUserData.row->columns[5];
    currentUserProfile.department = currentUserData.row->columns[6];
    currentUserProfile.is_staff   = std::stoi(currentUserData.row->columns[7]) == 1 ? true : false;
}



void PrintProfile(User &userProfile)
{
    std::cout << "ID: " << userProfile.id << std::endl;
    std::cout << "Full name: " << userProfile.first_name << " " << userProfile.last_name
              << std::endl;
    std::cout << "Date of birth: " << userProfile.date_of_birth.day << "/"
              << userProfile.date_of_birth.month << "/" << userProfile.date_of_birth.year
              << std::endl;
    std::cout << "Gender: ";
    userProfile.gender == Gender::MALE ? std::cout << "Male" : std::cout << "Female";
    std::cout << std::endl;
    std::cout << "Social ID: " << userProfile.social_id << std::endl;
    std::cout << "Department: " << userProfile.department << std::endl;
}