#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/player.h"

Player::Player(sf::RenderWindow *window, int x, int y, float rad){
  this->x = x;
  this->y = y;
  this->radius = rad;
  this->window = window;
}

Player::~Player(){
  std::cout << "....Player Deleted...." << std::endl;
}

void Player::update(){
  this->draw();

}


void Player::draw(){
  // Draw a circle
  sf::CircleShape circle(radius);
  circle.setFillColor(color);

  window->draw(circle);


}
