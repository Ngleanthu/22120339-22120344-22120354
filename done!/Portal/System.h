#pragma once
#include"AssetManager.h"
#include"StateMachine.h"


struct Data
{
	AssetManager* _assets;
	StateMachine* _states;
	sf::RenderWindow* _window;
	Data()
	{
		_assets = new AssetManager;
		_states = new StateMachine;
		_window = new sf::RenderWindow;
	}
};
class System
{
private:
	Data* _data;
	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
public:
	System();
	~System();
	void Run();
};


