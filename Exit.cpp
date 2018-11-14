
// Project Includes
#include "Exit.h"
#include "AssetManager.h"

Exit::Exit()
	: SpriteObject() // Initialise parent class
	, m_player(nullptr)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorClosed.png"));
}

void Exit::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{
		bool hasKey = m_player->HasKey();
		if (hasKey == true)
		{
			m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorOpen.png"));
		}
	}
}


void Exit::Collide(GameObject& _collider)
{
	// Only do something if the thing
	// we touched was the player
	Player* castPlayer = dynamic_cast<Player*>(&_collider);

	// Only do the thing if player is not null
	if (castPlayer != nullptr)
	{
		// We were touched by the player

		// if the player has the key...
		if (castPlayer->HasKey())
		{
			// Load Next Level
			castPlayer->AdvanceLevel();
		}
	}
}

void Exit::SetPlayer(Player* _player)
{
	m_player = _player;
}