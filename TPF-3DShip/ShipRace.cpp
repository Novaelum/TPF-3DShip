#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	//triangle = new Triangle();
	//cube = new Cube();
	triGrid = new TriGrid(100, 100, 1.f);
	//triGrid->SetPosition(5.f, 0.f, 0.f);
	
}

ShipRace::~ShipRace()
{
	//delete triangle;
	//delete cube;
	delete triGrid;
}

void ShipRace::Start()
{

}

void ShipRace::Update()
{
	posShip = ship->GetPosition();
	posCam = { posShip.x, posShip.y + 5, posShip.z - 15 };
	targetShip = { posShip.x, posShip.y, posShip.z };
	gEngine->GetCamera()->SetCamPos(posCam);
	gEngine->GetCamera()->SetCamtarget(targetShip);
	//static float rotation = 0;
	//rotation += 0.00001;
	//triGrid->SetRotation(rotation);
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}