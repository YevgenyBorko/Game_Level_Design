#include "Button_new.h"

//-----------------------------new level Button Constructor------------------------- 
Button_new::Button_new(sf::RenderWindow& window, sf::Vector2f position, Frame& frame)
	: Button(window, position, frame)
{}

//uploads image to draw from folder 
void Button_new::draw()
{
	sf::Texture Texture;
	sf::Sprite New;

	if (!Texture.loadFromFile("new.png"))
		std::cout << "error cannot open picture" << std::endl;

	New.setTexture(Texture);
	New.setPosition(m_position);
	m_window.draw(New);
}

Button_new::~Button_new()
{}
