// Library Includes
#include <assert.h>

// Project Includes
#include "AssetManager.h"

// Initialise the static reference to our instance - to nullptr (aka zero)
AssetManager* AssetManager::s_instance = nullptr;

// Constructor
AssetManager::AssetManager()
	:	m_textures		()
	,	m_soundBuffers	()
	,	m_fonts			()
{
	// Throw an error and stop execution (in debug mode) if a copy 
	// of this class has already been created
	assert(s_instance == nullptr);

	// Assign ourselves to the instance pointer
	// - this is the new instance of the class that has just been created
	s_instance = this;
}


sf::Texture& AssetManager::GetTexture(std::string _fileName)
{
	// Create an iterator to hold a key and value pair
	//	And search for the required key
	//	using the passed in file name
	auto keyValuePair = s_instance->m_textures.find(_fileName);
	// "auto" in this case is equivalent to writing 
	//	std::map<std::string,sf::Texture>::iterator
	// this keyword (auto) can be used in cases where the 
	// compiler can figure out the type of a variable for you
	// YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS
	
	// Did we find the texture? (aka was it already loaded?)
	// (iterator will be at the end if we did NOT find it)
	if (keyValuePair != s_instance->m_textures.end())
	{
		// YES! We found it!
		return keyValuePair->second;
	}
	else
	{
		// NO! We didn't find it!

		// Let's create it then!

		// Create a new key value pair using the filename
		// The subscript [] operator creates an entry in 
		// the map if there is not already one there

		sf::Texture& texture = s_instance->m_textures[_fileName];

		// blank texture has been created
		// Now just load it from file using sfml
		texture.loadFromFile(_fileName);

		// return the texture to the calling code
		return texture;
	}

}


// See texture function above for notes
sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string _fileName)
{
	auto keyValuePair = s_instance->m_soundBuffers.find(_fileName);

	if (keyValuePair != s_instance->m_soundBuffers.end())
	{
		// We DID find it
		return keyValuePair->second;
	}
	else
	{
		// We did NOT find it
		sf::SoundBuffer& soundBuffer = s_instance->m_soundBuffers[_fileName];
		soundBuffer.loadFromFile(_fileName);
		return soundBuffer;
	}
}


// See texture function above for notes
sf::Font& AssetManager::GetFont(std::string _fileName)
{
	auto keyValuePair = s_instance->m_fonts.find(_fileName);

	if (keyValuePair != s_instance->m_fonts.end())
	{
		// We DID find it
		return keyValuePair->second;
	}
	else
	{
		// We did NOT find it
		sf::Font& font = s_instance->m_fonts[_fileName];
		font.loadFromFile(_fileName);
		return font;
	}
}