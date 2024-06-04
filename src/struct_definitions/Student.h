#include <string>

struct Student
{
    unsigned int id;
    std::string name;
    Date dob;
    Gender gender;
    unsigned int social_id;
    Student *studentNext = nullptr;
};

