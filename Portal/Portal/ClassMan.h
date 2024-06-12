#pragma once
#include"State.h"
#include"System.h"
class ClassMan : public State
{
private:
	Data* _data;
	sf::Text _title;
	std::string _getclass[100];
	sf::Text _class[100] ;
	bool _classfocus[100];
	bool _classselected[100];
	int size;
	sf::RectangleShape _exitbutton;
	sf::Text _exit;
	bool _exitfocus;
	bool _exitselected;
	sf::RectangleShape _createbox;
	sf::Text _create;
	bool _createfocus;
	bool _createselected;
	std::string _tmp;
public:
	ClassMan(Data* data);
	~ClassMan();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};


