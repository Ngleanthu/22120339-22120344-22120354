#pragma once
#include"State.h"
#include"System.h"
class ChangePass : public State
{
private:
	
	Data* _data;
	sf::Time time;
	sf::Clock clock;
	sf::RectangleShape _oldpassbox;
	sf::RectangleShape _passwordbox;
	sf::RectangleShape _passwordbox2;
	sf::Text _oldpass;
	sf::Text _password;
	sf::Text _password2;
	sf::RectangleShape _submitbutton;
	sf::RectangleShape _exitbutton;
	sf::Text _submit;
	sf::Text _exit;
	sf::Text _showoldpass;
	std::string _getoldpass;
	sf::Text _showpassword;
	std::string _getpassword;
	std::string showpassword;
	sf::Text _showpassword2;
	std::string _getpassword2;
	std::string showpassword2;
	bool _oldpassfocus;
	bool _passwordfocus;
	bool _passwordfocus2;
	bool _blink;
	bool _exitfocus;
	bool _submitfocus;
	bool _exitselected;
	bool _submitselected;
	sf::Text _status;
	std::string username;
	

public:
	ChangePass(Data* data);
	~ChangePass();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

