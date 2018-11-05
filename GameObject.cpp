// Project Includes
#include "GameObject.h"

GameObject::GameObject()
	: m_active(true)
{

}

void GameObject::Draw(sf::RenderTarget& _target)
{

}

void GameObject::Update(sf::Time _frameTime)
{

}

sf::FloatRect GameObject::GetBounds()
{
	return sf::FloatRect();
}

void GameObject::Collide(GameObject& _collider)
{

}

bool GameObject::IsActive()
{
	return m_active;
}