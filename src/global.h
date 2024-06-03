#include <iostream>
#include <string>
#include "struct_definitions/Enums.h"
#include "struct_definitions/User.h"

struct Class
{
    unsigned int id;
    std::string name;
    std::string code;
    std::string enter_year;
    LLNode *student_list;
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
    unsigned int *student_list = new unsigned int[max_students];
};

struct SchoolYear
{
    std::string school_year;
    LLNode *class_list;
};

struct LLNode
{
    unsigned int id;
    LLNode *next;
};