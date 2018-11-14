#pragma once

// Project Includes
#include "SpriteObject.h"

class Hazard
	: public SpriteObject
{

public:

	Hazard();

	// Inherited Methods
	void Collide(GameObject& _collider);

};