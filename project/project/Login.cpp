#include<iostream>
#include "Login.h"
#include"AccountHandle.h"
using namespace std;
Login::Login(Data* data) : _data(data)
{
	
}
void Login::Init()
{
	cout << "Enter your username : "; cin >> username;
	cout << "Enter your password : "; cin >> password;
}
void Login::ProcessInput()
{
	
}
void Login::Update()
{
	if (isLoginSuccess(username, password)) // kiem tra dang nhap , ham khai bao trong AccountHandle
	{
		if (isStaff(username)) // kiem tra staff , ham khai bao trong AccountHandle
		{
			// Qua menu cua staff ,tao them class staff
		}
		else
		{
			// Qua menu cua student , tao them class student
		}
	}
	else
	{
		status = "Login failed!";
	}
}
void Login::Draw()
{
	system("cls");
	cout << status << endl;
	cout << "Enter your username : "; cin >> username;
	cout << "Enter your password : "; cin >> password;
}
