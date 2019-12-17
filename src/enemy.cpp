#include "../include/enemy.h"


Enemy::Enemy(sf::RenderWindow *window, float x, float y, Vector2 size):
GameObject(window, x, y){
    this->size = size;
    this->health = 100.f;
    ammo = new Ammo*[1];
    ammo[0] = NULL;

    pos = Vector2(x, y);
    vel = E_DEFAULT_VEL;
}

Enemy::~Enemy(){
  std::cout << ">>>>Enemy Destroyed<<<<<" << std::endl;
  delete [] ammo;
  ammo = NULL;
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
    *ammo = new Ammo(window, pos.x, pos.y, A_RAD, false);
    (*ammo)->setPos(pos + Vector2(-size.x/2, -size.y/2));
    (*ammo)->setColor(E_COLOR);
}

void Enemy::control(){
  /// 3 wave randomness
  // std::cout << rand() % 100 << std::endl;
  int waveA = rand() % 25;
  int waveB = rand() % 50;
  int waveC = rand() % 75;
  int target = rand() % 100;

  if(waveA < target && waveB > target && waveC < waveB
    && *ammo == NULL)fire();

  // move forward to player on
  if(pos.x > SCREEN_W/2 && waveA > waveB && waveA>waveC){
    vel.x-=10;
  }
  else if(pos.x <= SCREEN_W && waveA>waveB && waveB>target){
    vel.x+=20;
  }
  else{
    vel.x = 0;
  }
  //restrict enemy inside the boundry
  clamp();
}

void Enemy::damage(float dmg){
  health -= (health*dmg*this->dmg);
  this->dmg++;
}

bool Enemy::destroy(){
  return health <= 0;
}

void onCollision(Player *obj1, Enemy *obj2){
  float dist;
  dist = collision(obj1->getAmmo()[0], obj2);

  // std::cout << "distance: " << dist << "m." << std::endl;
  if(dist < E_WIDTH){
    std::cout << "....Collided..." << std::endl;
    std::cout << "Enemy Health: " << obj2->getHealth();
    obj2->damage(obj1->getAmmo()[0]->dmg());
    std::cout << " AFTER: " << obj2->getHealth() << std::endl;
    obj1->destroyAmmo(true);
  }
}
