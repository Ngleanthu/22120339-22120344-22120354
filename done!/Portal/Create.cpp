#include "Create.h"
#include<Windows.h>
#include"ClassView.h"
#include"CourseView.h"
CreateYear::CreateYear(Data* data) : _data(data), _boxfocus(0), _blink(1), _exitfocus(0),
_submitfocus(0), _exitselected(0), _submitselected(0)
{

}
CreateYear::~CreateYear()
{

}
void CreateYear::Init()
{
	time = sf::Time::Zero;

	_box.setSize(sf::Vector2f(300, 40));
	_box.setFillColor(sf::Color::White);
	_box.setOrigin(sf::Vector2f(_box.getGlobalBounds().width / 2, _box.getGlobalBounds().height / 2));
	_box.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 100);
	_box.setOutlineThickness(1);
    _box.setOutlineColor(sf::Color(40, 116, 166, 240));

	_text.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_text.setString("School Year:");
	_text.setCharacterSize(28);
	_text.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 160);
	_text.setFillColor(sf::Color::Black);

	_submitbutton.setSize(sf::Vector2f(150, 40));
    _submitbutton.setFillColor(sf::Color(40, 116, 166, 240));
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 100);

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color::Black);
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 150);

	_submit.setFont(_data->_assets->GetFont(KANIT));
	_submit.setString("SUBMIT");
	_submit.setCharacterSize(24);
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 95);
	_submit.setFillColor(sf::Color::White);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("BACK");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 145);
	_exit.setFillColor(sf::Color::Black);

	_showbox.setFont(_data->_assets->GetFont(LIGHT));
	_showbox.setCharacterSize(24);
	_showbox.setFillColor(sf::Color::Black);
	_showbox.setPosition(_data->_window->getSize().x / 2 - 145, _data->_window->getSize().y / 2 - 115);
	_showbox.setString("");

	file.open("Manage\\Year.txt", std::ios::app);
	
	_example.setFont(_data->_assets->GetFont(LIGHT));
	_example.setCharacterSize(20);
	_example.setString("For example : 2022-2023");
	_example.setPosition(_data->_window->getSize().x / 2 - 145, _data->_window->getSize().y / 2 - 115);
	_example.setFillColor(sf::Color::Color(0 , 0 , 0 , 50));
}
void CreateYear::ProcessInput()
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
			_submitfocus = (_submitbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_boxfocus = (_box.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_exitselected = (_exitfocus ? 1 : 0);
			_submitselected = (_submitfocus ? 1 : 0);
			_blink = 1;
		}

		if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (event.text.unicode < 128)
			{
				if (_boxfocus)
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
					{
						if (!_getbox.empty())
						{
							_getbox.pop_back();
						}
					}
					else
					{
						_getbox += static_cast<char>(event.text.unicode);
					}
				_blink = 1;
			}
		}

	}
}
void CreateYear::Update()
{
	time = clock.getElapsedTime();
	if (time.asSeconds() >= 0.5)
	{
		_blink = !_blink;
		clock.restart();
	}
	_showbox.setString(_getbox + ((_blink && _boxfocus) ? "|" : ""));
        (_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100))
                    : _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
        (_submitfocus ? _submitbutton.setFillColor(sf::Color(40, 116, 166, 100))
                      : _submitbutton.setFillColor(sf::Color(40, 116, 166, 240)));
	if (_boxfocus || !_getbox.empty())
	{
		_example.setFillColor(sf::Color::Color(0, 0, 0, 0));
	}
	else
	{
		_example.setFillColor(sf::Color::Color(0, 0, 0, 50));
	}
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;
	}

	if (!_getbox.empty() &&(_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
	{
		
		file << _getbox << std::endl;
		std::ofstream f("Manage\\" + _getbox + ".txt");
		std::ifstream f1("LastYear.txt");
		std::string get;
		getline(f1, get);
		if (!get.empty())
		{
			std::ifstream year("Manage\\" + get + ".txt");
			std::string gety;
			while (!year.eof())
			{
				getline(year, gety);
				f << gety << std::endl;
			}
		}
		f1.close();
		std::ofstream f2("LastYear.txt");
		f2 << _getbox;
		f2.close();
		file.close();
		Sleep(1000);
		_data->_states->RemoveState();
		_submitselected = 0;
	}
}
void CreateYear::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_box);
	_data->_window->draw(_text);
	_data->_window->draw(_submitbutton);
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_submit);
	_data->_window->draw(_exit);
	_data->_window->draw(_showbox);
	_data->_window->draw(_example);
	_data->_window->display();
}










