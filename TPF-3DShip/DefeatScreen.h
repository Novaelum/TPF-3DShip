#pragma once
#include "Scene.h"

class DefeatScreen : public Scene
{
public:
	DefeatScreen();
	~DefeatScreen();

	void Update();
	void Kill() { delete this; }

	void SetAllActive();
	void SetAllInactive();

private:
	Sprite* m_background;

	irrklang::ISoundSource* m_soundtrack;
};

