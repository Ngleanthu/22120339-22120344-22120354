#include "NotStaff.h"
#include"AccountHandle.h"
#include"ChangePass.h"
#include"StudentInfo.h"
#include"CourseMan.h"
#include"ScoreView.h"
NotStaff::NotStaff(Data* data) : _data(data), _logoutfocus(0), _logoutselected(0), _changepassfocus(0), _changepassselected(0), _studentfocus(0),
_studentselected(0), _coursefocus(0), _courseselected(0), _scorefocus(0), _scoreselected(0)
{

}
NotStaff::~NotStaff()
{

}
void NotStaff::Init()
{
	_data->_assets->AddFont(LIGHT, "Asset\\Light.ttf");
	_data->_assets->AddTexture(STU_PROFILE_PIC, "Asset\\blue-profile.png");
	
	_background.setSize(sf::Vector2f(800, 900));
	_background.setPosition(0.0f, 0.0f);
	_background.setFillColor(sf::Color::White);

	_profilepic.setTexture(_data->_assets->GetTexture(STU_PROFILE_PIC));
	_profilepic.setScale(0.18f, 0.18f);
	_profilepic.setOrigin(sf::Vector2f(_profilepic.getGlobalBounds().width / 2, _profilepic.getGlobalBounds().height / 2));
	_profilepic.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 100.0f, _background.getGlobalBounds().height / 2 - 390.0f));

	//_studentbox.setSize(sf::Vector2f(400, 60));
	//_studentbox.setFillColor(sf::Color::White);
	//_studentbox.setOrigin(sf::Vector2f(_studentbox.getGlobalBounds().width / 2, _studentbox.getGlobalBounds().height / 2));
	//_studentbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 100);

	//_student.setFont(_data->_assets->GetFont(LIGHT));
	//_student.setString("Student Profile");
	//_student.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 120);
	//_student.setFillColor(sf::Color::Black);


	_id.setFont(_data->_assets->GetFont(LIGHT));
	_id.setString("ID: ");
	_id.setCharacterSize(22);
	_id.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f, _background.getGlobalBounds().height / 2 - 145.0f));
	_id.setFillColor(sf::Color::Black);

	_firstname.setFont(_data->_assets->GetFont(LIGHT));
	_firstname.setString("FIRST NAME: ");
	_firstname.setCharacterSize(22);
	_firstname.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f, _background.getGlobalBounds().height / 2 - 55.0f));
	_firstname.setFillColor(sf::Color::Black);

	_lastname.setFont(_data->_assets->GetFont(LIGHT));
	_lastname.setString("LAST NAME: ");
	_lastname.setCharacterSize(22);
	_lastname.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f, _background.getGlobalBounds().height / 2 + 35.0f));
	_lastname.setFillColor(sf::Color::Black);

	_gender.setFont(_data->_assets->GetFont(LIGHT));
	_gender.setString("GENDER: ");
	_gender.setCharacterSize(22);
	_gender.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f, _background.getGlobalBounds().height / 2 + 125.0f));
	_gender.setFillColor(sf::Color::Black);

	_dob.setFont(_data->_assets->GetFont(LIGHT));
	_dob.setString("DATE OF BIRTH: ");
	_dob.setCharacterSize(22);
	_dob.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f, _background.getGlobalBounds().height / 2 + 215.0f));
	_dob.setFillColor(sf::Color::Black);

	_socialID.setFont(_data->_assets->GetFont(LIGHT));
	_socialID.setString("SOCIAL ID: ");
	_socialID.setCharacterSize(22);
	_socialID.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f, _background.getGlobalBounds().height / 2 + 305.0f));
	_socialID.setFillColor(sf::Color::Black);

	_idbox.setSize(sf::Vector2f(350.0f, 50.0f));
	_idbox.setFillColor(sf::Color(214, 219, 223, 240));
	_idbox.setOrigin(sf::Vector2f(_idbox.getGlobalBounds().width / 2, _idbox.getGlobalBounds().height / 2));
	_idbox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2, _background.getGlobalBounds().height / 2 - 90.0f));

	_firstnamebox.setSize(sf::Vector2f(350.0f, 50.0f));
	_firstnamebox.setFillColor(sf::Color(214, 219, 223, 240));
	_firstnamebox.setOrigin(sf::Vector2f(_firstnamebox.getGlobalBounds().width / 2, _firstnamebox.getGlobalBounds().height / 2));
	_firstnamebox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2, _background.getGlobalBounds().height / 2));

	_lastnamebox.setSize(sf::Vector2f(350.0f, 50.0f));
	_lastnamebox.setFillColor(sf::Color(214, 219, 223, 240));
	_lastnamebox.setOrigin(sf::Vector2f(_lastnamebox.getGlobalBounds().width / 2, _lastnamebox.getGlobalBounds().height / 2));
	_lastnamebox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2, _background.getGlobalBounds().height / 2 + 90.0f));

	_genderbox.setSize(sf::Vector2f(350.0f, 50.0f));
	_genderbox.setFillColor(sf::Color(214, 219, 223, 240));
	_genderbox.setOrigin(sf::Vector2f(_genderbox.getGlobalBounds().width / 2, _genderbox.getGlobalBounds().height / 2));
	_genderbox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2, _background.getGlobalBounds().height / 2 + 180.0f));

	_dobbox.setSize(sf::Vector2f(350.0f, 50.0f));
	_dobbox.setFillColor(sf::Color(214, 219, 223, 240));
	_dobbox.setOrigin(sf::Vector2f(_dobbox.getGlobalBounds().width / 2, _dobbox.getGlobalBounds().height / 2));
	_dobbox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2, _background.getGlobalBounds().height / 2 + 270.0f));

	_socialIDbox.setSize(sf::Vector2f(350.0f, 50.0f));
	_socialIDbox.setFillColor(sf::Color(214, 219, 223, 240));
	_socialIDbox.setOrigin(sf::Vector2f(_socialIDbox.getGlobalBounds().width / 2, _socialIDbox.getGlobalBounds().height / 2));
	_socialIDbox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2, _background.getGlobalBounds().height / 2 + 360.0f));

	_coursebox.setSize(sf::Vector2f(400.0f, 70.0f));
	_coursebox.setFillColor(sf::Color(40, 116, 166, 240));
	_coursebox.setPosition(sf::Vector2f(1000.0f, _background.getGlobalBounds().height / 2 - 150.0f));

	_scorebox.setSize(sf::Vector2f(400.0f, 70.0f));
	_scorebox.setFillColor(sf::Color(40, 116, 166, 240));  
	_scorebox.setPosition(sf::Vector2f(1000.0f, _background.getGlobalBounds().height / 2 - 40.0f));

	_changepassbox.setSize(sf::Vector2f(400.0f, 70.0f));
	_changepassbox.setFillColor(sf::Color(40, 116, 166, 240));
	_changepassbox.setPosition(sf::Vector2f(1000.0f, _background.getGlobalBounds().height / 2 + 70.0f));

	_course.setFont(_data->_assets->GetFont(KANIT));
	_course.setString("VIEW COURSE");
	_course.setCharacterSize(30);
	sf::FloatRect text_rect = _course.getLocalBounds();
	_course.setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2.0f);
	_course.setPosition(sf::Vector2f(1200.0f, _background.getGlobalBounds().height / 2 - 115.0f));
	_course.setFillColor(sf::Color::White);

	_score.setFont(_data->_assets->GetFont(KANIT));
	_score.setString("VIEW SCORE");
	_score.setCharacterSize(30);
	sf::FloatRect score_rect = _score.getLocalBounds();
	_score.setOrigin(score_rect.left + score_rect.width / 2.0f, score_rect.top + score_rect.height / 2.0f);
	_score.setPosition(sf::Vector2f(1200.0f, _background.getGlobalBounds().height / 2 - 5.0f));
	_score.setFillColor(sf::Color::White);

	_changepass.setFont(_data->_assets->GetFont(KANIT));
	_changepass.setString("CHANGE PASSWORD");
	_changepass.setCharacterSize(30);
	sf::FloatRect change_rect = _changepass.getLocalBounds();
	_changepass.setOrigin(change_rect.left + change_rect.width / 2.0f, change_rect.top + change_rect.height / 2.0f);
	_changepass.setPosition(sf::Vector2f(1200.0f, _background.getGlobalBounds().height / 2 + 105.0f));
	_changepass.setFillColor(sf::Color::White);

	std::ifstream f("Studentbuf.txt");
	getline(f, tmp);
	f.close();
	std::ifstream file("Student\\" + tmp + ".txt");
	std::string get;
	getline(file, get, ',');
	for (int l = 0; l < 5; l++)
	{
		getline(file, get, ',');
		_info[l].setFont(_data->_assets->GetFont(CHIVOMONO_REGULAR));
		_info[l].setString(get);
		_info[l].setStyle(sf::Text::Italic);
		_info[l].setCharacterSize(28);
		_info[l].setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 165.0f, _background.getGlobalBounds().height / 2 - 105.0f + l * 90.0f));
		_info[l].setFillColor(sf::Color::Black);
	}
	getline(file, get);
	_info[5].setFont(_data->_assets->GetFont(CHIVOMONO_REGULAR));
	_info[5].setString(get);
	_info[5].setStyle(sf::Text::Italic);
	_info[5].setCharacterSize(28);
	_info[5].setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 165.0f, _background.getGlobalBounds().height / 2 - 105.0f + 5 * 90.0f));
	_info[5].setFillColor(sf::Color::Black);

	_info[0].setString(_info[0].getString());
	_info[1].setString(_info[1].getString());
	_info[2].setString(_info[2].getString());
	_info[3].setString(_info[3].getString());
	_info[4].setString(_info[4].getString());
	_info[5].setString(_info[5].getString());

	_logoutbox.setSize(sf::Vector2f(150.0f, 50.0f));
	_logoutbox.setFillColor(sf::Color(214, 219, 223, 240));
	_logoutbox.setOrigin(sf::Vector2f(_logoutbox.getGlobalBounds().width / 2, _logoutbox.getGlobalBounds().height / 2));
	_logoutbox.setPosition(sf::Vector2f(1200.0f, _background.getGlobalBounds().height / 2 + 340.0f));

	_logout.setCharacterSize(23);
	_logout.setFont(_data->_assets->GetFont(KANIT));
	_logout.setString("Log Out");
	sf::FloatRect logout_rect = _logout.getLocalBounds();
	_logout.setOrigin(logout_rect.left + logout_rect.width / 2.0f, logout_rect.top + logout_rect.height / 2.0f);
	_logout.setPosition(sf::Vector2f(1200.0f, _background.getGlobalBounds().height / 2 + 340.0f));
	_logout.setFillColor(sf::Color::Black);
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
			_logoutfocus = (_logoutbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_changepassfocus = (_changepassbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
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
	(_logoutfocus ? _logoutbox.setFillColor(sf::Color(214, 219, 223, 100)) : _logoutbox.setFillColor(sf::Color(214, 219, 223, 240)));
	(_changepassfocus ? _changepassbox.setFillColor(sf::Color(40, 116, 166, 100)) : _changepassbox.setFillColor(sf::Color(40, 116, 166, 240)));
	(_studentfocus ? _studentbox.setFillColor(sf::Color::Yellow) : _studentbox.setFillColor(sf::Color::White));
	(_coursefocus ? _coursebox.setFillColor(sf::Color(40, 116, 166, 100)) : _coursebox.setFillColor(sf::Color(40, 116, 166, 240)));
	(_scorefocus ? _scorebox.setFillColor(sf::Color(40, 116, 166, 100)) : _scorebox.setFillColor(sf::Color(40, 116, 166, 240)));
	if (_logoutselected)
	{
		std::ofstream file("Studentbuf.txt");
		file.clear();
		file.close();
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
	_data->_window->clear(sf::Color(133, 193, 233, 255));
	_data->_window->draw(_background);
	_data->_window->draw(_profilepic);
	_data->_window->draw(_username);
	//_data->_window->draw(_studentbox);
	_data->_window->draw(_firstnamebox);
	_data->_window->draw (_lastnamebox);
	_data->_window->draw(_genderbox);
	_data->_window->draw(_idbox);
	_data->_window->draw(_dobbox);
	_data->_window->draw(_socialIDbox);
	_data->_window->draw(_id);
	_data->_window->draw(_firstname);
	_data->_window->draw(_lastname);
	_data->_window->draw(_gender);
	_data->_window->draw(_dob);
	_data->_window->draw(_socialID);
	//_data->_window->draw(_student);
	_data->_window->draw(_coursebox);
	_data->_window->draw(_course);
	_data->_window->draw(_scorebox);
	_data->_window->draw(_score);
	_data->_window->draw(_changepassbox);
	_data->_window->draw(_changepass);
	for (int i = 0; i < 6; i++)
	{
		_data->_window->draw(_info[i]);
	}
	_data->_window->draw(_logoutbox);
	_data->_window->draw(_logout);
	_data->_window->display();
}
