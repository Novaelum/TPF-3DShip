#include "Ship.h"

Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CONE)
	, m_updatedPos(0.f, -5.f, -15.f)
{
	SetPosition(m_updatedPos.x, m_updatedPos.y, m_updatedPos.z);
}

Ship::~Ship()
{
}

void Ship::Update()
{
	// Go Left
	if (gDInput->keyDown(DIK_A))
		m_updatedPos.x -= m_speed * gTimer->GetDeltaTime();
	// Go Right
	if (gDInput->keyDown(DIK_D))
		m_updatedPos.x += m_speed * gTimer->GetDeltaTime();
	// Go Down
	if (gDInput->keyDown(DIK_S))
		m_updatedPos.y -= m_speed * gTimer->GetDeltaTime();
	// Go Up
	if (gDInput->keyDown(DIK_W))
		m_updatedPos.y += m_speed * gTimer->GetDeltaTime();


	//SetRotationY(GetRotationY() + 10.f * gTimer->GetDeltaTime());	
	SetPosition(m_updatedPos.x, m_updatedPos.y, m_updatedPos.z);
}
