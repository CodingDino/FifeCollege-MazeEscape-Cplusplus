// Project Includes
#include "Pickup.h"
#include "Player.h"

Pickup::Pickup()
	: SpriteObject()
{

}

void Pickup::Collide(GameObject& _collider)
{
	// Only do something if the thing
	// we touched was the player

	// We take the generic reference to a Game Object passed in
	// We get the address for that Game Object
	// We attempt to treat that address as if it is for a Player
	// If successful, it IS a player and address is stored in castPlayer
	// If not successful, it is NOT a player and nullptr is stored in castPlayer
	Player* castPlayer = dynamic_cast<Player*>(&_collider);

	// Only do the thing if player is not null
	if (castPlayer != nullptr)
	{
		// Do something based on type of pickup
		OnPickup(*castPlayer);

		// Dissappear
		m_active = false;
	}

}

void Pickup::OnPickup(Player& _player)
{
	// Do Nothing
}