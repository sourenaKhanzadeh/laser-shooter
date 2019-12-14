#ifndef SETTINGS_H
#define SETTINGS_H

#define SCREEN_W 600
#define SCREEN_H 600
#define TITLE "Squad"

#include <iostream>
#include <SFML/Graphics.hpp>



#define P_COLOR sf::Color::Red
#define DEFAULT_VEL 0.01f
#define P_SPEED 1.25f

#define Key(x) sf::Keyboard::isKeyPressed(sf::Keyboard::x)
#define ORIGIN Vector2(0, 0)

typedef sf::Vector2f Vector2;



#endif
