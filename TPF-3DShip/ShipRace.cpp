#include "ShipRace.h"
#include "SceneManager.h"


ShipRace::ShipRace()
{
	m_player = new Ship();
	SpawnObstacles();
	m_triGrid = new TriGrid(200, 200, 1, true);
	m_soundtrack = Sounds->Get(Sound::RaceTheme_ID);
}

ShipRace::~ShipRace()
{
	// ClearComponents called at the end handle the deletion of all elements
	// As for the soundtrack, irrKlang handle them itself, nothing to do here really.
}

void ShipRace::Start()
{

}

void ShipRace::SpawnObstacles() {
	for (int i = 0; i < OBSTACLE_COUNT; i++) {
		Obstacle* obs = new Obstacle();
		m_obstacles.push_back(obs);
	}
}

void ShipRace::Update()
{
	// Set the camera to the player position with an offset
	D3DXVECTOR3 playerPos = m_player->GetPosition();
	gEngine->GetCamera()->SetCamPos({ playerPos.x, playerPos.y + 5, playerPos.z - 15 });
	gEngine->GetCamera()->SetCameraTarget(playerPos);

	// Check for collisions
	CheckCollisions();
}

// All meaningful collisions are related to the player
void ShipRace::CheckCollisions() {
	auto iter = m_obstacles.begin();
	for (; iter != m_obstacles.end(); iter++) {
		if (m_player->GetCollider()->CollidesWith((*iter)->GetCollider())) {
			// Checking z axis to confirm collision
			float posZ = (*iter)->GetPosition().z;
			float sizeMargin = (*iter)->GetSizeMargin();
			// if below 0 the cube in entirely behind the player : collision impossible
			if ((posZ + sizeMargin) > 0) {
				if (((posZ + sizeMargin) < 3.f && (posZ + sizeMargin) > 0)		// BackCheck
					|| ((posZ - sizeMargin) < 3.f && (posZ - sizeMargin) > 0))	// FrontCheck
				{
					Defeated();
					break;
				}
			}
		}
	}
}

void ShipRace::Defeated() 
{
	g_sceneManager->GetDefeat()->SetAllActive();
	SetAllInactive();
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}

void ShipRace::SetAllActive() {
	AudioSys->stopAllSounds();
	AudioSys->play2D(m_soundtrack);
	m_player->SetActive(true);
	m_triGrid->SetActive(true);
	{ auto iter = m_obstacles.begin();
	for (; iter != m_obstacles.end(); iter++) {
		(*iter)->SetActive(true);
	}
	}
	Reset();
	this->SetActive(true);
	
}

void ShipRace::SetAllInactive() {
	m_player->SetActive(false);
	m_triGrid->SetActive(false);
	{ auto iter = m_obstacles.begin();
	for (; iter != m_obstacles.end(); iter++) {
		(*iter)->SetActive(false);
	}
	}
	this->SetActive(false);
}

void ShipRace::Reset() {
	{ auto iter = m_obstacles.begin();
	for (; iter != m_obstacles.end(); iter++) {
	  	  (*iter)->Spawn();
	}
	}
	m_player->SetPosition(0.f, 5.f, 2.5f);
}