// Project Includes
#include "Level.h"
#include "Wall.h"
#include "Exit.h"
#include "Player.h"
#include "Baddy.h"
#include "Score.h"
#include "Coin.h"
#include "Key.h"

Level::Level()
	: m_player(nullptr)
	, m_updateList()
	, m_drawListWorld()
	, m_drawListUI()
	, m_collisionList()
{
	LoadLevel(1);
}


void Level::Draw(sf::RenderTarget& _target)
{
	// Create and update
	sf::View camera = _target.getDefaultView();
	// TODO: Follow player with camera

	// Draw game world to the window
	_target.setView(camera);
	// Draw game objects
	for (int i = 0; i < m_drawListWorld.size(); ++i)
	{
		if (m_drawListWorld[i]->IsActive())
			m_drawListWorld[i]->Draw(_target);
	}

	// Draw UI to the window
	_target.setView(_target.getDefaultView());
	// Draw UI objects
	for (int i = 0; i < m_drawListUI.size(); ++i)
	{
		if (m_drawListUI[i]->IsActive())
			m_drawListUI[i]->Draw(_target);
	}
}


void Level::Update(sf::Time _frameTime)
{
	// Update all game objects
	for (int i = 0; i < m_updateList.size(); ++i)
	{
		if (m_updateList[i]->IsActive())
			m_updateList[i]->Update(_frameTime);
	}


	// Collision detection
	for (int i = 0; i < m_collisionList.size(); ++i)
	{
		GameObject* handler = m_collisionList[i].first;
		GameObject* collider = m_collisionList[i].second;

		if (handler->IsActive() && collider->IsActive())
		{
			if (handler->GetBounds().intersects(collider->GetBounds()))
			{
				handler->Collide(*collider);
			}
		}
	}

}


void Level::LoadLevel(int _levelToLoad)
{
	// Clean up the old level

	// Delete any data already in the level
	for (int i = 0; i < m_updateList.size(); ++i)
	{
		delete m_updateList[i];
	}

	// Clear out our lists
	m_updateList.clear();
	m_drawListUI.clear();
	m_drawListWorld.clear();
	m_collisionList.clear();



	// Set up the new level
	Player* ourPlayer = new Player();
	ourPlayer->SetPosition(750.0f, 750.0f);
	m_updateList.push_back(ourPlayer);
	m_drawListWorld.push_back(ourPlayer);
	m_player = ourPlayer;

	Coin* ourCoin = new Coin();
	ourCoin->SetPosition(100.0f, 100.0f);
	m_updateList.push_back(ourCoin);
	m_drawListWorld.push_back(ourCoin);
	m_collisionList.push_back(std::make_pair(ourCoin, ourPlayer));

	Score* ourScore = new Score();
	ourScore->SetPlayer(ourPlayer);
	m_updateList.push_back(ourScore);
	m_drawListUI.push_back(ourScore);

	Key* ourKey = new Key();
	ourKey->SetPosition(200.0f, 200.0f);
	m_updateList.push_back(ourKey);
	m_drawListWorld.push_back(ourKey);
	m_collisionList.push_back(std::make_pair(ourKey, ourPlayer));

	Exit* ourExit = new Exit();
	ourExit->SetPosition(300.0f, 300.0f);
	ourExit->SetPlayer(ourPlayer);
	m_updateList.push_back(ourExit);
	m_drawListWorld.push_back(ourExit);

	Wall* ourWall = new Wall();
	ourWall->SetPosition(400.0f, 400.0f);
	m_updateList.push_back(ourWall);
	m_drawListWorld.push_back(ourWall);
	m_collisionList.push_back(std::make_pair(ourPlayer, ourWall));

}