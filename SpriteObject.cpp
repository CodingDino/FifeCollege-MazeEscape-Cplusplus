
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