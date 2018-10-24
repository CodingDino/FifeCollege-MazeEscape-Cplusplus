
// Project Includes
#include "MovingObject.h"

MovingObject::MovingObject()
	: SpriteObject	() // always intiialise base class
	, m_velocity	(0.0f, 0.0f)
{

}

void MovingObject::Update(sf::Time _frameTime)
{
	// Get the current position
	sf::Vector2f currentPosition = m_sprite.getPosition();

	// Calculate the amount moved
	sf::Vector2f amountMoved = m_velocity * _frameTime.asSeconds();

	// Calculate new position
	sf::Vector2f newPosition = currentPosition + amountMoved;

	// Set our sprite to this new position
	m_sprite.setPosition(newPosition);
}