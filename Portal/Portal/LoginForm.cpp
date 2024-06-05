#include "LoginForm.h"
#include"Staff.h"

LoginForm::LoginForm(Data* data): _data(data), _usernamefocus(0), _passwordfocus(0), _blink(1), _exitfocus(0),
	_submitfocus(0) , _exitselected(0) , _submitselected(0)
{

}
LoginForm::~LoginForm()
{

}
void LoginForm::Init()
{


	time = sf::Time::Zero;

	_usernamebox.setSize(sf::Vector2f(300, 40));
	_usernamebox.setFillColor(sf::Color::White);
	_usernamebox.setOrigin(sf::Vector2f(_usernamebox.getGlobalBounds().width / 2, _usernamebox.getGlobalBounds().height / 2));
	_usernamebox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 100);
	_usernamebox.setOutlineThickness(1);
	_usernamebox.setOutlineColor(sf::Color::Red);

	_passwordbox.setSize(sf::Vector2f(300, 40));
	_passwordbox.setFillColor(sf::Color::White);
	_passwordbox.setOrigin(sf::Vector2f(_passwordbox.getGlobalBounds().width / 2, _passwordbox.getGlobalBounds().height / 2));
	_passwordbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);
	_passwordbox.setOutlineThickness(1);
	_passwordbox.setOutlineColor(sf::Color::Red);

	_username.setFont(_data->_assets->GetFont(LIGHT));
	_username.setString("Username");
	_username.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 160);
	_username.setFillColor(sf::Color::Black);

	_password.setFont(_data->_assets->GetFont(LIGHT));
	_password.setString("Password");
	_password.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 60);
	_password.setFillColor(sf::Color::Black);

	_submitbutton.setSize(sf::Vector2f(150, 40));
	_submitbutton.setFillColor(sf::Color::Red);
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 100);

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color::Black);
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 150);

	_submit.setFont(_data->_assets->GetFont(LIGHT));
	_submit.setString("Submit");
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 95);
	_submit.setFillColor(sf::Color::Black);

	_exit.setFont(_data->_assets->GetFont(LIGHT));
	_exit.setString("Exit");
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 145);
	_exit.setFillColor(sf::Color::Red);

	_showusername.setFont(_data->_assets->GetFont(LIGHT));
	_showusername.setCharacterSize(24);
	_showusername.setFillColor(sf::Color::Black);
	_showusername.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 115);
	_showusername.setString("");

	_showpassword.setFont(_data->_assets->GetFont(LIGHT));
	_showpassword.setCharacterSize(24);
	_showpassword.setFillColor(sf::Color::Black);
	_showpassword.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 15);
	_showpassword.setString("");
	
	_status.setCharacterSize(20);
	_status.setFont(_data->_assets->GetFont(LIGHT));
	_status.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 245);
	_status.setFillColor(sf::Color::Red);
}
void LoginForm::ProcessInput()
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
			_usernamefocus = (_usernamebox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_passwordfocus = (_passwordbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_exitselected = (_exitfocus ? 1 : 0);
			_submitselected = (_submitfocus ? 1 : 0);
			_blink = 1;
		}
		
		if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (event.text.unicode < 128)
			{
				if (_usernamefocus)
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
					{
						if (!_getusername.empty())
						{
							_getusername.pop_back();
						}
					}
					else
					{
						_getusername += static_cast<char>(event.text.unicode);
					}
				_blink = 1;
				if (_passwordfocus)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
					{
						if (!_getpassword.empty())
						{
							_getpassword.pop_back();
							showpassword.pop_back();
						}
					}
					else
					{
						_getpassword += static_cast<char>(event.text.unicode);
						showpassword += "*";
					}

					_blink = 1;
				}
			}
		}

	}

}
void LoginForm::Update()
{

	time = clock.getElapsedTime();
	if (time.asSeconds() >= 0.5)
	{
		_blink = !_blink;
		clock.restart();
	}
	_showusername.setString(_getusername + ((_blink && _usernamefocus) ? "|" : ""));
	_showpassword.setString(showpassword + ((_blink && _passwordfocus) ? "|" : ""));
	(_exitfocus ? _exitbutton.setFillColor(sf::Color::Yellow) : _exitbutton.setFillColor(sf::Color::Black));
	(_submitfocus ? _submitbutton.setFillColor(sf::Color::Yellow) : _submitbutton.setFillColor(sf::Color::Red));
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;
	}
	if (_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (LoginSuccess(_getusername, _getpassword))
		{
			if (isStaff(_getusername))
			{
				_data->_states->AddState(new Staff(_data) , 1);
				std::ofstream file("username.txt");
				file << _getusername;
			}
		}
		else
		{
			_status.setString("Username haven't existed or wrong password!");
		}
		_submitselected = 0;
	}
}
void LoginForm::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_usernamebox);
	_data->_window->draw(_passwordbox);
	_data->_window->draw(_username);
	_data->_window->draw(_password);
	_data->_window->draw(_submitbutton);
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_submit);
	_data->_window->draw(_exit);
	_data->_window->draw(_showusername);
	_data->_window->draw(_showpassword);
	_data->_window->draw(_status);
	_data->_window->display();
}