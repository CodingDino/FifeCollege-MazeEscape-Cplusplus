#pragma once

// Library Includes
#include <SFML/Graphics.hpp>

class GameObject
{
public:

	// These will be very simple or empty functions
	// that can be overridden in derived classes
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	sf::FloatRect GetBounds();
	void Collide(GameObject& _collider);
};