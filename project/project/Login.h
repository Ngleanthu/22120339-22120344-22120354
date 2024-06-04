#pragma once
#include"State.h"
#include"System.h"
#include<iostream>
using namespace std;
class Login : public State
{
private:
	Data* _data;
	string username, password;
	string status;
public:
	Login(Data* data);
	~Login();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};
