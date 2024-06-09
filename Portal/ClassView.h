#pragma once
#include"State.h"
#include"System.h"
#include<fstream>

class ClassView : public State
{
private:
	Data* _data;
	sf::Text _title;
	std::fstream file;
	int cur; 
	sf::Text _No[100], _id[100], _Fname[100], _Lname[100], _dob[100], _gender[100] , _Sid[100];
	bool _idfocus[100];
	bool _idselected[100];
	sf::RectangleShape _exitbutton;
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;
	sf::RectangleShape _createbox;
	sf::Text _create;
	bool _createfocus;
	bool _createselected;
	sf::RectangleShape _cell1[100];
	sf::RectangleShape _cell2[100];
	sf::RectangleShape _cell3[100];
	sf::RectangleShape _cell4[100];
	sf::RectangleShape _cell5[100];
	sf::RectangleShape _cell6[100];
	sf::RectangleShape _cell7[100];
	
public:
	ClassView(Data* data);
	~ClassView();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();

};

