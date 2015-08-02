#pragma once
#include "GUtils.h"
#include "Scene.h"
#include "TitleScreen.h"
#include "DefeatScreen.h"
#include "ShipRace.h"


class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	Scene* GetTitle()	{ return m_Scenes.at(0); }
	Scene* GetDefeat()	{ return m_Scenes.at(1); }
	Scene* GetRace()	{ return m_Scenes.at(2); }

private:
	std::vector<Scene*> m_Scenes;
};

extern SceneManager* g_sceneManager;


