#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H


#include "settings.h"

class GameObject{
protected:
  sf::RenderWindow *window;
  Vector2 pos;
  Vector2 vel;
  sf::Color color = P_COLOR;


  float speed(){return DEFAULT_VEL * P_SPEED;};

public:
  // abstrac methods
  void virtual draw(){};
  void virtual move(){};
  void virtual control(){};

  void update();

  GameObject(sf::RenderWindow *window, float x, float y);

};


#endif
