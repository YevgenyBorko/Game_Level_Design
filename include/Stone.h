#pragma once

#include "Character.h"

//inheritance from Character class
class Stone:public Character
{
public:
	//-----------------------C-tor-------------------------
	Stone(sf::RenderWindow& window, sf::Vector2f position);

	//draw function
	void draw();

	//D-tor
	~Stone();
};