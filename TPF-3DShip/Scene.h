#pragma once
#include "GUtils.h"
#include "Component.h"
#include "Engine.h"
#include <irrKlang.h>

class Scene : public Component
{
public:
	Scene() {}
	~Scene() {}

	virtual void SetAllActive()		= 0;
	virtual void SetAllInactive()	= 0;
	
};

