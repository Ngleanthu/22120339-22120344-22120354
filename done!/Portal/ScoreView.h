#pragma once
#include"State.h"
#include"System.h"
#include <string>
#include<fstream>

class ScoreView : public State
{
private:
	Data* _data;
	sf::Text _title;
	int cur;
	sf::RectangleShape _exitbutton;
	sf::RectangleShape _cell1[50];
	sf::RectangleShape _cell2[50];
	sf::RectangleShape _cell3[50];
	sf::RectangleShape _cell4[50];
	sf::RectangleShape _cell5[50];
	sf::RectangleShape _cell6[50];
	sf::Text _No[100], _id[100], _name[100], _mterm[100], _final[100], _other[100];
	
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;
	std::string tmp;

public:
	ScoreView(Data* data);
	~ScoreView();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();

};

class ScoreView1 : public State
{
private:
	Data* _data;
	sf::Text _title;
	int cur;
	sf::Text _id[100], _mterm[100], _final[100], _other[100], _finalmark[100];
	sf::Text _gpa;
	sf::RectangleShape _exitbutton;
	sf::RectangleShape _cell1[50];
	sf::RectangleShape _cell2[50];
	sf::RectangleShape _cell3[50];
	sf::RectangleShape _cell4[50];
	sf::RectangleShape _cell5[50];
	sf::RectangleShape _cell6;
	sf::Text _gpaText;
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;
	std::string tmp;

public:
	ScoreView1(Data* data);
	~ScoreView1();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();

};
