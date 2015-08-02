#pragma once
#include "CRectangle.h"
#include "PrimitiveModel.h"

class Ship : public PrimitiveModel
{
public:
	Ship();
	~Ship();

	void Update();
	CCircle* GetCollider() { return m_collider; }


private:
	const float SPEED = 20.f;

	// Limiters
	const float LIMITER_SIDE	= 10.f;
	const float LIMITER_BOTTOM	= 1.25f;
	const float LIMITER_TOP		= 10.f;

	D3DXVECTOR3 m_updatedPos;
	CCircle* m_collider;

};

