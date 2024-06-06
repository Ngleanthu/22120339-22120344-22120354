#include "LoginForm.h"
#include"Staff.h"
#include"NotStaff.h"
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

	_data->_assets->AddTexture(PROFILE_ICON, "Asset\\profile-icon.png");

	_loginformbox.setSize(sf::Vector2f(500, 500));
	_loginformbox.setFillColor(sf::Color(153, 204, 255, 180));
	_loginformbox.setOrigin(sf::Vector2f(_loginformbox.getGlobalBounds().width / 2, _loginformbox.getGlobalBounds().height / 2));
	_loginformbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);

	_profileicon.setTexture(_data->_assets->GetTexture(PROFILE_ICON));
	_profileicon.setScale(0.3f, 0.3f);
	_profileicon.setOrigin(_profileicon.getLocalBounds().width / 2, _profileicon.getLocalBounds().height / 2);
	_profileicon.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 270);

	_usernamebox.setSize(sf::Vector2f(300, 40));
	_usernamebox.setFillColor(sf::Color::White);
	_usernamebox.setOrigin(sf::Vector2f(_usernamebox.getGlobalBounds().width / 2, _usernamebox.getGlobalBounds().height / 2));
	_usernamebox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 100);
	_usernamebox.setOutlineThickness(1);
	_usernamebox.setOutlineColor(sf::Color::Black);

	_passwordbox.setSize(sf::Vector2f(300, 40));
	_passwordbox.setFillColor(sf::Color::White);
	_passwordbox.setOrigin(sf::Vector2f(_passwordbox.getGlobalBounds().width / 2, _passwordbox.getGlobalBounds().height / 2));
	_passwordbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);
	_passwordbox.setOutlineThickness(1);
	_passwordbox.setOutlineColor(sf::Color::Black);

	_username.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_username.setString("Username: ");
	_username.setCharacterSize(25);
	_username.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 160);
	_username.setFillColor(sf::Color::Black);

	_password.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_password.setString("Password: ");
	_password.setCharacterSize(25);
	_password.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 60);
	_password.setFillColor(sf::Color::Black);

	_submitbutton.setSize(sf::Vector2f(160, 40));
	_submitbutton.setFillColor(sf::Color(0, 76, 153, 255));
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 100);

	_exitbutton.setSize(sf::Vector2f(160, 40));
	_exitbutton.setFillColor(sf::Color(0, 76, 153, 255));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 150);

	_submit.setFont(_data->_assets->GetFont(KANIT));
	_submit.setString("SUBMIT");
	_submit.setCharacterSize(24);
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 95);
	_submit.setFillColor(sf::Color::White);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("EXIT");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 145);
	_exit.setFillColor(sf::Color::White);

	_showusername.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_showusername.setCharacterSize(24);
	_showusername.setFillColor(sf::Color::Black);
	_showusername.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 115);
	_showusername.setString("");

	_showpassword.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_showpassword.setCharacterSize(24);
	_showpassword.setFillColor(sf::Color::Black);
	_showpassword.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 15);
	_showpassword.setString("");

	_status.setCharacterSize(22);
	_status.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_status.setStyle(sf::Text::Italic);
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
	(_exitfocus ? _exitbutton.setFillColor(sf::Color(0, 76, 153, 100)) : _exitbutton.setFillColor(sf::Color(0, 76, 153, 200)));
	(_submitfocus ? _submitbutton.setFillColor(sf::Color(0, 76, 153, 100)) : _submitbutton.setFillColor(sf::Color(0, 76, 153, 200)));
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
			else
			{
				_data->_states->AddState(new NotStaff(_data), 1);
				std::ofstream file("username.txt");
				file << _getusername;
				std::ofstream fout("Studentbuf.txt");
				fout << _getusername;
				file.close();
				fout.close();
			}
		}
		else
		{
			_status.setString("Username haven't existed or wrong password!");
			sf::FloatRect textRect = _status.getLocalBounds();
			_status.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
			_status.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 280);
		}
		_submitselected = 0;
	}
}
void LoginForm::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_loginformbox);
	_data->_window->draw(_profileicon);
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