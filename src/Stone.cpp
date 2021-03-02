#include "Stone.h"

//----------------Stone character Constructor----------------- 
Stone::Stone(sf::RenderWindow& window, sf::Vector2f position)
	: Character(window, position, '@') 
{}

//uploads image to draw from folder 
void Stone::draw()
{
	sf::Texture Texture;
	sf::Sprite Stone;

	if (!Texture.loadFromFile("stone.png"))
		std::cout << "Load failed" << std::endl;

	Stone.setTexture(Texture);
	Stone.setPosition(m_position);
	m_window.draw(Stone);
}

Stone::~Stone()
{}