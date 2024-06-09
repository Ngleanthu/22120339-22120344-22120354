#include "CourseMan.h"
#include <fstream>
#include <string>
#include "AccountHandle.h"
#include "CourseView.h"
#include "Create.h"
#include "Delete.h"
CourseMan::CourseMan(Data *data)
    : _data(data),
      _exitfocus(0),
      _exitselected(0),
      _createfocus(0),
      _createselected(0),
      _deletefocus(0),
      _deleteselected(0),
      size(0)
{}
CourseMan::~CourseMan() {}
void CourseMan::Init()
{
    std::string get;
    std::ifstream f("buffer.txt");
    getline(f, get, '/');
    f.close();
    _title.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _title.setString("COURSE VIEW:");
    _title.setStyle(sf::Text::Bold);
    _title.setPosition(100, 40);
    _title.setCharacterSize(30);
    _title.setFillColor(sf::Color::Black);
    std::ifstream file("Cmanage\\" + get + ".txt");
    _tmp      = get;
    int movex = 0, movey = 0;
    while (!file.eof())
    {
        getline(file, get);
        if (get.empty())
        {
            continue;
        }

        _coursebox[size].setSize(sf::Vector2f(400.0f, 50.0f));
        _coursebox[size].setFillColor(sf::Color(40, 116, 166, 240));
        _coursebox[size].setOrigin(sf::Vector2f(_coursebox[size].getGlobalBounds().width / 2 ,_coursebox[size].getGlobalBounds().height / 2));
        _coursebox[size].setPosition(movex * 700 + 300, movey * 60 + 120);

        _getcourse[size] = get;
        _course[size].setFont(_data->_assets->GetFont(KANIT));
        _course[size].setFillColor(sf::Color::White);
        _course[size].setCharacterSize(25);
        _course[size].setString(get);
        _course[size].setOrigin(sf::Vector2f(_course[size].getGlobalBounds().width / 2 ,_course[size].getGlobalBounds().height / 2));
        _course[size].setPosition(movex * 700 + 300, movey * 60 + 110);
        movey++;
        if (_course[size].getPosition().y > 700)
        {
            movex++;
            movey = 0;
        }
        size++;
    }

    memset(_coursefocus, 0, 100);
    memset(_courseselected, 0, 100);

    _exitbutton.setSize(sf::Vector2f(300, 40));
    _exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
    _exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2,_exitbutton.getGlobalBounds().height / 2));
    _exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 350);

    _exit.setFont(_data->_assets->GetFont(KANIT));
    _exit.setString("BACK");
    _exit.setCharacterSize(25);
    _exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
    _exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 340);
    _exit.setFillColor(sf::Color::Black);

    _createbox.setSize(sf::Vector2f(300, 40));
    _createbox.setFillColor(sf::Color(40, 116, 166, 240));
    _createbox.setOrigin(sf::Vector2f(_createbox.getGlobalBounds().width / 2,_createbox.getGlobalBounds().height / 2));
    _createbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 300);

    _create.setFont(_data->_assets->GetFont(KANIT));
    _create.setCharacterSize(25);
    _create.setString("CREATE NEW COURSE");
    _create.setOrigin(sf::Vector2f(_create.getGlobalBounds().width / 2, _create.getGlobalBounds().height / 2));
    _create.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 290);
    _create.setFillColor(sf::Color::White);

    _deletebox.setSize(sf::Vector2f(300, 40));
    _deletebox.setFillColor(sf::Color(40, 116, 166, 240));
    _deletebox.setOrigin(sf::Vector2f(_createbox.getGlobalBounds().width / 2,_createbox.getGlobalBounds().height / 2));
    _deletebox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 250);

    _delete.setFont(_data->_assets->GetFont(KANIT));
    _delete.setCharacterSize(25);
    _delete.setString("DELETE COURSE");
    _delete.setOrigin(sf::Vector2f(_delete.getGlobalBounds().width / 2, _delete.getGlobalBounds().height / 2));
    _delete.setPosition(_data->_window->getSize().x / 2,_data->_window->getSize().y / 2 + 240);
    _delete.setFillColor(sf::Color::White);

    _updatebox.setSize(sf::Vector2f(300, 40));
    _updatebox.setFillColor(sf::Color(40, 116, 166, 240));
    _updatebox.setOrigin(sf::Vector2f(_createbox.getGlobalBounds().width / 2,_createbox.getGlobalBounds().height / 2));
    _updatebox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 200);

    _update.setFont(_data->_assets->GetFont(KANIT));
    _update.setCharacterSize(25);
    _update.setString("UPDATE SCORE");
    _update.setOrigin(sf::Vector2f(_update.getGlobalBounds().width / 2, _update.getGlobalBounds().height / 2));
    _update.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 190);
    _update.setFillColor(sf::Color::White);

    _status.setCharacterSize(20);
    _status.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _status.setFillColor(sf::Color::Red);
}
void CourseMan::ProcessInput()
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
            _exitfocus   = (_exitbutton.getGlobalBounds().contains(
                              sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                           sf::Mouse::getPosition(*_data->_window).y))
                                ? 1
                                : 0);
            _createfocus = (_createbox.getGlobalBounds().contains(
                                sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                             sf::Mouse::getPosition(*_data->_window).y))
                                ? 1
                                : 0);
            _deletefocus = (_deletebox.getGlobalBounds().contains(
                                sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                             sf::Mouse::getPosition(*_data->_window).y))
                                ? 1
                                : 0);
            _updatefocus = (_updatebox.getGlobalBounds().contains(
                                sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                             sf::Mouse::getPosition(*_data->_window).y))
                                ? 1
                                : 0);
            for (int i = 0; i < size; i++)
            {
                _coursefocus[i] = (_coursebox[i].getGlobalBounds().contains(
                                       sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                                    sf::Mouse::getPosition(*_data->_window).y))
                                       ? 1
                                       : 0);
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            _exitselected   = (_exitfocus ? 1 : 0);
            _createselected = (_createfocus ? 1 : 0);
            _deleteselected = (_deletefocus ? 1 : 0);
            _updateselected = (_updatefocus ? 1 : 0);
            for (int i = 0; i < size; i++)
            {
                _courseselected[i] = (_coursefocus[i] ? 1 : 0);
            }
        }
    }
}
void CourseMan::Update()
{
    (_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100))
                : _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
    (_createfocus ? _createbox.setFillColor(sf::Color(40, 116, 166, 100))
                  : _createbox.setFillColor(sf::Color(40, 116, 166, 240)));
    (_deletefocus ? _deletebox.setFillColor(sf::Color(40, 116, 166, 100))
                  : _deletebox.setFillColor(sf::Color(40, 116, 166, 240)));
    (_updatefocus ? _updatebox.setFillColor(sf::Color(40, 116, 166, 100))
                  : _updatebox.setFillColor(sf::Color(40, 116, 166, 240)));
    for (int i = 0; i < size; i++)
    {
        (_coursefocus[i] ? _coursebox[i].setFillColor(sf::Color(40, 116, 166, 100))
                         : _coursebox[i].setFillColor(sf::Color(40, 116, 166, 240)));
    }
    for (int i = 0; i < size; i++)
    {
        if (_courseselected[i])
        {
            std::ofstream file("buffer.txt");
            std::string tmp1 = _getcourse[i].substr(_getcourse[i].find("(")) + _tmp.substr(0, 1);
            file << tmp1;
            file << std::endl << _tmp;
            file.close();
            _data->_states->AddState(new CourseView(_data));
            _courseselected[i] = 0;
        }
    }
    if (_exitselected)
    {
        _data->_states->RemoveState();
        _exitselected = 0;
    }
    if (_createselected)
    {
        _data->_states->AddState(new AddCourse(_data));
        _createselected = 0;
    }
    if (_deleteselected)
    {
        _data->_states->AddState(new DeleteCourse(_data));
        _deleteselected = 0;
    }
    if (_updateselected)
    {
        update(_tmp);
        _status.setString("Update Success!");
        _status.setOrigin(sf::Vector2f(_status.getGlobalBounds().width / 2, _status.getGlobalBounds().height / 2));
        _status.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 150);
        _updateselected = 0;
    }
}
void CourseMan::Draw()
{
    _data->_window->clear(sf::Color::White);
    _data->_window->draw(_title);
    for (int i = 0; i < size; i++)
    {
        _data->_window->draw(_coursebox[i]);
        _data->_window->draw(_course[i]);
    }
    _data->_window->draw(_exitbutton);
    _data->_window->draw(_exit);
    _data->_window->draw(_createbox);
    _data->_window->draw(_create);
    _data->_window->draw(_deletebox);
    _data->_window->draw(_delete);
    _data->_window->draw(_updatebox);
    _data->_window->draw(_update);
    _data->_window->draw(_status);
    _data->_window->display();
}

