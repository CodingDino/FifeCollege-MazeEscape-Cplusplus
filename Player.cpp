// Project Includes
#include "Player.h"
#include "AssetManager.h"

// Constants
#define SPEED 500.0f


Player::Player()
	: MovingObject() // Initialise base class
	, m_score(0)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/PlayerWalkDown1.png"));
}

void Player::Update(sf::Time _frameTime)
{
	// First, assume no keys are pressed
	m_velocity.x = 0.0f;
	m_velocity.y = 0.0f;

	// Use the keyboard function to check 
	// which keys are currently held down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_velocity.y = -SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_velocity.x = -SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_velocity.y = SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_velocity.x = SPEED;
	}

	// Call the update function manually on 
	// the parent class
	// This will actually move the character
	MovingObject::Update(_frameTime);
}

int Player::GetScore()
{
	return m_score;
}

void Player::ChangeScore(int _changeBy)
{
	m_score += _changeBy;
}