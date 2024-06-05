#include "Staff.h"
#include"AccountHandle.h"
#include"ChangePass.h"
#include"SchoolYear.h"
#include"Semester.h"

Staff::Staff(Data* data) : _data(data) , _logoutfocus(0) , _logoutselected(0) , _changepassfocus(0) , _changepassselected(0) , _studentfocus(0),
_studentselected(0)  , _coursefocus(0) , _courseselected(0) 
{

}
Staff::~Staff()
{

}
void Staff::Init()
{ 
	_data->_assets->AddFont(LIGHT, "Asset\\Light.ttf");


	_username.setFont(_data->_assets->GetFont(LIGHT));
	_username.setPosition(100, 20);
	std::ifstream file("username.txt");
	getline(file, username);
	file.clear();
	file.close();
	_username.setString("Hello , " + username);
	_username.setFillColor(sf::Color::Black);

	_logout.setCharacterSize(20);
	_logout.setFont(_data->_assets->GetFont(LIGHT));
	_logout.setPosition(_data->_window->getSize().x - 190, 20);
	_logout.setString("Logout");
	_logout.setFillColor(sf::Color::Red);

	_changepass.setCharacterSize(20);
	_changepass.setFont(_data->_assets->GetFont(LIGHT));
	_changepass.setPosition(_data->_window->getSize().x - 190, 50);
	_changepass.setString("Change password");
	_changepass.setFillColor(sf::Color::Red);

	_studentbox.setSize(sf::Vector2f(400, 60));
	_studentbox.setFillColor(sf::Color::White);
	_studentbox.setOrigin(sf::Vector2f(_studentbox.getGlobalBounds().width / 2, _studentbox.getGlobalBounds().height / 2));
	_studentbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 100);

	_student.setFont(_data->_assets->GetFont(LIGHT));
	_student.setString("Student management");
	_student.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 120);
	_student.setFillColor(sf::Color::Black);

	_coursebox.setSize(sf::Vector2f(400, 60));
	_coursebox.setFillColor(sf::Color::White);
	_coursebox.setOrigin(sf::Vector2f(_studentbox.getGlobalBounds().width / 2, _studentbox.getGlobalBounds().height / 2));
	_coursebox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);

	_course.setFont(_data->_assets->GetFont(LIGHT));
	_course.setString("Course management");
	_course.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 20);
	_course.setFillColor(sf::Color::Black);

}
void Staff::ProcessInput()
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
			_logoutfocus = (_logout.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_changepassfocus = (_changepass.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_studentfocus = (_studentbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_coursefocus = (_coursebox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_logoutselected = (_logoutfocus ? 1 : 0);
			_changepassselected = (_changepassfocus ? 1 : 0);
			_studentselected = (_studentfocus ? 1 : 0);
			_courseselected = (_coursefocus ? 1 : 0);
		}
	}
}
void Staff::Update()
{
	(_logoutfocus ? _logout.setFillColor(sf::Color::Blue) : _logout.setFillColor(sf::Color::Red));
	(_changepassfocus ? _changepass.setFillColor(sf::Color::Blue) : _changepass.setFillColor(sf::Color::Red));
	(_studentfocus ? _studentbox.setFillColor(sf::Color::Yellow) : _studentbox.setFillColor(sf::Color::White));
	(_coursefocus ? _coursebox.setFillColor(sf::Color::Yellow) : _coursebox.setFillColor(sf::Color::White));
	
	if (_logoutselected)
	{
		_data->_states->RemoveState();
		_logoutselected = 0;
	}
	if(_changepassselected)
	{
		std::ofstream file("username.txt");
		file << username;
		_changepassselected = 0;
		_data->_states->AddState(new ChangePass(_data));
	}
	
	if (_studentselected)
	{
		_data->_states->AddState(new SchoolYear(_data));
		_studentselected = 0;
	}

	if (_courseselected)
	{
		_data->_states->AddState(new Semester(_data));
		_courseselected = 0;
	}
}
void Staff::Draw()
{
	_data->_window->clear(sf::Color::Cyan);
	_data->_window->draw(_username);
	_data->_window->draw(_logout);
	_data->_window->draw(_changepass);
	_data->_window->draw(_studentbox);
	_data->_window->draw(_student);
	_data->_window->draw(_coursebox);
	_data->_window->draw(_course);
	
	_data->_window->display();
}
