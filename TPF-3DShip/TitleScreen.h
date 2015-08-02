#pragma once
#include "Component.h"
#include "Engine.h"
#include "GUtils.h"


class TitleScreen : Component
{
public:
	TitleScreen();
	~TitleScreen();

	void Update();
	void Kill() { delete this; }

private:
	Sprite* m_background;
	bool m_deletionCalled;
};

