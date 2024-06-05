#pragma once
#include"System.h"
#include"State.h"
class RegisterForm :public State
{
private:
	Data* _data;
	sf::Time time;
	sf::Clock clock;
	sf::RectangleShape _usernamebox;
	sf::RectangleShape _passwordbox;
	sf::RectangleShape _passwordbox2;
	sf::Text _username;
	sf::Text _password;
	sf::Text _password2;
	sf::RectangleShape _submitbutton;
	sf::RectangleShape _exitbutton;
	sf::Text _submit;
	sf::Text _exit;
	sf::Text _showusername;
	std::string _getusername;
	sf::Text _showpassword;
	std::string _getpassword;
	std::string showpassword;
	sf::Text _showpassword2;
	std::string _getpassword2;
	std::string showpassword2;
	bool _usernamefocus;
	bool _passwordfocus;
	bool _passwordfocus2;
	bool _blink;
	bool _exitfocus;
	bool _submitfocus;
	bool _exitselected;
	bool _submitselected;
	sf::Text _status;



public:
	RegisterForm(Data* data);
	~RegisterForm();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

