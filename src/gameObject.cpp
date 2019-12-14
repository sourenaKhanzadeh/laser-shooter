#include "../include/gameObject.h"


void GameObject::update(){
  draw();
  move();
  control();
}

GameObject::GameObject(sf::RenderWindow *window, float x, float y){
  this->window = window;
  
  Vector2 pos(x, y);
  Vector2 vel(DEFAULT_VEL, DEFAULT_VEL);
}
