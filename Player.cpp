// Project Includes
#include "Player.h"
#include "AssetManager.h"

Player::Player()
	: MovingObject() // Initialise base class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/PlayerWalkDown1.png"));
	m_velocity.x = 50.0f;
	m_velocity.y = 50.0f;
}