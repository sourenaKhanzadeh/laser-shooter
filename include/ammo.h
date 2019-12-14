#ifndef AMMO_H
#define AMMO_H

#include "gameObject.h"


class Ammo: public GameObject{
private:
    float radius;
    Vector2 acelerate;

    void draw();
    void control();
    void move();

    void destroy();

public:
    Ammo(sf::RenderWindow *window, float x, float y, float rad=A_RAD);
    ~Ammo();

};


#endif
