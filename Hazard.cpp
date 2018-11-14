// Project Includes
#include "Hazard.h"
#include "AssetManager.h"
#include "Player.h"

Hazard::Hazard()
	: SpriteObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Obstacle.png"));
}


void Hazard::Collide(GameObject& _collider)
{

	// Only do something if the thing
	// we touched was the player
	Player* castPlayer = dynamic_cast<Player*>(&_collider);

	// Only do the thing if player is not null
	if (castPlayer != nullptr)
	{
		// We were touched by the player

		// KILL THEM
		castPlayer->Kill();
	}
}