// Project Includes
#include "Level.h"
#include "Wall.h"
#include "Exit.h"
#include "Player.h"
#include "Baddy.h"
#include "Score.h"
#include "Coin.h"
#include "Key.h"
#include "Hazard.h"

// Library Includes
#include <iostream>
#include <fstream>

Level::Level()
	: m_currentLevel(0)
	, m_player(nullptr)
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
	// Follow player with camera
	camera.setCenter(m_player->GetPosition());

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


	// Set the current level
	m_currentLevel = _levelToLoad;


	// Set up the new level

	// Open our file for reading
	std::ifstream inFile;
	std::string fileName = "levels/Level" + std::to_string(m_currentLevel) + ".txt";
	inFile.open(fileName);

	// Make sure the file was opened
	if (!inFile) {
		std::cerr << "Unable to open file " + fileName;
		exit(1); // Call system to stop program with error
	}

	// Set the starting x and y coordinates used to position level objects
	float x = 0.0f;
	float y = 0.0f;

	// Define the spacing we will use for our grid
	const float X_SPACE = 100.0f;
	const float Y_SPACE = 100.0f;

	// Create the player first as other objects will need to reference it
	Player* ourPlayer = new Player();
	m_player = ourPlayer;

	// Read each character one by one from the file...
	char ch;
	// Each time, try to read the next character
	// If successful, execute body of loop
	// the "noskipws" means our input from the file will include 
	// the white space (spaces and new lines)
	while (inFile >> std::noskipws >> ch)
	{
		// Perform actions based on what character was read in

		if (ch == ' ')
		{
			x += X_SPACE;
		}
		else if (ch == '\n')
		{
			y += Y_SPACE;
			x = 0;
		}
		else if (ch == 'P')
		{
			ourPlayer->SetPosition(x, y);
			ourPlayer->SetLevel(this);
			m_updateList.push_back(ourPlayer);
			m_drawListWorld.push_back(ourPlayer);
		}
		else if (ch == 'W')
		{
			Wall* ourWall = new Wall();
			ourWall->SetPosition(x, y);
			m_updateList.push_back(ourWall);
			m_drawListWorld.push_back(ourWall);
			m_collisionList.push_back(std::make_pair(ourPlayer, ourWall));
		}
		else if (ch == 'C')
		{
			Coin* ourCoin = new Coin();
			ourCoin->SetPosition(x, y);
			m_updateList.push_back(ourCoin);
			m_drawListWorld.push_back(ourCoin);
			m_collisionList.push_back(std::make_pair(ourCoin, ourPlayer));
		}
		else if (ch == 'K')
		{
			Key* ourKey = new Key();
			ourKey->SetPosition(x, y);
			m_updateList.push_back(ourKey);
			m_drawListWorld.push_back(ourKey);
			m_collisionList.push_back(std::make_pair(ourKey, ourPlayer));
		}
		else if (ch == 'E')
		{
			Exit* ourExit = new Exit();
			ourExit->SetPosition(x, y);
			ourExit->SetPlayer(ourPlayer);
			m_updateList.push_back(ourExit);
			m_drawListWorld.push_back(ourExit);
			m_collisionList.push_back(std::make_pair(ourExit, ourPlayer));
		}
		else if (ch == 'H')
		{
			Hazard* ourHazard = new Hazard();
			ourHazard->SetPosition(x, y);
			m_updateList.push_back(ourHazard);
			m_drawListWorld.push_back(ourHazard);
			m_collisionList.push_back(std::make_pair(ourHazard, ourPlayer));
		}
		else if (ch == '-')
		{
			// Do nothing - empty space
		}
		else
		{
			std::cerr << "Unrecognised character in level file: " << ch;
		}
	}

	// Close the file now that we are done with it
	inFile.close();

	// Score - position not dependant on level
	Score* ourScore = new Score();
	ourScore->SetPlayer(ourPlayer);
	m_updateList.push_back(ourScore);
	m_drawListUI.push_back(ourScore);

}

void Level::ReloadLevel()
{
	LoadLevel(m_currentLevel);
}

void Level::LoadNextLevel()
{
	LoadLevel(m_currentLevel + 1);
}