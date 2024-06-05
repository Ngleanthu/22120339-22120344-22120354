#pragma once
#include"System.h"
#include"State.h"
#include"AccountHandle.h"

 
class LoginForm :public State
{
private:
	Data* _data;
	sf::Time time;
	sf::Clock clock;
	sf::RectangleShape _usernamebox;
	sf::RectangleShape _passwordbox;
	sf::Text _username;
	sf::Text _password;
	sf::RectangleShape _submitbutton;
	sf::RectangleShape _exitbutton;
	sf::Text _submit;
	sf::Text _exit;
	sf::Text _showusername;
	sf::Text _showpassword;
	std::string _getusername;
	std::string _getpassword;
	std::string showpassword;
	bool _usernamefocus;
	bool _passwordfocus;
	bool _blink;
    bool _exitfocus;
    bool _submitfocus;
	bool _exitselected;
	bool _submitselected;
	sf::Text _status;



public:
	LoginForm(Data* data);
	~LoginForm();
	void Init() ;
	void ProcessInput() ;
	void Update() ;
	void Draw() ;
};


