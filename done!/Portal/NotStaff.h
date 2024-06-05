#pragma once
#include"State.h"
#include"System.h"

class NotStaff : public State
{
private:
	Data* _data;
	sf::Text _username;
	sf::Text _logout;
	bool _logoutfocus;
	bool _logoutselected;
	sf::Text _changepass;
	bool _changepassfocus;
	bool _changepassselected;
	std::string username;
	sf::RectangleShape _studentbox;
	sf::Text _student;
	bool _studentfocus;
	bool _studentselected;
	sf::RectangleShape _coursebox;
	sf::Text _course;
	bool _coursefocus;
	bool _courseselected;
	sf::RectangleShape _scorebox;
	sf::Text _score;
	bool _scorefocus;
	bool _scoreselected;


public:
	NotStaff(Data* data);
	~NotStaff();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};
