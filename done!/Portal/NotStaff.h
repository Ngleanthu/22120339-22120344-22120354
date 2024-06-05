#pragma once
#include"State.h"
#include"System.h"

class NotStaff : public State
{
private:
	Data* _data;
	sf::Sprite _profilepic;
	sf::RectangleShape _background;
	sf::Text _username;
	sf::Text _logout;
	sf::RectangleShape _logoutbox;
	bool _logoutfocus;
	bool _logoutselected;
	sf::Text _changepass;
	sf::RectangleShape _changepassbox;
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
	sf::Text _info[6];
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
	std::string tmp;
public:
	NotStaff(Data* data);
	~NotStaff();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};
