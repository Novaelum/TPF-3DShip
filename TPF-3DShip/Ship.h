#pragma once

#include "PrimitiveModel.h"

class Ship : public PrimitiveModel
{
public:
	Ship();
	~Ship();

	void Update();


private:
	const float m_speed = 29.f;

	D3DXVECTOR3 m_updatedPos;

};

