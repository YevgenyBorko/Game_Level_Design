#include "Button_Delete.h"

//---------------------------------Delete Button Constructor------------------------------- 
Button_delete::Button_delete(sf::RenderWindow& window, sf::Vector2f position, Frame& frame)
	: Button(window, position, frame)
{}

//uploads image to draw from folder 
void Button_delete::draw() 
{
	sf::Texture Texture;
	sf::Sprite Delete;

	if (!Texture.loadFromFile("delete.png"))
		std::cout << "error cannot open picture" << std::endl;

	Delete.setTexture(Texture);
	Delete.setPosition(m_position);
	m_window.draw(Delete);
}

Button_delete::~Button_delete()
{}