Create::Create(Data* data) : _data(data), _boxfocus(0), _blink(1), _exitfocus(0),
_submitfocus(0), _exitselected(0), _submitselected(0)
{

}
Create::~Create()
{

}
void Create::Init()
{
	time = sf::Time::Zero;

	_box.setSize(sf::Vector2f(300, 40));
	_box.setFillColor(sf::Color::White);
	_box.setOrigin(sf::Vector2f(_box.getGlobalBounds().width / 2, _box.getGlobalBounds().height / 2));
	_box.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 100);
	_box.setOutlineThickness(1);
    _box.setOutlineColor(sf::Color(40, 116, 166, 240));

	_text.setFont(_data->_assets->GetFont(LIGHT));
	_text.setString("Class name");
	_text.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 160);
	_text.setFillColor(sf::Color::Black);

	_submitbutton.setSize(sf::Vector2f(150, 40));
    _submitbutton.setFillColor(sf::Color(40, 116, 166, 240));
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 100);

	_exitbutton.setSize(sf::Vector2f(150, 40));
    _exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 150);

	_submit.setFont(_data->_assets->GetFont(KANIT));
	_submit.setString("SUBMIT");
	_submit.setCharacterSize(24);
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 95);
	_submit.setFillColor(sf::Color::White);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("BACK");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 145);
	_exit.setFillColor(sf::Color::Black);

	_showbox.setFont(_data->_assets->GetFont(LIGHT));
	_showbox.setCharacterSize(24);
	_showbox.setFillColor(sf::Color::Black);
	_showbox.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 115);
	_showbox.setString("");
	std::string get;
	std::ifstream f("buffer.txt");
	getline(f, get);
	file.open("Manage\\" + get + ".txt", std::ios::app);
	_example.setFont(_data->_assets->GetFont(LIGHT));
	_example.setCharacterSize(20);
	_example.setString("For example : 22TT2");
	_example.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 115);
	_example.setFillColor(sf::Color::Color(0, 0, 0, 50));
}
void Create::ProcessInput()
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
			_submitfocus = (_submitbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_boxfocus = (_box.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_exitselected = (_exitfocus ? 1 : 0);
			_submitselected = (_submitfocus ? 1 : 0);
			_blink = 1;
		}

		if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (event.text.unicode < 128)
			{
				if (_boxfocus)
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
					{
						if (!_getbox.empty())
						{
							_getbox.pop_back();
						}
					}
					else
					{
						_getbox += static_cast<char>(event.text.unicode);
					}
				_blink = 1;
			}
		}

	}
}
void Create::Update()
{
	time = clock.getElapsedTime();
	if (time.asSeconds() >= 0.5)
	{
		_blink = !_blink;
		clock.restart();
	}
	_showbox.setString(_getbox + ((_blink && _boxfocus) ? "|" : ""));
        (_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100))
                    : _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
        (_submitfocus ? _submitbutton.setFillColor(sf::Color(40, 116, 166, 100))
                      : _submitbutton.setFillColor(sf::Color(40, 116, 166, 240)));
	if (_boxfocus || !_getbox.empty())
	{
		_example.setFillColor(sf::Color::Color(0, 0, 0, 0));
	}
	else
	{
		_example.setFillColor(sf::Color::Color(0, 0, 0, 50));
	}
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;
	}

	if (!_getbox.empty() && (_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
	{

		file << _getbox << std::endl;
		std::ofstream f("Manage\\" + _getbox + ".csv");
		file.close();
		Sleep(1000);
		_data->_states->RemoveState();
		_submitselected = 0;
	}
}
void Create::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_box);
	_data->_window->draw(_text);
	_data->_window->draw(_submitbutton);
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_submit);
	_data->_window->draw(_exit);
	_data->_window->draw(_showbox);
	_data->_window->draw(_example);
	_data->_window->display();
}










