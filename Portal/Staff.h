#pragma once
#include"State.h"
#include"System.h"

class Staff : public State 
{
private:
	Data* _data;
	sf::Text _username;
	sf::Text _logout;
    sf::RectangleShape _logoutbox;
    sf::Sprite _schoolbackground;
    sf::RectangleShape _background;
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
	
	
public:
	Staff(Data* data);
	~Staff();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

