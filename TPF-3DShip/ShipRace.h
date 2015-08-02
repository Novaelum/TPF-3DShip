#pragma once

#include "Component.h"
#include "TriGrid.h"
#include "Ship.h"
#include "Engine.h"
#include "Obstacle.h"
#include "Scene.h"
#include "Gutils.h"

class ShipRace : public Scene
{
public:
	ShipRace();
	~ShipRace();

	void Start();
	void Update();
	void Draw();
	void Stop();
	void Kill()		{ delete this; }

	void SetAllActive();
	void SetAllInactive();

	void Reset();

private:
	const int OBSTACLE_COUNT = 25;

	void SpawnObstacles();
	void CheckCollisions();
	void Defeated();

	Ship* m_player;
	TriGrid* m_triGrid;
	std::vector<Obstacle*> m_obstacles;
	irrklang::ISoundSource* m_soundtrack;

};

