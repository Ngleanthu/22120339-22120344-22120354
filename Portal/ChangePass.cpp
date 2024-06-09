#include "ChangePass.h"
#include"AccountHandle.h"
ChangePass::ChangePass(Data* data) : _data(data), _oldpassfocus(0), _passwordfocus(0), _passwordfocus2(0), _blink(1),
_exitfocus(0), _submitfocus(0), _exitselected(0), _submitselected(0)
{

}
ChangePass::~ChangePass()
{

}
void ChangePass::Init()
{

	time = sf::Time::Zero;

	std::ifstream file("buffer.txt");
	getline(file, username);
	file.clear();
	file.close();

	_changeform.setSize(sf::Vector2f(500, 600));
	_changeform.setFillColor(sf::Color(153, 204, 255, 180));
	_changeform.setOrigin(sf::Vector2f(_changeform.getGlobalBounds().width / 2, _changeform.getGlobalBounds().height / 2));
	_changeform.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);
	
	_oldpassbox.setSize(sf::Vector2f(300, 40));
	_oldpassbox.setFillColor(sf::Color::White);
	_oldpassbox.setOrigin(sf::Vector2f(_oldpassbox.getGlobalBounds().width / 2, _oldpassbox.getGlobalBounds().height / 2));
	_oldpassbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 135);
	_oldpassbox.setOutlineThickness(1);
	_oldpassbox.setOutlineColor(sf::Color::Black);

	_passwordbox.setSize(sf::Vector2f(300, 40));
	_passwordbox.setFillColor(sf::Color::White);
	_passwordbox.setOrigin(sf::Vector2f(_passwordbox.getGlobalBounds().width / 2, _passwordbox.getGlobalBounds().height / 2));
	_passwordbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 35);
	_passwordbox.setOutlineThickness(1);
	_passwordbox.setOutlineColor(sf::Color::Black);

	_passwordbox2.setSize(sf::Vector2f(300, 40));
	_passwordbox2.setFillColor(sf::Color::White);
	_passwordbox2.setOrigin(sf::Vector2f(_passwordbox2.getGlobalBounds().width / 2, _passwordbox2.getGlobalBounds().height / 2));
	_passwordbox2.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 65);
	_passwordbox2.setOutlineThickness(1);
	_passwordbox2.setOutlineColor(sf::Color::Black);

	_oldpass.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_oldpass.setString("Current password: ");
	_oldpass.setCharacterSize(25);
	_oldpass.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 195);
	_oldpass.setFillColor(sf::Color::Black);

	_password.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_password.setString("New password: ");
	_password.setCharacterSize(25);
	_password.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 95);
	_password.setFillColor(sf::Color::Black);

	_password2.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_password2.setString("Confirm password: ");
	_password2.setCharacterSize(25);
	_password2.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 5);
	_password2.setFillColor(sf::Color::Black);

	_submitbutton.setSize(sf::Vector2f(160, 40));
	_submitbutton.setFillColor(sf::Color(0, 76, 153, 255));
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 150);

	_exitbutton.setSize(sf::Vector2f(160, 40));
	_exitbutton.setFillColor(sf::Color(0, 76, 153, 255));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 200);

	_submit.setFont(_data->_assets->GetFont(KANIT));
	_submit.setString("SUBMIT");
	_submit.setCharacterSize(24);
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 145);
	_submit.setFillColor(sf::Color::White);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("EXIT");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 195);
	_exit.setFillColor(sf::Color::White);

	_showoldpass.setFont(_data->_assets->GetFont(LIGHT));
	_showoldpass.setCharacterSize(24);
	_showoldpass.setFillColor(sf::Color::Black);
	_showoldpass.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 150);
	_showoldpass.setString("");

	_showpassword.setFont(_data->_assets->GetFont(LIGHT));
	_showpassword.setCharacterSize(24);
	_showpassword.setFillColor(sf::Color::Black);
	_showpassword.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 50);
	_showpassword.setString("");

	_showpassword2.setFont(_data->_assets->GetFont(LIGHT));
	_showpassword2.setCharacterSize(24);
	_showpassword2.setFillColor(sf::Color::Black);
	_showpassword2.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 50);
	_showpassword2.setString("");

	_status.setCharacterSize(24);
	_status.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_status.setStyle(sf::Text::Italic);
	_status.setFillColor(sf::Color::Red);
}
void ChangePass::ProcessInput()
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
			_oldpassfocus = (_oldpassbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_passwordfocus = (_passwordbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_passwordfocus2 = (_passwordbox2.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_exitselected = (_exitfocus ? 1 : 0);
			_submitselected = (_submitfocus ? 1 : 0);
			_blink = 1;
		}

		if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (event.text.unicode < 128)
			{
				if (_oldpassfocus)
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
					{
						if (!_getoldpass.empty())
						{
							_getoldpass.pop_back();
						}
					}
					else
					{
						_getoldpass += static_cast<char>(event.text.unicode);
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
				if (_passwordfocus2)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
					{
						if (!_getpassword2.empty())
						{
							_getpassword2.pop_back();
							showpassword2.pop_back();
						}
					}
					else
					{
						_getpassword2 += static_cast<char>(event.text.unicode);
						showpassword2 += "*";
					}

					_blink = 1;
				}
			}
		}

	}

}
void ChangePass::Update()
{

	time = clock.getElapsedTime();
	if (time.asSeconds() >= 0.5)
	{
		_blink = !_blink;
		clock.restart();
	}
	_showoldpass.setString(_getoldpass + ((_blink && _oldpassfocus) ? "|" : ""));
	_showpassword.setString(showpassword + ((_blink && _passwordfocus) ? "|" : ""));
	_showpassword2.setString(showpassword2 + ((_blink && _passwordfocus2) ? "|" : ""));
	(_exitfocus ? _exitbutton.setFillColor(sf::Color(0, 76, 153, 100)) : _exitbutton.setFillColor(sf::Color(0, 76, 153, 255)));
	(_submitfocus ? _submitbutton.setFillColor(sf::Color(0, 76, 153, 100)) : _submitbutton.setFillColor(sf::Color(0, 76, 153, 255)));
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;
	}
	if (_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{

		if (_getpassword.empty() || _getoldpass.empty() || _getpassword2.empty())
		{
			_status.setString("Please fill in all the blank!");
		}
		else if (_getpassword != _getpassword2)
		{
			_status.setString("Wrong confirmation!");
		}
		else if (ChangePassword(username , _getoldpass , _getpassword))
		{
			_status.setString("Update success!");
		}
		else
		{
			_status.setString("Incorrect current password!");
		}

		sf::FloatRect textRect = _status.getLocalBounds();
		_status.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		_status.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 320);

		_submitselected = 0;
	}
}
void ChangePass::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_changeform);
	_data->_window->draw(_oldpassbox);
	_data->_window->draw(_passwordbox);
	_data->_window->draw(_passwordbox2);
	_data->_window->draw(_oldpass);
	_data->_window->draw(_password);
	_data->_window->draw(_password2);
	_data->_window->draw(_submitbutton);
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_submit);
	_data->_window->draw(_exit);
	_data->_window->draw(_showoldpass);
	_data->_window->draw(_showpassword);
	_data->_window->draw(_showpassword2);
	_data->_window->draw(_status);
	_data->_window->display();
}