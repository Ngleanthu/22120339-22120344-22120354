#include "System.h"
#include <Windows.h>
#include "SplashScreen.h"
System::System() : _data(new StateMachine)
{
    _data->AddState(new SplashScreen(_data));
    Run();
}

void System::Run()
{
    while (1)
    {
        Sleep(60);
        _data->ProcessStateChange();
        _data->GetCurrentState()->ProcessInput();
        _data->GetCurrentState()->Update();
        _data->GetCurrentState()->Draw();
    }
}
