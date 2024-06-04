#include "System.h"
#include<Windows.h>
#include"Login.h"
System::System() : _data(new Data)
{
	_data->_states->AddState(new Login(_data));
	
	Run();

}
void System::Run()
{


	while (1)
	{
		Sleep(60);
		_data->_states->ProcessStateChange();
		_data->_states->GetCurrentState()->ProcessInput();
		_data->_states->GetCurrentState()->Update();
		_data->_states->GetCurrentState()->Draw();	
	}
}