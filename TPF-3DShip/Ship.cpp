#include "Ship.h"

Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CONE)
	, m_updatedPos(0.f, 5.f, 0.f)
{
	m_collider = new CRectangle(this, m_updatedPos.x, m_updatedPos.y, 1.5f, 1.5f);
	SetPosition(m_updatedPos.x, m_updatedPos.y, m_updatedPos.z);
}

Ship::~Ship()
{
}

void Ship::Update()
{
	// Go Left
	if (gDInput->keyDown(DIK_A)) 
	{
		float posX = m_updatedPos.x - (SPEED * gTimer->GetDeltaTime());
		m_updatedPos.x = (posX > (LIMITER_SIDE * -1)) ? posX : (LIMITER_SIDE * -1);
	}
	// Go Right
	if (gDInput->keyDown(DIK_D)) 
	{
		float posX = m_updatedPos.x + (SPEED * gTimer->GetDeltaTime());
		m_updatedPos.x = (posX < (LIMITER_SIDE)) ? posX : (LIMITER_SIDE);
	}
	// Go Down
	if (gDInput->keyDown(DIK_S)) 
	{
		float posY = m_updatedPos.y - (SPEED * gTimer->GetDeltaTime());
		m_updatedPos.y = (posY > (LIMITER_BOTTOM)) ? posY : (LIMITER_BOTTOM);
	}
	// Go Up
	if (gDInput->keyDown(DIK_W))
	{
		float posY = m_updatedPos.y + (SPEED * gTimer->GetDeltaTime());
		m_updatedPos.y = (posY < (LIMITER_TOP)) ? posY : (LIMITER_TOP);
	}

	// change
	std::cout << m_updatedPos.y << std::endl;
	SetPosition(m_updatedPos.x, m_updatedPos.y, m_updatedPos.z);
	m_collider->SetPosition(m_updatedPos.x, m_updatedPos.y);
}
