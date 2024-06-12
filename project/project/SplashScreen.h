#pragma once
#include"State.h"
#include"System.h"
class SplashScreen : public State
{
private :
	StateMachine* _data;
public:
	SplashScreen(StateMachine* data);
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

