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
	std::string _tmp;
	
public:
	CourseMan(Data* data);
	~CourseMan();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};



