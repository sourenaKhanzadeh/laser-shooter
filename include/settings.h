#ifndef SETTINGS_H
#define SETTINGS_H

#define SCREEN_W 600
#define SCREEN_H 600
#define TITLE "Squad"

#include <iostream>
#include <time.h>
#include <math.h>
#include <SFML/Graphics.hpp>


// SYSTEM SETTINGS && ALIASES
#define FPS 64
#define Key(x) sf::Keyboard::isKeyPressed(sf::Keyboard::x)
typedef sf::Vector2f Vector2;
#define ORIGIN Vector2(0, 0)
#define STOP Vector2(0, 0)

// AMMO SETTINGS
#define A_RAD 4
#define ACCELERATION_FACTOR 1.10f
#define A_DEFAULT_VEL 1.2f


// PLAYER SETTINGS
#define P_COLOR sf::Color::Red
#define DEFAULT_VEL 5.f
#define P_SPEED 1.25f
#define P_RAD 10.0f


// ENEMY SETTINGS
#define E_WIDTH 20
#define E_HEIGHT 20
#define E_DEFUALT_NUM 4
#define E_COLOR sf::Color::Green
#define E_DEFAULT_VEL Vector2(0, 3)




#endif