AddStudent::AddStudent(Data* data) : _data(data) , _blink(1), _exitfocus(0),
_submitfocus(0), _exitselected(0), _submitselected(0)
{

}
AddStudent::~AddStudent()
{

}
void AddStudent::Init()
{
	time = sf::Time::Zero;
	for (int i = 0; i < 7; i++)
	{
		_boxfocus[i] = 0;
		_box[i].setSize(sf::Vector2f(300, 40));
		_box[i].setFillColor(sf::Color::White);
		_box[i].setOrigin(sf::Vector2f(_box[i].getGlobalBounds().width / 2, _box[i].getGlobalBounds().height / 2));
		_box[i].setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 350 + 100 * i);
		_box[i].setOutlineThickness(1);
        _box[i].setOutlineColor(sf::Color(40, 116, 166, 240));
		_text[i].setFont(_data->_assets->GetFont(LIGHT));
		_text[i].setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 410 + 100*i);
		_text[i].setFillColor(sf::Color::Black);
		_showbox[i].setFont(_data->_assets->GetFont(LIGHT));
		_showbox[i].setCharacterSize(24);
		_showbox[i].setFillColor(sf::Color::Black);
		_showbox[i].setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 365 + 100*i);
		_showbox[i].setString("");
	}
	_text[0].setString("No");
	_text[1].setString("Student ID");
	_text[2].setString("First name");
	_text[3].setString("Last name");
	_text[4].setString("Gender");
	_text[5].setString("Date of birth");
	_text[6].setString("Social ID");
	

	_submitbutton.setSize(sf::Vector2f(150, 40));
    _submitbutton.setFillColor(sf::Color(40, 116, 166, 240));
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 300);

	_exitbutton.setSize(sf::Vector2f(150, 40));
    _exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 350);

	_submit.setFont(_data->_assets->GetFont(KANIT));
	_submit.setString("SUBMIT");
	_submit.setCharacterSize(24);
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 295);
    _submit.setFillColor(sf::Color(40, 116, 166, 240));

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("BACK");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 345);
	_exit.setFillColor(sf::Color::Black);

	_status.setCharacterSize(20);
	_status.setFont(_data->_assets->GetFont(LIGHT));
	_status.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 245);
	_status.setFillColor(sf::Color::Red);

	std::string get1, get2;
	std::ifstream f("buffer.txt");
	getline(f, get1);
	getline(f, get2);
	file.open("Manage\\" + get2 + ".csv", std::ios::app);
	
}
void AddStudent::ProcessInput()
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
			_submitfocus = (_submitbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 7; i++)
			{
				_boxfocus[i] = (_box[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			}
			_exitselected = (_exitfocus ? 1 : 0);
			_submitselected = (_submitfocus ? 1 : 0);
			_blink = 1;
		}

		if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (event.text.unicode < 128)
			{
				for (int i = 0; i < 7; i++)
				{
					if (_boxfocus[i])
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
						{
							if (!_getbox[i].empty())
							{
								_getbox[i].pop_back();
							}
						}
						else
						{
							_getbox[i] += static_cast<char>(event.text.unicode);
						}
				}
				_blink = 1;
			}
		}

	}
}
void AddStudent::Update()
{
	time = clock.getElapsedTime();
	if (time.asSeconds() >= 0.5)
	{
		_blink = !_blink;
		clock.restart();
	}
	for (int i = 0; i < 7; i++)
	{
		_showbox[i].setString(_getbox[i] + ((_blink && _boxfocus[i]) ? "|" : ""));
	}
	
	(_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100))
                    : _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
    (_submitfocus ? _submitbutton.setFillColor(sf::Color(40, 116, 166, 100))
                      : _submitbutton.setFillColor(sf::Color(40, 116, 166, 240)));
	
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_data->_states->AddState(new ClassView(_data), 1);
		_exitselected = 0;
	}

	if (_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{

		std::ifstream check("Account\\" + _getbox[1] + ".txt");
		if (check)
		{
			_status.setString("This Student ID has been existed!");
		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				file << _getbox[i] << ",";
			}
			file << _getbox[6] << std::endl;
			file.close();
			std::ofstream f("Account\\" + _getbox[1] + ".txt");
			f << _getbox[1] << std::endl << "123";
			f.close();
			std::ofstream f1("Student\\" + _getbox[1] + ".txt");
			std::ofstream f2("StudentScore\\" + _getbox[1] + ".txt");
			std::fstream f3("Student\\Students.txt", std::ios::app);
			f3 << std::endl << _getbox[1];
			for (int i = 1; i < 6; i++)
			{
				f1 << _getbox[i] << ",";
			}
			f1 << _getbox[6] << std::endl;
			f1.close();
			Sleep(1000);
			_data->_states->RemoveState();
			_data->_states->AddState(new ClassView(_data), 1);
		}
		_submitselected = 0;
	}
}
void AddStudent::Draw()
{
	_data->_window->clear(sf::Color::White);
	for (int i = 0; i < 7; i++)
	{
		_data->_window->draw(_box[i]);
		_data->_window->draw(_text[i]);
		_data->_window->draw(_showbox[i]);
	}
	_data->_window->draw(_submitbutton);
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_submit);
	_data->_window->draw(_exit);
	_data->_window->draw(_status);
	_data->_window->display();
}









