#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include "Character.h"
#include "Diamond.h"
#include "Wall.h"
#include "Digger.h"
#include "Demon.h"
#include "Stone.h"

class Frame
{
public:
	//C-tor
	Frame();

	//---all around functions---
	void clear();
	void draw(sf::RenderWindow& window) const;
	void remove(sf::Vector2f location);
	void save_to_file(int width, int hight, int stones) const;
	void write_to_file(std::vector<std::vector<char>> map, int x, int y, int stones) const;
	void insert(sf::RenderWindow& window, sf::Vector2f location, char object_chosen);

	//C-tor
	~Frame();

private:
	//------------------Member Variables-------------------
	std::vector< std::unique_ptr <Character>> m_frame_shape;
};

