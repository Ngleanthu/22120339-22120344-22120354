#pragma once
#include"State.h"
#include"System.h"
#include<fstream>

class CourseView : public State
{
private:
	Data* _data;
	sf::Clock clock;
	sf::Text _title;
	int cur;
	sf::RectangleShape _coursebox;
	sf::Text _info[8];
	sf::Text _student[100];
	bool _studentfocus[100];
	bool _studentselected[100];
	sf::RectangleShape _exitbutton;
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;
	sf::RectangleShape _createbox;
	sf::Text _create;
	bool _createfocus;
	bool _createselected;
	sf::RectangleShape _deletebox;
	sf::Text _delete;
	bool _deletefocus;
	bool _deleteselected;
	sf::RectangleShape _exportbox;
	sf::Text _export;
	bool _exportfocus;
	bool _exportselected;
	sf::RectangleShape _scorebox;
	sf::Text _score;
	bool _scorefocus;
	bool _scoreselected;
	std::string tmp;
	sf::Text _status;
	std::string _getbuffer;
public:
	CourseView(Data* data);
	~CourseView();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();

};

class CourseView1 : public State
{
private:
	Data* _data;
	sf::Text _title;
	int cur;
	sf::Text _info[8];
	sf::Text _score[3];
	sf::RectangleShape _exitbutton;
    sf::RectangleShape _coursebox;
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;
	std::string tmp;

public:
	CourseView1(Data* data);
	~CourseView1();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();

};