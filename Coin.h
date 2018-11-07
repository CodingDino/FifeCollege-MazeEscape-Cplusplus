#pragma once

// Project Includes
#include "Pickup.h"

class Coin : public Pickup
{
public:
	Coin();

private:

	// Overriding Methods
	virtual void OnPickup(Player& _player);
};