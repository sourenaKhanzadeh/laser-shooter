#include "../include/stage.h"

Stage::Stage(sf::RenderWindow *window){
  enemies = new Enemy*[E_DEFUALT_NUM];
  this->window = window;

  init();
}

void Stage::init(){
  p = new Player(window, 0, 0);
  for(int i =0;i<E_DEFUALT_NUM;i++)
    enemies[i] = new Enemy(window, SCREEN_W-E_WIDTH*2, rand() % SCREEN_H);
}

void Stage::update(){
  if(p != NULL)
    p->update();
  for(int i =0;i<E_DEFUALT_NUM;i++)
    if(enemies[i] != NULL){
      enemies[i]->update();

      // Destroy enemy if health is below 0
      if(enemies[i]->isDestroyed()){
        delete enemies[i];
        enemies[i]=NULL;
      }
    }

  collisions();

}


void Stage::collisions(){
  if(p->getAmmo()[0] != NULL)
    for(int i=0;i<E_DEFUALT_NUM;i++)
      if(enemies[i] != NULL)
        onCollision(p->getAmmo()[0], enemies[i]);

}
