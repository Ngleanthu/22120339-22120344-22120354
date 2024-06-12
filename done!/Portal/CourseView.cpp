#include "CourseView.h"
#include"Create.h"
#include"CourseMan.h"
#include"Delete.h"
#include"StudentInfo.h"
#include"ScoreView.h"
CourseView::CourseView(Data* data) : _data(data) , _exitfocus(0), _exitselected(0), _createfocus(0), _createselected(0), _deletefocus(0),
_deleteselected(0) , _exportfocus(0) , _exportselected(0), _scorefocus(0), _scoreselected(0)
{

}
CourseView::~CourseView()
{

}
void CourseView::Init()
{
	memset(_studentfocus, 0, 100);
	memset(_studentselected, 0, 100);

	cur = 0;
	_title.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_title.setString("INFORMATION:						STUDENTS:");
	_title.setStyle(sf::Text::Bold);
	_title.setPosition(sf::Vector2f(20.0f, 15.0f));
	_title.setFillColor(sf::Color::Black);
	
	_exitbutton.setSize(sf::Vector2f(300, 40));
    _exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(170, _data->_window->getSize().y / 2 + 150);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("BACK");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(170, _data->_window->getSize().y / 2 + 140);
	_exit.setFillColor(sf::Color::Black);

	_createbox.setSize(sf::Vector2f(300, 40));
    _createbox.setFillColor(sf::Color(40, 116, 166, 240));
	_createbox.setOrigin(sf::Vector2f(_createbox.getGlobalBounds().width / 2, _createbox.getGlobalBounds().height / 2));
	_createbox.setPosition(170, _data->_window->getSize().y / 2 + 50);

	_create.setFont(_data->_assets->GetFont(KANIT));
	_create.setCharacterSize(25);
	_create.setString("ADD NEW STUDENT");
	_create.setOrigin(sf::Vector2f(_create.getGlobalBounds().width / 2, _create.getGlobalBounds().height / 2));
	_create.setPosition(170, _data->_window->getSize().y / 2 + 40);
	_create.setFillColor(sf::Color::White);

	_deletebox.setSize(sf::Vector2f(300, 40));
    _deletebox.setFillColor(sf::Color(40, 116, 166, 240));
	_deletebox.setOrigin(sf::Vector2f(_deletebox.getGlobalBounds().width / 2, _deletebox.getGlobalBounds().height / 2));
	_deletebox.setPosition(170, _data->_window->getSize().y / 2 + 100);

	_delete.setFont(_data->_assets->GetFont(KANIT));
	_delete.setCharacterSize(25);
	_delete.setString("DELETE STUDENT");
	_delete.setOrigin(sf::Vector2f(_delete.getGlobalBounds().width / 2, _delete.getGlobalBounds().height / 2));
	_delete.setPosition(170, _data->_window->getSize().y / 2 + 90);
	_delete.setFillColor(sf::Color::White);

	_exportbox.setSize(sf::Vector2f(300, 40));
    _exportbox.setFillColor(sf::Color(40, 116, 166, 240));
	_exportbox.setOrigin(sf::Vector2f(_exportbox.getGlobalBounds().width / 2, _exportbox.getGlobalBounds().height / 2));
	_exportbox.setPosition(170, _data->_window->getSize().y / 2);

	_export.setFont(_data->_assets->GetFont(KANIT));
	_export.setCharacterSize(25);
	_export.setString("EXPORT TO CSVFILE");
	_export.setOrigin(sf::Vector2f(_export.getGlobalBounds().width / 2, _export.getGlobalBounds().height / 2));
	_export.setPosition(170, _data->_window->getSize().y / 2 - 10);
	_export.setFillColor(sf::Color::White);

	_scorebox.setSize(sf::Vector2f(300, 40));
	_scorebox.setFillColor(sf::Color(40, 116, 166, 240));
	_scorebox.setOrigin(sf::Vector2f(_scorebox.getGlobalBounds().width / 2, _scorebox.getGlobalBounds().height / 2));
	_scorebox.setPosition(170, _data->_window->getSize().y / 2 - 50);

	_score.setFont(_data->_assets->GetFont(KANIT));
	_score.setCharacterSize(25);
	_score.setString("VIEW SCORE");
	_score.setOrigin(sf::Vector2f(_score.getGlobalBounds().width / 2, _score.getGlobalBounds().height / 2));
	_score.setPosition(170, _data->_window->getSize().y / 2 - 60);
	_score.setFillColor(sf::Color::White);

	_status.setCharacterSize(20);
	_status.setFont(_data->_assets->GetFont(KANIT));
	_status.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 290);
	_status.setFillColor(sf::Color::Black);

	_coursebox.setSize(sf::Vector2f(600.0f, 300.0f));
	_coursebox.setFillColor(sf::Color(214, 219, 223, 240));
	_coursebox.setPosition(sf::Vector2f(20.0f, 55.0f));
	_coursebox.setOutlineThickness(1);
	_coursebox.setOutlineColor(sf::Color::Black);

	
	std::ifstream f("buffer.txt");
	getline(f, _getbuffer);
	getline(f, tmp);
	f.close();
	std::ifstream file("CManage\\" + _getbuffer + ".txt");
	std::ifstream file1("CManage\\" + _getbuffer + ".csv");
	std::string get;
	int l = 0;
	while (!file.eof())
	{
		getline(file, get);
		
		if (get.empty())
		{
			continue;
		}
		_info[l].setFont(_data->_assets->GetFont(KANIT));
		_info[l].setString(get);
		_info[l].setPosition(sf::Vector2f(25.0f, 60.0f + 35.0f * l));
		_info[l].setFillColor(sf::Color::Black);
		l++;
	}
	_info[0].setString("Course ID : " + _info[0].getString());
	_info[1].setString("Course name : " + _info[1].getString());
	_info[2].setString("Class name : " + _info[2].getString());
	_info[3].setString("Teacher name : " + _info[3].getString());
	_info[4].setString("Number of credits : " + _info[4].getString());
	_info[5].setString("Maximum students : " + _info[5].getString());
	_info[6].setString("Day of the week : " + _info[6].getString());
	_info[7].setString("Sessions : " + _info[7].getString());
	int move_x = 0, move_y = 0; 
	while (!file1.eof())
	{
		getline(file1, get);

		if (get.empty())
		{
			continue;
		}
		std::ifstream ff("Account\\" + get + ".txt");
		if(ff)
		{
			_student[cur].setFont(_data->_assets->GetFont(LIGHT));
			_student[cur].setString(get);
			_student[cur].setPosition(700 + 100 * move_x, 50 + 35 * move_y);
			_student[cur].setFillColor(sf::Color::Black);
			move_y++;
			if (_student[cur].getPosition().y > 850)
			{
				move_y = 0;
				move_x++;
			}
			cur++;
		}
		
		
	}
}
void CourseView::ProcessInput()
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
			_deletefocus = (_deletebox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_exportfocus = (_exportbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_scorefocus = (_scorebox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			for (int i = 0; i < cur; i++)
			{
				_studentfocus[i] = (_student[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_exitselected = (_exitfocus ? 1 : 0);
			_createselected = (_createfocus ? 1 : 0);
			_deleteselected = (_deletefocus ? 1 : 0);
			_exportselected = (_exportfocus ? 1 : 0);
			_scoreselected = (_scorefocus ? 1 : 0);
			for (int i = 0; i < cur; i++)
			{
				_studentselected[i] = (_studentfocus[i] ? 1 : 0);
			}
		}
	}
}
void CourseView::Update()
{
    (_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100))
                    : _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
    (_createfocus ? _createbox.setFillColor(sf::Color(40, 116, 166, 100))
                      : _createbox.setFillColor(sf::Color(40, 116, 166, 240)));
    (_deletefocus ? _deletebox.setFillColor(sf::Color(40, 116, 166, 100))
                      : _deletebox.setFillColor(sf::Color(40, 116, 166, 240)));
    (_exportfocus ? _exportbox.setFillColor(sf::Color(40, 116, 166, 100))
                      : _exportbox.setFillColor(sf::Color(40, 116, 166, 240)));
	(_scorefocus ? _scorebox.setFillColor(sf::Color(40, 116, 166, 100))
		: _scorebox.setFillColor(sf::Color(40, 116, 166, 240)));;
	for (int i = 0; i < cur; i++)
	{
		(_studentfocus[i] ? _student[i].setFillColor(sf::Color::Red) : _student[i].setFillColor(sf::Color::Black));
	}
	for (int i = 0; i < cur; i++)
	{
		if (_studentselected[i])
		{
			std::ofstream file("Studentbuf.txt");
			std::string tmp1 = _student[i].getString();
			file << tmp1;
			file.close();
			_data->_states->AddState(new StudentInfo(_data));
			_studentselected[i] = 0;
		}
	}
	if (_exitselected)
	{
		std::ofstream f("buffer.txt");
		f << tmp;
		_data->_states->RemoveState();
		_exitselected = 0;

	}
	if (_createselected)
	{
		_data->_states->AddState(new AddStudent2(_data));
		_createselected = 0;
	}
	if (_deleteselected)
	{
		_data->_states->AddState(new DeleteStudent(_data));
		_deleteselected = 0;
	}
	if (_exportselected)
	{
		std::ofstream f("Score\\" + _getbuffer + ".csv");
		f << "No,StudentID,Full Name,Midterm,Final,Other" << std::endl;
		for (int i = 0; i < cur; i++)
		{
			std::string s = _student[i].getString();
			std::ifstream f1("Student\\" + s + ".txt");
			std::string s1, s2, s3;
			getline(f1, s1, ',');
			getline(f1, s1, ',');
			getline(f1, s2, ',');
			getline(f1, s3, ',');
			f << i + 1 << "," << s1 << "," << s3 << " " << s2 << ",/,/,/" << std::endl;
			f1.close();
		}
		f.close();
		_status.setString("Export success!");
		_exportselected = 0;
	}
	if (_scoreselected)
	{
		_data->_states->AddState(new ScoreView(_data));
		_scoreselected = 0;
	}
}
void CourseView::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_title);
	_data->_window->draw(_coursebox);
	for (int i = 0; i < 8; i++)
	{
		_data->_window->draw(_info[i]);
	}
	for (int i = 0; i < cur; i++)
	{
		_data->_window->draw(_student[i]);
	}
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_exit);
	_data->_window->draw(_createbox);
	_data->_window->draw(_create);
	_data->_window->draw(_deletebox);
	_data->_window->draw(_delete);
	_data->_window->draw(_exportbox);
	_data->_window->draw(_export);
	_data->_window->draw(_status);
	_data->_window->draw(_scorebox);
	_data->_window->draw(_score);
	_data->_window->display();
}










