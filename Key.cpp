// Project Includes
#include "Key.h"
#include "AssetManager.h"

Key::Key()
	: Pickup()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Key.png"));
	// TEMP: Position coin
	m_sprite.setPosition(500.0f, 300.0f);
}


void Key::OnPickup(Player& _player)
{
	_player.CollectKey();
}