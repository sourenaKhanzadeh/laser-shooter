#include "../include/ammo.h"


Ammo::Ammo(sf::RenderWindow *window, float x, float y, float rad, bool player):
GameObject(window, x, y){
  this->radius =  rad;
  this->player = player;

  acelerate = Vector2(ACCELERATION_FACTOR, ACCELERATION_FACTOR);
  if(player)
    vel = Vector2(A_DEFAULT_VEL, 0);
  else
    vel = Vector2(-A_DEFAULT_VEL, 0);
}


Ammo::~Ammo(){
  if(player)
    std::cout << "....Player Ammo Destroyed...." << std::endl;
  else
    std::cout << "....Enemy Ammo Destroyed...." << std::endl;
}

void Ammo::draw(){
  sf::RectangleShape rect(Vector2(radius*5, radius));
  rect.setFillColor(color);

  rect.move(pos);

  window->draw(rect);

}


void Ammo::move(){
  pos += vel;
  vel.x *= acelerate.x;


}


void Ammo::control(){

}
