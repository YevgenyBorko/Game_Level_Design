#pragma once

#include <SFML/Graphics.hpp>

#include "Frame.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>

class Controller
{
public:
	//---C-tor---
	Controller();

	//start builder
	void start();

	//---D-tor---
	~Controller();

private:
	//----Member Variables-----
	Menu m_menu;
	Frame m_frame;
	sf::RenderWindow m_window;

	//----Member functions-----
	void make_rectangles_array(sf::RectangleShape* object_array, int size) const;
	void Color_blue_chosen_object(sf::RectangleShape* object_array, int x, int y) const;
	bool check_if_character_was_pressed(sf::RectangleShape* object_array) const;
	char which_character(sf::RectangleShape* object_array) const;
	void make_character(std::ifstream& levelfile, int hight, int width);
	void insert_to_vec(char chosen, int x, int y);
	void insert_width_hight_stones(int& width, int& hight, int& stones) const;
};