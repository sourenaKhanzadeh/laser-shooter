#include "../include/stage.h"

Stage::Stage(sf::RenderWindow *window){
  enemies = new Enemy*[E_DEFUALT_NUM];
  this->window = window;

  init();
}

void Stage::init(){
  p = new Player(window, 0, 0);
  enemies[0] = new Enemy(window, 0, 0);
}

void Stage::update(){
  if(p != NULL)
    p->update();
  for(int i =0;i<E_DEFUALT_NUM;i++)
    if(enemies[i] != NULL)
      enemies[i]->update();
  collisions();

}


void Stage::collisions(){
  if(p->getAmmo()[0] != NULL)
    for(int i=0;i<E_DEFUALT_NUM;i++)
      onCollision(p->getAmmo()[0], enemies[i]);

}
