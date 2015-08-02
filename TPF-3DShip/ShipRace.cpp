#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	//triangle = new Triangle();
	m_cube = new Obstacle();
	//triGrid->SetPosition(5.f, 0.f, 0.f);
	//obstacle = new Obstacle();

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
	D3DXVECTOR3 cubePos = m_cube->GetPosition();
	gEngine->GetCamera()->SetCamPos({ playerPos.x, playerPos.y + 5, playerPos.z - 15 });
	gEngine->GetCamera()->SetCameraTarget(playerPos);

	//check collision
	if (m_player->GetCollider->CollidesWith(m_cube->GetCollider()))
		std::cout << "hello" << std::endl;



	//if ((playerPos.x + 1 > cubePos.x - 1) && (playerPos.x - 1 < cubePos.x + 1))
	//{
	//	std::cout << "touch" << std::endl;
	//}
	//if (playerPos.y - 1 <= cubePos.y + 1 && playerPos.y - 1 >= cubePos.y + 1)
	//{
	//	std::cout << "touch" << std::endl;
	//}
	//else
	//{
	//	std::cout << "no touch" << std::endl;
	//}

	//std::cout << cubePos.x << std::endl;
	//std::cout << playerPos.x << std::endl;
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}