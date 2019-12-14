#include "../include/gameObject.h"


void GameObject::update(){
  draw();
  move();
  control();
}

GameObject::GameObject(sf::RenderWindow *window, float x, float y){
  this->window = window;

  pos = Vector2(x, y);
  vel = Vector2(DEFAULT_VEL, DEFAULT_VEL);
}