StudentCourse::StudentCourse(Data *data) : _data(data), _exitfocus(0), _exitselected(0) {}
StudentCourse::~StudentCourse() {}
void StudentCourse::Init()
{
    char DefaultSemester = '1';
    std::string get;
    std::ifstream f("Studentbuf.txt");
    getline(f, get);
    f.close();
    _title.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _title.setString("MY COURSES:");
    _title.setStyle(sf::Text::Bold);
    _title.setPosition(100, 30);
    _title.setCharacterSize(30);
    _title.setFillColor(sf::Color::Black);
    std::ifstream file("Student\\" + get + ".txt");
    _tmp      = get;
    int movex = 0, movey = 0;
    do
    {
        getline(file, get);
    } while (get.empty());

    while (!file.eof())
    {
        getline(file, get);
        if (get.empty() || get[get.size() - 1] != DefaultSemester)
        {
            continue;
        }
        std::string tmp1;
        std::ifstream fin("Cmanage\\"+ get + ".txt");
        getline(fin,tmp1,'\n');
        getline(fin,tmp1,'\n');
        fin.close();

        _coursebox[size].setSize(sf::Vector2f(400.0f, 50.0f));
        _coursebox[size].setFillColor(sf::Color(40, 116, 166, 240));
        _coursebox[size].setOrigin(sf::Vector2f(_coursebox[size].getGlobalBounds().width / 2 ,_coursebox[size].getGlobalBounds().height / 2));
        _coursebox[size].setPosition(movex * 700 + 300, movey * 60 + 120);

        _getcourse[size] = get;
        _course[size].setFont(_data->_assets->GetFont(KANIT));
        _course[size].setFillColor(sf::Color::White);
        _course[size].setCharacterSize(25);
        _course[size].setString(tmp1 + "-"
                               + get.substr(get.find("(") + 1, get.find(")") - get.find("(") - 1));
        _course[size].setOrigin(sf::Vector2f(_course[size].getGlobalBounds().width / 2 ,_course[size].getGlobalBounds().height / 2));
        _course[size].setPosition(movex * 500 + 300, movey * 60 + 110);
        movey++;
        if (_course[size].getPosition().y > 500)
        {
            movex++;
            movey = 0;
        }
        size++;
    }

    memset(_coursefocus, 0, 100);
    memset(_courseselected, 0, 100);

    _exitbutton.setSize(sf::Vector2f(150, 40));
    _exitbutton.setFillColor(sf::Color(0, 76, 153, 255));
    _exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2,
                                       _exitbutton.getGlobalBounds().height / 2));
    _exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 250);

    _exit.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _exit.setString("EXIT");
    _exit.setCharacterSize(24);
    _exit.setOrigin(
        sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
    _exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 245);
    _exit.setFillColor(sf::Color::White);
}
void StudentCourse::ProcessInput()
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
            _exitfocus = (_exitbutton.getGlobalBounds().contains(
                              sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                           sf::Mouse::getPosition(*_data->_window).y))
                              ? 1
                              : 0);

            for (int i = 0; i < size; i++)
            {
                _coursefocus[i] = (_coursebox[i].getGlobalBounds().contains(
                                       sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                                    sf::Mouse::getPosition(*_data->_window).y))
                                       ? 1
                                       : 0);
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            _exitselected = (_exitfocus ? 1 : 0);

            for (int i = 0; i < size; i++)
            {
                _courseselected[i] = (_coursefocus[i] ? 1 : 0);
            }
        }
    }
}
void StudentCourse::Update()
{
    (_exitfocus ? _exitbutton.setFillColor(sf::Color(0, 76, 153, 100))
                : _exitbutton.setFillColor(sf::Color(0, 76, 153, 255)));

    for (int i = 0; i < size; i++)
    {
        (_coursefocus[i] ? _coursebox[i].setFillColor(sf::Color(40, 116, 166, 100))
                         : _coursebox[i].setFillColor(sf::Color(40, 116, 166, 240)));
    }
    for (int i = 0; i < size; i++)
    {
        if (_courseselected[i])
        {
            std::ofstream f("Studentbuf.txt");
            f << _getcourse[i] << std::endl << _tmp;
            f.close();
            _data->_states->AddState(new CourseView1(_data));
            _courseselected[i] = 0;
        }
    }
    if (_exitselected)
    {
        _data->_states->RemoveState();
        _exitselected = 0;
    }
}
void StudentCourse::Draw()
{
    _data->_window->clear(sf::Color::White);
    _data->_window->draw(_title);
    for (int i = 0; i < size; i++)
    {
        _data->_window->draw(_coursebox[i]);
        _data->_window->draw(_course[i]);
    }
    _data->_window->draw(_exitbutton);
    _data->_window->draw(_exit);
    _data->_window->display();
}