CreateSemester::CreateSemester(Data* data) : _data(data), _blink(1), _exitfocus(0),
_submitfocus(0), _exitselected(0), _submitselected(0)
{

}
CreateSemester::~CreateSemester()
{

}
void CreateSemester::Init()
{
	time = sf::Time::Zero;
	for (int i = 0; i < 4; i++)
	{
		_boxfocus[i] = 0;
		_box[i].setSize(sf::Vector2f(400, 40));
		_box[i].setFillColor(sf::Color::White);
		_box[i].setOrigin(sf::Vector2f(_box[i].getGlobalBounds().width / 2, _box[i].getGlobalBounds().height / 2));
		_box[i].setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 350 + 120 * i);
		_box[i].setOutlineThickness(1);
        _box[i].setOutlineColor(sf::Color(40, 116, 166, 240));

		_text[i].setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
		_text[i].setCharacterSize(28);
		_text[i].setPosition(_data->_window->getSize().x / 2 - 200, _data->_window->getSize().y / 2 - 410 + 120 * i);
		_text[i].setFillColor(sf::Color::Black);

		_showbox[i].setFont(_data->_assets->GetFont(LIGHT));
		_showbox[i].setCharacterSize(24);
		_showbox[i].setFillColor(sf::Color::Black);
		_showbox[i].setPosition(_data->_window->getSize().x / 2 - 195, _data->_window->getSize().y / 2 - 365 + 120 * i);
		_showbox[i].setString("");
	}
	_text[0].setString("Semester(1, 2 or 3):");
	_text[1].setString("School year:");
	_text[2].setString("Start date:");
	_text[3].setString("End date:");
	


	_submitbutton.setSize(sf::Vector2f(150, 40));
    _submitbutton.setFillColor(sf::Color(40, 116, 166, 240));
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 300);

	_exitbutton.setSize(sf::Vector2f(150, 40));
    _exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 350);

	_submit.setFont(_data->_assets->GetFont(KANIT));
	_submit.setString("SUBMIT");
	_submit.setCharacterSize(24);
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 295);
	_submit.setFillColor(sf::Color::White);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("BACK");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 345);
	_exit.setFillColor(sf::Color::Black);
	file.open("CManage\\Semester.txt", std::ios::app);
	
	
}
void CreateSemester::ProcessInput()
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
			_submitfocus = (_submitbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 4; i++)
			{
				_boxfocus[i] = (_box[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			}
			_exitselected = (_exitfocus ? 1 : 0);
			_submitselected = (_submitfocus ? 1 : 0);
			_blink = 1;
		}

		if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (event.text.unicode < 128)
			{
				for (int i = 0; i < 4; i++)
				{
					if (_boxfocus[i])
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
						{
							if (!_getbox[i].empty())
							{
								_getbox[i].pop_back();
							}
						}
						else
						{
							_getbox[i] += static_cast<char>(event.text.unicode);
						}
				}
				_blink = 1;
			}
		}

	}
}
void CreateSemester::Update()
{
	time = clock.getElapsedTime();
	if (time.asSeconds() >= 0.5)
	{
		_blink = !_blink;
		clock.restart();
	}
	for (int i = 0; i < 4; i++)
	{
		_showbox[i].setString(_getbox[i] + ((_blink && _boxfocus[i]) ? "|" : ""));
	}

	(_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100))
                    : _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
    (_submitfocus ? _submitbutton.setFillColor(sf::Color(40, 116, 166, 100))
                      : _submitbutton.setFillColor(sf::Color(40, 116, 166, 240)));

	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;
	}

	if (_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		int n = 0;
		std::ifstream s("Cmanage\\Semester.txt");
		std::string t;
		while (!s.eof())
		{
			getline(s, t);
			if (t.empty())
			{
				continue;
			}
			n++;
		}
		s.close();
		std::string get = std::to_string(n + 1) + ".Semester " + _getbox[0] + "(" + _getbox[1] + ")/(" + _getbox[2] + " - " + _getbox[3] + ")";
		std::string get1 = std::to_string(n + 1) + ".Semester " + _getbox[0] + "(" + _getbox[1] + ")" ;
		std::ofstream f("Cmanage\\" + get1 + ".txt");
		file << get << std::endl;
		file.close();
		Sleep(1000);
		_data->_states->RemoveState();
		_submitselected = 0;
		
	}
}
void CreateSemester::Draw()
{
	_data->_window->clear(sf::Color::White);
	for (int i = 0; i < 4; i++)
	{
		_data->_window->draw(_box[i]);
		_data->_window->draw(_text[i]);
		_data->_window->draw(_showbox[i]);
	}
	_data->_window->draw(_submitbutton);
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_submit);
	_data->_window->draw(_exit);
	_data->_window->display();
}








