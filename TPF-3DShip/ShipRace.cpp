#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	//triangle = new Triangle();
	//cube = new Cube();
	//triGrid->SetPosition(5.f, 0.f, 0.f);
	//obstacle1 = new Obstacle();

	m_player = new Ship();
	m_triGrid = new TriGrid(100, 100, 1);
	
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
	std::cout << "X " << gEngine->GetCamera()->GetCamPos().x << " Y " << gEngine->GetCamera()->GetCamPos().y << " Z " << gEngine->GetCamera()->GetCamPos().x << std::endl;
//	gEngine->GetCamera()->SetCamtarget(playerPos); // not found


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