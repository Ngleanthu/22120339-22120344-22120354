#pragma once
#include"State.h"
#include"System.h"
#include<fstream>
class CourseMan : public State
{
private:
	Data* _data;
	sf::Text _title;
	std::string _getcourse[100];
	sf::Text _course[100];
	bool _coursefocus[100];
	bool _courseselected[100];
	int size;
    sf::RectangleShape _coursebox[100];
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
	sf::RectangleShape _updatebox;
	sf::Text _update;
	bool _updatefocus;
	bool _updateselected;
	std::string _tmp;
	sf::Text _status;
public:
	CourseMan(Data* data);
	~CourseMan();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

class StudentCourse : public State
{
private:
	Data* _data;
	sf::Text _title;
	std::string _getcourse[100];
	sf::Text _course[100];
	bool _coursefocus[100];
	bool _courseselected[100];
	int size;
	sf::RectangleShape _exitbutton;
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;

	std::string _tmp;

public:
	StudentCourse(Data* data);
	~StudentCourse();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

