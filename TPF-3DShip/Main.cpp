#include "Utils.h"
#include "App.h"
#include "Engine.h"



int WINAPI _tWinMain(HINSTANCE hInstance, 
	HINSTANCE prevHInstance, 
	LPTSTR cmd, int showCmd)
{
	Engine* engine = new Engine(hInstance, "Peggle", 1280, 1024);
	gEngine = engine;

	gEngine->Init();

	int assert = gEngine->Run();

	delete engine;

	return assert;
}
