#ifndef ENEMY_H
#define ENEMY_H

#include "gameObject.h"
#include "ammo.h"


class Enemy: public GameObject{
private:
    Vector2 size;
    Ammo **ammo;

    void draw();
    void move();
    void control();

    void clamp();
    void clamp(Ammo **ammo);
    void fire();

public:
    Enemy(sf::RenderWindow *window, float x, float y, Vector2 size=Vector2(E_WIDTH, E_HEIGHT));
    ~Enemy();

};

#endif
