#include "Obstacle.h"


Obstacle::Obstacle()
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
{
	SetPosition(0.f, 5.f, 200.f);
	SetScale(10, 15, 2);
	m_collider = new CRectangle(this, GetPosition().x, GetPosition().y, 1, 1);
}


Obstacle::~Obstacle()
{

}

void Obstacle::Update()
{
	SetPosition(GetPosition().x, GetPosition().y, GetPosition().z - (70 * gTimer->GetDeltaTime()));
}
