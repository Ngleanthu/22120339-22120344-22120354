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
	
	_oldpassbox.setSize(sf::Vector2f(300, 40));
	_oldpassbox.setFillColor(sf::Color::White);
	_oldpassbox.setOrigin(sf::Vector2f(_oldpassbox.getGlobalBounds().width / 2, _oldpassbox.getGlobalBounds().height / 2));
	_oldpassbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 100);
	_oldpassbox.setOutlineThickness(1);
	_oldpassbox.setOutlineColor(sf::Color::Red);

	_passwordbox.setSize(sf::Vector2f(300, 40));
	_passwordbox.setFillColor(sf::Color::White);
	_passwordbox.setOrigin(sf::Vector2f(_passwordbox.getGlobalBounds().width / 2, _passwordbox.getGlobalBounds().height / 2));
	_passwordbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);
	_passwordbox.setOutlineThickness(1);
	_passwordbox.setOutlineColor(sf::Color::Red);

	_passwordbox2.setSize(sf::Vector2f(300, 40));
	_passwordbox2.setFillColor(sf::Color::White);
	_passwordbox2.setOrigin(sf::Vector2f(_passwordbox2.getGlobalBounds().width / 2, _passwordbox2.getGlobalBounds().height / 2));
	_passwordbox2.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 100);
	_passwordbox2.setOutlineThickness(1);
	_passwordbox2.setOutlineColor(sf::Color::Red);

	_oldpass.setFont(_data->_assets->GetFont(LIGHT));
	_oldpass.setString("Current password");
	_oldpass.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 160);
	_oldpass.setFillColor(sf::Color::Black);

	_password.setFont(_data->_assets->GetFont(LIGHT));
	_password.setString("Expected password");
	_password.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 60);
	_password.setFillColor(sf::Color::Black);

	_password2.setFont(_data->_assets->GetFont(LIGHT));
	_password2.setString("Confirm password");
	_password2.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 40);
	_password2.setFillColor(sf::Color::Black);

	_submitbutton.setSize(sf::Vector2f(150, 40));
	_submitbutton.setFillColor(sf::Color::Red);
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 150);

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color::Black);
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 200);

	_submit.setFont(_data->_assets->GetFont(LIGHT));
	_submit.setString("Submit");
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 145);
	_submit.setFillColor(sf::Color::Black);

	_exit.setFont(_data->_assets->GetFont(LIGHT));
	_exit.setString("Exit");
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 195);
	_exit.setFillColor(sf::Color::Red);

	_showoldpass.setFont(_data->_assets->GetFont(LIGHT));
	_showoldpass.setCharacterSize(24);
	_showoldpass.setFillColor(sf::Color::Black);
	_showoldpass.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 115);
	_showoldpass.setString("");

	_showpassword.setFont(_data->_assets->GetFont(LIGHT));
	_showpassword.setCharacterSize(24);
	_showpassword.setFillColor(sf::Color::Black);
	_showpassword.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 - 15);
	_showpassword.setString("");

	_showpassword2.setFont(_data->_assets->GetFont(LIGHT));
	_showpassword2.setCharacterSize(24);
	_showpassword2.setFillColor(sf::Color::Black);
	_showpassword2.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 85);
	_showpassword2.setString("");


	_status.setCharacterSize(20);
	_status.setFont(_data->_assets->GetFont(LIGHT));
	_status.setPosition(_data->_window->getSize().x / 2 - 150, _data->_window->getSize().y / 2 + 245);
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
	(_exitfocus ? _exitbutton.setFillColor(sf::Color::Yellow) : _exitbutton.setFillColor(sf::Color::Black));
	(_submitfocus ? _submitbutton.setFillColor(sf::Color::Yellow) : _submitbutton.setFillColor(sf::Color::Red));
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;
	}
	if (_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{

		if (_getpassword.empty())
		{
			_status.setString("Expected password can't be blanked");
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
			_status.setString("Incorrect current password");
		}
		_submitselected = 0;

	}
}
void ChangePass::Draw()
{
	_data->_window->clear(sf::Color::White);
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