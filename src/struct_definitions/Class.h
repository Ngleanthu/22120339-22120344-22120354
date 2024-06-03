#include <string>
#include "Student.h"
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