#pragma once

// Project Includes
#include "GameObject.h"

class Level
{

public:

	Level();

	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);

	void LoadLevel(int _levelToLoad);
	void ReloadLevel();
	void LoadNextLevel();

private: 

	int m_currentLevel;
	GameObject* m_player;
	std::vector<GameObject*> m_updateList;
	std::vector<GameObject*> m_drawListWorld;
	std::vector<GameObject*> m_drawListUI;
	std::vector<std::pair<GameObject*, GameObject*> > m_collisionList;

};