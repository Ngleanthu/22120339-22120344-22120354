#include "ClassView.h"
#include "ClassMan.h"
#include "Create.h"
#include "ScoreView.h"

ClassView::ClassView(Data *data) : _data(data) {}
ClassView::~ClassView() {}
void ClassView::Init()
{
    memset(_idfocus, 0, 100);
    memset(_idselected, 0, 100);
    cur = 0;
    _title.setFont(_data->_assets->GetFont(CHIVOMONO_REGULAR));
    _title.setStyle(sf::Text::Bold);
    _title.setPosition(95, 10);
    _title.setCharacterSize(25);
    _title.setString(
        "No  Student ID   First Name		 Last Name	Gender	   Date of Birth Social "
        "ID");
    _title.setFillColor(sf::Color::Red);
    std::string _getbuffer1;
    std::string _getbuffer2;
    std::ifstream f("buffer.txt");
    getline(f, _getbuffer1);
    getline(f, _getbuffer2);
    f.close();
    file.open("Manage\\" + _getbuffer2 + ".csv", std::ios::in);
    std::string No, id, Fname, Lname, gender, dob, Sid;
    while (!file.eof())
    {
        getline(file, No, ',');
        getline(file, id, ',');
        getline(file, Fname, ',');
        getline(file, Lname, ',');
        getline(file, gender, ',');
        getline(file, dob, ',');
        getline(file, Sid);
        if (No.empty())
        {
            continue;
        }
        _cell1[cur].setSize(sf::Vector2f(50.0f, 40.0f));
        _cell1[cur].setFillColor(sf::Color(214, 219, 223, 240));
        _cell1[cur].setOutlineColor(sf::Color::Black);
        _cell1[cur].setOutlineThickness(1);
        _cell1[cur].setPosition(95, cur * 50 + 50);

        _cell2[cur].setSize(sf::Vector2f(200.0f, 40.0f));
        _cell2[cur].setFillColor(sf::Color(214, 219, 223, 240));
        _cell2[cur].setOutlineColor(sf::Color::Black);
        _cell2[cur].setOutlineThickness(1);
        _cell2[cur].setPosition(155, cur * 50 + 50);

        _cell3[cur].setSize(sf::Vector2f(300.0f, 40.0f));
        _cell3[cur].setFillColor(sf::Color(214, 219, 223, 240));
        _cell3[cur].setOutlineColor(sf::Color::Black);
        _cell3[cur].setOutlineThickness(1);
        _cell3[cur].setPosition(365, cur * 50 + 50);

        _cell4[cur].setSize(sf::Vector2f(200.0f, 40.0f));
        _cell4[cur].setFillColor(sf::Color(214, 219, 223, 240));
        _cell4[cur].setOutlineColor(sf::Color::Black);
        _cell4[cur].setOutlineThickness(1);
        _cell4[cur].setPosition(675, cur * 50 + 50);

        _cell5[cur].setSize(sf::Vector2f(200.0f, 40.0f));
        _cell5[cur].setFillColor(sf::Color(214, 219, 223, 240));
        _cell5[cur].setOutlineColor(sf::Color::Black);
        _cell5[cur].setOutlineThickness(1);
        _cell5[cur].setPosition(885, cur * 50 + 50);

        _cell6[cur].setSize(sf::Vector2f(200.0f, 40.0f));
        _cell6[cur].setFillColor(sf::Color(214, 219, 223, 240));
        _cell6[cur].setOutlineColor(sf::Color::Black);
        _cell6[cur].setOutlineThickness(1);
        _cell6[cur].setPosition(1095, cur * 50 + 50);

        _cell7[cur].setSize(sf::Vector2f(200.0f, 40.0f));
        _cell7[cur].setFillColor(sf::Color(214, 219, 223, 240));
        _cell7[cur].setOutlineColor(sf::Color::Black);
        _cell7[cur].setOutlineThickness(1);
        _cell7[cur].setPosition(1305, cur * 50 + 50);

        _No[cur].setFont(_data->_assets->GetFont(KANIT));
        _No[cur].setCharacterSize(24);
        _No[cur].setFillColor(sf::Color::Black);
        _No[cur].setPosition(110, cur * 50 + 55);
        _No[cur].setString(No);

        _id[cur].setFont(_data->_assets->GetFont(KANIT));
        _id[cur].setCharacterSize(24);
        _id[cur].setFillColor(sf::Color::Black);
        _id[cur].setPosition(170, cur * 50 + 55);
        _id[cur].setString(id);

        _Fname[cur].setFont(_data->_assets->GetFont(KANIT));
        _Fname[cur].setCharacterSize(24);
        _Fname[cur].setFillColor(sf::Color::Black);
        _Fname[cur].setPosition(380, cur * 50 + 55);
        _Fname[cur].setString(Fname);
        _Fname[cur].setCharacterSize(25);

        _Lname[cur].setFont(_data->_assets->GetFont(KANIT));
        _Lname[cur].setCharacterSize(24);
        _Lname[cur].setFillColor(sf::Color::Black);
        _Lname[cur].setPosition(690, cur * 50 + 55);
        _Lname[cur].setString(Lname);

        _gender[cur].setFont(_data->_assets->GetFont(KANIT));
        _gender[cur].setCharacterSize(24);
        _gender[cur].setFillColor(sf::Color::Black);
        _gender[cur].setPosition(900, cur * 50 + 55);
        _gender[cur].setString(gender);

        _dob[cur].setFont(_data->_assets->GetFont(KANIT));
        _dob[cur].setCharacterSize(24);
        _dob[cur].setFillColor(sf::Color::Black);
        _dob[cur].setPosition(1110, cur * 50 + 55);
        _dob[cur].setString(dob);

        // long long number = std::stoll(Sid);

        _Sid[cur].setFont(_data->_assets->GetFont(KANIT));
        _Sid[cur].setCharacterSize(24);
        _Sid[cur].setFillColor(sf::Color::Black);
        _Sid[cur].setPosition(1320, cur * 50 + 55);
        _Sid[cur].setString(Sid);

        cur++;

        std::ifstream check("Account\\" + id + ".txt");
        if (check)
        {
            continue;
        }
        std::ofstream f("Account\\" + id + ".txt");
        f << id << std::endl << "123";
        f.close();
        std::ofstream f1("Student\\" + id + ".txt");
        f1 << No << "," << id << "," << Fname << "," << Lname << "," << gender << "," << dob << ","
           << Sid << std::endl;
        f1.close();
    }
    _exitbutton.setSize(sf::Vector2f(300, 40));
    _exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
    _exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2,
                                       _exitbutton.getGlobalBounds().height / 2));
    _exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 350);

    _exit.setFont(_data->_assets->GetFont(KANIT));
    _exit.setString("BACK");
    _exit.setCharacterSize(24);
    _exit.setOrigin(
        sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
    _exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 340);
    _exit.setFillColor(sf::Color::Black);

    _createbox.setSize(sf::Vector2f(300, 40));
    _createbox.setFillColor(sf::Color(40, 116, 166, 240));
    _createbox.setOrigin(sf::Vector2f(_createbox.getGlobalBounds().width / 2,
                                      _createbox.getGlobalBounds().height / 2));
    _createbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 300);

    _create.setFont(_data->_assets->GetFont(KANIT));
    _create.setString("ADD NEW STUDENT");
    _create.setCharacterSize(25);
    _create.setOrigin(
        sf::Vector2f(_create.getGlobalBounds().width / 2, _create.getGlobalBounds().height / 2));
    _create.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 290);
    _create.setFillColor(sf::Color::White);

    file.close();
}
void ClassView::ProcessInput()
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
            for (int i = 0; i < cur; i++)
            {
                _idfocus[i] = (_id[i].getGlobalBounds().contains(
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
            for (int i = 0; i < cur; i++)
            {
                _idselected[i] = (_idfocus[i] ? 1 : 0);
            }
        }
    }
}
void ClassView::Update()
{
    (_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100))
                : _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
    (_createfocus ? _createbox.setFillColor(sf::Color(40, 116, 166, 100))
                  : _createbox.setFillColor(sf::Color(40, 116, 166, 240)));
    for (int i = 0; i < cur; i++)
    {
        (_idfocus[i] ? _id[i].setFillColor(sf::Color::Blue) : _id[i].setFillColor(sf::Color::Red));
    }
    for (int i = 0; i < cur; i++)
    {
        if (_idselected[i])
        {
            std::ofstream f("Studentbuf.txt");
            std::string t = _id[i].getString();
            f << t;
            f.close();
            _data->_states->AddState(new ScoreView1(_data));
            _idselected[i] = 0;
        }
    }
    if (_exitselected)
    {
        _data->_states->RemoveState();
        _exitselected = 0;
    }
    if (_createselected)
    {
        _data->_states->AddState(new AddStudent(_data));
        _createselected = 0;
    }
}
void ClassView::Draw()
{
    _data->_window->clear(sf::Color::White);
    _data->_window->draw(_title);
    for (int i = 0; i < cur; ++i)
    {
        _data->_window->draw(_cell1[i]);
        _data->_window->draw(_cell2[i]);
        _data->_window->draw(_cell3[i]);
        _data->_window->draw(_cell4[i]);
        _data->_window->draw(_cell5[i]);
        _data->_window->draw(_cell6[i]);
        _data->_window->draw(_cell7[i]);
    }
    for (int i = 0; i < cur; i++)
    {
        _data->_window->draw(_No[i]);
        _data->_window->draw(_id[i]);
        _data->_window->draw(_Fname[i]);
        _data->_window->draw(_Lname[i]);
        _data->_window->draw(_gender[i]);
        _data->_window->draw(_dob[i]);
        _data->_window->draw(_Sid[i]);
    }
    _data->_window->draw(_exitbutton);
    _data->_window->draw(_exit);
    _data->_window->draw(_createbox);
    _data->_window->draw(_create);

    _data->_window->display();
}