CourseView1::CourseView1(Data* data) : _data(data), _exitfocus(0), _exitselected(0)
{

}
CourseView1::~CourseView1()
{

}
void CourseView1::Init()
{

	cur = 0;
	_title.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_title.setString("COURSE INFORMATION");
	_title.setFillColor(sf::Color::Red);

	_coursebox.setSize(sf::Vector2f(500,260));
	_coursebox.setFillColor(sf::Color(214, 219, 223, 240));
	_coursebox.setPosition(0,35);

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color(0, 76, 153, 255));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 250);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("EXIT");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 240);
	_exit.setFillColor(sf::Color::White);
	

	std::string _getbuffer;
	std::ifstream f("Studentbuf.txt");
	getline(f, _getbuffer);
	getline(f, tmp);
	f.close();
	std::ifstream file("CManage\\" + _getbuffer + ".txt");
	std::string get;
	int l = 0;
	while (!file.eof())
	{
		getline(file, get);

		if (get.empty())
		{
			continue;
		}
		_info[l].setFont(_data->_assets->GetFont(LIGHT));
		_info[l].setString(get);
		_info[l].setPosition(0, 40 + 30 * l);
		_info[l].setFillColor(sf::Color::Black);
		l++;
	}
	_info[0].setString("Course ID : " + _info[0].getString());
	_info[1].setString("Course name : " + _info[1].getString());
	_info[2].setString("Class name : " + _info[2].getString());
	_info[3].setString("Teacher name : " + _info[3].getString());
	_info[4].setString("Number of credits : " + _info[4].getString());
	_info[5].setString("Maximum students : " + _info[5].getString());
	_info[6].setString("Day of the week : " + _info[6].getString());
	_info[7].setString("Sessions : " + _info[7].getString());
	
}
void CourseView1::ProcessInput()
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
			
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_exitselected = (_exitfocus ? 1 : 0);
		}
	}
}
void CourseView1::Update()
{
	(_exitfocus ? _exitbutton.setFillColor(sf::Color(0, 76, 153, 100)) : _exitbutton.setFillColor(sf::Color(0, 76, 153, 255)));
	if (_exitselected)
	{
		std::ofstream f("Studentbuf.txt");
		f << tmp;
		f.close();
		_data->_states->RemoveState();
		
		_exitselected = 0;

	}
	
}
void CourseView1::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_title);
	_data->_window->draw(_coursebox);
	for (int i = 0; i < 8; i++)
	{
		_data->_window->draw(_info[i]);
	}
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_exit);
	_data->_window->display();
}
