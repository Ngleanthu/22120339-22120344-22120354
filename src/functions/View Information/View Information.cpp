#include "View Information.h"

void viewListOfClasses(SchoolYear school_year)  // view all the classes in a school year.
{
	Class* class_l = school_year.class_list;
    for (; class_l != nullptr; class_l = class_l->next)
    {
        std::cout << class_l->id << " - " << class_l->name << ".\n";
    }
}

void viewStudentsInClass(Class* a)             // view all the students in class. 
{   
    std::cout << "Number of students in the class: " << a->current_students << endl;
    int i = 0;
    while (a->studentList != nullptr)
    {
        std::cout << i + 1 << " - " << a->studentList->ID << " - " << a->studentList->name << ".\n";
        i++;
        a->studentList = a->studentList->studentNext;
    }
}

void viewListOfCourse(Course* course ,int numCourse)     // View a list of courses.
{
    for (int i = 0; i < numCourse; i++)
    {
        std::cout << Course[i].name << " - " << Course[i].code << "\n\n";
    }
}

void viewStudentsInCourse(Course* a)
{
    int i = 0;
    std::cout << "Number of students registered: " << a.current_students << " / " << a.max_students
         << '\n';
    while (a->student_list)
    {
        std::cout << i + 1 << " - " << a->student_list->ID << " - " << a->student_list->name << ".\n";
        i++;
        a->studentList = a->studentList->studentNext;
    }
}
