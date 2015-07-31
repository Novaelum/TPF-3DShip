#include "Ship.h"

Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CONE)
{
	currentx = 0.f;
	currenty = 5.f;
	currentz = 0.f;
	SetPosition(currentx, currenty, currentz);
}

Ship::~Ship()
{
}

void Ship::Update()
{
	//Go Left
	if (gDInput->keyDown(DIK_A))
		currentx -= speed * gTimer->GetDeltaTime();
	//Go Right
	if (gDInput->keyDown(DIK_D))
		currentx += speed * gTimer->GetDeltaTime();
	//Go Down
	if (gDInput->keyDown(DIK_S))
		currenty -= speed * gTimer->GetDeltaTime();
	//Go Up
	if (gDInput->keyDown(DIK_W))
		currenty += speed * gTimer->GetDeltaTime();


	//SetRotationY(GetRotationY() + 10.f * gTimer->GetDeltaTime());	
	this->SetPosition(currentx, currenty, currentz);
}
