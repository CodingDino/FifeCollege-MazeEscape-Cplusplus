// Project Includes
#include "Player.h"
#include "AssetManager.h"
#include "Wall.h"

// Constants
#define SPEED 500.0f


Player::Player()
	: MovingObject() // Initialise base class
	, m_score(0)
	, m_key(false)
	, m_animationSystem()
	, m_level(nullptr)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/PlayerWalkDown1.png"));

	// Set up the animation
	m_animationSystem.SetSprite(m_sprite);

	// Create indvidual animations
	Animation& standDown = m_animationSystem.CreateAnimation("standDown");
	standDown.AddFrame(AssetManager::GetTexture("graphics/PlayerWalkDown1.png"));

	Animation& runDown = m_animationSystem.CreateAnimation("runDown");
	runDown.AddFrame(AssetManager::GetTexture("graphics/PlayerWalkDown2.png"));
	runDown.AddFrame(AssetManager::GetTexture("graphics/PlayerWalkDown3.png"));
	runDown.SetPlayBackSpeed(10);
	runDown.SetLoop(true);

	m_animationSystem.Play("runDown");
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

	// Process animations
	m_animationSystem.Update(_frameTime);
}

void Player::Collide(GameObject& _collider)
{
	// Only do something if the thing
	// we touched was a wall

	// Dynamic cast the GameObjec ref
	// into a Wall pointer
	// if it succeeds, it was a wall
	Wall* wallCollider = dynamic_cast<Wall*>(&_collider);

	// If it was a wall we hit, we need to more ourselves
	// outside the wall's bounds, aka back where we were
	if (wallCollider != nullptr)
	{
		// We did hit a wall!!!

		// Return to our previous position that we just
		// moved away from this frame
		m_sprite.setPosition(m_previousPosition);

		// clumsy - results in "sticky" walls
		// But good enough for this game
	}
}

int Player::GetScore()
{
	return m_score;
}

void Player::ChangeScore(int _changeBy)
{
	m_score += _changeBy;
}

bool Player::HasKey()
{
	return m_key;
}

void Player::CollectKey()
{
	m_key = true;
}

void Player::Kill()
{
	// Reload current level
	if (m_level != nullptr)
		m_level->ReloadLevel();
}

void Player::SetLevel(Level* _newLevel)
{
	m_level = _newLevel;
}

void Player::AdvanceLevel()
{
	// Advance to next level
	if (m_level != nullptr)
		m_level->LoadNextLevel();
}