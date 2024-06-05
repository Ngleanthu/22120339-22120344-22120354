#pragma once
#include"State.h"
#include"System.h"
class NotStaff : public State
{
private:
	Data* _data;
	


public:
	NotStaff(Data* data);
	~NotStaff();
	void Init();
	void ProcessInput();
	void Update();
	void Draw();
};

