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
    std::string id;
    std::string student_name;
    Date dob;
    Gender gender;
    std::string social_id;
    Student *studentNext = nullptr;
};
struct ClassList
{
    std::string class_id;
    std::string class_name;
    //std::string code;
    //std::string enter_year;
    unsigned int max_students     = 50;
    unsigned int current_students = 0;
    unsigned int belong_to_schoolyear_id;
    ClassList *classNext = nullptr;
    Student *studentList = nullptr;
};
struct CourseList
{
    unsigned int course_id;
    std::string course_name;
    std::string code;
    std::string teacher_name;
    unsigned int credits;
    unsigned int max_students     = 50;
    unsigned int current_students = 0;
    // A course can only have so much students, so it's better to use an array here instead
    // Dizzme mùa đăng ký học phần
    Student *student_list;
};
struct SchoolYearList
{
    unsigned int id;
    std::string name;
    unsigned int start_year;
    unsigned int end_year;
    SchoolYearList *schoolYearNext = nullptr;
};