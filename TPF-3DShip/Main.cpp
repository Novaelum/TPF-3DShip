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
	Sounds->LoadSound(Sound::TitleTheme_ID, MakePath(musicPath, "TitleTheme.mp3"));
	Sounds->LoadSound(Sound::DefeatTheme_ID, MakePath(musicPath, "DefeatTheme.mp3"));
	Sounds->LoadSound(Sound::RaceTheme_ID, MakePath(musicPath, "RaceTheme.mp3"));

	SceneManager* sceneManager = new SceneManager();

	int assert = gEngine->Run();

	gEngine->ClearComponents();
	delete engine;

	return assert;
}
