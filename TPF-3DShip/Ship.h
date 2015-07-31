#pragma once

#include "PrimitiveModel.h"

class Ship : public PrimitiveModel
{
public:
	Ship();
	~Ship();

	void Update();

private:
	const float speed = 8.0f;

protected:
	float currentx, currenty, currentz;

};

