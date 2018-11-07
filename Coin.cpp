// Project Includes
#include "Coin.h"
#include "AssetManager.h"

Coin::Coin()
	: Pickup()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Coin.png"));
	// TEMP: Position coin
	m_sprite.setPosition(300.0f, 300.0f);
}


void Coin::OnPickup(Player& _player)
{
	_player.ChangeScore(1);
}