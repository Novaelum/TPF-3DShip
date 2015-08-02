#include "SceneManager.h"

extern SceneManager* g_sceneManager = 0;

SceneManager::SceneManager()
{
	TitleScreen*	ts = new TitleScreen();
	m_Scenes.push_back(ts);
	DefeatScreen*	ds = new DefeatScreen();
	ds->SetAllInactive();
	m_Scenes.push_back(ds);
	ShipRace*		sr = new ShipRace();
	sr->SetAllInactive();
	m_Scenes.push_back(sr);

	g_sceneManager = this;
}


SceneManager::~SceneManager()
{
	// ClearComponents handle this part
}
