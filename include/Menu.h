#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Button.h"
#include "Button_new.h"
#include "Button_save.h"
#include "Button_Delete.h"
#include "Character.h"
#include "Diamond.h"
#include "Wall.h"
#include "Digger.h"
#include "Demon.h"
#include "Stone.h"

class Menu
{
public:
	//C-tor
	Menu();

	//----------------Draw function-------------------
	void draw(sf::RenderWindow& window, Frame& frame);

	//D-tor
	~Menu();

private:
	//------------------Member Variables-------------------
	std::vector< std::unique_ptr <Character>> m_menu_shape;
	std::vector< std::unique_ptr <Button>> m_button;
};

