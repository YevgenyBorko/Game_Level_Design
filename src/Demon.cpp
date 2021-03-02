#include "Demon.h"

//----------------Demon character Constructor----------------- 
Demon::Demon(sf::RenderWindow& window, sf::Vector2f position)
	: Character(window, position, '!')
{}

//uploads image to draw from folder 
void Demon::draw()
{
	sf::Texture Texture;
	sf::Sprite Demon;

	if (!Texture.loadFromFile("monster.png"))
		std::cout << "Load failed" << std::endl;

	Demon.setTexture(Texture);
	Demon.setPosition(m_position);
	m_window.draw(Demon);
}

Demon::~Demon()
{}
