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

  // abstrac methods
  void virtual draw(){};
  void virtual move(){};
  void virtual control(){};
public:

  void update();

  GameObject(sf::RenderWindow *window, float x, float y);

  // getters && setters
  Vector2 getPos(){return pos;}
  Vector2 getVel(){return vel;}
  sf::Color getColor(){return color;}

  void setPos(Vector2 v){pos = v;}
  void setVel(Vector2 v){vel = v;}
  void setColor(sf::Color c){color = c;}
};

void onCollision(GameObject *obj1, GameObject *obj2);

#endif
