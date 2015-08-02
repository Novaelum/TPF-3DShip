#include "Ship.h"

Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CONE)
	, m_updatedPos(0.f, 6.f, 1.f)
{
	m_collider = new CCircle(this, m_updatedPos.x, m_updatedPos.y, 1.f);
	SetPosition(m_updatedPos.x, m_updatedPos.y, m_updatedPos.z);
}

Ship::~Ship()
{
}

void Ship::Update()
{
	// Check for input
	// W | Up arrow : Go Up
	if (gDInput->keyDown(DIK_W) || gDInput->keyDown(DIK_UPARROW))
	{
		float posY = m_updatedPos.y + (SPEED * gTimer->GetDeltaTime());
		m_updatedPos.y = (posY < (LIMITER_TOP)) ? posY : (LIMITER_TOP);
	}

	// A | Left arrow : Go Left
	if (gDInput->keyDown(DIK_A) || gDInput->keyDown(DIK_LEFTARROW))
	{
		float posX = m_updatedPos.x - (SPEED * gTimer->GetDeltaTime());
		m_updatedPos.x = (posX > (LIMITER_SIDE * -1)) ? posX : (LIMITER_SIDE * -1);
	}
	// S | Down arrow : Go Down
	if (gDInput->keyDown(DIK_S) || gDInput->keyDown(DIK_DOWNARROW))
	{
		float posY = m_updatedPos.y - (SPEED * gTimer->GetDeltaTime());
		m_updatedPos.y = (posY > (LIMITER_BOTTOM)) ? posY : (LIMITER_BOTTOM);
	}
	// D | Right arrow : Go Right
	if (gDInput->keyDown(DIK_D) || gDInput->keyDown(DIK_RIGHTARROW))
	{
		float posX = m_updatedPos.x + (SPEED * gTimer->GetDeltaTime());
		m_updatedPos.x = (posX < (LIMITER_SIDE)) ? posX : (LIMITER_SIDE);
	}

	// Apply modifications
	SetPosition(m_updatedPos.x, m_updatedPos.y, m_updatedPos.z);
	m_collider->SetPosition(m_updatedPos.x, m_updatedPos.y);
}
