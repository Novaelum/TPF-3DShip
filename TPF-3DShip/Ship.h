#pragma once

#include "PrimitiveModel.h"

class Ship
	: PrimitiveModel
{
public:
	Ship();
	~Ship();

	void Update();

private:
	float currentx, currenty, currentz;
	const float speed = 8.0f;

};

