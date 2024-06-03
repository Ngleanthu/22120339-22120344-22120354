#include <string>
#include "Student.h"
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