
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

void Exit::SetPlayer(Player* _player)
{
	m_player = _player;
}