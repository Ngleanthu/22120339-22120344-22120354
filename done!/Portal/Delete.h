#pragma once
#include"State.h"
#include"System.h"
#include<fstream>
class DeleteCourse : public State
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
	std::ifstream file;
	std::string tmp;
	std::string _get[100];
	std::string _id[100];
	int l;
	sf::Text _status;
public:
	DeleteCourse(Data* data);
	~DeleteCourse();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

class DeleteStudent : public State
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
	std::ifstream file;
	std::string tmp;
	std::string _get[100];
	
	int l;
	sf::Text _status;
public:
	DeleteStudent(Data* data);
	~DeleteStudent();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

