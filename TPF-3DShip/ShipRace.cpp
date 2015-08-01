#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	//triangle = new Triangle();
	m_cube = new Cube();
	//triGrid->SetPosition(5.f, 0.f, 0.f);
	//obstacle1 = new Obstacle();

	m_player = new Ship();
	m_triGrid = new TriGrid(100, 100, 1, true);
}

ShipRace::~ShipRace()
{
	//delete triangle;
	//delete cube;
	delete m_player;
	delete m_triGrid;
}

void ShipRace::Start()
{

}

void ShipRace::Update()
{
	// Camera is movable Object	
	// It Follows the ship		
	D3DXVECTOR3 playerPos = m_player->GetPosition();
	gEngine->GetCamera()->SetCamPos({ playerPos.x, playerPos.y, playerPos.z - 15 });
	gEngine->GetCamera()->SetCameraTarget(playerPos);
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}