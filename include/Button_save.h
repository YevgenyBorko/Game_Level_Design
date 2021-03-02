#pragma once

#include "Button.h"
#include <iostream>

//inheritance from button class
class Button_save:public Button
{
public:
	//---------------------------------C-tor-----------------------------------
	Button_save(sf::RenderWindow& window, sf::Vector2f position, Frame& Frame);

	//draw function
	void draw();

	//----D-tor---
	~Button_save();
};

