#include "../include/enemy.h"


Enemy::Enemy(sf::RenderWindow *window, float x, float y, Vector2 size):
GameObject(window, x, y){
    this->size = size;
    ammo = new Ammo*[1];
    ammo[0] = NULL;

    pos = Vector2(SCREEN_W-E_WIDTH*2, 0);
    vel = E_DEFAULT_VEL;
}

void Enemy::draw(){
  sf::RectangleShape rect(size);
  rect.setFillColor(E_COLOR);

  rect.move(pos);
  window->draw(rect);

}

void Enemy::move(){
  pos += vel;

  if(ammo[0] != NULL){
    ammo[0]->update();
    clamp(ammo);
  }
}




void Enemy::clamp(){
  // std::cout << "Enemy clamp" << std::endl;

  if(vel.y + pos.y + size.y > SCREEN_H)
    vel.y = -E_DEFAULT_VEL.y;
  if(vel.y + pos.y  < 0)
    vel.y = E_DEFAULT_VEL.y;

}

void Enemy::clamp(Ammo **ammo){
  // std::cout << "Ammo clamp" << std::endl;
  if( ammo[0]->getPos().x > SCREEN_W || ammo[0]->getPos().x <0){
      delete ammo[0];
      ammo[0] = NULL;
  }
}

void Enemy::fire(){
    ammo[0] = new Ammo(window, pos.x, pos.y, A_RAD, false);
    ammo[0]->setPos(pos + Vector2(-size.x/2, -size.y/2));
    ammo[0]->setColor(E_COLOR);
}

void Enemy::control(){
  /// 3 wave randomness
  // std::cout << rand() % 100 << std::endl;
  int waveA = rand() % 25;
  int waveB = rand() % 50;
  int waveC = rand() % 75;
  int target = rand() % 100;

  if(waveA < target && waveB > target && *ammo == NULL)fire();
  //restrict enemy inside the boundry
  clamp();
}
