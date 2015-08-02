#pragma once
#include "CRectangle.h"
#include "PrimitiveModel.h"

class Ship : public PrimitiveModel
{
public:
	Ship();
	~Ship();

	void Update();
	CRectangle* GetCollider() { return m_playerCollider; }


private:
	const float m_speed = 29.f;

	D3DXVECTOR3 m_updatedPos;

protected:

	CRectangle* m_playerCollider;

};

