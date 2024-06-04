#pragma once
#include"StateMachine.h"


struct Data
{
	StateMachine* _states;
	Data()
	{
		_states = new StateMachine;
	}
};
class System
{
private:
	Data* _data;
public:
	System();
	void Run();
};



