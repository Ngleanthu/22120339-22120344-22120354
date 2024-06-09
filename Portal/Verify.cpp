#include "Verify.h"
#include"RegisterForm.h"
Verify::Verify(Data* data): _data(data) , _boxfocus(0) , _blink(1), _exitfocus(0),
_submitfocus(0), _exitselected(0), _submitselected(0)
{

}
Verify::~Verify()
{

}
void Verify::Init()
{
	time = sf::Time::Zero;

	_box.setSize(sf::Vector2f(350, 50));
	_box.setFillColor(sf::Color::White);
	_box.setOrigin(sf::Vector2f(_box.getGlobalBounds().width / 2, _box.getGlobalBounds().height / 2));
	_box.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 - 100);
	_box.setOutlineThickness(1);
	_box.setOutlineColor(sf::Color::Red);

	_text.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_text.setString("Verify code: ");
	_text.setCharacterSize(25);
	_text.setPosition(_data->_window->getSize().x / 2 - 170, _data->_window->getSize().y / 2 - 160);
	_text.setFillColor(sf::Color::Black);

	_submitbutton.setSize(sf::Vector2f(150, 40));
	_submitbutton.setFillColor(sf::Color(0, 76, 153, 255));
	_submitbutton.setOrigin(sf::Vector2f(_submitbutton.getGlobalBounds().width / 2, _submitbutton.getGlobalBounds().height / 2));
	_submitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 100);

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color(0, 76, 153, 255));
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 150);

	_submit.setFont(_data->_assets->GetFont(KANIT));
	_submit.setString("SUBMIT");
	_submit.setCharacterSize(24);
	_submit.setOrigin(sf::Vector2f(_submit.getGlobalBounds().width / 2, _submit.getGlobalBounds().height / 2));
	_submit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 90);
	_submit.setFillColor(sf::Color::White);

	_exit.setFont(_data->_assets->GetFont(KANIT));
	_exit.setString("EXIT");
	_exit.setCharacterSize(24);
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 140);
	_exit.setFillColor(sf::Color::White);

	_showbox.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_showbox.setCharacterSize(24);
	_showbox.setFillColor(sf::Color::Black);
	_showbox.setPosition(_data->_window->getSize().x / 2 - 170, _data->_window->getSize().y / 2 - 115);
	_showbox.setString("");

	_status.setCharacterSize(20);
	_status.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_status.setStyle(sf::Text::Italic);
	_status.setFillColor(sf::Color::Red);
}
void Verify::ProcessInput()
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
void Verify::Update()
{
	time = clock.getElapsedTime();
	if (time.asSeconds() >= 0.5)
	{
		_blink = !_blink;
		clock.restart();
	}
	_showbox.setString(_getbox + ((_blink && _boxfocus) ? "|" : ""));
	(_exitfocus ? _exitbutton.setFillColor(sf::Color(0, 76, 153, 100)) : _exitbutton.setFillColor(sf::Color(0, 76, 153, 255)));
	(_submitfocus ? _submitbutton.setFillColor(sf::Color(0, 76, 153, 100)) : _submitbutton.setFillColor(sf::Color(0, 76, 153, 255)));
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;
	}
	if (_submitselected || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (_getbox == "PORTAL.HCMUS")
		{
			_data->_states->AddState(new RegisterForm(_data) , 1);
		}
		else
		{
			_status.setString("Wrong code!");
			sf::FloatRect textRect = _status.getLocalBounds();
			_status.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
			_status.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 200);
		}
		_submitselected = 0;
	}
}
void Verify::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_box);
	_data->_window->draw(_text);
	_data->_window->draw(_submitbutton);
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_submit);
	_data->_window->draw(_exit);
	_data->_window->draw(_showbox);
	_data->_window->draw(_status);
	_data->_window->display();
}