#pragma once
#include <string>

enum Gender
{
    MALE    = 0,
    FEMALE  = 1,
    NOT_SAY = 2
};

enum DayOfWeek
{
    MONDAY    = 0,
    TUESDAY   = 1,
    WEDNESDAY = 2,
    THURSDAY  = 3,
    FRIDAY    = 4,
    SATURDAY  = 5,
    SUNDAY    = 6
};
struct Date
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

struct Student
{
    unsigned int id;
    std::string name;
    Date dob;
    Gender gender;
    unsigned int social_id;
    Student *studentNext = nullptr;
};
struct Class
{
    unsigned int id;
    std::string name;
    std::string code;
    std::string enter_year;
    unsigned int max_students     = 50;
    unsigned int current_students = 0;
    Class *classNext              = nullptr;
    Student *studentList          = nullptr;
};
struct Course
{
    unsigned int id;
    std::string name;
    std::string code;
    std::string teacher_name;
    unsigned int credits;
    unsigned int max_students     = 50;
    unsigned int current_students = 0;
    // A course can only have so much students, so it's better to use an array here instead
    // Dizzme mùa đăng ký học phần
    Student *student_list;
};
