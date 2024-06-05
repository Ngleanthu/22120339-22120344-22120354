#pragma once
#include"State.h"
#include"System.h"
class Verify : public State
{
private:
	Data* _data;
	sf::Time time;
	sf::Clock clock;
	sf::RectangleShape _box;
	sf::Text _text;
	sf::Text _showbox;
	std::string _getbox;
	sf::RectangleShape _submitbutton;
	sf::RectangleShape _exitbutton;
	sf::Text _submit;
	sf::Text _exit;
	bool _boxfocus;
	bool _blink;
	bool _exitfocus;
	bool _submitfocus;
	bool _exitselected;
	bool _submitselected;
	sf::Text _status;
public:
	Verify(Data* data);
	~Verify();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};


