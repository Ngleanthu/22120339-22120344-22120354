#pragma once
#include"State.h"
#include"System.h"
#include<fstream>

class CourseView : public State
{
private:
	Data* _data;
	sf::Text _title;
	int cur;
	sf::Text _info[8];
	sf::Text _student[100];
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
	std::string tmp;

public:
	CourseView(Data* data);
	~CourseView();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();

};