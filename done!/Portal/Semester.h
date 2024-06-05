#pragma once
#include"State.h"
#include"System.h"

class Semester : public State
{
private:
	Data* _data;
	sf::Text _title;
	std::string _getsemester[100];
	sf::Text _semester[100];
	bool _semesterfocus[100];
	bool _semesterselected[100];
	int size;
	sf::RectangleShape _exitbutton;
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;
	sf::RectangleShape _createbox;
	sf::Text _create;
	bool _createfocus;
	bool _createselected;

	int n;
public:
	Semester(Data* data);
	~Semester();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

