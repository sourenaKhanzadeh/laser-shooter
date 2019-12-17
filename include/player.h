#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"
#include "ammo.h"


class Player: public GameObject{
private:
  float radius;
  Ammo **ammo;
  bool ammoIsDestroyed;
  int health = 4;

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

  void destroyAmmo(bool destroyed=false){ammoIsDestroyed = destroyed;}

  void damage(){health-=1;}
  bool isDestroyed(){return health <=0;}
  int getHealth(){return health;}

};


#endif
