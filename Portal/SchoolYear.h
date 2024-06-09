#pragma once
#include"State.h"
#include"System.h"
class SchoolYear : public State
{
private:
	Data* _data;
	sf::Text _title;
	std::string _getyear[100];
	sf::Text _year[100];
	bool _yearfocus[100];
	bool _yearselected[100];
	int size;
	sf::RectangleShape _exitbutton;
	sf::RectangleShape _yearbox[50];
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;
	sf::RectangleShape _createbox;
	sf::Text _create;
	bool _createfocus;
	bool _createselected;
public:
	SchoolYear(Data* data);
	~SchoolYear();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

