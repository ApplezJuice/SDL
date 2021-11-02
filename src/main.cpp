#include "Core.h"


int main(int argc, char* args[])
{
	Core::GetInstance()->Init();

	while (Core::GetInstance()->IsRunning())
	{
		Core::GetInstance()->Update();
	}

	Core::GetInstance()->Clean();
	return 0;
}