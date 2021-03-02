#include "Button_save.h"

//------------------------------save Button Constructor----------------------------- 
Button_save::Button_save(sf::RenderWindow& window, sf::Vector2f position, Frame& frame)
	: Button(window, position, frame)
{}

//uploads image to draw from folder 
void Button_save::draw()
{
	sf::Texture Texture;
	sf::Sprite Save;

	if (!Texture.loadFromFile("save.png"))
		std::cout << "error cannot open picture" << std::endl;

	Save.setTexture(Texture);
	Save.setPosition(m_position);
	m_window.draw(Save);
}

Button_save::~Button_save()
{}
