#pragma once

// Project Includes
#include "GameObject.h"

class TextObject
	// The " : public " means this class inherits from any class names that follow
	: public GameObject
{
public:

	TextObject();

	// Overriding Methods
	void Draw(sf::RenderTarget& _target);

protected: // This means derived/child classes can access

	sf::Text m_text;


};