#pragma once

// Project Includes
#include "TextObject.h"
#include "Player.h"

class Score : public TextObject
{
public:
	Score();

	// Overriding Methods
	virtual void Update(sf::Time _frameTime);

	// Public Score Methods
	void SetPlayer(Player* _player);

private:

	Player* m_player;

};