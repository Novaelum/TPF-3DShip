#pragma once
#include "PrimitiveModel.h"
#include "CRectangle.h"

class Obstacle : public PrimitiveModel
{
public:
public:
	Obstacle();
	~Obstacle();

	void GetCollider() { m_cubeCollider; }

	void Update();

private:
	D3DXVECTOR3 m_updatedPos;
	CRectangle* m_cubeCollider;
};

