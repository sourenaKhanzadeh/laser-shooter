#include "../include/enemy.h"


Enemy::Enemy(sf::RenderWindow *window, float x, float y, Vector2 size):
GameObject(window, x, y){
    this->size = size;
    ammo = new Ammo*[1];
    ammo[0] = NULL;

    pos = Vector2(SCREEN_W-E_WIDTH*2, 0);
}

void Enemy::draw(){
  sf::RectangleShape rect(size);
  rect.setFillColor(E_COLOR);

  rect.move(pos);
  window->draw(rect);

}

void Enemy::move(){
  vel = STOP;
  pos += vel;
}


void Enemy::control(){

}


void Enemy::clamp(){
  // std::cout << "Enemy clamp" << std::endl;
}

void Enemy::clamp(Ammo **ammo){
  // std::cout << "Ammo clamp" << std::endl;

}
