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



float collision(GameObject *obj1, GameObject *obj2){
  Vector2 pos1 = obj1->getPos();
  Vector2 pos2 = obj2->getPos();

  float dist = (float)sqrt(pow(pos2.x-pos1.x, 2) + pow(pos2.y-pos1.y, 2));

  // std::cout << "distance: " << dist << "m." << std::endl;
  // if(dist < E_WIDTH){
    // std::cout << "....Collided..." << std::endl;
  // }

  return dist;
}
