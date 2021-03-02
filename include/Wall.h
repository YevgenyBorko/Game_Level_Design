#pragma once

#include "Character.h"

//inheritance from Character class
class Wall:public Character
{
public:
	//-----------------------C-tor-------------------------
	Wall(sf::RenderWindow& window, sf::Vector2f position);

	//draw function
	void draw();

	//D-tor
	~Wall();
};