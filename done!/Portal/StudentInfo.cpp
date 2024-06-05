#include "StudentInfo.h"

StudentInfo::StudentInfo(Data* data) : _data(data), _exitfocus(0), _exitselected(0)
{

}
StudentInfo::~StudentInfo()
{

}
void StudentInfo::Init()
{
	cur = 0;
	_title.setFont(_data->_assets->GetFont(LIGHT));
	_title.setString("Student Info");
	_title.setFillColor(sf::Color::Red);

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color::Black);
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 250);

	_exit.setFont(_data->_assets->GetFont(LIGHT));
	_exit.setString("Exit");
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 240);
	_exit.setFillColor(sf::Color::Red);

	std::ifstream f("Studentbuf.txt");
	getline(f, tmp);
	f.close();
	std::ifstream file("Student\\" + tmp + ".txt");
	std::string get;
	getline(file, get, ',');
	for(int l = 0 ; l < 5 ; l++)
	{
		getline(file, get , ',');
		_info[l].setFont(_data->_assets->GetFont(LIGHT));
		_info[l].setString(get);
		_info[l].setPosition(0, 30 + 30 * l);
		_info[l].setFillColor(sf::Color::Black);
	}
	getline(file, get);
	_info[5].setFont(_data->_assets->GetFont(LIGHT));
	_info[5].setString(get);
	_info[5].setPosition(0, 30 + 30 * 5);
	_info[5].setFillColor(sf::Color::Black);

	_info[0].setString("Student ID : " + _info[0].getString());
	_info[1].setString("First name : " + _info[1].getString());
	_info[2].setString("Last name : " + _info[2].getString());
	_info[3].setString("Gender : " + _info[3].getString());
	_info[4].setString("Dob : " + _info[4].getString());
	_info[5].setString("Social ID : " + _info[5].getString());
	
}
void StudentInfo::ProcessInput()
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
void StudentInfo::Update()
{
	(_exitfocus ? _exitbutton.setFillColor(sf::Color::Yellow) : _exitbutton.setFillColor(sf::Color::Black));
	if (_exitselected)
	{
		std::ofstream file("Studentbuf.txt");
		file.clear();
		file.close();
		_data->_states->RemoveState();
		_exitselected = 0;

	}
}
void StudentInfo::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_title);
	for (int i = 0; i < 6; i++)
	{
		_data->_window->draw(_info[i]);
	}
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_exit);
	_data->_window->display();
}
