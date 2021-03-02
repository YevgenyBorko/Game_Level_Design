#include "Menu.h"

Menu::Menu()
{}

void Menu::draw(sf::RenderWindow& window, Frame& frame)
{
	//------make all the characters symbols---------
	m_menu_shape.push_back(std::make_unique<Digger>
		(window, sf::Vector2f(610, 705)));
	m_menu_shape.push_back(std::make_unique<Demon>
		(window, sf::Vector2f(675, 705)));
	m_menu_shape.push_back(std::make_unique<Diamond>
		(window, sf::Vector2f(747, 705)));
	m_menu_shape.push_back(std::make_unique<Wall>
		(window, sf::Vector2f(815, 705)));
	m_menu_shape.push_back(std::make_unique<Stone>
		(window, sf::Vector2f(885, 705)));

	for (int i = 0; i < 5; i++) //draw characters
		m_menu_shape[i]->draw();

	//-----------make all buttons symbols-----------
	m_button.push_back(std::make_unique<Button_delete>
		(window, sf::Vector2f(397, 705), frame));
	m_button.push_back(std::make_unique<Button_new>
		(window, sf::Vector2f(467, 705), frame));
	m_button.push_back(std::make_unique<Button_save>
		(window, sf::Vector2f(537, 705), frame));

	for (int i = 0; i < 3; i++)  //draw buttons
		m_button[i]->draw();
}

Menu::~Menu()
{}
