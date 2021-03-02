#include "Diamond.h"

//----------------Diamond character Constructor----------------- 
Diamond::Diamond(sf::RenderWindow& window, sf::Vector2f position)
	: Character(window, position, 'D')
{}

//uploads image to draw from folder 
void Diamond::draw()
{
	sf::Texture Texture;
	sf::Sprite Diamond;

	if (!Texture.loadFromFile("diamond.png"))
		std::cout << "Load failed" << std::endl;

	Diamond.setTexture(Texture);
	Diamond.setPosition(m_position);
	m_window.draw(Diamond);
}

Diamond::~Diamond()
{}
