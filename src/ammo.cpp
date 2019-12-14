#include "../include/ammo.h"


Ammo::Ammo(sf::RenderWindow *window, float x, float y, float rad):
GameObject(window, x, y){
  this->radius =  rad;

  acelerate = Vector2(ACCELERATION_FACTOR, ACCELERATION_FACTOR);
  vel = Vector2(A_DEFAULT_VEL, 0);
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
  pos += vel;
  vel.x *= acelerate.x;


}


void Ammo::control(){

}
