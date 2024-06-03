#include "SplashScreen.h"
#include<iostream>
#include"LoginForm.h"

SplashScreen::SplashScreen(Data* data) : _data(data), _loginfocus(0), _registerfocus(0),
_loginselected(0), _registerselected(0)
{

}
SplashScreen::~SplashScreen()
{

}
void SplashScreen::Init()
{
	_data->_assets->AddTexture(HCMUS, "Asset\\hcmus.png");
	_data->_assets->AddFont(LIGHT , "Asset\\Light.ttf");

	_logo.setTexture(_data->_assets->GetTexture(HCMUS));
	_logo.setOrigin(_logo.getLocalBounds().width / 2, _logo.getLocalBounds().height / 2);
	_logo.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);


	_loginbutton.setFont(_data->_assets->GetFont(LIGHT));
	_loginbutton.setPosition(_data->_window->getSize().x - 150, 0);
	_loginbutton.setString("Login");
	_loginbutton.setFillColor(sf::Color::White);
	_loginbutton.setOutlineColor(sf::Color::Yellow);
	_loginbutton.setOutlineThickness(0.5);

	_registerbutton.setFont(_data->_assets->GetFont(LIGHT));
	_registerbutton.setPosition(_data->_window->getSize().x - 150, 50);
	_registerbutton.setString("Register");
	_registerbutton.setFillColor(sf::Color::White);
	_registerbutton.setOutlineColor(sf::Color::Yellow);
	_registerbutton.setOutlineThickness(0.5);


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
			_loginfocus = (_loginbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
			_registerfocus = (_registerbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);
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
	(_loginfocus ? _loginbutton.setFillColor(sf::Color::Red) : _loginbutton.setFillColor(sf::Color::White));
	(_registerfocus ? _registerbutton.setFillColor(sf::Color::Red) : _registerbutton.setFillColor(sf::Color::White));
	if (_loginselected)
	{
		_data->_states->AddState(new LoginForm(_data));
		_loginselected = 0;
	}
}
void SplashScreen::Draw()
{
	_data->_window->clear();
	_data->_window->draw(_logo);
	_data->_window->draw(_loginbutton);
	_data->_window->draw(_registerbutton);
	_data->_window->display();

}