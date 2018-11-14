#pragma once

// Project Includes
#include "MovingObject.h"
#include "AnimationSystem.h"
#include "Level.h"

class Player : public MovingObject
{

public:

	Player();

	// Overriding Methods
	void Update(sf::Time _frameTime);
	virtual void Collide(GameObject& _collider);

	// Public Player Methods
	int GetScore();
	void ChangeScore(int _changeBy);
	bool HasKey();
	void CollectKey();
	void Kill();
	void SetLevel(Level* _newLevel);
	void AdvanceLevel();

private:

	int m_score;
	bool m_key;
	AnimationSystem m_animationSystem;
	Level* m_level;
};