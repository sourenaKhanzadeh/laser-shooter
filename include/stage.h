#ifndef STAGE_H
#define STAGE_H

#include "gameObject.h"

// Player Object
#include "player.h"
#include "enemy.h"


class Stage{
protected:
  Player *p;
  Enemy **enemies;
  sf::RenderWindow *window;

private:
  void init();

public:
  Stage(sf::RenderWindow *window);
  void update();
  void collisions();

};

#endif
