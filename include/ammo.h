#ifndef AMMO_H
#define AMMO_H

#include "gameObject.h"


class Ammo: public GameObject{
private:
    bool player;
    float radius;
    Vector2 acelerate;

    void draw();
    void control();
    void move();

    void destroy();

public:
    Ammo(sf::RenderWindow *window, float x, float y, float rad=A_RAD, bool player=true);
    ~Ammo();

      float dmg(){
        return 0.3f;
      }

    // getters && setters
    float getRadius(){return radius;}

};


#endif
