#include "ClassView.h"
#include"Create.h"
#include"ClassMan.h"
#include"ScoreView.h"
ClassView::ClassView(Data* data) : _data(data) 
{

}
ClassView::~ClassView()
{

}
void ClassView::Init()
{
	memset(_idfocus, 0, 100);
	memset(_idselected, 0, 100);
	cur = 0; 
	_title.setFont(_data->_assets->GetFont(KANIT));
	_title.setString("No      StudentID          FirstName             Lastname             Gender               Date of Birth                SocialID");
	_title.setFillColor(sf::Color::Red);
	std::string _getbuffer1;
	std::string _getbuffer2;
	std::ifstream f("buffer.txt");
	getline(f , _getbuffer1);
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
		getline(file, dob , ',');
		getline(file, Sid);
		if (No.empty())
		{
			continue;
		}
		_No[cur].setFont(_data->_assets->GetFont(LIGHT));
		_No[cur].setFillColor(sf::Color::Black);
		_No[cur].setPosition(0, cur * 50 + 30);
		_No[cur].setString(No);

		_id[cur].setFont(_data->_assets->GetFont(LIGHT));
		_id[cur].setFillColor(sf::Color::Black);
		_id[cur].setPosition(90, cur * 50 + 30);
		_id[cur].setString(id);

		_Fname[cur].setFont(_data->_assets->GetFont(LIGHT));
		_Fname[cur].setFillColor(sf::Color::Black);
		_Fname[cur].setPosition(310, cur * 50 + 30);
		_Fname[cur].setString(Fname);
		_Fname[cur].setCharacterSize(25);

		_Lname[cur].setFont(_data->_assets->GetFont(LIGHT));
		_Lname[cur].setFillColor(sf::Color::Black);
		_Lname[cur].setPosition(550, cur * 50 + 30);
		_Lname[cur].setString(Lname);

		_gender[cur].setFont(_data->_assets->GetFont(LIGHT));
		_gender[cur].setFillColor(sf::Color::Black);
		_gender[cur].setPosition(800, cur * 50 + 30);
		_gender[cur].setString(gender);

		_dob[cur].setFont(_data->_assets->GetFont(LIGHT));
		_dob[cur].setFillColor(sf::Color::Black);
		_dob[cur].setPosition(1010, cur * 50 + 30);
		_dob[cur].setString(dob);

		_Sid[cur].setFont(_data->_assets->GetFont(LIGHT));
		_Sid[cur].setFillColor(sf::Color::Black);
		_Sid[cur].setPosition(1280, cur * 50 + 30);
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
		f1 << No << "," << id << "," << Fname << "," << Lname << "," << gender << "," << dob << "," << Sid << std::endl;
		f1.close();
		
	}
	_exitbutton.setSize(sf::Vector2f(300, 40));
    _exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 350);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("BACK");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 340);
	_exit.setFillColor(sf::Color::Black);

	_createbox.setSize(sf::Vector2f(300, 40));
    _createbox.setFillColor(sf::Color(40, 116, 166, 240));
	_createbox.setOrigin(sf::Vector2f(_createbox.getGlobalBounds().width / 2, _createbox.getGlobalBounds().height / 2));
	_createbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 300);

	_create.setFont(_data->_assets->GetFont(KANIT));
	_create.setString("ADD NEW STUDENT");
	_create.setCharacterSize(25);
	_create.setOrigin(sf::Vector2f(_create.getGlobalBounds().width / 2, _create.getGlobalBounds().height / 2));
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
			_exitfocus = (_exitbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_createfocus = (_createbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			for (int i = 0; i < cur; i++)
			{
				_idfocus[i] = (_id[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_exitselected = (_exitfocus ? 1 : 0);
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
	for (int i = 0; i < cur ; i++)
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
