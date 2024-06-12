#include "Semester.h"
#include<fstream>
#include"Create.h"
#include"CourseMan.h"
Semester::Semester(Data* data) : _data(data), size(0), _exitfocus(0), _exitselected(0), _createfocus(0), _createselected(0)
{

}

void Semester::Init()
{
	_title.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_title.setString("SEMESTER:");
	_title.setStyle(sf::Text::Bold);
	_title.setPosition(50, 40);
	_title.setCharacterSize(30);
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
		_semesterbox[size].setSize(sf::Vector2f(700.0f, 50.0f));
        _semesterbox[size].setFillColor(sf::Color(40, 116, 166, 240));
        _semesterbox[size].setOrigin(sf::Vector2f(_semesterbox[size].getGlobalBounds().width / 2 ,_semesterbox[size].getGlobalBounds().height / 2));
        _semesterbox[size].setPosition(movex * 700 + 400, movey * 60 + 120);

		_getsemester[size] = get;
		_semester[size].setFont(_data->_assets->GetFont(KANIT));
		_semester[size].setFillColor(sf::Color::White);
		_semester[size].setCharacterSize(25);
		_semester[size].setString(get);
		_semester[size].setOrigin(sf::Vector2f(_semester[size].getGlobalBounds().width / 2, _semester[size].getGlobalBounds().height / 2));
		_semester[size].setPosition(movex * 700 + 400, movey * 60 + 110);
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

	_exitbutton.setSize(sf::Vector2f(300, 40));
    _exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 240);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("BACK");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 230);
	_exit.setFillColor(sf::Color::Black);

	_createbox.setSize(sf::Vector2f(300, 40));
    _createbox.setFillColor(sf::Color(40, 116, 166, 240));
	_createbox.setOrigin(sf::Vector2f(_createbox.getGlobalBounds().width / 2, _createbox.getGlobalBounds().height / 2));
	_createbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 190);

	_create.setFont(_data->_assets->GetFont(KANIT));
	_create.setCharacterSize(25);
	_create.setString("CREATE NEW SEMESTER");
	_create.setOrigin(sf::Vector2f(_create.getGlobalBounds().width / 2, _create.getGlobalBounds().height / 2));
	_create.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 180);
	_create.setFillColor(sf::Color::White);
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
				_semesterfocus[i] = (_semesterbox[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
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
    (_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100)): _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
    (_createfocus ? _createbox.setFillColor(sf::Color(40, 116, 166, 100)) : _createbox.setFillColor(sf::Color(40, 116, 166, 240)));
	for (int i = 0; i < size; i++)
	{
		(_semesterfocus[i] ? _semesterbox[i].setFillColor(sf::Color(40, 116, 166, 100)) : _semesterbox[i].setFillColor(sf::Color(40, 116, 166, 240)));
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
		_data->_window->draw(_semesterbox[i]);
		_data->_window->draw(_semester[i]);
	}
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_exit);
	_data->_window->draw(_createbox);
	_data->_window->draw(_create);
	_data->_window->display();
}