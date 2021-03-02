#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Character
{
public:
	//-----------------------------C-tor--------------------------------
	Character(sf::RenderWindow& window, sf::Vector2f position, char c);

	//-----polymorphism-----
	virtual void draw() = 0;

	//---all around functions---
	sf::Vector2f get_m_position();
	char get_m_type();

	//---D-tor---
	~Character();

protected:
	//--Protected Variables--
	sf::Vector2f m_position;
	char m_type;
	sf::RenderWindow& m_window;
};

