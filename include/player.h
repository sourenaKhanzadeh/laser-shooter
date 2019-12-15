#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"
#include "ammo.h"


class Player: public GameObject{
private:
  float radius;
  Ammo **ammo;

  void draw();
  void control();
  void move();
  void fire();

  void clamp(Ammo **ammo);

public:
  Player(sf::RenderWindow *window, float x, float y, float rad=P_RAD);
  ~Player();


  // getters && setters
  float getRadius(){return radius;}

  Ammo ** getAmmo(){return ammo;}


};

#endif
