#include "Obstacle.h"


Obstacle::Obstacle()
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	, m_updatedPos(0.f, 5.f, 0.f)
{
	m_cubeCollider = new CRectangle(this, m_updatedPos.x, m_updatedPos.y, 1, 1);
}


Obstacle::~Obstacle()
{
}

void Obstacle::Update()
{

}
