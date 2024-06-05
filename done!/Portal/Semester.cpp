#include "Semester.h"
#include<fstream>
#include"Create.h"
#include"CourseMan.h"
Semester::Semester(Data* data) : _data(data), size(0), _exitfocus(0), _exitselected(0), _createfocus(0), _createselected(0)
{

}

void Semester::Init()
{
	_title.setFont(_data->_assets->GetFont(LIGHT));
	_title.setString("Semester");
	_title.setPosition(0, 0);
	_title.setCharacterSize(40);
	_title.setFillColor(sf::Color::Black);
	n = 0;
	std::ifstream file("CManage\\Semester.txt");
	std::string get;
	int movex = 0, movey = 0;
	while (!file.eof())
	{
		getline(file, get);
		if (get.empty())
		{
			continue;
		}
		_getsemester[size] = get;
		_semester[size].setFont(_data->_assets->GetFont(LIGHT));
		_semester[size].setFillColor(sf::Color::Red);
		_semester[size].setCharacterSize(25);
		_semester[size].setString("*" + get);
		_semester[size].setPosition(movex * 50 + 100, movey * 50 + 100);
		movey++;
		if (_semester[size].getPosition().y > 500)
		{
			movex++;
			movey = 0;
		}
		size++;
		n++;
	}
	file.close();

	memset(_semesterfocus, 0, 100);
	memset(_semesterselected, 0, 100);

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color::Black);
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 250);

	_exit.setFont(_data->_assets->GetFont(LIGHT));
	_exit.setString("Exit");
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 240);
	_exit.setFillColor(sf::Color::Red);

	_createbox.setSize(sf::Vector2f(300, 40));
	_createbox.setFillColor(sf::Color::Red);
	_createbox.setOrigin(sf::Vector2f(_createbox.getGlobalBounds().width / 2, _createbox.getGlobalBounds().height / 2));
	_createbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 190);

	_create.setFont(_data->_assets->GetFont(LIGHT));
	_create.setCharacterSize(25);
	_create.setString("Create new semester");
	_create.setPosition(_data->_window->getSize().x / 2 - 120, _data->_window->getSize().y / 2 + 170);
	_create.setFillColor(sf::Color::Black);
}
void Semester::ProcessInput()
{
	sf::Event event;
	while (_data->_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_data->_window->close();
		}
		if (event.type == sf::Event::MouseMoved)
		{
			_exitfocus = (_exitbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_createfocus = (_createbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			for (int i = 0; i < size; i++)
			{
				_semesterfocus[i] = (_semester[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			}

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_exitselected = (_exitfocus ? 1 : 0);
			_createselected = (_createfocus ? 1 : 0);
			for (int i = 0; i < size; i++)
			{
				_semesterselected[i] = (_semesterfocus[i] ? 1 : 0);
			}
		}
	}
}
void Semester::Update()
{
	(_exitfocus ? _exitbutton.setFillColor(sf::Color::Yellow) : _exitbutton.setFillColor(sf::Color::Black));
	(_createfocus ? _createbox.setFillColor(sf::Color::Yellow) : _createbox.setFillColor(sf::Color::Red));
	for (int i = 0; i < size; i++)
	{
		(_semesterfocus[i] ? _semester[i].setFillColor(sf::Color::Blue) : _semester[i].setFillColor(sf::Color::Red));
	}
	for (int i = 0; i < size; i++)
	{
		if (_semesterselected[i])
		{
			std::ofstream file("buffer.txt");
			file << _getsemester[i].substr(0 , _getsemester[i].find("/"));
			file.close();
			_data->_states->AddState(new CourseMan(_data));
			_semesterselected[i] = 0;
		}
	}
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;
	}
	if (_createselected)
	{
		_data->_states->AddState(new CreateSemester(_data));
		_createselected = 0;
	}
}
void Semester::Draw()
{

	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_title);
	for (int i = 0; i < size; i++)
	{
		_data->_window->draw(_semester[i]);
	}
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_exit);
	_data->_window->draw(_createbox);
	_data->_window->draw(_create);
	_data->_window->display();
}