#pragma once
class State
{
public:
	virtual void Init() = 0;
	virtual void ProcessInput() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

