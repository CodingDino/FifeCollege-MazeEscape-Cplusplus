// Project Includes
#include "Coin.h"
#include "AssetManager.h"

Coin::Coin()
	: Pickup()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Coin.png"));
}


void Coin::OnPickup(Player& _player)
{
	_player.ChangeScore(1);
}