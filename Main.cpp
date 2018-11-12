// Library Includes
#include <SFML/Window.hpp>	
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>

// Project Includes
#include "AssetManager.h"
#include "Wall.h"
#include "Exit.h"
#include "Player.h"
#include "Baddy.h"
#include "Score.h"
#include "Coin.h"
#include "Key.h"

// The main() Function - entry point for our program
int main()
{
	// -----------------------------------------------
	// Game Setup
	// -----------------------------------------------

	// Window - to draw to the screen
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", sf::Style::Titlebar | sf::Style::Close);

	// Seed our random number generator 
	srand(time(NULL));

	// Create AssetManager
	AssetManager assets;

	// Game Clock - to keep track of time passed each frame
	sf::Clock gameClock;

	// Game state
	bool playing = false;

	// Game camera
	sf::View camera = gameWindow.getDefaultView();

	// GameObject Lists
	std::vector<GameObject*> updateList;
	std::vector<GameObject*> drawListWorld;
	std::vector<GameObject*> drawListUI;

	std::vector<std::pair<GameObject*,GameObject*> > collisionList;

	// Create test objects
	Player ourPlayer;
	ourPlayer.SetPosition(750.0f, 750.0f);
	updateList.push_back(&ourPlayer);
	drawListWorld.push_back(&ourPlayer);

	Coin ourCoin;
	ourCoin.SetPosition(100.0f, 100.0f);
	updateList.push_back(&ourCoin);
	drawListWorld.push_back(&ourCoin);
	collisionList.push_back(std::make_pair(&ourCoin, &ourPlayer));

	Score ourScore;
	ourScore.SetPlayer(&ourPlayer);
	updateList.push_back(&ourScore);
	drawListUI.push_back(&ourScore);

	Key ourKey;
	ourKey.SetPosition(200.0f, 200.0f);
	updateList.push_back(&ourKey);
	drawListWorld.push_back(&ourKey);
	collisionList.push_back(std::make_pair(&ourKey, &ourPlayer));

	Exit ourExit;
	ourExit.SetPosition(300.0f, 300.0f);
	ourExit.SetPlayer(&ourPlayer);
	updateList.push_back(&ourExit);
	drawListWorld.push_back(&ourExit);

	Wall ourWall;
	ourWall.SetPosition(400.0f, 400.0f);
	updateList.push_back(&ourWall);
	drawListWorld.push_back(&ourWall);
	collisionList.push_back(std::make_pair(&ourPlayer, &ourWall));

	// -----------------------------------------------
	// Game Loop
	// -----------------------------------------------
	while (gameWindow.isOpen())
	{
		// -----------------------------------------------
		// Input Section
		// -----------------------------------------------

		// Check all events since the last frame and process 
		// each one until there are no more
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			// TODO: Pass event to input objects


			// Did the player try to close the window?
			if (gameEvent.type == sf::Event::Closed)
			{
				// If so, call the close function on the window.
				gameWindow.close();
			}

		} // End event polling loop

		// -----------------------------------------------
		// Update Section
		// -----------------------------------------------
		// Get the time passed since the last frame and restart our game clock
		sf::Time frameTime = gameClock.restart();

		// Update all game objects
		for (int i = 0; i < updateList.size(); ++i)
		{
			if (updateList[i]->IsActive())
				updateList[i]->Update(frameTime);
		}


		// -----------------------------------------------
		// Collision Section
		// -----------------------------------------------

		// Collision detection
		for (int i = 0; i < collisionList.size(); ++i)
		{
			GameObject* handler = collisionList[i].first;
			GameObject* collider = collisionList[i].second;

			if (handler->IsActive() && collider->IsActive())
			{
				if (handler->GetBounds().intersects(collider->GetBounds()))
				{
					handler->Collide(*collider);
				}
			}
		}


		// -----------------------------------------------
		// Draw Section
		// -----------------------------------------------
		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// Draw game world to the window
		gameWindow.setView(camera);
		// Draw game objects
		for (int i = 0; i < drawListWorld.size(); ++i)
		{
			if (drawListWorld[i]->IsActive())
				drawListWorld[i]->Draw(gameWindow);
		}

		// Draw UI to the window
		gameWindow.setView(gameWindow.getDefaultView());
		// Draw UI objects
		for (int i = 0; i < drawListUI.size(); ++i)
		{
			if (drawListUI[i]->IsActive())
				drawListUI[i]->Draw(gameWindow);
		}

		// Display the window contents on the screen
		gameWindow.display();

	} // End of Game Loop
	return 0;

} // End of main() Function