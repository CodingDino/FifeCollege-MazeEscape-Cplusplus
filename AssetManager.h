#pragma once

// Library Includes
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{

public:

	// Public Interface / Behaviours

	// Constructor
	AssetManager();

	// Get a texture based on a file name
	static sf::Texture& GetTexture(std::string _fileName);
	// Get a sound buffer based on a file name
	static sf::SoundBuffer& GetSoundBuffer(std::string _fileName);
	// Get a font based on a file name
	static sf::Font& GetFont(std::string _fileName);

private:

	// Private data for this class

	// A pointer to the class itself
	// For the singleton design pattern
	// The one and only instance of this class
	static AssetManager* s_instance;

	// List of Textures
	std::map<std::string, sf::Texture> m_textures;
	// List of SoundBuffers
	std::map<std::string, sf::SoundBuffer> m_soundBuffers;
	// List of Fonts
	std::map<std::string, sf::Font> m_fonts;
};