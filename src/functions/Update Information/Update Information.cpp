#include "Update Information.h"

void updateStudentResult(std::string& course_name, std::string id, int& cnt)
{
	while (!checkValidFileName("course", "txt", course_name))		// check the course's name.
	{
		std::cout << "Unvalid course's name! \n";
		std::cout << "Please try again!";
		std::cout << "\nEnter course name: ";
		std::getline(std::cin, course_name, '\n');
	}

	std::ifstream fin;
	fin.open(course_name + "-scoreboard.csv");
	if (!fin.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return;
	}

	StudentScore stu;

	bool flag = false;
	for (int i = 0; i < cnt; ++i)									// check the ID.
	{
		if (students[i].id == id)
		{
			flag = true;
		}
	}
	if (!flag)
	{
		std::cout << "Unvalid Student's ID!" << std::endl;
		return;
	}

	stu.id = id;
	std::cout << "\nUpdate " << stu.id << "'s results: \n";

	std::cout << "Total Mark: ";
	std::cin >> stu.total_mark;

	std::cout << "Final Mark: ";
	std::cin >> stu.final_mark;

	std::cout << "Midterm Mark: ";
	std::cin >> stu.midterm_mark;

	std::cout << "Other Mark: ";
	std::cin >> stu.other_mark;

	std::cout << "Updated successfully!" << std::endl;

	for (int i = 0; i < cnt; ++i)
	{
		if (students[i].id == stu.id)
		{
			students[i].total_mark = stu.total_mark;
			students[i].final_mark = stu.final_mark;
			students[i].midterm_mark = stu.midterm_mark;
			students[i].other_mark = stu.other_mark;
		}
	}

	std::ofstream fout;
	fout.open("tmp.csv");

	if (fout.is_open())
	{
		fout << "No,Student ID,Student Full Name,Total Mark,Final Mark,Midterm Mark,Other Mark\n";

		for (int i = 0; i < cnt; ++i)
		{
			fout << i + 1 << "," << students[i].id << "," << students[i].full_name << "," << students[i].total_mark
				<< "," << students[i].final_mark << "," << students[i].midterm_mark << ","
				<< students[i].other_mark << "\n";
		}
		fin.close();
		fout.close();

		std::string filename = course_name + "-scoreboard.csv";
		std::string tmpfile = "tmp.csv";
		remove(filename.c_str());
		rename(tmpfile.c_str(), filename.c_str());
	}
	else std::cout << "Unable to open file!" << std::endl;
	return;
}