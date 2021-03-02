#include "Character.h"

//--------------------------Main character Constructor----------------------
Character::Character(sf::RenderWindow& window, sf::Vector2f position, char c) 
	:m_window(window), m_position(position), m_type(c)
{}

//---get the location of an character---
sf::Vector2f Character::get_m_position()
{
	return m_position;
}

//get the type of the character
char Character::get_m_type()
{
	return m_type;  
}

Character::~Character()
{}
