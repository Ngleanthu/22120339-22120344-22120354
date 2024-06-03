#include "StateMachine.h"
StateMachine::StateMachine() : _add(0), _replace(0), _remove(0), _head(nullptr)
{

}
StateMachine::~StateMachine()
{

}
void StateMachine::AddState(State* state, bool replace)
{
	_add = 1;
	_replace = replace;
	_newState = state;
}
void StateMachine::RemoveState()
{
	_remove = 1;
}
void StateMachine::ProcessStateChange()
{
	if (_remove && _head != nullptr)
	{
		pop_front(_head);
		_remove = 0;
	}
	if (_add)
	{
		if (_head != nullptr)
		{
			if (_replace)
			{
				pop_front(_head);
			}
		}
		push_front(_head, _newState);
		_head->_state->Init();
		_add = 0;
	}
}
State*& StateMachine::GetCurrentState()
{
	return _head->_state;
}