AddCourse::AddCourse(Data* data) : _data(data), _blink(1), _exitfocus(0),
_submitfocus(0), _exitselected(0), _submitselected(0)
{
	
}
AddCourse::~AddCourse()
{

}
void AddCourse::Init()
{

	std::ifstream f("buffer.txt");
	getline(f, get , '/');
	file.open("Cmanage\\" + get + ".txt" , std::ios::app);
	
	time = sf::Time::Zero;
	for (int i = 0; i < 8; i++)
	{
		_boxfocus[i] = 0;
		_box[i].setSize(sf::Vector2f(300, 40));
		_box[i].setFillColor(sf::Color::White);
		_box[i].setOrigin(sf::Vector2f(_box[i].getGlobalBounds().width / 2, _box[i].getGlobalBounds().height / 2));
		_box[i].setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 350 + 75 * i);
		_box[i].setOutlineThickness(1);
        _box[i].setOutlineColor(sf::Color(40, 116, 166, 240));

		_text[i].setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
		_text[i].setCharacterSize(25);
		_text[i].setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 400 + 75 * i);
		_text[i].setFillColor(sf::Color::Black);

		_showbox[i].setFont(_data->_assets->GetFont(LIGHT));
		_showbox[i].setCharacterSize(24);
		_showbox[i].setFillColor(sf::Color::Black);
		_showbox[i].setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 365 + 75 * i);
		_showbox[i].setString("");
	}
	_text[0].setString("Course ID:");
	_text[1].setString("Course name:");
	_text[2].setString("Class name:");
	_text[3].setString("Teacher name:");
	_text[4].setString("Number of credits:");
	_text[5].setString("Maximum students:");
	_text[6].setString("Day of the week:");
	_text[7].setString("Sessions:");


	_submitbutton.setSize(sf::Vector2f(150, 40));
    _submitbutton.setFillColor(sf::Color(40, 116, 166, 240));
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 300);

	_exitbutton.setSize(sf::Vector2f(150, 40));
    _exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 350);

	_submit.setFont(_data->_assets->GetFont(KANIT));
	_submit.setString("SUBMIT");
	_submit.setCharacterSize(24);
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 295);
	_submit.setFillColor(sf::Color::White);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("BACK");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 345);
	_exit.setFillColor(sf::Color::Black);
	
	_status.setCharacterSize(20);
	_status.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 245);
	_status.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_status.setStyle(sf::Text::Italic);
	_status.setFillColor(sf::Color::Red);
}
void AddCourse::ProcessInput()
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
			_submitfocus = (_submitbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 8; i++)
			{
				_boxfocus[i] = (_box[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			}
			_exitselected = (_exitfocus ? 1 : 0);
			_submitselected = (_submitfocus ? 1 : 0);
			_blink = 1;
		}

		if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (event.text.unicode < 128)
			{
				for (int i = 0; i < 8; i++)
				{
					if (_boxfocus[i])
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
						{
							if (!_getbox[i].empty())
							{
								_getbox[i].pop_back();
							}
						}
						else
						{
							_getbox[i] += static_cast<char>(event.text.unicode);
						}
				}
				_blink = 1;
			}
		}

	}
}
void AddCourse::Update()
{
	time = clock.getElapsedTime();
	if (time.asSeconds() >= 0.5)
	{
		_blink = !_blink;
		clock.restart();
	}
	for (int i = 0; i < 8; i++)
	{
		_showbox[i].setString(_getbox[i] + ((_blink && _boxfocus[i]) ? "|" : ""));
	}

	(_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100))
                    : _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
    (_submitfocus ? _submitbutton.setFillColor(sf::Color(40, 116, 166, 100))
                      : _submitbutton.setFillColor(sf::Color(40, 116, 166, 240)));

	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;
		
	}

	if (_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		std::ifstream check("Cmanage\\(" + _getbox[0] + ")" + get.substr(0, 1) + ".txt");
		if (check)
		{
			_status.setString("This course ID has been existed!");
		}
		else
		{
			file << _getbox[1] << "(" << _getbox[0] << ")" << std::endl;
			std::ofstream f("Cmanage\\(" + _getbox[0] + ")" + get.substr(0, 1) + ".txt");
			std::ofstream f1("Cmanage\\(" + _getbox[0] + ")" + get.substr(0, 1) + ".csv");
			std::ofstream f2("Score\\(" + _getbox[0] + ")" + get.substr(0, 1) + ".csv");
			for (int i = 0; i < 8; i++)
			{
				f << _getbox[i] << std::endl;
			}
			f.close();
			Sleep(1000);
			_data->_states->RemoveState();
		}
		_submitselected = 0;
		
	}
}
void AddCourse::Draw()
{
	_data->_window->clear(sf::Color::White);
	for (int i = 0; i < 8; i++)
	{
		_data->_window->draw(_box[i]);
		_data->_window->draw(_text[i]);
		_data->_window->draw(_showbox[i]);
	}
	_data->_window->draw(_submitbutton);
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_submit);
	_data->_window->draw(_exit);
	_data->_window->draw(_status);
	_data->_window->display();
}










