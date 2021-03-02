#pragma once

#include "Character.h"

//inheritance from Character class
class Digger:public Character
{
public:
	//-----------------------C-tor-------------------------
	Digger(sf::RenderWindow& window, sf::Vector2f position);

	//draw function
	void draw();

	//-D-tor--
	~Digger();
};