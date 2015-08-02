#include "ShipRace.h"


ShipRace::ShipRace()
{
	//triangle = new Triangle();
	m_cube = new Obstacle();
	//triGrid->SetPosition(5.f, 0.f, 0.f);
	//obstacle = new Obstacle();

	m_player = new Ship();
	m_triGrid = new TriGrid(200, 200, 1, true);
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
	D3DXVECTOR3 cubePos = m_cube->GetPosition();
	gEngine->GetCamera()->SetCamPos({ playerPos.x, playerPos.y + 5, playerPos.z - 15 });
	gEngine->GetCamera()->SetCameraTarget(playerPos);

	//check collision
	if (m_player->GetCollider()->CollidesWith(m_cube->GetCollider()))
		std::cout << "hello" << std::endl;
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}