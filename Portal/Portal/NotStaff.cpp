#include "NotStaff.h"
#include <iostream>
#include "AccountHandle.h"
#include "ChangePass.h"
#include "Semester.h"
NotStaff::NotStaff(Data *data)
    : _data(data),
      _logoutfocus(0),
      _logoutselected(0),
      _changepassfocus(0),
      _changepassselected(0) /*, _studentfocus(0),
_studentselected(0), _coursefocus(0), _courseselected(0)*/
{}
NotStaff::~NotStaff() {}
void NotStaff::Init()
{
    _data->_assets->AddFont(LIGHT, "Asset\\Light.ttf");
    _data->_assets->AddTexture(STU_PROFILE_PIC, "Asset\\blue-profile.png");

    _background.setSize(sf::Vector2f(800, 900));
    _background.setPosition(0.0f, 0.0f);
    _background.setFillColor(sf::Color::White);

    _profilepic.setTexture(_data->_assets->GetTexture(STU_PROFILE_PIC));
    _profilepic.setScale(0.2f, 0.2f);
    _profilepic.setOrigin(sf::Vector2f(_profilepic.getGlobalBounds().width / 2,
                                       _profilepic.getGlobalBounds().height / 2));
    _profilepic.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 100.0f,
                                         _background.getGlobalBounds().height / 2 - 400.0f));

    _username.setFont(_data->_assets->GetFont(HELVETICA_BOLD));
    _username.setPosition(100, 20);
    std::ifstream file("username.txt");
    getline(file, username, ',');

    std::string tmp;
    std::ifstream fin("Student\\" + username + ".txt");
    getline(fin, tmp, ',');
    getline(fin, tmp, ',');

    getline(file, username);
    file.close();
    _username.setString(username);
    sf::FloatRect textRect = _username.getLocalBounds();
    _username.setOrigin(textRect.left + textRect.width / 2.0f,
                        textRect.top + textRect.height / 2.0f);
    _username.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2,
                                       _background.getGlobalBounds().height / 2 - 150.0f));
    _username.setFillColor(sf::Color::Black);

    _idbox.setSize(sf::Vector2f(350.0f, 50.0f));
    _idbox.setFillColor(sf::Color(214, 219, 223, 240));
    _idbox.setOrigin(
        sf::Vector2f(_idbox.getGlobalBounds().width / 2, _idbox.getGlobalBounds().height / 2));
    _idbox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2,
                                    _background.getGlobalBounds().height / 2 - 80.0f));

    _genderbox.setSize(sf::Vector2f(350.0f, 50.0f));
    _genderbox.setFillColor(sf::Color(214, 219, 223, 240));
    _genderbox.setOrigin(sf::Vector2f(_genderbox.getGlobalBounds().width / 2,
                                      _genderbox.getGlobalBounds().height / 2));
    _genderbox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2,
                                        _background.getGlobalBounds().height / 2 + 10.0f));

    _dobBox.setSize(sf::Vector2f(350.0f, 50.0f));
    _dobBox.setFillColor(sf::Color(214, 219, 223, 240));
    _dobBox.setOrigin(
        sf::Vector2f(_dobBox.getGlobalBounds().width / 2, _dobBox.getGlobalBounds().height / 2));
    _dobBox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2,
                                     _background.getGlobalBounds().height / 2 + 100.0f));

    _socialIDbox.setSize(sf::Vector2f(350.0f, 50.0f));
    _socialIDbox.setFillColor(sf::Color(214, 219, 223, 240));
    _socialIDbox.setOrigin(sf::Vector2f(_socialIDbox.getGlobalBounds().width / 2,
                                        _socialIDbox.getGlobalBounds().height / 2));
    _socialIDbox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2,
                                          _background.getGlobalBounds().height / 2 + 190.0f));

    _classbox.setSize(sf::Vector2f(350.0f, 50.0f));
    _classbox.setFillColor(sf::Color(214, 219, 223, 240));
    _classbox.setOrigin(sf::Vector2f(_classbox.getGlobalBounds().width / 2,
                                     _classbox.getGlobalBounds().height / 2));
    _classbox.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2,
                                       _background.getGlobalBounds().height / 2 + 280.0f));

    _viewCourseBox.setSize(sf::Vector2f(400.0f, 70.0f));
    _viewCourseBox.setFillColor(sf::Color(40, 116, 166, 240));
    _viewCourseBox.setPosition(
        sf::Vector2f(1000.0f, _background.getGlobalBounds().height / 2 - 150.0f));

    _viewScoreBox.setSize(sf::Vector2f(400.0f, 70.0f));
    _viewScoreBox.setFillColor(sf::Color(40, 116, 166, 240));
    _viewScoreBox.setPosition(
        sf::Vector2f(1000.0f, _background.getGlobalBounds().height / 2 - 30.0f));

    _logout.setCharacterSize(20);
    _logout.setFont(_data->_assets->GetFont(HELVETICA_BOLD));
    _logout.setPosition(_data->_window->getSize().x - 1500, 850);
    _logout.setString("LOG OUT");
    _logout.setFillColor(sf::Color::Red);

    _changepass.setCharacterSize(20);
    _changepass.setFont(_data->_assets->GetFont(HELVETICA_BOLD));
    _changepass.setPosition(_data->_window->getSize().x - 1500, 800);
    _changepass.setString("CHANGE PASSWORD");
    _changepass.setFillColor(sf::Color::Red);

    _id.setFont(_data->_assets->GetFont(LIGHT));
    _id.setString("ID: ");
    _id.setCharacterSize(24);
    _id.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f,
                                 _background.getGlobalBounds().height / 2 - 135.0f));
    _id.setFillColor(sf::Color::Black);

    id.setFont(_data->_assets->GetFont(LIGHT));
    id.setString(tmp);
    id.setCharacterSize(24);
    id.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f,
                                _background.getGlobalBounds().height / 2 - 95.0f));
    id.setFillColor(sf::Color::Red);

    getline(fin, tmp, ',');
    getline(fin, tmp, ',');
    getline(fin, tmp, ',');

    _gender.setFont(_data->_assets->GetFont(LIGHT));
    _gender.setString("GENDER: ");
    _gender.setCharacterSize(24);
    _gender.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f,
                                     _background.getGlobalBounds().height / 2 - 45.0f));
    _gender.setFillColor(sf::Color::Black);

    gender.setFont(_data->_assets->GetFont(LIGHT));
    gender.setString(tmp);
    gender.setCharacterSize(24);
    gender.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f,
                                    _background.getGlobalBounds().height / 2 - 5.0f));
    gender.setFillColor(sf::Color::Red);

    getline(fin, tmp, ',');

    _dob.setFont(_data->_assets->GetFont(LIGHT));
    _dob.setString("DATE OF BIRTH: ");
    _dob.setCharacterSize(24);
    _dob.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f,
                                  _background.getGlobalBounds().height / 2 + 45.0f));
    _dob.setFillColor(sf::Color::Black);

    dob.setFont(_data->_assets->GetFont(LIGHT));
    dob.setString(tmp);
    dob.setCharacterSize(24);
    dob.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f,
                                 _background.getGlobalBounds().height / 2 + 85.0f));
    dob.setFillColor(sf::Color::Red);

    getline(fin, tmp, '\n');

    _socialID.setFont(_data->_assets->GetFont(LIGHT));
    _socialID.setString("SOCIAL ID: ");
    _socialID.setCharacterSize(24);
    _socialID.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f,
                                       _background.getGlobalBounds().height / 2 + 135.0f));
    _socialID.setFillColor(sf::Color::Black);

    socialID.setFont(_data->_assets->GetFont(LIGHT));
    socialID.setString(tmp);
    socialID.setCharacterSize(24);
    socialID.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f,
                                      _background.getGlobalBounds().height / 2 + 175.0f));
    socialID.setFillColor(sf::Color::Red);

    getline(fin, tmp, '\n');
    fin.close();

    _class.setFont(_data->_assets->GetFont(LIGHT));
    _class.setString("CLASS: ");
    _class.setCharacterSize(24);
    _class.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f,
                                    _background.getGlobalBounds().height / 2 + 225.0f));
    _class.setFillColor(sf::Color::Black);

    str_class.setFont(_data->_assets->GetFont(LIGHT));
    str_class.setString(tmp);
    str_class.setCharacterSize(24);
    str_class.setPosition(sf::Vector2f(_background.getGlobalBounds().width / 2 - 175.0f,
                                       _background.getGlobalBounds().height / 2 + 265.0f));
    str_class.setFillColor(sf::Color::Red);

    _viewCourse.setFont(_data->_assets->GetFont(HELVETICA_BOLD));
    _viewCourse.setString("VIEW COURSE");
    _viewCourse.setCharacterSize(30);
    sf::FloatRect text_rect = _viewCourse.getLocalBounds();
    _viewCourse.setOrigin(text_rect.left + text_rect.width / 2.0f,
                          text_rect.top + text_rect.height / 2.0f);
    _viewCourse.setPosition(
        sf::Vector2f(1200.0f, _background.getGlobalBounds().height / 2 - 115.0f));
    _viewCourse.setFillColor(sf::Color::White);

    _viewScore.setFont(_data->_assets->GetFont(HELVETICA_BOLD));
    _viewScore.setString("VIEW SCORE");
    _viewScore.setCharacterSize(30);
    sf::FloatRect score_rect = _viewScore.getLocalBounds();
    _viewScore.setOrigin(score_rect.left + score_rect.width / 2.0f,
                         score_rect.top + score_rect.height / 2.0f);
    _viewScore.setPosition(sf::Vector2f(1200.0f, _background.getGlobalBounds().height / 2 + 5.0f));
    _viewScore.setFillColor(sf::Color::White);

    //_studentbox.setSize(sf::Vector2f(400, 60));
    //_studentbox.setFillColor(sf::Color::White);
    //_studentbox.setOrigin(sf::Vector2f(_studentbox.getGlobalBounds().width / 2,
    //_studentbox.getGlobalBounds().height / 2));
    //_studentbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 -
    //100);

    //_student.setFont(_data->_assets->GetFont(LIGHT));
    //_student.setString("Profile Information");
    //_student.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 -
    //120); _student.setFillColor(sf::Color::Black);

    //_coursebox.setSize(sf::Vector2f(400, 60));
    //_coursebox.setFillColor(sf::Color::White);
    //_coursebox.setOrigin(sf::Vector2f(_studentbox.getGlobalBounds().width / 2,
    //_studentbox.getGlobalBounds().height / 2)); _coursebox.setPosition(_data->_window->getSize().x
    /// 2, _data->_window->getSize().y / 2);

    //_course.setFont(_data->_assets->GetFont(LIGHT));
    //_course.setString("Course information");
    //_course.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 -
    //20); _course.setFillColor(sf::Color::Black);
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
            _logoutfocus     = (_logout.getGlobalBounds().contains(
                                sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                                 sf::Mouse::getPosition(*_data->_window).y))
                                    ? 1
                                    : 0);
            _changepassfocus = (_changepass.getGlobalBounds().contains(
                                    sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                                 sf::Mouse::getPosition(*_data->_window).y))
                                    ? 1
                                    : 0);
            /*	_studentfocus =
               (_studentbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
               sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0); _coursefocus =
               (_coursebox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
               sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);*/
            // std::cout << sf::Mouse::getPosition(*_data->_window).x << " " <<
            // sf::Mouse::getPosition(*_data->_window).y << std::endl;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            _logoutselected     = (_logoutfocus ? 1 : 0);
            _changepassselected = (_changepassfocus ? 1 : 0);
            /*_studentselected = (_studentfocus ? 1 : 0);
            _courseselected = (_coursefocus ? 1 : 0);*/
        }
    }
}
void NotStaff::Update()
{
    (_logoutfocus ? _logout.setFillColor(sf::Color::Blue) : _logout.setFillColor(sf::Color::Red));
    (_changepassfocus ? _changepass.setFillColor(sf::Color::Blue)
                      : _changepass.setFillColor(sf::Color::Red));
    /*(_studentfocus ? _studentbox.setFillColor(sf::Color::Yellow) :
    _studentbox.setFillColor(sf::Color::White));
    (_coursefocus ? _coursebox.setFillColor(sf::Color::Yellow) :
    _coursebox.setFillColor(sf::Color::White));*/

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

    /*if (_studentselected)
    {
            _data->_states->AddState(new SchoolYear(_data));
            _studentselected = 0;
    }

    if (_courseselected)
    {
            _data->_states->AddState(new Semester(_data));
            _courseselected = 0;
    }*/
}
void NotStaff::Draw()
{
    _data->_window->clear(sf::Color(133, 193, 233, 255));
    _data->_window->draw(_background);
    _data->_window->draw(_profilepic);
    _data->_window->draw(_username);
    _data->_window->draw(_logout);
    _data->_window->draw(_changepass);
    _data->_window->draw(_genderbox);
    _data->_window->draw(_classbox);
    _data->_window->draw(_idbox);
    _data->_window->draw(_socialIDbox);
    _data->_window->draw(_id);
    _data->_window->draw(id);
    _data->_window->draw(_dob);
    _data->_window->draw(_dobBox);
    _data->_window->draw(dob);
    _data->_window->draw(_class);
    _data->_window->draw(str_class);
    _data->_window->draw(_gender);
    _data->_window->draw(gender);
    _data->_window->draw(_socialID);
    _data->_window->draw(socialID);
    _data->_window->draw(_viewCourseBox);
    _data->_window->draw(_viewCourse);
    _data->_window->draw(_viewScoreBox);
    _data->_window->draw(_viewScore);
    /*_data->_window->draw(_studentbox);
    _data->_window->draw(_student);
    _data->_window->draw(_coursebox);
    _data->_window->draw(_course);*/

    _data->_window->display();
}