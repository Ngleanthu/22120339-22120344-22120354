#pragma once
#include"Linklist.h"
class StateMachine 
{
private:
	List* _head ;
	State* _newState;
	bool _replace;
	bool _add;
	bool _remove;
public:
	StateMachine();
	~StateMachine();
	void AddState(State* state, bool replace = 0);
	void RemoveState();
	void ProcessStateChange();
	State*& GetCurrentState();
};

