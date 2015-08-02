#include "Utils.h"
#include "App.h"
#include "Engine.h"
#include "ShipRace.h"
#include "TitleScreen.h"

int WINAPI _tWinMain(HINSTANCE hInstance, 
	HINSTANCE prevHInstance, 
	LPTSTR cmd, int showCmd)
{
	Engine* engine = new Engine(hInstance, "SpriteApp", 1280, 720);
	gEngine = engine;

	engine->Init();

	TitleScreen* titleScreen = new TitleScreen();

	int assert = gEngine->Run();

	gEngine->ClearComponents();
	delete engine;

	return assert;
}
