#include "Enums.h"
#include "Misc.h"
#include <string>
// Student records
struct User
{
    unsigned int id;  // this will also be the Student/Admin ID
    std::string first_name;
    std::string last_name;
    Date date_of_birth;
    Gender gender;
    unsigned int social_id;
    std::string department;

    // Login details
    std::string username;
    std::string password;
};

// Struct Student extending User
struct Student
{
    User user;
    std::string major;
    std::string degree;
    float gpa;
};

// struct Admin extending User
struct Admin
{
    User user;
};