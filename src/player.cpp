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
  // Replace with texture
  sf::Texture texture;
  if(!texture.loadFromFile("./res/sprites/player.png")){
    std::cout << "<<<<Failed to load Player texture>>>>" << std::endl;
    exit(EXIT_FAILURE);
  }
  // Collider
  sf::RectangleShape rect(Vector2(-P_COLLIDER_SIZE,P_COLLIDER_SIZE));
  rect.setOutlineColor(color);
  rect.setFillColor(sf::Color(0,0,0,0));
  rect.setOutlineThickness(1);

  rect.move(pos);

  // sprite
  sf::Sprite sprite(texture);

  sprite.setScale(Vector2(0.1f, 0.1f));
  sprite.setRotation(90.f);

  sprite.move(pos);

  window->draw(sprite);
  window->draw(rect);


}

void Player::fire(){
  ammo[0] = new Ammo(window, pos.x, pos.y, A_RAD);
  ammo[0]->setPos(pos + Vector2(0, P_COLLIDER_SIZE/2));
}


void Player::clamp(Ammo **ammo){
  if( ammoIsDestroyed || (ammo[0]->getPos().x > SCREEN_W || ammo[0]->getPos().x <0)){
      delete ammo[0];
      ammo[0] = NULL;
      destroyAmmo();
  }
}

void Player::control(){
  bool domain = pos.y < 0 || pos.y > SCREEN_H || pos.x < 0;
  if( Key(A) ){
    // Move Left
    vel.x=-speed();
  }
  if( Key(W)){
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
      vel = STOP;
    }


}
