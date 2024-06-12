#include "RegisterForm.h"
#include "AccountHandle.h"
RegisterForm::RegisterForm(Data *data)
    : _data(data),
      _usernamefocus(0),
      _passwordfocus(0),
      _passwordfocus2(0),
      _blink(1),
      _exitfocus(0),
      _submitfocus(0),
      _exitselected(0),
      _submitselected(0)
{}
RegisterForm::~RegisterForm() {}
void RegisterForm::Init()
{
    time = sf::Time::Zero;

    _registerform.setSize(sf::Vector2f(550, 600));
    _registerform.setFillColor(sf::Color(153, 204, 255, 180));
    _registerform.setOrigin(sf::Vector2f(_registerform.getGlobalBounds().width / 2,
                                         _registerform.getGlobalBounds().height / 2));
    _registerform.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);

    _usernamebox.setSize(sf::Vector2f(300, 40));
    _usernamebox.setFillColor(sf::Color::White);
    _usernamebox.setOrigin(sf::Vector2f(_usernamebox.getGlobalBounds().width / 2,
                                        _usernamebox.getGlobalBounds().height / 2));
    _usernamebox.setPosition(_data->_window->getSize().x / 2,
                             _data->_window->getSize().y / 2 - 150);
    _usernamebox.setOutlineThickness(1);
    _usernamebox.setOutlineColor(sf::Color::Black);

    _passwordbox.setSize(sf::Vector2f(300, 40));
    _passwordbox.setFillColor(sf::Color::White);
    _passwordbox.setOrigin(sf::Vector2f(_passwordbox.getGlobalBounds().width / 2,
                                        _passwordbox.getGlobalBounds().height / 2));
    _passwordbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 50);
    _passwordbox.setOutlineThickness(1);
    _passwordbox.setOutlineColor(sf::Color::Black);

    _passwordbox2.setSize(sf::Vector2f(300, 40));
    _passwordbox2.setFillColor(sf::Color::White);
    _passwordbox2.setOrigin(sf::Vector2f(_passwordbox2.getGlobalBounds().width / 2,
                                         _passwordbox2.getGlobalBounds().height / 2));
    _passwordbox2.setPosition(_data->_window->getSize().x / 2,
                              _data->_window->getSize().y / 2 + 50);
    _passwordbox2.setOutlineThickness(1);
    _passwordbox2.setOutlineColor(sf::Color::Black);

    _username.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _username.setString("Username: ");
    _username.setCharacterSize(25);
    _username.setPosition(_data->_window->getSize().x / 2 - 150,
                          _data->_window->getSize().y / 2 - 210);
    _username.setFillColor(sf::Color::Black);

    _password.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _password.setString("Password: ");
    _password.setCharacterSize(25);
    _password.setPosition(_data->_window->getSize().x / 2 - 150,
                          _data->_window->getSize().y / 2 - 110);
    _password.setFillColor(sf::Color::Black);

    _password2.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _password2.setString("Confirm password: ");
    _password2.setCharacterSize(25);
    _password2.setPosition(_data->_window->getSize().x / 2 - 150,
                           _data->_window->getSize().y / 2 - 10);
    _password2.setFillColor(sf::Color::Black);

    _submitbutton.setSize(sf::Vector2f(150, 40));
    _submitbutton.setFillColor(sf::Color(0, 76, 153, 255));
    _submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2,
                                         _submitbutton.getGlobalBounds().height / 2));
    _submitbutton.setPosition(_data->_window->getSize().x / 2,
                              _data->_window->getSize().y / 2 + 160);

    _exitbutton.setSize(sf::Vector2f(150, 40));
    _exitbutton.setFillColor(sf::Color(0, 76, 153, 255));
    _exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2,
                                       _exitbutton.getGlobalBounds().height / 2));
    _exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 210);

    _submit.setFont(_data->_assets->GetFont(KANIT));
    _submit.setString("SUBMIT");
    _submit.setCharacterSize(24);
    _submit.setOrigin(
        sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
    _submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 155);
    _submit.setFillColor(sf::Color::White);

    _exit.setFont(_data->_assets->GetFont(KANIT));
    _exit.setString("EXIT");
    _exit.setCharacterSize(24);
    _exit.setOrigin(
        sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
    _exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 205);
    _exit.setFillColor(sf::Color::White);

    _showusername.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _showusername.setCharacterSize(24);
    _showusername.setFillColor(sf::Color::Black);
    _showusername.setPosition(_data->_window->getSize().x / 2 - 153,
                              _data->_window->getSize().y / 2 - 165);
    _showusername.setString("");

    _showpassword.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _showpassword.setCharacterSize(24);
    _showpassword.setFillColor(sf::Color::Black);
    _showpassword.setPosition(_data->_window->getSize().x / 2 - 153,
                              _data->_window->getSize().y / 2 - 65);
    _showpassword.setString("");

    _showpassword2.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _showpassword2.setCharacterSize(24);
    _showpassword2.setFillColor(sf::Color::Black);
    _showpassword2.setPosition(_data->_window->getSize().x / 2 - 153,
                               _data->_window->getSize().y / 2 + 36);
    _showpassword2.setString("");

    _status.setCharacterSize(22);
    _status.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
    _status.setStyle(sf::Text::Italic);
    _status.setFillColor(sf::Color::Red);
}
void RegisterForm::ProcessInput()
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
            _submitfocus = (_submitbutton.getGlobalBounds().contains(
                                sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                             sf::Mouse::getPosition(*_data->_window).y))
                                ? 1
                                : 0);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            _usernamefocus  = (_usernamebox.getGlobalBounds().contains(
                                  sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                                sf::Mouse::getPosition(*_data->_window).y))
                                   ? 1
                                   : 0);
            _passwordfocus  = (_passwordbox.getGlobalBounds().contains(
                                  sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                                sf::Mouse::getPosition(*_data->_window).y))
                                   ? 1
                                   : 0);
            _passwordfocus2 = (_passwordbox2.getGlobalBounds().contains(
                                   sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x,
                                                sf::Mouse::getPosition(*_data->_window).y))
                                   ? 1
                                   : 0);
            _exitselected   = (_exitfocus ? 1 : 0);
            _submitselected = (_submitfocus ? 1 : 0);
            _blink          = 1;
        }

        if (event.type == sf::Event::TextEntered &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            if (event.text.unicode < 128)
            {
                if (_usernamefocus)
                {
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
void RegisterForm::Update()
{
    time = clock.getElapsedTime();
    if (time.asSeconds() >= 0.5)
    {
        _blink = !_blink;
        clock.restart();
    }
    _showusername.setString(_getusername + ((_blink && _usernamefocus) ? "|" : ""));
    _showpassword.setString(showpassword + ((_blink && _passwordfocus) ? "|" : ""));
    _showpassword2.setString(showpassword2 + ((_blink && _passwordfocus2) ? "|" : ""));
    (_exitfocus ? _exitbutton.setFillColor(sf::Color(0, 76, 153, 100))
                : _exitbutton.setFillColor(sf::Color(0, 76, 153, 255)));
    (_submitfocus ? _submitbutton.setFillColor(sf::Color(0, 76, 153, 100))
                  : _submitbutton.setFillColor(sf::Color(0, 76, 153, 255)));
    if (_exitselected)
    {
        _data->_states->RemoveState();
        _exitselected = 0;
    }
    if (_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        if (_getusername.empty() || _getpassword.empty())
        {
            _status.setString("Username and password can't be blanked");
        }
        else if (_getpassword != _getpassword2)
        {
            _status.setString("Wrong confirmation!");
        }
        else if (RegisterSuccess(_getusername, _getpassword))
        {
            _status.setString("Register success!");
        }
        else
        {
            _status.setString("Username has been existed");
        }
        sf::FloatRect textRect = _status.getLocalBounds();
        _status.setOrigin(textRect.left + textRect.width / 2.0f,
                          textRect.top + textRect.height / 2.0f);
        _status.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 330);
        _submitselected = 0;
    }
}
void RegisterForm::Draw()
{
    _data->_window->clear(sf::Color::White);
    _data->_window->draw(_registerform);
    _data->_window->draw(_usernamebox);
    _data->_window->draw(_passwordbox);
    _data->_window->draw(_passwordbox2);
    _data->_window->draw(_username);
    _data->_window->draw(_password);
    _data->_window->draw(_password2);
    _data->_window->draw(_submitbutton);
    _data->_window->draw(_exitbutton);
    _data->_window->draw(_submit);
    _data->_window->draw(_exit);
    _data->_window->draw(_showusername);
    _data->_window->draw(_showpassword);
    _data->_window->draw(_showpassword2);
    _data->_window->draw(_status);
    _data->_window->display();
}