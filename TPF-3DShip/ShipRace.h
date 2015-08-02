#pragma once

#include "Component.h"
#include "Triangle.h"
#include "Cube.h"
#include "TriGrid.h"
#include "Ship.h"
#include "Engine.h"
#include "Obstacle.h"

#include "Gutils.h"

class ShipRace :
	public Component
{
public:
	ShipRace();
	~ShipRace();

	void Start();
	void Update();
	void Draw();
	void Stop();

private:
	Obstacle* m_cube;
	Ship* m_player;
	TriGrid* m_triGrid;
};

