#pragma once

#include <SFML/Graphics.hpp>
#include "Frame.h"

class Button
{
public:
    //------------------------------C-tor---------------------------------
    Button(sf::RenderWindow& window, sf::Vector2f position, Frame& frame);

    //-----polymorphism-----
    virtual void draw() = 0;

    //-D-tor--
	~Button();

protected:
    //---Protected Variables----
    sf::Vector2f m_position;
    sf::RenderWindow& m_window;
    Frame& m_frame;
};

