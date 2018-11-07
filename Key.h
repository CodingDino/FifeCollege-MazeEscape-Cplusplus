#pragma once

// Project Includes
#include "Pickup.h"

class Key : public Pickup
{
public:
	Key();

private:

	// Overriding Methods
	virtual void OnPickup(Player& _player);
};