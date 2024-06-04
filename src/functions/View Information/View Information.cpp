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

void viewStudentsInClass(const std::string& filename)           // view all the students in class. 
{   
	Student* students = new Student[MAX];
	std::ifstream file(filename + ".txt");
	int cnt = 0;
	if (file.is_open())
	{
		int i = 0;
		std::string line;
		std::getline(file, line);
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			std::string token;

			Student stu;

			std::getline(ss, token, ',');

			std::getline(ss, token, ',');
			stu.id = token;

			std::getline(ss, token, ',');
			stu.first_name = token;

			std::getline(ss, token, ',');
			stu.last_name = token;

			std::getline(ss, token, ',');
			stu.gender = token;

			std::getline(ss, token, ',');
			stu.dob = token;

			std::getline(ss, token);
			stu.social_id = token;

			students[i] = stu;
			i++;
		}
		cnt = i;
		file.close();
	}
	else
	{
		std::cerr << "Unable to open file" << std::endl;
	}

	for (int j = 0; j < cnt; ++j)
	{
		std::cout << j + 1 << "/ " << students[j].id << " - " << students[j].last_name
			<< " " << students[j].first_name << " - " << students[j].gender << " - " <<
			students[j].dob << " - " << students[j].social_id << ". \n";
	}
        delete[] students;
}

void viewListOfCourse(Course* head)     // View a list of courses.
{
        std::ifstream fin;
        fin.open("Course.txt");
        if (!fin.is_open())
        {
                std::cout << "Cannot open file !";
        }
        Course *head    = nullptr;
        Course *curr = head;
        while (!fin.eof())
        {
                Course *new_node = new Node;
                getline(fin, new_node->id, ',');
                getline(fin, new_node->name);

                new_node->next = nullptr;
                if (head == nullptr)
                {
                        head = curr = new_node;
                }
                else
                {
                        curr->course_next = new_node;
                        curr       = new_node;
                }
        }

        while (a)
        {
                std::cout << head->name << "-" << head->id << std::endl;
                head = head->course_next;
        }
      
        while (head != nullptr)
        {
                Course *curr = head;
                head         = head->course_next;
                delete curr;
        
        }
}

void viewStudentsInCourse(const std::string &filename)  // view students in a course
{
        Student *students = new Student[MAX];
        std::ifstream file(filename + ".txt");
        int cnt = 0;
        if (file.is_open())
        {
                int i = 0;
                std::string line;
                std::getline(file, line);
                while (std::getline(file, line))
                {
                        std::stringstream ss(line);
                        std::string token;

                        Student stu;

                        std::getline(ss, token, ',');

                        std::getline(ss, token, ',');
                        stu.id = token;

                        std::getline(ss, token, ',');
                        stu.first_name = token;

                        std::getline(ss, token, ',');
                        stu.last_name = token;

                        std::getline(ss, token, ',');
                        stu.gender = token;

                        std::getline(ss, token, ',');
                        stu.dob = token;

                        std::getline(ss, token);
                        stu.social_id = token;

                        students[i] = stu;
                        i++;
                }
                cnt = i;
                file.close();
        }
        else
        {
                std::cerr << "Unable to open file" << std::endl;
        }

        for (int j = 0; j < cnt; ++j)
        {
                std::cout << j + 1 << "/ " << students[j].id << " - " << students[j].last_name
                          << " " << students[j].first_name << " - " << students[j].gender << " - "
                          << students[j].dob << " - " << students[j].social_id << ". \n";
        }
        delete[] students;
}
