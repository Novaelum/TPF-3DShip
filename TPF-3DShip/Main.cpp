#include "Utils.h"
#include "App.h"
#include "Engine.h"
#include "ShipRace.h"
#include "TitleScreen.h"
#include "SceneManager.h"

int WINAPI _tWinMain(HINSTANCE hInstance, 
	HINSTANCE prevHInstance, 
	LPTSTR cmd, int showCmd)
{

	Engine* engine = new Engine(hInstance, "SpriteApp", 1280, 720);
	gEngine = engine;

	engine->Init();

	Textures->LoadTexture(Texture::TitleScreen_ID, MakePath(spritePath, "TitleScreen.jpg"));
	Textures->LoadTexture(Texture::DefeatScreen_ID, MakePath(spritePath, "DefeatScreen.jpg"));

	SceneManager* sceneManager = new SceneManager();

	int assert = gEngine->Run();

	gEngine->ClearComponents();
	delete engine;

	return assert;
}
