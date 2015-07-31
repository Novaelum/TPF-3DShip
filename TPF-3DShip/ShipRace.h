#pragma once

#include "Component.h"
#include "Triangle.h"
#include "Cube.h"
#include "TriGrid.h"
#include "Ship.h"
#include "Engine.h"
#include "Obstacle.h"

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
	Triangle* triangle;
	Cube* cube;
	TriGrid* triGrid;
	Obstacle* obstacle1;

	//////////////////////////////////////
	//instance of ship here to make		//
	//sure i can use it in the update	//
	//////////////////////////////////////
	Ship* ship;
	D3DXVECTOR3 posShip;
	D3DXVECTOR3 posCam;
	D3DXVECTOR3 targetShip;
};

