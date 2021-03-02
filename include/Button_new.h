#pragma once

#include "Button.h"
#include <iostream>

//inheritance from button class
class Button_new:public Button
{
public:
    //------------------------------C-tor---------------------------------
    Button_new(sf::RenderWindow& window, sf::Vector2f position, Frame& frame);

    //draw function
    void draw();

    //----D-tor---
    ~Button_new();
};

