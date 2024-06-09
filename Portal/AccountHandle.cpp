#include "AccountHandle.h"

bool RegisterSuccess(std::string username, std::string password)
{
	std::ifstream file;
	file.open("Account\\" + username + ".txt");
	if (file)
	{
		return 0;
	}
	std::ofstream newuser;
	newuser.open("Account\\" + username + ".txt");
	newuser << username << std::endl;
	newuser << password << std::endl;
	return 1; 

}
bool LoginSuccess(std::string username, std::string password)
{
	std::ifstream file;
	file.open("Account\\" + username + ".txt");
	if (!file)
	{
		return 0;
	}
	std::string user;
	std::string pass;
	getline(file, user);
	getline(file, pass);
	if (username == user && password == pass)
	{
		return 1;
	}
	return 0;
}
bool isStaff(std::string username)
{
	if (username.find("hcmus.staff") < username.size())
	{
		return 1;
	}
	return 0;
}
bool ChangePassword(std::string username , std::string password , std::string newpass)
{
	std::ifstream file("Account\\" + username + ".txt");
	std::string user;
	std::string pass;
	getline(file, user);
	getline(file, pass);
	file.clear();
	file.close();
	if (pass != password)
	{
		return 0;
	}
	std::ofstream nfile("Account\\" + username + ".txt");
	nfile << user << std::endl;
	nfile << newpass;
	nfile.close();
	return 1;
	
}
void update(std::string path)
{
	std::string get[100];
	std::ifstream f("Cmanage\\" + path + ".txt");
	int i = 0;
	std::string t;
	while (!f.eof())
	{
		getline(f, t);
		if (t.empty())
		{
			continue;
		}
		get[i] = t.substr(t.find("(")) + path.substr(0, 1);
		i++;
	}
	std::ifstream s("Student\\Students.txt");
	std::ofstream stu ;
	while (!s.eof())
	{
		getline(s, t);
		if (t.empty())
		{
			continue;
		}
		stu.open("StudentScore\\" + t + ".txt");
		stu.clear();
		stu.close();
	}
	for (int k1 = 0; k1 < i; k1++)
	{
		std::ifstream file("Score\\" + get[k1] + ".csv");
		do
		{
			getline(file, t);
		} while (t.empty());
		std::string No, id, name, mterm, final, other;
		while (!file.eof())
		{
			getline(file, No, ',');
			getline(file, id, ',');
			getline(file, name, ',');
			getline(file, mterm, ',');
			getline(file, final, ',');
			getline(file, other);
			if (No.empty())
			{
				continue;
			}
			std::fstream scr("StudentScore\\" + id + ".txt", std::ios::app);
			scr << get[k1] << "," << mterm << "," << final << "," << other << std::endl;
			scr.close();
			
		}
		
	}
	
}