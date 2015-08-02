#pragma once
#include "Component.h"
#include "Engine.h"

class Screen : Component
{
public:
	Screen() {}
	~Screen() {}

protected:
	Sprite* m_background;
	bool m_deletionCalled;
};