AddStudent2::AddStudent2(Data* data) : _data(data), _blink(1), _exitfocus(0), _boxfocus(0) ,
_submitfocus(0), _exitselected(0), _submitselected(0)
{

}
AddStudent2::~AddStudent2()
{

}
void AddStudent2::Init()
{
	time = sf::Time::Zero;
	
	_box.setSize(sf::Vector2f(300, 40));
	_box.setFillColor(sf::Color::White);
	_box.setOrigin(sf::Vector2f(_box.getGlobalBounds().width / 2, _box.getGlobalBounds().height / 2));
	_box.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 100);
	_box.setOutlineThickness(1);
	_box.setOutlineColor(sf::Color::Red);

	_text.setFont(_data->_assets->GetFont(LIGHT));
	_text.setString("Student ID");
	_text.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 160);
	_text.setFillColor(sf::Color::Black);

	_showbox.setFont(_data->_assets->GetFont(LIGHT));
	_showbox.setCharacterSize(24);
	_showbox.setFillColor(sf::Color::Black);
	_showbox.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 115);
	_showbox.setString("");

	_submitbutton.setSize(sf::Vector2f(150, 40));
	_submitbutton.setFillColor(sf::Color(0, 76, 153, 255));
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 300);

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color(214, 219, 223, 240));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 350);

	_submit.setFont(_data->_assets->GetFont(LIGHT));
	_submit.setString("SUBMIT");
	_submit.setCharacterSize(24);
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 295);
	_submit.setFillColor(sf::Color::White);

	_exit.setFont(_data->_assets->GetFont(LIGHT));
	_exit.setString("EXIT");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 345);
	_exit.setFillColor(sf::Color::Black);

	_status.setCharacterSize(20);
	_status.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 245);
	_status.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_status.setStyle(sf::Text::Italic);
	_status.setFillColor(sf::Color::Red);


	std::ifstream f("buffer.txt");
	getline(f, get);
	file.open("CManage\\" + get + ".csv", std::ios::app);

}
void AddStudent2::ProcessInput()
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
			_submitfocus = (_submitbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_boxfocus = (_box.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_exitselected = (_exitfocus ? 1 : 0);
			_submitselected = (_submitfocus ? 1 : 0);
			_blink = 1;
		}

		if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (event.text.unicode < 128)
			{
				if (_boxfocus)
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
					{
						if (!_getbox.empty())
						{
							_getbox.pop_back();
						}
					}
					else
					{
						_getbox += static_cast<char>(event.text.unicode);
					}
				_blink = 1;
			}
		}


	}
}
void AddStudent2::Update()
{
	time = clock.getElapsedTime();
	if (time.asSeconds() >= 0.5)
	{
		_blink = !_blink;
		clock.restart();
	}
	_showbox.setString(_getbox + ((_blink && _boxfocus) ? "|" : ""));
	(_exitfocus ? _exitbutton.setFillColor(sf::Color(214, 219, 223, 100))
		: _exitbutton.setFillColor(sf::Color(214, 219, 223, 240)));
	(_submitfocus ? _submitbutton.setFillColor(sf::Color(40, 116, 166, 100))
		: _submitbutton.setFillColor(sf::Color(40, 116, 166, 240)));
	if (_exitselected)
	{
		_data->_states->RemoveState();
		
		_exitselected = 0;
	}

	if (_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{

		std::ifstream f("Account\\" + _getbox + ".txt");
		if (f)
		{
			
			file << _getbox << std::endl;
			_data->_states->RemoveState();
			_data->_states->AddState(new CourseView(_data) , 1);
			std::fstream t("Student\\" + _getbox + ".txt", std::ios::app);
			t << std::endl << get ;
			
		}
		else
		{
			_status.setString("This student haven't added to any class before!");
		}

		_submitselected = 0;
	}
}
void AddStudent2::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_box);
	_data->_window->draw(_text);
	_data->_window->draw(_showbox);
	_data->_window->draw(_submitbutton);
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_submit);
	_data->_window->draw(_exit);
	_data->_window->draw(_status);
	_data->_window->display();
}