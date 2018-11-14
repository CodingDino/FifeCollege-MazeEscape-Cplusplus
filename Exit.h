#pragma once

// Project Includes
#include "SpriteObject.h"
#include "Player.h"

class Exit : public SpriteObject
{
public:
	Exit();

	// Overriding Methods
	void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);

	// Public Score Methods
	void SetPlayer(Player* _player);

private:

	Player* m_player;
};