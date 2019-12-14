#include "../include/ammo.h"


Ammo::Ammo(sf::RenderWindow *window, float x, float y, float rad):
GameObject(window, x, y){
  this->radius =  rad;

  Vector2 acelerate(ACCELERATION_FACTOR, ACCELERATION_FACTOR);
}


Ammo::~Ammo(){
  std::cout << "....Ammo Destroyed...." << std::endl;

}

void Ammo::draw(){
  sf::CircleShape circle(radius);
  circle.setFillColor(color);

  circle.move(pos);

  window->draw(circle);

}


void Ammo::move(){
  pos += Vector2(0.1f, 0);
  // vel.x *= acelerate.x;

}


void Ammo::control(){

}
