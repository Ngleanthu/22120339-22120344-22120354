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

	_id.setFont(_data->_assets->GetFont(LIGHT));
	_id.setString("ID: ");
	_id.setCharacterSize(22);
	_id.setPosition(sf::Vector2f(_data->_window->getSize().x / 2 - 175.0f, 95.0f));
	_id.setFillColor(sf::Color::Black);

	_firstname.setFont(_data->_assets->GetFont(LIGHT));
	_firstname.setString("FIRST NAME: ");
	_firstname.setCharacterSize(22);
	_firstname.setPosition(sf::Vector2f(_data->_window->getSize().x / 2 - 175.0f, 185.0f));
	_firstname.setFillColor(sf::Color::Black);

	_lastname.setFont(_data->_assets->GetFont(LIGHT));
	_lastname.setString("LAST NAME: ");
	_lastname.setCharacterSize(22);
	_lastname.setPosition(sf::Vector2f(_data->_window->getSize().x / 2 - 175.0f, 275.0f));
	_lastname.setFillColor(sf::Color::Black);

	_gender.setFont(_data->_assets->GetFont(LIGHT));
	_gender.setString("GENDER: ");
	_gender.setCharacterSize(22);
	_gender.setPosition(sf::Vector2f(_data->_window->getSize().x / 2 - 175.0f, 365.0f));
	_gender.setFillColor(sf::Color::Black);

	_dob.setFont(_data->_assets->GetFont(LIGHT));
	_dob.setString("DATE OF BIRTH: ");
	_dob.setCharacterSize(22);
	_dob.setPosition(sf::Vector2f(_data->_window->getSize().x / 2 - 175.0f, 455.0f));
	_dob.setFillColor(sf::Color::Black);

	_socialID.setFont(_data->_assets->GetFont(LIGHT));
	_socialID.setString("SOCIAL ID: ");
	_socialID.setCharacterSize(22);
	_socialID.setPosition(sf::Vector2f(_data->_window->getSize().x / 2 - 175.0f, 545.0f));
	_socialID.setFillColor(sf::Color::Black);

	_idbox.setSize(sf::Vector2f(350.0f, 50.0f));
	_idbox.setFillColor(sf::Color(214, 219, 223, 240));
	_idbox.setOrigin(sf::Vector2f(_idbox.getGlobalBounds().width / 2, _idbox.getGlobalBounds().height / 2));
	_idbox.setPosition(sf::Vector2f(_data->_window->getSize().x / 2, 150.0f));

	_firstnamebox.setSize(sf::Vector2f(350.0f, 50.0f));
	_firstnamebox.setFillColor(sf::Color(214, 219, 223, 240));
	_firstnamebox.setOrigin(sf::Vector2f(_firstnamebox.getGlobalBounds().width / 2, _firstnamebox.getGlobalBounds().height / 2));
	_firstnamebox.setPosition(sf::Vector2f(_data->_window->getSize().x / 2, 240.0f));

	_lastnamebox.setSize(sf::Vector2f(350.0f, 50.0f));
	_lastnamebox.setFillColor(sf::Color(214, 219, 223, 240));
	_lastnamebox.setOrigin(sf::Vector2f(_lastnamebox.getGlobalBounds().width / 2, _lastnamebox.getGlobalBounds().height / 2));
	_lastnamebox.setPosition(sf::Vector2f(_data->_window->getSize().x / 2, 330.0f));

	_genderbox.setSize(sf::Vector2f(350.0f, 50.0f));
	_genderbox.setFillColor(sf::Color(214, 219, 223, 240));
	_genderbox.setOrigin(sf::Vector2f(_genderbox.getGlobalBounds().width / 2, _genderbox.getGlobalBounds().height / 2));
	_genderbox.setPosition(sf::Vector2f(_data->_window->getSize().x / 2, 420.0f));

	_dobbox.setSize(sf::Vector2f(350.0f, 50.0f));
	_dobbox.setFillColor(sf::Color(214, 219, 223, 240));
	_dobbox.setOrigin(sf::Vector2f(_dobbox.getGlobalBounds().width / 2, _dobbox.getGlobalBounds().height / 2));
	_dobbox.setPosition(sf::Vector2f(_data->_window->getSize().x / 2, 510.0f));

	_socialIDbox.setSize(sf::Vector2f(350.0f, 50.0f));
	_socialIDbox.setFillColor(sf::Color(214, 219, 223, 240));
	_socialIDbox.setOrigin(sf::Vector2f(_socialIDbox.getGlobalBounds().width / 2, _socialIDbox.getGlobalBounds().height / 2));
	_socialIDbox.setPosition(sf::Vector2f(_data->_window->getSize().x / 2, 600.0f));

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color(0, 76, 153, 255));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 350);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("EXIT");
	_exit.setCharacterSize(24);
	sf::FloatRect textRect = _exit.getLocalBounds();
	_exit.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 350);
	_exit.setFillColor(sf::Color::White);

	std::ifstream f("Studentbuf.txt");
	getline(f, tmp);
	f.close();
	std::ifstream file("Student\\" + tmp + ".txt");
	std::string get;
	getline(file, get, ',');
	for(int l = 0 ; l < 5 ; l++)
	{
		getline(file, get , ',');
		_info[l].setFont(_data->_assets->GetFont(CHIVOMONO_REGULAR));
		_info[l].setString(get);
		_info[l].setCharacterSize(28);
		_info[l].setStyle(sf::Text::Italic);
		_info[l].setPosition(sf::Vector2f(_data->_window->getSize().x / 2 - 165.0f, 130.0f + 90.0f * l));
		_info[l].setFillColor(sf::Color::Black);
	}
	getline(file, get);
	_info[5].setFont(_data->_assets->GetFont(CHIVOMONO_REGULAR));
	_info[5].setString(get);
	_info[5].setCharacterSize(28);
	_info[5].setStyle(sf::Text::Italic);
	_info[5].setPosition(sf::Vector2f(_data->_window->getSize().x / 2 - 165.0f, 130.0f + 90.0f * 5));
	_info[5].setFillColor(sf::Color::Black);

	while (!file.eof())
	{
		getline(file, get);
	}
	file.close();

	_info[0].setString(_info[0].getString());
	_info[1].setString(_info[1].getString());
	_info[2].setString(_info[2].getString());
	_info[3].setString(_info[3].getString());
	_info[4].setString(_info[4].getString());
	_info[5].setString(_info[5].getString());
	
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
	(_exitfocus ? _exitbutton.setFillColor(sf::Color(0, 76, 153, 100)) : _exitbutton.setFillColor(sf::Color(0, 76, 153, 255)));
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
	_data->_window->draw(_firstnamebox);
	_data->_window->draw(_lastnamebox);
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
	for (int i = 0; i < 6; i++)
	{
		_data->_window->draw(_info[i]);
	}
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_exit);
	_data->_window->display();
}
