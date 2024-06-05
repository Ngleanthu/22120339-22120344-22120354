#include "NotStaff.h"
#include"AccountHandle.h"
#include"ChangePass.h"
#include"StudentInfo.h"
#include"CourseMan.h"
#include"ScoreView.h"
NotStaff::NotStaff(Data* data) : _data(data), _logoutfocus(0), _logoutselected(0), _changepassfocus(0), _changepassselected(0), _studentfocus(0),
_studentselected(0), _coursefocus(0), _courseselected(0)
{

}
NotStaff::~NotStaff()
{

}
void NotStaff::Init()
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
	_student.setString("Student Profile");
	_student.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 120);
	_student.setFillColor(sf::Color::Black);

	_coursebox.setSize(sf::Vector2f(400, 60));
	_coursebox.setFillColor(sf::Color::White);
	_coursebox.setOrigin(sf::Vector2f(_studentbox.getGlobalBounds().width / 2, _studentbox.getGlobalBounds().height / 2));
	_coursebox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);

	_course.setFont(_data->_assets->GetFont(LIGHT));
	_course.setString("Course View");
	_course.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 20);
	_course.setFillColor(sf::Color::Black);

	_scorebox.setSize(sf::Vector2f(400, 60));
	_scorebox.setFillColor(sf::Color::White);
	_scorebox.setOrigin(sf::Vector2f(_studentbox.getGlobalBounds().width / 2, _studentbox.getGlobalBounds().height / 2));
	_scorebox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2  + 100);

	_score.setFont(_data->_assets->GetFont(LIGHT));
	_score.setString("Score View");
	_score.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 80);
	_score.setFillColor(sf::Color::Black);
}
void NotStaff::ProcessInput()
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
			_scorefocus = (_scorebox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_logoutselected = (_logoutfocus ? 1 : 0);
			_changepassselected = (_changepassfocus ? 1 : 0);
			_studentselected = (_studentfocus ? 1 : 0);
			_courseselected = (_coursefocus ? 1 : 0);
			_scoreselected = (_scorefocus ? 1 : 0);
		}
	}
}
void NotStaff::Update()
{
	(_logoutfocus ? _logout.setFillColor(sf::Color::Blue) : _logout.setFillColor(sf::Color::Red));
	(_changepassfocus ? _changepass.setFillColor(sf::Color::Blue) : _changepass.setFillColor(sf::Color::Red));
	(_studentfocus ? _studentbox.setFillColor(sf::Color::Yellow) : _studentbox.setFillColor(sf::Color::White));
	(_coursefocus ? _coursebox.setFillColor(sf::Color::Yellow) : _coursebox.setFillColor(sf::Color::White));
	(_scorefocus ? _scorebox.setFillColor(sf::Color::Yellow) : _scorebox.setFillColor(sf::Color::White));
	if (_logoutselected)
	{
		_data->_states->RemoveState();
		_logoutselected = 0;
	}
	if (_changepassselected)
	{
		std::ofstream file("username.txt");
		file << username;
		_changepassselected = 0;
		_data->_states->AddState(new ChangePass(_data));
	}

	if (_studentselected)
	{
		std::ofstream file("Studentbuf.txt");
		file << username;
		file.close();
		_data->_states->AddState(new StudentInfo(_data));
		_studentselected = 0;
	}

	if (_courseselected)
	{
		std::ofstream file("Studentbuf.txt");
		file << username;
		file.close();
		_data->_states->AddState(new StudentCourse(_data));
		_courseselected = 0;
	}
	if (_scoreselected)
	{
		std::ofstream file("Studentbuf.txt");
		file << username;
		file.close();
		_data->_states->AddState(new ScoreView1(_data));
		_scoreselected = 0;
	}
}
void NotStaff::Draw()
{
	_data->_window->clear(sf::Color::Cyan);
	_data->_window->draw(_username);
	_data->_window->draw(_logout);
	_data->_window->draw(_changepass);
	_data->_window->draw(_studentbox);
	_data->_window->draw(_student);
	_data->_window->draw(_coursebox);
	_data->_window->draw(_course);
	_data->_window->draw(_scorebox);
	_data->_window->draw(_score);
	_data->_window->display();
}
