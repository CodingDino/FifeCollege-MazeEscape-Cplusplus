#pragma once

// Project Includes
#include "GameObject.h"

class SpriteObject
	// The " : public " means this class inherits from any class names that follow
	: public GameObject
{
public:

	SpriteObject();

	// Overriding Methods
	void Draw(sf::RenderTarget& _target);

protected: // This means derived/child classes can access

	sf::Sprite m_sprite;


};