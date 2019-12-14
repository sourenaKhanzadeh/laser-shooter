#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"
#include "ammo.h"

#define P_RAD 10.0f


class Player: public GameObject{
private:
  float radius;
  Ammo *ammo = NULL;

  void draw();
  void control();
  void move();
  void fire();

public:
  Player(sf::RenderWindow *window, float x, float y, float rad=P_RAD);
  ~Player();

};




#endif
