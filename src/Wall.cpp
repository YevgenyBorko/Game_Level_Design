#include "Wall.h"

//----------------Wall character Constructor----------------- 
Wall::Wall(sf::RenderWindow& window, sf::Vector2f position)
	: Character(window, position, '#')
{}

//uploads image to draw from folder 
void Wall::draw()
{
	sf::Texture Texture;
	sf::Sprite Wall;

	if (!Texture.loadFromFile("wall.png"))
		std::cout << "Load failed" << std::endl;

	Wall.setTexture(Texture);
	Wall.setPosition(m_position);
	m_window.draw(Wall);
}

Wall::~Wall()
{}
