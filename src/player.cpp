#include "../include/player.h"


Player::Player(sf::RenderWindow *window, float x, float y, float rad):
GameObject(window, x, y){
  this->radius = rad;
}

Player::~Player(){
  std::cout << "....Player Deleted...." << std::endl;
}

void Player::move(){
  pos += vel;
  if(ammo != NULL)
    ammo->update();
  // std::cout << pos.x << std::endl;
}


void Player::draw(){
  // Draw a circle
  sf::CircleShape circle(radius);
  circle.setFillColor(color);

  circle.move(pos);

  window->draw(circle);


}

void Player::fire(){
  ammo = new Ammo(window, pos.x, pos.y, A_RAD);

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

  if ( Key(Space) ){
    fire();
  }

  if(!Key(S) && !Key(A) && !Key(D) && !Key(W)){
    // movement stop
    vel = ORIGIN;
  }



}
