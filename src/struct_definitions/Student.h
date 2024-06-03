
#include <string>
struct Student
{
    std::string ID;
    std::string name;
    Date dob;
    Gender gen;  
    Student *studentNext = nullptr;
};

