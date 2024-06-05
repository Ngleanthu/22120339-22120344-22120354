#include "View Information.h"

bool checkValidFileName(std::string name_of_file, std::string directory, std::string name)
{
    std::ifstream file;
    file.open(name_of_file + "." + directory);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            if (line.find(name) != std::string::npos)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    else
    {
        std::cout << "Unable to open file to check!\n";
    }
}

void viewListOfClasses(SchoolYear school_year)  // view all the classes in a school year.
{
    //Check if the school_year is valid or not.
    //if (!checkValidFileName("school_year", "txt", school_year.name))
    //{
    //    std::cout << "Unvalid School Year!" << std::endl;
    //    return;
    //}

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

void viewStudentsInClass(const std::string& filename, int& cnt)           // view all the students in class. 
{   
	Student* students = new Student[MAX];
	std::ifstream file(filename + ".txt");

	cnt = 0;

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
            << " " << students[j].first_name << " - " << (students[j].gender == Gender::0 ? "Male" 
            : students[j].gender == Gender::1 ? "Female" : "Not say") << " - " << students[j].dob 
            << " - " << students[j].social_id << ". \n";
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

void viewStudentsInCourse(const std::string &filename, int& cnt)  // view students in a course
{
        Student *students = new Student[MAX];
        std::ifstream file(filename + ".txt");
        cnt = 0;
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

void viewScoreBoardOfCourse(std::string course_name, int& cnt)
{
    while (!checkValidFileName("course", "txt", course_name))
    {
        std::cout << "Unvalid course's name! \n";
        std::cout << "Please try again!";
        std::cout << "\nEnter course name: ";
        std::getline(std::cin, course_name, '\n');
    }

    std::ifstream fin;
    fin.open(course_name + "-scoreboard.csv");
    StudentScore* students = new StudentScore[MAX];
    cnt = 0;
    if (fin.is_open())
    {
        int i = 0;
        std::string line;
        std::getline(fin, line);
        while (std::getline(fin, line))
        {
            std::stringstream ss(line);
            std::string token;

            StudentScore stu;

            std::getline(ss, token, ',');

            std::getline(ss, token, ',');
            stu.id = token;

            std::getline(ss, token, ',');
            stu.full_name = token;

            std::getline(ss, token, ',');
            stu.total_mark = std::stof(token);

            std::getline(ss, token, ',');
            stu.final_mark = std::stof(token);

            std::getline(ss, token, ',');
            stu.midterm_mark = std::stof(token);

            std::getline(ss, token);
            stu.other_mark = std::stof(token);

            students[i] = stu;
            i++;
        }
        cnt = i;
        fin.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
        return;
    }

    std::cout << std::setw(3) << "No " << std::setw(3) << "ID" << std::setw(15)
        << "Name" << std::setw(25) << "Total Mark" << std::setw(15)
        << "Final Mark" << std::setw(15) << "Midterm Mark" << std::setw(15)
        << "Other Mark" << std::endl;

    for (int j = 0; j < cnt; ++j)
    {
        std::cout << std::left << std::setw(4) << j + 1 << std::setw(13) << students[j].id << std::setw(15)
            << students[j].full_name << std::setw(14) << std::right << students[j].total_mark
            << std::setw(15) << students[j].final_mark << std::setw(15)
            << students[j].midterm_mark << std::setw(15) << students[j].other_mark << std::endl;
    }
}