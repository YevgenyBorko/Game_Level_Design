#include "Digger.h"

//----------------Digger character Constructor----------------- 
Digger::Digger(sf::RenderWindow& window, sf::Vector2f position)
	: Character(window, position, '/')
{}

//uploads image to draw from folder 
void Digger::draw() 
{
	sf::Texture Texture;
	sf::Sprite Digger;

	if (!Texture.loadFromFile("digger.png"))
		std::cout << "Load failed" << std::endl;

	Digger.setTexture(Texture);
	Digger.setPosition(m_position);
	m_window.draw(Digger);
}

Digger::~Digger()
{}
