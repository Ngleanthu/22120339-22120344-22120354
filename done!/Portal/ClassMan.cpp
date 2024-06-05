#include "ClassMan.h"
#include<fstream>
#include"ClassView.h"
#include"Create.h"
ClassMan::ClassMan(Data* data) : _data(data), size(0) , _exitfocus(0) , _exitselected(0), _createfocus(0), _createselected(0)
{

}
ClassMan::~ClassMan()
{

}
void ClassMan::Init()
{
	_title.setFont(_data->_assets->GetFont(LIGHT));
	_title.setString("Class view");
	_title.setPosition(0 , 0);
	_title.setCharacterSize(40);
	_title.setFillColor(sf::Color::Black);
	std::ifstream f("buffer.txt");
	std::string get;
	getline(f, get);
	_tmp = get;
	f.close();
	std::ifstream file("Manage\\" + get + ".txt");
	
	int movex = 0, movey = 0; 
	while (!file.eof())
	{
		getline(file, get);
		if (get.empty())
		{
			continue;
		}
		_getclass[size] = get;
		_class[size].setFont(_data->_assets->GetFont(LIGHT));
		_class[size].setFillColor(sf::Color::Red);
		_class[size].setCharacterSize(25);
		_class[size].setString("*" + get);
		_class[size].setPosition(movex * 50 + 100, movey * 50 + 100);
		movey++;
		if (_class[size].getPosition().y > 500)
		{
			movex++;
			movey = 0;
		}
		size++;
	}
	file.close();
	
	memset(_classfocus, 0, 100);
	memset(_classselected, 0, 100);

	_exitbutton.setSize(sf::Vector2f(300, 40));
    _exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 250);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("Back");
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 240);
	_exit.setFillColor(sf::Color::Black);
	
	_createbox.setSize(sf::Vector2f(300, 40));
    _createbox.setFillColor(sf::Color(40, 116, 166, 240));
	_createbox.setOrigin(sf::Vector2f(_createbox.getGlobalBounds().width / 2, _createbox.getGlobalBounds().height / 2));
	_createbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 190);

	_create.setFont(_data->_assets->GetFont(KANIT));
	_create.setCharacterSize(25);
	_create.setString("Create new class");
	_create.setPosition(_data->_window->getSize().x / 2 - 110, _data->_window->getSize().y / 2 + 170);
	_create.setFillColor(sf::Color::White);
}
void ClassMan::ProcessInput()
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
				_classfocus[i] = (_class[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			}
			
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_exitselected = (_exitfocus ? 1 : 0);
			_createselected = (_createfocus ? 1 : 0);
			for (int i = 0; i < size; i++)
			{
				_classselected[i] = (_classfocus[i] ? 1 : 0);
			}
		}
	}
}
void ClassMan::Update()
{
        (_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100))
                    : _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
        (_createfocus ? _createbox.setFillColor(sf::Color(40, 116, 166, 100))
                      : _createbox.setFillColor(sf::Color(40, 116, 166, 240)));
	for (int i = 0; i < size; i++)
	{
		(_classfocus[i] ? _class[i].setFillColor(sf::Color::Blue) : _class[i].setFillColor(sf::Color::Red));
	}
	for (int i = 0; i < size; i++)
	{
		if (_classselected[i])
		{
			std::ofstream file("buffer.txt");
			file << _tmp;
			file << std::endl << _getclass[i];
			file.close();
			_data->_states->AddState(new ClassView(_data)) ;
			_classselected[i] = 0;
		}
	}
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;
	}
	if (_createselected)
	{
		_data->_states->AddState(new Create(_data));
		_createselected = 0;
	}
}
void ClassMan::Draw()
{
	
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_title);
	for (int i = 0; i < size; i++)
	{
		_data->_window->draw(_class[i]);
	}
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_exit);
	_data->_window->draw(_createbox);
	_data->_window->draw(_create);
	_data->_window->display();
}