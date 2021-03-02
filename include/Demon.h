#pragma once

#include "Character.h"

//inheritance from Character class
class Demon:public Character
{
public:
	//-----------------------C-tor-------------------------
	Demon(sf::RenderWindow& window, sf::Vector2f position);

	//draw function
	void draw();

	//-D-tor
	~Demon();
};

