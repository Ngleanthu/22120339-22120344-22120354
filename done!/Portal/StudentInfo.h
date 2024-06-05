#pragma once
#include"State.h"
#include"System.h"
#include<fstream>

class StudentInfo : public State
{
private:
	Data* _data;
	sf::Text _title;
	int cur;
	sf::Text _info[6];
	sf::RectangleShape _exitbutton;
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;
	std::string tmp;

public:
	StudentInfo(Data* data);
	~StudentInfo();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();

};