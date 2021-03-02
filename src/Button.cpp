#include "Button.h"

//------------------------Main Buttons Constructors-------------------------- 
Button::Button(sf::RenderWindow& window, sf::Vector2f position, Frame& frame)
	: m_window(window), m_position(position), m_frame(frame)
{}

Button::~Button()
{}
