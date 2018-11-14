
// Project Includes
#include "SpriteObject.h"

SpriteObject::SpriteObject()
	: GameObject() // Always initialise your parent class in your constructor
	, m_sprite()
{

}


void SpriteObject::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}



sf::FloatRect SpriteObject::GetBounds()
{
	return m_sprite.getGlobalBounds();
}


void SpriteObject::SetPosition(sf::Vector2f _position)
{
	m_sprite.setPosition(_position);
}

void SpriteObject::SetPosition(float _x, float _y)
{
	m_sprite.setPosition(_x, _y);
}

sf::Vector2f SpriteObject::GetPosition()
{
	return m_sprite.getPosition();
}