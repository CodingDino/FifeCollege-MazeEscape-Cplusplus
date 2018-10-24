
// Project Includes
#include "Exit.h"
#include "AssetManager.h"

Exit::Exit()
	: SpriteObject() // Initialise parent class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorClosed.png"));
}