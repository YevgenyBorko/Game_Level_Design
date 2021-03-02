#pragma once

#include "Character.h"

//inheritance from Character class
class Diamond:public Character
{
public:
	//-----------------------C-tor-------------------------
	Diamond(sf::RenderWindow& window, sf::Vector2f position);

	//draw function
	void draw();

	//-D-tor--
	~Diamond();
};

