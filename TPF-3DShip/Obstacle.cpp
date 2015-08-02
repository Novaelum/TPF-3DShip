#include "Obstacle.h"


Obstacle::Obstacle()
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	, m_speed(70)
	, m_collider(nullptr)
{
	Spawn();
	SetScale(m_sizeXYZ, m_sizeXYZ, m_sizeXYZ);
	m_collider = new CRectangle(this, GetPosition().x, GetPosition().y, m_sizeXYZ, m_sizeXYZ);
}

Obstacle::~Obstacle()
{
	if (m_collider)
		delete m_collider;
}

void Obstacle::Spawn() {
	// Set speed and position XY base on random
	m_speed = rand() % (int)((SPEED_MAX - SPEED_MIN) + SPEED_MIN);
	m_sizeXYZ = rand() % (int)((SIZE_XYZ_MAX - SIZE_XYZ_MIN) + SIZE_XYZ_MIN);
	int posX = rand() % (MARGIN_X_RANGE) + MARGIN_X_MIN;
	int posY = rand() % (int)((MARGIN_Y_MAX - MARGIN_Y_MIN) + MARGIN_Y_MIN);
	SetPosition(posX, posY, INITIAL_POSZ);
	// Failsafe for when the obstacle is first created
	if (m_collider) {
		m_collider->SetPosition(GetPosition().x, GetPosition().y);
		m_collider->SetSize(m_sizeXYZ, m_sizeXYZ);
	}
}

void Obstacle::Update()
{
	float posZ = GetPosition().z - (m_speed * gTimer->GetDeltaTime());
	// If still visible, apply movement
	if (posZ > RESET_POSZ)
		SetPosition(GetPosition().x, GetPosition().y, posZ);
	// If no longer visible (RESET_POSZ is behind the camera), respawn the obstacle
	else
		Spawn();
}
