#include "SplashScreen.h"
#include<iostream>
#include"LoginForm.h"
#include"Verify.h"
SplashScreen::SplashScreen(Data* data) : _data(data), _loginfocus(0), _registerfocus(0),
_loginselected(0), _registerselected(0)
{

}
SplashScreen::~SplashScreen()
{

}
void SplashScreen::Init()
{
	_data->_assets->AddTexture(HCMUS, "Asset\\hcmus-background.png");
	_data->_assets->AddFont(LIGHT, "Asset\\Light.ttf");
	_data->_assets->AddTexture(LOGO_HCMUS, "Asset\\logo-khtn.png");
	_data->_assets->AddFont(HELVETICA_BOLD, "Asset\\Helvetica-Bold.ttf");
	_data->_assets->AddFont(CHIVOMONO_LIGHT, "Asset\\ChivoMono-Light.ttf");
	_data->_assets->AddFont(CHIVOMONO_REGULAR, "Asset\\ChivoMono-Regular.ttf");
	_data->_assets->AddFont(KANIT, "Asset\\Kanit-Regular.ttf");
	_data->_assets->AddTexture(LOGIN, "Asset\\log-in-pic.png");

	//_logo.setTexture(_data->_assets->GetTexture(HCMUS));
	//_logo.setOrigin(_logo.getLocalBounds().width / 2, _logo.getLocalBounds().height / 2);
	//_logo.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);

	_logo.setTexture(_data->_assets->GetTexture(LOGIN));
	//_logo.setScale(0.65f, 0.65f);
	_logo.setOrigin(_logo.getLocalBounds().width / 2, _logo.getLocalBounds().height / 2);
	_logo.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);

	_loginbox.setSize(sf::Vector2f(400.0f, 100.0f));
	_loginbox.setOrigin(_loginbox.getLocalBounds().width / 2, _loginbox.getLocalBounds().height / 2);
	//_loginbox.setPosition(sf::Vector2f(1133.0f, 324.0f));
	_loginbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);
	_loginbox.setFillColor(sf::Color(0, 76, 153, 255));

	_loginbutton.setFont(_data->_assets->GetFont(KANIT));
	_loginbutton.setString("LOG IN");
	_loginbutton.setStyle(sf::Text::Bold);
	_loginbutton.setFillColor(sf::Color::White);
	_loginbutton.setCharacterSize(40);
	sf::FloatRect textRect = _loginbutton.getLocalBounds();
	_loginbutton.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//_loginbutton.setPosition(sf::Vector2f(1133.0f, 324.0f));
	_loginbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);

	_registerbox.setSize(sf::Vector2f(400.0f, 100.0f));
	_registerbox.setOrigin(_registerbox.getLocalBounds().width / 2, _registerbox.getLocalBounds().height / 2);
	//_registerbox.setPosition(sf::Vector2f(1133.0f, 454.0f));
	_registerbox.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 130);
	_registerbox.setFillColor(sf::Color(0, 76, 153, 255));

	_registerbutton.setFont(_data->_assets->GetFont(KANIT));
	_registerbutton.setCharacterSize(30);
	_registerbutton.setString("Create student account\n        (for staff only)");
	_registerbutton.setStyle(sf::Text::Bold);
	_registerbutton.setFillColor(sf::Color::White);
	textRect = _registerbutton.getLocalBounds();
	_registerbutton.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//_registerbutton.setPosition(sf::Vector2f(1133.0f, 454.0f));
	_registerbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 130);
}
void SplashScreen::ProcessInput()
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
			_loginfocus = (_loginbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_registerfocus = (_registerbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_loginselected = (_loginfocus ? 1 : 0);
			_registerselected = (_registerfocus ? 1 : 0);
		}
		
	}

}
void SplashScreen::Update()
{
	(_loginfocus ? _loginbox.setFillColor(sf::Color(0, 76, 153, 120)) : _loginbox.setFillColor(sf::Color(0, 76, 153, 255)));
	(_registerfocus ? _registerbox.setFillColor(sf::Color(0, 76, 153, 120)) : _registerbox.setFillColor(sf::Color(0, 76, 153, 255)));
	if (_loginselected)
	{
		_data->_states->AddState(new LoginForm(_data));
		_loginselected = 0;
	}
	if (_registerselected)
	{
		_data->_states->AddState(new Verify(_data));
		_registerselected = 0;
	}
}
void SplashScreen::Draw()
{
	_data->_window->clear();
	_data->_window->draw(_logo);
	_data->_window->draw(_loginbox);
	_data->_window->draw(_loginbutton);
	_data->_window->draw(_registerbox);
	_data->_window->draw(_registerbutton);
	_data->_window->display();
}