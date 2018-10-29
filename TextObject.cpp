
// Project Includes
#include "TextObject.h"

TextObject::TextObject()
	: GameObject() // Always initialise your parent class in your constructor
	, m_text()
{

}


void TextObject::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_text);
}