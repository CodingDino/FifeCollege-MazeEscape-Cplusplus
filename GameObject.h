#pragma once

// Library Includes
#include <SFML/Graphics.hpp>

class GameObject
{
public:

	GameObject();

	// These will be very simple or empty functions
	// that can be overridden in derived classes
	virtual void Draw(sf::RenderTarget& _target);
	virtual void Update(sf::Time _frameTime);
	virtual sf::FloatRect GetBounds();
	virtual void Collide(GameObject& _collider);
	virtual void SetPosition(sf::Vector2f _position);
	virtual void SetPosition(float _x, float _y);
	virtual sf::Vector2f GetPosition();
	bool IsActive();

protected:

	bool m_active;
};