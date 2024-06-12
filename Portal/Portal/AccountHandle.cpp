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
