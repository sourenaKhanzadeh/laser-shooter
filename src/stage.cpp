#include "../include/stage.h"

Stage::Stage(sf::RenderWindow *window){
  this->window = window;

  p = new Player(window, 0, 0);
  init();
  std::cout << "Enemies: " << enemies.size() << std::endl;
}

void Stage::init(){
  for(int i =0;i<E_DEFUALT_NUM;i++)
    enemies.push_back(new Enemy(window, SCREEN_W-E_WIDTH*2, rand() % SCREEN_H));
}

void Stage::update(){
  if(p != NULL)
    p->update();
  int i=0;
  for(auto enemy : enemies)
    if(enemy != NULL){
      enemy->update();

      // Destroy enemy if health is below 0
      if(enemy->isDestroyed()){
        delete enemy;
        enemy=NULL;
        enemies.erase(enemies.begin() + i);
        std::cout << "Enemies: " << enemies.size() << std::endl;
      }
      i++;
    }

  collisions();

}


void Stage::collisions(){
  if(p->getAmmo()[0] != NULL)
    for(auto enemy:enemies)
      if(enemy != NULL)
        onCollision(p->getAmmo()[0], enemy);

}
