#pragma once
#include "Scene.h"

class TitleScreen : public Scene
{
public:
	TitleScreen();
	~TitleScreen();

	void Update();
	void Kill() { delete this; }

	void SetAllActive();
	void SetAllInactive();

private:
	Sprite* m_background;
	irrklang::ISoundSource* m_soundtrack;
};

