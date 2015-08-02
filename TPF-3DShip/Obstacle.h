#pragma once
#include "PrimitiveModel.h"
#include "CRectangle.h"

class Obstacle : public PrimitiveModel
{
public:
public:
	Obstacle();
	~Obstacle();

	CRectangle* GetCollider()	{ return m_collider; }
	float		GetSizeMargin()	{ return m_sizeXYZ; }
	
	void Update();
	void Kill()					{ delete this; }

	void Spawn();

private:
	// Size const
	const float SIZE_XYZ_MIN	= 3.f;
	const float SIZE_XYZ_MAX	= 5.f;
	
	// Z position consts
	const float INITIAL_POSZ	= 200.f;
	const float RESET_POSZ		= -20.f;

	// Spawning XY margin consts
	const int	MARGIN_X_RANGE	= 20.f; 
	const int	MARGIN_X_MIN	= -10.f;
	const float MARGIN_Y_MIN	= 4.f;
	const float MARGIN_Y_MAX	= 8.5f;

	// Speed consts
	const float SPEED_MIN		= 60.f;
	const float SPEED_MAX		= 80.f;

	D3DXVECTOR3 m_updatedPos;
	CRectangle* m_collider;

	float m_speed;
	float m_sizeXYZ;
};

