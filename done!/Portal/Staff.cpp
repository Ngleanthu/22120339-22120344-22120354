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
    _data->_assets->AddTexture(SCHOOL_LOGO, "Asset\\school_background.jpg");

	_background.setSize(sf::Vector2f(2000, 2000));
    _background.setPosition(0.0f, 0.0f);
    _background.setFillColor(sf::Color::White);

	_schoolbackground.setTexture(_data->_assets->GetTexture(SCHOOL_LOGO));
    _schoolbackground.setScale(0.66f, 0.69f);
	_schoolbackground.setPosition(sf::Vector2f(0.0f, 0.0f));

	_username.setFont(_data->_assets->GetFont(LIGHT));
	_username.setPosition(100, 20);
	std::ifstream file("username.txt");
	getline(file, username);
	file.clear();
	file.close();
	_username.setString("Hello , " + username);
	_username.setFillColor(sf::Color::Black);

	_logoutbox.setSize(sf::Vector2f(200.0f, 40.0f));
    _logoutbox.setFillColor(sf::Color(214, 219, 223, 240));
	_logoutbox.setOrigin(sf::Vector2f(_logoutbox.getGlobalBounds().width / 2, _logoutbox.getGlobalBounds().height / 2));
	_logoutbox.setPosition(sf::Vector2f(_data->_window->getSize().x - 120.0f, 90.0f));

    _logout.setFont(_data->_assets->GetFont(KANIT));
	_logout.setString("Log Out");
	sf::FloatRect textbox = _logout.getLocalBounds();
	_logout.setOrigin(textbox.left + textbox.width / 2.0f, textbox.top + textbox.height / 2.0f);
	_logout.setPosition(sf::Vector2f(_data->_window->getSize().x - 120.0f, 95.0f));
	_logout.setCharacterSize(23);
	_logout.setFillColor(sf::Color::Black);


	_changepassbox.setSize(sf::Vector2f(200.0f, 40.0f));
    _changepassbox.setFillColor(sf::Color(40, 116, 166, 240));
	_changepassbox.setOrigin(sf::Vector2f(_changepassbox.getGlobalBounds().width / 2, _changepassbox.getGlobalBounds().height / 2));
	_changepassbox.setPosition(sf::Vector2f(_data->_window->getSize().x - 120.0f, 40.0f));

	_changepass.setCharacterSize(23);
    _changepass.setFont(_data->_assets->GetFont(KANIT));
	_changepass.setString("Change password");
	textbox = _changepass.getLocalBounds();
	_changepass.setOrigin(textbox.left + textbox.width / 2.0f, textbox.top + textbox.height / 2.0f);
	_changepass.setPosition(sf::Vector2f(_data->_window->getSize().x - 120.0f, 45.0f));
	_changepass.setFillColor(sf::Color::White);

	_studentbox.setSize(sf::Vector2f(400, 60));
    _studentbox.setFillColor(sf::Color(40, 116, 166, 240));
	_studentbox.setOrigin(sf::Vector2f(_studentbox.getGlobalBounds().width / 2, _studentbox.getGlobalBounds().height / 2));
	_studentbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 370.0f);

	_student.setFont(_data->_assets->GetFont(KANIT));
	_student.setString("STUDENT MANAGEMENT");
	sf::FloatRect mangage_rect = _student.getLocalBounds();
	_student.setOrigin(mangage_rect.left + mangage_rect.width / 2.0f, mangage_rect.top + mangage_rect.height / 2.0f);
	_student.setPosition(sf::Vector2f(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 370.0f));
	_student.setFillColor(sf::Color::White);

	_coursebox.setSize(sf::Vector2f(400, 60));
    _coursebox.setFillColor(sf::Color(40, 116, 166, 240));
	_coursebox.setOrigin(sf::Vector2f(_studentbox.getGlobalBounds().width / 2, _studentbox.getGlobalBounds().height / 2));
	_coursebox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 300);

	_course.setFont(_data->_assets->GetFont(KANIT));
	_course.setString("COURSE MANAGEMENT");
	mangage_rect = _course.getLocalBounds();
	_course.setOrigin(mangage_rect.left + mangage_rect.width / 2.0f, mangage_rect.top + mangage_rect.height / 2.0f);
	_course.setPosition(sf::Vector2f(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 300.0f));
	_course.setFillColor(sf::Color::White);

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
			_logoutfocus = (_logoutbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_changepassfocus = (_changepassbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
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
    (_logoutfocus ? _logoutbox.setFillColor(sf::Color(214, 219, 223, 100)) : _logoutbox.setFillColor(sf::Color(214, 219, 223, 240)));
    (_changepassfocus ? _changepassbox.setFillColor(sf::Color(40, 116, 166, 100)) : _changepassbox.setFillColor(sf::Color(40, 116, 166, 240)));
    (_studentfocus ? _studentbox.setFillColor(sf::Color(40, 116, 166, 100)) : _studentbox.setFillColor(sf::Color(40, 116, 166, 240)));
    (_coursefocus ? _coursebox.setFillColor(sf::Color(40, 116, 166, 100)) : _coursebox.setFillColor(sf::Color(40, 116, 166, 240)));
                     
                       
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
    _data->_window->draw(_background);
	_data->_window->draw(_username);
    _data->_window->draw(_schoolbackground);
    _data->_window->draw(_logoutbox);
	_data->_window->draw(_logout);
    _data->_window->draw(_changepassbox);
	_data->_window->draw(_changepass);
	_data->_window->draw(_studentbox);
	_data->_window->draw(_student);
	_data->_window->draw(_coursebox);
	_data->_window->draw(_course);
	_data->_window->display();
}
