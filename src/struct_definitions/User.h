#pragma once
#include <string>
#include "struct.h"
// Student records
struct User
{
    unsigned int id;  // this will also be the Student/Admin ID
    std::string first_name;
    std::string last_name;
    Date date_of_birth;
    Gender gender;
    std::string social_id;
    std::string department;
    bool is_staff;
};

// Struct Student extending User
struct Student_user
{
    User user;
    std::string major;
    std::string degree;
    float gpa;
};
