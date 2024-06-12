#include "System.h"
#include"SplashScreen.h"
#include"Staff.h"
#include"NotStaff.h"
System::System() : _data(new Data) 
{
	_data->_window->create(sf::VideoMode(1600, 900), "Portal", sf::Style::Close);
	_data->_states->AddState(new SplashScreen(_data));
	Run();

}
System::~System()
{
}
void System::Run()
{

	sf::Clock clock;
	sf::Time timeSinceLastFrame = sf::Time::Zero;

	while (_data->_window->isOpen())
	{
		timeSinceLastFrame += clock.restart();
		while (timeSinceLastFrame > TIME_PER_FRAME)
		{
			timeSinceLastFrame -= TIME_PER_FRAME;
			_data->_states->ProcessStateChange();
			_data->_states->GetCurrentState()->ProcessInput();
			_data->_states->GetCurrentState()->Update();
			_data->_states->GetCurrentState()->Draw();


		}
	}
}
