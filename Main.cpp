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

	// Create test objects
	Player ourPlayer;
	Coin ourCoin;

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

		// TODO: Update all game objects
		if (ourPlayer.IsActive())
			ourPlayer.Update(frameTime);
		if (ourCoin.IsActive())
			ourCoin.Update(frameTime);


		// -----------------------------------------------
		// Collision Section
		// -----------------------------------------------

		// TODO: Collision detection
		if (ourCoin.IsActive() && ourPlayer.IsActive())
		{
			if (ourCoin.GetBounds().intersects(ourPlayer.GetBounds()))
			{
				ourCoin.Collide(ourPlayer);
			}
		}


		// -----------------------------------------------
		// Draw Section
		// -----------------------------------------------
		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// Draw game world to the window
		gameWindow.setView(camera);
		// TODO: Draw game object
		if (ourCoin.IsActive())
			ourCoin.Draw(gameWindow);
		if (ourPlayer.IsActive())
			ourPlayer.Draw(gameWindow);

		// Draw UI to the window
		gameWindow.setView(gameWindow.getDefaultView());
		// TODO: Draw UI objects

		// Display the window contents on the screen
		gameWindow.display();

	} // End of Game Loop
	return 0;

} // End of main() Function