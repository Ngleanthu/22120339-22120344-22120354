#pragma once
#include"State.h"
#include"System.h"
#include<fstream>

class StudentInfo : public State
{
private:
	Data* _data;
	int cur;
	sf::Text _info[6];
	sf::RectangleShape _exitbutton;
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;
	std::string tmp;
	sf::RectangleShape _firstnamebox;
	sf::RectangleShape _lastnamebox;
	sf::RectangleShape _genderbox;
	sf::RectangleShape _idbox;
	sf::RectangleShape _dobbox;
	sf::RectangleShape _socialIDbox;
	sf::Text _firstname;
	sf::Text _lastname;
	sf::Text _id;
	sf::Text _gender;
	sf::Text _dob;
	sf::Text _socialID;

public:
	StudentInfo(Data* data);
	~StudentInfo();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();

};