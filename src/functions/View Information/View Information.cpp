#include "View Information.h"

void viewListOfClasses(SchoolYear school_year)  // view all the classes in a school year.
{
    // To do: Need to read school_year.name to open the correct file !!!

    // Read data in a file.
    std::ifstream fin;
    fin.open("D://school_year.txt");

    if (!fin.is_open()) std::cout << "Cannot open file!";

    LLNode* class_l = nullptr;
    LLNode* cur = class_l;

    while (!fin.eof())
    {
        LLNode* tmp = new LLNode;
        std::getline(fin, tmp->name);
        tmp->next = nullptr;
        if (cur == nullptr)
        {
            class_l = cur = tmp;
        }
        else
        {
            cur->next = tmp;
            cur = tmp;
        }
    }

    for (; class_l != nullptr; class_l = class_l->next)
    {
        std::cout << "\n" << class_l->name;
    }

    fin.close();
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
