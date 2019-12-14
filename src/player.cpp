#include "../include/player.h"


Player::Player(sf::RenderWindow *window, float x, float y, float rad):
GameObject(window, x, y){
  this->radius = rad;
  ammo = new Ammo*[1];
  ammo[0] = NULL;
}

Player::~Player(){
  std::cout << "....Player Deleted...." << std::endl;
  delete [] ammo;
}

void Player::move(){
  pos += vel;
  if(ammo[0] != NULL){
    ammo[0]->update();
    clamp(ammo);
  }
}


void Player::draw(){
  // Draw a circle
  sf::CircleShape circle(radius);
  circle.setFillColor(color);

  circle.move(pos);

  window->draw(circle);


}

void Player::fire(){
  ammo[0] = new Ammo(window, pos.x, pos.y, A_RAD);
  ammo[0]->setPos(pos + Vector2(radius/2, radius/2));
}


void Player::clamp(Ammo **ammo){
  if( ammo[0]->getPos().x > SCREEN_W || ammo[0]->getPos().x <0){
      delete ammo[0];
      ammo[0] = NULL;
  }
}

void Player::control(){
  if( Key(A) ){
    // Move Left
    vel.x=-speed();
  }
  if( Key(W) ){
    // Move Up
    vel.y=-speed();

  }if( Key(D) ){
    // Move Right
    vel.x=speed();

  }
  if ( Key(S) ){
    // Move Down
    vel.y=speed();

  }

  if ( Key(Space)  && ammo[0] == NULL){
    fire();
  }

  if(!Key(S) && !Key(A) && !Key(D) && !Key(W)){
    // movement stop
    vel = ORIGIN;
  }



}
