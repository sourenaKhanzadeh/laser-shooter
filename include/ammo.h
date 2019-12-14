#ifndef AMMO_H
#define AMMO_H

#include "gameObject.h"

#define A_RAD 4
#define ACCELERATION_FACTOR 1.58f
#define A_DEFAULT_VEL 5

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
