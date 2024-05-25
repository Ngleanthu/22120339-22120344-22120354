#include <iostream>
#include <string>

enum Gender
{
    MALE    = 0,
    FEMALE  = 1,
    NOT_SAY = 2
};

// Student records
struct User
{
    unsigned int id;  // this will also be the Student/Admin ID
    std::string first_name;
    std::string last_name;
    Date date_of_birth;
    Gender gender;
    unsigned int social_id;

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
    std::string department;
};

struct Date
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};
